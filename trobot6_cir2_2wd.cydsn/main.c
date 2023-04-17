 /* ========================================
 *
 * Copyright TIRI, 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF TIRI.
 * Trobot VI board is 2motor ver sion of Trobot VI board
 * 20191203 by K sakashita v6_02 2 big inwheel motor driver for Trobot-VI circuit bosrd temporally move
 *                        (v6_02 is same as v5.02 copied)
 * 20191224 by K sakashita v6_10 drv startup seq and PIS satpara changed
 * 20200125 by K sakashita v6_20 Trobot-VI final repaire board correct motor number and motor position(LF,RF,LR,RR)
               & complex drive braking by bmp sw and maxon ecflat50+39:1gear+2048enc para
 * 20200201 by K sakashita v6_21 Trobot-VI final repaire board maxon ecflat50+39:1gear+2048enc para for motor drive para can changed 
 * 20200202 by K sakashita v6_22 Trobot-VI add bmp sw cpmplex stop mortion correct for epf50
 * 20200202 by K sakashita v6_30 Trobot-VI repaire 1 control state and diagnosis routine & status0,1 data back PVM cntl by PSOC p0.7
 * 20200216 by K sakashita v6_31 Trobot-VI change pin VPM1 45pin to 69pin (because 68 pin is not use adin) and change pc2main 
 * 20200219 by K sakashita v6_32 change Ditect step pin 45(DIST4)=> 25pin(DIST9) becouse Device needs 5V VCC
 * 20200222 by K sakashita v6_33 SPI2 add for 8bit SPI I/F and diag,senser to IPCrootine
 * 20200228 by K sakashita v6_34 use SPI2 and 9axis accel6 jyro data z axis is reverse, 
 * 20200302 by K sakashita v6_35 pmv1,2& motor predrv 1,2 status 1,2 outoput output2_tag[15:20]
 * 20200304 by K sakashita v6_36 change pc2main remove write motor_en_reg before spi_ini 
 * 20200311 by K sakashita v6_37 correct velocity calc introducing CALC_RATIO 
 * 20200413 by K sakashita v6_38 drv8323 parameter change 
 * 20200419 by K sakashita v6_39 use drive_wheels in calcurate change_ratio in pc2main
 * 20200425 by K sakashita v6_40 corect motpdrv para reg2 0x060=>0x0c0 (indipendent mode => 1xmode)
 * 20200425 by K sakashita v6_41 change motor inwhoeel2 for kobayashi and try shange fault sequence
 * 20200529 by K sakashita v6_42 init and diag sequence change 
 * 20201229 by K sakashita v6_43 addtitin ENC_MALTI for parameter
 * 20201231 by K sakashita v6_50 piassign change for ver5.1 circuit board
                                (DOF9_CS=>31,PIC_CS=>32),psoc_nop=>44,(DIST4=>51)
                                 (SDI2_SPI2:4,SDO2_SPI2:5,SCK2_SPI2:33,TB_CS_SPI2:34),DIST8:80)
                                Motor_Contl4_3 add unti_windup_function  FIXed argorisum
 * 20210109 by K sakashita v6_51 Motor_Contl parm (pwm1_com ,pwm_mode ,otw_rep) are FIXed 
                                 In Initialize argorisum enabling USB routine
 * 20210126 by K sakashita v6_53 subcycle_Int_Start move to after USB_INIT routin
 * 20210209 by K sakashita v6_54 bugfix in USB connection & preDRV SPI clock up to 4MHz 
                                increase wait time (90ms) from PVM on to measure in init
 * 20210209 by K sakashita v6_55 move USB connection routin to stjust start position and use
                                sense_diagflag = 2 for stop diagsense duraing booting routin
 * 20210227 by K sakashita v6_56 detect SW_DET and shutdown state incert 99 
                                usb detect circuit r43 47K=> 4kohm
                                USB connect & REBOOT routine correct
 * 20210316 by K sakashita v6_57 Mcpuop2 subcycle move from 16 subc=>17subc
                                shortun the adc wait time 60 to 25us 
                                for finish Sub_Calc1 befor 16 sub_cycle start
 * 20210328 by K sakashita v6_61 for MB1013 require 135ms period edit 4Hz trigared measure
                                 and add sonner_trg_x4 pin for startMB1013  measurment         
 * 20210418 by K sakashita v6_70 [K3Garage] maininit and diagsence flow and WDT timer reset revaice      
 * 20210422 by K sakashita v6_71 [K3Garage] change diag_sense read_spi ssbo sel rewrite      
 * 20210818 by K sakashita v6_73 [K3Garage] revice diag condition not use ATMega      
 * 20211212 by K sakashita v6_74 [K3Garage] 2motor revice drv832x prisice gdf error info return in output132,133      
* ========================================
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <device.h>


#include "Motor_Contl4_3.h"
#include "sk_common.h"


//--------------------------------------------------------------------
// macro definitions 
//--------------------------------------------------------------------

#define FIRMWARE_VERSION	v6_74
#define DEMODE 1  // 0: normalmode 1: debugmode
#define DEMODE0 1  // 0: normalmode 1: debugmode(motor driver development)
#define DEMODE1 0  // 0: normalmode 1: debugmode
#define DEMODE3 0  // 0: normalmode 1: debugmode(nonInterrupt)
//#define EPF50_36 1 // Maxon ECflat50 36:1 gear 2048 enc  
//#define INWHEEL2 1 // Nippoh Mecanum Inwheel2 motor   
#define ZLLG40 1 // zltech 4inch inwheel motor ZLL40

#define DRIVEWHEELS 2 // 2: 2WD  4:4WD   
//#define	I2C_1_MSTAT_WR_CMPLT_HALT	(I2C_1_MSTAT_WR_CMPLT | I2C_1_MSTAT_XFER_INP | I2C_1_MSTAT_XFER_HALT)
#define BATTERY_V       12 // Battery voltage  range  12V / 24V  
#define LOW_VOLTAGE     30 // LowVoltage  limit value   
#define HIGH_TEMP      120 // Upper limit Value of Die Temperature
#define EMSTOP_TIMEOVER 3  // after 3traceline emstop gose down to FAULT

// State definision of T-robot control mode 
#define BOOT    1  // after power_on or REBOOT from PCBOOTUP and SELF TEST
#define IDLE    2  // success boot up
#define DRIVE   3  // 0: normalmode 1: debugmode
#define EMSTOP  4  // 0: normalmode 1: debugmode
#define REBOOT   5  // 0: normalmode 1: debugmode
#define FAULT 6  // 0: normalmode 1: debugmode
#define SHUTDWN 7  // 1: shutdown requesto to PC

//STATUS 0 definishon
#define POWER_SW_OFF  128 //DETECT POWER SWITCH OFF
#define DIE_TEMP_ERR   64 //Die templature Fault (High?)
#define USB_FAULT      32 //USB comyunication Fault
#define OVER_SPEED     16 //SPEED Over Warning
#define EM_STOP_OUT     8 //OUTPUT Emargency stop signal 
#define PVM2_FAULT      4 //PVM2 ERROR (LOW?)
#define PVM1_FAULT      2 //PVM1 ERROR (LOW?)
#define BATTERY_FAULT   1 //Battery Voltage (LOW?)

//STATUS 1 definishon
#define BODY_OVH_ERR  128 //RObot Body OVER HEAT (High Templature Error)
#define PVM_OVC_ERR    64 //PVM Line  over current ERROR
#define MOTOR_OVC_ERR  32 //motor_OVER_Cureent Error
#define AXIS9_SPI_ERR  16 //9Axis device SPI comunication ERROR
#define ATMEGA_SPI_ERR  8 //ATMEGA device SPI comunication ERROR
#define DRV_SPI_ERR     4 //Driver SPI comunication ERROR (LOW?)
#define MOTOR_DRV_DIS   2 //disable signal output to motor_pre_driver
#define MOTOR_FAULT     1 //motor predrv output fault signal

//motor driving condition
#define MOT_CIR_ALL_OFF 2 // PVM1,PVM2:off  sel:disEN   pDRV:disEN
#define MOT_PVM_ONLY_ON 6 // PVM1,PVM2:on   sel:disEN   pDRV:disEN
#define MOT_PVM_DRV_ON  7 // PVM1,PVM2:on   sel:disEN   pDRV:Enable
#define MOT_CIR_ALL_ON  5 // PVM1,PVM2:on   sel:Enable  pDRV:Enable

#define WDT_ESTOP_LIMIT_FRM     4    //wdt limit time to EMSTOP 2 farame
#define WDT_FAULT_LIMIT_FRM     8   //wdt limit time1 to FALUT 8 farame(0.5sec)
#define WDT_SHTDWN_LIMIT_FRM     8    //wdt limit time2 to FALUT 8 farame(0.5sec)



/* program flow contl*/
#define	LOG_MODE	0x2    /* set LOGMODE 0x0: sup pulse width(max200us), 0x01 : mot current, 0x02 : mot speed input*/
#define MAX_TRANS_LINE          16          /* Number of trans lines */
#define MAX_SUB_COUNT           32          /* Number of SubCount Value */

/* RS232C comunication control value*/

// for PC to board data 
#define COMMAND_LENGTH          14	          /* Length of command from pc = 14byte*/
#define COMMAND_LENGTH_P        64	          /* Length of New extra command from pc = 64byte*/

// for board to PC data 
#define SEND_DAT_LENGTH         0x91        /* Length of data to pc = 145byte*/
#define OUT2_LENGTH              7         /* Length of each subcycle output2 to pc = 7 byte*/
#define OUT2TAG_LENGTH          33          /* Length of tag data to pc = 33byte*/

// motor control parameer
#define DIRECT_CONT  0x0  /*    direct motor contorol 0x1:Notuse PID cont 0x0:PID     */
#define EM_STOP_EN  0xff  /* set EMARGENCY STOP function 0xff:set 0x0:not set*/
#define SPEED_RATIO 32 		/* input speed value and actual speed (1Km/h) ratio 2^n */	  
                                /* .e.g. 12: 2^12 = 4096 10: 2^10 = 1024 */
/* speed acceraration rate: 1: 1/16 sec 8:0.5sec */	  
#define	USE_MAX_SPEED_CHANGE	1 /* 1: USE , 0: Not USE*/
#define	MAX_SPEED_CHANGE	16 /* acc parame at Normal mode (high speed mode*/

// SPI Sellection drv8323 or PIC,MPU9250
#define SPI_DRV8323_EN  63 // DRV8323 sellect use spi_sel & SPI_DRV8323_EN
#define SPI_PIC_9Axis_EN  64 // DRV8323 sellect use spi_sel | SPI_PIC_9Axis_EN


//9axis board senser control parameter
#define SENSOR  0x1  	/* 	0 : not maeasure 1 : 9axis data measure	*/
//#define SENSOR  0x0	/*	0 : not maeasure 1 : 9axis data measure	*/

// I2C address of devices #01 add 

//#define I2CADXL345 (0x53)  // ADXL345  Accelerometer
//#define I2CITG3200 (0x68)  // ITG-3200 Gyroscope
//#define I2CHMC5883 (0x1e)  // HMC5883L Compass
#define I2CMPU9150	(0x68)  // Accelerometer and gyroscope
#define I2CAK8975	(0x0c)  // Compass

/* motor control PWM constant */

#define	DIRECT	0u    	// 1: direct 0: traditional
#define SIGN0 	0u    	// for motor0 1: minus 0: plus
#define BLK0 	1u		// for motor0 1: break 0: release
#define SIGN1 	0u    	// for motor1 1: minus 0: plus
#define BLK1 	1u		// for motor1 1: break 0: release
#define SIGN2 	0u    	// for motor2 1: minus 0: plus
#define BLK2 	1u		// for motor2 1: break 0: release
#define SIGN3 	0u    	// for motor3 1: minus 0: plus
#define BLK3 	1u		// for motor3 1: break 0: release
#define PWM_PERIOD 	200u		// pwm counter period

/* motor control circuit board polarity */

#define CW0 	1u    	// for motor0 1: cw 0: ccw
#define ENCD0 	1u		// for motor0 1: cw 0: ccw
#define CW1 	0u		// for motor1 1: cw 0: ccw
#define ENCD1 	0u		// for motor1 1: cw 0: ccw
#define CW2 	1u    	// for motor2 1: cw 0: ccw
#define ENCD2 	1u		// for motor2 1: cw 0: ccw
#define CW3 	0u		// for motor3 1: cw 0: ccw
#define ENCD3 	0u		// for motor3 1: cw 0: ccw

/* motor and Wheel assign */
#define MOTORASSIGN_LF    1
#define MOTORASSIGN_RF    0
#define MOTORASSIGN_LR    2
#define MOTORASSIGN_RR    3

/* motor encoder and Wheel assign */
#define ENCASSIGN_LF    1
#define ENCASSIGN_RF    0
#define ENCASSIGN_LR    2
#define ENCASSIGN_RR    3

/* Various Motor Parameter setting*/
#ifdef RE16
//#define	 MAXRPM 14000.0;// RE16
//#define	 GEAR_RATIO 185193.0/2197.0;   //GP16A
#endif
/* Tokusyu Denso, EMC:S14608G-240-6B15G */
//#define	 MAXRPM 4500; //4500.0;
//#define	 GEAR_RATIO 15.0;
//#define	 ENC_CUNT 2048.0; //(512 * 4 = 2048)

/* Tokusyu Denso, EMC:S14666G-240-6B15C */
#ifdef TOKUDEN800
    #define	 MAXRPM 200; //4500.0;
    #define	 GEAR_RATIO 1.0;
    #define	 ENC_CUNT 800.0; //(200 * 4 = 800):
    #define DIM_WHEEL 0.152;  // diamiter of wheel type-N(m)
    #define DIST_WHEEL 0.400;  // diamiter of wheel type-N(m)
    #define SAMP_RATE  256; //v_cntl
#endif

/* Nippoh mecanum Inwheel2, EMC:S14666G-240-6B15C */
#ifdef INWHEEL2
    #define	 MAXRPM 300; //6km/h : 193;
    #define	 GEAR_RATIO 1.0;
    #define	 ENC_CUNT 16384.0; //(4096 * 4 = 800):
    #define DIM_WHEEL 0.165;  // diamiter of wheel type-N(m)
    #define DIST_WHEEL 0.365;  // diamiter of wheel type-N(m)
    #define SAMP_RATE  256; //v_cntl
    #define ENC_MALTI 0 ;       //true enc = ENC_CUNT*2^ENC_MALTI
    #define CALC_RATIO 1 // the counts of calcuration per trace line for 4096 enc
#endif
/* zltech 4inch Inwheel, ZLLG40ASM100 */
#ifdef ZLLG40
    #define	 MAXRPM 300; //6km/h : 294.88;
    #define	 GEAR_RATIO 1.0;
    #define	 ENC_CUNT 4096.0; //(4096 * 4 = 800):
    #define DIM_WHEEL 0.108;  // diamiter of wheel type-N(m)
    #define DIST_WHEEL 0.30;  // diamiter of wheel type-N(m)
    #define SAMP_RATE  256; //v_cntl
    #define ENC_MALTI 0 ;       //true enc = ENC_CUNT*2^ENC_MALTI
    #define CALC_RATIO 1 // the counts of calcuration per trace line for 4096 enc
#endif

/* RE25 gearGP26X ENC MR*/
//#define	 MAXRPM 9690.0;// RE25
//#define	 GEAR_RATIO 226233.0/3179.0;   	//GP26A
//#define	 ENC_CUNT 2048.0; 				//count per round (512 * 4 = 2048)

/* RE50 gearGP52C HEDL5540 typeL*/
//#define	 MAXRPM 5950.0;// RE50
//#define	 GEAR_RATIO 1183.0/18;   //GP52C
//#define	 ENC_CUNT 2000.0; //count per roundHEDL5540
#ifdef EPF50_36
    #define	MAXRPM 6700; //6km/h : 9167  max speed 4.3Km/h;
    #define	GEAR_RATIO 36.0;
    #define	ENC_CUNT 1024.0; //(2048 * 4 / 2^ENC_MULTI = 800):
    #define DIM_WHEEL 0.125;  // diamiter of wheel type-N(m)
    #define DIST_WHEEL 0.4;  // diamiter of wheel type-N(m)
    #define SAMP_RATE  256; //v_cntl
    #define ENC_MALTI 3 ;       //true enc = ENC_CUNT*2^ENC_MALTI
    #define CALC_RATIO 1 // the counts of calcuration per trace line for 4096 enc
#endif






//--------------------------------------------------------------------
// Type Definitions (struct, enumeration, union)
//--------------------------------------------------------------------
        
struct Drv_if_rwbuf{
    uint16 rdwbuf[7];
};  
struct Drv_if_wwbuf{
    uint16 wdwbuf[7];
};        
struct Drv_if_rbuf{
    uint8 rdbuf[14];
};
struct Drv_if_wbuf{
    uint8 wdbuf[14];
};

struct Drv_para{

    uint8 vds_lc :1;
    uint8 vds_hc :1;
    uint8 vds_lb :1;
    uint8 vds_hb :1;
    uint8 vds_la :1;
    uint8 vds_ha :1;
    uint8 otsd :1;
    uint8 uvlo :1;
    uint8 gdf :1;
    
    uint8 vds_ocp :1;
    uint8 fault :1;
    uint8 dummy0 :5;


    uint8 vgs_lc :1;
    uint8 vgs_hc :1;
    uint8 vgs_lb :1;
    uint8 vgs_hb :1;
    uint8 vgs_la :1;
    uint8 vgs_ha :1;
    uint8 cpuv :1;
    uint8 otw :1;
    
    uint8 sc_oc :1;
    uint8 sb_oc :1;
    uint8 sa_oc :1;
    uint8 dummy1 :5;


    uint8 clr_flt :1;   //0
    uint8 brake :1;     //0
    uint8 coast :1;     //0
    uint8 pwm1_dir :1;  //0
    uint8 pwm1_com :1;  //0
    uint8 pwm_mode :2;  //10
    uint8 otw_rep :1;   //0

    uint8 dis_gdf :1;   //0
    uint8 dis_cpuv :1;  //0
    uint8 resereved :1; //0
    uint8 dummy2 :5;

    
    uint8 idriven_hs :4; //0010
    uint8 idrivep_hs :4; //0010

    uint8 lock :3;      //011
    uint8 dummy3 :5;
    

    uint8 idriven_ls :4; //0010
    uint8 idrivep_ls :4; //0010

    uint8 tdrive : 2;   //11
    uint8 cbc : 1;      //1
    uint8 dummy4 :5;


//    uint8 lds_lvl :4;
    uint8 lds_lvl :8;
    uint8 ocp_deg :2;
    uint8 ocp_mode :2;

    uint8 dead_time :2;
    uint8 tretry :1;
    uint8 dummy5 :5;


    uint8 sen_lvl :2;
    uint8 csa_cal_c :1;
    uint8 csa_cal_b :1;
    uint8 csa_cal_a :1;
    uint8 dis_sen :1;
    uint8 csa_gain :2;

    uint8 ls_ref :1;
    uint8 vref_div :1;
    uint8 csa_fet :1;
    uint8 dummy6 :5;

};
 union{
    struct Drv_if_rbuf m_para_set ;
    struct Drv_if_rwbuf m_para_wset ;
    struct Drv_para mpara ;
}motor_para_1;
 union{
    struct Drv_if_wbuf m_para_get ;
    struct Drv_if_wwbuf m_para_wget ;
    struct Drv_para mpara_g ;
}motor_parag_1[4];



//--------------------------------------------------------------------
// Fuction Prototype Decradation
//--------------------------------------------------------------------
        
uint8 main_init(void);
void pc2main(void);
void Sub_Enc(void);
void McpuOP(void);
void Sub_Calc1(void);
void Set_PWM(void);
void McpuOP2(void);
void main2pc(void);

void WheelStop(void);
void Chk_Bumper(void);
void Sensor(void);
void rt_OneStep(void);

void pout(uint);

uint8 spi_drv_init(void);
uint8 spi_drv_read(void);
uint8 spi_drv_set(void);

uint8 subp_init(void);
void variable_initialize(void);
void start_get_die_temp(void);
void get_die_temp(void);
uint8 get_adc_value(uint8,uint8);

void diag_sense(void);

void ini_spi2(void);
uint8 spi_write_byte(uint8, uint8, uint8, uint8);
uint8 spi_read_bytes(uint8, uint8, uint8, uint8);
uint8 spi2_clr_buff(void);
uint8 intmax( uint8, uint8);

uint8 status1_test = 0;
uint8 status2_tset = 0;
//void Calc_Contl(void);
//void TriggerCompass(void);

//void Get_asicdat(void);

//void sub_cpu_get_9axis(void);				//#01
//void Get_IIC(int id);					// #02 add
//void inii2c0(uint8 del);				// #01 add
//void inii2c0dev(void);					// #01 add
//void readi2c1dev(void);
//void readi2c2dev(void);
//void inibkservo(void);
//void setbkservo(uint8 bkval);
//int8 i2c0WriteByte(uint8 devadr, uint8 regadr, uint8 wr_dat, uint8 mask);	//#01 add
//int8 i2c0ReadBytes(uint8 devadr, uint8 regadr, uint8 num, uint8 *val);	//#01 add


//uint8 I2C_recover(int8 k);


//--------------------------------------------------------------------
// Gloval Variable Definition
//--------------------------------------------------------------------
        
