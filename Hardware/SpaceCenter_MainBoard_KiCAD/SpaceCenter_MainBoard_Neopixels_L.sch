EESchema Schematic File Version 4
LIBS:SpaceCenter_MainBoard_KiCAD-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Logic_LevelTranslator:SN74LVC2T45DCUR U?
U 1 1 5F517899
P 8600 2240
F 0 "U?" H 8950 1770 50  0000 C CNN
F 1 "SN74LVC2T45DCUR" H 9060 1670 50  0000 C CNN
F 2 "Package_SO:VSSOP-8_2.4x2.1mm_P0.5mm" H 8650 1690 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc2t45.pdf" H 7700 1690 50  0001 C CNN
	1    8600 2240
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F43F4BE
P 6150 1790
F 0 "J?" H 6190 2090 50  0000 C CNN
F 1 "Conn_01x05_Male" H 6258 2080 50  0001 C CNN
F 2 "" H 6150 1790 50  0001 C CNN
F 3 "~" H 6150 1790 50  0001 C CNN
	1    6150 1790
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F43FDCA
P 6490 1520
F 0 "#PWR?" H 6490 1370 50  0001 C CNN
F 1 "+5V" H 6505 1693 50  0000 C CNN
F 2 "" H 6490 1520 50  0001 C CNN
F 3 "" H 6490 1520 50  0001 C CNN
	1    6490 1520
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP?
U 1 1 5F441CAA
P 6500 1790
F 0 "TP?" V 6500 1978 50  0000 L CNN
F 1 "TestPoint" V 6545 1978 50  0001 L CNN
F 2 "" H 6700 1790 50  0001 C CNN
F 3 "~" H 6700 1790 50  0001 C CNN
	1    6500 1790
	0    1    1    0   
$EndComp
Text GLabel 6500 1890 2    50   Output ~ 0
CAP_TOUCH_BUTTON_L
$Comp
L power:GND #PWR?
U 1 1 5F443823
P 6500 2030
F 0 "#PWR?" H 6500 1780 50  0001 C CNN
F 1 "GND" H 6505 1857 50  0000 C CNN
F 2 "" H 6500 2030 50  0001 C CNN
F 3 "" H 6500 2030 50  0001 C CNN
	1    6500 2030
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 1990 6500 1990
Wire Wire Line
	6500 1990 6500 2030
Wire Wire Line
	6350 1890 6500 1890
Wire Wire Line
	6350 1790 6500 1790
Wire Wire Line
	6350 1590 6490 1590
Wire Wire Line
	6490 1590 6490 1520
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F446C79
P 6160 2810
F 0 "J?" H 6200 3110 50  0000 C CNN
F 1 "Conn_01x05_Male" H 6268 3100 50  0001 C CNN
F 2 "" H 6160 2810 50  0001 C CNN
F 3 "~" H 6160 2810 50  0001 C CNN
	1    6160 2810
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F446C7F
P 6500 2540
F 0 "#PWR?" H 6500 2390 50  0001 C CNN
F 1 "+5V" H 6515 2713 50  0000 C CNN
F 2 "" H 6500 2540 50  0001 C CNN
F 3 "" H 6500 2540 50  0001 C CNN
	1    6500 2540
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP?
U 1 1 5F446C86
P 6510 2810
F 0 "TP?" V 6510 2998 50  0000 L CNN
F 1 "TestPoint" V 6555 2998 50  0001 L CNN
F 2 "" H 6710 2810 50  0001 C CNN
F 3 "~" H 6710 2810 50  0001 C CNN
	1    6510 2810
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F446C8D
P 6510 3050
F 0 "#PWR?" H 6510 2800 50  0001 C CNN
F 1 "GND" H 6515 2877 50  0000 C CNN
F 2 "" H 6510 3050 50  0001 C CNN
F 3 "" H 6510 3050 50  0001 C CNN
	1    6510 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	6360 3010 6510 3010
Wire Wire Line
	6510 3010 6510 3050
Wire Wire Line
	6360 2910 6510 2910
Wire Wire Line
	6360 2810 6510 2810
Wire Wire Line
	6360 2610 6500 2610
Wire Wire Line
	6500 2610 6500 2540
