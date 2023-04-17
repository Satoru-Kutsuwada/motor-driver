/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================*/


#include "Motor_Contl4_3.h"
#include "Motor_Contl4_3_private.h"
#include "sk_source.h"
#include <RTC_1.h>

extern RT_MODEL_Motor_Contl4_3 Motor_Contl4_3_M_;
//extern void RTC_1_Start(void) ;


// 2 bit0-1

            
            
const COM_PARA compara_dital[] = {
    { 0 , " :  "},
    { 1 , " :  "},
    { 2 , " :  "},
    { 3 , " :  "},
    { 4 , " :  "},
    { 4 , " :  b0-1:logmode"},
    { 4 , " :  b2:direct_cnt"},
    { 4 , " :  b3:em_stop_en"},
    { 4 , " :  b4:use_smooth_chg"},
    { 4 , " :  b5:measure_sensor"},
    { 4 , " :  b6:drive_wheels"},
    { 5 , " :  (U)speedratio"},
    { 6 , " :  (L)"},
    { 7 , " :  (U)max_spd_chg"},
    { 8 , " :  (L)"},
    { 9 , " :  Assign MOT"},
    { 9 , " :  motorassign[4]"},
    { 10 , " :  Assign ENC"},
    { 10 , " :  encassign[4]"},
    { 11 , " :  Sig Direction"},
    { 11 , " :  encd0,encd1,encd2,encd3"},
    { 11 , " :  cw0,cw1,cw2,cw3"},
    { 12 , " :  enc_malti"},
    { 13 , " :  (U)max_rpm"},
    { 14 , " :  (L)"},
    { 15 , " :  (U)gear_ratio_i16"},
    { 16 , " :  (L)"},
    { 17 , " :  (U)samp_rate"},
    { 18 , " :  (L)"},
    { 19 , " :  (U)enc_count"},
    { 20 , " :  (L)"},
    { 21 , " :  (U)dim_wheel_i16"},
    { 22 , " :  (L)"},
    { 23 , " :  (U)dist_wheel_i16"},
    { 24 , " :  (L)"},
    { 25 , " :  (U)toruque_const_i16"},
    { 26 , " :  (L)"},
    { 27 , " :  (U)speed_const_i16"},
    { 28 , " :  (L)"},
    { 29 , " :  (U)spd_torq_grad_i16"},
    { 30 , " :  (L)"},
    { 31 , " :  (U)acc_limit_f_i16"},
    { 32 , " :  (L)"},
    { 33 , " :  (U)acc_limit_r_i16"},
    { 34 , " :  (L)"},
    { 35 , " :  (U)acc_limit_s_i16"},
    { 36 , " :  (L)"},
    { 37 , " :  (U)safty_const_i16"},
    { 38 , " :  (L)"},
    { 39 , " :  (U)kvp_i16"},
    { 40 , " :  (L)"},
    { 41 , " :  (U)kcp_i16"},
    { 42 , " :  (L)"},
    { 43 , " :  (U)kvi_i16"},
    { 44 , " :  (L)"},
    { 45 , " :  (U)kci_i16"},
    { 46 , " :  (L)"},
    { 47 , " :  (U)kdl_i16"},
    { 48 , " :  (L)"},
    { 49 , " :  (U)kdr_i16"},
    { 50 , " :  (L)"},
    { 51 , " :  (U)satv_i16"},
    { 52 , " :  (L)"},
    { 53 , " :  (U)satc_i16 ;"},
    { 54 , " :  (L)"},
    { 55 , " :  motor_par..rdwbuf[2]"},
    { 56 , " :  motor_par..rdwbuf[2][3]"},
    { 57 , " :  motor_par..rdwbuf[3]"},
    { 58 , " :  motor_par..rdwbuf[4]"},
    { 59 , " :  motor_par..rdwbuf[4][5]"},
    { 60 , " :  motor_par..rdwbuf[5[[6]"},
    { 61 , " :  motor_par..rdwbuf[6]"},
    { 62 , " :  motor_par..rdwbuf[6]"},
    { 63 , " :  "}

};




const MENUE Deb_menue00[] = {
     {""}, 
     {"*** TOP MENUE ***"},
     {"1:DISPLAY"},       
     {"2:LOG DEBUG"},            
     {"3:OUTPUT DEBUG"},           
     {"4:"},            
     {"5:"},    
     {""}
};
const MENUE Deb_menue01[] = {
    {"*** DISPLAY MENUE ***"},
    {"1:PRAM DISPLAY1"},       
    {"2:PRAM DISPLAY2"},
    {"3:PRAM DISPLAY3"},
    {"4:COMMAND_PARAM"},            
    {"5:MOTER CONTL COMMAND "},           
    {"6:RTC"},            
    {"7:OUTPUT PARAM"},    
    {"8:Moter Ctrl Param1"},
    {"9:Moter Ctrl Param2"},          
    {"r:return"}
};
const MENUE Deb_menue02[] = {
     {"*** LOG DEBUG MENUE ***"},
     {"1:LOG DISPLAY"},   
     {"2:LOG CLEAR"},   
     {""}, 
     {"a:SUBCYCL ON/OFF"},       
     {"b:MAX_SUB_COUNT ON/OFF"},            
     {"c:INTRUPT512 ON/OFF"},  
     {"d:SUBCYCL_8P ON/OFF"},   
     {"e:FRAME_CNT ON/OFF"},   
     {"f:CYCLE_START ON/OFF"},   
     {"g:COM_INT ON/OFF"},
     {"h:KEISOKU_TM ON/OFF"},   
     {"i:MAIN_LOOP ON/OFF"},   
     {"j:BMP_SENS ON/OFF"},   
     {"k:ADC_SENS ON/OFF"},   
     {"l:MAIN_LOOP_CHK ON/OFF"},   
     {"m:CYCLE_CNT ON/OFF"},   
     {"n:COM_RECIVE  ON/OFF"},   
     {"o:SPI READ LOG ON/OFF"},
     {"p:SPI SET LOG ON/OFF"},
     {"q:SPI WR LOG ON/OFF"},   
     {"r:return"},
     {"s:MT PWM LOG ON/OFF"},   
     {"t:MT PWM_DATA LOG ON/OFF"},
     {"u:MT ENC_DATA LOG ON/OFF"},
     {"v:MT CALC LOG ON/OFF"},
     {"w:MT START"}, 
     {"x:PMW CALC DeBUG"},
     {"y:MT CTRL DeBUG"},
    

     {""}
     
};
const MENUE Deb_menue03[] = {
     {"*** MOTER SPEED ***"},
     {"1:162 (5km/h)"},   
     {"2:250 (5km/h)"}, 
     {"3:200 (5km/h)"}, 
     {"4:100 (3.3km/h)"},
     {"5: 50 (1.7km/h)"},
     {"r:return"},
    

     {""}
     
};

const MENUE Deb_menue04[] = {
     {"*** OUTPUT PARAM ***"},
     {"OFFSET = "},   

     {""}
     
};
const MENUE Deb_menue05[] = {
    {"*** OUTPUT PARAM ***"},
    {"w:ON/OFF"},

     {""}
     
};


typedef struct
{
    MENUE *pt;
    uint8 clumn;
} MENUE_NUM_PAGE;

const MENUE_NUM_PAGE MenueList[]={
    Deb_menue00, (uint8)(sizeof(Deb_menue00 )/sizeof(MENUE)),
    Deb_menue01, (uint8)(sizeof(Deb_menue01 )/sizeof(MENUE)),
    Deb_menue02, (uint8)(sizeof(Deb_menue02 )/sizeof(MENUE)),
    Deb_menue03, (uint8)(sizeof(Deb_menue03 )/sizeof(MENUE)),
    Deb_menue04, (uint8)(sizeof(Deb_menue04 )/sizeof(MENUE)),
    Deb_menue05, (uint8)(sizeof(Deb_menue05 )/sizeof(MENUE))
};







uint8 MenueNum=0;
const uint8 MAX_MENBER=(uint8)sizeof(MenueList )/sizeof(MENUE_NUM_PAGE);

#define LOG_SIZE 1000
typedef struct{
    uint32  buf[LOG_SIZE];
    uint16  Wpt;
    uint16  Rpt;
} TIMER_INT_LOG;

TIMER_INT_LOG timerlog;

typedef enum {
    ON,
    OFF,
} FLAG;
FLAG Timer_log_sem;

void Get_sem_timer_log(void);
void Releace_sem_timer_log(void);


#define LOG_BUF_MAX  1000
#define LOG_BUF_CHAR  30

typedef struct{
    uint8 Sec;
    uint8 Min;
    uint8 Hour;
    uint8 DayOfMonth;
    uint8 Month;
    uint16 Year;
    uint16 time;
    char buf[LOG_BUF_CHAR];
} LOG_RECORD;



typedef struct{
    uint16 Wpt;
    uint16 Rpt;
    LOG_RECORD rec[LOG_BUF_MAX];
} LOG_MENBER;

LOG_MENBER Deblog;

uint16 sk_sub_cycl_int_cnt = 0;
uint16 sk_sub_cycl_int_cnt_av = 0;

LOG_FLAG sk_log_flg = 0;
LOG_FLAG2 sk_log_flg2=SK_LOG2_SPI_WR ;
LOG_FLAG3 sk_log_flg3 =0;
LOG_FLAG3 sk_log_flg3_pre ;
LOG_FLAG4 sk_log_flg4 =0;
LOG_FLAG5 sk_log_flg5 =0;


// LOG_FLAG2 sk_log_flg2=SK_LOG2_MAIN_LOOP ;



extern double Timer_count;
void Display_parameter(void);
void Display_Com_parameter(void);
void Display_MotCtrl_Com(void);
void  RTC_Display(void);
void sk_log_Display(void);
void SKLog_sub_cycl_int(void);
void Set_timer_log(double  data);
void skSet_time(uint16 ldata, char *cpt);



uint8  sk_measure_cnt=0;
uint8  sk_CycleStart_Reg;

extern void RTC_1_WriteIntervalMask(uint8 mask) ;
extern uint8   CycleStart_Read(void);
extern void KeisokuTimer_isr_SetPriority(uint8 priority);

void sk_log_out(char8 *string,uint16 data);
void     My_KeisokuTimer_isr_Interrupt(void);
void SKOutput_param_Disp(void);
void sk_log_main(char8 *string,uint16 data);

void Set_f2c(float dt, char *cpt,uint8 keta_u,uint8 keta_l);
void sk_log_int_string(char8 *string);
uint8 Menu00(uint8 ch);
uint8 Menu01(uint8 ch);
uint8 Menu02(uint8 ch);
void sk_adc_debug(uint8 ad, uint8 data );

/*
typedef enum{
    TM_ON,
    TM_OFF
TM_FLG;
*/

TM_FLG sk_1000ms_flg = TM_OFF;
TM_FLG sk_0100ms_flg = TM_OFF;
TM_FLG sk_0010ms_flg = TM_OFF;
TM_FLG sk_0001ms_flg = TM_OFF;

uint16    sk_1000ms_cnt = 9 ;
uint16    sk_0100ms_cnt = 6 ;
uint16    sk_0010ms_cnt = 3 ;
uint16    sk_0001ms_cnt = 0 ;
uint16    sk_log_cnt = 0 ;
uint8       sk_mt_start = 0;


#define TM_0001msec 20
#define TM_0010msec 200
#define TM_0100msec 2000
#define TM_1000msec 20000

extern void sk_int32toChar(char8 *string,int32 data);
extern void sk_int16toChar(char8 *string,int16 data) ;
void Display_parameter2(void);
void Display_parameter3(void);
extern void sk_PutString_int32(char8 *string,int32 data);
extern void sk_PutString_int16(char8 *string,int16 data);
extern void sk_PutString_int8(char8 *string,int8 data);
void sk_PutString_float(char8 *string,float data);
void Set_realT2c(real_T dt, char *cpt,uint8 keta_u,uint8 keta_l);
void MoterCtrl_data_Display(void);

//extern LOG_FLAG3 sk_log_flg1;
//extern LOG_FLAG3 sk_log_flg2;
extern LOG_FLAG3 sk_log_flg3;
//extern LOG_FLAG3 sk_log_flg4;
extern void sk_PutString_uint32(char8 *string,uint32 data);

uint16 ck_mtrlog_cnt=0;
extern int16 sk_ms0_main[4];

uint16 sk_mt_speed;
uint8 Menu03(l_ch);
uint16 sk_input_ofst = 0;
uint16 sk_input_data = 0;

uint8 Menu04(l_ch);
uint8 Menu05(l_ch);
//***************************************************************************
//
//***************************************************************************
TM_FLG Check_0001ms(void)
{
    if( sk_0001ms_flg == TM_ON ){
        sk_0001ms_flg = TM_OFF;
        return( TM_ON );  
    }
    else{
        return( TM_OFF );
    }
}
//***************************************************************************
//
//***************************************************************************
TM_FLG Check_0010ms(void)
{
    if( sk_0010ms_flg == TM_ON ){
        sk_0010ms_flg = TM_OFF;
        return( TM_ON );  
    }
    else{
        return( TM_OFF );
    }
}
//***************************************************************************
//
//***************************************************************************
TM_FLG Check_0100ms(void)
{
    if( sk_0100ms_flg == TM_ON ){
        sk_0100ms_flg = TM_OFF;
        return( TM_ON );  
    }
    else{
        return( TM_OFF );
    }
}
//***************************************************************************
//
//***************************************************************************
TM_FLG Check_1000ms(void)
{
    if( sk_1000ms_flg == TM_ON ){
        sk_1000ms_flg = TM_OFF;
        return( TM_ON );  
    }
    else{
        return( TM_OFF );
    }
}
    
   
//***************************************************************************
//
//  50usec 割込み
//***************************************************************************
My_KeisokuTimer_isr_Interrupt(void)
{
    KeisokuTimer_STATUS;
    if( sk_log_flg & SK_LOG_KEISOKU_TM  ){
        sk_log_int("KeisokuTimer_INT", 0);        
    }
    
    sk_sub_cycl_int_cnt++;
    
    
    sk_1000ms_cnt ++;
    sk_0100ms_cnt ++;
    sk_0010ms_cnt ++;
    sk_0001ms_cnt ++;
    
    
    if( sk_0001ms_cnt >= TM_0001msec ){
        sk_0001ms_flg = TM_ON;
        sk_0001ms_cnt = 0;
    }

    if( sk_0010ms_cnt >= TM_0010msec ){
        sk_0010ms_flg = TM_ON;
        sk_0010ms_cnt = 0;
    }

    if( sk_0100ms_cnt >= TM_0100msec ){
        sk_0100ms_flg = TM_ON;
        sk_0100ms_cnt = 0;
    }
    
    if( sk_1000ms_cnt >= TM_1000msec ){
        sk_1000ms_flg = TM_ON;
        sk_1000ms_cnt = 0;
    }

    
}

//***************************************************************************
//
//
//***************************************************************************

void debug_init(void)
{
    KeisokuTimer_Start();

    KeisokuTimer_isr_SetPriority(6);

    KeisokuTimer_isr_StartEx(KeisokuTimer_isr_Interrupt);
}

//***************************************************************************
//
//
//***************************************************************************
void debug_menue_init(void)
{
    timerlog.Rpt=0;
    timerlog.Wpt=0;
    Timer_log_sem=OFF;
}
//***************************************************************************
//
//
//***************************************************************************
void Set_timer_log(double  data)
{
    Get_sem_timer_log();
    timerlog.buf[timerlog.Wpt]=data;
    
    timerlog.Wpt++;
    if(timerlog.Wpt > LOG_SIZE){
        timerlog.Wpt=0;
    }
    
    if(timerlog.Wpt==timerlog.Rpt){
        timerlog.Rpt++;
        if(timerlog.Rpt > LOG_SIZE){
            timerlog.Rpt=0;
        }   
    }
    
    Releace_sem_timer_log();
}
//***************************************************************************
//
//
//***************************************************************************

//***************************************************************************
//
//
//***************************************************************************
void Get_sem_timer_log(void)
{
    for(;;){
        if(Timer_log_sem==OFF)
            break;
    }
    Timer_log_sem=ON;
}

