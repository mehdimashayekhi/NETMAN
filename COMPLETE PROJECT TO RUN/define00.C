/* this file was generated from the NETMAN file:
	define00.c
	07/09/98 15:09:11
*/
#define SUPER_USER
#include "petri.h"
#include "userfunc.h"
#include <stdlib.h>

#ifndef CONST_NET
#ifdef SEGMENTED_MEMORY
void DefineNet()
{
NCTArc *parcInputs, *parcOutputs;

DimensionNet( 1790, 1986 );

InitPlace( 0, "", 3, PlacePolicy(1) );
net.place[0].number[1] = 0;
net.place[0].number[2] = 0;

InitPlace( 1, "", 3, PlacePolicy(1) );
net.place[1].number[1] = 0;
net.place[1].number[2] = 1;

InitPlace( 2, "", 3, PlacePolicy(1) );
net.place[2].number[1] = 0;
net.place[2].number[2] = 2;

InitPlace( 3, "", 4, PlacePolicy(1) );
net.place[3].number[1] = 0;
net.place[3].number[2] = 3;
net.place[3].number[3] = 0;

InitPlace( 4, "", 4, PlacePolicy(1) );
net.place[4].number[1] = 0;
net.place[4].number[2] = 3;
net.place[4].number[3] = 1;

InitPlace( 5, "", 4, PlacePolicy(1) );
net.place[5].number[1] = 0;
net.place[5].number[2] = 3;
net.place[5].number[3] = 2;

InitPlace( 6, "", 4, PlacePolicy(1) );
net.place[6].number[1] = 0;
net.place[6].number[2] = 3;
net.place[6].number[3] = 3;

InitPlace( 7, "", 4, PlacePolicy(1) );
net.place[7].number[1] = 0;
net.place[7].number[2] = 3;
net.place[7].number[3] = 5;

InitPlace( 8, "", 4, PlacePolicy(1) );
net.place[8].number[1] = 0;
net.place[8].number[2] = 3;
net.place[8].number[3] = 6;

InitPlace( 9, "", 4, PlacePolicy(1) );
net.place[9].number[1] = 0;
net.place[9].number[2] = 3;
net.place[9].number[3] = 7;

InitPlace( 10, "", 3, PlacePolicy(1) );
net.place[10].number[1] = 0;
net.place[10].number[2] = 4;

InitPlace( 11, "", 4, PlacePolicy(1) );
net.place[11].number[1] = 0;
net.place[11].number[2] = 8;
net.place[11].number[3] = 0;

InitPlace( 12, "", 4, PlacePolicy(1) );
net.place[12].number[1] = 0;
net.place[12].number[2] = 8;
net.place[12].number[3] = 1;

InitPlace( 13, "", 4, PlacePolicy(1) );
net.place[13].number[1] = 0;
net.place[13].number[2] = 8;
net.place[13].number[3] = 2;

InitPlace( 14, "", 4, PlacePolicy(1) );
net.place[14].number[1] = 0;
net.place[14].number[2] = 8;
net.place[14].number[3] = 3;

InitPlace( 15, "", 4, PlacePolicy(1) );
net.place[15].number[1] = 0;
net.place[15].number[2] = 8;
net.place[15].number[3] = 5;

InitPlace( 16, "", 4, PlacePolicy(1) );
net.place[16].number[1] = 0;
net.place[16].number[2] = 8;
net.place[16].number[3] = 6;

InitPlace( 17, "", 4, PlacePolicy(1) );
net.place[17].number[1] = 0;
net.place[17].number[2] = 8;
net.place[17].number[3] = 7;

InitPlace( 18, "", 4, PlacePolicy(1) );
net.place[18].number[1] = 0;
net.place[18].number[2] = 10;
net.place[18].number[3] = 0;

InitPlace( 19, "", 4, PlacePolicy(1) );
net.place[19].number[1] = 0;
net.place[19].number[2] = 10;
net.place[19].number[3] = 1;

InitPlace( 20, "", 4, PlacePolicy(1) );
net.place[20].number[1] = 0;
net.place[20].number[2] = 10;
net.place[20].number[3] = 2;

InitPlace( 21, "", 4, PlacePolicy(1) );
net.place[21].number[1] = 0;
net.place[21].number[2] = 10;
net.place[21].number[3] = 3;

InitPlace( 22, "", 4, PlacePolicy(1) );
net.place[22].number[1] = 0;
net.place[22].number[2] = 10;
net.place[22].number[3] = 5;

InitPlace( 23, "", 4, PlacePolicy(1) );
net.place[23].number[1] = 0;
net.place[23].number[2] = 10;
net.place[23].number[3] = 6;

InitPlace( 24, "", 4, PlacePolicy(1) );
net.place[24].number[1] = 0;
net.place[24].number[2] = 10;
net.place[24].number[3] = 7;

InitPlace( 25, "", 4, PlacePolicy(1) );
net.place[25].number[1] = 0;
net.place[25].number[2] = 11;
net.place[25].number[3] = 0;

InitPlace( 26, "", 4, PlacePolicy(1) );
net.place[26].number[1] = 0;
net.place[26].number[2] = 11;
net.place[26].number[3] = 1;

InitPlace( 27, "", 4, PlacePolicy(1) );
net.place[27].number[1] = 0;
net.place[27].number[2] = 11;
net.place[27].number[3] = 2;

InitPlace( 28, "", 4, PlacePolicy(1) );
net.place[28].number[1] = 0;
net.place[28].number[2] = 11;
net.place[28].number[3] = 3;

InitPlace( 29, "", 4, PlacePolicy(1) );
net.place[29].number[1] = 0;
net.place[29].number[2] = 11;
net.place[29].number[3] = 5;

InitPlace( 30, "", 4, PlacePolicy(1) );
net.place[30].number[1] = 0;
net.place[30].number[2] = 11;
net.place[30].number[3] = 6;

InitPlace( 31, "", 4, PlacePolicy(1) );
net.place[31].number[1] = 0;
net.place[31].number[2] = 11;
net.place[31].number[3] = 7;

InitPlace( 32, "", 4, PlacePolicy(1) );
net.place[32].number[1] = 0;
net.place[32].number[2] = 12;
net.place[32].number[3] = 0;

InitPlace( 33, "", 4, PlacePolicy(1) );
net.place[33].number[1] = 0;
net.place[33].number[2] = 12;
net.place[33].number[3] = 1;

InitPlace( 34, "", 4, PlacePolicy(1) );
net.place[34].number[1] = 0;
net.place[34].number[2] = 12;
net.place[34].number[3] = 2;

InitPlace( 35, "", 4, PlacePolicy(1));
net.place[35].number[1] = 0;
net.place[35].number[2] = 12;
net.place[35].number[3] = 3;

InitPlace( 36, "", 4, PlacePolicy(1) );
net.place[36].number[1] = 0;
net.place[36].number[2] = 12;
net.place[36].number[3] = 5;

InitPlace( 37, "", 4, PlacePolicy(1));
net.place[37].number[1] = 0;
net.place[37].number[2] = 12;
net.place[37].number[3] = 6;

InitPlace( 38, "", 4, PlacePolicy(1) );
net.place[38].number[1] = 0;
net.place[38].number[2] = 12;
net.place[38].number[3] = 7;

InitPlace( 39, "", 4, PlacePolicy(1) );
net.place[39].number[1] = 0;
net.place[39].number[2] = 13;
net.place[39].number[3] = 0;

InitPlace( 40, "", 4, PlacePolicy(1) );
net.place[40].number[1] = 0;
net.place[40].number[2] = 13;
net.place[40].number[3] = 1;

InitPlace( 41, "", 4, PlacePolicy(1) );
net.place[41].number[1] = 0;
net.place[41].number[2] = 13;
net.place[41].number[3] = 2;

InitPlace( 42, "", 4, PlacePolicy(1) );
net.place[42].number[1] = 0;
net.place[42].number[2] = 13;
net.place[42].number[3] = 3;

InitPlace( 43, "", 4, PlacePolicy(1) );
net.place[43].number[1] = 0;
net.place[43].number[2] = 13;
net.place[43].number[3] = 5;

InitPlace( 44, "", 4, PlacePolicy(1) );
net.place[44].number[1] = 0;
net.place[44].number[2] = 13;
net.place[44].number[3] = 6;

InitPlace( 45, "", 4, PlacePolicy(1) );
net.place[45].number[1] = 0;
net.place[45].number[2] = 13;
net.place[45].number[3] = 7;

InitPlace( 46, "", 4, PlacePolicy(1));
net.place[46].number[1] = 0;
net.place[46].number[2] = 14;
net.place[46].number[3] = 0;

InitPlace( 47, "", 4, PlacePolicy(1) );
net.place[47].number[1] = 0;
net.place[47].number[2] = 14;
net.place[47].number[3] = 1;

InitPlace( 48, "", 4, PlacePolicy(1) );
net.place[48].number[1] = 0;
net.place[48].number[2] = 14;
net.place[48].number[3] = 2;

InitPlace( 49, "", 4, PlacePolicy(1) );
net.place[49].number[1] = 0;
net.place[49].number[2] = 14;
net.place[49].number[3] = 3;

InitPlace( 50, "", 4, PlacePolicy(1));
net.place[50].number[1] = 0;
net.place[50].number[2] = 14;
net.place[50].number[3] = 5;

InitPlace( 51, "", 4, PlacePolicy(1));
net.place[51].number[1] = 0;
net.place[51].number[2] = 14;
net.place[51].number[3] = 6;

InitPlace( 52, "", 4, PlacePolicy(1) );
net.place[52].number[1] = 0;
net.place[52].number[2] = 14;
net.place[52].number[3] = 7;

InitPlace( 53, "", 3, PlacePolicy(1) );
net.place[53].number[1] = 0;
net.place[53].number[2] = 15;

InitPlace( 54, "", 4, PlacePolicy(1) );
net.place[54].number[1] = 0;
net.place[54].number[2] = 16;
net.place[54].number[3] = 0;

InitPlace( 55, "", 4, PlacePolicy(1) );
net.place[55].number[1] = 0;
net.place[55].number[2] = 16;
net.place[55].number[3] = 1;

InitPlace( 56, "", 4, PlacePolicy(1) );
net.place[56].number[1] = 0;
net.place[56].number[2] = 16;
net.place[56].number[3] = 2;

InitPlace( 57, "", 4, PlacePolicy(1) );
net.place[57].number[1] = 0;
net.place[57].number[2] = 16;
net.place[57].number[3] = 3;

InitPlace( 58, "", 4, PlacePolicy(1) );
net.place[58].number[1] = 0;
net.place[58].number[2] = 16;
net.place[58].number[3] = 5;

InitPlace( 59, "", 4, PlacePolicy(1) );
net.place[59].number[1] = 0;
net.place[59].number[2] = 16;
net.place[59].number[3] = 6;

InitPlace( 60, "", 4, PlacePolicy(1));
net.place[60].number[1] = 0;
net.place[60].number[2] = 16;
net.place[60].number[3] = 7;

InitPlace( 61, "", 3, PlacePolicy(1) );
net.place[61].number[1] = 0;
net.place[61].number[2] = 17;

InitPlace( 62, "Y7", 4, PlacePolicy(0) );
net.place[62].number[1] = 0;
net.place[62].number[2] = 18;
net.place[62].number[3] = 0;

InitPlace( 63, "", 4, PlacePolicy(0) );
net.place[63].number[1] = 0;
net.place[63].number[2] = 18;
net.place[63].number[3] = 1;

InitPlace( 64, "", 4, PlacePolicy(0) );
net.place[64].number[1] = 0;
net.place[64].number[2] = 18;
net.place[64].number[3] = 2;

InitPlace( 65, "", 4, PlacePolicy(0) );
net.place[65].number[1] = 0;
net.place[65].number[2] = 18;
net.place[65].number[3] = 3;

InitPlace( 66, "", 4, PlacePolicy(0) );
net.place[66].number[1] = 0;
net.place[66].number[2] = 18;
net.place[66].number[3] = 4;

InitPlace( 67, "", 4, PlacePolicy(0) );
net.place[67].number[1] = 0;
net.place[67].number[2] = 18;
net.place[67].number[3] = 5;

InitPlace( 68, "", 4, PlacePolicy(0) );
net.place[68].number[1] = 0;
net.place[68].number[2] = 18;
net.place[68].number[3] = 6;

InitPlace( 69, "", 4, PlacePolicy(0) );
net.place[69].number[1] = 0;
net.place[69].number[2] = 18;
net.place[69].number[3] = 7;

InitPlace( 70, "", 4, PlacePolicy(0) );
net.place[70].number[1] = 0;
net.place[70].number[2] = 18;
net.place[70].number[3] = 8;

InitPlace( 71, "", 4, PlacePolicy(1) );
net.place[71].number[1] = 0;
net.place[71].number[2] = 18;
net.place[71].number[3] = 9;

InitPlace( 72, "", 4, PlacePolicy(0) );
net.place[72].number[1] = 0;
net.place[72].number[2] = 18;
net.place[72].number[3] = 10;

InitPlace( 73, "", 4, PlacePolicy(1) );
net.place[73].number[1] = 0;
net.place[73].number[2] = 18;
net.place[73].number[3] = 11;

InitPlace( 74, "", 4, PlacePolicy(1) );
net.place[74].number[1] = 0;
net.place[74].number[2] = 18;
net.place[74].number[3] = 12;

InitPlace( 75, "", 4, PlacePolicy(1) );
net.place[75].number[1] = 0;
net.place[75].number[2] = 18;
net.place[75].number[3] = 13;

InitPlace( 76, "", 4, PlacePolicy(1) );
net.place[76].number[1] = 0;
net.place[76].number[2] = 18;
net.place[76].number[3] = 14;

InitPlace( 77, "", 4, PlacePolicy(1) );
net.place[77].number[1] = 0;
net.place[77].number[2] = 18;
net.place[77].number[3] = 15;

InitPlace( 78, "", 4, PlacePolicy(1) );
net.place[78].number[1] = 0;
net.place[78].number[2] = 18;
net.place[78].number[3] = 16;

InitPlace( 79, "", 4, PlacePolicy(1) );
net.place[79].number[1] = 0;
net.place[79].number[2] = 18;
net.place[79].number[3] = 17;

InitPlace( 80, "", 4, PlacePolicy(1) );
net.place[80].number[1] = 0;
net.place[80].number[2] = 18;
net.place[80].number[3] = 18;

InitPlace( 81, "", 4, PlacePolicy(1) );
net.place[81].number[1] = 0;
net.place[81].number[2] = 18;
net.place[81].number[3] = 19;

InitPlace( 82, "", 4, PlacePolicy(1) );
net.place[82].number[1] = 0;
net.place[82].number[2] = 18;
net.place[82].number[3] = 20;

InitPlace( 83, "", 4, PlacePolicy(1) );
net.place[83].number[1] = 0;
net.place[83].number[2] = 18;
net.place[83].number[3] = 21;

InitPlace( 84, "", 4, PlacePolicy(0) );
net.place[84].number[1] = 0;
net.place[84].number[2] = 18;
net.place[84].number[3] = 42;

InitPlace( 85, "", 4, PlacePolicy(0) );
net.place[85].number[1] = 0;
net.place[85].number[2] = 18;
net.place[85].number[3] = 43;

InitPlace( 86, "", 4, PlacePolicy(0) );
net.place[86].number[1] = 0;
net.place[86].number[2] = 18;
net.place[86].number[3] = 76;

InitPlace( 87, "R6", 4, PlacePolicy(0) );
net.place[87].number[1] = 0;
net.place[87].number[2] = 18;
net.place[87].number[3] = 77;

InitPlace( 88, "GG7", 4, PlacePolicy(0) );
net.place[88].number[1] = 0;
net.place[88].number[2] = 18;
net.place[88].number[3] = 78;

InitPlace( 89, "GR6", 4, PlacePolicy(0) );
net.place[89].number[1] = 0;
net.place[89].number[2] = 18;
net.place[89].number[3] = 79;

InitPlace( 90, "", 4, PlacePolicy(0) );
net.place[90].number[1] = 0;
net.place[90].number[2] = 18;
net.place[90].number[3] = 80;

InitPlace( 91, "GG6", 4, PlacePolicy(0) );
net.place[91].number[1] = 0;
net.place[91].number[2] = 18;
net.place[91].number[3] = 83;

InitPlace( 92, "GG5", 4, PlacePolicy(0) );
net.place[92].number[1] = 0;
net.place[92].number[2] = 18;
net.place[92].number[3] = 84;

InitPlace( 93, "GR5", 4, PlacePolicy(0) );
net.place[93].number[1] = 0;
net.place[93].number[2] = 18;
net.place[93].number[3] = 90;

InitPlace( 94, "GG4", 4, PlacePolicy(0) );
net.place[94].number[1] = 0;
net.place[94].number[2] = 18;
net.place[94].number[3] = 91;

InitPlace( 95, "GR4", 4, PlacePolicy(0) );
net.place[95].number[1] = 0;
net.place[95].number[2] = 18;
net.place[95].number[3] = 92;

InitPlace( 96, "GR3", 4, PlacePolicy(0) );
net.place[96].number[1] = 0;
net.place[96].number[2] = 18;
net.place[96].number[3] = 93;

InitPlace( 97, "GG3", 4, PlacePolicy(0) );
net.place[97].number[1] = 0;
net.place[97].number[2] = 18;
net.place[97].number[3] = 94;

InitPlace( 98, "GR2", 4, PlacePolicy(0));
net.place[98].number[1] = 0;
net.place[98].number[2] = 18;
net.place[98].number[3] = 95;

InitPlace( 99, "GG2", 4, PlacePolicy(0) );
net.place[99].number[1] = 0;
net.place[99].number[2] = 18;
net.place[99].number[3] = 96;

InitPlace( 100, "GR1", 4, PlacePolicy(0) );
net.place[100].number[1] = 0;
net.place[100].number[2] = 18;
net.place[100].number[3] = 97;

InitPlace( 101, "GG1", 4, PlacePolicy(0) );
net.place[101].number[1] = 0;
net.place[101].number[2] = 18;
net.place[101].number[3] = 98;

InitPlace( 102, "GR0", 4, PlacePolicy(1) );
net.place[102].number[1] = 0;
net.place[102].number[2] = 18;
net.place[102].number[3] = 99;

InitPlace( 103, "GG0", 4, PlacePolicy(0) );
net.place[103].number[1] = 0;
net.place[103].number[2] = 18;
net.place[103].number[3] = 100;

InitPlace( 104, "", 4, PlacePolicy(1) );
net.place[104].number[1] = 0;
net.place[104].number[2] = 18;
net.place[104].number[3] = 101;

InitPlace( 105, "", 4, PlacePolicy(1) );
net.place[105].number[1] = 0;
net.place[105].number[2] = 18;
net.place[105].number[3] = 102;

InitPlace( 106, "RG0", 4, PlacePolicy(0) );
net.place[106].number[1] = 0;
net.place[106].number[2] = 18;
net.place[106].number[3] = 103;

InitPlace( 107, "M0", 4, PlacePolicy(0) );
net.place[107].number[1] = 0;
net.place[107].number[2] = 18;
net.place[107].number[3] = 104;

InitPlace( 108, "Y0", 4, PlacePolicy(0) );
net.place[108].number[1] = 0;
net.place[108].number[2] = 18;
net.place[108].number[3] = 105;

InitPlace( 109, "", 4, PlacePolicy(0) );
net.place[109].number[1] = 0;
net.place[109].number[2] = 18;
net.place[109].number[3] = 106;

InitPlace( 110, "G0", 4, PlacePolicy(0) );
net.place[110].number[1] = 0;
net.place[110].number[2] = 18;
net.place[110].number[3] = 107;

InitPlace( 111, "", 4, PlacePolicy(1) );
net.place[111].number[1] = 0;
net.place[111].number[2] = 18;
net.place[111].number[3] = 108;

InitPlace( 112, "RG1", 4, PlacePolicy(0));
net.place[112].number[1] = 0;
net.place[112].number[2] = 18;
net.place[112].number[3] = 109;

InitPlace( 113, "", 4, PlacePolicy(1) );
net.place[113].number[1] = 0;
net.place[113].number[2] = 18;
net.place[113].number[3] = 110;

InitPlace( 114, "Y1", 4, PlacePolicy(0) );
net.place[114].number[1] = 0;
net.place[114].number[2] = 18;
net.place[114].number[3] = 111;

InitPlace( 115, "", 4, PlacePolicy(0) );
net.place[115].number[1] = 0;
net.place[115].number[2] = 18;
net.place[115].number[3] = 112;

InitPlace( 116, "M1", 4, PlacePolicy(0));
net.place[116].number[1] = 0;
net.place[116].number[2] = 18;
net.place[116].number[3] = 113;

InitPlace( 117, "G1", 4, PlacePolicy(0) );
net.place[117].number[1] = 0;
net.place[117].number[2] = 18;
net.place[117].number[3] = 114;

InitPlace( 118, "Y2", 4, PlacePolicy(0) );
net.place[118].number[1] = 0;
net.place[118].number[2] = 18;
net.place[118].number[3] = 115;

InitPlace( 119, "", 4, PlacePolicy(0) );
net.place[119].number[1] = 0;
net.place[119].number[2] = 18;
net.place[119].number[3] = 116;

InitPlace( 120, "M2", 4, PlacePolicy(0) );
net.place[120].number[1] = 0;
net.place[120].number[2] = 18;
net.place[120].number[3] = 117;

InitPlace( 121, "G2", 4, PlacePolicy(0) );
net.place[121].number[1] = 0;
net.place[121].number[2] = 18;
net.place[121].number[3] = 118;

InitPlace( 122, "", 4, PlacePolicy(1) );
net.place[122].number[1] = 0;
net.place[122].number[2] = 18;
net.place[122].number[3] = 119;

InitPlace( 123, "RG2", 4, PlacePolicy(0) );
net.place[123].number[1] = 0;
net.place[123].number[2] = 18;
net.place[123].number[3] = 120;

InitPlace( 124, "", 4, PlacePolicy(1) );
net.place[124].number[1] = 0;
net.place[124].number[2] = 18;
net.place[124].number[3] = 121;

InitPlace( 125, "RG3", 4, PlacePolicy(0) );
net.place[125].number[1] = 0;
net.place[125].number[2] = 18;
net.place[125].number[3] = 122;

InitPlace( 126, "", 4, PlacePolicy(1) );
net.place[126].number[1] = 0;
net.place[126].number[2] = 18;
net.place[126].number[3] = 123;

InitPlace( 127, "", 4, PlacePolicy(1) );
net.place[127].number[1] = 0;
net.place[127].number[2] = 18;
net.place[127].number[3] = 124;

InitPlace( 128, "", 4, PlacePolicy(0) );
net.place[128].number[1] = 0;
net.place[128].number[2] = 18;
net.place[128].number[3] = 125;

InitPlace( 129, "Y3", 4, PlacePolicy(0) );
net.place[129].number[1] = 0;
net.place[129].number[2] = 18;
net.place[129].number[3] = 126;

InitPlace( 130, "G3", 4, PlacePolicy(0) );
net.place[130].number[1] = 0;
net.place[130].number[2] = 18;
net.place[130].number[3] = 127;

InitPlace( 131, "M3", 4, PlacePolicy(0) );
net.place[131].number[1] = 0;
net.place[131].number[2] = 18;
net.place[131].number[3] = 128;

InitPlace( 132, "RG4", 4, PlacePolicy(0) );
net.place[132].number[1] = 0;
net.place[132].number[2] = 18;
net.place[132].number[3] = 129;

InitPlace( 133, "", 4, PlacePolicy(0) );
net.place[133].number[1] = 0;
net.place[133].number[2] = 18;
net.place[133].number[3] = 130;

InitPlace( 134, "Y4", 4, PlacePolicy(0) );
net.place[134].number[1] = 0;
net.place[134].number[2] = 18;
net.place[134].number[3] = 131;

InitPlace( 135, "G4", 4, PlacePolicy(0) );
net.place[135].number[1] = 0;
net.place[135].number[2] = 18;
net.place[135].number[3] = 132;

InitPlace( 136, "M4", 4, PlacePolicy(0) );
net.place[136].number[1] = 0;
net.place[136].number[2] = 18;
net.place[136].number[3] = 133;

InitPlace( 137, "", 4, PlacePolicy(1) );
net.place[137].number[1] = 0;
net.place[137].number[2] = 18;
net.place[137].number[3] = 134;

InitPlace( 138, "", 4, PlacePolicy(1) );
net.place[138].number[1] = 0;
net.place[138].number[2] = 18;
net.place[138].number[3] = 135;

InitPlace( 139, "", 4, PlacePolicy(1) );
net.place[139].number[1] = 0;
net.place[139].number[2] = 18;
net.place[139].number[3] = 136;

InitPlace( 140, "Y5", 4, PlacePolicy(0) );
net.place[140].number[1] = 0;
net.place[140].number[2] = 18;
net.place[140].number[3] = 137;

InitPlace( 141, "", 4, PlacePolicy(0) );
net.place[141].number[1] = 0;
net.place[141].number[2] = 18;
net.place[141].number[3] = 138;

InitPlace( 142, "RG5", 4, PlacePolicy(0) );
net.place[142].number[1] = 0;
net.place[142].number[2] = 18;
net.place[142].number[3] = 139;

InitPlace( 143, "", 4, PlacePolicy(1));
net.place[143].number[1] = 0;
net.place[143].number[2] = 18;
net.place[143].number[3] = 140;

InitPlace( 144, "G5", 4, PlacePolicy(0) );
net.place[144].number[1] = 0;
net.place[144].number[2] = 18;
net.place[144].number[3] = 141;

InitPlace( 145, "M5", 4, PlacePolicy(0) );
net.place[145].number[1] = 0;
net.place[145].number[2] = 18;
net.place[145].number[3] = 142;

InitPlace( 146, "", 4, PlacePolicy(1) );
net.place[146].number[1] = 0;
net.place[146].number[2] = 18;
net.place[146].number[3] = 143;

InitPlace( 147, "Y6", 4, PlacePolicy(0) );
net.place[147].number[1] = 0;
net.place[147].number[2] = 18;
net.place[147].number[3] = 144;

InitPlace( 148, "", 4, PlacePolicy(0) );
net.place[148].number[1] = 0;
net.place[148].number[2] = 18;
net.place[148].number[3] = 145;

InitPlace( 149, "G6", 4, PlacePolicy(0) );
net.place[149].number[1] = 0;
net.place[149].number[2] = 18;
net.place[149].number[3] = 146;

InitPlace( 150, "M6", 4, PlacePolicy(0) );
net.place[150].number[1] = 0;
net.place[150].number[2] = 18;
net.place[150].number[3] = 147;

InitPlace( 151, "RG6", 4, PlacePolicy(0) );
net.place[151].number[1] = 0;
net.place[151].number[2] = 18;
net.place[151].number[3] = 148;

InitPlace( 152, "", 4, PlacePolicy(1) );
net.place[152].number[1] = 0;
net.place[152].number[2] = 18;
net.place[152].number[3] = 149;

InitPlace( 153, "", 4, PlacePolicy(0) );
net.place[153].number[1] = 0;
net.place[153].number[2] = 18;
net.place[153].number[3] = 151;

InitPlace( 154, "GR7", 4, PlacePolicy(0) );
net.place[154].number[1] = 0;
net.place[154].number[2] = 18;
net.place[154].number[3] = 152;

InitPlace( 155, "G7", 4, PlacePolicy(0) );
net.place[155].number[1] = 0;
net.place[155].number[2] = 18;
net.place[155].number[3] = 153;

InitPlace( 156, "", 4, PlacePolicy(1) );
net.place[156].number[1] = 0;
net.place[156].number[2] = 18;
net.place[156].number[3] = 154;

InitPlace( 157, "", 4, PlacePolicy(1) );
net.place[157].number[1] = 0;
net.place[157].number[2] = 18;
net.place[157].number[3] = 155;

InitPlace( 158, "M7", 4, PlacePolicy(0) );
net.place[158].number[1] = 0;
net.place[158].number[2] = 18;
net.place[158].number[3] = 156;

InitPlace( 159, "RG7", 4, PlacePolicy(0) );
net.place[159].number[1] = 0;
net.place[159].number[2] = 18;
net.place[159].number[3] = 157;

InitPlace( 160, "R7", 4, PlacePolicy(0) );
net.place[160].number[1] = 0;
net.place[160].number[2] = 18;
net.place[160].number[3] = 162;

InitPlace( 161, "R5", 4, PlacePolicy(0) );
net.place[161].number[1] = 0;
net.place[161].number[2] = 18;
net.place[161].number[3] = 163;

InitPlace( 162, "R4", 4, PlacePolicy(0) );
net.place[162].number[1] = 0;
net.place[162].number[2] = 18;
net.place[162].number[3] = 164;

InitPlace( 163, "R3", 4, PlacePolicy(0) );
net.place[163].number[1] = 0;
net.place[163].number[2] = 18;
net.place[163].number[3] = 165;

InitPlace( 164, "R2", 4, PlacePolicy(0));
net.place[164].number[1] = 0;
net.place[164].number[2] = 18;
net.place[164].number[3] = 166;

InitPlace( 165, "R1", 4, PlacePolicy(0) );
net.place[165].number[1] = 0;
net.place[165].number[2] = 18;
net.place[165].number[3] = 167;

InitPlace( 166, "R0", 4, PlacePolicy(0) );
net.place[166].number[1] = 0;
net.place[166].number[2] = 18;
net.place[166].number[3] = 168;

InitPlace( 167, "", 4, PlacePolicy(0) );
net.place[167].number[1] = 0;
net.place[167].number[2] = 18;
net.place[167].number[3] = 170;

InitPlace( 168, "", 4, PlacePolicy(0) );
net.place[168].number[1] = 0;
net.place[168].number[2] = 18;
net.place[168].number[3] = 288;

InitPlace( 169, "", 4, PlacePolicy(0));
net.place[169].number[1] = 0;
net.place[169].number[2] = 18;
net.place[169].number[3] = 309;

InitPlace( 170, "", 4, PlacePolicy(0));
net.place[170].number[1] = 0;
net.place[170].number[2] = 18;
net.place[170].number[3] = 318;

InitPlace( 171, "", 4, PlacePolicy(0));
net.place[171].number[1] = 0;
net.place[171].number[2] = 18;
net.place[171].number[3] = 335;

InitPlace( 172, "", 4, PlacePolicy(0));
net.place[172].number[1] = 0;
net.place[172].number[2] = 18;
net.place[172].number[3] = 360;

InitPlace( 173, "", 4, PlacePolicy(0));
net.place[173].number[1] = 0;
net.place[173].number[2] = 18;
net.place[173].number[3] = 377;

InitPlace( 174, "", 4, PlacePolicy(0) );
net.place[174].number[1] = 0;
net.place[174].number[2] = 18;
net.place[174].number[3] = 394;

InitPlace( 175, "", 4,PlacePolicy(0) );
net.place[175].number[1] = 0;
net.place[175].number[2] = 18;
net.place[175].number[3] = 427;

InitPlace( 176, "", 4, PlacePolicy(0));
net.place[176].number[1] = 0;
net.place[176].number[2] = 18;
net.place[176].number[3] = 428;

InitPlace( 177, "", 4, PlacePolicy(0));
net.place[177].number[1] = 0;
net.place[177].number[2] = 18;
net.place[177].number[3] = 449;

InitPlace( 178, "", 4, PlacePolicy(0));
net.place[178].number[1] = 0;
net.place[178].number[2] = 18;
net.place[178].number[3] = 457;

InitPlace( 179, "", 4, PlacePolicy(0));
net.place[179].number[1] = 0;
net.place[179].number[2] = 18;
net.place[179].number[3] = 481;

InitPlace( 180, "", 4, PlacePolicy(0));
net.place[180].number[1] = 0;
net.place[180].number[2] = 18;
net.place[180].number[3] = 500;

InitPlace( 181, "", 4, PlacePolicy(0));
net.place[181].number[1] = 0;
net.place[181].number[2] = 18;
net.place[181].number[3] = 533;

InitPlace( 182, "", 4, PlacePolicy(0));
net.place[182].number[1] = 0;
net.place[182].number[2] = 18;
net.place[182].number[3] = 534;

InitPlace( 183, "", 4, PlacePolicy(0));
net.place[183].number[1] = 0;
net.place[183].number[2] = 18;
net.place[183].number[3] = 551;

InitPlace( 184, "", 4, PlacePolicy(0));
net.place[184].number[1] = 0;
net.place[184].number[2] = 18;
net.place[184].number[3] = 584;

InitPlace( 185, "", 4, PlacePolicy(0));
net.place[185].number[1] = 0;
net.place[185].number[2] = 18;
net.place[185].number[3] = 585;

InitPlace( 186, "", 4, PlacePolicy(0));
net.place[186].number[1] = 0;
net.place[186].number[2] = 18;
net.place[186].number[3] = 634;

InitPlace( 187, "", 4, PlacePolicy(0));
net.place[187].number[1] = 0;
net.place[187].number[2] = 18;
net.place[187].number[3] = 635;

InitPlace( 188, "", 4, PlacePolicy(0) );
net.place[188].number[1] = 0;
net.place[188].number[2] = 18;
net.place[188].number[3] = 636;

InitPlace( 189, "", 4, PlacePolicy(0));
net.place[189].number[1] = 0;
net.place[189].number[2] = 18;
net.place[189].number[3] = 669;

InitPlace( 190, "", 4, PlacePolicy(0));
net.place[190].number[1] = 0;
net.place[190].number[2] = 18;
net.place[190].number[3] = 670;

InitPlace( 191, "", 4, PlacePolicy(0));
net.place[191].number[1] = 0;
net.place[191].number[2] = 18;
net.place[191].number[3] = 707;

InitPlace( 192, "", 4, PlacePolicy(0));
net.place[192].number[1] = 0;
net.place[192].number[2] = 18;
net.place[192].number[3] = 732;

InitPlace( 193, "", 4, PlacePolicy(0));
net.place[193].number[1] = 0;
net.place[193].number[2] = 18;
net.place[193].number[3] = 749;

InitPlace( 194, "", 4, PlacePolicy(0));
net.place[194].number[1] = 0;
net.place[194].number[2] = 18;
net.place[194].number[3] = 758;

InitPlace( 195, "", 4, PlacePolicy(0));
net.place[195].number[1] = 0;
net.place[195].number[2] = 18;
net.place[195].number[3] = 799;

InitPlace( 196, "", 4, PlacePolicy(0));
net.place[196].number[1] = 0;
net.place[196].number[2] = 18;
net.place[196].number[3] = 808;

InitPlace( 197, "", 4, PlacePolicy(0));
net.place[197].number[1] = 0;
net.place[197].number[2] = 18;
net.place[197].number[3] = 809;

InitPlace( 198, "", 4, PlacePolicy(0));
net.place[198].number[1] = 0;
net.place[198].number[2] = 18;
net.place[198].number[3] = 834;

InitPlace( 199, "", 4, PlacePolicy(0) );
net.place[199].number[1] = 0;
net.place[199].number[2] = 18;
net.place[199].number[3] = 843;

InitPlace( 200, "", 4, PlacePolicy(0));
net.place[200].number[1] = 0;
net.place[200].number[2] = 18;
net.place[200].number[3] = 860;

InitPlace( 201, "", 4, PlacePolicy(0));
net.place[201].number[1] = 0;
net.place[201].number[2] = 18;
net.place[201].number[3] = 885;

InitPlace( 202, "", 4, PlacePolicy(0) );
net.place[202].number[1] = 0;
net.place[202].number[2] = 18;
net.place[202].number[3] = 918;

InitPlace( 203, "", 4, PlacePolicy(0));
net.place[203].number[1] = 0;
net.place[203].number[2] = 18;
net.place[203].number[3] = 927;

InitPlace( 204, "", 4, PlacePolicy(0));
net.place[204].number[1] = 0;
net.place[204].number[2] = 18;
net.place[204].number[3] = 936;

InitPlace( 205, "", 4, PlacePolicy(0));
net.place[205].number[1] = 0;
net.place[205].number[2] = 18;
net.place[205].number[3] = 945;

InitPlace( 206, "", 4, PlacePolicy(0));
net.place[206].number[1] = 0;
net.place[206].number[2] = 18;
net.place[206].number[3] = 986;

InitPlace( 207, "", 4, PlacePolicy(0));
net.place[207].number[1] = 0;
net.place[207].number[2] = 18;
net.place[207].number[3] = 987;

InitPlace( 208, "", 4, PlacePolicy(0));
net.place[208].number[1] = 0;
net.place[208].number[2] = 18;
net.place[208].number[3] = 996;

InitPlace( 209, "", 4, PlacePolicy(0));
net.place[209].number[1] = 0;
net.place[209].number[2] = 18;
net.place[209].number[3] = 1021;

InitPlace( 210, "", 4, PlacePolicy(0));
net.place[210].number[1] = 0;
net.place[210].number[2] = 18;
net.place[210].number[3] = 1030;

InitPlace( 211, "", 4, PlacePolicy(0));
net.place[211].number[1] = 0;
net.place[211].number[2] = 18;
net.place[211].number[3] = 1047;

InitPlace( 212, "", 4, PlacePolicy(0));
net.place[212].number[1] = 0;
net.place[212].number[2] = 18;
net.place[212].number[3] = 1064;

InitPlace( 213, "", 4, PlacePolicy(0));
net.place[213].number[1] = 0;
net.place[213].number[2] = 18;
net.place[213].number[3] = 1081;

InitPlace( 214, "", 4, PlacePolicy(0));
net.place[214].number[1] = 0;
net.place[214].number[2] = 18;
net.place[214].number[3] = 1098;

InitPlace( 215, "", 4, PlacePolicy(0));
net.place[215].number[1] = 0;
net.place[215].number[2] = 18;
net.place[215].number[3] = 1107;

InitPlace( 216, "", 4, PlacePolicy(0));
net.place[216].number[1] = 0;
net.place[216].number[2] = 18;
net.place[216].number[3] = 1132;

InitPlace( 217, "", 4, PlacePolicy(0));
net.place[217].number[1] = 0;
net.place[217].number[2] = 18;
net.place[217].number[3] = 1149;

InitPlace( 218, "", 4, PlacePolicy(0));
net.place[218].number[1] = 0;
net.place[218].number[2] = 18;
net.place[218].number[3] = 1166;

InitPlace( 219, "", 3, PlacePolicy(0));
net.place[219].number[1] = 0;
net.place[219].number[2] = 19;

InitPlace( 220, "", 3, PlacePolicy(0));
net.place[220].number[1] = 0;
net.place[220].number[2] = 20;

InitPlace( 221, "", 3, PlacePolicy(0));
net.place[221].number[1] = 0;
net.place[221].number[2] = 21;

InitPlace( 222, "", 3, PlacePolicy(0));
net.place[222].number[1] = 0;
net.place[222].number[2] = 22;

InitPlace( 223, "", 3, PlacePolicy(1));
net.place[223].number[1] = 0;
net.place[223].number[2] = 23;

InitPlace( 224, "", 3, PlacePolicy(1));
net.place[224].number[1] = 0;
net.place[224].number[2] = 24;

InitPlace( 225, "", 3, PlacePolicy(1));
net.place[225].number[1] = 0;
net.place[225].number[2] = 169;

InitPlace( 226, "", 3, PlacePolicy(1));
net.place[226].number[1] = 0;
net.place[226].number[2] = 172;

InitPlace( 227, "", 3, PlacePolicy(1) );
net.place[227].number[1] = 0;
net.place[227].number[2] = 175;

InitPlace( 228, "", 3, PlacePolicy(1));
net.place[228].number[1] = 0;
net.place[228].number[2] = 177;

InitPlace( 229, "", 3, PlacePolicy(1));
net.place[229].number[1] = 0;
net.place[229].number[2] = 179;

InitPlace( 230, "", 3, PlacePolicy(1) );
net.place[230].number[1] = 0;
net.place[230].number[2] = 180;

InitPlace( 231, "", 3, PlacePolicy(1));
net.place[231].number[1] = 0;
net.place[231].number[2] = 181;

InitPlace( 232, "", 3, PlacePolicy(1));
net.place[232].number[1] = 0;
net.place[232].number[2] = 182;

InitPlace( 233, "", 3, PlacePolicy(1));
net.place[233].number[1] = 0;
net.place[233].number[2] = 183;

InitPlace( 234, "", 3, PlacePolicy(1));
net.place[234].number[1] = 0;
net.place[234].number[2] = 184;

InitPlace( 235, "", 3, PlacePolicy(1));
net.place[235].number[1] = 0;
net.place[235].number[2] = 185;

InitPlace( 236, "", 3, PlacePolicy(1));
net.place[236].number[1] = 0;
net.place[236].number[2] = 186;

InitPlace( 237, "", 3, PlacePolicy(1));
net.place[237].number[1] = 0;
net.place[237].number[2] = 187;

InitPlace( 238, "", 3, PlacePolicy(1));
net.place[238].number[1] = 0;
net.place[238].number[2] = 188;

InitPlace( 239, "", 3, PlacePolicy(1));
net.place[239].number[1] = 0;
net.place[239].number[2] = 189;

InitPlace( 240, "", 3, PlacePolicy(1));
net.place[240].number[1] = 0;
net.place[240].number[2] = 190;

InitPlace( 241, "", 3, PlacePolicy(1));
net.place[241].number[1] = 0;
net.place[241].number[2] = 193;

InitPlace( 242, "", 3, PlacePolicy(0));
net.place[242].number[1] = 0;
net.place[242].number[2] = 197;

InitPlace( 243, "", 3, PlacePolicy(1));
net.place[243].number[1] = 0;
net.place[243].number[2] = 198;

InitPlace( 244, "", 3, PlacePolicy(1) );
net.place[244].number[1] = 0;
net.place[244].number[2] = 199;

InitPlace( 245, "", 3, PlacePolicy(1));
net.place[245].number[1] = 0;
net.place[245].number[2] = 200;

InitPlace( 246, "", 3, PlacePolicy(1) );
net.place[246].number[1] = 0;
net.place[246].number[2] = 209;

InitPlace( 247, "", 3, PlacePolicy(1));
net.place[247].number[1] = 0;
net.place[247].number[2] = 210;

InitPlace( 248, "", 3, PlacePolicy(1) );
net.place[248].number[1] = 0;
net.place[248].number[2] = 211;

InitPlace( 249, "", 3, PlacePolicy(1));
net.place[249].number[1] = 0;
net.place[249].number[2] = 212;

InitPlace( 250, "", 3, PlacePolicy(1) );
net.place[250].number[1] = 0;
net.place[250].number[2] = 213;

InitPlace( 251, "", 3, PlacePolicy(1));
net.place[251].number[1] = 0;
net.place[251].number[2] = 214;

InitPlace( 252, "", 3, PlacePolicy(1));
net.place[252].number[1] = 0;
net.place[252].number[2] = 217;

InitPlace( 253, "", 3, PlacePolicy(1));
net.place[253].number[1] = 0;
net.place[253].number[2] = 218;

InitPlace( 254, "", 3, PlacePolicy(1));
net.place[254].number[1] = 0;
net.place[254].number[2] = 221;

InitPlace( 255, "", 3, PlacePolicy(1) );
net.place[255].number[1] = 0;
net.place[255].number[2] = 229;

InitPlace( 256, "", 3, PlacePolicy(1));
net.place[256].number[1] = 0;
net.place[256].number[2] = 232;

InitPlace( 257, "", 3, PlacePolicy(1) );
net.place[257].number[1] = 0;
net.place[257].number[2] = 233;

InitPlace( 258, "", 3, PlacePolicy(1) );
net.place[258].number[1] = 0;
net.place[258].number[2] = 234;

InitPlace( 259, "", 3, PlacePolicy(1));
net.place[259].number[1] = 0;
net.place[259].number[2] = 237;

InitPlace( 260, "", 3, PlacePolicy(1) );
net.place[260].number[1] = 0;
net.place[260].number[2] = 238;

InitPlace( 261, "", 3, PlacePolicy(1));
net.place[261].number[1] = 0;
net.place[261].number[2] = 239;

InitPlace( 262, "", 3, PlacePolicy(1) );
net.place[262].number[1] = 0;
net.place[262].number[2] = 242;

InitPlace( 263, "", 3, PlacePolicy(1) );
net.place[263].number[1] = 0;
net.place[263].number[2] = 252;

InitPlace( 264, "", 3, PlacePolicy(1) );
net.place[264].number[1] = 0;
net.place[264].number[2] = 253;

InitPlace( 265, "", 3, PlacePolicy(1) );
net.place[265].number[1] = 0;
net.place[265].number[2] = 254;

InitPlace( 266, "", 3, PlacePolicy(1) );
net.place[266].number[1] = 0;
net.place[266].number[2] = 255;

InitPlace( 267, "", 3, PlacePolicy(1));
net.place[267].number[1] = 1;
net.place[267].number[2] = 0;

InitPlace( 268, "", 3, PlacePolicy(1));
net.place[268].number[1] = 1;
net.place[268].number[2] = 1;

InitPlace( 269, "", 3, PlacePolicy(1));
net.place[269].number[1] = 1;
net.place[269].number[2] = 2;

InitPlace( 270, "", 4, PlacePolicy(1));
net.place[270].number[1] = 1;
net.place[270].number[2] = 3;
net.place[270].number[3] = 0;

InitPlace( 271, "", 4, PlacePolicy(1));
net.place[271].number[1] = 1;
net.place[271].number[2] = 3;
net.place[271].number[3] = 1;

InitPlace( 272, "", 4, PlacePolicy(1) );
net.place[272].number[1] = 1;
net.place[272].number[2] = 3;
net.place[272].number[3] = 2;

InitPlace( 273, "", 4, PlacePolicy(1) );
net.place[273].number[1] = 1;
net.place[273].number[2] = 3;
net.place[273].number[3] = 3;

InitPlace( 274, "", 4, PlacePolicy(1) );
net.place[274].number[1] = 1;
net.place[274].number[2] = 3;
net.place[274].number[3] = 5;

InitPlace( 275, "", 4, PlacePolicy(1) );
net.place[275].number[1] = 1;
net.place[275].number[2] = 3;
net.place[275].number[3] = 6;

InitPlace( 276, "", 4, PlacePolicy(1) );
net.place[276].number[1] = 1;
net.place[276].number[2] = 3;
net.place[276].number[3] = 7;

InitPlace( 277, "", 3, PlacePolicy(1));
net.place[277].number[1] = 1;
net.place[277].number[2] = 4;

InitPlace( 278, "", 4, PlacePolicy(1) );
net.place[278].number[1] = 1;
net.place[278].number[2] = 8;
net.place[278].number[3] = 0;

InitPlace( 279, "", 4, PlacePolicy(1) );
net.place[279].number[1] = 1;
net.place[279].number[2] = 8;
net.place[279].number[3] = 1;

InitPlace( 280, "", 4, PlacePolicy(1));
net.place[280].number[1] = 1;
net.place[280].number[2] = 8;
net.place[280].number[3] = 2;

InitPlace( 281, "", 4, PlacePolicy(1) );
net.place[281].number[1] = 1;
net.place[281].number[2] = 8;
net.place[281].number[3] = 3;

InitPlace( 282, "", 4, PlacePolicy(1) );
net.place[282].number[1] = 1;
net.place[282].number[2] = 8;
net.place[282].number[3] = 5;

InitPlace( 283, "", 4, PlacePolicy(1));
net.place[283].number[1] = 1;
net.place[283].number[2] = 8;
net.place[283].number[3] = 6;

InitPlace( 284, "", 4, PlacePolicy(1) );
net.place[284].number[1] = 1;
net.place[284].number[2] = 8;
net.place[284].number[3] = 7;

InitPlace( 285, "", 4, PlacePolicy(1));
net.place[285].number[1] = 1;
net.place[285].number[2] = 10;
net.place[285].number[3] = 0;

InitPlace( 286, "", 4, PlacePolicy(1));
net.place[286].number[1] = 1;
net.place[286].number[2] = 10;
net.place[286].number[3] = 1;

InitPlace( 287, "", 4, PlacePolicy(1) );
net.place[287].number[1] = 1;
net.place[287].number[2] = 10;
net.place[287].number[3] = 2;

InitPlace( 288, "", 4, PlacePolicy(1));
net.place[288].number[1] = 1;
net.place[288].number[2] = 10;
net.place[288].number[3] = 3;

InitPlace( 289, "", 4, PlacePolicy(1) );
net.place[289].number[1] = 1;
net.place[289].number[2] = 10;
net.place[289].number[3] = 5;

InitPlace( 290, "", 4, PlacePolicy(1));
net.place[290].number[1] = 1;
net.place[290].number[2] = 10;
net.place[290].number[3] = 6;

InitPlace( 291, "", 4, PlacePolicy(1));
net.place[291].number[1] = 1;
net.place[291].number[2] = 10;
net.place[291].number[3] = 7;

InitPlace( 292, "", 4, PlacePolicy(1) );
net.place[292].number[1] = 1;
net.place[292].number[2] = 11;
net.place[292].number[3] = 0;

InitPlace( 293, "", 4, PlacePolicy(1));
net.place[293].number[1] = 1;
net.place[293].number[2] = 11;
net.place[293].number[3] = 1;

InitPlace( 294, "", 4, PlacePolicy(1));
net.place[294].number[1] = 1;
net.place[294].number[2] = 11;
net.place[294].number[3] = 2;

InitPlace( 295, "", 4, PlacePolicy(1));
net.place[295].number[1] = 1;
net.place[295].number[2] = 11;
net.place[295].number[3] = 3;

InitPlace( 296, "", 4, PlacePolicy(1));
net.place[296].number[1] = 1;
net.place[296].number[2] = 11;
net.place[296].number[3] = 5;

InitPlace( 297, "", 4, PlacePolicy(1));
net.place[297].number[1] = 1;
net.place[297].number[2] = 11;
net.place[297].number[3] = 6;

InitPlace( 298, "", 4, PlacePolicy(1));
net.place[298].number[1] = 1;
net.place[298].number[2] = 11;
net.place[298].number[3] = 7;

InitPlace( 299, "", 4, PlacePolicy(1));
net.place[299].number[1] = 1;
net.place[299].number[2] = 12;
net.place[299].number[3] = 0;

InitPlace( 300, "", 4, PlacePolicy(1));
net.place[300].number[1] = 1;
net.place[300].number[2] = 12;
net.place[300].number[3] = 1;

InitPlace( 301, "", 4, PlacePolicy(1));
net.place[301].number[1] = 1;
net.place[301].number[2] = 12;
net.place[301].number[3] = 2;

InitPlace( 302, "", 4, PlacePolicy(1));
net.place[302].number[1] = 1;
net.place[302].number[2] = 12;
net.place[302].number[3] = 3;

InitPlace( 303, "", 4, PlacePolicy(1));
net.place[303].number[1] = 1;
net.place[303].number[2] = 12;
net.place[303].number[3] = 5;

InitPlace( 304, "", 4, PlacePolicy(1));
net.place[304].number[1] = 1;
net.place[304].number[2] = 12;
net.place[304].number[3] = 6;

InitPlace( 305, "", 4, PlacePolicy(1));
net.place[305].number[1] = 1;
net.place[305].number[2] = 12;
net.place[305].number[3] = 7;

InitPlace( 306, "", 4, PlacePolicy(1));
net.place[306].number[1] = 1;
net.place[306].number[2] = 13;
net.place[306].number[3] = 0;

InitPlace( 307, "", 4, PlacePolicy(1));
net.place[307].number[1] = 1;
net.place[307].number[2] = 13;
net.place[307].number[3] = 1;

InitPlace( 308, "", 4, PlacePolicy(1));
net.place[308].number[1] = 1;
net.place[308].number[2] = 13;
net.place[308].number[3] = 2;

InitPlace( 309, "", 4, PlacePolicy(1));
net.place[309].number[1] = 1;
net.place[309].number[2] = 13;
net.place[309].number[3] = 3;

InitPlace( 310, "", 4, PlacePolicy(1));
net.place[310].number[1] = 1;
net.place[310].number[2] = 13;
net.place[310].number[3] = 5;

InitPlace( 311, "", 4, PlacePolicy(1));
net.place[311].number[1] = 1;
net.place[311].number[2] = 13;
net.place[311].number[3] = 6;

InitPlace( 312, "", 4, PlacePolicy(1) );
net.place[312].number[1] = 1;
net.place[312].number[2] = 13;
net.place[312].number[3] = 7;

InitPlace( 313, "", 4, PlacePolicy(1));
net.place[313].number[1] = 1;
net.place[313].number[2] = 14;
net.place[313].number[3] = 0;

InitPlace( 314, "", 4, PlacePolicy(1));
net.place[314].number[1] = 1;
net.place[314].number[2] = 14;
net.place[314].number[3] = 1;

InitPlace( 315, "", 4, PlacePolicy(1));
net.place[315].number[1] = 1;
net.place[315].number[2] = 14;
net.place[315].number[3] = 2;

InitPlace( 316, "", 4, PlacePolicy(1) );
net.place[316].number[1] = 1;
net.place[316].number[2] = 14;
net.place[316].number[3] = 3;

InitPlace( 317, "", 4, PlacePolicy(1));
net.place[317].number[1] = 1;
net.place[317].number[2] = 14;
net.place[317].number[3] = 5;

InitPlace( 318, "", 4, PlacePolicy(1));
net.place[318].number[1] = 1;
net.place[318].number[2] = 14;
net.place[318].number[3] = 6;

InitPlace( 319, "", 4, PlacePolicy(1));
net.place[319].number[1] = 1;
net.place[319].number[2] = 14;
net.place[319].number[3] = 7;

InitPlace( 320, "", 3, PlacePolicy(1) );
net.place[320].number[1] = 1;
net.place[320].number[2] = 15;

InitPlace( 321, "", 4, PlacePolicy(1));
net.place[321].number[1] = 1;
net.place[321].number[2] = 16;
net.place[321].number[3] = 0;

InitPlace( 322, "", 4, PlacePolicy(1));
net.place[322].number[1] = 1;
net.place[322].number[2] = 16;
net.place[322].number[3] = 1;

InitPlace( 323, "", 4, PlacePolicy(1) );
net.place[323].number[1] = 1;
net.place[323].number[2] = 16;
net.place[323].number[3] = 2;

InitPlace( 324, "", 4, PlacePolicy(1));
net.place[324].number[1] = 1;
net.place[324].number[2] = 16;
net.place[324].number[3] = 3;

InitPlace( 325, "", 4, PlacePolicy(1));
net.place[325].number[1] = 1;
net.place[325].number[2] = 16;
net.place[325].number[3] = 5;

InitPlace( 326, "", 4, PlacePolicy(1));
net.place[326].number[1] = 1;
net.place[326].number[2] = 16;
net.place[326].number[3] = 6;

InitPlace( 327, "", 4, PlacePolicy(1));
net.place[327].number[1] = 1;
net.place[327].number[2] = 16;
net.place[327].number[3] = 7;

InitPlace( 328, "", 3, PlacePolicy(1) );
net.place[328].number[1] = 1;
net.place[328].number[2] = 17;

InitPlace( 329, "Y7", 4, PlacePolicy(0) );
net.place[329].number[1] = 1;
net.place[329].number[2] = 18;
net.place[329].number[3] = 0;

InitPlace( 330, "", 4, PlacePolicy(0) );
net.place[330].number[1] = 1;
net.place[330].number[2] = 18;
net.place[330].number[3] = 1;

InitPlace( 331, "", 4, PlacePolicy(0));
net.place[331].number[1] = 1;
net.place[331].number[2] = 18;
net.place[331].number[3] = 2;

InitPlace( 332, "", 4, PlacePolicy(0));
net.place[332].number[1] = 1;
net.place[332].number[2] = 18;
net.place[332].number[3] = 3;

InitPlace( 333, "", 4, PlacePolicy(0));
net.place[333].number[1] = 1;
net.place[333].number[2] = 18;
net.place[333].number[3] = 4;

InitPlace( 334, "", 4, PlacePolicy(0));
net.place[334].number[1] = 1;
net.place[334].number[2] = 18;
net.place[334].number[3] = 5;

InitPlace( 335, "", 4, PlacePolicy(0));
net.place[335].number[1] = 1;
net.place[335].number[2] = 18;
net.place[335].number[3] = 6;

InitPlace( 336, "", 4, PlacePolicy(0));
net.place[336].number[1] = 1;
net.place[336].number[2] = 18;
net.place[336].number[3] = 7;

InitPlace( 337, "", 4, PlacePolicy(0));
net.place[337].number[1] = 1;
net.place[337].number[2] = 18;
net.place[337].number[3] = 8;

InitPlace( 338, "", 4, PlacePolicy(1) );
net.place[338].number[1] = 1;
net.place[338].number[2] = 18;
net.place[338].number[3] = 9;

InitPlace( 339, "", 4, PlacePolicy(0) );
net.place[339].number[1] = 1;
net.place[339].number[2] = 18;
net.place[339].number[3] = 10;

InitPlace( 340, "", 4, PlacePolicy(1) );
net.place[340].number[1] = 1;
net.place[340].number[2] = 18;
net.place[340].number[3] = 11;

InitPlace( 341, "", 4, PlacePolicy(1));
net.place[341].number[1] = 1;
net.place[341].number[2] = 18;
net.place[341].number[3] = 12;

InitPlace( 342, "", 4, PlacePolicy(1));
net.place[342].number[1] = 1;
net.place[342].number[2] = 18;
net.place[342].number[3] = 13;

InitPlace( 343, "", 4, PlacePolicy(1) );
net.place[343].number[1] = 1;
net.place[343].number[2] = 18;
net.place[343].number[3] = 14;

InitPlace( 344, "", 4, PlacePolicy(1));
net.place[344].number[1] = 1;
net.place[344].number[2] = 18;
net.place[344].number[3] = 15;

InitPlace( 345, "", 4, PlacePolicy(1));
net.place[345].number[1] = 1;
net.place[345].number[2] = 18;
net.place[345].number[3] = 16;

InitPlace( 346, "", 4, PlacePolicy(1));
net.place[346].number[1] = 1;
net.place[346].number[2] = 18;
net.place[346].number[3] = 17;

InitPlace( 347, "", 4, PlacePolicy(1));
net.place[347].number[1] = 1;
net.place[347].number[2] = 18;
net.place[347].number[3] = 18;

InitPlace( 348, "", 4, PlacePolicy(1));
net.place[348].number[1] = 1;
net.place[348].number[2] = 18;
net.place[348].number[3] = 19;

InitPlace( 349, "", 4, PlacePolicy(1));
net.place[349].number[1] = 1;
net.place[349].number[2] = 18;
net.place[349].number[3] = 20;

InitPlace( 350, "", 4, PlacePolicy(1) );
net.place[350].number[1] = 1;
net.place[350].number[2] = 18;
net.place[350].number[3] = 21;

InitPlace( 351, "", 4, PlacePolicy(0));
net.place[351].number[1] = 1;
net.place[351].number[2] = 18;
net.place[351].number[3] = 42;

InitPlace( 352, "", 4, PlacePolicy(0) );
net.place[352].number[1] = 1;
net.place[352].number[2] = 18;
net.place[352].number[3] = 43;

InitPlace( 353, "", 4, PlacePolicy(0));
net.place[353].number[1] = 1;
net.place[353].number[2] = 18;
net.place[353].number[3] = 76;

InitPlace( 354, "R6", 4, PlacePolicy(0) );
net.place[354].number[1] = 1;
net.place[354].number[2] = 18;
net.place[354].number[3] = 77;

InitPlace( 355, "GG7", 4, PlacePolicy(0));
net.place[355].number[1] = 1;
net.place[355].number[2] = 18;
net.place[355].number[3] = 78;

InitPlace( 356, "GR6", 4, PlacePolicy(0));
net.place[356].number[1] = 1;
net.place[356].number[2] = 18;
net.place[356].number[3] = 79;

InitPlace( 357, "", 4, PlacePolicy(0));
net.place[357].number[1] = 1;
net.place[357].number[2] = 18;
net.place[357].number[3] = 80;

InitPlace( 358, "GG6", 4, PlacePolicy(0) );
net.place[358].number[1] = 1;
net.place[358].number[2] = 18;
net.place[358].number[3] = 83;

InitPlace( 359, "GG5", 4, PlacePolicy(0));
net.place[359].number[1] = 1;
net.place[359].number[2] = 18;
net.place[359].number[3] = 84;

InitPlace( 360, "GR5", 4, PlacePolicy(0));
net.place[360].number[1] = 1;
net.place[360].number[2] = 18;
net.place[360].number[3] = 90;

InitPlace( 361, "GG4", 4, PlacePolicy(0) );
net.place[361].number[1] = 1;
net.place[361].number[2] = 18;
net.place[361].number[3] = 91;

InitPlace( 362, "GR4", 4, PlacePolicy(0));
net.place[362].number[1] = 1;
net.place[362].number[2] = 18;
net.place[362].number[3] = 92;

InitPlace( 363, "GR3", 4, PlacePolicy(0) );
net.place[363].number[1] = 1;
net.place[363].number[2] = 18;
net.place[363].number[3] = 93;

InitPlace( 364, "GG3", 4, PlacePolicy(0) );
net.place[364].number[1] = 1;
net.place[364].number[2] = 18;
net.place[364].number[3] = 94;

InitPlace( 365, "GR2", 4, PlacePolicy(0));
net.place[365].number[1] = 1;
net.place[365].number[2] = 18;
net.place[365].number[3] = 95;

InitPlace( 366, "GG2", 4, PlacePolicy(0));
net.place[366].number[1] = 1;
net.place[366].number[2] = 18;
net.place[366].number[3] = 96;

InitPlace( 367, "GR1", 4, PlacePolicy(0));
net.place[367].number[1] = 1;
net.place[367].number[2] = 18;
net.place[367].number[3] = 97;

InitPlace( 368, "GG1", 4, PlacePolicy(0));
net.place[368].number[1] = 1;
net.place[368].number[2] = 18;
net.place[368].number[3] = 98;

InitPlace( 369, "GR0", 4, PlacePolicy(1) );
net.place[369].number[1] = 1;
net.place[369].number[2] = 18;
net.place[369].number[3] = 99;

InitPlace( 370, "GG0", 4, PlacePolicy(0) );
net.place[370].number[1] = 1;
net.place[370].number[2] = 18;
net.place[370].number[3] = 100;

InitPlace( 371, "", 4, PlacePolicy(1) );
net.place[371].number[1] = 1;
net.place[371].number[2] = 18;
net.place[371].number[3] = 101;

InitPlace( 372, "", 4, PlacePolicy(1) );
net.place[372].number[1] = 1;
net.place[372].number[2] = 18;
net.place[372].number[3] = 102;

InitPlace( 373, "RG0", 4, PlacePolicy(0) );
net.place[373].number[1] = 1;
net.place[373].number[2] = 18;
net.place[373].number[3] = 103;

InitPlace( 374, "M0", 4, PlacePolicy(0) );
net.place[374].number[1] = 1;
net.place[374].number[2] = 18;
net.place[374].number[3] = 104;

InitPlace( 375, "Y0", 4, PlacePolicy(0) );
net.place[375].number[1] = 1;
net.place[375].number[2] = 18;
net.place[375].number[3] = 105;

InitPlace( 376, "", 4, PlacePolicy(0) );
net.place[376].number[1] = 1;
net.place[376].number[2] = 18;
net.place[376].number[3] = 106;

InitPlace( 377, "G0", 4, PlacePolicy(0));
net.place[377].number[1] = 1;
net.place[377].number[2] = 18;
net.place[377].number[3] = 107;

InitPlace( 378, "", 4, PlacePolicy(1) );
net.place[378].number[1] = 1;
net.place[378].number[2] = 18;
net.place[378].number[3] = 108;

InitPlace( 379, "RG1", 4, PlacePolicy(0) );
net.place[379].number[1] = 1;
net.place[379].number[2] = 18;
net.place[379].number[3] = 109;

InitPlace( 380, "", 4, PlacePolicy(1) );
net.place[380].number[1] = 1;
net.place[380].number[2] = 18;
net.place[380].number[3] = 110;

InitPlace( 381, "Y1", 4, PlacePolicy(0));
net.place[381].number[1] = 1;
net.place[381].number[2] = 18;
net.place[381].number[3] = 111;

InitPlace( 382, "", 4, PlacePolicy(0) );
net.place[382].number[1] = 1;
net.place[382].number[2] = 18;
net.place[382].number[3] = 112;

InitPlace( 383, "M1", 4, PlacePolicy(0) );
net.place[383].number[1] = 1;
net.place[383].number[2] = 18;
net.place[383].number[3] = 113;

InitPlace( 384, "G1", 4, PlacePolicy(0) );
net.place[384].number[1] = 1;
net.place[384].number[2] = 18;
net.place[384].number[3] = 114;

InitPlace( 385, "Y2", 4, PlacePolicy(0));
net.place[385].number[1] = 1;
net.place[385].number[2] = 18;
net.place[385].number[3] = 115;

InitPlace( 386, "", 4, PlacePolicy(0) );
net.place[386].number[1] = 1;
net.place[386].number[2] = 18;
net.place[386].number[3] = 116;

InitPlace( 387, "M2", 4, PlacePolicy(0));
net.place[387].number[1] = 1;
net.place[387].number[2] = 18;
net.place[387].number[3] = 117;

InitPlace( 388, "G2", 4, PlacePolicy(0) );
net.place[388].number[1] = 1;
net.place[388].number[2] = 18;
net.place[388].number[3] = 118;

InitPlace( 389, "", 4, PlacePolicy(1) );
net.place[389].number[1] = 1;
net.place[389].number[2] = 18;
net.place[389].number[3] = 119;

InitPlace( 390, "RG2", 4, PlacePolicy(0) );
net.place[390].number[1] = 1;
net.place[390].number[2] = 18;
net.place[390].number[3] = 120;

InitPlace( 391, "", 4, PlacePolicy(1));
net.place[391].number[1] = 1;
net.place[391].number[2] = 18;
net.place[391].number[3] = 121;

InitPlace( 392, "RG3", 4, PlacePolicy(0) );
net.place[392].number[1] = 1;
net.place[392].number[2] = 18;
net.place[392].number[3] = 122;

InitPlace( 393, "", 4, PlacePolicy(1) );
net.place[393].number[1] = 1;
net.place[393].number[2] = 18;
net.place[393].number[3] = 123;

InitPlace( 394, "", 4, PlacePolicy(1) );
net.place[394].number[1] = 1;
net.place[394].number[2] = 18;
net.place[394].number[3] = 124;

InitPlace( 395, "", 4, PlacePolicy(0) );
net.place[395].number[1] = 1;
net.place[395].number[2] = 18;
net.place[395].number[3] = 125;

InitPlace( 396, "Y3", 4, PlacePolicy(0));
net.place[396].number[1] = 1;
net.place[396].number[2] = 18;
net.place[396].number[3] = 126;

InitPlace( 397, "G3", 4, PlacePolicy(0) );
net.place[397].number[1] = 1;
net.place[397].number[2] = 18;
net.place[397].number[3] = 127;

InitPlace( 398, "M3", 4, PlacePolicy(0));
net.place[398].number[1] = 1;
net.place[398].number[2] = 18;
net.place[398].number[3] = 128;

InitPlace( 399, "RG4", 4, PlacePolicy(0));
net.place[399].number[1] = 1;
net.place[399].number[2] = 18;
net.place[399].number[3] = 129;

InitPlace( 400, "", 4, PlacePolicy(0) );
net.place[400].number[1] = 1;
net.place[400].number[2] = 18;
net.place[400].number[3] = 130;

InitPlace( 401, "Y4", 4, PlacePolicy(0));
net.place[401].number[1] = 1;
net.place[401].number[2] = 18;
net.place[401].number[3] = 131;

InitPlace( 402, "G4", 4, PlacePolicy(0));
net.place[402].number[1] = 1;
net.place[402].number[2] = 18;
net.place[402].number[3] = 132;

InitPlace( 403, "M4", 4, PlacePolicy(0) );
net.place[403].number[1] = 1;
net.place[403].number[2] = 18;
net.place[403].number[3] = 133;

InitPlace( 404, "", 4, PlacePolicy(1));
net.place[404].number[1] = 1;
net.place[404].number[2] = 18;
net.place[404].number[3] = 134;

InitPlace( 405, "", 4, PlacePolicy(1));
net.place[405].number[1] = 1;
net.place[405].number[2] = 18;
net.place[405].number[3] = 135;

InitPlace( 406, "", 4, PlacePolicy(1) );
net.place[406].number[1] = 1;
net.place[406].number[2] = 18;
net.place[406].number[3] = 136;

InitPlace( 407, "Y5", 4, PlacePolicy(0));
net.place[407].number[1] = 1;
net.place[407].number[2] = 18;
net.place[407].number[3] = 137;

InitPlace( 408, "", 4, PlacePolicy(0));
net.place[408].number[1] = 1;
net.place[408].number[2] = 18;
net.place[408].number[3] = 138;

InitPlace( 409, "RG5", 4, PlacePolicy(0) );
net.place[409].number[1] = 1;
net.place[409].number[2] = 18;
net.place[409].number[3] = 139;

InitPlace( 410, "", 4, PlacePolicy(1));
net.place[410].number[1] = 1;
net.place[410].number[2] = 18;
net.place[410].number[3] = 140;

InitPlace( 411, "G5", 4, PlacePolicy(0) );
net.place[411].number[1] = 1;
net.place[411].number[2] = 18;
net.place[411].number[3] = 141;

InitPlace( 412, "M5", 4, PlacePolicy(0) );
net.place[412].number[1] = 1;
net.place[412].number[2] = 18;
net.place[412].number[3] = 142;


DefineNet1();
}
#endif /* SEGMENTED_MEMORY */
#endif /* CONST_NET */

