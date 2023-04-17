/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"
#include "sk_common.h"



//--------------------------------------------------------------------
// Gloval Variable Definition
//--------------------------------------------------------------------
extern float 	gear_ratio	;
extern float 	dim_wheel	;
extern float 	dist_wheel	;
extern float 	toruque_const	;
extern float 	speed_const	;
extern float 	spd_torq_grad	;
extern float 	acc_limit_f	;
extern float 	acc_limit_r	;
extern float 	acc_limit_s	;
extern float 	safty_const 	;
extern float 	kvp	;
extern float 	kcp	;
extern float 	kvi	;
extern float 	kci	;
extern float 	kdl	;
extern float 	kdr	;
extern float 	satv	;
extern float 	satc 	;
extern float 	ratio_rpm	;
extern float 	rpm2velo_ratio	;


extern int32	axis9[10]	;
extern int32	getcom_count	;
extern int32	getcom_count_buf	;
extern int32	getcom_count_para	;
extern int32	getcom_flag	;
extern int32	getcom_watch	;
extern int32	ms00_pw	;
extern int32	ms01_pw	;
extern int32	ms02_pw	;
extern int32	ms03_pw	;
extern int32	out2_tag_cycle	;
extern int32	out2_tagpos	;
extern int32	out2len	;
extern int32	out2pos	;
extern int32	output_tmp[4]	;
extern int32	sendcom_flag	;
extern int32	speed_lf	;
extern int32	speed_lf_buf	;
extern int32	speed_lf_delta	;
extern int32	speed_lf_pre	;
extern int32	speed_lr	;
extern int32	speed_lr_buf	;
extern int32	speed_lr_delta	;
extern int32	speed_lr_pre	;
extern int32	speed_rf	;
extern int32	speed_rf_buf	;
extern int32	speed_rf_delta	;
extern int32	speed_rf_pre	;
extern int32	speed_rr	;
extern int32	speed_rr_buf	;
extern int32	speed_rr_delta 	;
extern int32	speed_rr_pre	;


extern 	int16	die_temp ;
extern 	int16	die_temp_16 ;
extern 	int16	speedratio ;
extern 	int16	ms_lf_pc ;
extern 	int16	ms_rf_pc ;
extern 	int16	ms_lr_pc ;
extern 	int16	ms_rr_pc ;
extern 	int16	MS_LF_MAIN[3] ;
extern 	int16	MS_RF_MAIN[3] ;
extern 	int16	MS_LR_MAIN[3] ;
extern 	int16	MS_RR_MAIN[3] ;
extern 	int16	ms_lf_com_tx ;
extern 	int16	ms_rf_com_tx ;
extern 	int16	ms_lr_com_tx ;
extern 	int16	ms_rr_com_tx ;
extern 	int16	speedratio ;
extern 	int16	max_spd_chg ;
extern 	int16	acc_limit_f_i16 ;
extern 	int16	acc_limit_r_i16 ;
extern 	int16	acc_limit_s_i16 ;
extern 	int16	safty_const_i16 ;
extern 	int16	kvp_i16 ;
extern 	int16	kcp_i16 ;
extern 	int16	kvi_i16 ;
extern 	int16	kci_i16 ;
extern 	int16	kdl_i16 ;
extern 	int16	kdr_i16 ;
extern 	int16	satv_i16 ;
extern 	int16	satc_i16 ;
			
extern 	int8	die_temp_flag ;
extern 	int8	logmode ;
extern 	int8	direct_cnt ;
extern 	int8	em_stop_en ;
extern 	int8	use_smooth_chg ;
extern 	int8	measure_sensor ;
extern 	int8	motorassign[4] ;
extern 	int8	encassign[4] ;
extern 	int8	cw0 ;
extern 	int8	cw1 ;
extern 	int8	cw2 ;
extern 	int8	cw3 ;
extern 	int8	encd0 ;
extern 	int8	encd1 ;
extern 	int8	encd2 ;
extern 	int8	encd3 ;
extern 			
	uint16	dist_front ;
