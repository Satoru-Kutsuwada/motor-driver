# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\TIRI\k3g2pmpm_20211223\trobot_psoc_v6_73\trobot6_cir2_2wd.cydsn\trobot6_cir2_2wd.cyprj
# Date: Mon, 13 Mar 2023 08:25:23 GMT
#set_units -time ns
create_clock -name {ADC_SAR_1_theACLK(routed)} -period 625 -waveform {0 312.5} [list [get_pins {ClockBlock/dclk_3}]]
create_clock -name {CyXTAL_32kHz} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/clk_32k_xtal}]]
create_clock -name {CyXTAL} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 15.625 -waveform {0 7.8125} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {SPIM_1_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 9 17} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_generated_clock -name {SPIM_2_IntClock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 33 65} [list [get_pins {ClockBlock/dclk_glb_2}]]
create_generated_clock -name {ADC_SAR_1_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 41 81} [list [get_pins {ClockBlock/dclk_glb_3}]]
create_generated_clock -name {timer_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 3 5} -nominal_period 41.666666666666664 [list [get_pins {ClockBlock/dclk_glb_0}]]
create_clock -name {timer_clock(fixed-function)} -period 31.25 -waveform {0 15.625} -nominal_period 41.666666666666664 [get_pins {ClockBlock/dclk_glb_ff_0}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\TIRI\k3g2pmpm_20211223\trobot_psoc_v6_73\trobot6_cir2_2wd.cydsn\TopDesign\TopDesign.cysch
# Project: C:\TIRI\k3g2pmpm_20211223\trobot_psoc_v6_73\trobot6_cir2_2wd.cydsn\trobot6_cir2_2wd.cyprj
# Date: Mon, 13 Mar 2023 08:25:15 GMT
