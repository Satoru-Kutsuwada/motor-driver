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

#include "sk_source.h"

uint8 CharConv[16]={
  /* 0    1    2    3    4    5    6    7    8    9    R */
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
    'a', 'b', 'c', 'd', 'e', 'f'
};

//**********************************************
//
//
//**********************************************

void sk_uart_init(void)
{
    DEB_UART_Start();
    sk_PutString01("UART START2222",CRLF_ON);
}
//**********************************************
//
//
//**********************************************
void sk_log(char8 *string)
{
            DEB_UART_PutString(string);
            DEB_UART_PutCRLF(1);
}

//**********************************************
//
//
//**********************************************
void sk_PutString01(char8 *string,CRLF flg){
    
    switch(flg){
        case CRLF_NONE:
            DEB_UART_PutString(string);
            break;
        case CRLF_ON:
            DEB_UART_PutString(string);
            DEB_UART_PutCRLF(1);
            break;
        case CRLF_ONLY:
            DEB_UART_PutCRLF(1);
            break;
        default:
            break;
    }

}
//**********************************************
//
//
//**********************************************
void sk_PutString02(char8 *string,uint16 data,CRLF flg){
    char buf[10];
    
    switch(flg){
        case CRLF_NONE:
            itoa(data,buf,10);
            DEB_UART_PutString(string);
            DEB_UART_PutString(buf);
            break;
        case CRLF_ON:
            itoa(data,buf,10);
            DEB_UART_PutString(string);
            DEB_UART_PutString(buf);
            DEB_UART_PutCRLF(1);
            break;
        case CRLF_ONLY:
            DEB_UART_PutCRLF(1);
            break;
        default:
            break;
    }

}
//**********************************************
//
//
//**********************************************
void sk_PutString03(char8 *string,uint16 data,CRLF flg,uint8 kata){
    char buf[10];
    
    switch(flg){
        case CRLF_NONE:
            itoa(data,buf,kata);
            DEB_UART_PutString(string);
            DEB_UART_PutString(buf);
            break;
        case CRLF_ON:
            itoa(data,buf,kata);
            DEB_UART_PutString(string);
            DEB_UART_PutString(buf);
            DEB_UART_PutCRLF(1);
            break;
        case CRLF_ONLY:
            DEB_UART_PutCRLF(1);
            break;
        default:
            break;
    }
}
//**********************************************
//
//
//**********************************************
void sk_PutString04(char8 *string,uint16 data,CRLF flg){
    char buf[10];
    
    itoa(data,buf,10);
    DEB_UART_PutString(string);
    DEB_UART_PutString(buf);
    
    itoa(data,buf,16);
    DEB_UART_PutString("(0x");
    DEB_UART_PutString(buf);
    DEB_UART_PutString(")");
    
    if(flg == CRLF_ON){
           DEB_UART_PutCRLF(1);
     }
     
}
//**********************************************
//
//
//**********************************************
void sk_PutString06(char8 *string,uint16 data,CRLF flg){
    char buf[10];
    uint16 dt;
    
    
    if( data <= 32767 ){
        itoa(data,buf,10);
        DEB_UART_PutString(string);
        DEB_UART_PutString(buf);
        
        itoa(data,buf,16);
        DEB_UART_PutString("(0x");
        DEB_UART_PutString(buf);
        DEB_UART_PutString(")");
        
        if(flg == CRLF_ON){
               DEB_UART_PutCRLF(1);
         }
    }
    else{
        dt = 0xffff - data; 
        dt ++;
        buf[0] = '-';
        itoa(dt,&buf[1],10);
        DEB_UART_PutString(string);
        DEB_UART_PutString(buf);
        
        itoa(data,buf,16);
        DEB_UART_PutString("(0x");
        DEB_UART_PutString(buf);
        DEB_UART_PutString(")");
        
        if(flg == CRLF_ON){
               DEB_UART_PutCRLF(1);
         }
    }
    
     
}
//**********************************************
//
//
//**********************************************
void sk_int32toChar(char8 *string,int32 data)
{
    
    char buf[15];
    uint32 dt,dt2,i;
    uint8 j;
    uint8 flg = 0;
    uint16 dt16;
    
    dt = (uint32)data;
    
    // dt16 = (uint16)(0x0000ffff & data);
    // sk_PutString03("dt16(L)= 0x",dt16,CRLF_ON,16);
    // dt16 = (uint16)(data >> 16);
    // sk_PutString03("dt16(H)= 0x",dt16,CRLF_ON,16);
    
    j = 0;
    if( dt <= 2147483647 ){
        dt2=dt;
        for( i=1000000000; i>=1; i/=10 ){
            dt = dt / i;
            if( dt != 0 ){
                flg = 1;
                *string = CharConv[dt];
                string ++;
            }
            else if(( i==1 )||(flg==1)){
                *string = CharConv[0];
                string ++;
            }
            dt = dt2 - dt*i;
            dt2 = dt;
        }
        
    }
    else{

        dt = 0xffffffff - dt; 
        dt ++;
        dt2=dt;
        *string = '-';
        string ++;
     
        
        for( i=1000000000; i>=1; i/=10 ){
            dt = dt / i;
            if( dt != 0 ){
                flg = 1;
                *string = CharConv[dt];
                string ++;
            }
            else if(( i==1 )||(flg==1)){
                *string = CharConv[0];
                string ++;
            }
            dt = dt2 - dt*i;
            dt2 = dt;
        }
        
    }
    
    *string = NULL;
    
}
//**********************************************
//
//
//**********************************************
void sk_int16toChar(char8 *string,int16 data)
{
    
    char buf[15];
    uint16 dt,dt2,i;
    uint8 j;
    uint8 flg = 0;

    
    dt = data;
    
 
    
    j = 0;
    if( dt <= 32767 ){
        dt2=dt;
        for( i=10000; i>=1; i/=10 ){
            dt = dt / i;
            if( dt != 0 ){
                flg = 1;
                *string = CharConv[dt];
                string ++;
            }
            else if(( i==1 )||(flg==1)){
                *string = CharConv[0];
                string ++;
            }
            dt = dt2 - dt*i;
            dt2 = dt;
        }
        
    }
    else{

        dt = 0xffff - dt; 
        dt ++;
        dt2=dt;
        *string = '-';
        string ++;
     
        
        for( i=10000; i>=1; i/=10 ){
            dt = dt / i;
            if( dt != 0 ){
                flg = 1;
                *string = CharConv[dt];
                string ++;
            }
            else if(( i==1 )||(flg==1)){
                *string = CharConv[0];
                string ++;
            }
            dt = dt2 - dt*i;
            dt2 = dt;
        }
        
    }
    
    *string = NULL;
    
}
//**********************************************
//
//
//**********************************************
void sk_int8toChar(char8 *string,int8 data)
{
    
    char buf[15];
    uint8 dt,dt2,i;
    uint8 j;
    uint8 flg = 0;

    
    dt = (uint8)data;
    
 
    
    j = 0;
    if( dt <= 127 ){
        dt2=dt;
        for( i=100; i>=1; i/=10 ){
            dt = dt / i;
            if( dt != 0 ){
                flg = 1;
                *string = CharConv[dt];
                string ++;
            }
            else if(( i==1 )||(flg==1)){
                *string = CharConv[0];
                string ++;
            }
            dt = dt2 - dt*i;
            dt2 = dt;
        }
        
    }
    else{

        dt = 0xffff - dt; 
        dt ++;
        dt2=dt;
        *string = '-';
        string ++;
     
        
        for( i=100; i>=1; i/=10 ){
            dt = dt / i;
            if( dt != 0 ){
                flg = 1;
                *string = CharConv[dt];
                string ++;
            }
            else if(( i==1 )||(flg==1)){
                *string = CharConv[0];
                string ++;
            }
            dt = dt2 - dt*i;
            dt2 = dt;
        }
        
    }
    
    *string = NULL;
    
}
//**********************************************
//
//
//**********************************************
void sk_PutString_uint32(char8 *string,uint32 data)
{
    uint16 dt;
    
    char buf[20];
    
    DEB_UART_PutString(string);
    
    dt = (uint16)(data >> 16);
    itoa(dt,buf,16);
    DEB_UART_PutString(buf);
    
    dt = (uint16)data;
    itoa(dt,buf,16);
    DEB_UART_PutString(buf);
    
    DEB_UART_PutCRLF(1);
}