Text GLabel 9170 2140 2    50   Input ~ 0
NEO_PIX_BUTTON_L
Text GLabel 9170 2340 2    50   Input ~ 0
NEO_PIX_ROCKET_L
$Comp
L Device:R R?
U 1 1 5F448037
P 7910 2140
F 0 "R?" V 7820 2140 50  0000 C CNN
F 1 "24.9" V 7910 2140 50  0000 C CNN
F 2 "" V 7840 2140 50  0001 C CNN
F 3 "~" H 7910 2140 50  0001 C CNN
	1    7910 2140
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F44897C
P 7910 2340
F 0 "R?" V 7820 2340 50  0000 C CNN
F 1 "24.9" V 7910 2340 50  0000 C CNN
F 2 "" V 7840 2340 50  0001 C CNN
F 3 "~" H 7910 2340 50  0001 C CNN
	1    7910 2340
	0    1    1    0   
$EndComp
Wire Wire Line
	7760 2140 7760 1690
Wire Wire Line
	6350 1690 7760 1690
Wire Wire Line
	7760 2340 7760 2710
Wire Wire Line
	6360 2710 7760 2710
$Comp
L power:+5V #PWR?
U 1 1 5F44DD5D
P 8500 1450
F 0 "#PWR?" H 8500 1300 50  0001 C CNN
F 1 "+5V" H 8480 1610 50  0000 C CNN
F 2 "" H 8500 1450 50  0001 C CNN
F 3 "" H 8500 1450 50  0001 C CNN
	1    8500 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8500 1450 8500 1470
$Comp
L power:+3.3V #PWR?
U 1 1 5F44ED1C
P 8700 1450
F 0 "#PWR?" H 8700 1300 50  0001 C CNN
F 1 "+3.3V" H 8710 1610 50  0000 C CNN
F 2 "" H 8700 1450 50  0001 C CNN
F 3 "" H 8700 1450 50  0001 C CNN
	1    8700 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 1450 8700 1470
$Comp
L Device:C C?
U 1 1 5F44FF5B
P 9040 1650
F 0 "C?" H 9155 1696 50  0000 L CNN
F 1 "0.1u" H 9155 1605 50  0000 L CNN
F 2 "" H 9078 1500 50  0001 C CNN
F 3 "~" H 9040 1650 50  0001 C CNN
	1    9040 1650
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F4504FC
P 8160 1640
F 0 "C?" H 8275 1686 50  0000 L CNN
F 1 "0.1u" H 8275 1595 50  0000 L CNN
F 2 "" H 8198 1490 50  0001 C CNN
F 3 "~" H 8160 1640 50  0001 C CNN
	1    8160 1640
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F450E3E
P 8160 1830
F 0 "#PWR?" H 8160 1580 50  0001 C CNN
F 1 "GND" H 8165 1657 50  0000 C CNN
F 2 "" H 8160 1830 50  0001 C CNN
F 3 "" H 8160 1830 50  0001 C CNN
	1    8160 1830
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F4524F9
P 9040 1830
F 0 "#PWR?" H 9040 1580 50  0001 C CNN
F 1 "GND" H 9045 1657 50  0000 C CNN
F 2 "" H 9040 1830 50  0001 C CNN
F 3 "" H 9040 1830 50  0001 C CNN
	1    9040 1830
	1    0    0    -1  
$EndComp
Wire Wire Line
	8160 1490 8160 1470
Wire Wire Line
	8160 1470 8500 1470
Wire Wire Line
	8160 1790 8160 1830
Wire Wire Line
	9040 1500 9040 1470
Wire Wire Line
	9040 1470 8700 1470
Wire Wire Line
	9040 1800 9040 1830
$Comp
L power:GND #PWR?
U 1 1 5F45470D
P 8600 2790
F 0 "#PWR?" H 8600 2540 50  0001 C CNN
F 1 "GND" H 8605 2617 50  0000 C CNN
F 2 "" H 8600 2790 50  0001 C CNN
F 3 "" H 8600 2790 50  0001 C CNN
	1    8600 2790
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 1740 8700 1470
Connection ~ 8700 1470
Wire Wire Line
	8500 1740 8500 1470