/*variable for program flow control */
uint8  frame_count = 0;           // Frame count  1/16 sec count up
uint8  trans_line = MAX_TRANS_LINE -1;           // line count  1/256 sec count up
uint8  sub_cycle_count = MAX_SUB_COUNT -1;       //  sub_cycle in trans line  1/256*32 sec cout_up
uint32 interruptcnt = 0;
uint32 irqt1 = 0;
uint8  seq_code;
uint8  state = BOOT;
uint8  status0 = 0;
uint8  status1 = 0;

uint8 sense_diagflag = 0; // not execute

// ***********Error & fault timeover counters 

uint8   ems_sig_tmover =0 ;  // emstop signul output timeover counter
uint8   ems_pvm_tmover =0 ;  // pvm low voltage error timeover counter
uint8   ems_osp_tmover =0 ;  // over speed error timeover counter
uint8   ems_drv_tmover =0 ;  // driver error detect timeover counter
uint8   flt_dtm_tmover =0 ;  // die temprature high fault timeover counter
uint8   flt_bat_tmover =0 ;  // battery low fault timeover counter
uint8   flt_msw_tmover =0 ;  // main switch off detect timeover counter

/* future check item
uint8   ems_pvc_tmover =0 ;  // Pvm current over error timeover counter
uint8   ems_mtc_tmover =0 ;  // motor drive current over error timeover counter
uint8   ems_btm_tmover =0 ;  // board temprature high error timeover counter
*/
uint8	pvm1 ;
uint8   pvm2 ;

//uint8  Exe_Func = 0;										
//int16	sens9data[10];					// #01 sensor data 9axis
//uint8 val[8];
//int phase=1;         // out_buffer altrnation phase 
//int phase_tr=1;         // out_buffer altrnation phase 
//#01 char command[11];
uint8 command[64];

//for communicate PC and board

uint8 command_buf[64];
uint8 command_para[64];
int32 getcom_count = 0;
int32 getcom_count_buf = 0;
int32 getcom_count_para = 0;
int32 getcom_flag = 0;
int32 getcom_watch = 16;
uint32 no_getcom_loop_cnt = 3;
//int32 comin_value = 0;
uint8 output2_tag_head[3];
uint8 output2[MAX_TRANS_LINE][OUT2_LENGTH];
uint8 output2_tag[OUT2TAG_LENGTH];
//uint8 *buffer;
uint8 outbuff1[59];
uint8 outbuff2[56];
uint8 outbuff3[30];

uint8	motorassign[4]={MOTORASSIGN_RR,MOTORASSIGN_LR,MOTORASSIGN_RF,MOTORASSIGN_LF};
uint8	encassign[4]={ENCASSIGN_RR,ENCASSIGN_LR,ENCASSIGN_RF,ENCASSIGN_LF};

uint8   Status= (uint8)CYRET_UNKNOWN;  

//SPI

uint8 spi_sel;
uint8 tmp[4];
int32 axis9[10];

//ADC or Diagnous

uint8 diag_count = 0;
uint8	adin;
int16	die_temp;
uint8   mes_adc_val;
uint8   bwp_sw;
uint16 dist_front ;
uint16 dist_rear ;
uint16 dist_fr ;
uint16 dist_fl ;
uint16 dist_st ;

int16 die_temp_16 =0;
uint16 v_bat_16 = 0;
uint16 pvm1_16 = 0;
uint16 pvm2_16 = 0;

/* trobot farm status */
uint8   die_status;
uint8   com_status;
//uint8   iic_status;
//uint8   iic_status1;
uint8   trobot_status1;   // time out flag
uint8   trobot_status2;   //  return loop max count 


uint8	loop_max;
int8	die_temp_flag;

int32	output_tmp[4];
//uint8	*out2;
int32	out2pos,
	out2len,
	out2_tagpos=0,
	out2_tag_cycle =0;

//char  *buff = "0.11" ;
//uint8  buff[10] ;
//double suuti ;

/// New set Parameter by K.S 2016.04.18
uint8 drive_wheels = DRIVEWHEELS ;   
float gear_ratio = GEAR_RATIO;
uint8 calc_ratio = CALC_RATIO;
uint8 logmode = LOG_MODE;
uint8 direct_cnt = DIRECT_CONT;
uint8 em_stop_en = EM_STOP_EN ;
int16 speedratio = SPEED_RATIO ;
uint8 use_smooth_chg = USE_MAX_SPEED_CHANGE;
uint16 max_spd_chg = MAX_SPEED_CHANGE;
uint8 measure_sensor = SENSOR;
uint16 max_rpm =MAXRPM; //4500.0;
uint16 gear_motor, gear_output, gear_ratio_i16;
uint16 samp_rate = SAMP_RATE ;
uint16 enc_count = ENC_CUNT ; 
uint16 enc_malti = ENC_MALTI ; 
float dim_wheel = DIM_WHEEL;
float dist_wheel = DIST_WHEEL;
uint16 dim_wheel_i16, dist_wheel_i16;
float toruque_const, speed_const, spd_torq_grad;
uint16 toruque_const_i16, speed_const_i16, spd_torq_grad_i16;
float acc_limit_f, acc_limit_r, acc_limit_s, safty_const ;
uint16 acc_limit_f_i16, acc_limit_r_i16, acc_limit_s_i16, safty_const_i16 ;
float kvp, kcp, kvi, kci, kdl, kdr, satv, satc ;
uint16 kvp_i16, kcp_i16, kvi_i16, kci_i16, kdl_i16, kdr_i16, satv_i16, satc_i16 ;

//float max_speed;  // speed (km/h)
float ratio_rpm;
float rpm2velo_ratio;


// Eencoder count value for each line (1/256) to send data to PC 

int16	ms_lf_pc,	// Left Front wheel
		ms_rf_pc;	// Right Front wheel
int16	ms_lr_pc,	// Left Rear wheel 
		ms_rr_pc;	// Right Rear wheel 

//  Eencoder count value for each line (1/256) to calcurate in main routing

int16	MS_LF_MAIN[3],	// Left Front wheel
		MS_RF_MAIN[3],	// Right Front wheel)
		MS_LR_MAIN[3],	// Left Rear wheel
		MS_RR_MAIN[3];	// Right Rear wheel 

	

        // calcurated PWM pulse width for each LF,RF,LR,RR motor
        
int16 	ms_lf_com_tx, ms_rf_com_tx;
int16 	ms_lr_com_tx, ms_rr_com_tx;

        
        //calcurated pwm pulse value for each motor0,1,2,3
        
int32  	ms00_pw=0,	// motor0 omega & position 
        ms01_pw=0,	// motor1 omega & position 
		ms02_pw=0,	// motor2 omega & position 
		ms03_pw=0;	// motor3 omega & position 

		
uint8	cycle_count = 0;	// cycle count in RTC routine
uint8	cycle_count_buf = 0;	// cycle count in RTC routine
uint8	cycle_count_pre = 0;	// previous cycle count in RTC routine

        
        // Current target speed value 1/256 sec periodic(at smooth mode )

int32	speed_lf=0,	 		// target speed of Left Front wheel  
 	    speed_rf=0,	 		// target speed of Right Front wheel 
	    speed_lr=0,	 		// target speed of Left Rear wheel 
	    speed_rr=0;			// target speed of Right Rear wheel 
        
        // buffer of target speed command from PC 1/16sec periodec

int32	speed_lf_buf=0,     // Left Front wheel  
 	    speed_rf_buf=0,     // Right Front wheel
	    speed_lr_buf=0,     // Left Rear wheel
	    speed_rr_buf=0;     // Right Rear wheel 

        // previous line cycle target speed value 1/256 sec periodic(at smooth mode )

int32 	speed_lf_pre=0,	 	// Left Front wheel
        speed_rf_pre=0,	 	// Right Front wheel
        speed_lr_pre=0,	 	// Left Rear wheel
        speed_rr_pre=0;	 	// Right Rear wheel 


        // target speed increment value from previous line cycle
        // 1/256 sec period before

int32 	speed_lf_delta=0,   // Left Front wheel
        speed_rf_delta=0,   // Right Front wheel
        speed_lr_delta=0,   // Left Rear wheel 
        speed_rr_delta=0;   // Right Rear wheel 


uint8 	pwm_control;
uint8   direct = DIRECT;
uint8 	sign0 = SIGN0;
uint8	blk0 = BLK0;
uint8 	sign1 = SIGN1;
uint8   blk1 = BLK1;
uint8 	sign2 = SIGN2;
uint8	blk2 = BLK2;
uint8 	sign3 = SIGN3;
uint8   blk3 = BLK3;

        // motor0-3 rotation direction
uint8 	cw0 = CW0;
uint8	cw1 = CW1;
uint8 	cw2 = CW2;
uint8	cw3 = CW3;
        
        
        // encoder of motor0-3 rotation direction
uint8	encd0 = ENCD0;
uint8	encd1 = ENCD1;
uint8	encd2 = ENCD2;
uint8	encd3 = ENCD3;

uint8 	pwm_period = PWM_PERIOD;
uint8 	pwm_width0 = 0u;
uint8 	pwm_width1 = 0u;
uint8 	pwm_width2 = 0u;
uint8 	pwm_width3 = 0u;


int32	sendcom_flag = 0;

 //Watch Dog Counter for error detection
uint8 err_wdt_vds_ocp[4];
uint8 err_wdt_gdf[4];
uint8 err_wdt_uvlo[4];
uint8 err_wdt_otsd[4];
uint8 err_wdt_otw[4];
uint8 err_wdt_cpuv[4];
uint8 err_wdt_sa_ocp[4];
uint8 err_wdt_pvm_ocur[2];

uint8 err_wdt_sw_dt;
uint8 err_wdt_die_otp;
uint8 err_wdt_usb_if;
uint8 err_wdt_ov_spd[4];
uint8 err_wdt_em_stop_out;
uint8 err_wdt_pvm_low[2];
uint8 err_wdt_vbat_low;

uint8 err_wdt_body_oh[3];
uint8 err_wdt_pvm_ocpat[2];
uint8 err_wdt_sa_ocpat[4];
uint8 err_wdt_axis9_spi;
uint8 err_wdt_atm_spi;
uint8 err_wdt_drv_spi[4];
uint8 err_wdt_drv_dis;
uint8 err_wdt_mot_fault;
      


//--------------------------------------------------------------------
// Fuction Definition
//--------------------------------------------------------------------
extern void SKLog_sub_cycl_int(void);
extern void debug_main(void);
extern void debug_init(void);
extern void sk_PutString05(char8 *string,uint16 data1,uint16 data2,uint16 data3,uint16 data4);
uint8   sk_bwp_sw;
uint8 	sk_pwm_control,sk_pwm_period,sk_pwm_width0,sk_pwm_width1;

int32					sk_speed_lf_buf	= 0; 
int32    					sk_speed_rf_buf	= 0; 
int32    					sk_speed_lr_buf	= 0; 
int32    					sk_speed_rr_buf	= 0; 
int32					sk_speed_lf	= 0xff; 
int32    					sk_speed_rf	= 0xff; 
int32    					sk_speed_lr	= 0xff; 
int32    					sk_speed_rr	= 0xff; 
int16 sk_ms0_main[4];

extern uint16 sk_log_cnt;

extern sk_int32toChar(char8 *string,int32 data);
extern sk_int16toChar(char8 *string,int16 data);
        
extern void sk_adc_debug(uint8 ad, uint8 data );

extern void SK_1ms_main_loop(void);
extern void SK_10ms_main_loop(void);
extern void SK_100ms_main_loop(void);
extern void SK_1000ms_main_loop(void);
extern void sk_log_int_string(char8 *string);
extern void sk_log_int_float(char *string,float data);
extern void sk_log_int_realT(char *string,float data);
extern uint8       sk_mt_start;
extern void sk_mt_ctrl(uint16 flg);
extern uint16 sk_mt_speed;
extern uint16 sk_input_ofst ;
extern uint16 sk_input_data ;

extern void sk_log_int_uint16(char *string,uint16 dt1, uint16 dt2, uint16 dt3);
/************************************************/
/*	Trobot3 Interrupt routine (every sub_cycle) */
/************************************************/
CY_ISR(InterruptHandler) // 2'hfX
{
	uint8 istat_tmp ; // keep origin routine stat_sequence_code number
  
    
	/* Clear Interrupt */
   	Timer_sub_cycle_STATUS;
    
    
    
	FirstLine_Write(0);
    Sonr_TRG_x4_Write(0);                                  //for sonnor 1/4 sec period
	istat_tmp = (P_out_2_Read()*64+P_out_1_Read()*16+P_out_Read()) ;
	pout(0xf0) ; //2.42us

    

    
    SKLog_sub_cycl_int();
    
    if( sk_log_flg & SK_LOG_SUBCYCL ){
        sk_log_int("CY_ISR",0);

        sk_PutString05("I:S:T:F= ",interruptcnt,sub_cycle_count,trans_line,frame_count);
        
    }
    
    
    // last sub cycle ??
    
	if (sub_cycle_count == MAX_SUB_COUNT - 1){  // 3.9usec
     
		if (interruptcnt == 512 ){  //max feelds? (1/16sec 62.5msec )
            
            if( sk_log_flg & SK_LOG_INTRUPT512 )
                sk_log_int("interruptcnt512 ",0);
            
			FirstLine_Write(1);
			interruptcnt = 0;
			trans_line = 0;
       
            
            if ( frame_count >=15) {
                frame_count = 0 ;        //for sonnor 1/4 sec period
                
                if( sk_log_flg & SK_LOG_FRAME_CNT  )
                sk_log_int("frame_count ",0);
            }
            else {
                frame_count += 1 ;                         //for sonnor 1/4 sec period
            }
            
            if ( frame_count % 4 ==0) {
                Sonr_TRG_x4_Write(1); //for sonnor 1/4 sec period
            }
            
            if ( sense_diagflag == 2){
        		CyWdtClear(); //WDT CLEAR during boot prosess
        	}
		}else{
			trans_line= interruptcnt / MAX_SUB_COUNT ;
		}
    
		interruptcnt++;
		sub_cycle_count = 0;

	
    }else{
		
        sub_cycle_count++;
		interruptcnt++;
		CyGlobalIntDisable;
		CyGlobalIntEnable;
	
    }
    
        #if DEMODE == 1
    		pout(0xf1); //3.31us
        #endif
        #if DEMODE1 == 1
    		pout((uint)trans_line) ;
    		pout((uint)sub_cycle_count) ;
        #endif

	if (interruptcnt == 512){
		//Timer_cycle_Start();
        
        if( sk_log_flg & SK_LOG_CYCLE_START  ){
            sk_log_int("Timer_cycle_WriteCounter", 0);    

        }
                
		Timer_cycle_WriteCounter(0);

	}

	irqt1 = 2;
		
		//P_out_Write(sub_cycle_count) ;

    if ((sub_cycle_count % 8) == 0){    // 0.97msec
        if( sk_log_flg & SK_LOG_SUBCYCL_8P )
            sk_log_int("sub_cycle_count8P",0);

        if( sk_log_flg & SK_LOG_COM_INT  ){
            sk_log_int("Sub_Enc() START ",0); 
        }    
            
		Sub_Enc(); // 0x04 EXECUTE every 8 subcycle

        if( sk_log_flg & SK_LOG_COM_INT  ){
            sk_log_int("Sub_Enc() END ",0); 
        }    
	}
    
    
    // ******* UART comunication PC to Board (command) *********
        #if DEMODE == 1
            
    		pout(0xf2); //13.2us 13.31us
        #endif
    
    no_getcom_loop_cnt=0;

    if( sk_log_flg & SK_LOG_COM_INT  ){
        sk_log_int("pc2main() START ",0); 
    }    

    pc2main();

    if( sk_log_flg & SK_LOG_COM_INT  ){
        sk_log_int("pc2main() END ",0); 
    }    


    // ******* UART comunication PC to Board (command) *********
        #if DEMODE == 1
        	pout(0xf0);//20.71us
        	pout(0xf3);
        #endif
        
    if( sk_log_flg & SK_LOG_COM_INT  ){
        sk_log_int("main2pc() START ",0); 
    }    

    main2pc();

    if( sk_log_flg & SK_LOG_COM_INT  ){
        sk_log_int("main2pc() END ",0); 
    }    

    
// ******* finishing operation return previous stat  *********
        #if DEMODE == 1
        	pout(0xf0);//25.93us
        #endif
        
	pout(istat_tmp);
	
    
            
    if( sk_log_flg & SK_LOG_MAX_SUB_COUNT ){
        sk_log_int_uint16("int,tar,sub = ",(uint16)interruptcnt, trans_line,sub_cycle_count);
    }

	return;
}

//*************************************************
//			Trobot3 MAIN Initialaize routine 				
//*************************************************

uint8 main_init()    // 2'h1X
{
	//cystatus Status;
	//int32	i;
    //uint8 val;
    uint8 ret;
    uint8 j;
    uint8 pvm1,pvm2;
    
    //*******************************************
    //STEP1 : motor_en_reg set(2):
    //  bit2 = "L"      :PVM1,PVM2 OFF 
    //  bit1 = "H"      :motor predrv selector disenable (All output = "L")
    //  bit0 = "L"      :motor predrv(8323) disenable (ALL gate output = "L")
    //*******************************************
    sk_log_main("main_init():001",0);
    motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);     // PVM1,PVM2:off  sel:disEN  pDRV:disEN
    // sense_diagflag = 3;
    //*******************************************
    // STEP2 : PSOC SubProgram Initialize & fundamental env check
    //*******************************************
    ret=subp_init();
    if(0 !=ret){  //shtdown fault occur
        ret += 10;
        return ret;
    }else{
        //PASS to STEP3
    };

   sk_log_main("main_init():002",0);
    //*******************************************
    // STEP3 : (EM_SW condition watch) & PVM1,PVM2 Power on 
    //*******************************************

    //3-0: EM_SW Condition Check
    
        // currentry not imprement in the circuit Board in ver2 Trobot5 
    
    
    //3-1: PVM1 & PVM2 Power on 

    motor_en_reg_Write((uint8)MOT_PVM_ONLY_ON);       // PVM1,PVM2:on  sel:disEN  pDRV:disEN
    
    // need enough time(upto 90ms) to chrage up PVM1,2
    CyDelayUs(30000);
    CyDelayUs(30000);
    CyDelayUs(30000);
  


    if(drive_wheels == 2){  
       sk_log_main("main_init():003",0);
        // 2WD Case
        //3-2: PVM1 Voltage  Check (main battery )
                        
    	adin = 6;
    	seq_code = 0x99;
        pvm1=get_adc_value(adin,seq_code);
        
        j=0;
        while(pvm1 < LOW_VOLTAGE){  //32:normal
            if(j>=3){
            status0 |= PVM1_FAULT ;
            state = EMSTOP;
                output2_tag[28]=state;
                output2_tag[30]=status0;

                motor_en_reg_Write((uint8)MOT_PVM_DRV_ON); 
                sk_PutString01("ESTOP05",CRLF_ON);

                return 20 ;
            }else{
                // make 90ms wait 
                CyDelayUs(30000);  
                CyDelayUs(30000); 
                CyDelayUs(30000); 
            	adin = 6;
            	seq_code = 0x99;
                pvm1=get_adc_value(adin,seq_code);
                ++j;
            }
        }
   

    }else{
               sk_log_main("main_init():004",0);

        // 4WD Case 
        //3-3: PVM2 Voltage  Check (main battery )
    	adin = 6;
    	seq_code = 0x99;
        pvm1=get_adc_value(adin,seq_code);
        
        adin = 7;
    	seq_code = 0x9a;
        pvm2=get_adc_value(adin,seq_code);

        j=0;
        while(pvm1 < LOW_VOLTAGE ||pvm2 < LOW_VOLTAGE ){  //32:normal
            if(j>=3){
                if (pvm1 < LOW_VOLTAGE){
                    status0 |= PVM1_FAULT ;
                }
                if (pvm2 < LOW_VOLTAGE){
                    status0 |= PVM2_FAULT ;
                }

                state = EMSTOP;
                output2_tag[28]=state;
                output2_tag[30]=status0;

                motor_en_reg_Write((uint8)MOT_PVM_DRV_ON); 
                sk_PutString01("ESTOP06",CRLF_ON);

                return 20 ;
            }else{
                // make 90ms wait 
                CyDelayUs(30000);  
                CyDelayUs(30000); 
                CyDelayUs(30000); 
            	
                adin = 6;
            	seq_code = 0x99;
                pvm1=get_adc_value(adin,seq_code);
        
                adin = 7;
            	seq_code = 0x9a;
                pvm2=get_adc_value(adin,seq_code);
                
                ++j;
            }
        }
        
    }

 
    //*******************************************
    // STEP4 : MOTOR PRE DRV ENABLE & check condition 
    //*******************************************
    motor_en_reg_Write((uint8)MOT_PVM_DRV_ON);       // PVM1,PVM2:on  sel:disEN  pDRV:Enable
    CyDelayUs(1000);

    j=0;
    while(!(MOTOR_FAULT_Read()& 0X01)){  
        if(j>=3){
            status0 |= MOTOR_FAULT ;
            state = EMSTOP;
            if(0 != spi_drv_read()){
                status1 |= DRV_SPI_ERR ;
            };    

            motor_en_reg_Write((uint8)MOT_PVM_DRV_ON); 
            sk_PutString01("ESTOP07",CRLF_ON);

            return 40;
        }else{
            // make 90ms wait 
            CyDelayUs(30000);  
            CyDelayUs(30000); 
            CyDelayUs(30000); 
            ++j;
        }
    }

    
    //*******************************************
    // STEP5 : Motor Pre DRV set to 1Xmode 
    //*******************************************
    j=0;
    while(0 !=spi_drv_init()){  
        if(j>=3){
            status0 |= MOTOR_FAULT ;
            status1 |= DRV_SPI_ERR ; //spi comunication error
            state = EMSTOP;
            if(0 != spi_drv_read()){
                status1 |= DRV_SPI_ERR ;
            };    

            motor_en_reg_Write((uint8)MOT_PVM_DRV_ON); 
            sk_PutString01("ESTOP08",CRLF_ON);

            return 50;
        }else{
            // make 90ms wait 
            CyDelayUs(30000);  
            CyDelayUs(30000); 
            CyDelayUs(30000); 
            ++j;
        }
    }
    
    //*******************************************
    // STEP6 : selector for Input of Motor Pre DRV ENABLE  
    //*******************************************
   
    // input of Ti motor drv change  select to hole sencer  output 
    motor_en_reg_Write((uint8)MOT_CIR_ALL_ON);       // PVM1,PVM2:on  sel:enable  pDRV:enable
    
    if(!(MOTOR_FAULT_Read()&0X01)){
        if(0 != spi_drv_read()){
            status1 |= DRV_SPI_ERR ;
        };
        status0 |= MOTOR_FAULT ;
        state = EMSTOP;
        motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);       // PVM1,PVM2:off  sel:disEN  pDRV:disEN  
        sk_PutString01("ESTOP09",CRLF_ON);
        ret =60;
        return ret ;
    }
    else{
        //PASS  finish INITIALIZE & Check
    }
    motor_en_reg_Write((uint8)MOT_PVM_DRV_ON);       // PVM1,PVM2:on  sel:disEN  pDRV:Enable

    //state=IDLE;
	//CyWdtStart(CYWDT_128_TICKS, CYWDT_LPMODE_NOCHANGE);
    return ret ; //return noerror ret=0    j=0;
    while(!(MOTOR_FAULT_Read()&0X01)){  
        if(j>=3){
            status0 |= MOTOR_FAULT ;
            if(0 != spi_drv_read()){
                status1 |= DRV_SPI_ERR ;
            };    
            state = EMSTOP;

            motor_en_reg_Write((uint8)MOT_PVM_DRV_ON); 
            sk_PutString01("ESTOP10",CRLF_ON);

            return 50;
        }else{
            // make 90ms wait 
            CyDelayUs(30000);  
            CyDelayUs(30000); 
            CyDelayUs(30000); 
            ++j;
        }
    }

}



