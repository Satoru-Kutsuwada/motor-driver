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


#define MAX_LENGTH 30

typedef struct
{
    char    name[MAX_LENGTH];
} MENUE;

typedef struct
{
    uint8   pt;
    char    name[MAX_LENGTH];

} COM_PARA;


typedef enum{
    CRLF_NONE,
    CRLF_ON,
    CRLF_ONLY,
} CRLF;

extern void sk_uart_init(void);
extern void sk_PutString01(char8 *strin,CRLF flg);
extern void sk_PutString02(char8 *string,uint16 data,CRLF flg);
extern void sk_PutString06(char8 *string,uint16 data,CRLF flg);







extern void sk_log_int(char8 *string,uint16 data);

typedef enum{
    SK_LOG_SUBCYCL = 0x01,
    SK_LOG_MAX_SUB_COUNT = 0x02,
    SK_LOG_INTRUPT512 = 0x04,
    SK_LOG_SUBCYCL_8P = 0x08,
    SK_LOG_FRAME_CNT = 0x10,
    SK_LOG_CYCLE_START = 0x20,
    SK_LOG_COM_INT = 0x40,
    SK_LOG_KEISOKU_TM = 0x80,
    
    SK_LOG_FULL = 0xff
    
} LOG_FLAG;

extern LOG_FLAG sk_log_flg;

typedef enum{
    SK_LOG2_MAIN_LOOP = 0x01,
    SK_LOG2_BMP_SENS = 0x02,
    SK_LOG2_LOOP_CHK = 0x04,
    SK_LOG2_CYCLE_CNT = 0x08,
    SK_LOG2_COM_RECIVE = 0x10,
    SK_LOG2_SPI_READ = 0x20,
    SK_LOG2_SPI_SET = 0x40,
    SK_LOG2_SPI_WR = 0x80,
    
    SK_LOG2_FULL = 0xff
    
} LOG_FLAG2;
extern LOG_FLAG2 sk_log_flg2;

typedef enum{
    SK_LOG4_MT_PWM = 0x01,
    SK_LOG4_PWM_DATA = 0x02,
    SK_LOG4_ENC_DATA = 0x04,
    SK_LOG4_SUB_CALC1 = 0x08,
    SK_LOG4_MOT_START = 0x10,

    
    SK_LOG4_FULL = 0xff
    
} LOG_FLAG4;
extern LOG_FLAG4 sk_log_flg4;

typedef enum{
    SK_LOG5_PWM_CALUC = 0x01,
    SK_LOG5_MT_CTRL = 0x02,
    SK_LOG5_OUTPUT_P = 0x04,
    SK_LOG5_ENC_CNTDBG = 0x08,
    SK_LOG5_FULL = 0xff
    
} LOG_FLAG5;
extern LOG_FLAG5 sk_log_flg5;

typedef enum{
    SK_LOG2_DIST0 = 0x01,
    SK_LOG2_DIST1 = 0x02,
    SK_LOG2_DIST2 = 0x04,
    SK_LOG2_DIST3 = 0x08,
    SK_LOG2_DIST4 = 0x10,
    SK_LOG2_DIST5 = 0x20,
    SK_LOG2_DIST6 = 0x40,
    SK_LOG2_DIST7 = 0x80,
    
    SK_LOG3_FULL = 0xff
    
} LOG_FLAG3;
extern LOG_FLAG3 sk_log_flg3;


typedef enum{
    TM_ON,
    TM_OFF
} TM_FLG;


//***************************************************************************
//
//***************************************************************************
extern TM_FLG Check_0001ms(void);
extern TM_FLG Check_0010ms(void);
extern TM_FLG Check_0100ms(void);
extern TM_FLG Check_1000ms(void);





/* [] END OF FILE */