Connection ~ 8500 1470
Wire Wire Line
	8200 2140 8060 2140
Wire Wire Line
	8200 2340 8060 2340
Wire Wire Line
	9000 2140 9170 2140
Wire Wire Line
	9000 2340 9170 2340
Wire Wire Line
	8600 2740 8600 2790
$Comp
L power:GND #PWR?
U 1 1 5F4581CB
P 8110 2630
F 0 "#PWR?" H 8110 2380 50  0001 C CNN
F 1 "GND" H 8115 2457 50  0000 C CNN
F 2 "" H 8110 2630 50  0001 C CNN
F 3 "" H 8110 2630 50  0001 C CNN
	1    8110 2630
	1    0    0    -1  
$EndComp
Wire Wire Line
	8110 2630 8110 2540
Wire Wire Line
	8110 2540 8200 2540
Wire Notes Line
	5960 1110 5960 3310
Wire Notes Line
	5960 3310 10140 3310
Wire Notes Line
	10140 3310 10140 1110
Wire Notes Line
	10140 1110 5960 1110
Text Notes 6870 1500 0    118  ~ 0
Left Button/\nRocket
$Comp
L Logic_LevelTranslator:SN74LVC2T45DCUR U?
U 1 1 5F4661E6
P 8460 4920
F 0 "U?" H 8810 4450 50  0000 C CNN
F 1 "SN74LVC2T45DCUR" H 8920 4350 50  0000 C CNN
F 2 "Package_SO:VSSOP-8_2.4x2.1mm_P0.5mm" H 8510 4370 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc2t45.pdf" H 7560 4370 50  0001 C CNN
	1    8460 4920
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4661EC
P 1480 2040
F 0 "J?" H 1520 2340 50  0000 C CNN
F 1 "Conn_01x05_Male" H 1588 2330 50  0001 C CNN
F 2 "" H 1480 2040 50  0001 C CNN
F 3 "~" H 1480 2040 50  0001 C CNN
	1    1480 2040
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4661F2
P 1820 1770
F 0 "#PWR?" H 1820 1620 50  0001 C CNN
F 1 "+5V" H 1835 1943 50  0000 C CNN
F 2 "" H 1820 1770 50  0001 C CNN
F 3 "" H 1820 1770 50  0001 C CNN
	1    1820 1770
	1    0    0    -1  
$EndComp
Text GLabel 2040 2140 2    50   Output ~ 0
CAP_TOUCH_STAR_L_0
$Comp
L power:GND #PWR?
U 1 1 5F4661FF
P 1810 2280
F 0 "#PWR?" H 1810 2030 50  0001 C CNN
F 1 "GND" H 1815 2107 50  0000 C CNN
F 2 "" H 1810 2280 50  0001 C CNN
F 3 "" H 1810 2280 50  0001 C CNN
	1    1810 2280
	1    0    0    -1  
$EndComp
Wire Wire Line
	1680 2140 2040 2140
Wire Wire Line
	1680 1840 1820 1840
Wire Wire Line
	1820 1840 1820 1770
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F46620B
P 1390 2840
F 0 "J?" H 1430 3140 50  0000 C CNN
F 1 "Conn_01x05_Male" H 1498 3130 50  0001 C CNN
F 2 "" H 1390 2840 50  0001 C CNN
F 3 "~" H 1390 2840 50  0001 C CNN
	1    1390 2840
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F466211
P 1620 2570
F 0 "#PWR?" H 1620 2420 50  0001 C CNN
F 1 "+5V" H 1635 2743 50  0000 C CNN
F 2 "" H 1620 2570 50  0001 C CNN
F 3 "" H 1620 2570 50  0001 C CNN
	1    1620 2570
	1    0    0    -1  
$EndComp
Text GLabel 2040 2940 2    50   Output ~ 0
CAP_TOUCH_STAR_L_1
$Comp
L power:GND #PWR?
U 1 1 5F46621E
P 1640 3080
F 0 "#PWR?" H 1640 2830 50  0001 C CNN
F 1 "GND" H 1645 2907 50  0000 C CNN
F 2 "" H 1640 3080 50  0001 C CNN
F 3 "" H 1640 3080 50  0001 C CNN
	1    1640 3080
	1    0    0    -1  