//*************************************************
//			Trobot3-V ver2 MAIN Function				
//*************************************************
	int main() 	 // 2'h1X
{
    uint8 ret;
    uint16 i ;
    uint8 j ;
    
    pout(0x00);
    
    sk_log_main("main():001",0);
    
    sk_uart_init();
    SK_Rtc_init();
    
    sk_log_main("main():002",0);
    
    //diagnostics selftest 
    ret = SelfTest_CPU_Registers();
    if(ret!=0) pout(0x99)      ;
    // start Initialize and Initial Diagnostics 
	ret = main_init();

    sk_log_main("main():003",0);

    if(ret != 0){
        //state = EMSTOP;  //Initial diag error stop PVM
    }
    ret =0;
    // start die temprature measure 
    if(state != SHUTDWN){
        start_get_die_temp();
   	    sense_diagflag = 0 ;
    }

    
    output2_tag[28]=state;
    output2_tag[29]=status1;
    output2_tag[30]=status0;

    debug_init();
    
//		TP_1_Write(0) ;      //end marker

	// ********* main routine start *********
	
	while(1){
        debug_main();
        debug_menue();
        CyWdtClear(); //WDT CLEAR during boot prosess
        
        
       

        if( Check_0001ms() == TM_ON ){
            SK_1ms_main_loop();
        }
        if( Check_0010ms() == TM_ON ){
             SK_10ms_main_loop();
        
        }
        if( Check_0100ms() == TM_ON ){
            SK_100ms_main_loop();
        }
        if( Check_1000ms() == TM_ON ){
            SK_1000ms_main_loop();
        }
        
        
        
        


        
            #if DEMODE == 1
            	pout(0x10) ;				
		if (irqt1==2){
            sk_log_main("main():004",0);
            #endif
//		if (irqt1==2 && ((state == IDLE)||(state == DRIVE))){
                #if DEMODE == 1
                	pout(0x11) ;	//11L:37.53us			
					pout((uint)speed_lf_buf) ;
					pout(0x11) ;    //11L:40.04us //12L:31.92us 
                #endif
                #if DEMODE1 == 1					
					pout((uint)speed_lf_buf) ;
					pout(0x11) ;
					pout((uint)speed_rf_buf) ;
					pout(0x11) ;
//					pout((uint)speed_lr_buf) ;
//					pout(0x11) ;
//					pout((uint)speed_rr_buf) ;
//					pout(0x11) ;
                #endif
			switch(sub_cycle_count){
                case 10:


                #if DEMODE == 1
                        	pout(0x12);		//33.6us			
                        #endif
					McpuOP();  //2'h5X
                        #if DEMODE == 1
                        	pout(0x13);					
                        #endif
				    output2_tag[28]=state;
                    output2_tag[29]=status1;
                    output2_tag[30]=status0;
                #if CALC_RATIO ==2
                    case 26:
                #endif
                        
                        
					Sub_Calc1();  // 2'h7X
                        #if DEMODE == 1
                        	pout(0x14);		//409.51us			
                        #endif
					 
                        #if DEMODE == 1
                        	pout(0x15);     //419.49us
                        #endif


                        irqt1 = 0;
					break;
//				case 16:
				case 16:
                        #if DEMODE == 1
                        	pout(0x17);					
                        #endif
					McpuOP2();

                        #if DEMODE == 1
                        	pout(0x10);					
                        #endif
					irqt1 = 0;
					break;
				case 20:
                        #if DEMODE == 1
                        	pout(0x20);					
                        #endif

                        
                    diag_sense();
                        
                        #if DEMODE == 1
                        	pout(0x10);					
                        #endif
 					irqt1 = 0;
					break;
                        
                case 24:
            // sk_log_main("main():005",0);

                    // Sensor();  // trans line 14 //11L:45.2us
                    //                    start_get_die_temp();
                    //Diagnostic(); // transline 11 start 13 getdata

                    irqt1 = 0;
                     break;

				case 31:
					if(trans_line == 12){
                            #if DEMODE == 1
                            	pout(0x1e);					
                            #endif
						//CyWdtClear();
					}
                        #if DEMODE == 1
                        	pout(0x10);					
                        #endif
					irqt1 = 0;
					break;
				default:
					irqt1 = 0;					
					break;
			}
		}
		else{
			CyDelayUs(10);
		}




            #if DEMODE == 1
            	pout(0x10);					
            #endif

	}		
}

// ********* main routine end *********


//**************************************************
// PC2Mcpu recieve transfer using RS232C Rountine 
//**************************************************

void pc2main(void)   	// 2'h2X
{
            
            //target speed command increment from previous PC command
            // 1/16sec period before
    
    int32	speed_lf_change;    // Left Front wheel
    int32	speed_rf_change;    // Right Front wheel
    int32	speed_lr_change;    // Left Rear wheel
    int32	speed_rr_change;    // Right Rear wheel


	float   change_ratio ;  // 2016.0304 by K.sakashita

    int8 i ;
    uint8 ret ;
    
    char l_output[30];
    
    
        #if DEMODE == 1
    		pout(0x20);  //14.92us 8L:15.27us
        #endif
	
        
        
        
        
    if((sub_cycle_count == 0)&&(trans_line == 8)) {
            #if DEMODE == 1						
				pout(0x21);  //16.01us
            #endif
            #if DEMODE == 1
				pout(no_getcom_loop_cnt) ;
			    //CyDelayUs(1); // 1us wait
            #endif

		if(no_getcom_loop_cnt < 3){
		}else{
                #if DEMODE == 1						
						pout(0x2f);
                #endif
			WheelStop();
		}
   	}           
    
    
    //USB data pre get from PC but  wait 8 transline and 0sub count 
    
	if (USBUART_1_DataIsReady()!=0){ //usb にデータが到着していたら’０’以外　nide-ta gatoutyakusiteitara 0igai 
            #if DEMODE == 1						
						pout(0x22);
            #endif
//    	getcom_flag = 0; //command receive compleate
    	getcom_count_buf = 0; // received command byte
		getcom_count_buf = USBUART_1_GetAll(&command_buf[getcom_count_buf]);
            #if DEMODE1 == 1
				pout(getcom_count_buf) ;
			    //CyDelayUs(1); // 1us wait
		        //TP_1_Write(0) ;
                pout(loop_max);
            #endif
		if(getcom_count_buf > loop_max){
                #if DEMODE == 1						
						pout(0x23);
                #endif
			loop_max = getcom_count_buf;
			trobot_status2 = loop_max;
        }
        if((command_buf[0]==0x02)&&(command_buf[1]==5)&&(command_buf[2]==COMMAND_LENGTH)&&(command_buf[COMMAND_LENGTH-1]==0x03)){
             if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
                sk_log_int("Moter Ctrl Command Rcv ", 0 );
            }
            
            
            i=0;
                #if DEMODE == 1
                	pout(0x29);			
                #endif
            while(i < command_buf[2]){
                command[i]=command_buf[i];
                i++;
            }
            getcom_count=getcom_count_buf;
            getcom_flag = 0; //command receive compleate

        }else if((command_buf[0]==0x54)&&(command_buf[1]==command_buf[2])&&(command_buf[3] == 0x16)){  //frame format ('T'=0x54)
             if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
                sk_log_int("Command Param Rcv ", 0 );
            }
            i=0;
                #if DEMODE == 1
                	pout(0x2a);			
                #endif
            while(i < 64){
                command_para[i]=command_buf[i];
                i++ ;
            }
            getcom_count_para = getcom_count_buf;
            getcom_flag = 0; //command receive compleate

        }
        CyWdtClear();
    }else if (state == SHUTDWN){
        CyWdtClear();
    }else{
        no_getcom_loop_cnt++;

    }
    
    
        #if DEMODE == 1						
			pout(0x24);			//16.93us 8L:18.5us
        #endif
        #if DEMODE1 == 1
			pout(getcom_count_buf) ;
			pout(0x24);
		    //CyDelayUs(1); // 1us wait
        #endif
        
        
	
	if(getcom_flag == 0){
            #if DEMODE == 1						
				pout(0x25);		//8L:20.21us
            #endif
            #if DEMODE1 == 1
				pout(getcom_count) ;
				pout(0x25);
				pout(getcom_count_para) ;
				pout(0x25);
			    //CyDelayUs(1); // 1us wait
            #endif
		if((getcom_count_para != COMMAND_LENGTH_P)&&(getcom_count >= COMMAND_LENGTH)){

				com_status |= 2;
		}
        if((getcom_count % COMMAND_LENGTH) != 0){
			com_status |= 4;
		}
		if((getcom_count / COMMAND_LENGTH) > 2){
			com_status |= 8;
		}

        
        //
        //Speed set from PC
        //
        if( sk_log_flg4 & SK_LOG4_MOT_START   ){
            if( sk_log_flg5 & SK_LOG5_PWM_CALUC   ){
                sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
                 if(sk_mt_start == 1){
                    // sk_log_flg4 |= SK_LOG4_SUB_CALC1;
                    sk_mt_start =0;
                    sk_log_cnt =0;
                }
            }
            else{
                if(sk_mt_start == 1){
                    //sk_log_flg4 |= SK_LOG4_SUB_CALC1;
                    sk_log_int_string("**** MT START ***** ");
                    sk_mt_start =0;
                    sk_log_cnt =0;
                
                }
            }
            CyDelayUs(5); // 5us wait
            if((state == IDLE )||(state == DRIVE)){
				speed_lf_buf	= sk_mt_speed; 
				speed_rf_buf	= sk_mt_speed; 
                speed_lr_buf	= 0; 
				speed_rr_buf	= 0; 
            }
            
            if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
                if( sk_log_cnt > 900 ){
                    sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
                }
                sk_log_int_string("Morter Start 00");
                sk_log_int_int32("speed_lf_buf =  ", speed_lf_buf);
                sk_log_int_int32("speed_rf_buf  =  ", speed_rf_buf );
                sk_log_int_int32("speed_lf =  ", speed_lf);
                sk_log_int_int32("speed_rf  =  ", speed_rf );

                sk_log_cnt+=5;
            }
            
            
            
            // calcurate required speed change 
                    
			getcom_watch = 16;
			speed_lf_change = speed_lf_buf - speed_lf;
			speed_rf_change = speed_rf_buf - speed_rf;
			speed_lr_change = speed_lr_buf - speed_lr;
			speed_rr_change = speed_rr_buf - speed_rr;


            // calcurate approval speed according to the MAX change 

			if((speed_lf_change + speed_rf_change + speed_lr_change + speed_rr_change)!=0){   //直進方向の速度変化のみを取り出す    									//20170721 K.S			
				change_ratio=(float)(drive_wheels*(uint32)max_spd_chg)/(abs(speed_lf_change + speed_rf_change + speed_lr_change + speed_rr_change)) ; 	//20170721 K.S
				if(change_ratio < 1){
					speed_lf_buf = speed_lf + (int32)((speed_lf_change * change_ratio)) ;
					speed_rf_buf = speed_rf + (int32)((speed_rf_change * change_ratio)) ;
					speed_lr_buf = speed_lr + (int32)((speed_lr_change * change_ratio)) ;
					speed_rr_buf = speed_rr + (int32)((speed_rr_change * change_ratio)) ;
				}
			}
            
            if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
                if( sk_log_cnt > 900 ){
                    sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
                }
                sk_log_int_string("Morter Start 01");
                //sk_log_int_int32("speed_lf_buf =  ", speed_lf_buf);
                //sk_log_int_int32("speed_rf_buf  =  ", speed_rf_buf );
                //sk_log_int_int32("speed_lf =  ", speed_lf);
                //sk_log_int_int32("speed_rf  =  ", speed_rf );

                sk_log_int_int32("speed_lf_change =  ", speed_lf_change);
                sk_log_int_int32("speed_rf_change  =  ", speed_rf_change );
                
                sk_log_int("drive_wheels = ", drive_wheels);
                sk_log_int("max_spd_chg = ", (uint16) max_spd_chg);
                sk_log_int_float("change_ratio = ", change_ratio );
            
                sk_log_cnt += 6;
            }
                        

			getcom_count = 0;
			getcom_flag = 1;
			no_getcom_loop_cnt = 0;
        }
        else if(getcom_count == COMMAND_LENGTH){
            
            if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
                sk_log_int("Moter Ctrl Command Rcv ", 1 );
            }
            
                        #if DEMODE == 1						
    						pout(0x26); //23.01us
                        #endif
					CyDelayUs(5); // 5us wait
					
                    //
                    // read speed data from command
                    //
					cycle_count_buf = command[12];
                    if( sk_log_flg2 & SK_LOG2_CYCLE_CNT ){
                        sk_log_int("cycle_count_buf = ",cycle_count_buf);
                    }
                    
                    if((state == IDLE )||(state == DRIVE)){
    					speed_lf_buf	= (int32)((int8)command[4]); 
    					speed_lf_buf	= (int32)(((uint32)speed_lf_buf<<8)+(uint8)command[5]); 
    					speed_rf_buf	= (int32)((int8)command[6]); 
    					speed_rf_buf	= (int32)(((uint32)speed_rf_buf<<8)+(uint8)command[7]); 
    					speed_lr_buf	= (int32)((int8)command[8]); 
    					speed_lr_buf	= (int32)(((uint32)speed_lr_buf<<8)+(uint8)command[9]); 
    					speed_rr_buf	= (int32)((int8)command[10]); 
    					speed_rr_buf	= (int32)(((uint32)speed_rr_buf<<8)+(uint8)command[11]); 
                    }else{
     					speed_lf_buf	= 0; 
    					speed_lf_buf	= 0; 
    					speed_rf_buf	= 0; 
    					speed_rf_buf	= 0; 
    					speed_lr_buf	= 0; 
    					speed_lr_buf	= 0; 
    					speed_rr_buf	= 0; 
    					speed_rr_buf	= 0; 
                   }

                    //
                    // for debud 
                    //
                    
                    if( sk_log_flg4 & SK_LOG4_PWM_DATA  ){
                        if(sk_speed_lf_buf	!= speed_lf_buf ){
                            sk_speed_lf_buf	= speed_lf_buf	; 
                            l_output[0]='L';
                            l_output[1]='F';
                            l_output[2]=':';
                            
                            sk_int32toChar(&l_output[3],(uint32) speed_lf_buf);
                            sk_log_int_string(l_output);
                        }
    					if( sk_speed_rf_buf	!= speed_rf_buf){
                            sk_speed_rf_buf	= speed_rf_buf	; 
                            l_output[0]='R';
                            l_output[1]='F';
                            l_output[2]=':';
                            
                            sk_int32toChar(&l_output[3],(uint32) speed_rf_buf);
                            sk_log_int_string(l_output);
                        }
                    
                        //
                        // 以下は4駆動の時に使用
                        //
                        
    					if( sk_speed_lr_buf	!= speed_lr_buf ){
                            sk_speed_lr_buf	= speed_lr_buf	; 
                            l_output[0]='L';
                            l_output[1]='R';
                            l_output[2]=':';
                            sk_int32toChar(&l_output[3],(uint32) speed_lr_buf);
                            sk_log_int_string(l_output);
    					}
                        
                        if( sk_speed_rr_buf	!= speed_rr_buf ){
                           
                            sk_speed_rr_buf	= speed_rr_buf	; 
                            l_output[0]='R';
                            l_output[1]='R';
                            l_output[2]=':';
                            sk_int32toChar(&l_output[3],(uint32) speed_rr_buf);
                            sk_log_int_string(l_output);
                        }
                    }
                    
                    
                    
                    
                    //
                    // Check stop conditin and over write speed_xx_buf data
                    //

                    // Bumper Switch check 
                    
                    if(em_stop_en != 0)Chk_Bumper(); // em_stop_en != 0 check bmp sw
                    
                    // robot status check : faults and EM_stop
                   
                    if((state != DRIVE)&&(state != IDLE))WheelStop(); // em_stop_en != 0 check bmp sw

                    // calcurate required speed change 
                    
					getcom_watch = 16;
					speed_lf_change = speed_lf_buf - speed_lf;
					speed_rf_change = speed_rf_buf - speed_rf;
 					speed_lr_change = speed_lr_buf - speed_lr;
					speed_rr_change = speed_rr_buf - speed_rr;

                    if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
                        sk_log_int("Moter Ctrl Command Rcv ", 2 );
                    }
                                        
	 					#if DEMODE1 == 1						
							pout((uint)max_spd_chg);
						    CyDelayUs(1); // 1us wait
							pout((uint)speed_lf_change);
						    CyDelayUs(1); // 1us wait
							pout((uint)speed_rf_change);
						#endif

                    // calcurate approval speed according to the MAX change 

					if((speed_lf_change + speed_rf_change + speed_lr_change + speed_rr_change)!=0){   //直進方向の速度変化のみを取り出す    									//20170721 K.S			
						change_ratio=(float)(drive_wheels*(uint32)max_spd_chg)/(abs(speed_lf_change + speed_rf_change + speed_lr_change + speed_rr_change)) ; 	//20170721 K.S
						if(change_ratio < 1){
                                #if DEMODE == 1						
            						pout(0x27);
                                #endif
                                
                                
                            if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
                                sk_log_int("Moter Ctrl Command Rcv ", 3 );
                            }

							speed_lf_buf = speed_lf + (int32)((speed_lf_change * change_ratio)) ;
							speed_rf_buf = speed_rf + (int32)((speed_rf_change * change_ratio)) ;
							speed_lr_buf = speed_lr + (int32)((speed_lr_change * change_ratio)) ;
							speed_rr_buf = speed_rr + (int32)((speed_rr_change * change_ratio)) ;
						}
                            #if DEMODE1 == 1						
        						pout(speed_lf_buf);
        						pout(0x20);
        						pout(speed_rf_buf);
                            #endif
					}


					getcom_count = 0;
					getcom_flag = 1;
					no_getcom_loop_cnt = 0;
        }
        
        //
        // parameter set form PC
        //
		
        if(getcom_count_para == COMMAND_LENGTH_P){
                #if DEMODE == 1
                	pout(0x28);			
        // 		            TP_1_Write(1) ;
                #endif
            motor_en_reg_Write((uint8)MOT_PVM_DRV_ON);       // PVM1,PVM2:on  sel:disenable  pDRV:enable

                #if DEMODE1 == 1
        			pout(getcom_count_para);
        			CyDelayUs(1); // 5us wait	
                #endif

// 		            TP_1_Write(0) ;

            logmode 		= (uint8)3 & (uint8)command_para[4];                        // 2 bit0-1
			direct_cnt 		= (uint8)(((uint8)4 &(uint8)command_para[4])>>2);           // 0 bit2
			em_stop_en		= (uint8)(((uint8)8 &(uint8)command_para[4])>>3);           // 0 bit3  
			use_smooth_chg	= (uint8)(((uint8)16 &(uint8)command_para[4])>>4);          // 1 bit4
			measure_sensor 	= (uint8)(((uint8)32 &(uint8)command_para[4])>>5);          // 1 bit5(2WD/4WD)
			drive_wheels 	= (uint8)(((((uint8)64 &(uint8)command_para[4])>>6)+1)*2);  // 2 bit6 2or4 
            
			speedratio		= (int16)((int8)command_para[5]);
			speedratio		= (int16)(((uint16)speedratio	<<8)+(uint8)command_para[6]);
			max_spd_chg		= (int16)((int8)command_para[7]);
			max_spd_chg		= (int16)(((uint16)max_spd_chg	<<8)+(uint8)command_para[8]);
            
            // Assign MOT 11 10 01 00
			motorassign[0] 	= (uint8)((uint8)3 &(uint8)command_para[9]);        //Wheel LF (wheel left:2WD)
			motorassign[1] 	= (uint8)(((uint8)12 &(uint8)command_para[9])>>2);  //Wheel RF (wheel right:2WD)
			motorassign[2] 	= (uint8)(((uint8)48 &(uint8)command_para[9])>>4);  //Wheel LR (non:2WD)
			motorassign[3] 	= (uint8)(((uint8)192 &(uint8)command_para[9])>>6); //Wheel RR (non:2WD)
            
            // Assign ENC 11 10 01 00 
			encassign[0] 	= (uint8)((uint8)3 &(uint8)command_para[10]);           // 00
			encassign[1] 	= (uint8)(((uint8)12 &(uint8)command_para[10])>>2);     // 01
			encassign[2] 	= (uint8)(((uint8)48 &(uint8)command_para[10])>>4);     // 10 
			encassign[3] 	= (uint8)(((uint8)192 &(uint8)command_para[10])>>6);    // 11
            
            // Sig Direction  0110 1001 --> 0110 0011
			cw0 			= (uint8)((uint8)1 &(uint8)command_para[11]);           // 1 -> 1
			cw1 			= (uint8)(((uint8)4 &(uint8)command_para[11])>>2);      // 0 -> 0
            cw2  			= (uint8)(((uint8)16 &(uint8)command_para[11])>>4);     // 0 -> 0
			cw3  			= (uint8)(((uint8)64 &(uint8)command_para[11])>>6);     // 1 -> 1
			
            encd0 			= (uint8)(((uint8)2 &(uint8)command_para[11])>>1);      // 0 -> 1
            encd1 			= (uint8)(((uint8)8 &(uint8)command_para[11])>>3);      // 1 -> 0
			encd2   		= (uint8)(((uint8)32 &(uint8)command_para[11])>>5);     // 1 -> 1
			encd3  			= (uint8)(((uint8)128 &(uint8)command_para[11])>>7);    // 0 -> 0
			
                #if DEMODE1 == 1
					pout(encd0*16+cw0);
					pout(0x2a);
					pout(encd1*16+cw1);
					pout(0x2a);
				#endif
			
/* 1111111111111111111111111111   */
            enc_malti		= (uint16)((uint8)command_para[12]);
			max_rpm 		= (int16)((int8)command_para[13]);
			max_rpm 		= (int16)(((uint16)max_rpm<<8)+(uint8)command_para[14]);
			gear_ratio_i16	= (int16)((int8)command_para[15]);
			gear_ratio_i16	= (int16)(((uint16)gear_ratio_i16<<8)+(uint8)command_para[16]);
			samp_rate		= (int16)((int8)command_para[17]); 
			samp_rate		= (int16)(((uint16)samp_rate<<8)+(uint8)command_para[18]); 
			enc_count		= (int16)((int8)command_para[19]);
			enc_count		= (int16)(((uint16)enc_count<<8)+(uint8)command_para[20]);
			dim_wheel_i16	= (int16)((int8)command_para[21]); 
			dim_wheel_i16	= (int16)(((uint16)dim_wheel_i16<<8)+(uint8)command_para[22]); 
			dist_wheel_i16	= (int16)((int8)command_para[23]);
			dist_wheel_i16	= (int16)(((uint16)dist_wheel_i16<<8)+(uint8)command_para[24]);

			toruque_const_i16	= (int16)((int8)command_para[25]); 
			toruque_const_i16	= (int16)(((uint16)toruque_const_i16<<8)+(uint8)command_para[26]); 
			speed_const_i16	= (int16)((int8)command_para[27]); 
			speed_const_i16	= (int16)(((uint16)speed_const_i16<<8)+(uint8)command_para[28]); 
			spd_torq_grad_i16	= (int16)((int8)command_para[29]);
			spd_torq_grad_i16	= (int16)(((uint16)spd_torq_grad_i16<<8)+(uint8)command_para[30]);
			acc_limit_f_i16	= (int16)((int8)command_para[31]); 
			acc_limit_f_i16	= (int16)(((uint16)acc_limit_f_i16<<8)+(uint8)command_para[32]); 
			acc_limit_r_i16	= (int16)((int8)command_para[33]<<8); 
			acc_limit_r_i16	= (int16)(((uint16)acc_limit_r_i16<<8)+(uint8)command_para[34]); 
			acc_limit_s_i16	= (int16)((int8)command_para[35]); 
			acc_limit_s_i16	= (int16)(((uint16)acc_limit_s_i16<<8)+(uint8)command_para[36]); 
			safty_const_i16 	= (int16)((int8)command_para[37]);
			safty_const_i16 	= (int16)(((uint16)safty_const_i16<<8)+(uint8)command_para[38]);


			kvp_i16			= (int16)((int8)command_para[39]); 
			kvp_i16			= (int16)(((uint16)kvp_i16<<8)+(uint8)command_para[40]); 
			kcp_i16			= (int16)((int8)command_para[41]); 
			kcp_i16			= (int16)(((uint16)kcp_i16<<8)+(uint8)command_para[42]); 
			kvi_i16			= (int16)((int8)command_para[43]); 
			kvi_i16			= (int16)(((uint16)kvi_i16<<8)+(uint8)command_para[44]); 
			kci_i16			= (int16)((int8)command_para[45]); 
			kci_i16			= (int16)(((uint16)kci_i16<<8)+(uint8)command_para[46]); 
			kdl_i16			= (int16)((int8)command_para[47]); 
			kdl_i16			= (int16)(((uint16)kdl_i16<<8)+(uint8)command_para[48]); 
			kdr_i16			= (int16)((int8)command_para[49]); 
			kdr_i16			= (int16)(((uint16)kdr_i16<<8)+(uint8)command_para[50]); 
			satv_i16		= (int16)((int8)command_para[51]); 
			satv_i16		= (int16)(((uint16)satv_i16<<8)+(uint8)command_para[52]); 
			satc_i16		= (int16)((int8)command_para[53]);
			satc_i16		= (int16)(((uint16)satc_i16<<8)+(uint8)command_para[54]);
            motor_para_1.m_para_wset.rdwbuf[2]= (uint16)(((uint16)command_para[55]<<4)+(uint8)(command_para[56]>>4));

            // bellow 3 motor parameter not changed by application for safty 20210109 K.S.
            motor_para_1.mpara.pwm1_com =0;  // synclonous mode
            motor_para_1.mpara.pwm_mode = 2;  // 1x MODE
            motor_para_1.mpara.otw_rep = 0;   // OTW error Enable

            motor_para_1.m_para_wset.rdwbuf[3]= (uint16)((((uint16)command_para[56]<<8)&0X0F00)+(uint8)command_para[57]);
            motor_para_1.m_para_wset.rdwbuf[4]= (uint16)(((uint16)command_para[58]<<4)+(uint8)(command_para[59]>>4));
            motor_para_1.m_para_wset.rdwbuf[5]= (uint16)((((uint16)command_para[59]<<8)&0X0F00)+(uint8)command_para[60]);
            motor_para_1.m_para_wset.rdwbuf[6]= (uint16)(((uint16)command_para[61]<<4)+(uint8)(command_para[62]>>4));
            
			gear_ratio		=((float)gear_ratio_i16)/100;
			dim_wheel 		=((float)dim_wheel_i16)/1000;
			dist_wheel 		=((float)dist_wheel_i16)/1000;
			toruque_const	=((float)toruque_const_i16)/100; 
			speed_const	 	=((float)speed_const_i16)/100;  
			spd_torq_grad	=((float)spd_torq_grad_i16)/100; 
			acc_limit_f		=((float)acc_limit_f_i16)/1000;  
			acc_limit_r		=((float)acc_limit_r_i16)/1000;  
			acc_limit_s		=((float)acc_limit_s_i16)/1000;  
			safty_const 	=((float)safty_const_i16)/100; 
			kvp				=((float)kvp_i16)/100;  
			kcp				=((float)kcp_i16)/100;  
			kvi				=((float)kvi_i16)/100;  
			kci				=((float)kci_i16)/100;  
			kdl				=((float)kdl_i16)/100;  
			kdr				=((float)kdr_i16)/100;  
			satv			=((float)satv_i16)/100;  
			satc 			=((float)satc_i16)/100; 
			
			Motor_Contl4_3_P.Gain_Gain  = kvp;
			Motor_Contl4_3_P.Gain2_Gain = kvi;
			Motor_Contl4_3_P.Gain_Gain_a  = kvp;
			Motor_Contl4_3_P.Gain2_Gain_a = kvi;
			Motor_Contl4_3_P.Gain_Gain_i  = kvp;
			Motor_Contl4_3_P.Gain2_Gain_e = kvi;
			Motor_Contl4_3_P.Gain_Gain_o  = kvp;
			Motor_Contl4_3_P.Gain2_Gain_j = kvi;

			Motor_Contl4_3_P.Saturation_UpperSat= satv ;
			Motor_Contl4_3_P.Saturation_LowerSat= -satv ;
			
			Motor_Contl4_3_P.Saturation_UpperSat_o= satv ;
			Motor_Contl4_3_P.Saturation_LowerSat_j= -satv ;

            Motor_Contl4_3_P.Saturation_UpperSat_j= satv ;
			Motor_Contl4_3_P.Saturation_LowerSat_a= -satv ;
			
			Motor_Contl4_3_P.Saturation_UpperSat_g= satv ;
			Motor_Contl4_3_P.Saturation_LowerSat_l= -satv ;

/* 222222222222222222222*/

			rpm2velo_ratio=0.06/gear_ratio*calc_ratio*dim_wheel*3.141516; //rpm to speed(Km/h) Coef
			//max_speed = max_rpm*rpm2velo_ratio;  // speed (km/h)
			//coef_rpm = max_rpm/60*enc_count/samp_rate/max_accel; 
			ratio_rpm = (60.0*(float)samp_rate)/enc_count;
// 		            TP_1_Write(1) ;


            blk0 = 0u;
            blk1 = 0u;
            blk2 = 0u;
            blk3 = 0u;

			getcom_flag = 1;
			no_getcom_loop_cnt = 0;
            getcom_count_para = 0;
            
            ret=spi_drv_set();
            if(ret!=0){ 
                status1 |= DRV_SPI_ERR ;
                state=FAULT;
                motor_en_reg_Write((uint8)MOT_PVM_DRV_ON);       // PVM1,PVM2:on  sel:disenable  pDRV:enable
                sk_PutString01("FAULT07",CRLF_ON);
              
            }else{
                motor_en_reg_Write((uint8)MOT_CIR_ALL_ON);       // PVM1,PVM2:on  sel:enable  pDRV:enable
            }
            
            CyDelayUs(1000);
            
            if ((state != EMSTOP)&&(state != FAULT)&&(state != SHUTDWN)){
                state=IDLE;
                sk_PutString01("IDLE02",CRLF_ON);
            }

		}
				
				
		
	}
        #if DEMODE == 1						
        	pout(0x20);			//		18.61us 8L:32.71us
        #endif
}