void Releace_sem_timer_log(void)
{
    Timer_log_sem=OFF;
}
//***************************************************************************
//
//
//***************************************************************************
void debug_main(void)
{
    uint8 dt;
    
    dt = CycleStart_Read();
    if( sk_CycleStart_Reg != dt ){
        sk_CycleStart_Reg = dt;
        if( sk_log_flg & SK_LOG_CYCLE_START  ){
            // sk_log_int("CycleStart_Reg = ", (uint16 )dt);        
        }
    }
}
//***************************************************************************
//
//
//***************************************************************************
void debug_menue(void)
{
    uint8   l_ch;
    uint8   l_i;
    uint8   l_column; 
    MENUE   *menu_pt;
    uint8   rtn;
    
    l_ch  = SK_GetChar_uart();


        
    if(l_ch > 0){
        sk_PutString03("Get CHAR = ", l_ch, CRLF_ON,16);
        
        switch(MenueNum){
        case 0:
            rtn = Menu00(l_ch);
            break;
        case 1:
            rtn = Menu01(l_ch);
            break;
        case 2:
            rtn = Menu02(l_ch);
            break;
        case 3:
            rtn = Menu03(l_ch);
            break;        
        case 4:
            rtn = Menu04(l_ch);
            break;
        case 5:
            rtn = Menu05(l_ch);
            break;
        default:
            MenueNum = 0;
            break;
        }    
            
        if( rtn == 0 ){
            
            // Menuを表示する
     
            menu_pt=MenueList[MenueNum].pt;
            l_column = MenueList[MenueNum].clumn;
        
        
            // sk_PutString03("MenueNum = ", MenueNum, CRLF_ON,16);
            // sk_PutString03("l_column = ", l_column, CRLF_ON,16);
        
            
            for(l_i=0;l_i< l_column;l_i++){
                sk_PutString01(menu_pt->name,CRLF_NONE);
                menu_pt ++;
                sk_PutString01(menu_pt->name,CRLF_ONLY);
            }
        
            sk_PutString01(menu_pt->name,CRLF_ONLY);
            
            
            switch(MenueNum){
            
            case 2:

                sk_PutString03("sk_log_flg1 = ", sk_log_flg , CRLF_ON,16 );
                sk_PutString03("sk_log_flg2 = ", sk_log_flg2 , CRLF_ON,16 );
                sk_PutString03("sk_log_flg3 = ", sk_log_flg3 , CRLF_ON,16 );
                sk_PutString03("sk_log_flg4 = ", sk_log_flg4 , CRLF_ON,16 );
                sk_PutString03("sk_log_flg5 = ", sk_log_flg5 , CRLF_ON,16 );
                


                break;
            case 4:
                sk_PutString03("OFFSET = ", sk_input_ofst , CRLF_ON,10 );
                break;
                
            case 5:
                sk_PutString03("OFFSET = ", sk_input_ofst , CRLF_ON,10 );
                sk_PutString03("DATA = ", sk_input_data , CRLF_ON,10 );
            default:
                    
                break;
            }    
            
        }
    }
}
uint8 Menu00(uint8 ch)
{
        uint8 rtn = 0;
        char buf[30];
        int16 dt;
        real_T dt_rT;
        
        switch( ch ){
        case '1':
            // DISPLAY Menue         
            MenueNum =1 ;
            break;
        case '2':
            // LOG DEBUG Menue
            MenueNum = 2;
            break;
        case '3':
            MenueNum = 4;
            sk_input_ofst = 0;
            sk_input_data = 0;

            break;
        case '4':
            
            Set_realT2c(18.75, buf,3,6);
            sk_PutString01(buf,CRLF_ON);
            
            Set_realT2c(0.00075, buf,3,6);
            
            sk_PutString01(buf,CRLF_ON);
            
            Set_realT2c(-1.0054, buf,3,6);
            
            sk_PutString01(buf,CRLF_ON);
            
            //sk_int32toChar(buf,-250);
            Set_f2c(0.00314, buf,3,6);
            sk_PutString01(buf,CRLF_ON);
            Set_f2c(-0.00314, buf,3,6);
            sk_PutString01(buf,CRLF_ON);
            Set_f2c(0.0000314, buf,3,6);
            sk_PutString01(buf,CRLF_ON);

        default:
            break;
        }
        
        return rtn;
}
uint8 Menu01(uint8 ch)
{
    uint8 rtn = 0;

    switch(ch){
        case '1':
            Display_parameter();
            break;
        case '2':
            Display_parameter2();
            break;
        case '3':
            Display_parameter3();
            break;
        case '4':
            Display_Com_parameter();
            break;
        case '5':
            Display_MotCtrl_Com();
            break;
        case '6':
            RTC_Display();
            break;
        case '7':
            SKOutput_param_Disp();
            break;  
        case '8':
            MoterCtrl_data_Display();
            break;  
        case '9':
            MoterCtrl_data2_Display();
            rtn = 0;
            break;
        case 'r':
        case 'R':
            MenueNum = 0;
        default:  
            rtn = 0;
            break;
    }
    return rtn;
    
}
uint8 Menu02(uint8 ch)
{
    uint8 rtn = 1;

    switch(ch){
        case '1':
            sk_log_Display();
            break;
        case '2':
            Deblog.Wpt=0;
            Deblog.Rpt=0;
            
            break;
            
        case 'a':

            if( sk_log_flg & SK_LOG_SUBCYCL ){
                sk_log_flg &= ~SK_LOG_SUBCYCL;
                sk_PutString01("LOG_SUBCYCL OFF", CRLF_ON );    
            }
            else{
                sk_log_flg |= SK_LOG_SUBCYCL;
                sk_PutString01("LOG_SUBCYCL ON", CRLF_ON );    
            }
                  
            break;
        case 'b':
            if( sk_log_flg & SK_LOG_MAX_SUB_COUNT ){
                sk_log_flg &= ~SK_LOG_MAX_SUB_COUNT;
                sk_PutString01("MAX_SUB_COUNT OFF", CRLF_ON );  
            }
            else{
                sk_log_flg |= SK_LOG_MAX_SUB_COUNT;
                sk_PutString01("MAX_SUB_COUNT ON", CRLF_ON );  
            }
            
            break;
        case 'c':
             if( sk_log_flg & SK_LOG_INTRUPT512 ){
                sk_log_flg &= ~SK_LOG_INTRUPT512;
                sk_PutString01("INTRUPT512 OFF", CRLF_ON );  
            }
            else{
                sk_log_flg |= SK_LOG_INTRUPT512;
                sk_PutString01("INTRUPT512 ON", CRLF_ON );  
            }
            
            break;
        case 'd':
            if( sk_log_flg & SK_LOG_SUBCYCL_8P ){
                sk_log_flg &= ~SK_LOG_SUBCYCL_8P;
                sk_PutString01("SUBCYCL_8P OFF", CRLF_ON );  
            }
            else{
                sk_log_flg |= SK_LOG_SUBCYCL_8P;
                sk_PutString01("SUBCYCL_8P ON", CRLF_ON );  
            }

            break;
        case 'e':
            if( sk_log_flg & SK_LOG_FRAME_CNT  ){
                sk_log_flg &= ~SK_LOG_FRAME_CNT ;
                sk_PutString01("FRAME_CNT OFF", CRLF_ON );  
            }
            else{
                sk_log_flg |= SK_LOG_FRAME_CNT ;
                sk_PutString01("FRAME_CNT ON", CRLF_ON );  
            }
            break;
        case 'f':
            if( sk_log_flg & SK_LOG_CYCLE_START  ){
                sk_log_flg &= ~SK_LOG_CYCLE_START ;
                sk_PutString01("CYCLE_START OFF", CRLF_ON );  
            }
            else{
                sk_log_flg |= SK_LOG_CYCLE_START ;
                sk_PutString01("CYCLE_START ON", CRLF_ON );  
            }
            break;
        case 'g':
            if( sk_log_flg & SK_LOG_COM_INT  ){
                sk_log_flg &= ~SK_LOG_COM_INT ;
                sk_PutString01("COM_INT OFF", CRLF_ON );  
            }
            else{
                sk_log_flg |= SK_LOG_COM_INT ;
                sk_PutString01("COM_INT ON", CRLF_ON );  
            }
            break;
        case 'h':
            if( sk_log_flg & SK_LOG_KEISOKU_TM  ){
                sk_log_flg &= ~SK_LOG_KEISOKU_TM ;
                sk_PutString01("KEISOKU_TM OFF", CRLF_ON );  
            }
            else{
                sk_log_flg |= SK_LOG_KEISOKU_TM ;
                sk_PutString01("KEISOKU_TM ON", CRLF_ON );  
            }
            break;    
        case 'i':
            if( sk_log_flg2 & SK_LOG2_MAIN_LOOP  ){
                sk_log_flg2 &= ~SK_LOG2_MAIN_LOOP ;
                sk_PutString01("MAIN_LOOP OFF", CRLF_ON );  
            }
            else{
                sk_log_flg2 |= SK_LOG2_MAIN_LOOP ;
                sk_PutString01("MAIN_LOOP ON", CRLF_ON );  
            }
            break;   
        case 'j':
            if( sk_log_flg2 & SK_LOG2_BMP_SENS ){
                sk_log_flg2 &= ~SK_LOG2_BMP_SENS ;
                sk_PutString01("BMP_SENS OFF", CRLF_ON );  
            }
            else{
                sk_log_flg2 |= SK_LOG2_BMP_SENS ;
                sk_PutString01("BMP_SENS ON", CRLF_ON );  
            }
            break; 
        case 'k':
            
            if(sk_log_flg3_pre == 0){
                sk_log_flg3 |= SK_LOG2_DIST0 ;
                sk_log_flg3_pre = SK_LOG2_DIST0 ;
            }
            else{
                if( sk_log_flg3 != 0 ){
                    //sk_log_flg3_pre = sk_log_flg3;
                    sk_log_flg3 = 0;
                sk_PutString01("ADC OFF", CRLF_ON);
                    
                }
                else{
                    if( sk_log_flg3_pre & SK_LOG2_DIST7){
                        sk_log_flg3_pre = SK_LOG2_DIST0;
                        sk_log_flg3 = sk_log_flg3_pre;
                    }
                    else{
                        sk_log_flg3_pre = sk_log_flg3_pre << 1;
                        sk_log_flg3 = sk_log_flg3_pre;
                    }
                    
                }
            }

            if (sk_log_flg3 & SK_LOG2_DIST0)             
                sk_PutString03("ADC DIST0 ON = ", sk_log_flg3, CRLF_ON,16 );
            if (sk_log_flg3 & SK_LOG2_DIST1)             
                sk_PutString03("ADC DIST1 ON = ", sk_log_flg3, CRLF_ON,16 );
            if (sk_log_flg3 & SK_LOG2_DIST2)             
                sk_PutString03("ADC DIST2 ON = ", sk_log_flg3, CRLF_ON,16 );
            if (sk_log_flg3 & SK_LOG2_DIST3)             
                sk_PutString03("ADC DIST3 ON = ", sk_log_flg3, CRLF_ON,16 );
            if (sk_log_flg3 & SK_LOG2_DIST4)             
                sk_PutString03("ADC DIST4 ON = ", sk_log_flg3, CRLF_ON,16 );
            if (sk_log_flg3 & SK_LOG2_DIST5)             
                sk_PutString03("ADC DIST5 ON = ", sk_log_flg3, CRLF_ON,16 );
            if (sk_log_flg3 & SK_LOG2_DIST6)             
                sk_PutString03("ADC DIST6 ON = ", sk_log_flg3, CRLF_ON,16 );
            if (sk_log_flg3 & SK_LOG2_DIST7)             
                sk_PutString03("ADC DIST7 ON = ", sk_log_flg3, CRLF_ON,16 );

            
            break;        
        case 'l':  // L
            if( sk_log_flg2 & SK_LOG2_LOOP_CHK ){
                sk_log_flg2 &= ~SK_LOG2_LOOP_CHK ;
                sk_PutString01("LOOP_CHK OFF", CRLF_ON);
            }
            else{
                sk_log_flg2 |= SK_LOG2_LOOP_CHK ;
                sk_PutString01("LOOP_CHK ON", CRLF_ON);
            }        
                
            break;             
        case 'm':  // L
            if( sk_log_flg2 & SK_LOG2_CYCLE_CNT ){
                sk_log_flg2 &= ~SK_LOG2_CYCLE_CNT ;
                sk_PutString01("CYCLE_CNT OFF", CRLF_ON);
            }
            else{
                sk_log_flg2 |= SK_LOG2_CYCLE_CNT ;
                sk_PutString01("CYCLE_CNT ON", CRLF_ON);
            }        
                
            break;             
        case 'n':  // L
            if( sk_log_flg2 & SK_LOG2_COM_RECIVE  ){
                sk_log_flg2 &= ~SK_LOG2_COM_RECIVE  ;
                sk_PutString01("COM_RECIVE  OFF", CRLF_ON);
            }
            else{
                sk_log_flg2 |= SK_LOG2_COM_RECIVE  ;
                sk_PutString01("COM_RECIVE  ON", CRLF_ON);
            }        
                
            break;       
         case 'o':  // L
            if( sk_log_flg2 & SK_LOG2_SPI_READ  ){
                sk_log_flg2 &= ~SK_LOG2_SPI_READ  ;
                sk_PutString01("SPI READ LOG OFF", CRLF_ON);
            }
            else{
                sk_log_flg2 |= SK_LOG2_SPI_READ  ;
                sk_PutString01("SPI READ LOG ON", CRLF_ON);
            }        
                
            break;    
        case 'p':  
            if( sk_log_flg2 & SK_LOG2_SPI_SET  ){
                sk_log_flg2 &= ~SK_LOG2_SPI_SET  ;
                sk_PutString01("SPI SET LOG OFF", CRLF_ON);
            }
            else{
                sk_log_flg2 |= SK_LOG2_SPI_SET  ;
                sk_PutString01("SPI SET LOG ON", CRLF_ON);
            }        
                
            break;  
        case 'q':  
            if( sk_log_flg2 & SK_LOG2_SPI_WR  ){
                sk_log_flg2 &= ~SK_LOG2_SPI_WR  ;
                sk_PutString01("SPI WR LOG OFF", CRLF_ON);
            }
            else{
                sk_log_flg2 |= SK_LOG2_SPI_WR  ;
                sk_PutString01("SPI WR LOG ON", CRLF_ON);
            }        

            break;  
        case 's':  
            if( sk_log_flg4 & SK_LOG4_MT_PWM  ){
                sk_log_flg4 &= ~SK_LOG4_MT_PWM  ;
                sk_PutString01("MT PWM LOG OFF", CRLF_ON);
            }
            else{
                sk_log_flg4 |= SK_LOG4_MT_PWM  ;
                sk_PutString01("MT PWM LOG ON", CRLF_ON);
            }        


            break;  
        case 't':  
            if( sk_log_flg4 & SK_LOG4_PWM_DATA  ){
                sk_log_flg4 &= ~SK_LOG4_PWM_DATA  ;
                sk_PutString01("MT PWM DATA LOG OFF", CRLF_ON);
            }
            else{
                sk_log_flg4 |= SK_LOG4_PWM_DATA  ;
                sk_PutString01("MT PWM DATA LOG ON", CRLF_ON);
            }        


            break;  
        case 'u':  
            if( sk_log_flg4 & SK_LOG4_ENC_DATA  ){
                sk_log_flg4 &= ~SK_LOG4_ENC_DATA  ;
                sk_PutString01("MT ENC DATA LOG OFF", CRLF_ON);
            }
            else{
                sk_log_flg4 |= SK_LOG4_ENC_DATA  ;
                sk_PutString01("MT ENC DATA LOG ON", CRLF_ON);
            }        


            break; 
        case 'v':  
            if( sk_log_flg4 & SK_LOG4_SUB_CALC1   ){
                sk_log_flg4 &= ~SK_LOG4_SUB_CALC1   ;
                sk_PutString01("MT CALC LOG OFF", CRLF_ON);
            }
            else{
                sk_log_flg4 |= SK_LOG4_SUB_CALC1   ;
                sk_PutString03("MT CALC LOG ON = ",sk_log_flg4, CRLF_ON,16);
                sk_log_cnt=0;
            }        
            break; 
        case 'w':  
            if( sk_log_flg4 & SK_LOG4_MOT_START   ){
                sk_log_flg4 &= ~SK_LOG4_MOT_START   ;
                sk_PutString01("MT STOP", CRLF_ON);
            }
            else{
                MenueNum = 3;
                rtn = 0;
            }
            break; 
        case 'x':  
            if( sk_log_flg5 & SK_LOG5_PWM_CALUC   ){
                sk_log_flg5 &= ~SK_LOG5_PWM_CALUC   ;
                sk_PutString01("PWM_CALUC OFF", CRLF_ON);
            }
            else{
                sk_log_flg5 |= SK_LOG5_PWM_CALUC  ;
                
                sk_log_cnt=0;
            }        
            break; 
        case 'y':  
            if( sk_log_flg5 & SK_LOG5_MT_CTRL   ){
                sk_log_flg5 &= ~SK_LOG5_MT_CTRL   ;
                sk_PutString01("MT CTRLC OFF", CRLF_ON);
            }
            else{
                sk_log_flg5 |= SK_LOG5_MT_CTRL  ;
                sk_PutString03("MT CTRL ON = ",sk_log_flg4, CRLF_ON,16);
                ck_mtrlog_cnt = 0;
            }        
            break; 
        case 'z':  
            if( sk_log_flg5 & SK_LOG4_ENC_DATA   ){
                sk_log_flg5 &= ~SK_LOG4_ENC_DATA   ;
                sk_PutString01("ENC CNT OFF", CRLF_ON);
                sk_PutString03("sk_ms0_main[0] = ",sk_ms0_main[0], CRLF_ON,10);
                sk_PutString03("sk_ms0_main[1] = ",sk_ms0_main[1], CRLF_ON,10);
                sk_PutString03("sk_ms0_main[2] = ",sk_ms0_main[2], CRLF_ON,10);
                sk_PutString03("sk_ms0_main[3] = ",sk_ms0_main[3], CRLF_ON,10);
            }
            else{
                sk_log_flg5 |= SK_LOG4_ENC_DATA  ;
                sk_PutString03("ENC CNT ON = ",sk_log_flg4, CRLF_ON,16);
                sk_ms0_main[0] = 0;
                sk_ms0_main[1] = 0;
                sk_ms0_main[2] = 0;
                sk_ms0_main[3] = 0;
            }        
            break; 

        case 'r':
        case 'R':
            MenueNum = 0;
        default:  
            rtn = 0;
            break;
    }
    return rtn;
}