$EndComp
Wire Wire Line
	1590 2940 2040 2940
Text GLabel 9030 4820 2    50   Input ~ 0
NEO_PIX_STAR_L
Text GLabel 9030 5020 2    50   Input ~ 0
NEO_PIX_STAR_R
$Comp
L Device:R R?
U 1 1 5F46622C
P 7770 4820
F 0 "R?" V 7680 4820 50  0000 C CNN
F 1 "24.9" V 7770 4820 50  0000 C CNN
F 2 "" V 7700 4820 50  0001 C CNN
F 3 "~" H 7770 4820 50  0001 C CNN
	1    7770 4820
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5F466232
P 7770 5020
F 0 "R?" V 7680 5020 50  0000 C CNN
F 1 "24.9" V 7770 5020 50  0000 C CNN
F 2 "" V 7700 5020 50  0001 C CNN
F 3 "~" H 7770 5020 50  0001 C CNN
	1    7770 5020
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F46623C
P 8360 4130
F 0 "#PWR?" H 8360 3980 50  0001 C CNN
F 1 "+5V" H 8340 4290 50  0000 C CNN
F 2 "" H 8360 4130 50  0001 C CNN
F 3 "" H 8360 4130 50  0001 C CNN
	1    8360 4130
	1    0    0    -1  
$EndComp
Wire Wire Line
	8360 4130 8360 4150
$Comp
L power:+3.3V #PWR?
U 1 1 5F466243
P 8560 4130
F 0 "#PWR?" H 8560 3980 50  0001 C CNN
F 1 "+3.3V" H 8570 4290 50  0000 C CNN
F 2 "" H 8560 4130 50  0001 C CNN
F 3 "" H 8560 4130 50  0001 C CNN
	1    8560 4130
	1    0    0    -1  
$EndComp
Wire Wire Line
	8560 4130 8560 4150
$Comp
L Device:C C?
U 1 1 5F46624A
P 8900 4330
F 0 "C?" H 9015 4376 50  0000 L CNN
F 1 "0.1u" H 9015 4285 50  0000 L CNN
F 2 "" H 8938 4180 50  0001 C CNN
F 3 "~" H 8900 4330 50  0001 C CNN
	1    8900 4330
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5F466250
P 8020 4320
F 0 "C?" H 8135 4366 50  0000 L CNN
F 1 "0.1u" H 8135 4275 50  0000 L CNN
F 2 "" H 8058 4170 50  0001 C CNN
F 3 "~" H 8020 4320 50  0001 C CNN
	1    8020 4320
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F466256
P 8020 4510
F 0 "#PWR?" H 8020 4260 50  0001 C CNN
F 1 "GND" H 8025 4337 50  0000 C CNN
F 2 "" H 8020 4510 50  0001 C CNN
F 3 "" H 8020 4510 50  0001 C CNN
	1    8020 4510
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5F46625C
P 8900 4510
F 0 "#PWR?" H 8900 4260 50  0001 C CNN
F 1 "GND" H 8905 4337 50  0000 C CNN
F 2 "" H 8900 4510 50  0001 C CNN
F 3 "" H 8900 4510 50  0001 C CNN
	1    8900 4510
	1    0    0    -1  
$EndComp
Wire Wire Line
	8020 4170 8020 4150
Wire Wire Line
	8020 4150 8360 4150
Wire Wire Line
	8020 4470 8020 4510
Wire Wire Line
	8900 4180 8900 4150
Wire Wire Line
	8900 4150 8560 4150
Wire Wire Line
	8900 4480 8900 4510
$Comp
L power:GND #PWR?
U 1 1 5F466268
P 8460 5470
F 0 "#PWR?" H 8460 5220 50  0001 C CNN
F 1 "GND" H 8465 5297 50  0000 C CNN
F 2 "" H 8460 5470 50  0001 C CNN
F 3 "" H 8460 5470 50  0001 C CNN
	1    8460 5470
	1    0    0    -1  
$EndComp
Wire Wire Line
	8560 4420 8560 4150
Connection ~ 8560 4150
Wire Wire Line
	8360 4420 8360 4150