//****************************************************
//	Motor and Sencer observe & Control  Rountine				   
//****************************************************
void Sub_Enc()  	// 2'h4X
{
	int16 ms0_main[4];
    uint8 i,j;
    char string[30];
    char *pt;
    
    const MENUE menue[] = {
        {"ms0_main[0]= "},
        {"ms0_main[1]= "},
        {"ms0_main[2]= "},
        {"ms0_main[3]= "}
    };


    
        #if DEMODE == 1 
            // 6.26us
        	pout(0x40);//6.41us 8L:6.61us
        #endif

    // get enc data for each motor0,1,2,3
	ms0_main[0] = (int16)((2*encd0-1)*CY_GET_REG16(motor_enc_0_motor_enc_u0__16BIT_A1_REG));
	ms0_main[1] = (int16)((2*encd1-1)*CY_GET_REG16(motor_enc_1_motor_enc_u0__16BIT_A1_REG));
	ms0_main[2] = (int16)((2*encd2-1)*CY_GET_REG16(motor_enc_2_motor_enc_u0__16BIT_A1_REG));
	ms0_main[3] = (int16)((2*encd3-1)*CY_GET_REG16(motor_enc_3_motor_enc_u0__16BIT_A1_REG));
    
    if( sk_log_flg5 & SK_LOG4_ENC_DATA   ){
    	sk_ms0_main[0] += CY_GET_REG16(motor_enc_0_motor_enc_u0__16BIT_A1_REG);
    	sk_ms0_main[1] += CY_GET_REG16(motor_enc_1_motor_enc_u0__16BIT_A1_REG);
    	sk_ms0_main[2] += CY_GET_REG16(motor_enc_2_motor_enc_u0__16BIT_A1_REG);
    	sk_ms0_main[3] += CY_GET_REG16(motor_enc_3_motor_enc_u0__16BIT_A1_REG);
    }
    
    /*
    if( sk_ms0_main[0] != ms0_main[0] ){
                sk_ms0_main[0] = ms0_main[0];
                sk_pwm_debug(8,CY_GET_REG16(motor_enc_0_motor_enc_u0__16BIT_A1_REG),ms0_main[0],encd0,0);
    }
    
    
    if( sk_log_flg4 & SK_LOG4_ENC_DATA  ){
        for( i = 0; i < 4; i ++ ){
            if( sk_ms0_main[i] != ms0_main[i] ){
                sk_ms0_main[i] = ms0_main[i];
                pt = menue[i].name;
                j=0;
                while( *pt != NULL ){
                    string[j] = *pt;
                    pt++;
                    j++;
                }
                string[j] = NULL;
                // j++;
                sk_int16toChar(&string[j], ms0_main[i]);
                sk_log_int_string(string);
            }
        }
    }
    */
    
    i=0;
    
	while (i<4){
        if (ms0_main[i] < 0 ){
            ms0_main[i] = -(abs(ms0_main[i])>>enc_malti);

        }else{
            ms0_main[i] = (abs(ms0_main[i])>>enc_malti);
        }
        i++;
    }


    // motor0,1,2,3 enc data => motor_LF,_RF,_LR,_RR conversion
    
	MS_LF_MAIN[1] = ms0_main[encassign[0]];
	MS_RF_MAIN[1] = ms0_main[encassign[1]];
	MS_LR_MAIN[1] = ms0_main[encassign[2]];
	MS_RR_MAIN[1] = ms0_main[encassign[3]];
    
    // Accumulate enc counts for motor_LF,_RF,_LR,_RR in each trans line 
    
	MS_LF_MAIN[0] +=  MS_LF_MAIN[1];			//LF WHEEL MOTOR
	MS_RF_MAIN[0] +=  MS_RF_MAIN[1];			// RF WHEEL MOTOR
	MS_LR_MAIN[0] +=  MS_LR_MAIN[1];			//LR WHEEL MOTOR
	MS_RR_MAIN[0] +=  MS_RR_MAIN[1];			// RRWHEEL MOTOR

    if( sk_log_flg4 & SK_LOG4_ENC_DATA  ){
        string[0] = 'L';
        string[1] = 'F';
        string[2] = '=';
        sk_int16toChar(&string[3], MS_LF_MAIN[0]);
        
        i=0;
        while(string[i]!=NULL){
            i++;
        }
        string[i] = ',';
        i++;
        sk_int16toChar(&string[i], MS_LF_MAIN[1]);
        sk_log_int_string(string);
        
        string[0] = 'R';
        string[1] = 'F';
        string[2] = '=';
        sk_int16toChar(&string[3], MS_RF_MAIN[0]);
        
        i=0;
        while(string[i]!=NULL){
            i++;
        }
        string[i] = ',';
        i++;
        sk_int16toChar(&string[i], MS_RF_MAIN[1]);
        sk_log_int_string(string);
        
    }
        #if DEMODE == 1 
            // 6.26us
        	pout((int8)MS_LF_MAIN[1]);//LEFT WHEEL
        	pout(0x40);//6.41us 8L:6.61us
        	pout((int8)MS_RF_MAIN[1]);//RIGHT WHEEL
         	pout(0x40);//6.41us 8L:6.61us
        	pout((int8)MS_LF_MAIN[0]);//LEFT WHEEL
        	pout(0x40);//6.41us 8L:6.61us
        	pout((int8)MS_RF_MAIN[0]);//RIGHT WHEEL
         	pout(0x40);//6.41us 8L:6.61us
        #endif


    
    return;
}


//************************************************
//		McpuOP  Rountine						
//************************************************

void McpuOP() 	// 2'h5X
{
    

        #if DEMODE == 1
        	pout(0x50); //35.41us
        #endif
	if(logmode == 0){
        if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
            sk_log_int("McpuOP() ", 0 );
        }
                    
		output_tmp[0] =	ms_lf_com_tx;
		output_tmp[1] =	ms_rf_com_tx;
		output_tmp[2] =	ms_lr_com_tx;
		output_tmp[3] =	ms_rr_com_tx;
	}
	else if(logmode == 0x02){
        if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
            sk_log_int("McpuOP() ", 1 );
        }
        
			#if DEMODE == 1
				pout(0x52);
			#endif
		output_tmp[0] = speed_lf;
		output_tmp[1] = speed_rf;
		output_tmp[2] = speed_lr;
		output_tmp[3] = speed_rr;
	}
	else{
        if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
            sk_log_int("McpuOP() ", 2 );
        }
        
			#if DEMODE == 1
				pout(0x53);
			#endif
		output_tmp[0] = ms_lf_com_tx;
		output_tmp[1] = ms_rf_com_tx;
		output_tmp[2] = ms_lr_com_tx;
		output_tmp[3] = ms_rr_com_tx;
	}

	out2len = SEND_DAT_LENGTH;

    if(trans_line == 8){                    // 20160227 ks
			#if DEMODE == 1
				pout(0x54);
			#endif
        cycle_count_pre = cycle_count; // 20160214 ks
        cycle_count = cycle_count_buf;
		speed_lf_pre = speed_lf * 16;			
		speed_rf_pre = speed_rf * 16;
		speed_lr_pre = speed_lr * 16;			
		speed_rr_pre = speed_rr * 16;
    	speed_lf = speed_lf_buf;
    	speed_rf = speed_rf_buf;
    	speed_lr = speed_lr_buf;
    	speed_rr = speed_rr_buf;
		speed_lf_delta = (speed_lf-speed_lf_pre / 16);			
		speed_rf_delta = (speed_rf-speed_rf_pre / 16);
		speed_lr_delta = (speed_lr-speed_lr_pre / 16);			
		speed_rr_delta = (speed_rr-speed_rr_pre / 16);
        
       if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
            if( sk_log_cnt > 900 ){
                sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
            }
            
            if( sk_speed_lf != speed_lf ){
                sk_speed_lf = speed_lf;
                sk_log_int_int32("1 speed_lf =  ", speed_lf);    
                sk_log_cnt ++;
            }
            
            if( sk_speed_rf != speed_rf ){
                sk_speed_rf = speed_rf;
                sk_log_int_int32("1 speed_rf =  ", speed_rf);      
                sk_log_cnt ++;
            }                
        }
		
			#if DEMODE1 == 1
				pout(speed_lf_buf);
				pout(0x54);
				pout(speed_rf_buf);
			#endif
	}
			
	if (getcom_watch > 0){
		speed_lf_pre = speed_lf_pre + speed_lf_delta;
		speed_rf_pre = speed_rf_pre + speed_rf_delta;
		speed_lr_pre = speed_lr_pre + speed_lr_delta;
		speed_rr_pre = speed_rr_pre + speed_rr_delta;
		getcom_watch--;		
	}

   	if (use_smooth_chg == 1){

    	speed_lf = speed_lf_pre / 16;
    	speed_rf = speed_rf_pre / 16;
    	speed_lr = speed_lr_pre / 16;
    	speed_rr = speed_rr_pre / 16;
    		#if DEMODE == 1
				pout(0x55);  //39.7us
			#endif
			#if DEMODE1 == 1
				pout(speed_lf_pre);
				pout(0x55);
				pout(speed_lf);
			#endif

       if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
            if( sk_log_cnt > 900 ){
                sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
            }
            
            if( sk_speed_lf != speed_lf ){
                sk_speed_lf = speed_lf;
                sk_log_int_int32("2 speed_lf =  ", speed_lf);    
                sk_log_cnt ++;
            }
            
            if( sk_speed_rf != speed_rf ){
                sk_speed_rf = speed_rf;
                sk_log_int_int32("2 speed_rf =  ", speed_rf);      
                sk_log_cnt ++;
            }                
        }
    }
    #if DEMODE == 1
        	pout(0x50);	//42.49us
        #endif


	return;
}

