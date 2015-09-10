/* this file was generated from the NETMAN file:
	define02.c
	06/18/14 13:17:42
*/
#define SUPER_USER
#include "petri.h"
#include "userfunc.h"
#include <stdlib.h>

#ifndef CONST_NET
#ifdef SEGMENTED_MEMORY
void DefineNet2()
{
NCTArc *parcInputs, *parcOutputs;

InitPlace( 835, "", 4, 1 );
net.place[835].number[1] = 3;
net.place[835].number[2] = 12;
net.place[835].number[3] = 2;

InitPlace( 836, "", 4, 1 );
net.place[836].number[1] = 3;
net.place[836].number[2] = 12;
net.place[836].number[3] = 3;

InitPlace( 837, "", 4, 1 );
net.place[837].number[1] = 3;
net.place[837].number[2] = 12;
net.place[837].number[3] = 5;

InitPlace( 838, "", 4, 1 );
net.place[838].number[1] = 3;
net.place[838].number[2] = 12;
net.place[838].number[3] = 6;

InitPlace( 839, "", 4, 1 );
net.place[839].number[1] = 3;
net.place[839].number[2] = 12;
net.place[839].number[3] = 7;

InitPlace( 840, "", 4, 1 );
net.place[840].number[1] = 3;
net.place[840].number[2] = 13;
net.place[840].number[3] = 0;

InitPlace( 841, "", 4, 1 );
net.place[841].number[1] = 3;
net.place[841].number[2] = 13;
net.place[841].number[3] = 1;

InitPlace( 842, "", 4, 1 );
net.place[842].number[1] = 3;
net.place[842].number[2] = 13;
net.place[842].number[3] = 2;

InitPlace( 843, "", 4, 1 );
net.place[843].number[1] = 3;
net.place[843].number[2] = 13;
net.place[843].number[3] = 3;

InitPlace( 844, "", 4, 1 );
net.place[844].number[1] = 3;
net.place[844].number[2] = 13;
net.place[844].number[3] = 5;

InitPlace( 845, "", 4, 1 );
net.place[845].number[1] = 3;
net.place[845].number[2] = 13;
net.place[845].number[3] = 6;

InitPlace( 846, "", 4, 1 );
net.place[846].number[1] = 3;
net.place[846].number[2] = 13;
net.place[846].number[3] = 7;

InitPlace( 847, "", 4, 1 );
net.place[847].number[1] = 3;
net.place[847].number[2] = 14;
net.place[847].number[3] = 0;

InitPlace( 848, "", 4, 1 );
net.place[848].number[1] = 3;
net.place[848].number[2] = 14;
net.place[848].number[3] = 1;

InitPlace( 849, "", 4, 1 );
net.place[849].number[1] = 3;
net.place[849].number[2] = 14;
net.place[849].number[3] = 2;

InitPlace( 850, "", 4, 1 );
net.place[850].number[1] = 3;
net.place[850].number[2] = 14;
net.place[850].number[3] = 3;

InitPlace( 851, "", 4, 1 );
net.place[851].number[1] = 3;
net.place[851].number[2] = 14;
net.place[851].number[3] = 5;

InitPlace( 852, "", 4, 1 );
net.place[852].number[1] = 3;
net.place[852].number[2] = 14;
net.place[852].number[3] = 6;

InitPlace( 853, "", 4, 1 );
net.place[853].number[1] = 3;
net.place[853].number[2] = 14;
net.place[853].number[3] = 7;

InitPlace( 854, "", 3, 1 );
net.place[854].number[1] = 3;
net.place[854].number[2] = 15;

InitPlace( 855, "", 4, 1 );
net.place[855].number[1] = 3;
net.place[855].number[2] = 16;
net.place[855].number[3] = 0;

InitPlace( 856, "", 4, 1 );
net.place[856].number[1] = 3;
net.place[856].number[2] = 16;
net.place[856].number[3] = 1;

InitPlace( 857, "", 4, 1 );
net.place[857].number[1] = 3;
net.place[857].number[2] = 16;
net.place[857].number[3] = 2;

InitPlace( 858, "", 4, 1 );
net.place[858].number[1] = 3;
net.place[858].number[2] = 16;
net.place[858].number[3] = 3;

InitPlace( 859, "", 4, 1 );
net.place[859].number[1] = 3;
net.place[859].number[2] = 16;
net.place[859].number[3] = 5;

InitPlace( 860, "", 4, 1 );
net.place[860].number[1] = 3;
net.place[860].number[2] = 16;
net.place[860].number[3] = 6;

InitPlace( 861, "", 4, 1 );
net.place[861].number[1] = 3;
net.place[861].number[2] = 16;
net.place[861].number[3] = 7;

InitPlace( 862, "", 3, 1 );
net.place[862].number[1] = 3;
net.place[862].number[2] = 17;

InitPlace( 863, "Y7", 4, 0 );
net.place[863].number[1] = 3;
net.place[863].number[2] = 18;
net.place[863].number[3] = 0;

InitPlace( 864, "", 4, 0 );
net.place[864].number[1] = 3;
net.place[864].number[2] = 18;
net.place[864].number[3] = 1;

InitPlace( 865, "", 4, 0 );
net.place[865].number[1] = 3;
net.place[865].number[2] = 18;
net.place[865].number[3] = 2;

InitPlace( 866, "", 4, 0 );
net.place[866].number[1] = 3;
net.place[866].number[2] = 18;
net.place[866].number[3] = 3;

InitPlace( 867, "", 4, 0 );
net.place[867].number[1] = 3;
net.place[867].number[2] = 18;
net.place[867].number[3] = 4;

InitPlace( 868, "", 4, 0 );
net.place[868].number[1] = 3;
net.place[868].number[2] = 18;
net.place[868].number[3] = 5;

InitPlace( 869, "", 4, 0 );
net.place[869].number[1] = 3;
net.place[869].number[2] = 18;
net.place[869].number[3] = 6;

InitPlace( 870, "", 4, 0 );
net.place[870].number[1] = 3;
net.place[870].number[2] = 18;
net.place[870].number[3] = 7;

InitPlace( 871, "", 4, 0 );
net.place[871].number[1] = 3;
net.place[871].number[2] = 18;
net.place[871].number[3] = 8;

InitPlace( 872, "", 4, 1 );
net.place[872].number[1] = 3;
net.place[872].number[2] = 18;
net.place[872].number[3] = 9;

InitPlace( 873, "", 4, 0 );
net.place[873].number[1] = 3;
net.place[873].number[2] = 18;
net.place[873].number[3] = 10;

InitPlace( 874, "", 4, 1 );
net.place[874].number[1] = 3;
net.place[874].number[2] = 18;
net.place[874].number[3] = 11;

InitPlace( 875, "", 4, 1 );
net.place[875].number[1] = 3;
net.place[875].number[2] = 18;
net.place[875].number[3] = 12;

InitPlace( 876, "", 4, 1 );
net.place[876].number[1] = 3;
net.place[876].number[2] = 18;
net.place[876].number[3] = 13;

InitPlace( 877, "", 4, 1 );
net.place[877].number[1] = 3;
net.place[877].number[2] = 18;
net.place[877].number[3] = 14;

InitPlace( 878, "", 4, 1 );
net.place[878].number[1] = 3;
net.place[878].number[2] = 18;
net.place[878].number[3] = 15;

InitPlace( 879, "", 4, 1 );
net.place[879].number[1] = 3;
net.place[879].number[2] = 18;
net.place[879].number[3] = 16;

InitPlace( 880, "", 4, 1 );
net.place[880].number[1] = 3;
net.place[880].number[2] = 18;
net.place[880].number[3] = 17;

InitPlace( 881, "", 4, 1 );
net.place[881].number[1] = 3;
net.place[881].number[2] = 18;
net.place[881].number[3] = 18;

InitPlace( 882, "", 4, 1 );
net.place[882].number[1] = 3;
net.place[882].number[2] = 18;
net.place[882].number[3] = 19;

InitPlace( 883, "", 4, 1 );
net.place[883].number[1] = 3;
net.place[883].number[2] = 18;
net.place[883].number[3] = 20;

InitPlace( 884, "", 4, 1 );
net.place[884].number[1] = 3;
net.place[884].number[2] = 18;
net.place[884].number[3] = 21;

InitPlace( 885, "", 4, 0 );
net.place[885].number[1] = 3;
net.place[885].number[2] = 18;
net.place[885].number[3] = 42;

InitPlace( 886, "", 4, 0 );
net.place[886].number[1] = 3;
net.place[886].number[2] = 18;
net.place[886].number[3] = 43;

InitPlace( 887, "", 4, 0 );
net.place[887].number[1] = 3;
net.place[887].number[2] = 18;
net.place[887].number[3] = 76;

InitPlace( 888, "R6", 4, 0 );
net.place[888].number[1] = 3;
net.place[888].number[2] = 18;
net.place[888].number[3] = 77;

InitPlace( 889, "GG7", 4, 0 );
net.place[889].number[1] = 3;
net.place[889].number[2] = 18;
net.place[889].number[3] = 78;

InitPlace( 890, "GR6", 4, 0 );
net.place[890].number[1] = 3;
net.place[890].number[2] = 18;
net.place[890].number[3] = 79;

InitPlace( 891, "", 4, 0 );
net.place[891].number[1] = 3;
net.place[891].number[2] = 18;
net.place[891].number[3] = 80;

InitPlace( 892, "GG6", 4, 0 );
net.place[892].number[1] = 3;
net.place[892].number[2] = 18;
net.place[892].number[3] = 83;

InitPlace( 893, "GG5", 4, 0 );
net.place[893].number[1] = 3;
net.place[893].number[2] = 18;
net.place[893].number[3] = 84;

InitPlace( 894, "GR5", 4, 0 );
net.place[894].number[1] = 3;
net.place[894].number[2] = 18;
net.place[894].number[3] = 90;

InitPlace( 895, "GG4", 4, 0 );
net.place[895].number[1] = 3;
net.place[895].number[2] = 18;
net.place[895].number[3] = 91;

InitPlace( 896, "GR4", 4, 0 );
net.place[896].number[1] = 3;
net.place[896].number[2] = 18;
net.place[896].number[3] = 92;

InitPlace( 897, "GR3", 4, 0 );
net.place[897].number[1] = 3;
net.place[897].number[2] = 18;
net.place[897].number[3] = 93;

InitPlace( 898, "GG3", 4, 0 );
net.place[898].number[1] = 3;
net.place[898].number[2] = 18;
net.place[898].number[3] = 94;

InitPlace( 899, "GR2", 4, 0 );
net.place[899].number[1] = 3;
net.place[899].number[2] = 18;
net.place[899].number[3] = 95;

InitPlace( 900, "GG2", 4, 0 );
net.place[900].number[1] = 3;
net.place[900].number[2] = 18;
net.place[900].number[3] = 96;

InitPlace( 901, "GR1", 4, 0 );
net.place[901].number[1] = 3;
net.place[901].number[2] = 18;
net.place[901].number[3] = 97;

InitPlace( 902, "GG1", 4, 0 );
net.place[902].number[1] = 3;
net.place[902].number[2] = 18;
net.place[902].number[3] = 98;

InitPlace( 903, "GR0", 4, 1 );
net.place[903].number[1] = 3;
net.place[903].number[2] = 18;
net.place[903].number[3] = 99;

InitPlace( 904, "GG0", 4, 0 );
net.place[904].number[1] = 3;
net.place[904].number[2] = 18;
net.place[904].number[3] = 100;

InitPlace( 905, "", 4, 1 );
net.place[905].number[1] = 3;
net.place[905].number[2] = 18;
net.place[905].number[3] = 101;

InitPlace( 906, "", 4, 1 );
net.place[906].number[1] = 3;
net.place[906].number[2] = 18;
net.place[906].number[3] = 102;

InitPlace( 907, "RG0", 4, 0 );
net.place[907].number[1] = 3;
net.place[907].number[2] = 18;
net.place[907].number[3] = 103;

InitPlace( 908, "M0", 4, 0 );
net.place[908].number[1] = 3;
net.place[908].number[2] = 18;
net.place[908].number[3] = 104;

InitPlace( 909, "Y0", 4, 0 );
net.place[909].number[1] = 3;
net.place[909].number[2] = 18;
net.place[909].number[3] = 105;

InitPlace( 910, "", 4, 0 );
net.place[910].number[1] = 3;
net.place[910].number[2] = 18;
net.place[910].number[3] = 106;

InitPlace( 911, "G0", 4, 0 );
net.place[911].number[1] = 3;
net.place[911].number[2] = 18;
net.place[911].number[3] = 107;

InitPlace( 912, "", 4, 1 );
net.place[912].number[1] = 3;
net.place[912].number[2] = 18;
net.place[912].number[3] = 108;

InitPlace( 913, "RG1", 4, 0 );
net.place[913].number[1] = 3;
net.place[913].number[2] = 18;
net.place[913].number[3] = 109;

InitPlace( 914, "", 4, 1 );
net.place[914].number[1] = 3;
net.place[914].number[2] = 18;
net.place[914].number[3] = 110;

InitPlace( 915, "Y1", 4, 0 );
net.place[915].number[1] = 3;
net.place[915].number[2] = 18;
net.place[915].number[3] = 111;

InitPlace( 916, "", 4, 0 );
net.place[916].number[1] = 3;
net.place[916].number[2] = 18;
net.place[916].number[3] = 112;

InitPlace( 917, "M1", 4, 0 );
net.place[917].number[1] = 3;
net.place[917].number[2] = 18;
net.place[917].number[3] = 113;

InitPlace( 918, "G1", 4, 0 );
net.place[918].number[1] = 3;
net.place[918].number[2] = 18;
net.place[918].number[3] = 114;

InitPlace( 919, "Y2", 4, 0 );
net.place[919].number[1] = 3;
net.place[919].number[2] = 18;
net.place[919].number[3] = 115;

InitPlace( 920, "", 4, 0 );
net.place[920].number[1] = 3;
net.place[920].number[2] = 18;
net.place[920].number[3] = 116;

InitPlace( 921, "M2", 4, 0 );
net.place[921].number[1] = 3;
net.place[921].number[2] = 18;
net.place[921].number[3] = 117;

InitPlace( 922, "G2", 4, 0 );
net.place[922].number[1] = 3;
net.place[922].number[2] = 18;
net.place[922].number[3] = 118;

InitPlace( 923, "", 4, 1 );
net.place[923].number[1] = 3;
net.place[923].number[2] = 18;
net.place[923].number[3] = 119;

InitPlace( 924, "RG2", 4, 0 );
net.place[924].number[1] = 3;
net.place[924].number[2] = 18;
net.place[924].number[3] = 120;

InitPlace( 925, "", 4, 1 );
net.place[925].number[1] = 3;
net.place[925].number[2] = 18;
net.place[925].number[3] = 121;

InitPlace( 926, "RG3", 4, 0 );
net.place[926].number[1] = 3;
net.place[926].number[2] = 18;
net.place[926].number[3] = 122;

InitPlace( 927, "", 4, 1 );
net.place[927].number[1] = 3;
net.place[927].number[2] = 18;
net.place[927].number[3] = 123;

InitPlace( 928, "", 4, 1 );
net.place[928].number[1] = 3;
net.place[928].number[2] = 18;
net.place[928].number[3] = 124;

InitPlace( 929, "", 4, 0 );
net.place[929].number[1] = 3;
net.place[929].number[2] = 18;
net.place[929].number[3] = 125;

InitPlace( 930, "Y3", 4, 0 );
net.place[930].number[1] = 3;
net.place[930].number[2] = 18;
net.place[930].number[3] = 126;

InitPlace( 931, "G3", 4, 0 );
net.place[931].number[1] = 3;
net.place[931].number[2] = 18;
net.place[931].number[3] = 127;

InitPlace( 932, "M3", 4, 0 );
net.place[932].number[1] = 3;
net.place[932].number[2] = 18;
net.place[932].number[3] = 128;

InitPlace( 933, "RG4", 4, 0 );
net.place[933].number[1] = 3;
net.place[933].number[2] = 18;
net.place[933].number[3] = 129;

InitPlace( 934, "", 4, 0 );
net.place[934].number[1] = 3;
net.place[934].number[2] = 18;
net.place[934].number[3] = 130;

InitPlace( 935, "Y4", 4, 0 );
net.place[935].number[1] = 3;
net.place[935].number[2] = 18;
net.place[935].number[3] = 131;

InitPlace( 936, "G4", 4, 0 );
net.place[936].number[1] = 3;
net.place[936].number[2] = 18;
net.place[936].number[3] = 132;

InitPlace( 937, "M4", 4, 0 );
net.place[937].number[1] = 3;
net.place[937].number[2] = 18;
net.place[937].number[3] = 133;

InitPlace( 938, "", 4, 1 );
net.place[938].number[1] = 3;
net.place[938].number[2] = 18;
net.place[938].number[3] = 134;

InitPlace( 939, "", 4, 1 );
net.place[939].number[1] = 3;
net.place[939].number[2] = 18;
net.place[939].number[3] = 135;

InitPlace( 940, "", 4, 1 );
net.place[940].number[1] = 3;
net.place[940].number[2] = 18;
net.place[940].number[3] = 136;

InitPlace( 941, "Y5", 4, 0 );
net.place[941].number[1] = 3;
net.place[941].number[2] = 18;
net.place[941].number[3] = 137;

InitPlace( 942, "", 4, 0 );
net.place[942].number[1] = 3;
net.place[942].number[2] = 18;
net.place[942].number[3] = 138;

InitPlace( 943, "RG5", 4, 0 );
net.place[943].number[1] = 3;
net.place[943].number[2] = 18;
net.place[943].number[3] = 139;

InitPlace( 944, "", 4, 1 );
net.place[944].number[1] = 3;
net.place[944].number[2] = 18;
net.place[944].number[3] = 140;

InitPlace( 945, "G5", 4, 0 );
net.place[945].number[1] = 3;
net.place[945].number[2] = 18;
net.place[945].number[3] = 141;

InitPlace( 946, "M5", 4, 0 );
net.place[946].number[1] = 3;
net.place[946].number[2] = 18;
net.place[946].number[3] = 142;

InitPlace( 947, "", 4, 1 );
net.place[947].number[1] = 3;
net.place[947].number[2] = 18;
net.place[947].number[3] = 143;

InitPlace( 948, "Y6", 4, 0 );
net.place[948].number[1] = 3;
net.place[948].number[2] = 18;
net.place[948].number[3] = 144;

InitPlace( 949, "", 4, 0 );
net.place[949].number[1] = 3;
net.place[949].number[2] = 18;
net.place[949].number[3] = 145;

InitPlace( 950, "G6", 4, 0 );
net.place[950].number[1] = 3;
net.place[950].number[2] = 18;
net.place[950].number[3] = 146;

InitPlace( 951, "M6", 4, 0 );
net.place[951].number[1] = 3;
net.place[951].number[2] = 18;
net.place[951].number[3] = 147;

InitPlace( 952, "RG6", 4, 0 );
net.place[952].number[1] = 3;
net.place[952].number[2] = 18;
net.place[952].number[3] = 148;

InitPlace( 953, "", 4, 1 );
net.place[953].number[1] = 3;
net.place[953].number[2] = 18;
net.place[953].number[3] = 149;

InitPlace( 954, "", 4, 0 );
net.place[954].number[1] = 3;
net.place[954].number[2] = 18;
net.place[954].number[3] = 151;

InitPlace( 955, "GR7", 4, 0 );
net.place[955].number[1] = 3;
net.place[955].number[2] = 18;
net.place[955].number[3] = 152;

InitPlace( 956, "G7", 4, 0 );
net.place[956].number[1] = 3;
net.place[956].number[2] = 18;
net.place[956].number[3] = 153;

InitPlace( 957, "", 4, 1 );
net.place[957].number[1] = 3;
net.place[957].number[2] = 18;
net.place[957].number[3] = 154;

InitPlace( 958, "", 4, 1 );
net.place[958].number[1] = 3;
net.place[958].number[2] = 18;
net.place[958].number[3] = 155;

InitPlace( 959, "M7", 4, 0 );
net.place[959].number[1] = 3;
net.place[959].number[2] = 18;
net.place[959].number[3] = 156;

InitPlace( 960, "RG7", 4, 0 );
net.place[960].number[1] = 3;
net.place[960].number[2] = 18;
net.place[960].number[3] = 157;

InitPlace( 961, "R7", 4, 0 );
net.place[961].number[1] = 3;
net.place[961].number[2] = 18;
net.place[961].number[3] = 162;

InitPlace( 962, "R5", 4, 0 );
net.place[962].number[1] = 3;
net.place[962].number[2] = 18;
net.place[962].number[3] = 163;

InitPlace( 963, "R4", 4, 0 );
net.place[963].number[1] = 3;
net.place[963].number[2] = 18;
net.place[963].number[3] = 164;

InitPlace( 964, "R3", 4, 0 );
net.place[964].number[1] = 3;
net.place[964].number[2] = 18;
net.place[964].number[3] = 165;

InitPlace( 965, "R2", 4, 0 );
net.place[965].number[1] = 3;
net.place[965].number[2] = 18;
net.place[965].number[3] = 166;

InitPlace( 966, "R1", 4, 0 );
net.place[966].number[1] = 3;
net.place[966].number[2] = 18;
net.place[966].number[3] = 167;

InitPlace( 967, "R0", 4, 0 );
net.place[967].number[1] = 3;
net.place[967].number[2] = 18;
net.place[967].number[3] = 168;

InitPlace( 968, "", 4, 0 );
net.place[968].number[1] = 3;
net.place[968].number[2] = 18;
net.place[968].number[3] = 170;

InitPlace( 969, "", 4, 0 );
net.place[969].number[1] = 3;
net.place[969].number[2] = 18;
net.place[969].number[3] = 288;

InitPlace( 970, "", 4, 0 );
net.place[970].number[1] = 3;
net.place[970].number[2] = 18;
net.place[970].number[3] = 309;

InitPlace( 971, "", 4, 0 );
net.place[971].number[1] = 3;
net.place[971].number[2] = 18;
net.place[971].number[3] = 318;

InitPlace( 972, "", 4, 0 );
net.place[972].number[1] = 3;
net.place[972].number[2] = 18;
net.place[972].number[3] = 335;

InitPlace( 973, "", 4, 0 );
net.place[973].number[1] = 3;
net.place[973].number[2] = 18;
net.place[973].number[3] = 360;

InitPlace( 974, "", 4, 0 );
net.place[974].number[1] = 3;
net.place[974].number[2] = 18;
net.place[974].number[3] = 377;

InitPlace( 975, "", 4, 0 );
net.place[975].number[1] = 3;
net.place[975].number[2] = 18;
net.place[975].number[3] = 394;

InitPlace( 976, "", 4, 0 );
net.place[976].number[1] = 3;
net.place[976].number[2] = 18;
net.place[976].number[3] = 427;

InitPlace( 977, "", 4, 0 );
net.place[977].number[1] = 3;
net.place[977].number[2] = 18;
net.place[977].number[3] = 428;

InitPlace( 978, "", 4, 0 );
net.place[978].number[1] = 3;
net.place[978].number[2] = 18;
net.place[978].number[3] = 449;

InitPlace( 979, "", 4, 0 );
net.place[979].number[1] = 3;
net.place[979].number[2] = 18;
net.place[979].number[3] = 457;

InitPlace( 980, "", 4, 0 );
net.place[980].number[1] = 3;
net.place[980].number[2] = 18;
net.place[980].number[3] = 481;

InitPlace( 981, "", 4, 0 );
net.place[981].number[1] = 3;
net.place[981].number[2] = 18;
net.place[981].number[3] = 500;

InitPlace( 982, "", 4, 0 );
net.place[982].number[1] = 3;
net.place[982].number[2] = 18;
net.place[982].number[3] = 533;

InitPlace( 983, "", 4, 0 );
net.place[983].number[1] = 3;
net.place[983].number[2] = 18;
net.place[983].number[3] = 534;

InitPlace( 984, "", 4, 0 );
net.place[984].number[1] = 3;
net.place[984].number[2] = 18;
net.place[984].number[3] = 551;

InitPlace( 985, "", 4, 0 );
net.place[985].number[1] = 3;
net.place[985].number[2] = 18;
net.place[985].number[3] = 584;

InitPlace( 986, "", 4, 0 );
net.place[986].number[1] = 3;
net.place[986].number[2] = 18;
net.place[986].number[3] = 585;

InitPlace( 987, "", 4, 0 );
net.place[987].number[1] = 3;
net.place[987].number[2] = 18;
net.place[987].number[3] = 634;

InitPlace( 988, "", 4, 0 );
net.place[988].number[1] = 3;
net.place[988].number[2] = 18;
net.place[988].number[3] = 635;

InitPlace( 989, "", 4, 0 );
net.place[989].number[1] = 3;
net.place[989].number[2] = 18;
net.place[989].number[3] = 636;

InitPlace( 990, "", 4, 0 );
net.place[990].number[1] = 3;
net.place[990].number[2] = 18;
net.place[990].number[3] = 669;

InitPlace( 991, "", 4, 0 );
net.place[991].number[1] = 3;
net.place[991].number[2] = 18;
net.place[991].number[3] = 670;

InitPlace( 992, "", 4, 0 );
net.place[992].number[1] = 3;
net.place[992].number[2] = 18;
net.place[992].number[3] = 707;

InitPlace( 993, "", 4, 0 );
net.place[993].number[1] = 3;
net.place[993].number[2] = 18;
net.place[993].number[3] = 732;

InitPlace( 994, "", 4, 0 );
net.place[994].number[1] = 3;
net.place[994].number[2] = 18;
net.place[994].number[3] = 749;

InitPlace( 995, "", 4, 0 );
net.place[995].number[1] = 3;
net.place[995].number[2] = 18;
net.place[995].number[3] = 758;

InitPlace( 996, "", 4, 0 );
net.place[996].number[1] = 3;
net.place[996].number[2] = 18;
net.place[996].number[3] = 799;

InitPlace( 997, "", 4, 0 );
net.place[997].number[1] = 3;
net.place[997].number[2] = 18;
net.place[997].number[3] = 808;

InitPlace( 998, "", 4, 0 );
net.place[998].number[1] = 3;
net.place[998].number[2] = 18;
net.place[998].number[3] = 809;

InitPlace( 999, "", 4, 0 );
net.place[999].number[1] = 3;
net.place[999].number[2] = 18;
net.place[999].number[3] = 834;

InitPlace( 1000, "", 4, 0 );
net.place[1000].number[1] = 3;
net.place[1000].number[2] = 18;
net.place[1000].number[3] = 843;

InitPlace( 1001, "", 4, 0 );
net.place[1001].number[1] = 3;
net.place[1001].number[2] = 18;
net.place[1001].number[3] = 860;

InitPlace( 1002, "", 4, 0 );
net.place[1002].number[1] = 3;
net.place[1002].number[2] = 18;
net.place[1002].number[3] = 885;

InitPlace( 1003, "", 4, 0 );
net.place[1003].number[1] = 3;
net.place[1003].number[2] = 18;
net.place[1003].number[3] = 918;

InitPlace( 1004, "", 4, 0 );
net.place[1004].number[1] = 3;
net.place[1004].number[2] = 18;
net.place[1004].number[3] = 927;

InitPlace( 1005, "", 4, 0 );
net.place[1005].number[1] = 3;
net.place[1005].number[2] = 18;
net.place[1005].number[3] = 936;

InitPlace( 1006, "", 4, 0 );
net.place[1006].number[1] = 3;
net.place[1006].number[2] = 18;
net.place[1006].number[3] = 945;

InitPlace( 1007, "", 4, 0 );
net.place[1007].number[1] = 3;
net.place[1007].number[2] = 18;
net.place[1007].number[3] = 986;

InitPlace( 1008, "", 4, 0 );
net.place[1008].number[1] = 3;
net.place[1008].number[2] = 18;
net.place[1008].number[3] = 987;

InitPlace( 1009, "", 4, 0 );
net.place[1009].number[1] = 3;
net.place[1009].number[2] = 18;
net.place[1009].number[3] = 996;

InitPlace( 1010, "", 4, 0 );
net.place[1010].number[1] = 3;
net.place[1010].number[2] = 18;
net.place[1010].number[3] = 1021;

InitPlace( 1011, "", 4, 0 );
net.place[1011].number[1] = 3;
net.place[1011].number[2] = 18;
net.place[1011].number[3] = 1030;

InitPlace( 1012, "", 4, 0 );
net.place[1012].number[1] = 3;
net.place[1012].number[2] = 18;
net.place[1012].number[3] = 1047;

InitPlace( 1013, "", 4, 0 );
net.place[1013].number[1] = 3;
net.place[1013].number[2] = 18;
net.place[1013].number[3] = 1064;

InitPlace( 1014, "", 4, 0 );
net.place[1014].number[1] = 3;
net.place[1014].number[2] = 18;
net.place[1014].number[3] = 1081;

InitPlace( 1015, "", 4, 0 );
net.place[1015].number[1] = 3;
net.place[1015].number[2] = 18;
net.place[1015].number[3] = 1098;

InitPlace( 1016, "", 4, 0 );
net.place[1016].number[1] = 3;
net.place[1016].number[2] = 18;
net.place[1016].number[3] = 1107;

InitPlace( 1017, "", 4, 0 );
net.place[1017].number[1] = 3;
net.place[1017].number[2] = 18;
net.place[1017].number[3] = 1132;

InitPlace( 1018, "", 4, 0 );
net.place[1018].number[1] = 3;
net.place[1018].number[2] = 18;
net.place[1018].number[3] = 1149;

InitPlace( 1019, "", 4, 0 );
net.place[1019].number[1] = 3;
net.place[1019].number[2] = 18;
net.place[1019].number[3] = 1166;

InitPlace( 1020, "", 3, 0 );
net.place[1020].number[1] = 3;
net.place[1020].number[2] = 19;

InitPlace( 1021, "", 3, 0 );
net.place[1021].number[1] = 3;
net.place[1021].number[2] = 20;

InitPlace( 1022, "", 3, 0 );
net.place[1022].number[1] = 3;
net.place[1022].number[2] = 21;

InitPlace( 1023, "", 3, 0 );
net.place[1023].number[1] = 3;
net.place[1023].number[2] = 22;

InitPlace( 1024, "", 3, 1 );
net.place[1024].number[1] = 3;
net.place[1024].number[2] = 23;

InitPlace( 1025, "", 3, 1 );
net.place[1025].number[1] = 3;
net.place[1025].number[2] = 24;

InitPlace( 1026, "", 3, 1 );
net.place[1026].number[1] = 3;
net.place[1026].number[2] = 169;

InitPlace( 1027, "", 3, 1 );
net.place[1027].number[1] = 3;
net.place[1027].number[2] = 172;

InitPlace( 1028, "", 3, 1 );
net.place[1028].number[1] = 3;
net.place[1028].number[2] = 175;

InitPlace( 1029, "", 3, 1 );
net.place[1029].number[1] = 3;
net.place[1029].number[2] = 177;

InitPlace( 1030, "", 3, 1 );
net.place[1030].number[1] = 3;
net.place[1030].number[2] = 179;

InitPlace( 1031, "", 3, 1 );
net.place[1031].number[1] = 3;
net.place[1031].number[2] = 180;

InitPlace( 1032, "", 3, 1 );
net.place[1032].number[1] = 3;
net.place[1032].number[2] = 181;

InitPlace( 1033, "", 3, 1 );
net.place[1033].number[1] = 3;
net.place[1033].number[2] = 182;

InitPlace( 1034, "", 3, 1 );
net.place[1034].number[1] = 3;
net.place[1034].number[2] = 183;

InitPlace( 1035, "", 3, 1 );
net.place[1035].number[1] = 3;
net.place[1035].number[2] = 184;

InitPlace( 1036, "", 3, 1 );
net.place[1036].number[1] = 3;
net.place[1036].number[2] = 185;

InitPlace( 1037, "", 3, 1 );
net.place[1037].number[1] = 3;
net.place[1037].number[2] = 186;

InitPlace( 1038, "", 3, 1 );
net.place[1038].number[1] = 3;
net.place[1038].number[2] = 187;

InitPlace( 1039, "", 3, 1 );
net.place[1039].number[1] = 3;
net.place[1039].number[2] = 188;

InitPlace( 1040, "", 3, 1 );
net.place[1040].number[1] = 3;
net.place[1040].number[2] = 189;

InitPlace( 1041, "", 3, 1 );
net.place[1041].number[1] = 3;
net.place[1041].number[2] = 190;

InitPlace( 1042, "", 3, 1 );
net.place[1042].number[1] = 3;
net.place[1042].number[2] = 193;

InitPlace( 1043, "", 3, 0 );
net.place[1043].number[1] = 3;
net.place[1043].number[2] = 197;

InitPlace( 1044, "", 3, 1 );
net.place[1044].number[1] = 3;
net.place[1044].number[2] = 198;

InitPlace( 1045, "", 3, 1 );
net.place[1045].number[1] = 3;
net.place[1045].number[2] = 199;

InitPlace( 1046, "", 3, 1 );
net.place[1046].number[1] = 3;
net.place[1046].number[2] = 200;

InitPlace( 1047, "", 3, 1 );
net.place[1047].number[1] = 3;
net.place[1047].number[2] = 209;

InitPlace( 1048, "", 3, 1 );
net.place[1048].number[1] = 3;
net.place[1048].number[2] = 210;

InitPlace( 1049, "", 3, 1 );
net.place[1049].number[1] = 3;
net.place[1049].number[2] = 211;

InitPlace( 1050, "", 3, 1 );
net.place[1050].number[1] = 3;
net.place[1050].number[2] = 212;

InitPlace( 1051, "", 3, 1 );
net.place[1051].number[1] = 3;
net.place[1051].number[2] = 213;

InitPlace( 1052, "", 3, 1 );
net.place[1052].number[1] = 3;
net.place[1052].number[2] = 214;

InitPlace( 1053, "", 3, 1 );
net.place[1053].number[1] = 3;
net.place[1053].number[2] = 217;

InitPlace( 1054, "", 3, 1 );
net.place[1054].number[1] = 3;
net.place[1054].number[2] = 218;

InitPlace( 1055, "", 3, 1 );
net.place[1055].number[1] = 3;
net.place[1055].number[2] = 221;

InitPlace( 1056, "", 3, 1 );
net.place[1056].number[1] = 3;
net.place[1056].number[2] = 229;

InitPlace( 1057, "", 3, 1 );
net.place[1057].number[1] = 3;
net.place[1057].number[2] = 232;

InitPlace( 1058, "", 3, 1 );
net.place[1058].number[1] = 3;
net.place[1058].number[2] = 233;

InitPlace( 1059, "", 3, 1 );
net.place[1059].number[1] = 3;
net.place[1059].number[2] = 234;

InitPlace( 1060, "", 3, 1 );
net.place[1060].number[1] = 3;
net.place[1060].number[2] = 237;

InitPlace( 1061, "", 3, 1 );
net.place[1061].number[1] = 3;
net.place[1061].number[2] = 238;

InitPlace( 1062, "", 3, 1 );
net.place[1062].number[1] = 3;
net.place[1062].number[2] = 239;

InitPlace( 1063, "", 3, 1 );
net.place[1063].number[1] = 3;
net.place[1063].number[2] = 242;

InitPlace( 1064, "", 3, 1 );
net.place[1064].number[1] = 3;
net.place[1064].number[2] = 252;

InitPlace( 1065, "", 3, 1 );
net.place[1065].number[1] = 3;
net.place[1065].number[2] = 253;

InitPlace( 1066, "", 3, 1 );
net.place[1066].number[1] = 3;
net.place[1066].number[2] = 254;

InitPlace( 1067, "", 3, 1 );
net.place[1067].number[1] = 3;
net.place[1067].number[2] = 255;

InitPlace( 1068, "", 2, 1 );
net.place[1068].number[1] = 4;

InitPlace( 1069, "", 2, 1 );
net.place[1069].number[1] = 5;

InitPlace( 1070, "", 2, 0 );
net.place[1070].number[1] = 6;

InitPlace( 1071, "", 2, 1 );
net.place[1071].number[1] = 7;

InitPlace( 1072, "", 2, 0 );
net.place[1072].number[1] = 8;

InitPlace( 1073, "", 3, 1 );
net.place[1073].number[1] = 9;
net.place[1073].number[2] = 0;

InitPlace( 1074, "", 3, 1 );
net.place[1074].number[1] = 9;
net.place[1074].number[2] = 1;

InitPlace( 1075, "", 3, 1 );
net.place[1075].number[1] = 9;
net.place[1075].number[2] = 2;

InitPlace( 1076, "", 4, 1 );
net.place[1076].number[1] = 9;
net.place[1076].number[2] = 3;
net.place[1076].number[3] = 0;

InitPlace( 1077, "", 4, 1 );
net.place[1077].number[1] = 9;
net.place[1077].number[2] = 3;
net.place[1077].number[3] = 1;

InitPlace( 1078, "", 4, 1 );
net.place[1078].number[1] = 9;
net.place[1078].number[2] = 3;
net.place[1078].number[3] = 2;

InitPlace( 1079, "", 4, 1 );
net.place[1079].number[1] = 9;
net.place[1079].number[2] = 3;
net.place[1079].number[3] = 3;

InitPlace( 1080, "", 4, 1 );
net.place[1080].number[1] = 9;
net.place[1080].number[2] = 3;
net.place[1080].number[3] = 5;

InitPlace( 1081, "", 4, 1 );
net.place[1081].number[1] = 9;
net.place[1081].number[2] = 3;
net.place[1081].number[3] = 6;

InitPlace( 1082, "", 4, 1 );
net.place[1082].number[1] = 9;
net.place[1082].number[2] = 3;
net.place[1082].number[3] = 7;

InitPlace( 1083, "", 3, 1 );
net.place[1083].number[1] = 9;
net.place[1083].number[2] = 4;

InitPlace( 1084, "", 4, 1 );
net.place[1084].number[1] = 9;
net.place[1084].number[2] = 8;
net.place[1084].number[3] = 0;

InitPlace( 1085, "", 4, 1 );
net.place[1085].number[1] = 9;
net.place[1085].number[2] = 8;
net.place[1085].number[3] = 1;

InitPlace( 1086, "", 4, 1 );
net.place[1086].number[1] = 9;
net.place[1086].number[2] = 8;
net.place[1086].number[3] = 2;

InitPlace( 1087, "", 4, 1 );
net.place[1087].number[1] = 9;
net.place[1087].number[2] = 8;
net.place[1087].number[3] = 3;

InitPlace( 1088, "", 4, 1 );
net.place[1088].number[1] = 9;
net.place[1088].number[2] = 8;
net.place[1088].number[3] = 5;

InitPlace( 1089, "", 4, 1 );
net.place[1089].number[1] = 9;
net.place[1089].number[2] = 8;
net.place[1089].number[3] = 6;

InitPlace( 1090, "", 4, 1 );
net.place[1090].number[1] = 9;
net.place[1090].number[2] = 8;
net.place[1090].number[3] = 7;

InitPlace( 1091, "", 4, 1 );
net.place[1091].number[1] = 9;
net.place[1091].number[2] = 10;
net.place[1091].number[3] = 0;

InitPlace( 1092, "", 4, 1 );
net.place[1092].number[1] = 9;
net.place[1092].number[2] = 10;
net.place[1092].number[3] = 1;

InitPlace( 1093, "", 4, 1 );
net.place[1093].number[1] = 9;
net.place[1093].number[2] = 10;
net.place[1093].number[3] = 2;

InitPlace( 1094, "", 4, 1 );
net.place[1094].number[1] = 9;
net.place[1094].number[2] = 10;
net.place[1094].number[3] = 3;

InitPlace( 1095, "", 4, 1 );
net.place[1095].number[1] = 9;
net.place[1095].number[2] = 10;
net.place[1095].number[3] = 5;

InitPlace( 1096, "", 4, 1 );
net.place[1096].number[1] = 9;
net.place[1096].number[2] = 10;
net.place[1096].number[3] = 6;

InitPlace( 1097, "", 4, 1 );
net.place[1097].number[1] = 9;
net.place[1097].number[2] = 10;
net.place[1097].number[3] = 7;

InitPlace( 1098, "", 4, 1 );
net.place[1098].number[1] = 9;
net.place[1098].number[2] = 11;
net.place[1098].number[3] = 0;

InitPlace( 1099, "", 4, 1 );
net.place[1099].number[1] = 9;
net.place[1099].number[2] = 11;
net.place[1099].number[3] = 1;

InitPlace( 1100, "", 4, 1 );
net.place[1100].number[1] = 9;
net.place[1100].number[2] = 11;
net.place[1100].number[3] = 2;

InitPlace( 1101, "", 4, 1 );
net.place[1101].number[1] = 9;
net.place[1101].number[2] = 11;
net.place[1101].number[3] = 3;

InitPlace( 1102, "", 4, 1 );
net.place[1102].number[1] = 9;
net.place[1102].number[2] = 11;
net.place[1102].number[3] = 5;

InitPlace( 1103, "", 4, 1 );
net.place[1103].number[1] = 9;
net.place[1103].number[2] = 11;
net.place[1103].number[3] = 6;

InitPlace( 1104, "", 4, 1 );
net.place[1104].number[1] = 9;
net.place[1104].number[2] = 11;
net.place[1104].number[3] = 7;

InitPlace( 1105, "", 4, 1 );
net.place[1105].number[1] = 9;
net.place[1105].number[2] = 12;
net.place[1105].number[3] = 0;

InitPlace( 1106, "", 4, 1 );
net.place[1106].number[1] = 9;
net.place[1106].number[2] = 12;
net.place[1106].number[3] = 1;

InitPlace( 1107, "", 4, 1 );
net.place[1107].number[1] = 9;
net.place[1107].number[2] = 12;
net.place[1107].number[3] = 2;

InitPlace( 1108, "", 4, 1 );
net.place[1108].number[1] = 9;
net.place[1108].number[2] = 12;
net.place[1108].number[3] = 3;

InitPlace( 1109, "", 4, 1 );
net.place[1109].number[1] = 9;
net.place[1109].number[2] = 12;
net.place[1109].number[3] = 5;

InitPlace( 1110, "", 4, 1 );
net.place[1110].number[1] = 9;
net.place[1110].number[2] = 12;
net.place[1110].number[3] = 6;

InitPlace( 1111, "", 4, 1 );
net.place[1111].number[1] = 9;
net.place[1111].number[2] = 12;
net.place[1111].number[3] = 7;

InitPlace( 1112, "", 4, 1 );
net.place[1112].number[1] = 9;
net.place[1112].number[2] = 13;
net.place[1112].number[3] = 0;

InitPlace( 1113, "", 4, 1 );
net.place[1113].number[1] = 9;
net.place[1113].number[2] = 13;
net.place[1113].number[3] = 1;

InitPlace( 1114, "", 4, 1 );
net.place[1114].number[1] = 9;
net.place[1114].number[2] = 13;
net.place[1114].number[3] = 2;

InitPlace( 1115, "", 4, 1 );
net.place[1115].number[1] = 9;
net.place[1115].number[2] = 13;
net.place[1115].number[3] = 3;

InitPlace( 1116, "", 4, 1 );
net.place[1116].number[1] = 9;
net.place[1116].number[2] = 13;
net.place[1116].number[3] = 5;

InitPlace( 1117, "", 4, 1 );
net.place[1117].number[1] = 9;
net.place[1117].number[2] = 13;
net.place[1117].number[3] = 6;

InitPlace( 1118, "", 4, 1 );
net.place[1118].number[1] = 9;
net.place[1118].number[2] = 13;
net.place[1118].number[3] = 7;

InitPlace( 1119, "", 4, 1 );
net.place[1119].number[1] = 9;
net.place[1119].number[2] = 14;
net.place[1119].number[3] = 0;

InitPlace( 1120, "", 4, 1 );
net.place[1120].number[1] = 9;
net.place[1120].number[2] = 14;
net.place[1120].number[3] = 1;

InitPlace( 1121, "", 4, 1 );
net.place[1121].number[1] = 9;
net.place[1121].number[2] = 14;
net.place[1121].number[3] = 2;

InitPlace( 1122, "", 4, 1 );
net.place[1122].number[1] = 9;
net.place[1122].number[2] = 14;
net.place[1122].number[3] = 3;

InitPlace( 1123, "", 4, 1 );
net.place[1123].number[1] = 9;
net.place[1123].number[2] = 14;
net.place[1123].number[3] = 5;

InitPlace( 1124, "", 4, 1 );
net.place[1124].number[1] = 9;
net.place[1124].number[2] = 14;
net.place[1124].number[3] = 6;

InitPlace( 1125, "", 4, 1 );
net.place[1125].number[1] = 9;
net.place[1125].number[2] = 14;
net.place[1125].number[3] = 7;

InitPlace( 1126, "", 3, 1 );
net.place[1126].number[1] = 9;
net.place[1126].number[2] = 15;

InitPlace( 1127, "", 4, 1 );
net.place[1127].number[1] = 9;
net.place[1127].number[2] = 16;
net.place[1127].number[3] = 0;

InitPlace( 1128, "", 4, 1 );
net.place[1128].number[1] = 9;
net.place[1128].number[2] = 16;
net.place[1128].number[3] = 1;

InitPlace( 1129, "", 4, 1 );
net.place[1129].number[1] = 9;
net.place[1129].number[2] = 16;
net.place[1129].number[3] = 2;

InitPlace( 1130, "", 4, 1 );
net.place[1130].number[1] = 9;
net.place[1130].number[2] = 16;
net.place[1130].number[3] = 3;

InitPlace( 1131, "", 4, 1 );
net.place[1131].number[1] = 9;
net.place[1131].number[2] = 16;
net.place[1131].number[3] = 5;

InitPlace( 1132, "", 4, 1 );
net.place[1132].number[1] = 9;
net.place[1132].number[2] = 16;
net.place[1132].number[3] = 6;

InitPlace( 1133, "", 4, 1 );
net.place[1133].number[1] = 9;
net.place[1133].number[2] = 16;
net.place[1133].number[3] = 7;

InitPlace( 1134, "", 3, 1 );
net.place[1134].number[1] = 9;
net.place[1134].number[2] = 17;

InitPlace( 1135, "Y7", 4, 0 );
net.place[1135].number[1] = 9;
net.place[1135].number[2] = 18;
net.place[1135].number[3] = 0;

InitPlace( 1136, "", 4, 0 );
net.place[1136].number[1] = 9;
net.place[1136].number[2] = 18;
net.place[1136].number[3] = 1;

InitPlace( 1137, "", 4, 0 );
net.place[1137].number[1] = 9;
net.place[1137].number[2] = 18;
net.place[1137].number[3] = 2;

InitPlace( 1138, "", 4, 0 );
net.place[1138].number[1] = 9;
net.place[1138].number[2] = 18;
net.place[1138].number[3] = 3;

InitPlace( 1139, "", 4, 0 );
net.place[1139].number[1] = 9;
net.place[1139].number[2] = 18;
net.place[1139].number[3] = 4;

InitPlace( 1140, "", 4, 0 );
net.place[1140].number[1] = 9;
net.place[1140].number[2] = 18;
net.place[1140].number[3] = 5;

InitPlace( 1141, "", 4, 0 );
net.place[1141].number[1] = 9;
net.place[1141].number[2] = 18;
net.place[1141].number[3] = 6;

InitPlace( 1142, "", 4, 0 );
net.place[1142].number[1] = 9;
net.place[1142].number[2] = 18;
net.place[1142].number[3] = 7;

InitPlace( 1143, "", 4, 0 );
net.place[1143].number[1] = 9;
net.place[1143].number[2] = 18;
net.place[1143].number[3] = 8;

InitPlace( 1144, "", 4, 1 );
net.place[1144].number[1] = 9;
net.place[1144].number[2] = 18;
net.place[1144].number[3] = 9;

InitPlace( 1145, "", 4, 0 );
net.place[1145].number[1] = 9;
net.place[1145].number[2] = 18;
net.place[1145].number[3] = 10;

InitPlace( 1146, "", 4, 1 );
net.place[1146].number[1] = 9;
net.place[1146].number[2] = 18;
net.place[1146].number[3] = 11;

InitPlace( 1147, "", 4, 1 );
net.place[1147].number[1] = 9;
net.place[1147].number[2] = 18;
net.place[1147].number[3] = 12;

InitPlace( 1148, "", 4, 1 );
net.place[1148].number[1] = 9;
net.place[1148].number[2] = 18;
net.place[1148].number[3] = 13;

InitPlace( 1149, "", 4, 1 );
net.place[1149].number[1] = 9;
net.place[1149].number[2] = 18;
net.place[1149].number[3] = 14;

InitPlace( 1150, "", 4, 1 );
net.place[1150].number[1] = 9;
net.place[1150].number[2] = 18;
net.place[1150].number[3] = 15;

InitPlace( 1151, "", 4, 1 );
net.place[1151].number[1] = 9;
net.place[1151].number[2] = 18;
net.place[1151].number[3] = 16;

InitPlace( 1152, "", 4, 1 );
net.place[1152].number[1] = 9;
net.place[1152].number[2] = 18;
net.place[1152].number[3] = 17;

InitPlace( 1153, "", 4, 1 );
net.place[1153].number[1] = 9;
net.place[1153].number[2] = 18;
net.place[1153].number[3] = 18;

InitPlace( 1154, "", 4, 1 );
net.place[1154].number[1] = 9;
net.place[1154].number[2] = 18;
net.place[1154].number[3] = 19;

InitPlace( 1155, "", 4, 1 );
net.place[1155].number[1] = 9;
net.place[1155].number[2] = 18;
net.place[1155].number[3] = 20;

InitPlace( 1156, "", 4, 1 );
net.place[1156].number[1] = 9;
net.place[1156].number[2] = 18;
net.place[1156].number[3] = 21;

InitPlace( 1157, "", 4, 0 );
net.place[1157].number[1] = 9;
net.place[1157].number[2] = 18;
net.place[1157].number[3] = 42;

InitPlace( 1158, "", 4, 0 );
net.place[1158].number[1] = 9;
net.place[1158].number[2] = 18;
net.place[1158].number[3] = 43;

InitPlace( 1159, "", 4, 0 );
net.place[1159].number[1] = 9;
net.place[1159].number[2] = 18;
net.place[1159].number[3] = 76;

InitPlace( 1160, "R6", 4, 0 );
net.place[1160].number[1] = 9;
net.place[1160].number[2] = 18;
net.place[1160].number[3] = 77;

InitPlace( 1161, "GG7", 4, 0 );
net.place[1161].number[1] = 9;
net.place[1161].number[2] = 18;
net.place[1161].number[3] = 78;

InitPlace( 1162, "GR6", 4, 0 );
net.place[1162].number[1] = 9;
net.place[1162].number[2] = 18;
net.place[1162].number[3] = 79;

InitPlace( 1163, "", 4, 0 );
net.place[1163].number[1] = 9;
net.place[1163].number[2] = 18;
net.place[1163].number[3] = 80;

InitPlace( 1164, "GG6", 4, 0 );
net.place[1164].number[1] = 9;
net.place[1164].number[2] = 18;
net.place[1164].number[3] = 83;

InitPlace( 1165, "GG5", 4, 0 );
net.place[1165].number[1] = 9;
net.place[1165].number[2] = 18;
net.place[1165].number[3] = 84;

InitPlace( 1166, "GR5", 4, 0 );
net.place[1166].number[1] = 9;
net.place[1166].number[2] = 18;
net.place[1166].number[3] = 90;

InitPlace( 1167, "GG4", 4, 0 );
net.place[1167].number[1] = 9;
net.place[1167].number[2] = 18;
net.place[1167].number[3] = 91;

InitPlace( 1168, "GR4", 4, 0 );
net.place[1168].number[1] = 9;
net.place[1168].number[2] = 18;
net.place[1168].number[3] = 92;

InitPlace( 1169, "GR3", 4, 0 );
net.place[1169].number[1] = 9;
net.place[1169].number[2] = 18;
net.place[1169].number[3] = 93;

InitPlace( 1170, "GG3", 4, 0 );
net.place[1170].number[1] = 9;
net.place[1170].number[2] = 18;
net.place[1170].number[3] = 94;

InitPlace( 1171, "GR2", 4, 0 );
net.place[1171].number[1] = 9;
net.place[1171].number[2] = 18;
net.place[1171].number[3] = 95;

InitPlace( 1172, "GG2", 4, 0 );
net.place[1172].number[1] = 9;
net.place[1172].number[2] = 18;
net.place[1172].number[3] = 96;

InitPlace( 1173, "GR1", 4, 0 );
net.place[1173].number[1] = 9;
net.place[1173].number[2] = 18;
net.place[1173].number[3] = 97;

InitPlace( 1174, "GG1", 4, 0 );
net.place[1174].number[1] = 9;
net.place[1174].number[2] = 18;
net.place[1174].number[3] = 98;

InitPlace( 1175, "GR0", 4, 1 );
net.place[1175].number[1] = 9;
net.place[1175].number[2] = 18;
net.place[1175].number[3] = 99;

InitPlace( 1176, "GG0", 4, 0 );
net.place[1176].number[1] = 9;
net.place[1176].number[2] = 18;
net.place[1176].number[3] = 100;

InitPlace( 1177, "", 4, 1 );
net.place[1177].number[1] = 9;
net.place[1177].number[2] = 18;
net.place[1177].number[3] = 101;

InitPlace( 1178, "", 4, 1 );
net.place[1178].number[1] = 9;
net.place[1178].number[2] = 18;
net.place[1178].number[3] = 102;

InitPlace( 1179, "RG0", 4, 0 );
net.place[1179].number[1] = 9;
net.place[1179].number[2] = 18;
net.place[1179].number[3] = 103;

InitPlace( 1180, "M0", 4, 0 );
net.place[1180].number[1] = 9;
net.place[1180].number[2] = 18;
net.place[1180].number[3] = 104;

InitPlace( 1181, "Y0", 4, 0 );
net.place[1181].number[1] = 9;
net.place[1181].number[2] = 18;
net.place[1181].number[3] = 105;

InitPlace( 1182, "", 4, 0 );
net.place[1182].number[1] = 9;
net.place[1182].number[2] = 18;
net.place[1182].number[3] = 106;

InitPlace( 1183, "G0", 4, 0 );
net.place[1183].number[1] = 9;
net.place[1183].number[2] = 18;
net.place[1183].number[3] = 107;

InitPlace( 1184, "", 4, 1 );
net.place[1184].number[1] = 9;
net.place[1184].number[2] = 18;
net.place[1184].number[3] = 108;

InitPlace( 1185, "RG1", 4, 0 );
net.place[1185].number[1] = 9;
net.place[1185].number[2] = 18;
net.place[1185].number[3] = 109;

InitPlace( 1186, "", 4, 1 );
net.place[1186].number[1] = 9;
net.place[1186].number[2] = 18;
net.place[1186].number[3] = 110;

InitPlace( 1187, "Y1", 4, 0 );
net.place[1187].number[1] = 9;
net.place[1187].number[2] = 18;
net.place[1187].number[3] = 111;

InitPlace( 1188, "", 4, 0 );
net.place[1188].number[1] = 9;
net.place[1188].number[2] = 18;
net.place[1188].number[3] = 112;

InitPlace( 1189, "M1", 4, 0 );
net.place[1189].number[1] = 9;
net.place[1189].number[2] = 18;
net.place[1189].number[3] = 113;

InitPlace( 1190, "G1", 4, 0 );
net.place[1190].number[1] = 9;
net.place[1190].number[2] = 18;
net.place[1190].number[3] = 114;

InitPlace( 1191, "Y2", 4, 0 );
net.place[1191].number[1] = 9;
net.place[1191].number[2] = 18;
net.place[1191].number[3] = 115;

InitPlace( 1192, "", 4, 0 );
net.place[1192].number[1] = 9;
net.place[1192].number[2] = 18;
net.place[1192].number[3] = 116;

InitPlace( 1193, "M2", 4, 0 );
net.place[1193].number[1] = 9;
net.place[1193].number[2] = 18;
net.place[1193].number[3] = 117;

InitPlace( 1194, "G2", 4, 0 );
net.place[1194].number[1] = 9;
net.place[1194].number[2] = 18;
net.place[1194].number[3] = 118;

InitPlace( 1195, "", 4, 1 );
net.place[1195].number[1] = 9;
net.place[1195].number[2] = 18;
net.place[1195].number[3] = 119;

InitPlace( 1196, "RG2", 4, 0 );
net.place[1196].number[1] = 9;
net.place[1196].number[2] = 18;
net.place[1196].number[3] = 120;

InitPlace( 1197, "", 4, 1 );
net.place[1197].number[1] = 9;
net.place[1197].number[2] = 18;
net.place[1197].number[3] = 121;

InitPlace( 1198, "RG3", 4, 0 );
net.place[1198].number[1] = 9;
net.place[1198].number[2] = 18;
net.place[1198].number[3] = 122;

InitPlace( 1199, "", 4, 1 );
net.place[1199].number[1] = 9;
net.place[1199].number[2] = 18;
net.place[1199].number[3] = 123;

InitPlace( 1200, "", 4, 1 );
net.place[1200].number[1] = 9;
net.place[1200].number[2] = 18;
net.place[1200].number[3] = 124;

InitPlace( 1201, "", 4, 0 );
net.place[1201].number[1] = 9;
net.place[1201].number[2] = 18;
net.place[1201].number[3] = 125;

InitPlace( 1202, "Y3", 4, 0 );
net.place[1202].number[1] = 9;
net.place[1202].number[2] = 18;
net.place[1202].number[3] = 126;

InitPlace( 1203, "G3", 4, 0 );
net.place[1203].number[1] = 9;
net.place[1203].number[2] = 18;
net.place[1203].number[3] = 127;

InitPlace( 1204, "M3", 4, 0 );
net.place[1204].number[1] = 9;
net.place[1204].number[2] = 18;
net.place[1204].number[3] = 128;

InitPlace( 1205, "RG4", 4, 0 );
net.place[1205].number[1] = 9;
net.place[1205].number[2] = 18;
net.place[1205].number[3] = 129;

InitPlace( 1206, "", 4, 0 );
net.place[1206].number[1] = 9;
net.place[1206].number[2] = 18;
net.place[1206].number[3] = 130;

InitPlace( 1207, "Y4", 4, 0 );
net.place[1207].number[1] = 9;
net.place[1207].number[2] = 18;
net.place[1207].number[3] = 131;

InitPlace( 1208, "G4", 4, 0 );
net.place[1208].number[1] = 9;
net.place[1208].number[2] = 18;
net.place[1208].number[3] = 132;

InitPlace( 1209, "M4", 4, 0 );
net.place[1209].number[1] = 9;
net.place[1209].number[2] = 18;
net.place[1209].number[3] = 133;

InitPlace( 1210, "", 4, 1 );
net.place[1210].number[1] = 9;
net.place[1210].number[2] = 18;
net.place[1210].number[3] = 134;

InitPlace( 1211, "", 4, 1 );
net.place[1211].number[1] = 9;
net.place[1211].number[2] = 18;
net.place[1211].number[3] = 135;

InitPlace( 1212, "", 4, 1 );
net.place[1212].number[1] = 9;
net.place[1212].number[2] = 18;
net.place[1212].number[3] = 136;

InitPlace( 1213, "Y5", 4, 0 );
net.place[1213].number[1] = 9;
net.place[1213].number[2] = 18;
net.place[1213].number[3] = 137;

InitPlace( 1214, "", 4, 0 );
net.place[1214].number[1] = 9;
net.place[1214].number[2] = 18;
net.place[1214].number[3] = 138;

InitPlace( 1215, "RG5", 4, 0 );
net.place[1215].number[1] = 9;
net.place[1215].number[2] = 18;
net.place[1215].number[3] = 139;

InitPlace( 1216, "", 4, 1 );
net.place[1216].number[1] = 9;
net.place[1216].number[2] = 18;
net.place[1216].number[3] = 140;

InitPlace( 1217, "G5", 4, 0 );
net.place[1217].number[1] = 9;
net.place[1217].number[2] = 18;
net.place[1217].number[3] = 141;

InitPlace( 1218, "M5", 4, 0 );
net.place[1218].number[1] = 9;
net.place[1218].number[2] = 18;
net.place[1218].number[3] = 142;

InitPlace( 1219, "", 4, 1 );
net.place[1219].number[1] = 9;
net.place[1219].number[2] = 18;
net.place[1219].number[3] = 143;

InitPlace( 1220, "Y6", 4, 0 );
net.place[1220].number[1] = 9;
net.place[1220].number[2] = 18;
net.place[1220].number[3] = 144;

InitPlace( 1221, "", 4, 0 );
net.place[1221].number[1] = 9;
net.place[1221].number[2] = 18;
net.place[1221].number[3] = 145;

InitPlace( 1222, "G6", 4, 0 );
net.place[1222].number[1] = 9;
net.place[1222].number[2] = 18;
net.place[1222].number[3] = 146;

InitPlace( 1223, "M6", 4, 0 );
net.place[1223].number[1] = 9;
net.place[1223].number[2] = 18;
net.place[1223].number[3] = 147;

InitPlace( 1224, "RG6", 4, 0 );
net.place[1224].number[1] = 9;
net.place[1224].number[2] = 18;
net.place[1224].number[3] = 148;

InitPlace( 1225, "", 4, 1 );
net.place[1225].number[1] = 9;
net.place[1225].number[2] = 18;
net.place[1225].number[3] = 149;

InitPlace( 1226, "", 4, 0 );
net.place[1226].number[1] = 9;
net.place[1226].number[2] = 18;
net.place[1226].number[3] = 151;

InitPlace( 1227, "GR7", 4, 0 );
net.place[1227].number[1] = 9;
net.place[1227].number[2] = 18;
net.place[1227].number[3] = 152;

InitPlace( 1228, "G7", 4, 0 );
net.place[1228].number[1] = 9;
net.place[1228].number[2] = 18;
net.place[1228].number[3] = 153;

InitPlace( 1229, "", 4, 1 );
net.place[1229].number[1] = 9;
net.place[1229].number[2] = 18;
net.place[1229].number[3] = 154;

InitPlace( 1230, "", 4, 1 );
net.place[1230].number[1] = 9;
net.place[1230].number[2] = 18;
net.place[1230].number[3] = 155;

InitPlace( 1231, "M7", 4, 0 );
net.place[1231].number[1] = 9;
net.place[1231].number[2] = 18;
net.place[1231].number[3] = 156;

InitPlace( 1232, "RG7", 4, 0 );
net.place[1232].number[1] = 9;
net.place[1232].number[2] = 18;
net.place[1232].number[3] = 157;

InitPlace( 1233, "R7", 4, 0 );
net.place[1233].number[1] = 9;
net.place[1233].number[2] = 18;
net.place[1233].number[3] = 162;

InitPlace( 1234, "R5", 4, 0 );
net.place[1234].number[1] = 9;
net.place[1234].number[2] = 18;
net.place[1234].number[3] = 163;

InitPlace( 1235, "R4", 4, 0 );
net.place[1235].number[1] = 9;
net.place[1235].number[2] = 18;
net.place[1235].number[3] = 164;

InitPlace( 1236, "R3", 4, 0 );
net.place[1236].number[1] = 9;
net.place[1236].number[2] = 18;
net.place[1236].number[3] = 165;

InitPlace( 1237, "R2", 4, 0 );
net.place[1237].number[1] = 9;
net.place[1237].number[2] = 18;
net.place[1237].number[3] = 166;

InitPlace( 1238, "R1", 4, 0 );
net.place[1238].number[1] = 9;
net.place[1238].number[2] = 18;
net.place[1238].number[3] = 167;

InitPlace( 1239, "R0", 4, 0 );
net.place[1239].number[1] = 9;
net.place[1239].number[2] = 18;
net.place[1239].number[3] = 168;

InitPlace( 1240, "", 4, 0 );
net.place[1240].number[1] = 9;
net.place[1240].number[2] = 18;
net.place[1240].number[3] = 170;

InitPlace( 1241, "", 4, 0 );
net.place[1241].number[1] = 9;
net.place[1241].number[2] = 18;
net.place[1241].number[3] = 288;

InitPlace( 1242, "", 4, 0 );
net.place[1242].number[1] = 9;
net.place[1242].number[2] = 18;
net.place[1242].number[3] = 309;

InitPlace( 1243, "", 4, 0 );
net.place[1243].number[1] = 9;
net.place[1243].number[2] = 18;
net.place[1243].number[3] = 318;

InitPlace( 1244, "", 4, 0 );
net.place[1244].number[1] = 9;
net.place[1244].number[2] = 18;
net.place[1244].number[3] = 335;

InitPlace( 1245, "", 4, 0 );
net.place[1245].number[1] = 9;
net.place[1245].number[2] = 18;
net.place[1245].number[3] = 360;

InitPlace( 1246, "", 4, 0 );
net.place[1246].number[1] = 9;
net.place[1246].number[2] = 18;
net.place[1246].number[3] = 377;

InitPlace( 1247, "", 4, 0 );
net.place[1247].number[1] = 9;
net.place[1247].number[2] = 18;
net.place[1247].number[3] = 394;

InitPlace( 1248, "", 4, 0 );
net.place[1248].number[1] = 9;
net.place[1248].number[2] = 18;
net.place[1248].number[3] = 427;


DefineNet3();
}
#endif /* SEGMENTED_MEMORY */
#endif /* CONST_NET */