Connection ~ 8360 4150
Wire Wire Line
	8060 4820 7920 4820
Wire Wire Line
	8060 5020 7920 5020
Wire Wire Line
	8860 4820 9030 4820
Wire Wire Line
	8860 5020 9030 5020
Wire Wire Line
	8460 5420 8460 5470
$Comp
L power:GND #PWR?
U 1 1 5F466277
P 7970 5310
F 0 "#PWR?" H 7970 5060 50  0001 C CNN
F 1 "GND" H 7975 5137 50  0000 C CNN
F 2 "" H 7970 5310 50  0001 C CNN
F 3 "" H 7970 5310 50  0001 C CNN
	1    7970 5310
	1    0    0    -1  
$EndComp
Wire Wire Line
	7970 5310 7970 5220
Wire Wire Line
	7970 5220 8060 5220
Wire Wire Line
	1680 2040 1970 2040
Wire Wire Line
	1590 2640 1620 2640
Wire Wire Line
	1620 2640 1620 2570
Wire Wire Line
	1680 2240 1810 2240
Wire Wire Line
	1810 2240 1810 2280
Wire Wire Line
	1970 2040 1970 2740
Wire Wire Line
	1590 2740 1970 2740
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F48ABA6
P 1480 3640
F 0 "J?" H 1520 3940 50  0000 C CNN
F 1 "Conn_01x05_Male" H 1588 3930 50  0001 C CNN
F 2 "" H 1480 3640 50  0001 C CNN
F 3 "~" H 1480 3640 50  0001 C CNN
	1    1480 3640
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F48ABAC
P 1820 3370
F 0 "#PWR?" H 1820 3220 50  0001 C CNN
F 1 "+5V" H 1835 3543 50  0000 C CNN
F 2 "" H 1820 3370 50  0001 C CNN
F 3 "" H 1820 3370 50  0001 C CNN
	1    1820 3370
	1    0    0    -1  
$EndComp
Text GLabel 2040 3740 2    50   Output ~ 0
CAP_TOUCH_STAR_L_2
$Comp
L power:GND #PWR?
U 1 1 5F48ABB3
P 1810 3880
F 0 "#PWR?" H 1810 3630 50  0001 C CNN
F 1 "GND" H 1815 3707 50  0000 C CNN
F 2 "" H 1810 3880 50  0001 C CNN
F 3 "" H 1810 3880 50  0001 C CNN
	1    1810 3880
	1    0    0    -1  
$EndComp
Wire Wire Line
	1680 3740 2040 3740
Wire Wire Line
	1680 3440 1820 3440
Wire Wire Line
	1820 3440 1820 3370
Wire Wire Line
	1680 3640 1970 3640
Wire Wire Line
	1680 3840 1810 3840
Wire Wire Line
	1810 3840 1810 3880
Wire Wire Line
	1590 3040 1640 3040
Wire Wire Line
	1640 3040 1640 3080
Wire Wire Line
	1590 2840 1970 2840
Wire Wire Line
	1970 2840 1970 3540
Wire Wire Line
	1970 3540 1680 3540
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4A1BAA
P 1390 4440
F 0 "J?" H 1430 4740 50  0000 C CNN
F 1 "Conn_01x05_Male" H 1498 4730 50  0001 C CNN
F 2 "" H 1390 4440 50  0001 C CNN
F 3 "~" H 1390 4440 50  0001 C CNN
	1    1390 4440
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4A1BB0
P 1620 4170
F 0 "#PWR?" H 1620 4020 50  0001 C CNN
F 1 "+5V" H 1635 4343 50  0000 C CNN
F 2 "" H 1620 4170 50  0001 C CNN
F 3 "" H 1620 4170 50  0001 C CNN
	1    1620 4170
	1    0    0    -1  
$EndComp
Text GLabel 2040 4540 2    50   Output ~ 0
CAP_TOUCH_STAR_L_3
$Comp
L power:GND #PWR?
U 1 1 5F4A1BB7
P 1640 4680
F 0 "#PWR?" H 1640 4430 50  0001 C CNN
F 1 "GND" H 1645 4507 50  0000 C CNN
F 2 "" H 1640 4680 50  0001 C CNN
F 3 "" H 1640 4680 50  0001 C CNN
	1    1640 4680
	1    0    0    -1  