//************************************************
//		Control Data Calcuration Rountinen 1 #01
//************************************************
void Sub_Calc1(){			// 2'h7X
	int32 ms0_com[4];

		#if DEMODE == 1
			pout(0x70) ; //45.72us
		#endif
        
    ms_lf_pc += MS_LF_MAIN[0]; 
	ms_rf_pc += MS_RF_MAIN[0]; 
	ms_lr_pc += MS_LR_MAIN[0]; 
	ms_rr_pc += MS_RR_MAIN[0]; 
    
		#if DEMODE == 1
			pout(ms_lf_pc) ;
			pout(0x70) ; //45.72us
			pout(ms_rf_pc) ;
			pout(0x70) ; //45.72us
		#endif
	if ((speed_lf==0) && (speed_rf==0) && (MS_LF_MAIN[0]==0) && (MS_RF_MAIN[0]==0) 
	 && (speed_lr==0) && (speed_rr==0) && (MS_LR_MAIN[0]==0) && (MS_RR_MAIN[0]==0)){
        
        // required speed == 0 and WHEEL currentry STOP
        if (state == DRIVE){  
            state=IDLE;
            sk_PutString01("IDLE01",CRLF_ON);
        }
        
		ms00_pw = 0;
		ms01_pw = 0;
		ms02_pw = 0;
		ms03_pw = 0;
		// Initialize model 
		Motor_Contl4_3_initialize();
	}else{      // requiered to move or currentry moving

        if (state == IDLE){  
            state=DRIVE;
            
            sk_PutString01("DRIVE",CRLF_ON);
            
            //sk_log_flg4 |= SK_LOG4_SUB_CALC1;
            // sk_log_cnt = 0;
            sk_log_int("state=DRIVE ",0);
            //sk_log_int_int32("0 speed_lf =  ", speed_lf);        
            //sk_log_int_int32("0 speed_rf =  ", speed_rf);   
            
        }
        
		if(direct_cnt){ // direct pulse width foced mode (user require to control direct pulse width )         
				#if DEMODE == 1
					pout(0x71);
				#endif
            if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
                if( sk_log_cnt > 900 ){
                    sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
                }
                sk_log_int("direct_cnt = ",direct_cnt);
                sk_log_cnt += 1;
            }
                            
                
			if (abs(speed_lf)>96 ){
				Motor_Contl4_3_Y.PWMDuty1= (float)(24); // 127=>96 by KS 20160311
			}else{
				Motor_Contl4_3_Y.PWMDuty1= (float)speed_lf/pwm_period * 24.0; // 127=>96 by KS 20160311
			}
			if (abs(speed_rf)>96 ){
				Motor_Contl4_3_Y.PWMDuty2= (float)(24); // 127=>96 by KS 20160311
			}else{
				Motor_Contl4_3_Y.PWMDuty2= (float)speed_rf/pwm_period * 24.0; // 127=>96 by KS 20160311
			}
			if (abs(speed_lr)>96 ){
				Motor_Contl4_3_Y.PWMDuty3= (float)(24); // 127=>96 by KS 20160311
			}else{
				Motor_Contl4_3_Y.PWMDuty3= (float)speed_lr/pwm_period * 24.0; // 127=>96 by KS 20160311
			}
			if (abs(speed_rr)>96 ){
				Motor_Contl4_3_Y.PWMDuty4= (float)(24); // 127=>96 by KS 20160311
			}else{
				Motor_Contl4_3_Y.PWMDuty4= (float)speed_rr/pwm_period * 24.0; // 127=>96 by KS 20160311
			}
				#if DEMODE1 == 1
					pout(speed_lf%16) ;
					pout(0x71);
					pout(speed_rf%16) ;
					pout(0x71);
				#endif
            if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
                if( sk_log_cnt > 900 ){
                    sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
                }

                sk_log_int("pwm_period = ", pwm_period);
                sk_log_int_int32("speed_lf =  ", speed_lf);
                sk_log_int_realT(".PWMDuty1 = ", Motor_Contl4_3_Y.PWMDuty1);
                sk_log_int_int32("speed_rf =  ", speed_rf);
                sk_log_int_realT(".PWMDuty2 = ", Motor_Contl4_3_Y.PWMDuty2);
                
            
                sk_log_cnt += 5;
            }
            
		}else{ // velocity control by PI contoroler
            #if DEMODE1 == 1
				pout((int8)(MS_LF_MAIN[0]/16)) ;
				pout(0x72);
				pout((uint8)(((int16)MS_LF_MAIN[0])&0x00FF)) ;
				pout(0x72);
			#endif

            
    		Motor_Contl4_3_U.Targetspeed1=((float)speed_lf/(float)speedratio);	// Targetspeed_rf(Km/h)LF wheel'
    		Motor_Contl4_3_U.Targetspeed2=((float)speed_rf/(float)speedratio);	// Targetspeed_lr(Km/h)RF wheel
    		Motor_Contl4_3_U.Targetspeed3=((float)speed_lr/(float)speedratio);	// Targetspeed_rr(Km/h)LR wheel'
    		Motor_Contl4_3_U.Targetspeed4=((float)speed_rr/(float)speedratio);	// Targetspeed4(Km/h)RR wheel'
    		Motor_Contl4_3_U.RPM1=(float)MS_LF_MAIN[0]*ratio_rpm;				// RPM1'*256*60/2048 LF wheel
    		Motor_Contl4_3_U.RPM2=(float)MS_RF_MAIN[0]*ratio_rpm;				// RPM2'*256*60/2048 RF wheel
    		Motor_Contl4_3_U.RPM3=(float)MS_LR_MAIN[0]*ratio_rpm;				// RPM3'*256*60/2048 LR wheel
    		Motor_Contl4_3_U.RPM4=(float)MS_RR_MAIN[0]*ratio_rpm;				// RPM4'*256*60/2048 RR wheel

            if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
                if( sk_log_cnt > 900 ){
                    sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
                }
               
                sk_log_int_int16("speedratio = ", speedratio);
                sk_log_int_int32("speed_lf = ", speed_lf);                
                sk_log_int_realT(".Targetspeed1 = ", Motor_Contl4_3_U.Targetspeed1);
                
                sk_log_int_int32("speed_rf = ", speed_rf);
                sk_log_int_realT(".Targetspeed2 = ", Motor_Contl4_3_U.Targetspeed2);
                
                sk_log_int_float("ratio_rpm = ", ratio_rpm);
                sk_log_int_int16("MS_LF_MAIN[0] = ", MS_LF_MAIN[0]);
                sk_log_int_realT(".RPM1 = ", Motor_Contl4_3_U.RPM1);

                sk_log_int_int16("MS_RF_MAIN[0] = ", MS_RF_MAIN[0]);
                sk_log_int_realT(".RPM2 = ", Motor_Contl4_3_U.RPM2);

                sk_log_cnt += 11;
                

            }
    			#if DEMODE2 == 1
    				pout(0x70) ;
    				pout(MS_LF_MAIN[0]>>8) ;
    				pout(0x70) ;
    				pout(MS_RF_MAIN[0]>>8) ;
    				pout(0x70) ;
    				pout((uint16)(Motor_Contl4_3_U.Targetspeed_rf*16)%16) ;
    				pout(0x70) ;
    				pout((uint16)(Motor_Contl4_3_U.Targetspeed_lr*16)%16) ;
    				pout(0x70) ;
    				pout((int16)(Motor_Contl4_3_U.RPM1*256.0)%16) ;
    				pout(0x70) ;
    				pout((int16)(Motor_Contl4_3_U.RPM2*256.0)%16) ;
    				pout(0x70) ;
    			#endif
    		rt_OneStep();
        
        }


        //  calcurate PWM pulse width from driving volatge  for each motor_LF,_RF,_LR,_RR
        //  and reassign motor-n's pulse width ms_lf,_rf,_lr,_ll => ms0_com[0] ,[1],[2],[3]
        
        if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
            if( sk_log_cnt > 900 ){
                sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
            }
            sk_log_int("PWM CALC",1);
            sk_log_cnt += 1;
        }
        
        MS_LF_MAIN[0] = 0;
            #if DEMODE == 1
				pout(0x71);
			#endif
		ms_lf_com_tx = (int32)(Motor_Contl4_3_Y.PWMDuty1 * (pwm_period-1.0)/24.0);
		ms0_com[motorassign[0]] = ms_lf_com_tx ;
        ms_lf_com_tx= (int16)(ms_lf_com_tx);
            #if DEMODE1 == 1
				pout((int8)(ms_lf_com_tx/16)) ;
				pout(0x72);
				pout((uint8)(ms_lf_com_tx & 0X00FF)) ;
				pout(0x72);
			#endif
		
		MS_RF_MAIN[0] = 0;
            #if DEMODE == 1
				pout(0x72);
			#endif
		ms_rf_com_tx = (int32)(Motor_Contl4_3_Y.PWMDuty2 * (pwm_period-1.0)/24.0);
		ms0_com[motorassign[1]] = ms_rf_com_tx ;
        ms_rf_com_tx= (int16)(ms_rf_com_tx);
		

		MS_LR_MAIN[0] = 0;
		ms_lr_com_tx = (int32)(Motor_Contl4_3_Y.PWMDuty3 * (pwm_period-1.0)/24.0);
		ms0_com[motorassign[2]] = ms_lr_com_tx ;
        ms_lr_com_tx= (int16)(ms_lr_com_tx);

		MS_RR_MAIN[0] = 0;
		ms_rr_com_tx = (int32)(Motor_Contl4_3_Y.PWMDuty4 * (pwm_period-1.0)/24.0);
		ms0_com[motorassign[3]] = ms_rr_com_tx ;
        ms_rr_com_tx= (int16)(ms_rr_com_tx);

        // calculate considering each rotation direction for motor0-motor3 
        // ms00_Pw : motor0 pulse width cpwm counter unit (max 199 to min -199)
        
		ms00_pw = (2*cw0-1)*ms0_com[0]; 
		ms01_pw = (2*cw1-1)*ms0_com[1];
		ms02_pw = (2*cw2-1)*ms0_com[2];
		ms03_pw = (2*cw3-1)*ms0_com[3];
        
        if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
            if( sk_log_cnt > 900 ){
                sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
            }
        
            sk_log_int("pwm_period = ", pwm_period);
            sk_log_int_realT(".PWMDuty1 = ", Motor_Contl4_3_Y.PWMDuty1);
            sk_log_int_int16("ms_lf_com_tx = ", ms_lf_com_tx);
            sk_log_int_int32("ms00_pw = ", ms00_pw );
                        
            sk_log_int_realT(".PWMDuty2 = ", Motor_Contl4_3_Y.PWMDuty2);
            sk_log_int_int16("ms_rf_com_tx = ", ms_rf_com_tx);
            sk_log_int_int32("ms01_pw = ", ms01_pw );
            
            sk_log_cnt += 5;
            

        }
				
			#if DEMODE1 == 1
				pout((int8)(ms00_pw/256)) ;
				pout(0x72);
				pout((uint8)(ms00_pw & 0X00FF)) ;
				pout(0x72);
			#endif


	}
        #if DEMODE == 1
        	pout(0x76) ;  //406.7us				
        #endif

	return ;
}
//************************************************
//	Set PWM					
//************************************************
void Set_PWM(){			// 2'h8X
	// Call Function to configure duty cycle
		#if DEMODE == 1
			pout(0x80) ;   //411.22us
		#endif

        
    //================================================================
    // Morter LF
    //================================================================
    
    //    
    // PWM
    //    
	pwm_width0=(uint8)(abs(ms00_pw));

    //    
    // 回転方向
    //    
	if(ms00_pw <0){
		sign0= 1u;
	}else{
		sign0= 0u;
	}	

    //================================================================
    // Morter RF
    //================================================================
    
    //    
    // PWM
    //    
	pwm_width1=(uint8)(abs(ms01_pw));

    //    
    // 回転方向
    //    
	if(ms01_pw <0){
		sign1= 1u;
	}else{
		sign1= 0u;
	}
    
    if (drive_wheels == 2){
    	pwm_width2=0;
		sign2= 0u;
        pwm_width3=0;
		sign3= 0u;
    }else{
    

        //================================================================
        // Morter LR
        //================================================================
        
        //    
        // PWM
        //    

    	pwm_width2=(uint8)(abs(ms02_pw));

        //    
        // 回転方向
        //    
    	if(ms02_pw <0){
    		sign2= 1u;
    	}else{
    		sign2= 0u;
    	}	

    	//================================================================
        // Morter RR
        //================================================================
        
        //    
        // PWM
        //    

    	pwm_width3=(uint8)(abs(ms03_pw));

        //    
        // 回転方向
        //    
    	if(ms03_pw <0){
    		sign3= 1u;
    	}else{
    		sign3= 0u;
    	}
    }
    
    
	pwm_control = blk1*16 + sign1*8 + blk0*4 + sign0*2 + direct;
 	motor_contl_reg_0_Write( pwm_control);
			pout(pwm_width1%16) ;
			pout(0x80) ; //416.12us
		#if DEMODE1 == 1
			pout(pwm_width2%16) ;
			pout(0x80) ;

		#endif
        
    if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){ // if( sk_log_flg4 & SK_LOG4_MT_PWM  ){
        if( sk_log_cnt > 900 ){
            sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
        }
    
        if( sk_pwm_control != pwm_control ){
           sk_pwm_control = pwm_control;
            sk_log_int("Set PWM1:pwm_control = ",pwm_control);
        }
        
        if( sk_pwm_period != pwm_period ){
           sk_pwm_period = pwm_period;
            sk_log_int("Set PWM1:pwm_period = ",pwm_period);
        }

        if( sk_pwm_width0 != pwm_width0 ) {
           sk_pwm_width0 = pwm_width0;
            sk_log_int("Set PWM1:pwm_width0 = ",pwm_width0);
        }
        if( sk_pwm_width1 != pwm_width1 ) {
           sk_pwm_width1 = pwm_width1;
            sk_log_int("Set PWM1:pwm_width1 = ",pwm_width1);
        }
        
      
        //sk_log_int("Set PWM1:pwm_control = ",pwm_control);
        //sk_log_int("Set PWM1:pwm_period = ",pwm_period);
        //sk_log_int("Set PWM1:pwm_width0 = ",pwm_width0);
        //sk_log_int("Set PWM1:pwm_width1 = ",pwm_width1);

        sk_log_cnt +=4;
 
    }

//	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__A0_REG , pwm_period);
	CY_SET_REG8 ( Direct_dual_8bPWM_0_Direct_dual_8bPWM_u0__A1_REG , pwm_period);
 	CY_SET_REG8 ( Direct_dual_8bPWM_0_Direct_dual_8bPWM_u0__D0_REG , pwm_width0);
	CY_SET_REG8 ( Direct_dual_8bPWM_0_Direct_dual_8bPWM_u0__D1_REG , pwm_width1);

    pwm_control = blk3*16 + sign3*8 + blk2*4 + sign2*2 + direct;
 	motor_contl_reg_1_Write( pwm_control);

    sk_mt_ctrl(31);
    if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){ // if( sk_log_flg4 & SK_LOG4_MT_PWM  ){
        if( sk_log_cnt > 900 ){
            sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
        }

        //sk_log_int("Set PWM2:pwm_control = ",pwm_control);
        //sk_log_int("Set PWM2:pwm_period = ",pwm_period);
        //sk_log_int("Set PWM2:pwm_width0 = ",pwm_width2);
        //sk_log_int("Set PWM2:pwm_width1 = ",pwm_width3);

        //sk_log_cnt +=4;
    }
        
//	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__A0_REG , pwm_period);
	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__A1_REG , pwm_period);
 	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__D0_REG , pwm_width2);
	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__D1_REG , pwm_width3);

	return;
}

//************************************************
//		McpuOP2  Rountine						
//************************************************

void McpuOP2()		// 2'h6X
{
		#if DEMODE == 1
			pout(0x60) ;
		#endif
	if((trans_line%2)==1){  // trans_line odd case done
		
			#if DEMODE == 1
				pout(0x61) ;
			#endif
		output2[trans_line-1][0] = (output_tmp[1]) & 0xFF;		   	// mot1 contl value
		output2[trans_line-1][1] = (output_tmp[0]) & 0xFF;		   	// mot0 contl value
		output2[trans_line-1][2] = (output_tmp[0] >> 4)& 0xF0;		// mot0 contl value
		output2[trans_line-1][2] += (output_tmp[1] >> 8)& 0x0F;	   	// mot1 contl value
	
		output2[trans_line-1][3] = ms_rf_pc & 0xFF;					// mot1 enc value
		output2[trans_line-1][4] = ms_lf_pc & 0xFF;					// mot0 enc value
		output2[trans_line-1][5] = (ms_lf_pc >> 4)& 0xF0;			// mot0 enc value
		output2[trans_line-1][5] += (ms_rf_pc >> 8)& 0x0F;			// mot1 enc value
		output2[trans_line-1][6] = cycle_count;       
	 
		output2[trans_line][0] = (output_tmp[3]) & 0xFF;		   	// mot3 contl value
		output2[trans_line][1] = (output_tmp[2]) & 0xFF;		   	// mot2 contl value
		output2[trans_line][2] = (output_tmp[2] >> 4)& 0xF0;		// mot2 contl value
		output2[trans_line][2] += (output_tmp[3] >> 8)& 0x0F;	   	// mot3 contl value
	
		output2[trans_line][3] = ms_rr_pc & 0xFF;					// mot3 enc value
		output2[trans_line][4] = ms_lr_pc & 0xFF;					// mot1 enc value
		output2[trans_line][5] = (ms_lr_pc >> 4)& 0xF0;			   	// mot1 enc value
		output2[trans_line][5] += (ms_rr_pc >> 8)& 0x0F;				// mot3 enc value
	 
		output2[trans_line][6] = cycle_count;       
        
        ms_lf_pc = 0; 
		ms_rf_pc = 0; 
    	ms_lr_pc = 0; 
		ms_rr_pc = 0; 

	
			#if DEMODE1 == 1
				pout(ms_lf_pc) ;
		 		pout(0x61) ;
				pout(ms_lf_pc/16) ;
		 		pout(0x61) ;
			#endif
			#if DEMODE2 == 1
				pout(ms_rf_pc) ;
		 		pout(0x62) ;
				pout(ms_rf_pc/16) ;
		 		pout(0x62) ;
			#endif
	}
	return;
}

//************************************************
//	main2pc : send data to PC using USBUART 
//************************************************

void  main2pc()		// 2'haX
{
	int8 out2_datpos;
	int8 out2_tagpos2;

        #if DEMODE == 1
        	pout(0xa0);
        #endif

	if((sub_cycle_count ==30 )&&(trans_line == 15)){
        
            #if DEMODE == 1
            	pout(0xa1);
            #endif
		out2pos = 0;
		out2_tagpos2 = 0;
		out2_tag_cycle = 0;
		out2_datpos = 0;
		if (state == SHUTDWN){
			output2_tag_head[1] = 0x99; // SHUT Down request to CPU
		    getcom_flag = 1;
            sk_PutString01("SHUTDWN01",CRLF_ON);
		}
        else if (getcom_flag == 0){
			output2_tag_head[1] = 0x66; // send data receive error
		    getcom_flag = 1;
		}

		else{
			output2_tag_head[1] = 0x55; // send datareceive corect
			if(!sendcom_flag){
//				getcom_flag = 0;				
				sendcom_flag = 1;
			}
		}	
	
		while(out2_tagpos2 < 59){
			if (out2_tagpos2 < 3){
				outbuff1[out2_tagpos2]=output2_tag_head[out2_tagpos2];
			}
			else{
				outbuff1[out2_tagpos2]=output2[out2pos][out2_datpos];
				if(out2_datpos == 6){
					out2_datpos = 0;
					out2pos += 1;
				}
				else{
					out2_datpos +=1;
				}
			}
			out2_tagpos2 += 1;
		}
//	}

//	if((sub_cycle_count == 31)&&(trans_line == 15)){
            #if DEMODE == 1
            	pout(0xa2);
            #endif
		out2pos = 8;
		out2_tagpos2 = 0;
		out2_tag_cycle = 0;
		out2_datpos = 0;

		while(out2_tagpos2 < 56){
			outbuff2[out2_tagpos2]=output2[out2pos][out2_datpos];
		    if(out2_datpos==6){
				out2_datpos = 0;
				out2pos +=1;
			}
			else{
				out2_datpos +=1;
			}
			out2_tagpos2 += 1;
		}
        out2_tagpos2 = 0;
		
		while(out2_tagpos2 < 30){
			outbuff3[out2_tagpos2]=output2_tag[out2_tagpos2+3];
			out2_tagpos2 += 1;
		}
//	}
//	if((sub_cycle_count ==0 )&&(trans_line == 0)){
    		#if DEMODE == 1
    			pout(0xa3);
    		#endif
		out2pos = 0;
		out2_tagpos = 0;
		out2_tag_cycle = 0;
	}
    
            
    if( sk_log_flg5 & SK_LOG5_OUTPUT_P   ){
        if(sk_input_ofst<59){
            outbuff1[sk_input_ofst] = sk_input_data;
        }
        else if(sk_input_ofst<115){
            outbuff2[sk_input_ofst-59] = sk_input_data;
        }
        else if(sk_input_ofst<145){
            outbuff3[sk_input_ofst-115] = sk_input_data;
        }
    }
    
    
    
	
	if( out2_tagpos ==0) {               //TX empty?
		if(USBUART_1_CDCIsReady() != 0u){    // if ready to send more data to the PC 
			pout(0xa4) ;
      		USBUART_1_PutData(outbuff1, 59);	// Send 59 byte data to PC 
			CyDelayUs(5);
			out2_tagpos = 1;
		}
	}else if(out2_tagpos ==1){
		if(USBUART_1_CDCIsReady() != 0u){    // if ready to send more data to the PC
			pout(0xa5) ;
      		USBUART_1_PutData(outbuff2, 56);	// Send 56 byte data to PC 
			CyDelayUs(5);
			out2_tagpos = 2;
		}
	}else if(out2_tagpos ==2){
		if(USBUART_1_CDCIsReady() != 0u){    // if ready to send more data to the PC 

			pout(0xa6) ;
      		USBUART_1_PutData(outbuff3, 30);	// Send 30 byte data to PC 
			CyDelayUs(5);
			out2_tagpos = 3;
		}
	}else if(out2_tagpos ==3){
		if(USBUART_1_CDCIsReady() != 0u){    // Wait till component is ready to send more data to the PC 
			out2_tagpos = 4;
		}
	}
}