extern 	uint16	dist_rear ;
extern 	uint16	dist_fr ;
extern 	uint16	dist_fl ;
extern 	uint16	dist_st ;
extern 	uint16	v_bat_16 ;
extern 	uint16	pvm1_16 ;
extern 	uint16	pvm2_16 ;
extern 	uint16	max_rpm ;
extern 	uint16	gear_motor ;
extern 	uint16	samp_rate ;
extern 	uint16	enc_count ;
extern 	uint16	enc_malti ;
extern 	uint16	dim_wheel_i16 ;
extern 	uint16	dist_wheel_i16 ;
extern 	uint16	toruque_const_i16 ;
extern 	uint16	speed_const_i16 ;
extern 	uint16	spd_torq_grad_i16 ;
			
extern 	uint8	adin ;
extern 	uint8	blk0 ;
extern 	uint8	blk1 ;
extern 	uint8	blk2 ;
extern 	uint8	blk3 ;
extern 	uint8	bwp_sw ;
extern 	uint8	calc_ratio ;
extern 	uint8	com_status ;
extern 	uint8	cycle_count ;
extern 	uint8	cycle_count_buf ;
extern 	uint8	cycle_count_pre ;
extern 	uint8	diag_count ;
extern 	uint8	die_status ;
extern 	uint8	direct ;
extern 	uint8	drive_wheels ;
extern 	uint8	err_wdt_atm_spi ;
extern 	uint8	err_wdt_axis9_spi ;
extern 	uint8	err_wdt_body_oh[3] ;
extern 	uint8	err_wdt_cpuv[4] ;
extern 	uint8	err_wdt_die_otp ;
extern 	uint8	err_wdt_drv_dis ;
extern 	uint8	err_wdt_drv_spi[4] ;
extern 	uint8	err_wdt_em_stop_out ;
extern 	uint8	err_wdt_gdf[4] ;
extern 	uint8	err_wdt_mot_fault ;
extern 	uint8	err_wdt_otsd[4] ;
extern 	uint8	err_wdt_otw[4] ;
extern 	uint8	err_wdt_ov_spd[4] ;
extern 	uint8	err_wdt_pvm_low[2] ;
extern 	uint8	err_wdt_pvm_ocpat[2] ;
extern 	uint8	err_wdt_pvm_ocur[2] ;
extern 	uint8	err_wdt_sa_ocp[4] ;
extern 	uint8	err_wdt_sa_ocpat[4] ;
extern 	uint8	err_wdt_sw_dt ;
extern 	uint8	err_wdt_usb_if ;
extern 	uint8	err_wdt_uvlo[4] ;
extern 	uint8	err_wdt_vbat_low ;
extern 	uint8	err_wdt_vds_ocp[4] ;
extern 	uint8	loop_max ;
extern 	uint8	mes_adc_val ;
extern 	uint8	pwm_control ;
extern 	uint8	pwm_period ;
extern 	uint8	pwm_width0 ;
extern 	uint8	pwm_width1 ;
extern 	uint8	pwm_width2 ;
extern 	uint8	pwm_width3 ;
extern 	uint8	sign0 ;
extern 	uint8	sign1 ;
extern 	uint8	sign2 ;
extern 	uint8	sign3 ;
extern 	uint8	spi_sel ;
extern 	uint8	tmp[4] ;
extern 	uint8	trobot_status1 ;
extern 	uint8	trobot_status2 ;



//--------------------------------------------------------------------
// Gloval Variable Definition
//--------------------------------------------------------------------

extern uint8 command_para[64];
extern uint8 command[64];

extern uint8 outbuff1[59];
extern uint8 outbuff2[56];
extern uint8 outbuff3[30];
#define OUT2TAG_LENGTH          33          /* Length of tag data to pc = 33byte*/
extern uint8 output2_tag[OUT2TAG_LENGTH];
/**
//--------------------------------------------------------------------
// Gloval Variable Definition
//--------------------------------------------------------------------
        
// variable for program flow control 
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

// future check item
uint8   ems_pvc_tmover =0 ;  // Pvm current over error timeover counter
uint8   ems_mtc_tmover =0 ;  // motor drive current over error timeover counter
uint8   ems_btm_tmover =0 ;  // board temprature high error timeover counter

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

/* trobot farm status 
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

**/

/* [] END OF FILE */