$EndComp
Wire Wire Line
	1590 4540 2040 4540
Wire Wire Line
	1590 4240 1620 4240
Wire Wire Line
	1620 4240 1620 4170
Wire Wire Line
	1590 4340 1970 4340
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4A1BC2
P 1480 5240
F 0 "J?" H 1520 5540 50  0000 C CNN
F 1 "Conn_01x05_Male" H 1588 5530 50  0001 C CNN
F 2 "" H 1480 5240 50  0001 C CNN
F 3 "~" H 1480 5240 50  0001 C CNN
	1    1480 5240
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4A1BC8
P 1820 4970
F 0 "#PWR?" H 1820 4820 50  0001 C CNN
F 1 "+5V" H 1835 5143 50  0000 C CNN
F 2 "" H 1820 4970 50  0001 C CNN
F 3 "" H 1820 4970 50  0001 C CNN
	1    1820 4970
	1    0    0    -1  
$EndComp
Text GLabel 2040 5340 2    50   Output ~ 0
CAP_TOUCH_STAR_L_4
Wire Wire Line
	1680 5340 2040 5340
Wire Wire Line
	1680 5040 1820 5040
Wire Wire Line
	1820 5040 1820 4970
Wire Wire Line
	1680 5440 1810 5440
Wire Wire Line
	1590 4640 1640 4640
Wire Wire Line
	1640 4640 1640 4680
Wire Wire Line
	1590 4440 1970 4440
Wire Wire Line
	1970 4440 1970 5140
Wire Wire Line
	1970 5140 1680 5140
$Comp
L power:GND #PWR?
U 1 1 5F4DEF1B
P 1810 5510
F 0 "#PWR?" H 1810 5260 50  0001 C CNN
F 1 "GND" H 1815 5337 50  0000 C CNN
F 2 "" H 1810 5510 50  0001 C CNN
F 3 "" H 1810 5510 50  0001 C CNN
	1    1810 5510
	1    0    0    -1  
$EndComp
Wire Wire Line
	1810 5440 1810 5510
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4EFA0F
P 4730 2040
F 0 "J?" H 4770 2340 50  0000 C CNN
F 1 "Conn_01x05_Male" H 4838 2330 50  0001 C CNN
F 2 "" H 4730 2040 50  0001 C CNN
F 3 "~" H 4730 2040 50  0001 C CNN
	1    4730 2040
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4EFA15
P 4390 1770
F 0 "#PWR?" H 4390 1620 50  0001 C CNN
F 1 "+5V" H 4405 1943 50  0000 C CNN
F 2 "" H 4390 1770 50  0001 C CNN
F 3 "" H 4390 1770 50  0001 C CNN
	1    4390 1770
	-1   0    0    -1  
$EndComp
Text GLabel 4170 2140 0    50   Output ~ 0
CAP_TOUCH_STAR_L_5
$Comp
L power:GND #PWR?
U 1 1 5F4EFA1C
P 4400 2280
F 0 "#PWR?" H 4400 2030 50  0001 C CNN
F 1 "GND" H 4405 2107 50  0000 C CNN
F 2 "" H 4400 2280 50  0001 C CNN
F 3 "" H 4400 2280 50  0001 C CNN
	1    4400 2280
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4530 2140 4170 2140
Wire Wire Line
	4530 1840 4390 1840
Wire Wire Line
	4390 1840 4390 1770
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4EFA25
P 4820 2840
F 0 "J?" H 4860 3140 50  0000 C CNN
F 1 "Conn_01x05_Male" H 4928 3130 50  0001 C CNN
F 2 "" H 4820 2840 50  0001 C CNN
F 3 "~" H 4820 2840 50  0001 C CNN
	1    4820 2840
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4EFA2B
P 4590 2570
F 0 "#PWR?" H 4590 2420 50  0001 C CNN
F 1 "+5V" H 4605 2743 50  0000 C CNN
F 2 "" H 4590 2570 50  0001 C CNN
F 3 "" H 4590 2570 50  0001 C CNN
	1    4590 2570
	-1   0    0    -1  