//**************************************************
// After this line the sub function for various service writen 
//**************************************************

//********************************************************
//	WheelStop : Stop Wheel at bump sw , or various trable				   
//********************************************************

void WheelStop(void)  	// 2'h3X
{
                
            //target speed command increment from previous PC command
            // 1/16sec period before
    
    int32	speed_lf_change;    // Left Front wheel
    int32	speed_rf_change;    // Right Front wheel
    int32	speed_lr_change;    // Left Rear wheel
    int32	speed_rr_change;    // Right Rear wheel


	float change_ratio ;  // 2016.0304 by K.sakashita
	static int	usb_conf_flag = 0;
        #if DEMODE == 1						
            pout(0x30);						
        #endif

	speed_lf_buf = 0;
	speed_rf_buf = 0;
	speed_lr_buf = 0;
	speed_rr_buf = 0;
	getcom_watch = 16;
    
        if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
            if( sk_log_cnt > 900 ){
                sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
            }

            sk_log_int_int32("3 speed_lf =  ", speed_lf);        
            sk_log_int_int32("3 speed_rf =  ", speed_rf);        
            sk_log_cnt += 2;
        }
                
//  New argolizum only streight acc limited 2016.0304 by K.sakashita 

	speed_lf_change = speed_lf_buf - speed_lf;
	speed_rf_change = speed_rf_buf - speed_rf;
	speed_lr_change = speed_lr_buf - speed_lr;
	speed_rr_change = speed_rr_buf - speed_rr;

	if((speed_lf_change + speed_rf_change + speed_lr_change + speed_rr_change)!=0){       									//20160314 K.S			
		change_ratio=(float)(4*(uint32)max_spd_chg)/(abs(speed_lf_change + speed_rf_change + speed_lr_change + speed_rr_change)) ; 	//20160314 K.S

		if(change_ratio < 1){
			speed_lf_buf = speed_lf + (int32)((speed_lf_change * change_ratio)) ;
			speed_rf_buf = speed_rf + (int32)((speed_rf_change * change_ratio)) ;
			speed_lr_buf = speed_lr + (int32)((speed_lr_change * change_ratio)) ;
			speed_rr_buf = speed_rr + (int32)((speed_rr_change * change_ratio)) ;
		}
	}	

	if(!USBUART_1_GetConfiguration()){
		sendcom_flag = 0;
		usb_conf_flag = 1;
	}
	else{
		if(usb_conf_flag){
			USBUART_1_CDC_Init();
			usb_conf_flag = 0;
		}
	}
}

//**************************************************
// Check Bumper SW and drive direction limited
//**************************************************

void Chk_Bumper(void)
{
            // Bumper sw read   
        
/**************************************************/
/*      Bumper sw signal direction assign         */
/*                                                */
/*   BMP_SW[0]  :Right Rear  Bumper               */
/*   BMP_SW[1]  :Rear  Right Bumper               */
/*   BMP_SW[2]  :Rear  Left  Bumper               */
/*   BMP_SW[3]  :Left  Rear  Bumper               */
/*   BMP_SW[4]  :Left  Front Bumper               */
/*   BMP_SW[5]  :Front Left  Bumper               */
/*   BMP_SW[6]  :Front Right Bumper               */
/*   BMP_SW[7]  :Right Front Bumper               */
/*                                                */
/**************************************************/

        bwp_sw=~(BMP_SW_Read() );

        output2_tag[31] =bwp_sw;
        
/*	complex speed limit control by Bumper Switch*/
/*	   2015/11/30 by K sakashita		*/

        
        /* front bwp touch the obstacl */
        if( sk_log_flg2 & SK_LOG2_BMP_SENS ){
            sk_PutString03("sk_bwp_sw = ",sk_bwp_sw , CRLF_ON,16);
            sk_PutString03("bwp_sw = ",bwp_sw , CRLF_ON,16);
            if( sk_bwp_sw != bwp_sw ){
                sk_bwp_sw = bwp_sw;
                sk_log_int("bwp_sw = ",bwp_sw);
                sk_log_int("speed_lf_buf = ",speed_lf_buf);
                sk_log_int("speed_rf_buf = ",speed_rf_buf);
                sk_log_int("speed_lr_buf = ",speed_lr_buf);
                sk_log_int("speed_rr_buf = ",speed_rr_buf);
            }
        }
        
        if((0 == (bwp_sw & 2)) || ( 0 ==( bwp_sw & 4))){
            if (speed_lf_buf>0) { speed_lf_buf = 0;}
            if (speed_rf_buf>0) { speed_rf_buf = 0;}
            if (speed_lr_buf>0) { speed_lr_buf = 0;}
            if (speed_rr_buf>0) { speed_rr_buf = 0;}  
        }

        /* rear bwp touch the obstacl */
        if((0 == (bwp_sw & 32)) || ( 0 ==( bwp_sw & 64))){
            if (speed_lf_buf<0) { speed_lf_buf = 0;}
            if (speed_rf_buf<0) { speed_rf_buf = 0;}
            if (speed_lr_buf<0) { speed_lr_buf = 0;}
            if (speed_rr_buf<0) { speed_rr_buf = 0;}  
        }

        /* Left bwp touch the obstacl */
        if((0 == (bwp_sw & 8)) || ( 0 ==( bwp_sw & 16))){
            if (speed_lf_buf<0) { speed_lf_buf = 0;}
            if (speed_rf_buf>0) { speed_rf_buf = 0;}
            if (speed_lr_buf>0) { speed_lr_buf = 0;}
            if (speed_rr_buf<0) { speed_rr_buf = 0;}  
        }

        /* Right bwp touch the obstacl */
        if((0 == (bwp_sw & 128)) || ( 0 ==( bwp_sw & 1))){
            if (speed_lf_buf>0) { speed_lf_buf = 0;}
            if (speed_rf_buf<0) { speed_rf_buf = 0;}
            if (speed_lr_buf<0) { speed_lr_buf = 0;}
            if (speed_rr_buf>0) { speed_rr_buf = 0;} 
        }
        
        
        /***** end of complex speed limit control by bmp_sw ***/
        /******************************************************/
}
/************************************************/
/*	get Sensor DATA Battery, distance	*/
/************************************************/
void Sensor()		// 2'h9X
{
	//uint8	pvm1, pvm2;
	//uint8	dstep;
	//cystatus Status;
        #if DEMODE == 1
        	pout(0x90) ;	
        #endif 
        #if DEMODE1 == 1
        	pout(trans_line) ;
        	pout(0x90) ;
        	pout(sub_cycle_count) ;
        	pout(0x90) ;
        #endif
        
        
    
    
	if(trans_line == 14){	
            #if DEMODE == 1
            	pout(0x91) ;	//14L:37.8us
            #endif

    	// Measure Die Temp
        
        //get_die_temp(output2_tag[22],die_status);
              
                
        // Distance Sensor 1 Check [front]
        adin = 1;
        seq_code =0X97;
        output2_tag[24]=get_adc_value(adin,seq_code); //63.11us
        

        // Battery Voltage  Check (main battery )
        
            //Check in Diagonostic routine

        // Distance Sensor 3  Check[rear] 

        adin = 3;
        seq_code =0X99;
        output2_tag[26]=get_adc_value(adin,seq_code); //87.81us

        
        // PVM1 (Power Voltage 1)  Check
        
            //Check in Diagonostic routine


        // Distance Sensor 0 Check [right front]

        adin = 0;
        seq_code =0X96;
        output2_tag[23]=get_adc_value(adin,seq_code); //112.21us
        

                
        // PVM2 (Power Voltage 2)  Check 
        
            //Check in Diagonostic routine


        // Distance Sensor 2 Check [left front] 
        
        adin = 2;
        seq_code =0X98;
        output2_tag[25]=get_adc_value(adin,seq_code);//146.91us


               
		/* STEP Distance Sensor Check */
    
        adin = 4;
        seq_code =0X9a;
        output2_tag[27]=get_adc_value(adin,seq_code);
			
        

	}
        #if DEMODE == 1
        		pout(0x9b) ;//11L:43.42us 12L:35.23us 13L:37.81us //14L:148.42us
        #endif 
        
            
	return;
}

/************************************************/
/*	PI control calcuration floating wquation 	*/
/************************************************/

void rt_OneStep(void)	// 2'hbX
{
  static boolean_T OverrunFlag = FALSE;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag){
    // # define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
    // Motor_Contl4_3_M->errorStatus = "Overrun";
    rtmSetErrorStatus(Motor_Contl4_3_M, "Overrun");
    return;
  }

  OverrunFlag = TRUE;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model for base rate */
 sk_mt_ctrl(30);
  Motor_Contl4_3_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = FALSE;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*debug out */
void pout(uint num)
{
		P_out_Write((num)%16) ;
		P_out_1_Write((num>>4)%4) ;
        P_out_2_Write((num>>6)%4) ;

}
uint8 spi_drv_init(void)
{
   uint16 spitx_wd;
    uint16 spirx_wd;
    uint8 spirx_status;
    uint8 spitx_status;
    //uint8 wd_count;
    int i,ii,iw,ret,ir ;
    // CyGlobalIntEnable; /* Enable global interrupts. */
 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
        spi_sel = 63;
        SS0_B_Write(spi_sel);    // SPI_1 enable
    SPIM_1_Start();
    ii=0;       //motor driver address
    ret= 0;     // return value set to 0 (no error)
    
    motor_para_1.m_para_wset.rdwbuf[0]=(uint16)0x000 ;
    motor_para_1.m_para_wset.rdwbuf[1]=(uint16)0x000 ;
    //motor_para_1.m_para_wset.rdwbuf[2]=(uint16)0x040 ;
    motor_para_1.m_para_wset.rdwbuf[2]=(uint16)0x0c0 ;  // OTW_REP: enable
    //motor_para_1.m_para_wset.rdwbuf[2]=(uint16)0x060 ;  // OTW_REP: enable(wrong=>indipend mode)
    //motor_para_1.m_para_wset.rdwbuf[3]=(uint16)0x344 ;
    motor_para_1.m_para_wset.rdwbuf[3]=(uint16)0x322 ;  
    motor_para_1.m_para_wset.rdwbuf[4]=(uint16)0x522 ;  // CBC(retry OCP 
    //motor_para_1.m_para_wset.rdwbuf[4]=(uint16)0x344 ;
    //motor_para_1.m_para_wset.rdwbuf[4]=(uint16)0x722 ;
    //motor_para_1.m_para_wset.rdwbuf[5]=(uint16)0x159 ;
    //motor_para_1.m_para_wset.rdwbuf[5]=(uint16)0x119 ;//ocp fault cause shutdown FET gate out put
    //motor_para_1.m_para_wset.rdwbuf[5]=(uint16)0x110 ;//ocp fault cause shutdown FET gate out put
    motor_para_1.m_para_wset.rdwbuf[5]=(uint16)0x195 ;//for 100A MAX IDS(4us)
    //motor_para_1.m_para_wset.rdwbuf[5]=(uint16)0x191 ;//for 30A IDS mode(4us)
    //motor_para_1.m_para_wset.rdwbuf[6]=(uint16)0x280 ;
    //motor_para_1.m_para_wset.rdwbuf[6]=(uint16)0x242 ;  // for 11A  continuous ids_max (report only)
    motor_para_1.m_para_wset.rdwbuf[6]=(uint16)0x240 ;  // for 3.5A  continuous ids_max (report only)
    
    
    // motor driver 0 to 3 assign
    
    while(ii < drive_wheels )     
//    while(ii <= 1 )
    {
        i=0;    // adress register adress
        pout(66);
        
        if(ii==0){
            spi_sel = 62;    //motor0 driver address
        }else if(ii==1){
            spi_sel = 61;    //motor1 driver address
        }else if(ii==2){
            spi_sel = 59;    //motor2 driver address
        }else if(ii==3){
            spi_sel = 55;    //motor3 driver address
        }else{
            spi_sel = 63;    // not assign adress
        }
        
        if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
            sk_log_int("spi_sel = ",spi_sel);
        }
        
        
        SS0_B_Write(spi_sel);    // not assign adress
        pout(ii);
        
        
        // register adress 0 to 6 (7 address) assign

        //while(i <= 6)       
        while(i <= 7)    //add icsa caribration stage(i:7)    
        {
            ir=i;
            if(i>6) {
                ir=6;
                //CyDelayUs(500);  
                CyDelayUs(10);  
            }
            // SPI RX buffer clear for motor driver 
            
            spirx_status    =   SPIM_1_ReadRxStatus()  ;
            iw=100;           
            while(spirx_status & SPIM_1_STS_RX_FIFO_NOT_EMPTY){
               SPIM_1_ClearRxBuffer();
               spirx_status    =   SPIM_1_ReadRxStatus()  ;
                if (iw==0){
                    ret= 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }
            
            // SPI TX buffer clear for motor driver 
            
            spitx_status    =   SPIM_1_ReadTxStatus()  ;
            iw=100;           
            while(!(spitx_status & SPIM_1_STS_SPI_IDLE)){
                SPIM_1_ClearTxBuffer();
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;

            }
            
            
            // SPI write for reg address 2 to 6 (0,1 read only reg)
            
            if(i>=2){
//            if(i>=3){
                if(i==6){ // csa amp auto caribration
                    spitx_wd = (uint16)((motor_para_1.m_para_wset.rdwbuf[ir] + (ir<<11))|0x0010 );
                }else{
                    spitx_wd = (uint16)(motor_para_1.m_para_wset.rdwbuf[ir] + (ir<<11)) ;
                }
                SPIM_1_WriteTxData(spitx_wd);
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                iw=100;           
                while(!(spitx_status & SPIM_1_STS_SPI_DONE)){  // wait until finish writing
                    CyDelayUs(5);  
                    spitx_status    =   SPIM_1_ReadTxStatus()  ;
                    if (iw==0){
                        ret = 1;        //SPI comunucation timeout
                        return ret;
                    }
                    //iw +=1;
                    iw -=1;
                }
 
                // register value Dummy read from  Buffer
            
                spirx_status    =   SPIM_1_GetRxBufferSize()  ;
                iw=100;           
                while(spirx_status == 0){                      // wait until finish reading
                    CyDelayUs(5);  
                    spirx_status    =   SPIM_1_GetRxBufferSize()  ;
                    if (iw==0){
                        ret = 1;        //SPI comunucation timeout
                        return ret;
                    }
                    //iw +=1;
                    iw -=1;
                }
           
                // read data store the spirx_wd
                
                spirx_wd = SPIM_1_ReadRxData(); 

            }
            
            
            // confirm register value by read SPI reg address 0 to 6 
            
            // value "0" write each adrress(0-6) dummy write for read data
            
            spitx_wd = (uint16)(0x8000 + (ir<<11)) ;
            SPIM_1_WriteTxData(spitx_wd);
            spitx_status    =   SPIM_1_ReadTxStatus()  ;
            iw=100;           
           
            while(!(spitx_status & SPIM_1_STS_SPI_DONE)){ // wait until finish writing
                CyDelayUs(5);  
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }

            
            // register value read from  each adrress(0-6)
            
            spirx_status    =   SPIM_1_GetRxBufferSize()  ;
            iw=100;           
            while(spirx_status == 0){                      // wait until finish reading
                CyDelayUs(5);  
                spirx_status    =   SPIM_1_GetRxBufferSize()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
           }
           
            // read data store the spirx_wd
            
            spirx_wd = 0xffff ;
            spirx_wd = SPIM_1_ReadRxData(); 
            iw=100;           
            while(spirx_wd == 0xFFFF){
                CyDelayUs(5);  
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }
            motor_parag_1[ii].m_para_wget.wdwbuf[ir]=(spirx_wd & 0x07ff);
            // read data stored => wdwbuf[i]
                
//            if (i >=3 ){
            if (i >=2 ){
                if (i == 6 ){  // csa amp auto caribration
    	            if((motor_para_1.m_para_wset.rdwbuf[ir]|0x0010 )== (motor_parag_1[ii].m_para_wget.wdwbuf[ir])){
    	                i +=1 ; 
                    }else{
    	                i =i; //address i register re-write
                    }
                }else{
    	            if(motor_para_1.m_para_wset.rdwbuf[ir] == motor_parag_1[ii].m_para_wget.wdwbuf[ir]){
    	                i +=1 ; 
                    }else{
    	                i =i; //address i register re-write
                    }
                }
	        }else{
	            if(0== motor_parag_1[ii].m_para_wget.wdwbuf[ir]){
	                i +=1 ;
	            }else{
                   // mpu_status=DRIVER_FAULT ;      // abnormal driver condition;   
	                i +=1 ; //address i register re-write 
	            }
            }
 
        }
        ii +=1 ;
    }
    return ret;
}

uint8 spi_drv_read(void)
{
    uint16 spitx_wd;
    uint16 spirx_wd;
    uint8 spirx_status;
    uint8 spitx_status;
    int i,ii,iw,ret ;
    // CyGlobalIntEnable; /* Enable global interrupts. */
 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    spi_sel = 63;
    SS0_B_Write(spi_sel);    // SPI_1 enable

    SPIM_1_Start();
    ii=0;       //motor driver address
    ret= 0;     // return value set to 0 (no error)
    
    motor_para_1.m_para_wset.rdwbuf[0]=(uint16)0x000 ;
    motor_para_1.m_para_wset.rdwbuf[1]=(uint16)0x000 ;
    
    if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
        sk_log_int("read01:spi_sel = ",spi_sel);
    }

    // motor driver 0 to 3 assign
    
    while(ii < drive_wheels )     