//**********************************************
//
//
//**********************************************
void sk_PutString_int32(char8 *string,int32 data)
{
    char buf[20];
    DEB_UART_PutString(string);
    sk_int32toChar(buf,data);
    DEB_UART_PutString(buf);
    DEB_UART_PutCRLF(1);
}
//**********************************************
//
//
//**********************************************
void sk_PutString_int16(char8 *string,int16 data)
{
    char buf[20];
    DEB_UART_PutString(string);
    sk_int16toChar(buf,data);
    DEB_UART_PutString(buf);
    DEB_UART_PutCRLF(1);
}
//**********************************************
//
//
//**********************************************
void sk_PutString_int8(char8 *string,int8 data)
{
    char buf[20];
    DEB_UART_PutString(string);
    sk_int8toChar(buf,data);
    DEB_UART_PutString(buf);
    DEB_UART_PutCRLF(1);
}

//**********************************************
//
//
//**********************************************
void sk_PutString05(char8 *string,uint16 data1,uint16 data2,uint16 data3,uint16 data4)
{
    char buf[20];
    uint16 dt0;
    uint16 dt1;
    uint16 i,j,k;
    

    
    for( k=0; k<4; k++ ){
        switch(k){
            case 0:
                dt0 = dt1 = data1;
                break;
            case 1:
                dt0 = dt1 = data2;
                break;
            case 2:
                dt0 = dt1 = data3;
                break;
            case 3:
                dt0 = dt1 = data4;
                break;
            default:
                break;
        }
        
        for(i=0; i<6; i++ ){
            dt0 /= 10;
            if( dt0 == 0 ){
                i++;
                break;
            }
        }
        
        switch(i){
        
        case 5:
            dt0 = dt1 / 10000;
            dt1 = dt1 - 10000*dt0;
            buf[j] = CharConv[dt0];
            j++;

        case 4:
            dt0 = dt1 / 1000;
            dt1 = dt1 - 1000*dt0;
            buf[j] = CharConv[dt0];
            j++;
        case 3:
            dt0 = dt1 / 100;
            dt1 = dt1 - 100*dt0;
            buf[j] = CharConv[dt0];
            j++;
        case 2:
            dt0 = dt1 / 10;
            dt1 = dt1 - 10*dt0;
            buf[j] = CharConv[dt0];
            j++;
        case 1:
            dt0 = dt1 ;
            buf[j] = CharConv[dt0];
            j++;
            buf[j]=':';
            j++;
            break;
        default:
            buf[j]='-';
            j++;
            break;
        }
        buf[j]=NULL;
        
    }
    DEB_UART_PutString(string);
    DEB_UART_PutString(buf);
    DEB_UART_PutCRLF(1);
    
    
}
//**********************************************
//
//
//**********************************************
 
uint8 SK_GetChar_uart(void)
{
    return(DEB_UART_GetChar());
}

/* [] END OF FILE */
