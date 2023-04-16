
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
// Generated on 12/13/2013 at 18:31
// Component: motor_enc_v1_3
module motor_enc_v1_3 (
	input   a,
	input   b,
	input   clk,
	input   re_load,
	input   reset
);

//`#start body` -- edit after this line, do not edit this line
//unused Datapath Connections
	wire carry, tc_lsb, cmp_lsb ;
	
//        Your code goes here
	reg down_pulse;
	reg up_pulse;
	reg re_load_pulse;

	reg a_sync; 
	reg b_sync; 
	reg re_load_sync;
//	reg re_load_sync2;
	reg a_sync_c; 
	reg b_sync_c; 
	reg re_load_sync_c;

 	reg a1; 
 	reg b1; 
 	reg a2; 
 	reg b2; 
 	reg a3; 
 	reg b3; 

	reg re_load1;
	reg re_load2;

	always @ (posedge clk)
	begin
		a1 <= a ;
		a2 <= a1 ;
		a3 <= a2 ;
		a_sync <= a_sync_c;
		
		b1 <= b ;
		b2 <= b1 ;
		b3 <= b2 ;
		b_sync <= b_sync_c;

		re_load1 <= re_load;
		re_load2 <= re_load1;
		re_load_sync <= re_load_sync_c;
//		re_load_sync2 <= re_load_sync;

		up_pulse <= (a_sync ^ b_sync_c) & ~(b_sync ^ a_sync_c);
		down_pulse <= ~(a_sync ^ b_sync_c) & (b_sync ^ a_sync_c);
		re_load_pulse <= (~re_load_sync & re_load_sync_c) ;
//		re_load_pulse <= (~re_load_sync & re_load_sync_c) | (~re_load_sync2 & re_load_sync) ;

//		down_pulse_w <= down_pulse;
//		up_pulse_w <= up_pulse;
//		re_load_pulse_w <= re_load_pulse;
	
	end

	always @ (a or a1 or a2 or a3 or a_sync)
	begin
		a_sync_c = (a1 | a2 | a3)&(a_sync | (a1 & a2 & a3));
	end

	always @ (b or b1 or b2 or b3 or b_sync)

	begin
		b_sync_c = (b1 | b2 | b3)&(b_sync | (b1 & b2 & b3));
	end

	always @ (re_load or re_load1 or re_load2 or re_load_sync)

	begin
		re_load_sync_c = (re_load1 | re_load2)&(re_load_sync | (re_load1 & re_load2));
	end

//`#end` -- edit above this line, do not edit this line


cy_psoc3_dp16 #(.cy_dpconfig_a(
{
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM0:       noOP*/
    `CS_ALU_OP__INC, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM1:       up_pulse*/
    `CS_ALU_OP__DEC, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM2:       down_pulse*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM3:       noOP*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM4:       re_load_pulse*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM5:       re_load_pulse*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM6:       re_load_pulse*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM7:       re_load_pulse*/
    8'hFF, 8'h00,  /*CFG9:        */
    8'hFF, 8'hFF,  /*CFG11-10:        */
    `SC_CMPB_A1_D1, `SC_CMPA_A1_D1, `SC_CI_B_ARITH,
    `SC_CI_A_ARITH, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL,
    `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
    `SC_SI_A_DEFSI, /*CFG13-12:        */
    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
    1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
    `SC_MSB_DSBL, `SC_MSB_BIT0, `SC_MSB_NOCHN,
    `SC_FB_NOCHN, `SC_CMP1_NOCHN,
    `SC_CMP0_NOCHN, /*CFG15-14:        */
    10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
    `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
    `SC_WRK16CAT_DSBL /*CFG17-16:        */
}
), .cy_dpconfig_b(
{
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM0:       noOP*/
    `CS_ALU_OP__INC, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM1:       up_pulse for MSB*/
    `CS_ALU_OP__DEC, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM2:       down_pulse for MSB*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC__ALU, `CS_A1_SRC_NONE,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM3:       noOP*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM4:       re_load_pulse*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM5:       re_load_pulse*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM6:       re_load_pulse*/
    `CS_ALU_OP_PASS, `CS_SRCA_A0, `CS_SRCB_D0,
    `CS_SHFT_OP_PASS, `CS_A0_SRC___D0, `CS_A1_SRC__ALU,
    `CS_FEEDBACK_DSBL, `CS_CI_SEL_CFGA, `CS_SI_SEL_CFGA,
    `CS_CMP_SEL_CFGA, /*CFGRAM7:       re_load_pulse*/
    8'hFF, 8'h00,  /*CFG9:        */
    8'hFF, 8'hFF,  /*CFG11-10:        */
    `SC_CMPB_A1_D1, `SC_CMPA_A1_D1, `SC_CI_B_CHAIN,
    `SC_CI_A_CHAIN, `SC_C1_MASK_DSBL, `SC_C0_MASK_DSBL,
    `SC_A_MASK_DSBL, `SC_DEF_SI_0, `SC_SI_B_DEFSI,
    `SC_SI_A_DEFSI, /*CFG13-12:        */
    `SC_A0_SRC_ACC, `SC_SHIFT_SL, 1'h0,
    1'h0, `SC_FIFO1_BUS, `SC_FIFO0_BUS,
    `SC_MSB_DSBL, `SC_MSB_BIT0, `SC_MSB_NOCHN,
    `SC_FB_NOCHN, `SC_CMP1_CHNED,
    `SC_CMP0_CHNED, /*CFG15-14:        */
    10'h00, `SC_FIFO_CLK__DP,`SC_FIFO_CAP_AX,
    `SC_FIFO_LEVEL,`SC_FIFO__SYNC,`SC_EXTCRC_DSBL,
    `SC_WRK16CAT_DSBL /*CFG17-16:        */
}
)) motor_enc(
        /*  input                   */  .reset(reset),
        /*  input                   */  .clk(clk),
        /*  input   [02:00]         */  .cs_addr({re_load_pulse,down_pulse,up_pulse}),
        /*  input                   */  .route_si(1'b0),
        /*  input                   */  .route_ci(1'b0),
        /*  input                   */  .f0_load(1'b0),
        /*  input                   */  .f1_load(1'b0),
        /*  input                   */  .d0_load(1'b0),
        /*  input                   */  .d1_load(1'b0),
        /*  output  [01:00]                  */  .ce0(),
        /*  output  [01:00]                  */  .cl0(),
        /*  output  [01:00]                  */  .z0(),
        /*  output  [01:00]                  */  .ff0(),
        /*  output  [01:00]                  */  .ce1(),
        /*  output  [01:00]                  */  .cl1(),
        /*  output  [01:00]                  */  .z1(),
        /*  output  [01:00]                  */  .ff1(),
        /*  output  [01:00]                  */  .ov_msb(),
        /*  output  [01:00]                  */  .co_msb(),
        /*  output  [01:00]                  */  .cmsb(),
        /*  output  [01:00]                  */  .so(),
        /*  output  [01:00]                  */  .f0_bus_stat(),
        /*  output  [01:00]                  */  .f0_blk_stat(),
        /*  output  [01:00]                  */  .f1_bus_stat(),
        /*  output  [01:00]                  */  .f1_blk_stat()
);
endmodule
//`#start footer` -- edit after this line, do not edit this line
//`#end` -- edit above this line, do not edit this line