//    while(ii <= 1 )
    {
        if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
            sk_log_int("read02:ii = ",ii);
        }

        i=0;    // adress register adress
        pout(66); //0x42
        
        if(ii==0){
            spi_sel = 62;    //motor0 driver address
        }else if(ii==1){
            spi_sel = 61;    //motor1 driver address
        }else if(ii==2){
            spi_sel = 59;    //motor2 driver address
        }else if(ii==3){
            spi_sel = 55;    //motor3 driver address
        }else{
            spi_sel = 63;    // not assign adress
        }
        SS0_B_Write(spi_sel);    // not assign adress
        pout(ii);
        
        if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
            sk_log_int("read02:spi_sel = ",spi_sel);
        }        
        
        
        // register adress 0 to 6 (7 address) assign

        while(i <= 1)       
        {
            
            // SPI RX buffer clear for motor driver 
            
            spirx_status    =   SPIM_1_ReadRxStatus()  ;
            iw=100;
            while(spirx_status & SPIM_1_STS_RX_FIFO_NOT_EMPTY){
                SPIM_1_ClearRxBuffer();
                spirx_status    =   SPIM_1_ReadRxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    sk_PutString01("SPI time out 01",CRLF_ON);
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }

            if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
                sk_log_int("read03:spi_sel = ",spirx_status );
            }        

            // SPI TX buffer clear for motor driver 
            
            spitx_status    =   SPIM_1_ReadTxStatus()  ;
            iw=100;           
            while(!(spitx_status & SPIM_1_STS_SPI_IDLE)){
                SPIM_1_ClearTxBuffer();
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    sk_PutString01("SPI time out 02",CRLF_ON);
                    return ret;
                }
                //iw +=1;
                iw -=1;

            }

            if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
                sk_log_int("read04:spi_sel = ",spirx_status );
            }        
            
            // confirm register value by read SPI reg address 0 to 6 
            
            // value "0" write each adrress(0-6) dummy write for read data
            
            spitx_wd = (uint16)(0x8000 + (i<<11)) ;
            SPIM_1_WriteTxData(spitx_wd);
            spitx_status    =   SPIM_1_ReadTxStatus()  ;
            iw=100;           
            while(!(spitx_status & SPIM_1_STS_SPI_DONE)){ // wait until finish writing
                //CyDelayUs(2);  
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    sk_PutString01("SPI time out 03",CRLF_ON);
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }
            if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
                sk_log_int("read05:spitx_wd  = ",spitx_wd  );
            } 
            
            // register value read from  each adrress(0-6)
            
            spirx_status    =   SPIM_1_GetRxBufferSize()  ;
            iw=100;           
            while(spirx_status == 0){                      // wait until finish reading
                //CyDelayUs(2);  
             spirx_status    =   SPIM_1_GetRxBufferSize()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    sk_PutString01("SPI time out 04",CRLF_ON);
                    return ret;
                }
                //iw +=1;
                iw -=1;
           }
           
            // read data store the spirx_wd
            
            spirx_wd = 0xffff ;
            spirx_wd = SPIM_1_ReadRxData(); 
            iw=100;           
            while(spirx_wd == 0xFFFF){
                //CyDelayUs(2);  
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    
                    sk_PutString01("SPI time out 05",CRLF_ON);
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }
            
            if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
                sk_log_int("read06:spirx_wd  = ",spirx_wd );
            } 
            // read data stored => wdwbuf[i]
            motor_parag_1[ii].m_para_wget.wdwbuf[i]=(spirx_wd & 0x07ff);
            if(drive_wheels <=2 ){ //2wheels case
                if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
                    sk_log_int("read07:i  = ",i );
                } 
                if(i==0){
                    output2_tag[17+ii]=(( spirx_wd & 0x03c0)>>2);
                    //output2_tag[19+ii]=(( spirx_wd & 0x003f)); //vds_error{0,0,HA,LA,HB,LB,HC,LC}
                }else{
                    output2_tag[17+ii] +=((( spirx_wd & 0x00c0)>>4)+(( spirx_wd & 0x0400)>>9));
                    output2_tag[19+ii] =(( spirx_wd & 0x003f)); //vgs_error{0,0,HA,LA,HB,LB,HC,LC}
                }
            }else{ // over than 2wheels(3,4 whells)
                if(i==0){
                    output2_tag[17+ii]=(( spirx_wd & 0x03c0)>>2);
                }else{
                    output2_tag[17+ii] +=((( spirx_wd & 0x00c0)>>4)+(( spirx_wd & 0x0400)>>9));
                }
            }
            i +=1 ;    
 
        }
        ii +=1 ;
    }
    return ret;
}
uint8 spi_drv_set(void)
{
    uint16 spitx_wd;
    uint16 spirx_wd;
    uint8 spirx_status;
    uint8 spitx_status;
    int i,ii,iw,ret ;
    // CyGlobalIntEnable; /* Enable global interrupts. */
    spi_sel = 63;
    SS0_B_Write(spi_sel);    // SPI_1 enable
 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    SPIM_1_Start();
    ii=0;
    ret= 0;     // return value set to 0 (no error)

    if( sk_log_flg2 & SK_LOG2_SPI_SET ){
        sk_log_int("spi_drv_set", 0);
    }
    while(ii < drive_wheels )
//     while(ii <= 1 )
    {
        if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
            sk_log_int("SPI ii ***** = ", ii);
        }
        
        
        i=0;    // adress register adress
        pout(66);
        
        if(ii==0){
            spi_sel = 62;    //motor0 driver address ★0x3e
        }else if(ii==1){
            spi_sel = 61;    //motor1 driver address ★0x3d
        }else if(ii==2){
            spi_sel = 59;    //motor2 driver address
        }else if(ii==3){
            spi_sel = 55;    //motor3 driver address
        }else{
            spi_sel = 63;    // not assign adress
        }
        
        if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
            sk_log_int("SPI spi_sel = ", spi_sel);
        }
                
        SS0_B_Write(spi_sel);    // not assign adress
        pout(ii);
        
        
        
        // register adress 0 to 6 (7 address) assign
        // i: DRV8323のレジスタ

        while(i <= 6)       
        {
            if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
                sk_log_int("SPI i = ", i);
            }
                    
            
            // SPI RX buffer clear for motor driver 
            
            spirx_status    =   SPIM_1_ReadRxStatus()  ;
            iw=100;           
            while(spirx_status & SPIM_1_STS_RX_FIFO_NOT_EMPTY){
                SPIM_1_ClearRxBuffer();
                spirx_status    =   SPIM_1_ReadRxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }
            
            // SPI TX buffer clear for motor driver 
            
            spitx_status    =   SPIM_1_ReadTxStatus()  ;
            iw=100;                      
            while(!(spitx_status & SPIM_1_STS_SPI_IDLE)){
                SPIM_1_ClearTxBuffer();
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;

            }
            
            
            // SPI write for reg address 2 to 6 (0,1 read only reg)
            
            if(i>=2){
                spitx_wd = (uint16)(motor_para_1.m_para_wset.rdwbuf[i] + (i<<11)) ;
                
                if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
                    sk_log_int("SPI 0 spitx_wd = ", spitx_wd);
                }
                
                SPIM_1_WriteTxData(spitx_wd);
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                iw=100;           
                while(!(spitx_status & SPIM_1_STS_SPI_DONE)){  // wait until finish writing
                    CyDelayUs(5);  
                    spitx_status    =   SPIM_1_ReadTxStatus()  ;
                    if (iw==0){
                        ret = 1;        //SPI comunucation timeout
                        return ret;
                    }
                    //iw +=1;
                    iw -=1;
                }
 
                // register value Dummy read from  Buffer
            
                spirx_status    =   SPIM_1_GetRxBufferSize()  ;
                iw=100;           
                while(spirx_status == 0){                      // wait until finish reading
                    CyDelayUs(5);  
                    spirx_status    =   SPIM_1_GetRxBufferSize()  ;
                    if (iw==0){
                        ret = 1;        //SPI comunucation timeout
                        return ret;
                    }
                    //iw +=1;
                    iw -=1;
                }
           
                // read data store the spirx_wd
                
                //spirx_wd = 0xffff ;
                spirx_wd = SPIM_1_ReadRxData(); 
                //while(spirx_wd == 0xFFFF){
                //    CyDelayUs(5);  
                //}
                if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
                    sk_log_int("SPI 1 spirx_wd = ", spirx_wd);
                }
            }
            
            
            // confirm register value by read SPI reg address 0 to 6 
            
            // value "0" write each adrress(0-6) dummy write for read data
            
            spitx_wd = (uint16)(0x8000 + (i<<11)) ;
            SPIM_1_WriteTxData(spitx_wd);
                            
                if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
                    sk_log_int("SPI 2 spitx_wd = ", spitx_wd);
                }
                
            spitx_status    =   SPIM_1_ReadTxStatus()  ;
            iw=100;           
          
            while(!(spitx_status & SPIM_1_STS_SPI_DONE)){ // wait until finish writing
                CyDelayUs(5);  
                spitx_status    =   SPIM_1_ReadTxStatus()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }

            
            // register value read from  each adrress(0-6)
            
            spirx_status    =   SPIM_1_GetRxBufferSize()  ;
            iw=100;           
            while(spirx_status == 0){                      // wait until finish reading
                CyDelayUs(5);  
             spirx_status    =   SPIM_1_GetRxBufferSize()  ;
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
           }
           
            // read data store the spirx_wd
            
            spirx_wd = 0xffff ;
            spirx_wd = SPIM_1_ReadRxData(); 
            
                if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
                    sk_log_int("SPI 3 spirx_wd = ", spirx_wd);
                }
                
            
            iw=100;           
            while(spirx_wd == 0xFFFF){
                CyDelayUs(5);  
                if (iw==0){
                    ret = 1;        //SPI comunucation timeout
                    return ret;
                }
                //iw +=1;
                iw -=1;
            }

            // read data stored spirx_wd => wdwbuf[i]
            motor_parag_1[ii].m_para_wget.wdwbuf[i]=(spirx_wd & 0x07ff);
                if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
                    sk_log_int("SPI 4 .wdwbuf[i] = ",motor_parag_1[ii].m_para_wget.wdwbuf[i]);
                }
                
            if (i >=2 ){
	            if(motor_para_1.m_para_wset.rdwbuf[i] == motor_parag_1[ii].m_para_wget.wdwbuf[i]){
	                i +=1 ; 
                }else{
	                i =i; //address i register re-write
                }
	        }else{
	            if(0== motor_parag_1[ii].m_para_wget.wdwbuf[i]){
	                i +=1 ;
	            }else{
                   // mpu_status=DRIVER_FAULT ;      // abnormal driver condition;   
	                i +=1 ; //address i register re-write 
	            }
            }
 
        }
        ii +=1 ;
    }
    return ret;
}
//**************************************************************
//  subp_init : SubProgram Initialize & fundamental env check 
//**************************************************************

uint8 subp_init(void)
{
    uint8 ret;
    uint8 j;
    // start die temprature measure 
    
    sk_log_main("sub_init():001",0 );
    
    start_get_die_temp();
    
    // variable of each function Initialize
   
    sk_log_main("sub_init():002",0);
    variable_initialize();

    // To Enable Interrupt Globally
    
	CYGlobalIntEnable;

    // Start each Timer count
	Timer_cycle_Start();
	Timer_sub_cycle_Start();
	Timer_PWM_Start();

    // Start WDT 300~400ms Timer count


	/* Enable the subcycle interrupt */

  	/* *****USB UART connecting***** */

    //CyWdtStart(CYWDT_128_TICKS, CYWDT_LPMODE_NOCHANGE);
#if DEMODE3 != 1
    CyWdtStart(CYWDT_1024_TICKS, CYWDT_LPMODE_NOCHANGE); //2~3sec wdt over => restart cpu


    USBUART_1_Start(0, USBUART_1_3V_OPERATION);
    sk_log_main("sub_init():003",0);

    ret=0;
    while(ret==0){                      // USBを接続しないとここで待つ
        j=USBUART_1_DataIsReady() ;
        CyDelayUs(100); // 100us wait
        ret=USBUART_1_bGetConfiguration();
    }
    sk_log_main("sub_init():004",0);

    USBUART_1_CDC_Init();
 
    /* Enable the subcycle interrupt START Sub Cycle INT */
    sense_diagflag = 2;


    sub_cycle_int_StartEx(InterruptHandler);
#endif
/* *****USB UART connecting***** */

    sk_log_main("sub_init():005",0);

    /* VDAC for ref of SAR_ADC setting */
	VDAC8_1_Start();

    CyDelayUs(1000);

    sk_log_main("sub_init():006",0);

	/* ADC_SAR & Amux setting */
	adin = 0;
	AMux_1_Start();
	AMux_1_FastSelect(adin);
	ADC_SAR_1_Start();
	ADC_SAR_1_Enable();

    // Fundamental Environment Check
    // Die Temperature and Battery Voltage
    
	/****** Die Temp check ******/
    /* 540ms continuous error cause Die temprature fault */
    sk_log_main("sub_init():007",0);
    
    get_die_temp();
    output2_tag[22]=(uint8)die_temp;
    j=0;
    while(output2_tag[22]> HIGH_TEMP || die_status != 32){  //32:normal
        if(j>=6){
            status0 |= DIE_TEMP_ERR ;
            //state = EMSTOP;
            state = SHUTDWN;
            output2_tag[28]=state;
            output2_tag[30]=status0;

            motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF); 
             sk_PutString01("SHUTDWN02",CRLF_ON);

            return 1 ;
        }else{
            // make 90ms wait 
            start_get_die_temp();
            CyDelayUs(30000);  
            CyDelayUs(30000); 
            CyDelayUs(30000); 
            get_die_temp();
            output2_tag[22]=(uint8)die_temp;
            ++j;
        }
    }
        //pass goto Battery Voltage Ckeck
    
    

    /***** Battery Voltage  Check (main battery )  ******/
    /* 540ms continuous error cause Die temprature fault */
                    
	adin = 5;
	seq_code = 0x93;
    output2_tag[21]=get_adc_value(adin,seq_code);
    j=0;
    while(output2_tag[21]<LOW_VOLTAGE ){
        if(j>=6){
            status0 |= BATTERY_FAULT ;
            state = SHUTDWN;
            output2_tag[28]=state;
            output2_tag[30]=status0;

            motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF); 
             sk_PutString01("SHUTDWN03",CRLF_ON);

            return  1;
        }else{
            CyDelayUs(30000);  
            CyDelayUs(30000); 
            CyDelayUs(30000); 
        	adin = 5;
        	seq_code = 0x93;
            output2_tag[21]=get_adc_value(adin,seq_code);
            ++j;
        }
    }
    // SPI2 (MPU9250) initalize   )
    
    ini_spi2();
    
    return 0;
}


//***************************************************************
//	variable_initialize : variable of each function Initialize    
//***************************************************************

void variable_initialize(void)
{
    //*****************************************************
    //  main : Initialize program control variable 
    //*****************************************************

    loop_max = 0;
	die_temp_flag = 0;
	no_getcom_loop_cnt = 3;
    

    //*******************************************
    // pc2main :  variable Initialize
    //*******************************************
  	
    speed_lf = 0;
	speed_rf = 0;
	speed_lr = 0;
	speed_rr = 0;
    
	command[4] = 0;
	command[5] = 0;
	command[6] = 0;
	command[7] = 0;
	command[8] = 0;
	command[9] = 0;
	command[10] = 0;
	command[11] = 0;
    
    MS_LF_MAIN[0] =  0;			//LF WHEEL MOTOR
	MS_RF_MAIN[0] =  0;			// RF WHEEL MOTOR
	MS_LR_MAIN[0] =  0;			//LR WHEEL MOTOR
	MS_RR_MAIN[0] =  0;			// RRWHEEL MOTOR


 
    //*******************************************
	// main2pc : variable Initialize 
    //*******************************************
    
	output2_tag_head[0] = 0x02;
	output2_tag_head[1] = 0x99;
	output2_tag_head[2] = SEND_DAT_LENGTH;
	output2_tag[OUT2TAG_LENGTH-1] = 0x03;

	state = BOOT;
    status0=0;
    status1=0;
    die_status = 0;
	com_status = 0;
    trobot_status1 = 0;
    trobot_status2 = 0;

    output2_tag[27] = 0;  // soner4 
	output2_tag[28] = 0;  // soner5 
	output2_tag[29] = 0;  // soner6 
	output2_tag[30] = 0;  // soner7 
	output2_tag[31] = 0;  // bumperSW status 1: on 0: non

    //*******************************************
    //SPI sellector initialize
    //*******************************************

    spi_sel &= SPI_DRV8323_EN ; //SPI1(for motor driver SPI sellect)
    SS0_B_Write(spi_sel);
    
    //*******************************************
    //Set_PWM : variable & HW Initialize
    //*******************************************
    
    //PWM value initialize
    
    pwm_width0 =0 ;
    pwm_width1 =0 ;
    pwm_width2 =0 ;
    pwm_width3 =0 ;
    
	// PWM_0,1 setting 
	pwm_control = (blk1*16)+(sign1*8)+(blk0*4)+(sign0*2)+direct;
 	motor_contl_reg_0_Write(pwm_control);
  	CY_SET_REG8 ( Direct_dual_8bPWM_0_Direct_dual_8bPWM_u0__A0_REG , pwm_period);
  	CY_SET_REG8 ( Direct_dual_8bPWM_0_Direct_dual_8bPWM_u0__A1_REG , pwm_period);
 	CY_SET_REG8 ( Direct_dual_8bPWM_0_Direct_dual_8bPWM_u0__D0_REG , pwm_width0);
	CY_SET_REG8 ( Direct_dual_8bPWM_0_Direct_dual_8bPWM_u0__D1_REG , pwm_width1);

    // PWM_2,3 setting 
    pwm_control = (blk3*16)+(sign3*8)+(blk2*4)+(sign2*2)+direct;
 	motor_contl_reg_1_Write(pwm_control);

  	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__A0_REG , pwm_period);
  	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__A1_REG , pwm_period);
 	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__D0_REG , pwm_width2);
	CY_SET_REG8 ( Direct_dual_8bPWM_1_Direct_dual_8bPWM_u0__D1_REG , pwm_width3);

    
    //*******************************************
    // Sub_Calc1 : variable pre-calcuration 
    //*******************************************

 	ratio_rpm = 60*samp_rate/enc_count;             
	//max_speed = max_rpm*rpm2velo_ratio;  // speed (km/h)


    
    //*****************************************************
    // Motor_Cntl4_3 function: (PID parameter Initialize)
    //*****************************************************

    // PID parameter setting for velocity cntl 
	kvp = 3.0 ; // motor velocity kvp=3.3
	kvi = 20.0 ; //motor velocity kvi=10.0
	satv = 12.0 ; //motor velocity satv=24.0
	rpm2velo_ratio=0.06/gear_ratio*calc_ratio*dim_wheel*3.141516; //rpm to speed(Km/h) Coef

    // PID parameter setting for torque cntl 
	kcp = 1.0 ; // motor torque kcp=1.0
	kci = 3.0; //motor torque kci=10.0
	satc = 10.0 ; //motor torque satc=24.0
    
    // motor_cntl subroutin initialize
	Motor_Contl4_3_initialize();

}
//************************************************
//	get Die Temprature DATA       
//************************************************

void start_get_die_temp(void)
{
	//static uint8 Status= (uint8)CYRET_UNKNOWN;    
    
        #if DEMODE == 1
        	pout(0xc0) ; //47.19us
        #endif
    
    /* Die Temp Measurement Start */
    
    //if (Status != (uint8)CYRET_STARTED){
	    Status = (uint8)DieTemp_1_Start();
    //}
        #if DEMODE == 1
        	pout(0xc1) ; //52.34us
            pout(Status);  // Status:7 STARTED 
        	pout(0xc6) ;  //55.43us
        #endif
        
}

//************************************************
//	get Die Temprature DATA       
//************************************************

void get_die_temp(void)
{
	//static uint8 Status= (uint8)CYRET_UNKNOWN;    
    uint8 i;
    //uint8 val;
    int16 die_temp_l;
    uint8 die_status_l;
    
    die_status_l= 32;
        #if DEMODE == 1
        	pout(0xc0) ; //13L:42.91us
        #endif
    
    /* Die Temp Measurement Start */
//	Status = (uint8)DieTemp_1_Start();
	i = 0;
        #if DEMODE == 1
//        	pout(0xc1) ; //13L:48.02us
//            pout(Status);
        	pout(0xc6) ;            
        #endif
    
    // Get Die temp measurement loop limit 100 loop cycle
    
	while(Status != (uint8)CYRET_SUCCESS){
		Status = (uint8)DieTemp_1_Query(&die_temp_l);
		CyDelayUs(1);
        #if DEMODE == 1
        	pout(0xc1) ; //58.11us
            pout(Status);
        #endif

		i++;
        if (i >100) break;
	}
    
    die_temp = die_temp_l;
    
        #if DEMODE == 1
        	pout(0xc2) ;
        #endif
  
    // Get temp data in succeed
	die_status_l = 32; //0x20 : normal
    if(Status == (uint8)CYRET_SUCCESS){
        if((die_temp >= 140) ||(die_temp <= -40)){               //plus data
			die_temp = 0x8f;
		}else{
            //NOP : normal data
        }
            
    }else if(Status == (uint8)CYRET_UNKNOWN){
		die_temp = 0x8f;
		die_status_l = 0x10; // unknown
	}
	else if(Status == (uint8)CYRET_TIMEOUT){
		die_temp = 0x8f;
		die_status_l = 0x40; //time_out
	}else{
		die_temp= 0x8f;
		die_status_l = 0x80; // other error
	}
    
    die_status= die_status_l;
    
        #if DEMODE == 1
            pout(0xc3) ; //13L:62.92us 
        #endif
        #if DEMODE1 == 1
    		pout(die_temp) ;
    		pout(0xc5);
        #endif
 
}


//***********************************************
// get_adc_value: measure ADC value for adin
//***********************************************

uint8 get_adc_value(uint8 adin_l, uint8 seq_code_l)
{
    
    uint8 ret ;
   
    //adin_l = 1;
	AMux_1_FastSelect(adin_l);
	//CyDelayUs(50);
	CyDelayUs(20);

	ADC_SAR_1_StartConvert();
    
	ret = ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT);

    if(ret){
		mes_adc_val = (uint8)(ADC_SAR_1_GetResult16() / 16);
        
        sk_adc_debug( adin, mes_adc_val );
    }
	else{
		mes_adc_val = 0xfe;
    }
        #if DEMODE == 1
        		pout(seq_code_l) ; //13L 90.22us pmv1:114.295us
        #endif
        #if DEMODE1 == 1
        		pout(mes_adc_val) ;
        		pout(seq_code_l);
        #endif
        
    return mes_adc_val;
}