$EndComp
Text GLabel 4170 2940 0    50   Output ~ 0
CAP_TOUCH_STAR_L_6
$Comp
L power:GND #PWR?
U 1 1 5F4EFA32
P 4570 3080
F 0 "#PWR?" H 4570 2830 50  0001 C CNN
F 1 "GND" H 4575 2907 50  0000 C CNN
F 2 "" H 4570 3080 50  0001 C CNN
F 3 "" H 4570 3080 50  0001 C CNN
	1    4570 3080
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4620 2940 4170 2940
Wire Wire Line
	4530 2040 4240 2040
Wire Wire Line
	4620 2640 4590 2640
Wire Wire Line
	4590 2640 4590 2570
Wire Wire Line
	4530 2240 4400 2240
Wire Wire Line
	4400 2240 4400 2280
Wire Wire Line
	4240 2040 4240 2740
Wire Wire Line
	4620 2740 4240 2740
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4EFA40
P 4730 3640
F 0 "J?" H 4770 3940 50  0000 C CNN
F 1 "Conn_01x05_Male" H 4838 3930 50  0001 C CNN
F 2 "" H 4730 3640 50  0001 C CNN
F 3 "~" H 4730 3640 50  0001 C CNN
	1    4730 3640
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4EFA46
P 4390 3370
F 0 "#PWR?" H 4390 3220 50  0001 C CNN
F 1 "+5V" H 4405 3543 50  0000 C CNN
F 2 "" H 4390 3370 50  0001 C CNN
F 3 "" H 4390 3370 50  0001 C CNN
	1    4390 3370
	-1   0    0    -1  
$EndComp
Text GLabel 4170 3740 0    50   Output ~ 0
CAP_TOUCH_STAR_L_7
$Comp
L power:GND #PWR?
U 1 1 5F4EFA4D
P 4400 3880
F 0 "#PWR?" H 4400 3630 50  0001 C CNN
F 1 "GND" H 4405 3707 50  0000 C CNN
F 2 "" H 4400 3880 50  0001 C CNN
F 3 "" H 4400 3880 50  0001 C CNN
	1    4400 3880
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4530 3740 4170 3740
Wire Wire Line
	4530 3440 4390 3440
Wire Wire Line
	4390 3440 4390 3370
Wire Wire Line
	4530 3640 4240 3640
Wire Wire Line
	4530 3840 4400 3840
Wire Wire Line
	4400 3840 4400 3880
Wire Wire Line
	4620 3040 4570 3040
Wire Wire Line
	4570 3040 4570 3080
Wire Wire Line
	4620 2840 4240 2840
Wire Wire Line
	4240 2840 4240 3540
Wire Wire Line
	4240 3540 4530 3540
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4EFA5E
P 4820 4440
F 0 "J?" H 4860 4740 50  0000 C CNN
F 1 "Conn_01x05_Male" H 4928 4730 50  0001 C CNN
F 2 "" H 4820 4440 50  0001 C CNN
F 3 "~" H 4820 4440 50  0001 C CNN
	1    4820 4440
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4EFA64
P 4590 4170
F 0 "#PWR?" H 4590 4020 50  0001 C CNN
F 1 "+5V" H 4605 4343 50  0000 C CNN
F 2 "" H 4590 4170 50  0001 C CNN
F 3 "" H 4590 4170 50  0001 C CNN
	1    4590 4170
	-1   0    0    -1  
$EndComp
Text GLabel 4170 4540 0    50   Output ~ 0
CAP_TOUCH_STAR_L_8
$Comp
L power:GND #PWR?
U 1 1 5F4EFA6B
P 4570 4680
F 0 "#PWR?" H 4570 4430 50  0001 C CNN
F 1 "GND" H 4575 4507 50  0000 C CNN
F 2 "" H 4570 4680 50  0001 C CNN
F 3 "" H 4570 4680 50  0001 C CNN
	1    4570 4680
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4620 4540 4170 4540
Wire Wire Line
	4620 4240 4590 4240
Wire Wire Line
	4590 4240 4590 4170
Wire Wire Line
	4620 4340 4240 4340