uint8 Menu03(l_ch)
{
    uint8 rtn = 0;
    
    MenueNum = 2;
    switch(l_ch){
        case '1':
            sk_mt_speed=162;
            break;
        case '2':
            sk_mt_speed=250;
            break;
        case '3':
            sk_mt_speed=200;
            break;
        case '4':
            sk_mt_speed=100;
            break;
        case '5':
            sk_mt_speed= 50;
            break;
        case '6':
            
        default:  
            sk_mt_speed=162;
            break;
    }
    
    if( sk_log_flg4 & SK_LOG4_MOT_START   ){
        sk_log_flg4 &= ~SK_LOG4_MOT_START   ;
        sk_PutString01("MT STOP", CRLF_ON);
    }
    else{
        sk_log_flg4 |= SK_LOG4_MOT_START  ;
        sk_PutString03("MT START = ",sk_mt_speed, CRLF_ON,10);
        sk_mt_start = 1;
    }  
            
            
    
    return rtn;
}

uint8 Menu04(l_ch)
{
    uint8 rtn = 0;
    
    switch(l_ch){
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            sk_input_ofst *= 10;
            sk_input_ofst += (l_ch - '0');
            break;
        case 0x0d:
            MenueNum = 5;
            break;
        case 'r':
        case 'R':
            MenueNum = 0;
            break;
        
        default:  
           
            break;
    }
    
    
    return rtn;
}
uint8 Menu05(l_ch)
{
    uint8 rtn = 0;
    
    switch(l_ch){
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
  
            sk_input_data *= 10;
            sk_input_data += (l_ch - '0');
            break;
        case 0x0d:
            //MenueNum = 0;
            break;
        case 'w' :
            
            if( sk_log_flg5 & SK_LOG5_OUTPUT_P   ){
                sk_log_flg5 &= ~SK_LOG5_OUTPUT_P   ;
                sk_PutString01("OUTPUT_OFF", CRLF_ON);
            }
            else{
                sk_log_flg5 |= SK_LOG5_OUTPUT_P  ;
                sk_PutString03("OUTPUT_ON= ",sk_log_flg4, CRLF_ON,16);
                ck_mtrlog_cnt = 0;
            }        
            break;
        case 'r':
        case 'R':
            MenueNum = 0;
            break;
        
        default:  
           
            break;
    }
    
    
    return rtn;
}

//***************************************************************************
//
//
//***************************************************************************
void SKOutput_param_Disp(void)
{
    uint8 i;
    uint8 dt;
    
    for( i=0; i<145; i++ ){
        if( i < 59 ){
            dt = outbuff1[i];
        }
        else if( i < 115 ){
            dt = outbuff2[i-59];
        }
        else{
            dt = outbuff3[i-115];
        }
     
        sk_PutString03(" output[",i,CRLF_NONE,10);
        sk_PutString03("] = ",dt,CRLF_NONE,10);
        sk_PutString03(" ( 0x",dt,CRLF_NONE,16);
        
        switch(i){
        case 135:
            
            sk_PutString01(" )  DIST0(front）",CRLF_ON);

            break;
        case 136:
            sk_PutString01(" )  DIST1（Right)",CRLF_ON);
            break;
        case 137:
            sk_PutString01(" )  DIST2（Rear))",CRLF_ON);

            break;
        case 138:
            sk_PutString01(" )  DIST3（Left))",CRLF_ON);

            break;
            
        case 139:
            sk_PutString01(" )  DIST_STEP)",CRLF_ON);
            break;
                        
        case 143:
            sk_PutString01(" )  BMP_SW)",CRLF_ON);
            break;
        default:
            sk_PutString01(" )",CRLF_ON);
            break;
        }
        
    }
    
    
    for( i=0; i<OUT2TAG_LENGTH; i++ ){
        dt = output2_tag[i];
        sk_PutString03(" output2_tag[",i,CRLF_NONE,10);
        sk_PutString03("] = ",dt,CRLF_NONE,10);
        sk_PutString03(" ( 0x",dt,CRLF_NONE,16);
        sk_PutString01(" )",CRLF_ON);
    }    
   
}