void diag_sense(void)
{
    uint8 ret;
      
    if (trans_line==0) diag_count=0;
       
	switch(trans_line%4){ // every 1/16/4 sec(=15.625ms)
		case 0:    
            //****** [PreProcess] Counter setting
                #if DEMODE == 1
                	pout(0xd0) ;	//Counter calc
                #endif 
            if(state==SHUTDWN){
                 sk_PutString01("SHUTDWN04",CRLF_ON);
                break;
            }
            ++diag_count;
                
            //****** [DIAG] Measure Die Temperature
                #if DEMODE == 1
                	pout(0xd1) ;	//enter diag_sense function
                #endif 
            get_die_temp();    	
            die_temp_16 +=(uint8)die_temp;
            if(trans_line>11){
                //if(state == EMSTOP) --emstop_timeover;
                output2_tag[22] =(uint8)(die_temp_16>>2);
                die_temp_16 =0;
                if((diag_count >= 4 ) && ((output2_tag[22]>>2)> HIGH_TEMP || die_status != 32)){
                    status0 |= DIE_TEMP_ERR ;
                    ++flt_dtm_tmover;
                    if(flt_dtm_tmover>= WDT_SHTDWN_LIMIT_FRM){
                        state = SHUTDWN;
                        motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);   // PVM1,PVM2:off  sel:disEN  pDRV:disEN
                         sk_PutString01("SHUTDWN05",CRLF_ON);
                        break;
                    }
                }else{
                    
                    //pass goto Battery Voltage Ckeck (NOP)
                    status0 &= ~(uint8)DIE_TEMP_ERR ;
                    flt_dtm_tmover =0;

                }
            }
            //****** Die Temp measure Start
                #if DEMODE == 1
                	pout(0xd7) ;	//13L: 41.19us
                #endif
            start_get_die_temp();

			//****** [DIAG] Battery Voltage  Check (main battery )
                #if DEMODE == 1
                	pout(0xd2) ;	//enter diag_sense function
                #endif 
    		adin = 5;
            seq_code =0xb1;
            v_bat_16 +=get_adc_value(adin,seq_code);
            

            if(trans_line>11){
                output2_tag[21] =(uint8)((v_bat_16>>2)*1.0); // x8 volt
                v_bat_16 =0;
                if((diag_count >= 4 ) && (output2_tag[21]<LOW_VOLTAGE) ){
                    status0 |= BATTERY_FAULT ;
                    ++flt_bat_tmover;
                    if(flt_bat_tmover>= WDT_SHTDWN_LIMIT_FRM){
                        state = SHUTDWN;
                        motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);   // PVM1,PVM2:off  sel:disEN  pDRV:disEN
                         sk_PutString01("SHUTDWN06",CRLF_ON);
                        break;
                    }
                }else{
                    
                    //pass goto PVM1 Voltage Ckeck(NOP)
                    status0 &= ~(uint8)BATTERY_FAULT ;
                    flt_bat_tmover=0;

                }
                
			}

            //******* [SENSE]DET_SW(main SWitch off 
                #if DEMODE == 1
                	pout(0xdf) ;	//enter diag_sense function
                #endif           
            if(trans_line>11){
                if( (diag_count >= 4 ) &&(dist8_SW_DET_Read()!= 0) ){ 
                    // Main sw turn OFF
                    status0 |= POWER_SW_OFF;
                    ++flt_msw_tmover;
                    if(flt_msw_tmover>= WDT_SHTDWN_LIMIT_FRM){
                        state = SHUTDWN;
                        motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);   // PVM1,PVM2:off  sel:disEN  pDRV:disEN
                         sk_PutString01("SHUTDWN07",CRLF_ON);
                        break;
                    }
                }else{
                    // Main sw Keep ON
                    status0 &= ~POWER_SW_OFF;
                    flt_msw_tmover=0;
                }
            }
            
            //****** [DIAG] EM_stop_signal check
                #if DEMODE == 1
                	pout(0xd3) ;	//enter diag_sense function
                #endif 
            if(state==FAULT){
                 sk_PutString01("FAULT01",CRLF_ON);
                break;
            }

            if(trans_line>11){
                if( ((motor_en_reg_Read() & 0x04) != 4  )){
                    status0 |= EM_STOP_OUT ;
                    ++ems_sig_tmover;
                    if((ems_sig_tmover>= WDT_FAULT_LIMIT_FRM)&&(state==EMSTOP)){
                        state = FAULT;
                        motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);   // PVM1,PVM2:off  sel:disEN  pDRV:disEN
                        sk_PutString01("FAULT02",CRLF_ON);
                        break;
                    }else if((ems_sig_tmover>= WDT_ESTOP_LIMIT_FRM)&&(state!=EMSTOP)){
                        state = EMSTOP;
                        sk_PutString01("ESTOP01",CRLF_ON);
                        break;
                    }
                }else{ 
                    //pass goto PVM1 Voltage Ckeck
                    status0 &= ~(uint8)EM_STOP_OUT ;
                    ems_sig_tmover=0 ;
                }
            }
            
            if(drive_wheels == 2){
			//****** [DIAG] PVM1 (Power Voltage 1)  Check 
                    #if DEMODE == 1
                    	pout(0xd4) ;	//enter diag_sense function
                    #endif 
        		adin = 6;
                seq_code =0xb4;
                pvm1_16 +=get_adc_value(adin,seq_code);
                if(trans_line>11){

                    output2_tag[15] = (uint8)((pvm1_16>>2)*1.0) ; // x8 Volt
                    output2_tag[16] = 0 ; // x8 Volt
                    pvm1_16 = 0;
                    if((diag_count >= 4 ) && (output2_tag[15]<LOW_VOLTAGE )){
                        status0 |= PVM1_FAULT ;
                        ++ems_pvm_tmover;
                        if((ems_pvm_tmover>= WDT_FAULT_LIMIT_FRM)&&(state==EMSTOP)){
                            state = FAULT;
                            motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);   // PVM1,PVM2:off  sel:disEN  pDRV:disEN
                            sk_PutString01("FAULT03",CRLF_ON);
                            break;
                        }else if((ems_pvm_tmover>= WDT_ESTOP_LIMIT_FRM)&&(state!=EMSTOP)){
                            state = EMSTOP;
                            sk_PutString01("ESTOP02",CRLF_ON);
                        }

                    }else{
                        //pass goto PVM2 Voltage Ckeck
                        status0 &= ~(uint8)PVM1_FAULT ;
                        ems_pvm_tmover = 0;
                    }

                }
            
            }else{
			//****** [DIAG] PVM2 (Power Voltage 2)  Check 
                    #if DEMODE == 1
                    	pout(0xd5) ;	//enter diag_sense function
                    #endif 

                adin = 6;
                seq_code =0xb4;
                pvm1_16 +=get_adc_value(adin,seq_code);
        
        		adin = 7;
                seq_code =0xb5;
                pvm2_16 +=get_adc_value(adin,seq_code);
        		if(trans_line>11){
                    output2_tag[15] = (uint8)((pvm1_16>>2)*1.0) ; // x8 Volt
                    output2_tag[16] = (uint8)((pvm2_16>>2)*1.0) ; // x8 Volt
                    pvm1_16 = 0;
                    pvm2_16 = 0;
                    if((diag_count >= 4 ) &&((output2_tag[15]<LOW_VOLTAGE )||(output2_tag[16]<LOW_VOLTAGE ))){
                        status0 |= PVM1_FAULT ;
                        status0 |= PVM2_FAULT ;
                        ++ems_pvm_tmover;
                        if((ems_pvm_tmover>= WDT_FAULT_LIMIT_FRM)&&(state==EMSTOP)){
                            state = FAULT;
                            motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);   // PVM1,PVM2:off  sel:disEN  pDRV:disEN
                            sk_PutString01("FAULT04",CRLF_ON);
                            break;
                        }else if((ems_pvm_tmover>= WDT_ESTOP_LIMIT_FRM)&&(state!=EMSTOP)){
                            state = EMSTOP;
                            sk_PutString01("ESTOP03",CRLF_ON);
                        }

                    }else{
                        //pass goto PVM2 Voltage Ckeck
                        status0 &= ~(uint8)PVM1_FAULT ;
                        status0 &= ~(uint8)PVM2_FAULT ;
                        ems_pvm_tmover = 0;
                    }

                }
			}
            
            //****** [DIAG] Motor Pre Drive FAULT Check
                #if DEMODE == 1
                	pout(0xd6) ;	//enter diag_sense function
                #endif 
                         
            if(trans_line>11){
                ret=SS0_B_Read();
                spi_drv_read();

                if(!(MOTOR_FAULT_Read()& 0x01)&&(diag_count >= 4 )){
                    status1 |= DRV_SPI_ERR ;
                    ++ems_drv_tmover;
                    if((ems_drv_tmover>= WDT_FAULT_LIMIT_FRM)&&(state==EMSTOP)){
                        state = FAULT;
                        motor_en_reg_Write((uint8)MOT_CIR_ALL_OFF);   // PVM1,PVM2:off  sel:disEN  pDRV:disEN
                        sk_PutString01("FAULT05",CRLF_ON);
                        SS0_B_Write(ret);
                        break;
                    }else if((ems_drv_tmover>= WDT_ESTOP_LIMIT_FRM)&&(state!=EMSTOP)){
                        state = EMSTOP;
                        sk_PutString01("ESTOP04",CRLF_ON);
                    }

                }else{
                    //pass goto PVM2 Voltage Ckeck
                    status1 &= ~(uint8)DRV_SPI_ERR ;
                    ems_drv_tmover = 0;
                }
                SS0_B_Write(ret);

            }
 

			break;

        case 1:    
            //****** [SENSE] ACCEL METER 9Axis 
                #if DEMODE == 1
                	pout(0xd8) ;	//enter diag_sense function
                #endif           
            spi_sel = 111;
            ret = spi_read_bytes(spi_sel, 0x3b, 4, 0);
            axis9[0] += (int16)(((uint16)tmp[0]<<8)+tmp[1]);
            axis9[1] += (int16)(((uint16)tmp[2]<<8)+tmp[3]);

            spi_sel = 111;
            ret = spi_read_bytes(spi_sel, 0x3f, 2, 0);
            axis9[2] += (int16)(((uint16)tmp[0]<<8)+tmp[1]);
            if(trans_line>11){

                output2_tag[3] = (int8)(axis9[0]>>10); //63.11us
                output2_tag[4] = ((int8)(axis9[0]>>2)); //63.11us
                output2_tag[5] = (int8)(axis9[1]>>10); //63.11us
                output2_tag[6] = ((int8)(axis9[1]>>2)); //63.11us
                output2_tag[7] = (int8)(axis9[2]>>10); //63.11us
                output2_tag[8] = ((int8)(axis9[2]>>2)); //63.11us
                axis9[0] = 0;
                axis9[1] = 0;
                axis9[2] = 0;
     	
			}
			
            //******* [SENSE] Gyro METER 9Axis 
                #if DEMODE == 1
                	pout(0xd9) ;	//enter diag_sense function
                #endif           
            spi_sel = 111;
            ret = spi_read_bytes(spi_sel, 0x43, 4, 0);
            axis9[3] += (int16)(((uint16)tmp[0]<<8)+tmp[1]);
            axis9[4] += (int16)(((uint16)tmp[2]<<8)+tmp[3]);
            spi_sel = 111;
            ret = spi_read_bytes(spi_sel, 0x47, 2, 0);
            axis9[5] += (int16)(((uint16)tmp[0]<<8)+tmp[1]);
            if(trans_line>11){

                output2_tag[9] = (int8)(axis9[3]>>10); //63.11us
                output2_tag[10] = ((int8)(axis9[3]>>2)); //63.11us
                output2_tag[11] = (int8)(axis9[4]>>10); //63.11us
                output2_tag[12] = ((int8)(axis9[4]>>2)); //63.11us
                output2_tag[13] = (int8)(axis9[5]>>10); //63.11us
                output2_tag[14] = ((int8)(axis9[5]>>2)); //63.11us
                axis9[3] = 0;
                axis9[4] = 0;
                axis9[5] = 0;
            }
			break;
           

        case 2:     
            //****** [SENSE] Distance Sensor 1 Check [front]
            //if (frame_count %4 ==3){  //for 1/4 Hz sonner measure
            if(trans_line>11){
                    #if DEMODE == 1
                    	pout(0xda) ;	//enter diag_sense function
                    #endif 
     
                adin = 1;
                seq_code =0X97;
                dist_front +=get_adc_value(adin,seq_code); //63.11us
                //output2_tag[24] = (uint8)(dist_front>>2); //63.11us
                output2_tag[24] = (uint8)dist_front; //63.11us
                dist_front =0;
            }
            //}
            //****** [SENSE] Distance Sensor 3  Check[rear] 
            //if (frame_count %4 ==3){  //for 1/4 Hz sonner measure
            if(trans_line>11){
                    #if DEMODE == 1
                    	pout(0xdb) ;	//enter diag_sense function
                    #endif 
                adin = 3;
                seq_code =0X99;
                dist_rear +=get_adc_value(adin,seq_code); //63.11us
                //output2_tag[26] = (uint8)(dist_rear>>2); //63.11us
                output2_tag[26] = (uint8)dist_rear; //63.11us
                dist_rear =0;
            }
            //}

		    break;


        case 3:     
            //****** [SENSE] Distance Sensor 0 Check [right front]
            //if (frame_count %4 ==3){  //for 1/4 Hz sonner measure
            if(trans_line>11){
                    #if DEMODE == 1
                    	pout(0xdc) ;	//enter diag_sense function
                    #endif 
                adin = 0;
                seq_code =0X98;
                dist_fr +=get_adc_value(adin,seq_code); //63.11us
                //output2_tag[23] = (uint8)(dist_fr>>2); //63.11us
                output2_tag[23] = (uint8)dist_fr; //63.11us
                dist_fr =0;
            }
            //}
            
            //****** [SENSE] Distance Sensor 2 Check [left front]
            //if (frame_count %4 ==3){  //for 1/4 Hz sonner measure
            if(trans_line>11){
                    #if DEMODE == 1
                    	pout(0xdd) ;	//enter diag_sense function
                    #endif 
                adin = 2;
                seq_code =0X98;
                dist_fl +=get_adc_value(adin,seq_code); //63.11us
                //output2_tag[25] = (uint8)(dist_fl>>2); //63.11us
                output2_tag[25] = (uint8)dist_fl; //63.11us
                dist_fl =0;
            }
            //}
			
            //****** [SENSE] STEP Distance Sensor Check 
                #if DEMODE == 1
                	pout(0xde) ;	//enter diag_sense function
                #endif           
            adin = 4;
            seq_code =0X9a;
            dist_st +=get_adc_value(adin,seq_code); //63.11us
            if(trans_line>11){
                output2_tag[27] = (uint8)(dist_st>>2); //63.11us
                dist_st =0;
    		}	
		    break;


            
        default :
        break;
    }
    if(trans_line>11){
        output2_tag[28]=state;
        output2_tag[29]=status1;
        output2_tag[30]=status0;
	}
        
        #if DEMODE == 1
        		pout(0xd0) ; //11L:56.72us 12L:38.52us 13L:118.81us
        #endif 
	return;
   
}

//----------------------------------------------------------
// Setup SPI I/F devices MPU9250
void ini_spi2(void)
{
	uint8	ret;
    uint8 spi2_status1;
    uint8 spi2_status;
    uint8 spi2_whoami;
    spi_sel = 111;
    SS0_B_Write(spi_sel);    // SPI_1 enable
    SPIM_2_Start();

    //spi_sel = 111;
 	ret=spi2_clr_buff();
 	
 	if(ret == 1)
		spi2_status1 |= 1;
	else if(ret == 2)
		spi2_status |= 1;
	else if(ret == 3){
		spi2_status |= 16;
	}
    
    
	//check 9deg chip (read whoami reg(0x75)
    //tmp[0]=0x71 : mpu9250
    //tmp[0]=0x

    ret = spi_read_bytes(spi_sel, 0x75, 1, 0);
    spi2_whoami = tmp[0];

	//set config reg adr 0x1a value 0x00
	ret = spi_write_byte(spi_sel, 0x1a, 0x0, 0x3f);
	if(ret == 1)
		spi2_status1 |= 1;
	else if(ret == 2)
		spi2_status |= 1;
	else if(ret == 3){
		spi2_status |= 16;
	}

	CyDelayUs(20);

    //set accel_config reg adr 0x1c value 0x00
    
	ret = spi_write_byte(spi_sel, 0x1c, 0x0, 0x1f);//accel_fs_SEL= +-2g
	if(ret == 1)
		spi2_status1 |= 1;
	else if(ret == 2)
		spi2_status |= 1;
	else if(ret == 3){
		spi2_status |= 16;
	}

	CyDelayUs(20);

    //set PWR_MGMT_1 reg adr 0x6b value 0x00
	ret = spi_write_byte(spi_sel, 0x6b, 0x0, 0x6f); 
	if(ret == 1)
		spi2_status1 |= 1;
	else if(ret == 2)
		spi2_status |= 1;
	else if(ret == 3){
		spi2_status |= 16;
	}

	CyDelayUs(20);

    //set INT_PIN_CFG reg adr 0x37 value 0x02

	ret = spi_write_byte(spi_sel, 0x37, 0x2, 0xff);//Bypass enable
	if(ret == 1)
		spi2_status1 |= 1;
	else if(ret == 2)
		spi2_status |= 1;
	else if(ret == 3){
		spi2_status |= 16;
	}

	CyDelayUs(20);
    
    //set GYRO_CONFIG reg adr 0x371b value 0x10
	
	ret = spi_write_byte(spi_sel, 0x1b, 0x18, 0x18); //FS_SEL=2000 dps
	//ret = spi_write_byte(spi_sel, 0x1b, 0x10, 0x18); //FS_SEL=1000 dps
	//ret = spi_write_byte(spi_sel, 0x1b, 0x0, 0x18); //FS_SEL=250 dps
	if(ret == 1)
		spi2_status1 |= 2;
	else if(ret == 2)
		spi2_status |= 2;
	else if(ret == 3){
		spi2_status |= 32;
	}

	CyDelayUs(20);
  	ret=spi2_clr_buff();
   
    
    //test read
                ret = spi_read_bytes(spi_sel, 0x75, 1, 0);
                axis9[0] += (int16)(tmp[1]);
 	ret=spi2_clr_buff();

	//Compass AK8975
    /*	
    ret = spi_write_byte(I2CAK8975, 0x0a, 1, 0xff);
	if(ret == 1)
		spi2_status1 |= 4;
	else if(ret == 2)
		spi2_status |= 4;
	else if(ret == 3){
		spi2_status |= 64;
	}
    */
}

//----------------------------------------------------------#01 add
uint8 spi_write_byte(uint8 devadr, uint8 regadr, uint8 wr_dat, uint8 mask)
{
	uint8	wr_data;
	//uint8	k;
	//uint8	rd_data;
	uint8	err = 0;
    uint8 iw;
    
    if( sk_log_flg2 & SK_LOG2_SPI_WR  ){
        sk_log_int("SPI_WR:devadr = ",devadr );
        sk_log_int("SPI_WR:regadr = ",regadr );
        sk_log_int("SPI_WR:wr_dat = ",wr_dat );
        //sk_log_int("SPI_WR:mask = ",mask );
    }
        
    SS0_B_Write(devadr);    // SPI_1 enable
	wr_data = wr_dat;
	SPIM_2_WriteTxData(regadr);
	SPIM_2_WriteTxData(wr_data);
    err    =   SPIM_2_ReadTxStatus()  ;
    
    iw=100;           
    while(!(err & SPIM_2_STS_SPI_DONE)){  // wait until finish writing
        CyDelayUs(5);  
        err    =   SPIM_2_ReadTxStatus()  ;
        if (iw==0){
            if( sk_log_flg2 & SK_LOG2_SPI_WR  ){
                sk_log_int("SPI_WR:err = ",err );
            }
            return 1;        //SPI comunucation timeout
        }
        iw +=1;
    }
    
    spi2_clr_buff();

	return err;
}

//----------------------------------------------------------#01 add
uint8 spi_read_bytes(uint8 devadr, uint8 regadr, uint8 num, uint8 start)
{
	//uint8	k;
	uint8	err = 0;  
    uint8   iw;
    uint8   i ;
    //spi2_clr_buff();
    i = 0 ;
	if (num < 1){
        num = 1;
	}
    else if (num > 4){
        num = 4;
    }
    
    SS0_B_Write(devadr);    // SPI_1 enable
	regadr = 0x80 + regadr;

//	I2C_1_MasterClearStatus();

	SPIM_2_WriteTxData(regadr);
    
    while ( i < num){
    	SPIM_2_WriteTxData(0x00);
        ++i;
    }
     
    err    =   SPIM_2_ReadTxStatus()  ;
    iw=100;           
    while(!(err & SPIM_2_STS_SPI_DONE)){  // wait until finish writing
        CyDelayUs(5);  
        err    =   SPIM_2_ReadTxStatus()  ;
        if (iw==0){
            return 1;        //SPI comunucation timeout
        }
        iw +=1;
    }
    
    i=0;
    tmp[i+start] = SPIM_2_ReadRxData() ;  //dummy read RX buffer for write adrress

    while ( i < num){
        tmp[i+start] = SPIM_2_ReadRxData() ; 
        ++i;
    }

	CyDelayUs(2);

	return err;	
}

uint8 spi2_clr_buff(void)
{
    uint8 spirx_status;
    uint8 spitx_status;
    uint8   iw;

 
    // SPI RX buffer clear for MPU9250
    
    spirx_status    =   SPIM_2_ReadRxStatus()  ;
    iw=100;
    while(spirx_status & SPIM_2_STS_RX_FIFO_NOT_EMPTY){
        SPIM_2_ClearRxBuffer();
        spirx_status    =   SPIM_2_ReadRxStatus()  ;
        if (iw==0){
            return 1;        //SPI comunucation timeout
        }
        iw +=1;
    }
    
    // SPI TX buffer clear for MPU9250 
    
    spitx_status    =   SPIM_2_ReadTxStatus()  ;
    iw=100;           
    while(!(spitx_status & SPIM_2_STS_SPI_IDLE)){
        SPIM_2_ClearTxBuffer();
        spitx_status    =   SPIM_2_ReadTxStatus()  ;
        if (iw==0){
            return 2;        //SPI comunucation timeout
        }
        iw +=1;

    }
    return 0;
}

uint8 intmax( uint8 a, uint8 b)
{
    if (a>b) {
        return a;
    } else {
        return b;
    }
}