$Comp
L Connector:Conn_01x05_Male J?
U 1 1 5F4EFA75
P 4730 5240
F 0 "J?" H 4770 5540 50  0000 C CNN
F 1 "Conn_01x05_Male" H 4838 5530 50  0001 C CNN
F 2 "" H 4730 5240 50  0001 C CNN
F 3 "~" H 4730 5240 50  0001 C CNN
	1    4730 5240
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5F4EFA7B
P 4390 4970
F 0 "#PWR?" H 4390 4820 50  0001 C CNN
F 1 "+5V" H 4405 5143 50  0000 C CNN
F 2 "" H 4390 4970 50  0001 C CNN
F 3 "" H 4390 4970 50  0001 C CNN
	1    4390 4970
	-1   0    0    -1  
$EndComp
Text GLabel 4170 5340 0    50   Output ~ 0
CAP_TOUCH_STAR_L_9
Wire Wire Line
	4530 5340 4170 5340
Wire Wire Line
	4530 5040 4390 5040
Wire Wire Line
	4390 5040 4390 4970
Wire Wire Line
	4530 5440 4400 5440
Wire Wire Line
	4620 4640 4570 4640
Wire Wire Line
	4570 4640 4570 4680
Wire Wire Line
	4620 4440 4240 4440
Wire Wire Line
	4240 4440 4240 5140
Wire Wire Line
	4240 5140 4530 5140
$Comp
L power:GND #PWR?
U 1 1 5F4EFA8C
P 4400 5510
F 0 "#PWR?" H 4400 5260 50  0001 C CNN
F 1 "GND" H 4405 5337 50  0000 C CNN
F 2 "" H 4400 5510 50  0001 C CNN
F 3 "" H 4400 5510 50  0001 C CNN
	1    4400 5510
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4400 5440 4400 5510
Wire Wire Line
	1970 3640 1970 4340
Wire Wire Line
	3120 5240 3120 1940
Wire Wire Line
	3120 1940 4530 1940
Wire Wire Line
	1680 5240 3120 5240
Wire Wire Line
	4240 3640 4240 4340
$Comp
L Connector:TestPoint TP?
U 1 1 5F51E325
P 4470 5240
F 0 "TP?" V 4470 5480 50  0000 C CNN
F 1 "TestPoint" V 4515 5428 50  0001 L CNN
F 2 "" H 4670 5240 50  0001 C CNN
F 3 "~" H 4670 5240 50  0001 C CNN
	1    4470 5240
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4470 5240 4530 5240
$Comp
L Connector:TestPoint TP?
U 1 1 5F547E33
P 6510 2910
F 0 "TP?" V 6510 3098 50  0000 L CNN
F 1 "TestPoint" V 6555 3098 50  0001 L CNN
F 2 "" H 6710 2910 50  0001 C CNN
F 3 "~" H 6710 2910 50  0001 C CNN
	1    6510 2910
	0    1    1    0   
$EndComp
Text Label 6590 1690 0    50   ~ 0
NEO_PIX_BUTTON_L_5V
Text Label 6600 2710 0    50   ~ 0
NEO_PIX_ROCKET_L_5V
Text GLabel 7420 4820 0    50   Output ~ 0
NEO_PIX_STAR_L_5V
Text GLabel 7430 5020 0    50   Output ~ 0
NEO_PIX_STAR_R_5V
Wire Wire Line
	7420 4820 7620 4820
Wire Wire Line
	7430 5020 7620 5020
Wire Notes Line
	6300 3700 6300 5790
Wire Notes Line
	6300 5790 10010 5790
Wire Notes Line
	10010 5790 10010 3700
Wire Notes Line
	10010 3700 6300 3700
Text Notes 6420 4150 0    118  ~ 0
L/R Star\nLevel Translator
Text GLabel 2040 1940 2    50   Input ~ 0
NEO_PIX_STAR_L_5V
Wire Wire Line
	2040 1940 1680 1940
Wire Notes Line
	1300 1190 1300 5900
Wire Notes Line
	1300 5900 4990 5900
Wire Notes Line
	4990 5900 4990 1190
Wire Notes Line
	4990 1190 1300 1190
Text Notes 2250 1480 0    118  ~ 0
Left Star Connectors
$EndSCHEMATC