//***************************************************************************
//
//
//***************************************************************************
void Display_parameter(void)
{
    sk_PutString01("",CRLF_ON);


    sk_PutString01("***** uint16 *****",CRLF_ON);
    sk_PutString04("dist_front = ",dist_front ,CRLF_ON );
    sk_PutString04("dist_rear = ",dist_rear ,CRLF_ON );
    sk_PutString04("dist_fr = ",dist_fr ,CRLF_ON );
    sk_PutString04("dist_fl = ",dist_fl ,CRLF_ON );
    sk_PutString04("dist_st = ",dist_st ,CRLF_ON );
    sk_PutString04("v_bat_16 = ",v_bat_16 ,CRLF_ON );
    sk_PutString04("pvm1_16 = ",pvm1_16 ,CRLF_ON );
    sk_PutString04("pvm2_16 = ",pvm2_16 ,CRLF_ON );
    sk_PutString04("max_spd_chg = ",max_spd_chg ,CRLF_ON );
    sk_PutString04("max_rpm = ",max_rpm ,CRLF_ON );
    sk_PutString04("gear_motor = ",gear_motor ,CRLF_ON );
    sk_PutString04("samp_rate = ",samp_rate ,CRLF_ON );
    sk_PutString04("enc_count = ",enc_count ,CRLF_ON );
    sk_PutString04("enc_malti = ",enc_malti ,CRLF_ON );
    sk_PutString04("dim_wheel_i16 = ",dim_wheel_i16 ,CRLF_ON );
    sk_PutString04("dist_wheel_i16 = ",dist_wheel_i16 ,CRLF_ON );
    sk_PutString04("toruque_const_i16 = ",toruque_const_i16 ,CRLF_ON );
    sk_PutString04("speed_const_i16 = ",speed_const_i16 ,CRLF_ON );
    sk_PutString04("spd_torq_grad_i16 = ",spd_torq_grad_i16 ,CRLF_ON );
    sk_PutString04("acc_limit_f_i16 = ",acc_limit_f_i16 ,CRLF_ON );
    sk_PutString04("acc_limit_r_i16 = ",acc_limit_r_i16 ,CRLF_ON );
    sk_PutString04("acc_limit_s_i16 = ",acc_limit_s_i16 ,CRLF_ON );
    sk_PutString04("safty_const_i16 = ",safty_const_i16 ,CRLF_ON );
    sk_PutString04("kvp_i16 = ",kvp_i16 ,CRLF_ON );
    sk_PutString04("kcp_i16 = ",kcp_i16 ,CRLF_ON );
    sk_PutString04("kvi_i16 = ",kvi_i16 ,CRLF_ON );
    sk_PutString04("kci_i16 = ",kci_i16 ,CRLF_ON );
    sk_PutString04("kdl_i16 = ",kdl_i16 ,CRLF_ON );
    sk_PutString04("kdr_i16 = ",kdr_i16 ,CRLF_ON );
    sk_PutString04("satv_i16 = ",satv_i16 ,CRLF_ON );
    sk_PutString04("satc_i16 = ",satc_i16 ,CRLF_ON );

    sk_PutString01("",CRLF_ON);
    sk_PutString01("***** uint8 *****",CRLF_ON);
    sk_PutString04("adin = ",adin ,CRLF_ON );
    sk_PutString04("blk0 = ",blk0 ,CRLF_ON );
    sk_PutString04("blk1 = ",blk1 ,CRLF_ON );
    sk_PutString04("blk2 = ",blk2 ,CRLF_ON );
    sk_PutString04("blk3 = ",blk3 ,CRLF_ON );
    sk_PutString04("bwp_sw = ",bwp_sw ,CRLF_ON );
    sk_PutString04("calc_ratio = ",calc_ratio ,CRLF_ON );
    sk_PutString04("com_status = ",com_status ,CRLF_ON );
    sk_PutString04("cw0 = ",cw0 ,CRLF_ON );
    sk_PutString04("cw1 = ",cw1 ,CRLF_ON );
    sk_PutString04("cw2 = ",cw2 ,CRLF_ON );
    sk_PutString04("cw3 = ",cw3 ,CRLF_ON );
    sk_PutString04("cycle_count = ",cycle_count ,CRLF_ON );
    sk_PutString04("cycle_count_buf = ",cycle_count_buf ,CRLF_ON );
    sk_PutString04("cycle_count_pre = ",cycle_count_pre ,CRLF_ON );
    sk_PutString04("diag_count = ",diag_count ,CRLF_ON );
    sk_PutString04("die_status = ",die_status ,CRLF_ON );
    sk_PutString04("direct = ",direct ,CRLF_ON );
    sk_PutString04("drive_wheels = ",drive_wheels ,CRLF_ON );
    sk_PutString04("encd0 = ",encd0 ,CRLF_ON );
    sk_PutString04("encd1 = ",encd1 ,CRLF_ON );
    sk_PutString04("encd2 = ",encd2 ,CRLF_ON );
    sk_PutString04("encd3 = ",encd3 ,CRLF_ON );
    sk_PutString04("err_wdt_atm_spi = ",err_wdt_atm_spi ,CRLF_ON );
    sk_PutString04("err_wdt_axis9_spi = ",err_wdt_axis9_spi ,CRLF_ON );
    sk_PutString04("err_wdt_body_oh[0] = ",err_wdt_body_oh[0] ,CRLF_ON );
    sk_PutString04("err_wdt_body_oh[1] = ",err_wdt_body_oh[1] ,CRLF_ON );
    sk_PutString04("err_wdt_body_oh[2] = ",err_wdt_body_oh[2] ,CRLF_ON );
    sk_PutString04("err_wdt_cpuv[0] = ",err_wdt_cpuv[0] ,CRLF_ON );
    sk_PutString04("err_wdt_cpuv[1] = ",err_wdt_cpuv[1] ,CRLF_ON );
    sk_PutString04("err_wdt_cpuv[2] = ",err_wdt_cpuv[2] ,CRLF_ON );
    sk_PutString04("err_wdt_cpuv[3] = ",err_wdt_cpuv[3] ,CRLF_ON );
    sk_PutString04("err_wdt_die_otp = ",err_wdt_die_otp ,CRLF_ON );
    sk_PutString04("err_wdt_drv_dis = ",err_wdt_drv_dis ,CRLF_ON );
    sk_PutString04("err_wdt_drv_spi[0] = ",err_wdt_drv_spi[0] ,CRLF_ON );
    sk_PutString04("err_wdt_drv_spi[1] = ",err_wdt_drv_spi[1] ,CRLF_ON );
    sk_PutString04("err_wdt_drv_spi[2] = ",err_wdt_drv_spi[2] ,CRLF_ON );
    sk_PutString04("err_wdt_drv_spi[3] = ",err_wdt_drv_spi[3] ,CRLF_ON );

    sk_PutString04("err_wdt_em_stop_out = ",err_wdt_em_stop_out ,CRLF_ON );

    sk_PutString04("err_wdt_gdf[0] = ",err_wdt_gdf[0] ,CRLF_ON );
    sk_PutString04("err_wdt_gdf[1] = ",err_wdt_gdf[1] ,CRLF_ON );
    sk_PutString04("err_wdt_gdf[2] = ",err_wdt_gdf[2] ,CRLF_ON );
    sk_PutString04("err_wdt_gdf[3] = ",err_wdt_gdf[3] ,CRLF_ON );

    sk_PutString04("err_wdt_mot_fault = ",err_wdt_mot_fault ,CRLF_ON );

    sk_PutString04("err_wdt_otsd[0] = ",err_wdt_otsd[0] ,CRLF_ON );
    sk_PutString04("err_wdt_otsd[1] = ",err_wdt_otsd[1] ,CRLF_ON );
    sk_PutString04("err_wdt_otsd[2] = ",err_wdt_otsd[2] ,CRLF_ON );
    sk_PutString04("err_wdt_otsd[3] = ",err_wdt_otsd[3] ,CRLF_ON );
    sk_PutString04("err_wdt_otw[0] = ",err_wdt_otw[0] ,CRLF_ON );
    sk_PutString04("err_wdt_otw[1] = ",err_wdt_otw[1] ,CRLF_ON );
    sk_PutString04("err_wdt_otw[2] = ",err_wdt_otw[2] ,CRLF_ON );
    sk_PutString04("err_wdt_otw[3] = ",err_wdt_otw[3] ,CRLF_ON );
    sk_PutString04("err_wdt_ov_spd[0] = ",err_wdt_ov_spd[0] ,CRLF_ON );
    sk_PutString04("err_wdt_ov_spd[1] = ",err_wdt_ov_spd[1] ,CRLF_ON );
    sk_PutString04("err_wdt_ov_spd[2] = ",err_wdt_ov_spd[2] ,CRLF_ON );
    sk_PutString04("err_wdt_ov_spd[3] = ",err_wdt_ov_spd[3] ,CRLF_ON );

    sk_PutString04("err_wdt_pvm_low[0] = ",err_wdt_pvm_low[0] ,CRLF_ON );
    sk_PutString04("err_wdt_pvm_low[1] = ",err_wdt_pvm_low[1] ,CRLF_ON );
    sk_PutString04("err_wdt_pvm_ocpat[0] = ",err_wdt_pvm_ocpat[0] ,CRLF_ON );
    sk_PutString04("err_wdt_pvm_ocpat[1] = ",err_wdt_pvm_ocpat[1] ,CRLF_ON );

    sk_PutString04("err_wdt_pvm_ocur[0] = ",err_wdt_pvm_ocur[0] ,CRLF_ON );
    sk_PutString04("err_wdt_pvm_ocur[1] = ",err_wdt_pvm_ocur[1] ,CRLF_ON );

    sk_PutString04("err_wdt_sa_ocp[0] = ",err_wdt_sa_ocp[0] ,CRLF_ON );
    sk_PutString04("err_wdt_sa_ocp[1] = ",err_wdt_sa_ocp[1] ,CRLF_ON );
    sk_PutString04("err_wdt_sa_ocp[2] = ",err_wdt_sa_ocp[2] ,CRLF_ON );
    sk_PutString04("err_wdt_sa_ocp[3] = ",err_wdt_sa_ocp[3] ,CRLF_ON );
    sk_PutString04("err_wdt_sa_ocpat[0] = ",err_wdt_sa_ocpat[0] ,CRLF_ON );
    sk_PutString04("err_wdt_sa_ocpat[1] = ",err_wdt_sa_ocpat[1] ,CRLF_ON );
    sk_PutString04("err_wdt_sa_ocpat[2] = ",err_wdt_sa_ocpat[2] ,CRLF_ON );
    sk_PutString04("err_wdt_sa_ocpat[3] = ",err_wdt_sa_ocpat[3] ,CRLF_ON );

    sk_PutString04("err_wdt_sw_dt = ",err_wdt_sw_dt ,CRLF_ON );
    sk_PutString04("err_wdt_usb_if = ",err_wdt_usb_if ,CRLF_ON );

    sk_PutString04("err_wdt_uvlo[0] = ",err_wdt_uvlo[0] ,CRLF_ON );
    sk_PutString04("err_wdt_uvlo[1] = ",err_wdt_uvlo[1] ,CRLF_ON );
    sk_PutString04("err_wdt_uvlo[2] = ",err_wdt_uvlo[2] ,CRLF_ON );
    sk_PutString04("err_wdt_uvlo[3] = ",err_wdt_uvlo[3] ,CRLF_ON );

    sk_PutString04("err_wdt_vbat_low = ",err_wdt_vbat_low ,CRLF_ON );

    sk_PutString04("err_wdt_vds_ocp[0] = ",err_wdt_vds_ocp[0] ,CRLF_ON );
    sk_PutString04("err_wdt_vds_ocp[1] = ",err_wdt_vds_ocp[1] ,CRLF_ON );
    sk_PutString04("err_wdt_vds_ocp[2] = ",err_wdt_vds_ocp[2] ,CRLF_ON );
    sk_PutString04("err_wdt_vds_ocp[3] = ",err_wdt_vds_ocp[3] ,CRLF_ON );

    sk_PutString04("loop_max = ",loop_max ,CRLF_ON );
    sk_PutString04("measure_sensor = ",measure_sensor ,CRLF_ON );
    sk_PutString04("mes_adc_val = ",mes_adc_val ,CRLF_ON );
    sk_PutString04("pwm_control = ",pwm_control ,CRLF_ON );
    sk_PutString04("pwm_period = ",pwm_period ,CRLF_ON );
    sk_PutString04("pwm_width0 = ",pwm_width0 ,CRLF_ON );
    sk_PutString04("pwm_width1 = ",pwm_width1 ,CRLF_ON );
    sk_PutString04("pwm_width2 = ",pwm_width2 ,CRLF_ON );
    sk_PutString04("pwm_width3 = ",pwm_width3 ,CRLF_ON );
    sk_PutString04("sign0 = ",sign0 ,CRLF_ON );
    sk_PutString04("sign1 = ",sign1 ,CRLF_ON );
    sk_PutString04("sign2 = ",sign2 ,CRLF_ON );
    sk_PutString04("sign3 = ",sign3 ,CRLF_ON );
    sk_PutString04("spi_sel = ",spi_sel ,CRLF_ON );
    sk_PutString04("tmp[0] = ",tmp[0] ,CRLF_ON );
    sk_PutString04("tmp[1] = ",tmp[1] ,CRLF_ON );
    sk_PutString04("tmp[2] = ",tmp[2] ,CRLF_ON );
    sk_PutString04("tmp[3] = ",tmp[3] ,CRLF_ON );
    sk_PutString04("trobot_status1 = ",trobot_status1 ,CRLF_ON );
    sk_PutString04("trobot_status2 = ",trobot_status2 ,CRLF_ON );
    sk_PutString04("use_smooth_chg = ",use_smooth_chg ,CRLF_ON );

    sk_PutString01("**********************", CRLF_ON ); 
    sk_PutString04("sk_sub_cycl_int_cnt_av = ",sk_sub_cycl_int_cnt_av ,CRLF_ON );
    

}
//***************************************************************************
//
//
//***************************************************************************
void Display_parameter2(void)
{
sk_PutString01("",CRLF_ON);
sk_PutString01("***** int16 *****",CRLF_ON);

sk_PutString_int16("die_temp = ",die_temp);
sk_PutString_int16("die_temp_16 = ",die_temp_16);
sk_PutString_int16("speedratio = ",speedratio);
sk_PutString_int16("ms_lf_pc = ",ms_lf_pc);
sk_PutString_int16("ms_rf_pc = ",ms_rf_pc);
sk_PutString_int16("ms_lr_pc = ",ms_lr_pc);
sk_PutString_int16("ms_rr_pc = ",ms_rr_pc);

sk_PutString_int16("MS_LF_MAIN[0] = ",MS_LF_MAIN[0]);
sk_PutString_int16("MS_RF_MAIN[0] = ",MS_RF_MAIN[0]);
sk_PutString_int16("MS_LR_MAIN[0] = ",MS_LR_MAIN[0]);
sk_PutString_int16("MS_RR_MAIN[0] = ",MS_RR_MAIN[0]);

sk_PutString_int16("MS_LF_MAIN[1] = ",MS_LF_MAIN[1]);
sk_PutString_int16("MS_RF_MAIN[1] = ",MS_RF_MAIN[1]);
sk_PutString_int16("MS_LR_MAIN[1] = ",MS_LR_MAIN[1]);
sk_PutString_int16("MS_RR_MAIN[1] = ",MS_RR_MAIN[1]);

sk_PutString_int16("MS_LF_MAIN[2] = ",MS_LF_MAIN[2]);
sk_PutString_int16("MS_RF_MAIN[2] = ",MS_RF_MAIN[2]);
sk_PutString_int16("MS_LR_MAIN[2] = ",MS_LR_MAIN[2]);
sk_PutString_int16("MS_RR_MAIN[2] = ",MS_RR_MAIN[2]);

sk_PutString_int16("ms_lf_com_tx = ",ms_lf_com_tx);
sk_PutString_int16("ms_rf_com_tx = ",ms_rf_com_tx);
sk_PutString_int16("ms_lr_com_tx = ",ms_lr_com_tx);
sk_PutString_int16("ms_rr_com_tx = ",ms_rr_com_tx);
sk_PutString_int16("speedratio = ",speedratio);
sk_PutString_int16("max_spd_chg = ",max_spd_chg);
sk_PutString_int16("acc_limit_f_i16 = ",acc_limit_f_i16);
sk_PutString_int16("acc_limit_r_i16 = ",acc_limit_r_i16);
sk_PutString_int16("acc_limit_s_i16 = ",acc_limit_s_i16);
sk_PutString_int16("safty_const_i16 = ",safty_const_i16);
sk_PutString_int16("kvp_i16 = ",kvp_i16);
sk_PutString_int16("kcp_i16 = ",kcp_i16);
sk_PutString_int16("kvi_i16 = ",kvi_i16);
sk_PutString_int16("kci_i16 = ",kci_i16);
sk_PutString_int16("kdl_i16 = ",kdl_i16);
sk_PutString_int16("kdr_i16 = ",kdr_i16);
sk_PutString_int16("satv_i16 = ",satv_i16);
sk_PutString_int16("satc_i16 = ",satc_i16);


sk_PutString01("",CRLF_ON);
sk_PutString01("***** int8 *****",CRLF_ON);
sk_PutString_int8("die_temp_flag = ",die_temp_flag);
sk_PutString_int8("logmode = ",logmode);
sk_PutString_int8("direct_cnt = ",direct_cnt);
sk_PutString_int8("em_stop_en = ",em_stop_en);
sk_PutString_int8("use_smooth_chg = ",use_smooth_chg);
sk_PutString_int8("measure_sensor = ",measure_sensor);
sk_PutString_int8("motorassign[0] = ",motorassign[0]);
sk_PutString_int8("motorassign[1] = ",motorassign[1]);
sk_PutString_int8("motorassign[2] = ",motorassign[2]);
sk_PutString_int8("motorassign[3] = ",motorassign[3]);
sk_PutString_int8("encassign[0] = ",encassign[0]);
sk_PutString_int8("encassign[1] = ",encassign[1]);
sk_PutString_int8("encassign[2] = ",encassign[2]);
sk_PutString_int8("encassign[3] = ",encassign[3]);
sk_PutString_int8("cw0 = ",cw0);
sk_PutString_int8("cw1 = ",cw1);
sk_PutString_int8("cw2 = ",cw2);
sk_PutString_int8("cw3 = ",cw3);
sk_PutString_int8("encd0 = ",encd0);
sk_PutString_int8("encd1 = ",encd1);
sk_PutString_int8("encd2 = ",encd2);
sk_PutString_int8("encd3 = ",encd3);



    

}
//***************************************************************************
//
//
//***************************************************************************
void Display_parameter3(void)
{
    
sk_PutString01("",CRLF_ON);
sk_PutString01("***** float *****",CRLF_ON);

sk_PutString_float("gear_ratio = ",gear_ratio);
sk_PutString_float("dim_wheel = ",dim_wheel);
sk_PutString_float("dist_wheel = ",dist_wheel);
sk_PutString_float("toruque_const = ",toruque_const);
sk_PutString_float("speed_const = ",speed_const);
sk_PutString_float("spd_torq_grad = ",spd_torq_grad);
sk_PutString_float("acc_limit_f = ",acc_limit_f);
sk_PutString_float("acc_limit_r = ",acc_limit_r);
sk_PutString_float("acc_limit_s = ",acc_limit_s);
sk_PutString_float("safty_const  = ",safty_const );
sk_PutString_float("kvp = ",kvp);
sk_PutString_float("kcp = ",kcp);
sk_PutString_float("kvi = ",kvi);
sk_PutString_float("kci = ",kci);
sk_PutString_float("kdl = ",kdl);
sk_PutString_float("kdr = ",kdr);
sk_PutString_float("satv = ",satv);
sk_PutString_float("satc  = ",satc );
sk_PutString_float("ratio_rpm = ",ratio_rpm);
sk_PutString_float("rpm2velo_ratio = ",rpm2velo_ratio);

sk_PutString01("",CRLF_ON);
sk_PutString01("***** int32 *****",CRLF_ON);
    sk_PutString_int32("axis9[0] =  ",axis9[0]);
    sk_PutString_int32("axis9[1] =  ",axis9[1]);
    sk_PutString_int32("axis9[2] =  ",axis9[2]);
    sk_PutString_int32("axis9[3] =  ",axis9[3]);
    sk_PutString_int32("axis9[4] =  ",axis9[4]);
    sk_PutString_int32("axis9[5] =  ",axis9[5]);
    sk_PutString_int32("axis9[6] =  ",axis9[6]);
    sk_PutString_int32("axis9[7] =  ",axis9[7]);
    sk_PutString_int32("axis9[8] =  ",axis9[8]);
    sk_PutString_int32("axis9[9] =  ",axis9[9]);
    sk_PutString_int32("getcom_count =  ",getcom_count);
    sk_PutString_int32("getcom_count_buf =  ",getcom_count_buf);
    sk_PutString_int32("getcom_count_para =  ",getcom_count_para);
    sk_PutString_int32("getcom_flag =  ",getcom_flag);
    sk_PutString_int32("getcom_watch =  ",getcom_watch);
    sk_PutString_int32("ms00_pw =  ",ms00_pw);
    sk_PutString_int32("ms01_pw =  ",ms01_pw);
    sk_PutString_int32("ms02_pw =  ",ms02_pw);
    sk_PutString_int32("ms03_pw =  ",ms03_pw);
    sk_PutString_int32("out2_tag_cycle =  ",out2_tag_cycle);
    sk_PutString_int32("out2_tagpos =  ",out2_tagpos);
    sk_PutString_int32("out2len =  ",out2len);
    sk_PutString_int32("out2pos =  ",out2pos);
    sk_PutString_int32("output_tmp[0] =  ",output_tmp[0]);
    sk_PutString_int32("output_tmp[1] =  ",output_tmp[1]);
    sk_PutString_int32("output_tmp[2] =  ",output_tmp[2]);
    sk_PutString_int32("output_tmp[3] =  ",output_tmp[3]);
    sk_PutString_int32("sendcom_flag =  ",sendcom_flag);
    sk_PutString_int32("speed_lf =  ",speed_lf);
    sk_PutString_int32("speed_lf_buf =  ",speed_lf_buf);
    sk_PutString_int32("speed_lf_delta =  ",speed_lf_delta);
    sk_PutString_int32("speed_lf_pre =  ",speed_lf_pre);
    sk_PutString_int32("speed_lr =  ",speed_lr);
    sk_PutString_int32("speed_lr_buf =  ",speed_lr_buf);
    sk_PutString_int32("speed_lr_delta =  ",speed_lr_delta);
    sk_PutString_int32("speed_lr_pre =  ",speed_lr_pre);
    sk_PutString_int32("speed_rf =  ",speed_rf);
    sk_PutString_int32("speed_rf_buf =  ",speed_rf_buf);
    sk_PutString_int32("speed_rf_delta =  ",speed_rf_delta);
    sk_PutString_int32("speed_rf_pre =  ",speed_rf_pre);
    sk_PutString_int32("speed_rr =  ",speed_rr);
    sk_PutString_int32("speed_rr_buf =  ",speed_rr_buf);
    sk_PutString_int32("speed_rr_delta  =  ",speed_rr_delta );
    sk_PutString_int32("speed_rr_pre =  ",speed_rr_pre);


}
//***************************************************************************
//
//
//***************************************************************************

void Display_Com_parameter(void)
{
    uint8 i,j;
    
    j=0;
    for(i=0; i<64; i++){
        sk_PutString03(" command_para[",i ,CRLF_NONE,10);
        sk_PutString03("] = ",command_para[i],CRLF_NONE,10);
        sk_PutString03(" : 0x",command_para[i],CRLF_NONE,16);

        if( compara_dital[j].pt == i){
            sk_PutString01(compara_dital[j].name,CRLF_ON);
        }
        j++;
        
        for( ;compara_dital[j].pt==i; j++){
            
            sk_PutString01("                ",CRLF_NONE);
            sk_PutString01(compara_dital[j].name,CRLF_ON);
               
        }
   
    }
    
    
}

//***************************************************************************
//
//
//***************************************************************************

void Display_MotCtrl_Com(void)
{
    uint8 i,j;
    int dt;
    
    j=0;
    for(i=0; i<14; i++){
        sk_PutString03(" command[",i ,CRLF_NONE,10);
        sk_PutString03("] = ",command[i],CRLF_NONE,10);
        sk_PutString03(" : 0x",command[i],CRLF_ON,16);
   

            
    }
    // speedLF
    dt = command[4];
    dt <<= 8;
    dt |= command[5];
    sk_PutString06("Speed LF = ",dt ,CRLF_ON );

    
    dt = command[6];
    dt <<= 8;
    dt |= command[7];
    sk_PutString06("Speed RF = ",dt ,CRLF_ON );
    
    dt = command[8];
    dt <<= 8;
    dt |= command[9];
    sk_PutString06("Speed LR = ",dt ,CRLF_ON );
    
    dt = command[10];
    dt <<= 8;
    dt |= command[11];
    sk_PutString06("Speed RR = ",dt ,CRLF_ON );
}

//***************************************************************************
//
//
//***************************************************************************
void  RTC_Display(void)
{
    RTC_1_TIME_DATE  *tm;

    tm = RTC_1_ReadTime();
    
    sk_PutString03("Day&Time = ",tm->Year,CRLF_NONE,10);
    sk_PutString03("/",tm->Month,CRLF_NONE,10);
    sk_PutString03("/",tm->DayOfMonth,CRLF_NONE,10);
    
    sk_PutString03(" ",tm->Hour,CRLF_NONE,10);
    sk_PutString03(":",tm->Min,CRLF_NONE,10);
    sk_PutString03(":",tm->Sec,CRLF_ON,10);
    
    
}

