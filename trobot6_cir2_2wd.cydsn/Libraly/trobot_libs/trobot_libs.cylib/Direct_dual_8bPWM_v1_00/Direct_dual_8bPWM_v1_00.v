
//`#start header` -- edit after this line, do not edit this line
// ========================================
//
// Copyright YOUR COMPANY, THE YEAR
// All Rights Reserved
// UNPUBLISHED, LICENSED SOFTWARE.
//
// CONFIDENTIAL AND PROPRIETARY INFORMATION
// WHICH IS THE PROPERTY OF your company.
//
// ========================================
`include "cypress.v"
//`#end` -- edit above this line, do not edit this line
// Generated on 03/10/2014 at 12:10
// Component: Direct_dual_8bPWM_v1_00
module Direct_dual_8bPWM_v1_00 (
	output reg ah1_pwm1,
	output reg ah2_pwm2,
	output reg al1_blk1,
	output reg al2_blk2,
	output reg bh1_cw1,
	output reg bh2_cw2,
	output reg bl1,
	output reg bl2,
	output reg tc_post,
	input   blk1,
	input   blk2,
	input   clk,
	input   cw_ccw1,
	input   cw_ccw2,
	input   direct,
	input   reset
);

//`#start body` -- edit after this line, do not edit this line

//        Your code goes here

	parameter [7:0] Counter_Period = 8'd0 ;
	parameter [7:0] Compare_Value1 = 8'd0 ;
	parameter [7:0] Compare_Value2 = 8'd0 ;
	
	wire ce0, cl0, ce1, cl1 ;
    reg tc;

/*
	reg  ah1_pwm1;
	reg  ah2_pwm2;
	reg  al1_cw1;
	reg  al2_cw2;
	reg  bh1_blk1;
	reg  bh2_blk2;
	reg  bl1;
	reg  bl2;
*/

always @ (posedge clk )
begin

 ah1_pwm1 <= (~direct & cl0)|(direct & cl0 & ~cw_ccw1 & ~blk1) ;
 ah2_pwm2 <= (~direct & cl1)|(direct & cl1 & ~cw_ccw2 & ~blk2) ;
 //al1_cw1 <= (~direct & cw_ccw1)|(direct & ~(cl0 & ~cw_ccw1 & ~blk1)) ;
 //al2_cw2 <= (~direct & cw_ccw2)|(direct & ~(cl1 & ~cw_ccw2 & ~blk2)) ;
 //bh1_blk1 <= (~direct & blk1)|(direct & cl0 & cw_ccw1 & ~blk1) ;
 //bh2_blk2 <= (~direct & blk2)|(direct & cl1 & cw_ccw2 & ~blk2) ;
 bh1_cw1 <= (~direct & cw_ccw1)|(direct & cl0 & cw_ccw1 & ~blk1) ;
 bh2_cw2 <= (~direct & cw_ccw2)|(direct & cl1 & cw_ccw2 & ~blk2) ;
 al1_blk1 <= (~direct & blk1)|(direct & ~(cl0 & ~cw_ccw1 & ~blk1)) ;
 al2_blk2 <= (~direct & blk2)|(direct & ~(cl1 & ~cw_ccw2 & ~blk2)) ;
 bl1 <= direct & ~(cl0 & cw_ccw1 & ~blk1) ;
 bl2 <= direct & ~(cl1 & cw_ccw2 & ~blk2) ;
 tc_post <= tc ;
end



cy_psoc3_dp8 #(.a0_init_a(Counter_Period), .a1_init_a(Counter_Period), .d0_init_a(Compare_Value1), 
.d1_init_a(Compare_Value2), 
.cy_dpconfig_a(
{
    `CS_ALU_OP__DEC, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM0:         */
    `CS_ALU_OP__DEC, `CS_SRCA_A1, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM1:         Idle*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM2:         */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM3:         */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM4:         */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM5:         */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM6:         */
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC_NONE, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM7:         */
    8'hFF, 8'h00,  /*CFG9:         */
    8'hFF, 8'hFF,  /*CFG11-10:         */
    `SC_CMPB_A0_D1, `SC_CMPA_A0_D1, `SC_CI_B_ARITH,
    `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL,
    `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
    `SC_SI_A_DEFSI, /*CFG13-12:         */
    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
    1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
    `SC_MSB_ENBL, `SC_MSB_BIT7, `SC_MSB_NOCHN,
    `SC_FB_NOCHN, `SC_CMP1_NOCHN,
    `SC_CMP0_NOCHN, /*CFG15-14:         */
    10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
    `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
    `SC_WRK16CAT_DSBL /*CFG17-16:         */
}
)) Direct_dual_8bPWM(
        /*  input                   */  .reset(reset),
        /*  input                   */  .clk(clk),
        /*  input   [02:00]         */  .cs_addr({2'b0,tc}),
        /*  input                   */  .route_si(1'b0),
        /*  input                   */  .route_ci(1'b0),
        /*  input                   */  .f0_load(1'b0),
        /*  input                   */  .f1_load(1'b0),
        /*  input                   */  .d0_load(1'b0),
        /*  input                   */  .d1_load(1'b0),
        /*  output                  */  .ce0(ce0),
        /*  output                  */  .cl0(cl0),
        /*  output                  */  .z0(tc),
        /*  output                  */  .ff0(),
        /*  output                  */  .ce1(ce1),
        /*  output                  */  .cl1(cl1),
        /*  output                  */  .z1(),
        /*  output                  */  .ff1(),
        /*  output                  */  .ov_msb(),
        /*  output                  */  .co_msb(),
        /*  output                  */  .cmsb(),
        /*  output                  */  .so(),
        /*  output                  */  .f0_bus_stat(),
        /*  output                  */  .f0_blk_stat(),
        /*  output                  */  .f1_bus_stat(),
        /*  output                  */  .f1_blk_stat()
);
//`#end` -- edit above this line, do not edit this line
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line