//***************************************************************************
//
//
//***************************************************************************
void MoterCtrl_data_Display(void)
{
    sk_PutString01("Motor_Contl4_3_P",CRLF_ON);
    sk_PutString_realT("  Integrator1_IC = ",Motor_Contl4_3_P.Integrator1_IC,CRLF_ON);
    sk_PutString_realT("  Gain2_Gain = ",Motor_Contl4_3_P.Gain2_Gain,CRLF_ON);
    sk_PutString_realT("  Gain_Gain  = ",Motor_Contl4_3_P.Gain_Gain,CRLF_ON);
    sk_PutString_realT("  Satu..UpperSat = ",Motor_Contl4_3_P.Saturation_UpperSat,CRLF_ON);
    sk_PutString_realT("  Satu..LowerSat = ",Motor_Contl4_3_P.Saturation_LowerSat,CRLF_ON);
    sk_PutString_realT("  Integrator1_IC_i = ",Motor_Contl4_3_P.Integrator1_IC_i,CRLF_ON);
    sk_PutString_realT("  Gain2_Gain_a = ",Motor_Contl4_3_P.Gain2_Gain_a,CRLF_ON);
    sk_PutString_realT("  Gain_Gain_a = ",Motor_Contl4_3_P.Gain_Gain_a,CRLF_ON);
    sk_PutString_realT("  Satu.UpperSat_o = ",Motor_Contl4_3_P.Saturation_UpperSat_o,CRLF_ON);
    sk_PutString_realT("  Satu..LowerSat_j = ",Motor_Contl4_3_P.Saturation_LowerSat_j,CRLF_ON);
    sk_PutString_realT("  Integrator1_IC_p = ",Motor_Contl4_3_P.Integrator1_IC_p,CRLF_ON);
    sk_PutString_realT("  Gain2_Gain_j = ",Motor_Contl4_3_P.Gain2_Gain_j,CRLF_ON);
    sk_PutString_realT("  Gain_Gain_i = ",Motor_Contl4_3_P.Gain_Gain_i,CRLF_ON);
    sk_PutString_realT("  Satu..UpperSat_j = ",Motor_Contl4_3_P.Saturation_UpperSat_j,CRLF_ON);
    sk_PutString_realT("  Satu..LowerSat_a = ",Motor_Contl4_3_P.Saturation_LowerSat_a,CRLF_ON);
    sk_PutString_realT("  Integrator1_IC_ik = ",Motor_Contl4_3_P.Integrator1_IC_ik,CRLF_ON);
    sk_PutString_realT("  Gain2_Gain_e = ",Motor_Contl4_3_P.Gain2_Gain_e,CRLF_ON);
    sk_PutString_realT("  Gain_Gain_o = ",Motor_Contl4_3_P.Gain_Gain_o,CRLF_ON);
    sk_PutString_realT("  Satu..UpperSat_g = ",Motor_Contl4_3_P.Saturation_UpperSat_g,CRLF_ON);
    sk_PutString_realT("  Satu..LowerSat_l = ",Motor_Contl4_3_P.Saturation_LowerSat_l,CRLF_ON);
    sk_PutString01("",CRLF_ON);
    sk_PutString01(" Motor_Contl4_3_X",CRLF_ON);
    sk_PutString_realT("  Int..CSTATE   = ",Motor_Contl4_3_X.Integrator1_CSTATE,CRLF_ON);
    sk_PutString_realT("  Int..CSTATE_h = ",Motor_Contl4_3_X.Integrator1_CSTATE_h,CRLF_ON);
    sk_PutString_realT("  Int..CSTATE_l = ",Motor_Contl4_3_X.Integrator1_CSTATE_l,CRLF_ON);
    sk_PutString_realT("  Int..CSTATE_g = ",Motor_Contl4_3_X.Integrator1_CSTATE_g,CRLF_ON);
    sk_PutString01("",CRLF_ON);
    sk_PutString01("Motor_Contl4_3_B",CRLF_ON);
    sk_PutString_realT("  Sum   = ",Motor_Contl4_3_B.Sum,CRLF_ON);
    sk_PutString_realT("  Sum_n = ",Motor_Contl4_3_B.Sum_n,CRLF_ON);
    sk_PutString_realT("  Sum_m = ",Motor_Contl4_3_B.Sum_m,CRLF_ON);
    sk_PutString_realT("  Sum_i = ",Motor_Contl4_3_B.Sum_i,CRLF_ON);
    sk_PutString01("",CRLF_ON);
    sk_PutString01("Motor_Contl4_3_X",CRLF_ON); 
    sk_PutString_realT("  Int..CSTATE   = ",Motor_Contl4_3_X.Integrator1_CSTATE,CRLF_ON);
    sk_PutString_realT("  Int..CSTATE_h = ",Motor_Contl4_3_X.Integrator1_CSTATE_h,CRLF_ON);
    sk_PutString_realT("  Int..CSTATE_l = ",Motor_Contl4_3_X.Integrator1_CSTATE_l,CRLF_ON);
    sk_PutString_realT("  Int..CSTATE_g = ",Motor_Contl4_3_X.Integrator1_CSTATE_g,CRLF_ON);
    sk_PutString01("",CRLF_ON);
    sk_PutString01("Motor_Contl4_3_U",CRLF_ON); 
    sk_PutString_realT("  Targetspeed1 = ",Motor_Contl4_3_U.Targetspeed1,CRLF_ON);
    sk_PutString_realT("  Targetspeed2 = ",Motor_Contl4_3_U.Targetspeed2,CRLF_ON);
    sk_PutString_realT("  Targetspeed4 = ",Motor_Contl4_3_U.Targetspeed4,CRLF_ON);
    sk_PutString_realT("  Targetspeed3 = ",Motor_Contl4_3_U.Targetspeed3,CRLF_ON);
    sk_PutString_realT("  RPM1 = ",Motor_Contl4_3_U.RPM1,CRLF_ON);
    sk_PutString_realT("  RPM2 = ",Motor_Contl4_3_U.RPM2,CRLF_ON);
    sk_PutString_realT("  RPM3 = ",Motor_Contl4_3_U.RPM3,CRLF_ON);
    sk_PutString_realT("  RPM4 = ",Motor_Contl4_3_U.RPM4,CRLF_ON);
    sk_PutString01("",CRLF_ON);
    sk_PutString01("Motor_Contl4_3_Y",CRLF_ON); 
    sk_PutString_realT("  PWMDuty1 = ",Motor_Contl4_3_Y.PWMDuty1,CRLF_ON);
    sk_PutString_realT("  PWMDuty2 = ",Motor_Contl4_3_Y.PWMDuty2,CRLF_ON);
    sk_PutString_realT("  PWMDuty3 = ",Motor_Contl4_3_Y.PWMDuty3,CRLF_ON);
    sk_PutString_realT("  PWMDuty4 = ",Motor_Contl4_3_Y.PWMDuty4,CRLF_ON);
    sk_PutString_realT("  VKmh1 = ",Motor_Contl4_3_Y.VKmh1,CRLF_ON);
    sk_PutString_realT("  VKmh2 = ",Motor_Contl4_3_Y.VKmh2,CRLF_ON);
    sk_PutString_realT("  VKmh3 = ",Motor_Contl4_3_Y.VKmh3,CRLF_ON);
    sk_PutString_realT("  VKmh4 = ",Motor_Contl4_3_Y.VKmh4,CRLF_ON);
    sk_PutString01("",CRLF_ON);
        
    
    
    
}
//***************************************************************************
//
//
//***************************************************************************
void MoterCtrl_data2_Display(void)
{

    

sk_PutString03("isVariableStepSolver = ", Motor_Contl4_3_M_.solverInfo.isVariableStepSolver, CRLF_ON,16);
sk_PutString03("solverNeedsReset = ",Motor_Contl4_3_M_.solverInfo.solverNeedsReset, CRLF_ON, 16  );

//sk_PutString03("solverMode = ",Motor_Contl4_3_M_.solverInfo.solverMode, CRLF_ON, 16  );

switch(Motor_Contl4_3_M_.solverInfo.solverMode){
case SOLVER_MODE_AUTO:
    sk_PutString01("solverMode = AUTO", CRLF_ON );
    break;
case SOLVER_MODE_SINGLETASKING:
    sk_PutString01("solverMode = SINGLETASKING", CRLF_ON );
    break;
case SOLVER_MODE_MULTITASKING:
default:
     sk_PutString01("solverMode = MULTITASKING", CRLF_ON );
   
    break;
}



sk_PutString_realT("solverStopTime = ",Motor_Contl4_3_M_.solverInfo.solverStopTime, CRLF_ON );
sk_PutString_realT("minStepSize = ",Motor_Contl4_3_M_.solverInfo.minStepSize, CRLF_ON );
sk_PutString_realT("maxStepSize = ",Motor_Contl4_3_M_.solverInfo.maxStepSize, CRLF_ON );
sk_PutString_realT("fixedStepSize = ",Motor_Contl4_3_M_.solverInfo.fixedStepSize, CRLF_ON );
sk_PutString03("solverShapePreserveControl = ",Motor_Contl4_3_M_.solverInfo.solverShapePreserveControl, CRLF_ON, 16  );
sk_PutString03("s..MaxConsecutiveMinStep = ",Motor_Contl4_3_M_.solverInfo.solverMaxConsecutiveMinStep, CRLF_ON, 16  );
sk_PutString03("maxNumMinSteps = ",Motor_Contl4_3_M_.solverInfo.maxNumMinSteps, CRLF_ON, 16  );
sk_PutString03("s..MaxOrder = ",Motor_Contl4_3_M_.solverInfo.solverMaxOrder, CRLF_ON, 16  );
//sk_PutString_realT("s..ConsecutiveZCsStepRelTol = ",Motor_Contl4_3_M_.solverInfo.solverConsecutiveZCsStepRelTol, CRLF_ON );


sk_PutString03("s..MaxConsecutiveZCs = ",Motor_Contl4_3_M_.solverInfo.solverMaxConsecutiveZCs, CRLF_ON, 16  );
sk_PutString03("s..ExtrapolationOrder = ",Motor_Contl4_3_M_.solverInfo.solverExtrapolationOrder, CRLF_ON, 16  );
sk_PutString03("s..NumberNewtonIterations = ",Motor_Contl4_3_M_.solverInfo.solverNumberNewtonIterations, CRLF_ON, 16  );
sk_PutString03("s..RefineFactor = ",Motor_Contl4_3_M_.solverInfo.solverRefineFactor, CRLF_ON, 16  );
sk_PutString_realT("s..RelTol = ",Motor_Contl4_3_M_.solverInfo.solverRelTol, CRLF_ON );
sk_PutString_realT("unused_real_T_1 = ",Motor_Contl4_3_M_.solverInfo.unused_real_T_1, CRLF_ON );
sk_PutString03("zcSignalVectorLength = ",Motor_Contl4_3_M_.solverInfo.zcSignalVectorLength, CRLF_ON, 16  );
sk_PutString03("foundContZcEvents = ",Motor_Contl4_3_M_.solverInfo.foundContZcEvents, CRLF_ON, 16  );
sk_PutString03("isAtLeftPostOfContZcEvent = ",Motor_Contl4_3_M_.solverInfo.isAtLeftPostOfContZcEvent, CRLF_ON, 16  );
sk_PutString03("isAtRightPostOfContZcEvent = ",Motor_Contl4_3_M_.solverInfo.isAtRightPostOfContZcEvent, CRLF_ON, 16  );
sk_PutString03("ne..ZcEventNotification = ",Motor_Contl4_3_M_.solverInfo.needsContZcEventNotification, CRLF_ON, 16  );
sk_PutString03("adaptiveZcDetection = ",Motor_Contl4_3_M_.solverInfo.adaptiveZcDetection, CRLF_ON, 16  );
sk_PutString03("numZcSignals = ",Motor_Contl4_3_M_.solverInfo.numZcSignals, CRLF_ON, 16  );
sk_PutString03("stateProjection = ",Motor_Contl4_3_M_.solverInfo.stateProjection, CRLF_ON, 16  );
sk_PutString03("robustResetMethod = ",Motor_Contl4_3_M_.solverInfo.robustResetMethod, CRLF_ON, 16  );
sk_PutString03("updateJacobianAtReset = ",Motor_Contl4_3_M_.solverInfo.updateJacobianAtReset, CRLF_ON, 16  );
sk_PutString03("consistencyChecking = ",Motor_Contl4_3_M_.solverInfo.consistencyChecking, CRLF_ON, 16  );


//sk_PutString03("massMatrixType = ",Motor_Contl4_3_M_.solverInfo.massMatrixType, CRLF_ON, 16  );

switch(Motor_Contl4_3_M_.solverInfo.massMatrixType){

case SS_MATRIX_NONE:
     sk_PutString01("smassMatrixType = NONE", CRLF_ON );
    break;
case SS_MATRIX_CONSTANT:
     sk_PutString01("smassMatrixType = CONSTANT", CRLF_ON );
    break;
case SS_MATRIX_TIMEDEP:
     sk_PutString01("smassMatrixType = TIMEDEP", CRLF_ON );
    break;
case SS_MATRIX_STATEDEP:
default:
     sk_PutString01("smassMatrixType = STATEDEP", CRLF_ON );
    break;
}


sk_PutString03("massMatrixNzMax = ",Motor_Contl4_3_M_.solverInfo.massMatrixNzMax, CRLF_ON, 16  );
sk_PutString_realT("zcThreshold = ",Motor_Contl4_3_M_.solverInfo.zcThreshold, CRLF_ON );
sk_PutString_realT("zeroCrossAlgorithm = ",Motor_Contl4_3_M_.solverInfo.zeroCrossAlgorithm, CRLF_ON );
sk_PutString03("consecutiveZCsError = ",Motor_Contl4_3_M_.solverInfo.consecutiveZCsError, CRLF_ON, 16  );
sk_PutString03("blkStateChange = ",Motor_Contl4_3_M_.solverInfo.blkStateChange, CRLF_ON, 16  );
sk_PutString03("isComputingJacobian = ",Motor_Contl4_3_M_.solverInfo.isComputingJacobian, CRLF_ON, 16  );
sk_PutString03("s..JacobianMethodControl = ",Motor_Contl4_3_M_.solverInfo.solverJacobianMethodControl, CRLF_ON, 16  );
sk_PutString03("ignoredZcDiagnostic = ",Motor_Contl4_3_M_.solverInfo.ignoredZcDiagnostic, CRLF_ON, 16  );
sk_PutString03("maskedZcDiagnostic = ",Motor_Contl4_3_M_.solverInfo.maskedZcDiagnostic, CRLF_ON, 16  );

sk_PutString01("***** Data Info *****", CRLF_ON );

sk_PutString03("zCCacheNeedsReset = ",Motor_Contl4_3_M_.ModelData.zCCacheNeedsReset, CRLF_ON, 16  );
sk_PutString03("derivCacheNeedsReset = ",Motor_Contl4_3_M_.ModelData.derivCacheNeedsReset, CRLF_ON, 16  );
sk_PutString03("blkStateChange = ",Motor_Contl4_3_M_.ModelData.blkStateChange, CRLF_ON, 16  );
sk_PutString_realT("odeY[0] = ",Motor_Contl4_3_M_.ModelData.odeY[0], CRLF_ON );
sk_PutString_realT("odeY[1] = ",Motor_Contl4_3_M_.ModelData.odeY[1], CRLF_ON );
sk_PutString_realT("odeY[2] = ",Motor_Contl4_3_M_.ModelData.odeY[2], CRLF_ON );
sk_PutString_realT("odeY[3] = ",Motor_Contl4_3_M_.ModelData.odeY[3], CRLF_ON );
sk_PutString_realT("odeF[0][0] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[0][1] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[0][2] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[0][3] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[1][0] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[1][1] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[1][2] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[1][3] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[2][0] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[2][1] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[2][2] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );
sk_PutString_realT("odeF[2][3] = ",Motor_Contl4_3_M_.ModelData.odeF[3][4], CRLF_ON );








sk_PutString_realT("intgData.y = ",Motor_Contl4_3_M_.ModelData.intgData.y, CRLF_ON );
sk_PutString_realT("intgData.f[0] = ",Motor_Contl4_3_M_.ModelData.intgData.f[0], CRLF_ON );
sk_PutString_realT("intgData.f[1] = ",Motor_Contl4_3_M_.ModelData.intgData.f[1], CRLF_ON );
sk_PutString_realT("intgData.f[2] = ",Motor_Contl4_3_M_.ModelData.intgData.f[2], CRLF_ON );


sk_PutString01("***** Sample Time *****", CRLF_ON );

sk_PutString03("numContStates = ",Motor_Contl4_3_M_.Sizes.numContStates, CRLF_ON, 16  );
sk_PutString03("numSampTimes = ",Motor_Contl4_3_M_.Sizes.numSampTimes, CRLF_ON, 16  );



sk_PutString01("***** Timing info *****", CRLF_ON );

sk_PutString_uint32("clockTick0 = ", Motor_Contl4_3_M_.Timing.clockTick0 );
sk_PutString_realT("stepSize0 = ",Motor_Contl4_3_M_.Timing.stepSize0, CRLF_ON );
sk_PutString_uint32("clockTick1 = ",Motor_Contl4_3_M_.Timing.clockTick1  );
//sk_PutString03("simTimeStep = ",Motor_Contl4_3_M_.Timing.simTimeStep, CRLF_ON, 16  );

switch( Motor_Contl4_3_M_.Timing.simTimeStep){
    case MINOR_TIME_STEP:
        sk_PutString01("simTimeStep = MINOR_TIME", CRLF_ON );
    case MAJOR_TIME_STEP:
    default:
        sk_PutString01("simTimeStep = MAJOR_TIME", CRLF_ON );
        break;
}


sk_PutString03("stopRequestedFlag = ",Motor_Contl4_3_M_.Timing.stopRequestedFlag, CRLF_ON, 16  );
sk_PutString_realT("tArray[0] = ",Motor_Contl4_3_M_.Timing.tArray[0], CRLF_ON  );
sk_PutString_realT("tArray[1] = ",Motor_Contl4_3_M_.Timing.tArray[1], CRLF_ON  );

}

//***************************************************************************
//
//
//***************************************************************************
void sk_log_main(char8 *string,uint16 data)
{
    if( sk_log_flg2 & SK_LOG2_MAIN_LOOP  ){
        sk_log_out(string,data);
    }
}

//***************************************************************************
//
//
//***************************************************************************
void sk_log_int(char8 *string,uint16 data)
{
     RTC_1_TIME_DATE  *tm;
    uint8 i;
    
    
    // 
    // RTCから時刻を読む
    // 
    tm = RTC_1_ReadTime();
    
    Deblog.rec[Deblog.Wpt].Year = tm->Year;
    Deblog.rec[Deblog.Wpt].Month = tm->Month;
    Deblog.rec[Deblog.Wpt].DayOfMonth = tm->DayOfMonth;
    Deblog.rec[Deblog.Wpt].Hour = tm->Hour;
    Deblog.rec[Deblog.Wpt].Min = tm->Min;
    Deblog.rec[Deblog.Wpt].Sec = tm->Sec;
    Deblog.rec[Deblog.Wpt].time = sk_sub_cycl_int_cnt;
    
    // 
    // 引数の文字をレコードに登録
    //
    for(i=0; i< LOG_BUF_CHAR; i++){
        
        if( *string == NULL ){
            Deblog.rec[Deblog.Wpt].buf[i]= ' ';
            i++;
            Deblog.rec[Deblog.Wpt].buf[i]= '0';
            i++;
            Deblog.rec[Deblog.Wpt].buf[i]= 'x';
            i++;
            break;
        }
        else{
            Deblog.rec[Deblog.Wpt].buf[i] = *string;
            string ++;
        }   
    }

    itoa(data,&Deblog.rec[Deblog.Wpt].buf[i],16);
    
    //
    // リード、ライトポインタを更新
    // 
    Deblog.Wpt++;
    if( Deblog.Wpt > LOG_BUF_MAX ){
        Deblog.Wpt =0 ;
        
        if( Deblog.Wpt == Deblog.Rpt ){
            Deblog.Rpt ++;
                if( Deblog.Rpt > LOG_BUF_MAX ){
                    Deblog.Rpt =0 ;
                }
        }
    }
    
    
    
}

//***************************************************************************
//
//
//***************************************************************************
void sk_log_int_string(char8 *string)
{
     RTC_1_TIME_DATE  *tm;
    uint8 i;
    uint8 null_flg;
    
    // 
    // RTCから時刻を読む
    // 
    tm = RTC_1_ReadTime();
    
    Deblog.rec[Deblog.Wpt].Year = tm->Year;
    Deblog.rec[Deblog.Wpt].Month = tm->Month;
    Deblog.rec[Deblog.Wpt].DayOfMonth = tm->DayOfMonth;
    Deblog.rec[Deblog.Wpt].Hour = tm->Hour;
    Deblog.rec[Deblog.Wpt].Min = tm->Min;
    Deblog.rec[Deblog.Wpt].Sec = tm->Sec;
    Deblog.rec[Deblog.Wpt].time = sk_sub_cycl_int_cnt;
    
    // 
    // 引数の文字をレコードに登録
    //
    null_flg=0;
    for(i=0; i< LOG_BUF_CHAR; i++){
        
        if( *string == NULL ){
            Deblog.rec[Deblog.Wpt].buf[i]= NULL;
            null_flg=1;
            break;
        }
        else{
            Deblog.rec[Deblog.Wpt].buf[i] = *string;
            string ++;
        }   
    }
    if( null_flg == 0){
        Deblog.rec[Deblog.Wpt].buf[LOG_BUF_CHAR-1]= NULL;
    }

        
    //
    // リード、ライトポインタを更新
    // 
    Deblog.Wpt++;
    if( Deblog.Wpt > LOG_BUF_MAX ){
        Deblog.Wpt =0 ;
        
        if( Deblog.Wpt == Deblog.Rpt ){
            Deblog.Rpt ++;
                if( Deblog.Rpt > LOG_BUF_MAX ){
                    Deblog.Rpt =0 ;
                }
        }
    }
    
    
    
}
//***************************************************************************
//
//
//***************************************************************************
void sk_log_int_realT(char *string,real_T data)
{
    char buf[30];
    uint8 i;
    char *pt;
    
    pt = string;
    i = 0;
    while( *pt != NULL ){
        buf[i] = *pt;
        pt ++;
        i++;
    }
    Set_realT2c(data,&buf[i],3,5);
    sk_log_int_string(buf);
}

void sk_PutString_realT(char8 *string,real_T data,CRLF flg)
{
    char buf[30];
    uint8 i;
    char *pt;
    
    pt = string;
    i = 0;
    while( *pt != NULL ){
        buf[i] = *pt;
        pt ++;
        i++;
    }
    Set_realT2c(data,&buf[i],1,5);
    sk_PutString01(buf,flg);
}

//***************************************************************************
//
//
//***************************************************************************
void sk_log_int_float(char *string,float data)
{
    char buf[30];
    uint8 i;
    char *pt;
    
    pt = string;
    i = 0;
    while( *pt != NULL ){
        buf[i] = *pt;
        pt ++;
        i++;
    }
    Set_f2c(data,&buf[i],3,5);
    sk_log_int_string(buf);
}
//***************************************************************************
//
//
//***************************************************************************
void sk_log_int_int32(char *string,int32 data)
{
    char buf[30];
    uint8 i;
    char *pt;
    
    pt = string;
    i = 0;
    while( *pt != NULL ){
        buf[i] = *pt;
        pt ++;
        i++;
    }
    sk_int32toChar(&buf[i],data);
    sk_log_int_string(buf);
}
//***************************************************************************
//
//
//***************************************************************************
extern uint8 CharConv[16];
void sk_log_int_uint16(char *string,uint16 dt1, uint16 dt2, uint16 dt3)
{
    char buf[40];
    uint8 i,j;
    char *pt;
    
    pt = string;
    i = 0;
    while( *pt != NULL ){
        buf[i] = *pt;
        pt ++;
        i++;
    }
        
        
    buf[i] = CharConv[(dt1 >> 12) & 0x000f];
    i++;
    buf[i] = CharConv[(dt1 >> 8) & 0x000f];
    i++;
    buf[i] = CharConv[(dt1 >> 4) & 0x000f];
    i++;
    buf[i] = CharConv[dt1 & 0x000f];
    i++;
    buf[i] = ',';
    i++;

    buf[i] = CharConv[(dt2 >> 12) & 0x000f];
    i++;
    buf[i] = CharConv[(dt2 >> 8) & 0x000f];
    i++;
    buf[i] = CharConv[(dt2 >> 4) & 0x000f];
    i++;
    buf[i] = CharConv[dt2 & 0x000f];
    i++;
    buf[i] = ',';
    i++;

    buf[i] = CharConv[(dt3 >> 12) & 0x000f];
    i++;
    buf[i] = CharConv[(dt3 >> 8) & 0x000f];
    i++;
    buf[i] = CharConv[(dt3 >> 4) & 0x000f];
    i++;
    buf[i] = CharConv[dt3 & 0x000f];
    i++;
    buf[i] = NULL;

    
    sk_log_int_string(buf);
}




//***************************************************************************
//
//
//***************************************************************************
void sk_log_int_int16(char *string,int16 data)
{
    char buf[30];
    uint8 i;
    char *pt;
    
    pt = string;
    i = 0;
    while( *pt != NULL ){
        buf[i] = *pt;
        pt ++;
        i++;
    }
    sk_int16toChar(&buf[i],data);
    sk_log_int_string(buf);
}
//***************************************************************************
//
//
//***************************************************************************
void sk_log_out(char8 *string,uint16 data)
{
    RTC_1_TIME_DATE  *tm;
    RTC_1_TIME_DATE  tmbuf;
    char buf1[20];
    char buf2[20];
    uint8 i;
    
    // 
    // RTCから時刻を読む
    // 
    tm = RTC_1_ReadTime();
    
    // tmbuf.Year = tm->Year;
    // tmbuf.Month = tm->Month;
    // tmbuf.DayOfMonth = tm->DayOfMonth;
    tmbuf = *tm;
    
    // 
    // 引数の文字をレコードに登録
    //
    for(i=0; i< LOG_BUF_CHAR; i++){
        
        if( *string == NULL ){
            buf1[i]= ' ';
            i++;
            buf1[i]= '0';
            i++;
            buf1[i]= 'x';
            i++;
            break;
        }
        else{
            buf1[i] = *string;
            string ++;
        }   
    }
    itoa(data,&buf1[i],16);
   
    skSet_time(sk_sub_cycl_int_cnt,buf2);
    sk_PutString03(" ",tmbuf.Hour,CRLF_NONE,10);
    sk_PutString03(":",tmbuf.Min,CRLF_NONE,10);
    sk_PutString03(":",tmbuf.Sec,CRLF_NONE,10);
    
    sk_PutString01(":",CRLF_NONE);
    sk_PutString01(buf2,CRLF_NONE);
    
    sk_PutString01("  ",CRLF_NONE);
    sk_PutString01(buf1,CRLF_ON);

}
//***************************************************************************
//
//
//***************************************************************************

void sk_log_Display(void)
{
    uint16 Wpt;
    uint16 Rpt;
    uint16 i;
    char buf[10];

    sk_PutString01("*** LOG DISPLAY ***",CRLF_ON);
    
    Wpt = Deblog.Wpt;
    Rpt = Deblog.Rpt;
    
    sk_PutString03("Wpt = ",Wpt,CRLF_ON,10);
    sk_PutString03("Rpt = ",Rpt,CRLF_ON,10);

    if( Wpt != Rpt ){
        for( i=0; i< LOG_BUF_MAX; i++){
        
        //    sk_PutString03(" ",Deblog.rec[Rpt].Year,CRLF_NONE,10);
        //    sk_PutString03("/",Deblog.rec[Rpt].Month,CRLF_NONE,10);
        //    sk_PutString03("/",Deblog.rec[Rpt].DayOfMonth,CRLF_NONE,10);
            skSet_time(Deblog.rec[Rpt].time,buf);

            sk_PutString03(" ",Deblog.rec[Rpt].Hour,CRLF_NONE,10);
            sk_PutString03(":",Deblog.rec[Rpt].Min,CRLF_NONE,10);
            sk_PutString03(":",Deblog.rec[Rpt].Sec,CRLF_NONE,10);
            
            sk_PutString01(":",CRLF_NONE);
            sk_PutString01(buf,CRLF_NONE);
            
            sk_PutString01("  ",CRLF_NONE);
            sk_PutString01(Deblog.rec[Rpt].buf,CRLF_ON);
        
            if( Rpt < LOG_BUF_MAX ){
                Rpt++;
            }
            else{
                Rpt=0;
            }
            
            if( Rpt >= Wpt ){
                   break;
            }
        }
    }
    
}

//***************************************************************************
//
//
//***************************************************************************
void sk_adc_debug(uint8 ad, uint8 data )
{
    int n;
    int i=0;
    int k=0;
    float dt1;
    float dt2;
    char *buf1;
    char buf2[30];
char dist0[]="DIST0(A4)= ";
char dist1[]="DIST1(A1)= ";
char dist2[]="DIST2(A2)= ";
char dist3[]="DIST3(A3)= ";
char dist4[]="DIST4= ";
char dist5[]="DIST5= ";
char dist6[]="DIST6= ";
char dist7[]="DIST7= ";
char etc[]="NONE";
                
    
    dt1=data;
   
        switch(ad){
            case 0:
                buf1 = dist0;
                break;
            case 1:
                buf1 = dist1;
                break;
            case 2:
                buf1 = dist2;
                break;
            case 3:
                buf1 = dist3;
                break;
            case 4:
                buf1 = dist4;
                break;
            case 5:
                buf1 = dist5;
                break;
            case 6:
                buf1 = dist6;
                break;
            case 7:
                buf1 = dist7;
                break;    
            default:
                buf1 = etc;
                break;
        }
                //sk_PutString01(buf1,CRLF_ON);
        
        switch(ad){
            case 0:
                if( sk_log_flg3 & SK_LOG2_DIST0 ){
                    i = 0;
                    while( *buf1 != NULL ){
                        buf2[i] = *buf1;
                        buf1++;
                        i++;
                    }
                    buf2[i] = NULL;
                                 
                    dt2= 300*dt1/0xa8;
                    Set_f2c(dt2, &buf2[i],3,3);
                    sk_log_int_string(buf2);
                }
                break;
            case 1:
                if( sk_log_flg3 & SK_LOG2_DIST1 ){
                    i = 0;
                    while( *buf1 != NULL ){
                        buf2[i] = *buf1;
                        buf1++;
                        i++;
                    }
                    buf2[i] = NULL;
                                 
                    dt2= 300*dt1/0xa8;
                    Set_f2c(dt2, &buf2[i],3,3);
                    sk_log_int_string(buf2);
                }
                break;
            case 2:
                if( sk_log_flg3 & SK_LOG2_DIST2 ){
                    i = 0;
                    while( *buf1 != NULL ){
                        buf2[i] = *buf1;
                        buf1++;
                        i++;
                    }
                    buf2[i] = NULL;
                                 
                    dt2= 300*dt1/0xa8;
                    Set_f2c(dt2, &buf2[i],3,3);
                    sk_log_int_string(buf2);
                }
                break;
            case 3:
                if( sk_log_flg3 & SK_LOG2_DIST3 ){
                    i = 0;
                    while( *buf1 != NULL ){
                        buf2[i] = *buf1;
                        buf1++;
                        i++;
                    }
                    buf2[i] = NULL;
                                 
                    dt2= 300*dt1/0xa8;
                    Set_f2c(dt2, &buf2[i],3,3);
                    sk_log_int_string(buf2);
                }
                break;
            case 4:
                if( sk_log_flg3 & SK_LOG2_DIST4 ){
                    dt2= 300*dt1/0xa8;
                    sk_log_int(buf1,data);
                }
                break;
            case 5:
                if( sk_log_flg3 & SK_LOG2_DIST5 ){

                    sk_log_int(buf1,data);
                }
                break;
            case 6:
                if( sk_log_flg3 & SK_LOG2_DIST6 ){

                    sk_log_int(buf1,data);
                }
                break;
            case 7:
                if( sk_log_flg3 & SK_LOG2_DIST7 ){

                    sk_log_int(buf1,data);
                }
                break;
            default:
                break;
        }
                
        
   
}
//**********************************************
//
//
//**********************************************
void sk_PutString_float(char8 *string,float data)
{
    char buf[20];
    DEB_UART_PutString(string);
    Set_f2c(data,buf,3,3);
    DEB_UART_PutString(buf);
    DEB_UART_PutCRLF(1);
}
void Set_f2c(float dt, char *cpt,uint8 keta_u,uint8 keta_l)
{
    int n;
    uint8 i=0;
    uint8 k=0;
    uint8 j;
    float dt0;
    float dt1;
    float dt2;
    uint32 dt32;

    
    dt32 = dt;
    
    if( dt < 0 ){
        *cpt = '-';
        cpt ++;
        dt *= -1;
       
    }
    
    

    

    // 整数部の桁数を確認
    
    //sk_PutString03("step1",0,CRLF_ON,10);

    dt1=dt;
    n=(int)dt;
    i=0;
    while( n>0 )
    {
        dt1 /= 10;
        n=(int)dt1;
        i++;
        
        //sk_PutString03("n= ",n,CRLF_ON,10);
        //sk_PutString03("i= ",i,CRLF_ON,10);
    }
    //if( i== 0 )
    //  i=1;

    //sk_PutString03("step2",0,CRLF_ON,10);

    // データの桁数と表示桁数が異なっている場合
    j=0;
    if( keta_u > i ){
        for(j=0 ; j <(keta_u - i ); j++ ){
            *(cpt+j) = '0';
        }
    }
   //sk_PutString03("j= ",j,CRLF_ON,10);
 

    
 //   k = i + j ;


    
    /*
    dt1=dt;
    i=0;
    while( n>0 )
    {
        dt1 /= 10;
        n=(int)dt1;
        i++;
    }
    */
    //sk_PutString03("step3",0,CRLF_ON,10);
       //sk_PutString03("i= ",i,CRLF_ON,10);
       //sk_PutString03("j= ",j,CRLF_ON,10);

    k=i+j;
    *(cpt+k) = '.';

    dt1 *= 10;
    n = (int)dt1;
    dt1 = dt1 - n;
 //sk_PutString03("step4",0,CRLF_ON,10);
       //sk_PutString03("j= ",j,CRLF_ON,10);
       //sk_PutString03("n= ",n,CRLF_ON,10);

        while( j <= (k+keta_l) ){

            
            // sk_PutString03("skSet_time(4)n= ",n,CRLF_ON,10);
            
            if( j== k){
                j++;
            }
            // sk_PutString03("k= ",k,CRLF_ON,10);
       //sk_PutString03("j= ",j,CRLF_ON,10);
       //sk_PutString03("n= ",n,CRLF_ON,10);

            *( cpt + j ) = '0' + n;
            
            dt1 *= 10;
            n = (int)dt1;
            dt1 = dt1 - n;

            j++;
            
        }

        /* Null-terminated string */
        *(cpt+j) = NULL;
        
      //sk_PutString01(cpt,CRLF_ON);
}
void Set_realT2c(real_T dt, char *cpt,uint8 keta_u,uint8 keta_l)
{
    int n;
    uint8 i=0;
    uint8 k=0;
    uint8 j;
    real_T dt0;
    real_T dt1;
    real_T dt2;
    uint64 dt64;
    

    if( dt < 0 ){
        *cpt = '-';
        cpt++;
        dt *= -1;
    }
   
    

    // 整数部の桁数を確認
    
    //sk_PutString03("step1",0,CRLF_ON,10);

    dt1=dt;
    n=(int)dt;
    i=0;
    while( n>0 )
    {
        dt1 /= 10;
        n=(int)dt1;
        i++;
        
    }


    // データの桁数と表示桁数が異なっている場合
    j=0;
    if( keta_u > i ){
        for(j=0 ; j <(keta_u - i ); j++ ){
            *(cpt+j) = '0';
        }
    }


    k=i+j;
    *(cpt+k) = '.';

    dt1 *= 10;
    n = (int)dt1;
    dt1 = dt1 - n;

        while( j <= (k+keta_l) ){

            
            if( j== k){
                j++;
            }

            *( cpt + j ) = '0' + n;
            
            dt1 *= 10;
            n = (int)dt1;
            dt1 = dt1 - n;

            j++;
            
        }

        /* Null-terminated string */
        *(cpt+j) = NULL;
        
}

//***************************************************************************
//
//
//***************************************************************************
void skSet_time(uint16 ldata, char *cpt)
{
    int n;
    int i=0;
    int k=0;
    float dt1;
    float dt2;

	if( sk_sub_cycl_int_cnt_av == 0 ){
		cpt = "000.000";
	}
	else if( ldata >= sk_sub_cycl_int_cnt_av ){
		cpt = "999.999";
	}
	else{
        
        dt1 = ldata;
        dt2 = sk_sub_cycl_int_cnt_av;
        
        dt1 = 1000*dt1/dt2;
        // dt1=6.456;
        
        n=(int)dt1;

        if( n >= 100 ){
            // 3桁
        }
        else if( n >= 10 ){
            // 2桁
            *(cpt+i) = '0';
            i++;
        }
        else if( n >= 1 ){
            // 1桁
            *(cpt+i) = '0';
            i++;
            *(cpt+i) = '0';
            i++;
        }
        else{
            *(cpt+i) = '0';
            i++;
            *(cpt+i) = '0';
            i++;
            *(cpt+i) = '0';
            i++;
        }
        k = i;
        
     
        
        // sk_PutString03("skSet_time(0)n= ",n,CRLF_ON,10);
        

        while( n>0 )
        {
            dt1 /= 10;
            n=(int)dt1;
            // sk_PutString03("skSet_time(1)n= ",n,CRLF_ON,10);
            i++;
        }

        *(cpt+i) = '.';

        dt1 *= 10;
        n = (int)dt1;
        dt1 = dt1 - n;
        
        // sk_PutString03("i= ",i,CRLF_ON,10);
        // sk_PutString03("k= ",k,CRLF_ON,10);

        while( k <= (i+3) ){
            
            // sk_PutString03("skSet_time(4)n= ",n,CRLF_ON,10);
            
            if(k == i){
                k++;
            }
            // sk_PutString03("k= ",k,CRLF_ON,10);
            
            *( cpt + k ) = '0' + n;
            
            dt1 *= 10;
            n = (int)dt1;
            dt1 = dt1 - n;

            k++;
            
        }

        /* Null-terminated string */
        *(cpt+k) = NULL;
        // sk_PutString01(cpt,CRLF_ON);
        
	}
}
//***************************************************************************
//  割込みに置くログ
//
//***************************************************************************
void SKLog_sub_cycl_int(void)
{

    // sk_sub_cycl_int_cnt++;
    
    
    if( sk_sub_cycl_int_cnt == 100 ){
        // sk_sub_cycl_int_cnt = 0;
        // sk_log_int("sub_cycle()",0);
    }
}

//***************************************************************************
//
//
//***************************************************************************

void MyRTC_1_EverySecondHandler(void)
{
    uint16 dt;
    
    // sk_PutString01("RTC Sec Interrupt",CRLF_ON);
    switch(sk_measure_cnt){
	case 0:
		sk_measure_cnt++;
        //sk_log_int("MyRTC_1_Ever(0)",0);
		break;
	case 1:
		sk_measure_cnt++;
		sk_sub_cycl_int_cnt_av = sk_sub_cycl_int_cnt;
        
        //sk_log_int("MyRTC_1_Ever(1)",0);
		break;
	default:
		// sk_measure_cnt++;
        if( sk_sub_cycl_int_cnt_av <= sk_sub_cycl_int_cnt )
            sk_sub_cycl_int_cnt_av = sk_sub_cycl_int_cnt;
 
	}
    // sk_log_int("cnt_av= ",sk_sub_cycl_int_cnt_av);
    
    sk_sub_cycl_int_cnt = 0;
    
    

}

void MyRTC_1_EveryMinuteHandler(void)
{
    // sk_PutString01("RTC Min Interrupt",CRLF_ON);
}

void MyRTC_1_EveryHourHandler(void)
{
    // sk_PutString01("RTC Hour Interrupt",CRLF_ON);
}

//***************************************************************************
//
//
//***************************************************************************
void SK_Rtc_init(void)
{
    RTC_1_TIME_DATE  tm;
    uint8   dt;

    tm.Sec = 0;
    tm.Min = 0;
    tm.Hour = 0;
    tm.DayOfWeek = 1;
    tm.DayOfMonth = 1;
    tm.DayOfYear = 1;
    tm.Month = 1;
    tm.Year = 2023;
    
    //RTC_1_start();
    RTC_1_WriteTime(&tm);
    RTC_1_Start();
    RTC_1_Enable();
    
    RTC_1_EnableInt();
    
    dt = RTC_1_INTERVAL_SEC_MASK|RTC_1_INTERVAL_MIN_MASK |RTC_1_INTERVAL_HOUR_MASK ;
    RTC_1_WriteIntervalMask(dt);

}
//***************************************************************************
//
//
//***************************************************************************
void SK_1ms_main_loop(void)
{
    if( sk_log_flg2 & SK_LOG2_LOOP_CHK ){
        sk_log_int("MAIN LOOP 1msec ", 0);        
    }
}

void SK_10ms_main_loop(void)
{
    if( sk_log_flg2 & SK_LOG2_LOOP_CHK ){
        sk_log_int("MAIN LOOP 10msec ", 0);        
    }
}

void SK_100ms_main_loop(void)
{
    if( sk_log_flg2 & SK_LOG2_LOOP_CHK ){
        sk_log_int("MAIN LOOP 100msec ", 0);        
    }
}

void SK_1000ms_main_loop(void)
{
    if( sk_log_flg2 & SK_LOG2_LOOP_CHK ){
        sk_log_int("MAIN LOOP 100msec ", 0);        
    }
}

//  *********************************************************************************
//  
//  *********************************************************************************
void sk_mt_ctrl(uint16 flg)
{

    if( sk_log_flg5 & SK_LOG5_MT_CTRL   ){
        if( ck_mtrlog_cnt > 900   ){
                    sk_log_flg5 &= ~SK_LOG5_MT_CTRL   ;
        }
    
        switch(flg){
        case 1:
            sk_log_int("MT CTRL ", flg );
            
            sk_log_int_realT("Targetspeed1 = ",Motor_Contl4_3_U.Targetspeed1);
            sk_log_int_realT("RPM1 = ",Motor_Contl4_3_U.RPM1);
            //sk_log_int_realT("MS_LF_MAIN = ",MS_LF_MAIN[0]);
            sk_log_int_realT("VKmh1 = ",Motor_Contl4_3_Y.VKmh1);
            sk_log_int_realT("Sum = ",Motor_Contl4_3_B.Sum);
            sk_log_int_realT("PWMDuty1 = ",Motor_Contl4_3_Y.PWMDuty1);
            sk_log_int_realT("Int..CSTATE = ",Motor_Contl4_3_X.Integrator1_CSTATE);
            ck_mtrlog_cnt += 8;
            break;

        case 10:
            sk_log_int("Conti MINOR ", flg );
            sk_log_int_realT("Targetspeed1 = ",Motor_Contl4_3_U.Targetspeed1);
            sk_log_int_realT("RPM1 = ",Motor_Contl4_3_U.RPM1);
            //sk_log_int_realT("MS_LF_MAIN = ",MS_LF_MAIN[0]);
            sk_log_int_realT("VKmh1 = ",Motor_Contl4_3_Y.VKmh1);
            sk_log_int_realT("Sum = ",Motor_Contl4_3_B.Sum);
            sk_log_int_realT("PWMDuty1 = ",Motor_Contl4_3_Y.PWMDuty1);
            sk_log_int_realT("Int..CSTATE = ",Motor_Contl4_3_X.Integrator1_CSTATE);
            ck_mtrlog_cnt += 8;
            break;
        case 11:
            sk_log_int("Conti MCl4_3_step", flg );
            //sk_log_int_realT("Targetspeed1 = ",Motor_Contl4_3_U.Targetspeed1);
            //sk_log_int_realT("RPM1 = ",Motor_Contl4_3_U.RPM1);
            //sk_log_int_realT("MS_LF_MAIN = ",MS_LF_MAIN[0]);
            //sk_log_int_realT("VKmh1 = ",Motor_Contl4_3_Y.VKmh1);
            //sk_log_int_realT("Sum = ",Motor_Contl4_3_B.Sum);
            //sk_log_int_realT("WMDuty1 = ",Motor_Contl4_3_Y.PWMDuty1);
            //sk_log_int_realT("Int..CSTATE = ",Motor_Contl4_3_X.Integrator1_CSTATE);
            ck_mtrlog_cnt += 1;
            break;
        case 12:
            sk_log_int("Conti MAJOR", flg );
            sk_log_int_realT("Targetspeed1 = ",Motor_Contl4_3_U.Targetspeed1);
            sk_log_int_realT("RPM1 = ",Motor_Contl4_3_U.RPM1);
            //sk_log_int_realT("MS_LF_MAIN = ",MS_LF_MAIN[0]);
            sk_log_int_realT("VKmh1 = ",Motor_Contl4_3_Y.VKmh1);
            sk_log_int_realT("Sum = ",Motor_Contl4_3_B.Sum);
            sk_log_int_realT("PWMDuty1 = ",Motor_Contl4_3_Y.PWMDuty1);
            sk_log_int_realT("Int..CSTATE = ",Motor_Contl4_3_X.Integrator1_CSTATE);
            ck_mtrlog_cnt += 7;
            break;
        case 30:
            sk_log_int("MT CTRL START ", flg );
            sk_log_int_int16("Enc0 = ",sk_ms0_main[0]);
            sk_log_int_int16("Enc1 = ",sk_ms0_main[1]);
            sk_log_int_realT("MS_LF_MAIN = ",MS_LF_MAIN[0]);
            sk_log_int_realT("speed_lf = ",speed_lf);
            sk_log_int_realT("Targetspeed1 = ",Motor_Contl4_3_U.Targetspeed1);
            sk_log_int_realT("RPM1 = ",Motor_Contl4_3_U.RPM1);
            sk_log_int_realT("VKmh1 = ",Motor_Contl4_3_Y.VKmh1);
            sk_log_int_realT("Sum = ",Motor_Contl4_3_B.Sum);
            sk_log_int_realT("PWMDuty1 = ",Motor_Contl4_3_Y.PWMDuty1);
            sk_log_int_realT("Int..CSTATE = ",Motor_Contl4_3_X.Integrator1_CSTATE);
            ck_mtrlog_cnt += 9;
            break;
        case 31:
            //sk_log_int("MT CTRL ", flg );
            //sk_log_int("pwm_period = ",pwm_period);
         	//sk_log_int("pwm_width0 = ",pwm_width0);
            //ck_mtrlog_cnt += 3;
            break;
        default:
            sk_log_int("MT CTRL ", flg );
            ck_mtrlog_cnt += 1;
            break;
        }
        
    }
}


//  *********************************************************************************
//  
//  *********************************************************************************

void sk_pwm_debug(uint8 flg,real_T dt0,real_T dt1,real_T dt2,real_T dt3)
{
   
    if( sk_log_flg5 & SK_LOG5_MT_CTRL   ){
        if( ck_mtrlog_cnt > 900   ){
                    sk_log_flg5 &= ~SK_LOG5_MT_CTRL   ;
        }
                
        switch(flg){
        case 1:
            sk_log_int_realT("1:rtb_Sum2 = " ,dt0 );
            sk_log_int_realT("1:RPM1 = ", dt1 );
            sk_log_int_realT("1:Sum = ", dt2 );
            sk_log_int_realT("1:Targetspeed1 = ", dt3 );
            ck_mtrlog_cnt +=4;
            break;
        case 3:
            sk_log_int_realT("3:u = " ,dt0 );
            sk_log_int_realT("3:Int..CSTATE = " ,dt1 );
            sk_log_int_realT("3:PWMDuty1 = " ,dt2 );
            ck_mtrlog_cnt +=3;
            break;
        case 2:
            sk_log_int_realT("2:Int..CSTATE = ", dt0);
            sk_log_int_realT("2:Sum = ", dt1);
            sk_log_int_realT("2:Int..CSTATE_h = ", dt2);
            sk_log_int_realT("2:Sum_n = ", dt3);
            ck_mtrlog_cnt +=4;
            break;
        case 4:
            sk_log_int_realT("4:hB[0]= ", dt0 );
            sk_log_int_realT("4:h    = ", dt1 );
            sk_log_int_realT("4:rt_ODE3_B[0][0]= ", dt2 );
            ck_mtrlog_cnt +=3;
            break;
        case 5:

            sk_log_int_realT("5:x[i] = ", dt0 );
            sk_log_int_realT("5:y[i] = ", dt1 );
            sk_log_int_realT("5:f0[i]= ", dt2 );
            ck_mtrlog_cnt +=3;
            break;
        case 6:
            sk_log_int_realT("6:x[i] = ",dt0);
            sk_log_int_realT("6:y[i] = ",dt1);
            sk_log_int_realT("6:f0[i] = ",dt2);
            sk_log_int_realT("6:f1[i]) = ",dt3);
            ck_mtrlog_cnt +=4;
            break;
        case 7:
            sk_log_int_realT("7:hB[0],rt = ",dt0);
            sk_log_int_realT("7:rt_ODE3_B[1][0] = ",dt1);
            sk_log_int_realT("7:hB[1] = ",dt2);
            sk_log_int_realT("7:rt_ODE3_B[1][1]) = ",dt3);
            ck_mtrlog_cnt +=4;
            break;
        case 8:
            sk_log_int_realT("8:motor_enc0 = ",dt0);
            sk_log_int_realT("8:ms0_main[0] = ",dt1);
            sk_log_int_realT("8:encd0 = ",dt2);
            ck_mtrlog_cnt +=3;
        case 9:
            
        default:
            break;
            
        }
        
    }    
}

//  *********************************************************************************
//  Model step function 
//  *********************************************************************************

extern RT_MODEL_Motor_Contl4_3 Motor_Contl4_3_M_;

void SK_Motor_Contl4_3_step(void)
{
    real_T  rtb_Sum2;
    real_T  u;
    real_T  dt;

 
    //if (rtmIsMajorTimeStep(Motor_Contl4_3_M)) {    // if( Motor_Contl4_3_M->Timing.simTimeStep == MAJOR_TIME_STEP ){    
    //    // メジャー時間であれば時刻を設定する
    //    /* set solver stop time */
    //    // #define rtsiSetSolverStopTime(S,st) ((S)->solverStopTime = (st))
    //    rtsiSetSolverStopTime(&Motor_Contl4_3_M->solverInfo,((Motor_Contl4_3_M->Timing.clockTick0+1)*Motor_Contl4_3_M->Timing.stepSize0));
    //    
    //    // Motor_Contl4_3_M->solverInfo.solverStopTime = (((Motor_Contl4_3_M->Timing.clockTick0+1)*Motor_Contl4_3_M->Timing.stepSize0));
    //}                                  
    
    // end MajorTimeStep 

    // Update absolute time of base rate at minor time step 
    // # define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
    
    //if (rtmIsMinorTimeStep(Motor_Contl4_3_M)) {   // if(((Motor_Contl4_3_M->Timing.simTimeStep) == MINOR_TIME_STEP)){
    //    
    //    // #define rtsiGetT(S)       (*((S)->tPtr))[0]
    //    // Motor_Contl4_3_M->Timing.t[0] = (*(Motor_Contl4_3_M->solverInfo->tPtr))[0];
    //    Motor_Contl4_3_M->Timing.t[0] = rtsiGetT(&Motor_Contl4_3_M->solverInfo);
    //}
    
 

    //=======================================================================
    //
    //  Moter LF
    //
    //=======================================================================
    
    
    //=======================================================================
    //  Fcn: '<S1>/Fcn' incorporates:
    //  Inport: '<Root>/RPM1'
    //  エンコーダーのカウントすうから速度を計算
    //=======================================================================
	rtb_Sum2 = Motor_Contl4_3_U.RPM1 * rpm2velo_ratio;

    //=======================================================================
    // rtb_Sum2 = Motor_Contl4_3_U.RPM1 * 0.00033108163; //GP26A
    //  rtb_Sum2 = Motor_Contl4_3_U.RPM1 * 0.00044679337; //GP26B
    // motorRPM => velosity(Km/h)
    // = 60/gire_ratio/1000*Dwhell*pi 
    // =0.000812456 @gire_ratio = 29, Dwheel = 0.125
    // =0.000280487 @gire_ratio = 84, Dwheel = 0.125 
    // =0.00044679337 @gire_ratio = 3375.0/64(GP26B), Dwheel = 0.125 
    // =0.00033108163 @gire_ratio = 226233/3179(GP26A), Dwheel = 0.125 
    // Sum: '<S1>/Sum' incorporates:
    //  Inport: '<Root>/Target speed1'
    // 目標速度の現在の速度の差分を計算
    //=======================================================================

    Motor_Contl4_3_B.Sum = Motor_Contl4_3_U.Targetspeed1 - rtb_Sum2;

    //=======================================================================
    // Saturate: '<S1>/Saturation' incorporates:
    //  Gain: '<S1>/Gain'
    //  Gain: '<S1>/Gain2'
    //  Integrator: '<S1>/Integrator1'
    //  Sum: '<S1>/Sum2'
    //=======================================================================
    
    u = Motor_Contl4_3_P.Gain2_Gain * Motor_Contl4_3_X.Integrator1_CSTATE + Motor_Contl4_3_P.Gain_Gain * Motor_Contl4_3_B.Sum;

    /* Outport: '<Root>/PWM Duty1' incorporates:
    *  Saturate: '<S1>/Saturation'
    */
    // Motor_Contl4_3_Y.PWMDuty1 = u >= Motor_Contl4_3_P.Saturation_UpperSat ?
    // Motor_Contl4_3_P.Saturation_UpperSat : u <=
    // Motor_Contl4_3_P.Saturation_LowerSat ? Motor_Contl4_3_P.Saturation_LowerSat :
    // u;

    if( u >= Motor_Contl4_3_P.Saturation_UpperSat ){
        Motor_Contl4_3_Y.PWMDuty1 = Motor_Contl4_3_P.Saturation_UpperSat;
    }
    else if( u <= Motor_Contl4_3_P.Saturation_LowerSat){
        Motor_Contl4_3_Y.PWMDuty1  = Motor_Contl4_3_P.Saturation_LowerSat;
    }
    else{
        Motor_Contl4_3_Y.PWMDuty1 = u;
    }

    /* Outport: '<Root>/V(Km//h)1' */
    Motor_Contl4_3_Y.VKmh1 = rtb_Sum2;
    
    
    //=======================================================================
    //
    //  Moter RF
    //
    //=======================================================================
    
    /***************************************************/
    /* Fcn: '<S2>/Fcn' incorporates:
    *  Inport: '<Root>/RPM2'
    */
    /***************************************************/
    rtb_Sum2 = Motor_Contl4_3_U.RPM2 * rpm2velo_ratio;


    /* Sum: '<S2>/Sum' incorporates:
    *  Inport: '<Root>/Target speed2'
    */
    Motor_Contl4_3_B.Sum_n = Motor_Contl4_3_U.Targetspeed2 - rtb_Sum2;

    /* Saturate: '<S2>/Saturation' incorporates:
    *  Gain: '<S2>/Gain'
    *  Gain: '<S2>/Gain2'
    *  Integrator: '<S2>/Integrator1'
    *  Sum: '<S2>/Sum2'
    */
    u = Motor_Contl4_3_P.Gain2_Gain_a * Motor_Contl4_3_X.Integrator1_CSTATE_h + Motor_Contl4_3_P.Gain_Gain_a * Motor_Contl4_3_B.Sum_n;

    /* Outport: '<Root>/PWM Duty2' incorporates:
    *  Saturate: '<S2>/Saturation'
    */
    
    // Motor_Contl4_3_Y.PWMDuty2 = u >= Motor_Contl4_3_P.Saturation_UpperSat_o ?
    // Motor_Contl4_3_P.Saturation_UpperSat_o : u <=
    // Motor_Contl4_3_P.Saturation_LowerSat_j ?
    // Motor_Contl4_3_P.Saturation_LowerSat_j : u;
    
    if( u >= Motor_Contl4_3_P.Saturation_UpperSat_o ){
        Motor_Contl4_3_Y.PWMDuty2 = Motor_Contl4_3_P.Saturation_UpperSat_o;
    }
    else if(u <= Motor_Contl4_3_P.Saturation_LowerSat_j){
        Motor_Contl4_3_Y.PWMDuty2 = Motor_Contl4_3_P.Saturation_LowerSat_j;
    }
    else{
        Motor_Contl4_3_Y.PWMDuty2 = u;
    }
    

    /* Outport: '<Root>/V(Km//h)2' */
    Motor_Contl4_3_Y.VKmh2 = rtb_Sum2;
    
    //=======================================================================
    //
    //  Moter LR
    //
    //=======================================================================
    
    /***************************************************/
    /* Fcn: '<S3>/Fcn' incorporates:
    *  Inport: '<Root>/RPM3'
    */
    /***************************************************/
    rtb_Sum2 = Motor_Contl4_3_U.RPM3 * rpm2velo_ratio;


    /* Sum: '<S3>/Sum' incorporates:
    *  Inport: '<Root>/Target speed3'
    */
    Motor_Contl4_3_B.Sum_m = Motor_Contl4_3_U.Targetspeed3 - rtb_Sum2;

    /* Saturate: '<S3>/Saturation' incorporates:
    *  Gain: '<S3>/Gain'
    *  Gain: '<S3>/Gain2'
    *  Integrator: '<S3>/Integrator1'
    *  Sum: '<S3>/Sum2'
    */
    u = Motor_Contl4_3_P.Gain2_Gain_j * Motor_Contl4_3_X.Integrator1_CSTATE_l + Motor_Contl4_3_P.Gain_Gain_i * Motor_Contl4_3_B.Sum_m;

    /* Outport: '<Root>/PWM Duty3' incorporates:
    *  Saturate: '<S3>/Saturation'
    */
    // Motor_Contl4_3_Y.PWMDuty3 = u >= Motor_Contl4_3_P.Saturation_UpperSat_j ?
    // Motor_Contl4_3_P.Saturation_UpperSat_j : u <= Motor_Contl4_3_P.Saturation_LowerSat_a ?
    // Motor_Contl4_3_P.Saturation_LowerSat_a : u;

    if(u >= Motor_Contl4_3_P.Saturation_UpperSat_j ){
        Motor_Contl4_3_Y.PWMDuty3 = Motor_Contl4_3_P.Saturation_UpperSat_j;
    }
    else if(u <= Motor_Contl4_3_P.Saturation_LowerSat_a){
        Motor_Contl4_3_Y.PWMDuty3 = Motor_Contl4_3_P.Saturation_LowerSat_a;
    }
    else{
        Motor_Contl4_3_Y.PWMDuty3 = u;
    }
    
    
    /* Outport: '<Root>/V(Km//h)3' */
    Motor_Contl4_3_Y.VKmh3 = rtb_Sum2;

    //=======================================================================
    //
    //  Moter RR
    //
    //=======================================================================
    
    
    /***************************************************/
    /* Fcn: '<S4>/Fcn' incorporates:
    *  Inport: '<Root>/RPM4'
    */
    /***************************************************/

    rtb_Sum2 = Motor_Contl4_3_U.RPM4 * rpm2velo_ratio;


    /* Sum: '<S4>/Sum' incorporates:
    *  Inport: '<Root>/Target speed4'
    */
    Motor_Contl4_3_B.Sum_i = Motor_Contl4_3_U.Targetspeed4 - rtb_Sum2;

    /* Saturate: '<S4>/Saturation' incorporates:
    *  Gain: '<S4>/Gain'
    *  Gain: '<S4>/Gain2'
    *  Integrator: '<S4>/Integrator1'
    *  Sum: '<S4>/Sum2'
    */
    u = Motor_Contl4_3_P.Gain2_Gain_e * Motor_Contl4_3_X.Integrator1_CSTATE_g + Motor_Contl4_3_P.Gain_Gain_o * Motor_Contl4_3_B.Sum_i;

    /* Outport: '<Root>/PWM Duty4' incorporates:
    *  Saturate: '<S4>/Saturation'
    */
    // Motor_Contl4_3_Y.PWMDuty4 = u >= Motor_Contl4_3_P.Saturation_UpperSat_g ?
    // Motor_Contl4_3_P.Saturation_UpperSat_g : u <= Motor_Contl4_3_P.Saturation_LowerSat_l ?
    // Motor_Contl4_3_P.Saturation_LowerSat_l : u;
    
    if(u >= Motor_Contl4_3_P.Saturation_UpperSat_g){
        Motor_Contl4_3_Y.PWMDuty4 = Motor_Contl4_3_P.Saturation_UpperSat_g;
    }
    else if(u <= Motor_Contl4_3_P.Saturation_LowerSat_l){
        Motor_Contl4_3_Y.PWMDuty4 = Motor_Contl4_3_P.Saturation_LowerSat_l;
    }
    else{
        Motor_Contl4_3_Y.PWMDuty4 = u;
    }
    

    // Outport: '<Root>/V(Km//h)4' 
    Motor_Contl4_3_Y.VKmh4 = rtb_Sum2;

    /***************************************************/

    // if (rtmIsMajorTimeStep(Motor_Contl4_3_M)) {
    //     rt_ertODEUpdateContinuousStates(&Motor_Contl4_3_M->solverInfo);

    // Update absolute time for base rate */
    // The "clockTick0" counts the number of times the code of this task has
    // been executed. The absolute time is the multiplication of "clockTick0"
    // and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    // overflow during the application lifespan selected.

    //    ++Motor_Contl4_3_M->Timing.clockTick0;
    //    Motor_Contl4_3_M->Timing.t[0] = rtsiGetSolverStopTime(&Motor_Contl4_3_M->solverInfo);

    // Update absolute timer for sample time: [0.0625s, 0.0s] 
    // The "clockTick1" counts the number of times the code of this task has
    // been executed. The resolution of this integer timer is 0.0625, which is the step size
    // of the task. Size of "clockTick1" ensures timer will not overflow during the
    // application lifespan selected.

    //    Motor_Contl4_3_M->Timing.clockTick1++;

    // }                                     /* end MajorTimeStep */
}

 

/*
//現在の日付と時刻をCで出力します
int main(void)
{
    //日付と時刻のコンポーネントを格納する変数
    int hours, minutes, seconds, day, month, year;
 
    //`time_t`は算術時間タイプです
    time_t now;
 
    //現在の時刻を取得します
    // `time()`はシステムの現在の時刻を`time_t`値として返します
    time(&now);
 
    //現地時間形式に変換し、stdoutに出力します
    printf("Today is %s", ctime(&now));
 
    // localtimeは、`time_t`値をカレンダー時間に変換します
    //メンバーを含む`tm`構造体へのポインタを返します
    //対応する値で埋められます
    struct tm *local = localtime(&now);
 
    hours = local->tm_hour;         //深夜からの時間を取得します(0-23)
    minutes = local->tm_min;        //時間の後に経過した分を取得します(0-59)
    seconds = local->tm_sec;        // 1分後に経過した秒数を取得します(0-59)
 
    day = local->tm_mday;            //日を取得します(1から31)
    month = local->tm_mon + 1;      //月を取得します(0から11)
    year = local->tm_year + 1900;   //1900年から1年を取得
 
    //現地時間を印刷します
    if (hours < 12) {    // 昼前から
        printf("Time is %02d:%02d:%02d am\n", hours, minutes, seconds);
    }
    else {    //正午以降
        printf("Time is %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
    }
 
    //現在の日付を印刷します
    printf("Date is: %02d/%02d/%d\n", day, month, year);
 
    return 0;
}
*/

//************************************************
//*	Trobot3 Interrupt routine (every sub_cycle) *
//************************************************

/*
SK_CY_ISR(InterruptHandler) // 2'hfX
{
	uint8 istat_tmp ; // keep origin routine stat_sequence_code number
  
    
	// Clear Interrupt 
   	Timer_sub_cycle_STATUS;
    
	FirstLine_Write(0);
    Sonr_TRG_x4_Write(0);                                  //for sonnor 1/4 sec period
	 
    
    // last sub cycle ??
    
	if (sub_cycle_count == MAX_SUB_COUNT - 1){  // 3.9usec
        
          

        if (interruptcnt == 512 ){  //max feelds? (1/16sec 62.5msec )

            FirstLine_Write(1);
            interruptcnt = 0;
            trans_line = 0;

            if ( frame_count >=15) {
                frame_count = 0 ;        //for sonnor 1/4 sec period

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
    
    
    if (interruptcnt == 512){
        //Timer_cycle_Start();
        Timer_cycle_WriteCounter(0);
    }

    irqt1 = 2;

    //P_out_Write(sub_cycle_count) ;

    if ((sub_cycle_count % 8) == 0){    // 0.97msec
        Sub_Enc(); // 0x04 EXECUTE every 8 subcycle
    }


    // ******* UART comunication PC to Board (command) *********

    no_getcom_loop_cnt=0;
    pc2main();

    // ******* UART comunication PC to Board (command) *********

    main2pc();

    // ******* finishing operation return previous stat  *********

    pout(istat_tmp);
	
	return;
}

*/

/*

//*************************************************
//			Trobot3-V ver2 MAIN Function				
//*************************************************
	int main() 	 // 2'h1X
{
    uint8 ret;
    uint16 i ;
    uint8 j ;
    
    
    //diagnostics selftest 
    ret = SelfTest_CPU_Registers();

    // start Initialize and Initial Diagnostics 
	ret = main_init();


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


    while(1){
        switch(sub_cycle_count){
            case 10:
                McpuOP();  //2'h5X
                output2_tag[28]=state;
                output2_tag[29]=status1;
                output2_tag[30]=status0;
                Sub_Calc1();  // 2'h7X
                Set_PWM();
                irqt1 = 0;
                break;
            case 16:
                McpuOP2();
                irqt1 = 0;
                break;
            case 20:
                diag_sense();
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
}
 */

/* [] END OF FILE */
