/* this file was generated from the NETMAN file:
	define01.c
	07/09/98 15:09:11
*/
#define SUPER_USER
#include "petri.h"
#include "userfunc.h"
#include <stdlib.h>

#ifndef CONST_NET
#ifdef SEGMENTED_MEMORY
void DefineNet1()
{
NCTArc *parcInputs, *parcOutputs;

InitPlace( 413, "", 4, PlacePolicy(1) );
net.place[413].number[1] = 1;
net.place[413].number[2] = 18;
net.place[413].number[3] = 143;

InitPlace( 414, "Y6", 4, PlacePolicy(0) );
net.place[414].number[1] = 1;
net.place[414].number[2] = 18;
net.place[414].number[3] = 144;

InitPlace( 415, "", 4, PlacePolicy(0) );
net.place[415].number[1] = 1;
net.place[415].number[2] = 18;
net.place[415].number[3] = 145;

InitPlace( 416, "G6", 4, PlacePolicy(0));
net.place[416].number[1] = 1;
net.place[416].number[2] = 18;
net.place[416].number[3] = 146;

InitPlace( 417, "M6", 4, PlacePolicy(0));
net.place[417].number[1] = 1;
net.place[417].number[2] = 18;
net.place[417].number[3] = 147;

InitPlace( 418, "RG6", 4, PlacePolicy(0) );
net.place[418].number[1] = 1;
net.place[418].number[2] = 18;
net.place[418].number[3] = 148;

InitPlace( 419, "", 4, PlacePolicy(1) );
net.place[419].number[1] = 1;
net.place[419].number[2] = 18;
net.place[419].number[3] = 149;

InitPlace( 420, "", 4, PlacePolicy(0));
net.place[420].number[1] = 1;
net.place[420].number[2] = 18;
net.place[420].number[3] = 151;

InitPlace( 421, "GR7", 4, PlacePolicy(0) );
net.place[421].number[1] = 1;
net.place[421].number[2] = 18;
net.place[421].number[3] = 152;

InitPlace( 422, "G7", 4, PlacePolicy(0));
net.place[422].number[1] = 1;
net.place[422].number[2] = 18;
net.place[422].number[3] = 153;

InitPlace( 423, "", 4, PlacePolicy(1) );
net.place[423].number[1] = 1;
net.place[423].number[2] = 18;
net.place[423].number[3] = 154;

InitPlace( 424, "", 4, PlacePolicy(1) );
net.place[424].number[1] = 1;
net.place[424].number[2] = 18;
net.place[424].number[3] = 155;

InitPlace( 425, "M7", 4, PlacePolicy(0));
net.place[425].number[1] = 1;
net.place[425].number[2] = 18;
net.place[425].number[3] = 156;

InitPlace( 426, "RG7", 4, PlacePolicy(0) );
net.place[426].number[1] = 1;
net.place[426].number[2] = 18;
net.place[426].number[3] = 157;

InitPlace( 427, "R7", 4, PlacePolicy(0));
net.place[427].number[1] = 1;
net.place[427].number[2] = 18;
net.place[427].number[3] = 162;

InitPlace( 428, "R5", 4, PlacePolicy(0));
net.place[428].number[1] = 1;
net.place[428].number[2] = 18;
net.place[428].number[3] = 163;

InitPlace( 429, "R4", 4, PlacePolicy(0));
net.place[429].number[1] = 1;
net.place[429].number[2] = 18;
net.place[429].number[3] = 164;

InitPlace( 430, "R3", 4, PlacePolicy(0));
net.place[430].number[1] = 1;
net.place[430].number[2] = 18;
net.place[430].number[3] = 165;

InitPlace( 431, "R2", 4, PlacePolicy(0));
net.place[431].number[1] = 1;
net.place[431].number[2] = 18;
net.place[431].number[3] = 166;

InitPlace( 432, "R1", 4, PlacePolicy(0));
net.place[432].number[1] = 1;
net.place[432].number[2] = 18;
net.place[432].number[3] = 167;

InitPlace( 433, "R0", 4, PlacePolicy(0));
net.place[433].number[1] = 1;
net.place[433].number[2] = 18;
net.place[433].number[3] = 168;

InitPlace( 434, "", 4, PlacePolicy(0));
net.place[434].number[1] = 1;
net.place[434].number[2] = 18;
net.place[434].number[3] = 170;

InitPlace( 435, "", 4, PlacePolicy(0));
net.place[435].number[1] = 1;
net.place[435].number[2] = 18;
net.place[435].number[3] = 288;

InitPlace( 436, "", 4, PlacePolicy(0) );
net.place[436].number[1] = 1;
net.place[436].number[2] = 18;
net.place[436].number[3] = 309;

InitPlace( 437, "", 4, PlacePolicy(0) );
net.place[437].number[1] = 1;
net.place[437].number[2] = 18;
net.place[437].number[3] = 318;

InitPlace( 438, "", 4, PlacePolicy(0));
net.place[438].number[1] = 1;
net.place[438].number[2] = 18;
net.place[438].number[3] = 335;

InitPlace( 439, "", 4, PlacePolicy(0));
net.place[439].number[1] = 1;
net.place[439].number[2] = 18;
net.place[439].number[3] = 360;

InitPlace( 440, "", 4, PlacePolicy(0) );
net.place[440].number[1] = 1;
net.place[440].number[2] = 18;
net.place[440].number[3] = 377;

InitPlace( 441, "", 4, PlacePolicy(0));
net.place[441].number[1] = 1;
net.place[441].number[2] = 18;
net.place[441].number[3] = 394;

InitPlace( 442, "", 4, PlacePolicy(0));
net.place[442].number[1] = 1;
net.place[442].number[2] = 18;
net.place[442].number[3] = 427;

InitPlace( 443, "", 4, PlacePolicy(0));
net.place[443].number[1] = 1;
net.place[443].number[2] = 18;
net.place[443].number[3] = 428;

InitPlace( 444, "", 4, PlacePolicy(0));
net.place[444].number[1] = 1;
net.place[444].number[2] = 18;
net.place[444].number[3] = 449;

InitPlace( 445, "", 4, PlacePolicy(0));
net.place[445].number[1] = 1;
net.place[445].number[2] = 18;
net.place[445].number[3] = 457;

InitPlace( 446, "", 4, PlacePolicy(0));
net.place[446].number[1] = 1;
net.place[446].number[2] = 18;
net.place[446].number[3] = 481;

InitPlace( 447, "", 4, PlacePolicy(0));
net.place[447].number[1] = 1;
net.place[447].number[2] = 18;
net.place[447].number[3] = 500;

InitPlace( 448, "", 4, PlacePolicy(0));
net.place[448].number[1] = 1;
net.place[448].number[2] = 18;
net.place[448].number[3] = 533;

InitPlace( 449, "", 4, PlacePolicy(0));
net.place[449].number[1] = 1;
net.place[449].number[2] = 18;
net.place[449].number[3] = 534;

InitPlace( 450, "", 4, PlacePolicy(0));
net.place[450].number[1] = 1;
net.place[450].number[2] = 18;
net.place[450].number[3] = 551;

InitPlace( 451, "", 4, PlacePolicy(0));
net.place[451].number[1] = 1;
net.place[451].number[2] = 18;
net.place[451].number[3] = 584;

InitPlace( 452, "", 4, PlacePolicy(0));
net.place[452].number[1] = 1;
net.place[452].number[2] = 18;
net.place[452].number[3] = 585;

InitPlace( 453, "", 4, PlacePolicy(0));
net.place[453].number[1] = 1;
net.place[453].number[2] = 18;
net.place[453].number[3] = 634;

InitPlace( 454, "", 4, PlacePolicy(0));
net.place[454].number[1] = 1;
net.place[454].number[2] = 18;
net.place[454].number[3] = 635;

InitPlace( 455, "", 4, PlacePolicy(0));
net.place[455].number[1] = 1;
net.place[455].number[2] = 18;
net.place[455].number[3] = 636;

InitPlace( 456, "", 4, PlacePolicy(0));
net.place[456].number[1] = 1;
net.place[456].number[2] = 18;
net.place[456].number[3] = 669;

InitPlace( 457, "", 4, PlacePolicy(0));
net.place[457].number[1] = 1;
net.place[457].number[2] = 18;
net.place[457].number[3] = 670;

InitPlace( 458, "", 4, PlacePolicy(0));
net.place[458].number[1] = 1;
net.place[458].number[2] = 18;
net.place[458].number[3] = 707;

InitPlace( 459, "", 4, PlacePolicy(0));
net.place[459].number[1] = 1;
net.place[459].number[2] = 18;
net.place[459].number[3] = 732;

InitPlace( 460, "", 4, PlacePolicy(0));
net.place[460].number[1] = 1;
net.place[460].number[2] = 18;
net.place[460].number[3] = 749;

InitPlace( 461, "", 4, PlacePolicy(0));
net.place[461].number[1] = 1;
net.place[461].number[2] = 18;
net.place[461].number[3] = 758;

InitPlace( 462, "", 4, PlacePolicy(0));
net.place[462].number[1] = 1;
net.place[462].number[2] = 18;
net.place[462].number[3] = 799;

InitPlace( 463, "", 4, PlacePolicy(0));
net.place[463].number[1] = 1;
net.place[463].number[2] = 18;
net.place[463].number[3] = 808;

InitPlace( 464, "", 4, PlacePolicy(0));
net.place[464].number[1] = 1;
net.place[464].number[2] = 18;
net.place[464].number[3] = 809;

InitPlace( 465, "", 4, PlacePolicy(0));
net.place[465].number[1] = 1;
net.place[465].number[2] = 18;
net.place[465].number[3] = 834;

InitPlace( 466, "", 4, PlacePolicy(0));
net.place[466].number[1] = 1;
net.place[466].number[2] = 18;
net.place[466].number[3] = 843;

InitPlace( 467, "", 4, PlacePolicy(0));
net.place[467].number[1] = 1;
net.place[467].number[2] = 18;
net.place[467].number[3] = 860;

InitPlace( 468, "", 4, PlacePolicy(0) );
net.place[468].number[1] = 1;
net.place[468].number[2] = 18;
net.place[468].number[3] = 885;

InitPlace( 469, "", 4, PlacePolicy(0));
net.place[469].number[1] = 1;
net.place[469].number[2] = 18;
net.place[469].number[3] = 918;

InitPlace( 470, "", 4, PlacePolicy(0));
net.place[470].number[1] = 1;
net.place[470].number[2] = 18;
net.place[470].number[3] = 927;

InitPlace( 471, "", 4, PlacePolicy(0));
net.place[471].number[1] = 1;
net.place[471].number[2] = 18;
net.place[471].number[3] = 936;

InitPlace( 472, "", 4, PlacePolicy(0));
net.place[472].number[1] = 1;
net.place[472].number[2] = 18;
net.place[472].number[3] = 945;

InitPlace( 473, "", 4, PlacePolicy(0));
net.place[473].number[1] = 1;
net.place[473].number[2] = 18;
net.place[473].number[3] = 986;

InitPlace( 474, "", 4, PlacePolicy(0) );
net.place[474].number[1] = 1;
net.place[474].number[2] = 18;
net.place[474].number[3] = 987;

InitPlace( 475, "", 4, PlacePolicy(0));
net.place[475].number[1] = 1;
net.place[475].number[2] = 18;
net.place[475].number[3] = 996;

InitPlace( 476, "", 4, PlacePolicy(0));
net.place[476].number[1] = 1;
net.place[476].number[2] = 18;
net.place[476].number[3] = 1021;

InitPlace( 477, "", 4, PlacePolicy(0));
net.place[477].number[1] = 1;
net.place[477].number[2] = 18;
net.place[477].number[3] = 1030;

InitPlace( 478, "", 4, PlacePolicy(0) );
net.place[478].number[1] = 1;
net.place[478].number[2] = 18;
net.place[478].number[3] = 1047;

InitPlace( 479, "", 4, PlacePolicy(0) );
net.place[479].number[1] = 1;
net.place[479].number[2] = 18;
net.place[479].number[3] = 1064;

InitPlace( 480, "", 4, PlacePolicy(0));
net.place[480].number[1] = 1;
net.place[480].number[2] = 18;
net.place[480].number[3] = 1081;

InitPlace( 481, "", 4, PlacePolicy(0));
net.place[481].number[1] = 1;
net.place[481].number[2] = 18;
net.place[481].number[3] = 1098;

InitPlace( 482, "", 4, PlacePolicy(0));
net.place[482].number[1] = 1;
net.place[482].number[2] = 18;
net.place[482].number[3] = 1107;

InitPlace( 483, "", 4, PlacePolicy(0));
net.place[483].number[1] = 1;
net.place[483].number[2] = 18;
net.place[483].number[3] = 1132;

InitPlace( 484, "", 4, PlacePolicy(0) );
net.place[484].number[1] = 1;
net.place[484].number[2] = 18;
net.place[484].number[3] = 1149;

InitPlace( 485, "", 4, PlacePolicy(0));
net.place[485].number[1] = 1;
net.place[485].number[2] = 18;
net.place[485].number[3] = 1166;

InitPlace( 486, "", 3, PlacePolicy(0));
net.place[486].number[1] = 1;
net.place[486].number[2] = 19;

InitPlace( 487, "", 3, PlacePolicy(0));
net.place[487].number[1] = 1;
net.place[487].number[2] = 20;

InitPlace( 488, "", 3, PlacePolicy(0));
net.place[488].number[1] = 1;
net.place[488].number[2] = 21;

InitPlace( 489, "", 3, PlacePolicy(0));
net.place[489].number[1] = 1;
net.place[489].number[2] = 22;

InitPlace( 490, "", 3, PlacePolicy(1) );
net.place[490].number[1] = 1;
net.place[490].number[2] = 23;

InitPlace( 491, "", 3, PlacePolicy(1) );
net.place[491].number[1] = 1;
net.place[491].number[2] = 24;

InitPlace( 492, "", 3, PlacePolicy(1));
net.place[492].number[1] = 1;
net.place[492].number[2] = 169;

InitPlace( 493, "", 3, PlacePolicy(1));
net.place[493].number[1] = 1;
net.place[493].number[2] = 172;

InitPlace( 494, "", 3, PlacePolicy(1) );
net.place[494].number[1] = 1;
net.place[494].number[2] = 175;

InitPlace( 495, "", 3, PlacePolicy(1));
net.place[495].number[1] = 1;
net.place[495].number[2] = 177;

InitPlace( 496, "", 3, PlacePolicy(1));
net.place[496].number[1] = 1;
net.place[496].number[2] = 179;

InitPlace( 497, "", 3, PlacePolicy(1));
net.place[497].number[1] = 1;
net.place[497].number[2] = 180;

InitPlace( 498, "", 3, PlacePolicy(1));
net.place[498].number[1] = 1;
net.place[498].number[2] = 181;

InitPlace( 499, "", 3, PlacePolicy(1));
net.place[499].number[1] = 1;
net.place[499].number[2] = 182;

InitPlace( 500, "", 3, PlacePolicy(1) );
net.place[500].number[1] = 1;
net.place[500].number[2] = 183;

InitPlace( 501, "", 3, PlacePolicy(1));
net.place[501].number[1] = 1;
net.place[501].number[2] = 184;

InitPlace( 502, "", 3, PlacePolicy(1));
net.place[502].number[1] = 1;
net.place[502].number[2] = 185;

InitPlace( 503, "", 3, PlacePolicy(1));
net.place[503].number[1] = 1;
net.place[503].number[2] = 186;

InitPlace( 504, "", 3, PlacePolicy(1));
net.place[504].number[1] = 1;
net.place[504].number[2] = 187;

InitPlace( 505, "", 3, PlacePolicy(1));
net.place[505].number[1] = 1;
net.place[505].number[2] = 188;

InitPlace( 506, "", 3, PlacePolicy(1) );
net.place[506].number[1] = 1;
net.place[506].number[2] = 189;

InitPlace( 507, "", 3, PlacePolicy(1));
net.place[507].number[1] = 1;
net.place[507].number[2] = 190;

InitPlace( 508, "", 3, PlacePolicy(1));
net.place[508].number[1] = 1;
net.place[508].number[2] = 193;

InitPlace( 509, "", 3, PlacePolicy(0));
net.place[509].number[1] = 1;
net.place[509].number[2] = 197;

InitPlace( 510, "", 3, PlacePolicy(1));
net.place[510].number[1] = 1;
net.place[510].number[2] = 198;

InitPlace( 511, "", 3, PlacePolicy(1));
net.place[511].number[1] = 1;
net.place[511].number[2] = 199;

InitPlace( 512, "", 3, PlacePolicy(1));
net.place[512].number[1] = 1;
net.place[512].number[2] = 200;

InitPlace( 513, "", 3, PlacePolicy(1) );
net.place[513].number[1] = 1;
net.place[513].number[2] = 209;

InitPlace( 514, "", 3, PlacePolicy(1));
net.place[514].number[1] = 1;
net.place[514].number[2] = 210;

InitPlace( 515, "", 3, PlacePolicy(1));
net.place[515].number[1] = 1;
net.place[515].number[2] = 211;

InitPlace( 516, "", 3, PlacePolicy(1) );
net.place[516].number[1] = 1;
net.place[516].number[2] = 212;

InitPlace( 517, "", 3, PlacePolicy(1));
net.place[517].number[1] = 1;
net.place[517].number[2] = 213;

InitPlace( 518, "", 3, PlacePolicy(1));
net.place[518].number[1] = 1;
net.place[518].number[2] = 214;

InitPlace( 519, "", 3, PlacePolicy(1));
net.place[519].number[1] = 1;
net.place[519].number[2] = 217;

InitPlace( 520, "", 3,PlacePolicy(1) );
net.place[520].number[1] = 1;
net.place[520].number[2] = 218;

InitPlace( 521, "", 3, PlacePolicy(1) );
net.place[521].number[1] = 1;
net.place[521].number[2] = 221;

InitPlace( 522, "", 3, PlacePolicy(1));
net.place[522].number[1] = 1;
net.place[522].number[2] = 229;

InitPlace( 523, "", 3, PlacePolicy(1));
net.place[523].number[1] = 1;
net.place[523].number[2] = 232;

InitPlace( 524, "", 3, PlacePolicy(1));
net.place[524].number[1] = 1;
net.place[524].number[2] = 233;

InitPlace( 525, "", 3, PlacePolicy(1));
net.place[525].number[1] = 1;
net.place[525].number[2] = 234;

InitPlace( 526, "", 3, PlacePolicy(1));
net.place[526].number[1] = 1;
net.place[526].number[2] = 237;

InitPlace( 527, "", 3, PlacePolicy(1));
net.place[527].number[1] = 1;
net.place[527].number[2] = 238;

InitPlace( 528, "", 3, PlacePolicy(1));
net.place[528].number[1] = 1;
net.place[528].number[2] = 239;

InitPlace( 529, "", 3, PlacePolicy(1));
net.place[529].number[1] = 1;
net.place[529].number[2] = 242;

InitPlace( 530, "", 3, PlacePolicy(1));
net.place[530].number[1] = 1;
net.place[530].number[2] = 252;

InitPlace( 531, "", 3, PlacePolicy(1));
net.place[531].number[1] = 1;
net.place[531].number[2] = 253;

InitPlace( 532, "", 3, PlacePolicy(1));
net.place[532].number[1] = 1;
net.place[532].number[2] = 254;

InitPlace( 533, "", 3, PlacePolicy(1));
net.place[533].number[1] = 1;
net.place[533].number[2] = 255;

InitPlace( 534, "", 3, PlacePolicy(1));
net.place[534].number[1] = 2;
net.place[534].number[2] = 0;

InitPlace( 535, "", 3, PlacePolicy(1));
net.place[535].number[1] = 2;
net.place[535].number[2] = 1;

InitPlace( 536, "", 3, PlacePolicy(1));
net.place[536].number[1] = 2;
net.place[536].number[2] = 2;

InitPlace( 537, "", 4, PlacePolicy(1));
net.place[537].number[1] = 2;
net.place[537].number[2] = 3;
net.place[537].number[3] = 0;

InitPlace( 538, "", 4, PlacePolicy(1));
net.place[538].number[1] = 2;
net.place[538].number[2] = 3;
net.place[538].number[3] = 1;

InitPlace( 539, "", 4, PlacePolicy(1));
net.place[539].number[1] = 2;
net.place[539].number[2] = 3;
net.place[539].number[3] = 2;

InitPlace( 540, "", 4, PlacePolicy(1));
net.place[540].number[1] = 2;
net.place[540].number[2] = 3;
net.place[540].number[3] = 3;

InitPlace( 541, "", 4, PlacePolicy(1));
net.place[541].number[1] = 2;
net.place[541].number[2] = 3;
net.place[541].number[3] = 5;

InitPlace( 542, "", 4, PlacePolicy(1));
net.place[542].number[1] = 2;
net.place[542].number[2] = 3;
net.place[542].number[3] = 6;

InitPlace( 543, "", 4, PlacePolicy(1));
net.place[543].number[1] = 2;
net.place[543].number[2] = 3;
net.place[543].number[3] = 7;

InitPlace( 544, "", 3, PlacePolicy(1));
net.place[544].number[1] = 2;
net.place[544].number[2] = 4;

InitPlace( 545, "", 4, PlacePolicy(1));
net.place[545].number[1] = 2;
net.place[545].number[2] = 8;
net.place[545].number[3] = 0;

InitPlace( 546, "", 4, PlacePolicy(1));
net.place[546].number[1] = 2;
net.place[546].number[2] = 8;
net.place[546].number[3] = 1;

InitPlace( 547, "", 4, PlacePolicy(1));
net.place[547].number[1] = 2;
net.place[547].number[2] = 8;
net.place[547].number[3] = 2;

InitPlace( 548, "", 4, PlacePolicy(1));
net.place[548].number[1] = 2;
net.place[548].number[2] = 8;
net.place[548].number[3] = 3;

InitPlace( 549, "", 4, PlacePolicy(1));
net.place[549].number[1] = 2;
net.place[549].number[2] = 8;
net.place[549].number[3] = 5;

InitPlace( 550, "", 4, PlacePolicy(1));
net.place[550].number[1] = 2;
net.place[550].number[2] = 8;
net.place[550].number[3] = 6;

InitPlace( 551, "", 4, PlacePolicy(1));
net.place[551].number[1] = 2;
net.place[551].number[2] = 8;
net.place[551].number[3] = 7;

InitPlace( 552, "", 4, PlacePolicy(1));
net.place[552].number[1] = 2;
net.place[552].number[2] = 10;
net.place[552].number[3] = 0;

InitPlace( 553, "", 4, PlacePolicy(1));
net.place[553].number[1] = 2;
net.place[553].number[2] = 10;
net.place[553].number[3] = 1;

InitPlace( 554, "", 4, PlacePolicy(1));
net.place[554].number[1] = 2;
net.place[554].number[2] = 10;
net.place[554].number[3] = 2;

InitPlace( 555, "", 4, PlacePolicy(1));
net.place[555].number[1] = 2;
net.place[555].number[2] = 10;
net.place[555].number[3] = 3;

InitPlace( 556, "", 4, PlacePolicy(1) );
net.place[556].number[1] = 2;
net.place[556].number[2] = 10;
net.place[556].number[3] = 5;

InitPlace( 557, "", 4, PlacePolicy(1));
net.place[557].number[1] = 2;
net.place[557].number[2] = 10;
net.place[557].number[3] = 6;

InitPlace( 558, "", 4, PlacePolicy(1));
net.place[558].number[1] = 2;
net.place[558].number[2] = 10;
net.place[558].number[3] = 7;

InitPlace( 559, "", 4, PlacePolicy(1) );
net.place[559].number[1] = 2;
net.place[559].number[2] = 11;
net.place[559].number[3] = 0;

InitPlace( 560, "", 4, PlacePolicy(1));
net.place[560].number[1] = 2;
net.place[560].number[2] = 11;
net.place[560].number[3] = 1;

InitPlace( 561, "", 4, PlacePolicy(1));
net.place[561].number[1] = 2;
net.place[561].number[2] = 11;
net.place[561].number[3] = 2;

InitPlace( 562, "", 4, PlacePolicy(1));
net.place[562].number[1] = 2;
net.place[562].number[2] = 11;
net.place[562].number[3] = 3;

InitPlace( 563, "", 4, PlacePolicy(1) );
net.place[563].number[1] = 2;
net.place[563].number[2] = 11;
net.place[563].number[3] = 5;

InitPlace( 564, "", 4, PlacePolicy(1));
net.place[564].number[1] = 2;
net.place[564].number[2] = 11;
net.place[564].number[3] = 6;

InitPlace( 565, "", 4, PlacePolicy(1));
net.place[565].number[1] = 2;
net.place[565].number[2] = 11;
net.place[565].number[3] = 7;

InitPlace( 566, "", 4, PlacePolicy(1));
net.place[566].number[1] = 2;
net.place[566].number[2] = 12;
net.place[566].number[3] = 0;

InitPlace( 567, "", 4, PlacePolicy(1));
net.place[567].number[1] = 2;
net.place[567].number[2] = 12;
net.place[567].number[3] = 1;

InitPlace( 568, "", 4, PlacePolicy(1));
net.place[568].number[1] = 2;
net.place[568].number[2] = 12;
net.place[568].number[3] = 2;

InitPlace( 569, "", 4, PlacePolicy(1) );
net.place[569].number[1] = 2;
net.place[569].number[2] = 12;
net.place[569].number[3] = 3;

InitPlace( 570, "", 4, PlacePolicy(1));
net.place[570].number[1] = 2;
net.place[570].number[2] = 12;
net.place[570].number[3] = 5;

InitPlace( 571, "", 4, PlacePolicy(1));
net.place[571].number[1] = 2;
net.place[571].number[2] = 12;
net.place[571].number[3] = 6;

InitPlace( 572, "", 4, PlacePolicy(1));
net.place[572].number[1] = 2;
net.place[572].number[2] = 12;
net.place[572].number[3] = 7;

InitPlace( 573, "", 4, PlacePolicy(1));
net.place[573].number[1] = 2;
net.place[573].number[2] = 13;
net.place[573].number[3] = 0;

InitPlace( 574, "", 4, PlacePolicy(1));
net.place[574].number[1] = 2;
net.place[574].number[2] = 13;
net.place[574].number[3] = 1;

InitPlace( 575, "", 4, PlacePolicy(1));
net.place[575].number[1] = 2;
net.place[575].number[2] = 13;
net.place[575].number[3] = 2;

InitPlace( 576, "", 4, PlacePolicy(1));
net.place[576].number[1] = 2;
net.place[576].number[2] = 13;
net.place[576].number[3] = 3;

InitPlace( 577, "", 4, PlacePolicy(1) );
net.place[577].number[1] = 2;
net.place[577].number[2] = 13;
net.place[577].number[3] = 5;

InitPlace( 578, "", 4, PlacePolicy(1));
net.place[578].number[1] = 2;
net.place[578].number[2] = 13;
net.place[578].number[3] = 6;

InitPlace( 579, "", 4, PlacePolicy(1));
net.place[579].number[1] = 2;
net.place[579].number[2] = 13;
net.place[579].number[3] = 7;

InitPlace( 580, "", 4, PlacePolicy(1) );
net.place[580].number[1] = 2;
net.place[580].number[2] = 14;
net.place[580].number[3] = 0;

InitPlace( 581, "", 4, PlacePolicy(1));
net.place[581].number[1] = 2;
net.place[581].number[2] = 14;
net.place[581].number[3] = 1;

InitPlace( 582, "", 4, PlacePolicy(1));
net.place[582].number[1] = 2;
net.place[582].number[2] = 14;
net.place[582].number[3] = 2;

InitPlace( 583, "", 4, PlacePolicy(1));
net.place[583].number[1] = 2;
net.place[583].number[2] = 14;
net.place[583].number[3] = 3;

InitPlace( 584, "", 4, PlacePolicy(1));
net.place[584].number[1] = 2;
net.place[584].number[2] = 14;
net.place[584].number[3] = 5;

InitPlace( 585, "", 4, PlacePolicy(1));
net.place[585].number[1] = 2;
net.place[585].number[2] = 14;
net.place[585].number[3] = 6;

InitPlace( 586, "", 4, PlacePolicy(1) );
net.place[586].number[1] = 2;
net.place[586].number[2] = 14;
net.place[586].number[3] = 7;

InitPlace( 587, "", 3, PlacePolicy(1));
net.place[587].number[1] = 2;
net.place[587].number[2] = 15;

InitPlace( 588, "", 4, PlacePolicy(1));
net.place[588].number[1] = 2;
net.place[588].number[2] = 16;
net.place[588].number[3] = 0;

InitPlace( 589, "", 4, PlacePolicy(1));
net.place[589].number[1] = 2;
net.place[589].number[2] = 16;
net.place[589].number[3] = 1;

InitPlace( 590, "", 4, PlacePolicy(1));
net.place[590].number[1] = 2;
net.place[590].number[2] = 16;
net.place[590].number[3] = 2;

InitPlace( 591, "", 4, PlacePolicy(1));
net.place[591].number[1] = 2;
net.place[591].number[2] = 16;
net.place[591].number[3] = 3;

InitPlace( 592, "", 4, PlacePolicy(1) );
net.place[592].number[1] = 2;
net.place[592].number[2] = 16;
net.place[592].number[3] = 5;

InitPlace( 593, "", 4, PlacePolicy(1));
net.place[593].number[1] = 2;
net.place[593].number[2] = 16;
net.place[593].number[3] = 6;

InitPlace( 594, "", 4, PlacePolicy(1));
net.place[594].number[1] = 2;
net.place[594].number[2] = 16;
net.place[594].number[3] = 7;

InitPlace( 595, "", 3, PlacePolicy(1));
net.place[595].number[1] = 2;
net.place[595].number[2] = 17;

InitPlace( 596, "Y7", 4, PlacePolicy(0) );
net.place[596].number[1] = 2;
net.place[596].number[2] = 18;
net.place[596].number[3] = 0;

InitPlace( 597, "", 4, PlacePolicy(0));
net.place[597].number[1] = 2;
net.place[597].number[2] = 18;
net.place[597].number[3] = 1;

InitPlace( 598, "", 4, PlacePolicy(0));
net.place[598].number[1] = 2;
net.place[598].number[2] = 18;
net.place[598].number[3] = 2;

InitPlace( 599, "", 4, PlacePolicy(0));
net.place[599].number[1] = 2;
net.place[599].number[2] = 18;
net.place[599].number[3] = 3;

InitPlace( 600, "", 4, PlacePolicy(0));
net.place[600].number[1] = 2;
net.place[600].number[2] = 18;
net.place[600].number[3] = 4;

InitPlace( 601, "", 4, PlacePolicy(0));
net.place[601].number[1] = 2;
net.place[601].number[2] = 18;
net.place[601].number[3] = 5;

InitPlace( 602, "", 4, PlacePolicy(0) );
net.place[602].number[1] = 2;
net.place[602].number[2] = 18;
net.place[602].number[3] = 6;

InitPlace( 603, "", 4, PlacePolicy(0));
net.place[603].number[1] = 2;
net.place[603].number[2] = 18;
net.place[603].number[3] = 7;

InitPlace( 604, "", 4, PlacePolicy(0));
net.place[604].number[1] = 2;
net.place[604].number[2] = 18;
net.place[604].number[3] = 8;

InitPlace( 605, "", 4, PlacePolicy(1));
net.place[605].number[1] = 2;
net.place[605].number[2] = 18;
net.place[605].number[3] = 9;

InitPlace( 606, "", 4, PlacePolicy(0));
net.place[606].number[1] = 2;
net.place[606].number[2] = 18;
net.place[606].number[3] = 10;

InitPlace( 607, "", 4, PlacePolicy(1));
net.place[607].number[1] = 2;
net.place[607].number[2] = 18;
net.place[607].number[3] = 11;

InitPlace( 608, "", 4, PlacePolicy(1) );
net.place[608].number[1] = 2;
net.place[608].number[2] = 18;
net.place[608].number[3] = 12;

InitPlace( 609, "", 4, PlacePolicy(1) );
net.place[609].number[1] = 2;
net.place[609].number[2] = 18;
net.place[609].number[3] = 13;

InitPlace( 610, "", 4, PlacePolicy(1) );
net.place[610].number[1] = 2;
net.place[610].number[2] = 18;
net.place[610].number[3] = 14;

InitPlace( 611, "", 4, PlacePolicy(1));
net.place[611].number[1] = 2;
net.place[611].number[2] = 18;
net.place[611].number[3] = 15;

InitPlace( 612, "", 4, PlacePolicy(1) );
net.place[612].number[1] = 2;
net.place[612].number[2] = 18;
net.place[612].number[3] = 16;

InitPlace( 613, "", 4, PlacePolicy(1) );
net.place[613].number[1] = 2;
net.place[613].number[2] = 18;
net.place[613].number[3] = 17;

InitPlace( 614, "", 4, PlacePolicy(1) );
net.place[614].number[1] = 2;
net.place[614].number[2] = 18;
net.place[614].number[3] = 18;

InitPlace( 615, "", 4, PlacePolicy(1) );
net.place[615].number[1] = 2;
net.place[615].number[2] = 18;
net.place[615].number[3] = 19;

InitPlace( 616, "", 4, PlacePolicy(1) );
net.place[616].number[1] = 2;
net.place[616].number[2] = 18;
net.place[616].number[3] = 20;

InitPlace( 617, "", 4, PlacePolicy(1) );
net.place[617].number[1] = 2;
net.place[617].number[2] = 18;
net.place[617].number[3] = 21;

InitPlace( 618, "", 4, PlacePolicy(0) );
net.place[618].number[1] = 2;
net.place[618].number[2] = 18;
net.place[618].number[3] = 42;

InitPlace( 619, "", 4, PlacePolicy(0) );
net.place[619].number[1] = 2;
net.place[619].number[2] = 18;
net.place[619].number[3] = 43;

InitPlace( 620, "", 4, PlacePolicy(0) );
net.place[620].number[1] = 2;
net.place[620].number[2] = 18;
net.place[620].number[3] = 76;

InitPlace( 621, "R6", 4, PlacePolicy(0));
net.place[621].number[1] = 2;
net.place[621].number[2] = 18;
net.place[621].number[3] = 77;

InitPlace( 622, "GG7", 4, PlacePolicy(0));
net.place[622].number[1] = 2;
net.place[622].number[2] = 18;
net.place[622].number[3] = 78;

InitPlace( 623, "GR6", 4, PlacePolicy(0) );
net.place[623].number[1] = 2;
net.place[623].number[2] = 18;
net.place[623].number[3] = 79;

InitPlace( 624, "", 4, PlacePolicy(0) );
net.place[624].number[1] = 2;
net.place[624].number[2] = 18;
net.place[624].number[3] = 80;

InitPlace( 625, "GG6", 4, PlacePolicy(0) );
net.place[625].number[1] = 2;
net.place[625].number[2] = 18;
net.place[625].number[3] = 83;

InitPlace( 626, "GG5", 4, PlacePolicy(0) );
net.place[626].number[1] = 2;
net.place[626].number[2] = 18;
net.place[626].number[3] = 84;

InitPlace( 627, "GR5", 4, PlacePolicy(0) );
net.place[627].number[1] = 2;
net.place[627].number[2] = 18;
net.place[627].number[3] = 90;

InitPlace( 628, "GG4", 4, PlacePolicy(0) );
net.place[628].number[1] = 2;
net.place[628].number[2] = 18;
net.place[628].number[3] = 91;

InitPlace( 629, "GR4", 4, PlacePolicy(0) );
net.place[629].number[1] = 2;
net.place[629].number[2] = 18;
net.place[629].number[3] = 92;

InitPlace( 630, "GR3", 4, PlacePolicy(0) );
net.place[630].number[1] = 2;
net.place[630].number[2] = 18;
net.place[630].number[3] = 93;

InitPlace( 631, "GG3", 4, PlacePolicy(0) );
net.place[631].number[1] = 2;
net.place[631].number[2] = 18;
net.place[631].number[3] = 94;

InitPlace( 632, "GR2", 4, PlacePolicy(0) );
net.place[632].number[1] = 2;
net.place[632].number[2] = 18;
net.place[632].number[3] = 95;

InitPlace( 633, "GG2", 4, PlacePolicy(0));
net.place[633].number[1] = 2;
net.place[633].number[2] = 18;
net.place[633].number[3] = 96;

InitPlace( 634, "GR1", 4, PlacePolicy(0));
net.place[634].number[1] = 2;
net.place[634].number[2] = 18;
net.place[634].number[3] = 97;

InitPlace( 635, "GG1", 4, PlacePolicy(0) );
net.place[635].number[1] = 2;
net.place[635].number[2] = 18;
net.place[635].number[3] = 98;

InitPlace( 636, "GR0", 4, PlacePolicy(1) );
net.place[636].number[1] = 2;
net.place[636].number[2] = 18;
net.place[636].number[3] = 99;

InitPlace( 637, "GG0", 4, PlacePolicy(0));
net.place[637].number[1] = 2;
net.place[637].number[2] = 18;
net.place[637].number[3] = 100;

InitPlace( 638, "", 4, PlacePolicy(1));
net.place[638].number[1] = 2;
net.place[638].number[2] = 18;
net.place[638].number[3] = 101;

InitPlace( 639, "", 4, PlacePolicy(1) );
net.place[639].number[1] = 2;
net.place[639].number[2] = 18;
net.place[639].number[3] = 102;

InitPlace( 640, "RG0", 4, PlacePolicy(0) );
net.place[640].number[1] = 2;
net.place[640].number[2] = 18;
net.place[640].number[3] = 103;

InitPlace( 641, "M0", 4, PlacePolicy(0));
net.place[641].number[1] = 2;
net.place[641].number[2] = 18;
net.place[641].number[3] = 104;

InitPlace( 642, "Y0", 4, PlacePolicy(0));
net.place[642].number[1] = 2;
net.place[642].number[2] = 18;
net.place[642].number[3] = 105;

InitPlace( 643, "", 4, PlacePolicy(0) );
net.place[643].number[1] = 2;
net.place[643].number[2] = 18;
net.place[643].number[3] = 106;

InitPlace( 644, "G0", 4, PlacePolicy(0));
net.place[644].number[1] = 2;
net.place[644].number[2] = 18;
net.place[644].number[3] = 107;

InitPlace( 645, "", 4, PlacePolicy(1) );
net.place[645].number[1] = 2;
net.place[645].number[2] = 18;
net.place[645].number[3] = 108;

InitPlace( 646, "RG1", 4, PlacePolicy(0));
net.place[646].number[1] = 2;
net.place[646].number[2] = 18;
net.place[646].number[3] = 109;

InitPlace( 647, "", 4, PlacePolicy(1) );
net.place[647].number[1] = 2;
net.place[647].number[2] = 18;
net.place[647].number[3] = 110;

InitPlace( 648, "Y1", 4, PlacePolicy(0));
net.place[648].number[1] = 2;
net.place[648].number[2] = 18;
net.place[648].number[3] = 111;

InitPlace( 649, "", 4, PlacePolicy(0));
net.place[649].number[1] = 2;
net.place[649].number[2] = 18;
net.place[649].number[3] = 112;

InitPlace( 650, "M1", 4, PlacePolicy(0) );
net.place[650].number[1] = 2;
net.place[650].number[2] = 18;
net.place[650].number[3] = 113;

InitPlace( 651, "G1", 4, PlacePolicy(0));
net.place[651].number[1] = 2;
net.place[651].number[2] = 18;
net.place[651].number[3] = 114;

InitPlace( 652, "Y2", 4, PlacePolicy(0) );
net.place[652].number[1] = 2;
net.place[652].number[2] = 18;
net.place[652].number[3] = 115;

InitPlace( 653, "", 4, PlacePolicy(0) );
net.place[653].number[1] = 2;
net.place[653].number[2] = 18;
net.place[653].number[3] = 116;

InitPlace( 654, "M2", 4, PlacePolicy(0));
net.place[654].number[1] = 2;
net.place[654].number[2] = 18;
net.place[654].number[3] = 117;

InitPlace( 655, "G2", 4, PlacePolicy(0) );
net.place[655].number[1] = 2;
net.place[655].number[2] = 18;
net.place[655].number[3] = 118;

InitPlace( 656, "", 4, PlacePolicy(1) );
net.place[656].number[1] = 2;
net.place[656].number[2] = 18;
net.place[656].number[3] = 119;

InitPlace( 657, "RG2", 4, PlacePolicy(0) );
net.place[657].number[1] = 2;
net.place[657].number[2] = 18;
net.place[657].number[3] = 120;

InitPlace( 658, "", 4, PlacePolicy(1) );
net.place[658].number[1] = 2;
net.place[658].number[2] = 18;
net.place[658].number[3] = 121;

InitPlace( 659, "RG3", 4, PlacePolicy(0) );
net.place[659].number[1] = 2;
net.place[659].number[2] = 18;
net.place[659].number[3] = 122;

InitPlace( 660, "", 4, PlacePolicy(1) );
net.place[660].number[1] = 2;
net.place[660].number[2] = 18;
net.place[660].number[3] = 123;

InitPlace( 661, "", 4, PlacePolicy(1) );
net.place[661].number[1] = 2;
net.place[661].number[2] = 18;
net.place[661].number[3] = 124;

InitPlace( 662, "", 4, PlacePolicy(0));
net.place[662].number[1] = 2;
net.place[662].number[2] = 18;
net.place[662].number[3] = 125;

InitPlace( 663, "Y3", 4, PlacePolicy(0));
net.place[663].number[1] = 2;
net.place[663].number[2] = 18;
net.place[663].number[3] = 126;

InitPlace( 664, "G3", 4, PlacePolicy(0));
net.place[664].number[1] = 2;
net.place[664].number[2] = 18;
net.place[664].number[3] = 127;

InitPlace( 665, "M3", 4, PlacePolicy(0) );
net.place[665].number[1] = 2;
net.place[665].number[2] = 18;
net.place[665].number[3] = 128;

InitPlace( 666, "RG4", 4, PlacePolicy(0));
net.place[666].number[1] = 2;
net.place[666].number[2] = 18;
net.place[666].number[3] = 129;

InitPlace( 667, "", 4, PlacePolicy(0));
net.place[667].number[1] = 2;
net.place[667].number[2] = 18;
net.place[667].number[3] = 130;

InitPlace( 668, "Y4", 4, PlacePolicy(0));
net.place[668].number[1] = 2;
net.place[668].number[2] = 18;
net.place[668].number[3] = 131;

InitPlace( 669, "G4", 4, PlacePolicy(0) );
net.place[669].number[1] = 2;
net.place[669].number[2] = 18;
net.place[669].number[3] = 132;

InitPlace( 670, "M4", 4, PlacePolicy(0) );
net.place[670].number[1] = 2;
net.place[670].number[2] = 18;
net.place[670].number[3] = 133;

InitPlace( 671, "", 4, PlacePolicy(1));
net.place[671].number[1] = 2;
net.place[671].number[2] = 18;
net.place[671].number[3] = 134;

InitPlace( 672, "", 4, PlacePolicy(1) );
net.place[672].number[1] = 2;
net.place[672].number[2] = 18;
net.place[672].number[3] = 135;

InitPlace( 673, "", 4, PlacePolicy(1));
net.place[673].number[1] = 2;
net.place[673].number[2] = 18;
net.place[673].number[3] = 136;

InitPlace( 674, "Y5", 4, PlacePolicy(0) );
net.place[674].number[1] = 2;
net.place[674].number[2] = 18;
net.place[674].number[3] = 137;

InitPlace( 675, "", 4, PlacePolicy(0) );
net.place[675].number[1] = 2;
net.place[675].number[2] = 18;
net.place[675].number[3] = 138;

InitPlace( 676, "RG5", 4, PlacePolicy(0) );
net.place[676].number[1] = 2;
net.place[676].number[2] = 18;
net.place[676].number[3] = 139;

InitPlace( 677, "", 4, PlacePolicy(1) );
net.place[677].number[1] = 2;
net.place[677].number[2] = 18;
net.place[677].number[3] = 140;

InitPlace( 678, "G5", 4, PlacePolicy(0));
net.place[678].number[1] = 2;
net.place[678].number[2] = 18;
net.place[678].number[3] = 141;

InitPlace( 679, "M5", 4, PlacePolicy(0) );
net.place[679].number[1] = 2;
net.place[679].number[2] = 18;
net.place[679].number[3] = 142;

InitPlace( 680, "", 4, PlacePolicy(1));
net.place[680].number[1] = 2;
net.place[680].number[2] = 18;
net.place[680].number[3] = 143;

InitPlace( 681, "Y6", 4, PlacePolicy(0) );
net.place[681].number[1] = 2;
net.place[681].number[2] = 18;
net.place[681].number[3] = 144;

InitPlace( 682, "", 4, PlacePolicy(0));
net.place[682].number[1] = 2;
net.place[682].number[2] = 18;
net.place[682].number[3] = 145;

InitPlace( 683, "G6", 4, PlacePolicy(0));
net.place[683].number[1] = 2;
net.place[683].number[2] = 18;
net.place[683].number[3] = 146;

InitPlace( 684, "M6", 4, PlacePolicy(0) );
net.place[684].number[1] = 2;
net.place[684].number[2] = 18;
net.place[684].number[3] = 147;

InitPlace( 685, "RG6", 4, PlacePolicy(0));
net.place[685].number[1] = 2;
net.place[685].number[2] = 18;
net.place[685].number[3] = 148;

InitPlace( 686, "", 4, PlacePolicy(1));
net.place[686].number[1] = 2;
net.place[686].number[2] = 18;
net.place[686].number[3] = 149;

InitPlace( 687, "", 4, PlacePolicy(0));
net.place[687].number[1] = 2;
net.place[687].number[2] = 18;
net.place[687].number[3] = 151;

InitPlace( 688, "GR7", 4, PlacePolicy(0));
net.place[688].number[1] = 2;
net.place[688].number[2] = 18;
net.place[688].number[3] = 152;

InitPlace( 689, "G7", 4, PlacePolicy(0));
net.place[689].number[1] = 2;
net.place[689].number[2] = 18;
net.place[689].number[3] = 153;

InitPlace( 690, "", 4, PlacePolicy(1));
net.place[690].number[1] = 2;
net.place[690].number[2] = 18;
net.place[690].number[3] = 154;

InitPlace( 691, "", 4, PlacePolicy(1));
net.place[691].number[1] = 2;
net.place[691].number[2] = 18;
net.place[691].number[3] = 155;

InitPlace( 692, "M7", 4, PlacePolicy(0));
net.place[692].number[1] = 2;
net.place[692].number[2] = 18;
net.place[692].number[3] = 156;

InitPlace( 693, "RG7", 4, PlacePolicy(0) );
net.place[693].number[1] = 2;
net.place[693].number[2] = 18;
net.place[693].number[3] = 157;

InitPlace( 694, "R7", 4, PlacePolicy(0));
net.place[694].number[1] = 2;
net.place[694].number[2] = 18;
net.place[694].number[3] = 162;

InitPlace( 695, "R5", 4, PlacePolicy(0));
net.place[695].number[1] = 2;
net.place[695].number[2] = 18;
net.place[695].number[3] = 163;

InitPlace( 696, "R4", 4, PlacePolicy(0));
net.place[696].number[1] = 2;
net.place[696].number[2] = 18;
net.place[696].number[3] = 164;

InitPlace( 697, "R3", 4, PlacePolicy(0));
net.place[697].number[1] = 2;
net.place[697].number[2] = 18;
net.place[697].number[3] = 165;

InitPlace( 698, "R2", 4, PlacePolicy(0));
net.place[698].number[1] = 2;
net.place[698].number[2] = 18;
net.place[698].number[3] = 166;

InitPlace( 699, "R1", 4, PlacePolicy(0));
net.place[699].number[1] = 2;
net.place[699].number[2] = 18;
net.place[699].number[3] = 167;

InitPlace( 700, "R0", 4, PlacePolicy(0));
net.place[700].number[1] = 2;
net.place[700].number[2] = 18;
net.place[700].number[3] = 168;

InitPlace( 701, "", 4, PlacePolicy(0));
net.place[701].number[1] = 2;
net.place[701].number[2] = 18;
net.place[701].number[3] = 170;

InitPlace( 702, "", 4, PlacePolicy(0));
net.place[702].number[1] = 2;
net.place[702].number[2] = 18;
net.place[702].number[3] = 288;

InitPlace( 703, "", 4, PlacePolicy(0));
net.place[703].number[1] = 2;
net.place[703].number[2] = 18;
net.place[703].number[3] = 309;

InitPlace( 704, "", 4, PlacePolicy(0));
net.place[704].number[1] = 2;
net.place[704].number[2] = 18;
net.place[704].number[3] = 318;

InitPlace( 705, "", 4, PlacePolicy(0));
net.place[705].number[1] = 2;
net.place[705].number[2] = 18;
net.place[705].number[3] = 335;

InitPlace( 706, "", 4, PlacePolicy(0));
net.place[706].number[1] = 2;
net.place[706].number[2] = 18;
net.place[706].number[3] = 360;

InitPlace( 707, "", 4, PlacePolicy(0));
net.place[707].number[1] = 2;
net.place[707].number[2] = 18;
net.place[707].number[3] = 377;

InitPlace( 708, "", 4, PlacePolicy(0) );
net.place[708].number[1] = 2;
net.place[708].number[2] = 18;
net.place[708].number[3] = 394;

InitPlace( 709, "", 4, PlacePolicy(0));
net.place[709].number[1] = 2;
net.place[709].number[2] = 18;
net.place[709].number[3] = 427;

InitPlace( 710, "", 4, PlacePolicy(0));
net.place[710].number[1] = 2;
net.place[710].number[2] = 18;
net.place[710].number[3] = 428;

InitPlace( 711, "", 4, PlacePolicy(0));
net.place[711].number[1] = 2;
net.place[711].number[2] = 18;
net.place[711].number[3] = 449;

InitPlace( 712, "", 4, PlacePolicy(0));
net.place[712].number[1] = 2;
net.place[712].number[2] = 18;
net.place[712].number[3] = 457;

InitPlace( 713, "", 4, PlacePolicy(0));
net.place[713].number[1] = 2;
net.place[713].number[2] = 18;
net.place[713].number[3] = 481;

InitPlace( 714, "", 4, PlacePolicy(0) );
net.place[714].number[1] = 2;
net.place[714].number[2] = 18;
net.place[714].number[3] = 500;

InitPlace( 715, "", 4, PlacePolicy(0));
net.place[715].number[1] = 2;
net.place[715].number[2] = 18;
net.place[715].number[3] = 533;

InitPlace( 716, "", 4, PlacePolicy(0));
net.place[716].number[1] = 2;
net.place[716].number[2] = 18;
net.place[716].number[3] = 534;

InitPlace( 717, "", 4, PlacePolicy(0));
net.place[717].number[1] = 2;
net.place[717].number[2] = 18;
net.place[717].number[3] = 551;

InitPlace( 718, "", 4, PlacePolicy(0));
net.place[718].number[1] = 2;
net.place[718].number[2] = 18;
net.place[718].number[3] = 584;

InitPlace( 719, "", 4, PlacePolicy(0));
net.place[719].number[1] = 2;
net.place[719].number[2] = 18;
net.place[719].number[3] = 585;

InitPlace( 720, "", 4, PlacePolicy(0) );
net.place[720].number[1] = 2;
net.place[720].number[2] = 18;
net.place[720].number[3] = 634;

InitPlace( 721, "", 4, PlacePolicy(0));
net.place[721].number[1] = 2;
net.place[721].number[2] = 18;
net.place[721].number[3] = 635;

InitPlace( 722, "", 4, PlacePolicy(0));
net.place[722].number[1] = 2;
net.place[722].number[2] = 18;
net.place[722].number[3] = 636;

InitPlace( 723, "", 4, PlacePolicy(0));
net.place[723].number[1] = 2;
net.place[723].number[2] = 18;
net.place[723].number[3] = 669;

InitPlace( 724, "", 4, PlacePolicy(0) );
net.place[724].number[1] = 2;
net.place[724].number[2] = 18;
net.place[724].number[3] = 670;

InitPlace( 725, "", 4, PlacePolicy(0));
net.place[725].number[1] = 2;
net.place[725].number[2] = 18;
net.place[725].number[3] = 707;

InitPlace( 726, "", 4, PlacePolicy(0));
net.place[726].number[1] = 2;
net.place[726].number[2] = 18;
net.place[726].number[3] = 732;

InitPlace( 727, "", 4, PlacePolicy(0));
net.place[727].number[1] = 2;
net.place[727].number[2] = 18;
net.place[727].number[3] = 749;

InitPlace( 728, "", 4, PlacePolicy(0));
net.place[728].number[1] = 2;
net.place[728].number[2] = 18;
net.place[728].number[3] = 758;

InitPlace( 729, "", 4, PlacePolicy(0) );
net.place[729].number[1] = 2;
net.place[729].number[2] = 18;
net.place[729].number[3] = 799;

InitPlace( 730, "", 4, PlacePolicy(0));
net.place[730].number[1] = 2;
net.place[730].number[2] = 18;
net.place[730].number[3] = 808;

InitPlace( 731, "", 4, PlacePolicy(0));
net.place[731].number[1] = 2;
net.place[731].number[2] = 18;
net.place[731].number[3] = 809;

InitPlace( 732, "", 4, PlacePolicy(0));
net.place[732].number[1] = 2;
net.place[732].number[2] = 18;
net.place[732].number[3] = 834;

InitPlace( 733, "", 4, PlacePolicy(0));
net.place[733].number[1] = 2;
net.place[733].number[2] = 18;
net.place[733].number[3] = 843;

InitPlace( 734, "", 4, PlacePolicy(0) );
net.place[734].number[1] = 2;
net.place[734].number[2] = 18;
net.place[734].number[3] = 860;

InitPlace( 735, "", 4, PlacePolicy(0));
net.place[735].number[1] = 2;
net.place[735].number[2] = 18;
net.place[735].number[3] = 885;

InitPlace( 736, "", 4, PlacePolicy(0));
net.place[736].number[1] = 2;
net.place[736].number[2] = 18;
net.place[736].number[3] = 918;

InitPlace( 737, "", 4, PlacePolicy(0));
net.place[737].number[1] = 2;
net.place[737].number[2] = 18;
net.place[737].number[3] = 927;

InitPlace( 738, "", 4, PlacePolicy(0) );
net.place[738].number[1] = 2;
net.place[738].number[2] = 18;
net.place[738].number[3] = 936;

InitPlace( 739, "", 4, PlacePolicy(0));
net.place[739].number[1] = 2;
net.place[739].number[2] = 18;
net.place[739].number[3] = 945;

InitPlace( 740, "", 4, PlacePolicy(0));
net.place[740].number[1] = 2;
net.place[740].number[2] = 18;
net.place[740].number[3] = 986;

InitPlace( 741, "", 4, PlacePolicy(0));
net.place[741].number[1] = 2;
net.place[741].number[2] = 18;
net.place[741].number[3] = 987;

InitPlace( 742, "", 4, PlacePolicy(0));
net.place[742].number[1] = 2;
net.place[742].number[2] = 18;
net.place[742].number[3] = 996;

InitPlace( 743, "", 4, PlacePolicy(0) );
net.place[743].number[1] = 2;
net.place[743].number[2] = 18;
net.place[743].number[3] = 1021;

InitPlace( 744, "", 4, PlacePolicy(0));
net.place[744].number[1] = 2;
net.place[744].number[2] = 18;
net.place[744].number[3] = 1030;

InitPlace( 745, "", 4, PlacePolicy(0) );
net.place[745].number[1] = 2;
net.place[745].number[2] = 18;
net.place[745].number[3] = 1047;

InitPlace( 746, "", 4, PlacePolicy(0));
net.place[746].number[1] = 2;
net.place[746].number[2] = 18;
net.place[746].number[3] = 1064;

InitPlace( 747, "", 4, PlacePolicy(0));
net.place[747].number[1] = 2;
net.place[747].number[2] = 18;
net.place[747].number[3] = 1081;

InitPlace( 748, "", 4, PlacePolicy(0) );
net.place[748].number[1] = 2;
net.place[748].number[2] = 18;
net.place[748].number[3] = 1098;

InitPlace( 749, "", 4, PlacePolicy(0));
net.place[749].number[1] = 2;
net.place[749].number[2] = 18;
net.place[749].number[3] = 1107;

InitPlace( 750, "", 4, PlacePolicy(0));
net.place[750].number[1] = 2;
net.place[750].number[2] = 18;
net.place[750].number[3] = 1132;

InitPlace( 751, "", 4, PlacePolicy(0));
net.place[751].number[1] = 2;
net.place[751].number[2] = 18;
net.place[751].number[3] = 1149;

InitPlace( 752, "", 4, PlacePolicy(0));
net.place[752].number[1] = 2;
net.place[752].number[2] = 18;
net.place[752].number[3] = 1166;

InitPlace( 753, "", 3, PlacePolicy(0) );
net.place[753].number[1] = 2;
net.place[753].number[2] = 19;

InitPlace( 754, "", 3, PlacePolicy(0));
net.place[754].number[1] = 2;
net.place[754].number[2] = 20;

InitPlace( 755, "", 3, PlacePolicy(0));
net.place[755].number[1] = 2;
net.place[755].number[2] = 21;

InitPlace( 756, "", 3, PlacePolicy(0));
net.place[756].number[1] = 2;
net.place[756].number[2] = 22;

InitPlace( 757, "", 3, PlacePolicy(1) );
net.place[757].number[1] = 2;
net.place[757].number[2] = 23;

InitPlace( 758, "", 3, PlacePolicy(1) );
net.place[758].number[1] = 2;
net.place[758].number[2] = 24;

InitPlace( 759, "", 3, PlacePolicy(1));
net.place[759].number[1] = 2;
net.place[759].number[2] = 169;

InitPlace( 760, "", 3, PlacePolicy(1));
net.place[760].number[1] = 2;
net.place[760].number[2] = 172;

InitPlace( 761, "", 3, PlacePolicy(1));
net.place[761].number[1] = 2;
net.place[761].number[2] = 175;

InitPlace( 762, "", 3, PlacePolicy(1));
net.place[762].number[1] = 2;
net.place[762].number[2] = 177;

InitPlace( 763, "", 3, PlacePolicy(1));
net.place[763].number[1] = 2;
net.place[763].number[2] = 179;

InitPlace( 764, "", 3, PlacePolicy(1) );
net.place[764].number[1] = 2;
net.place[764].number[2] = 180;

InitPlace( 765, "", 3, PlacePolicy(1));
net.place[765].number[1] = 2;
net.place[765].number[2] = 181;

InitPlace( 766, "", 3, PlacePolicy(1));
net.place[766].number[1] = 2;
net.place[766].number[2] = 182;

InitPlace( 767, "", 3, PlacePolicy(1));
net.place[767].number[1] = 2;
net.place[767].number[2] = 183;

InitPlace( 768, "", 3, PlacePolicy(1));
net.place[768].number[1] = 2;
net.place[768].number[2] = 184;

InitPlace( 769, "", 3, PlacePolicy(1) );
net.place[769].number[1] = 2;
net.place[769].number[2] = 185;

InitPlace( 770, "", 3, PlacePolicy(1));
net.place[770].number[1] = 2;
net.place[770].number[2] = 186;

InitPlace( 771, "", 3, PlacePolicy(1));
net.place[771].number[1] = 2;
net.place[771].number[2] = 187;

InitPlace( 772, "", 3, PlacePolicy(1));
net.place[772].number[1] = 2;
net.place[772].number[2] = 188;

InitPlace( 773, "", 3, PlacePolicy(1));
net.place[773].number[1] = 2;
net.place[773].number[2] = 189;

InitPlace( 774, "", 3, PlacePolicy(1));
net.place[774].number[1] = 2;
net.place[774].number[2] = 190;

InitPlace( 775, "", 3, PlacePolicy(1));
net.place[775].number[1] = 2;
net.place[775].number[2] = 193;

InitPlace( 776, "", 3, PlacePolicy(0));
net.place[776].number[1] = 2;
net.place[776].number[2] = 197;

InitPlace( 777, "", 3, PlacePolicy(1));
net.place[777].number[1] = 2;
net.place[777].number[2] = 198;

InitPlace( 778, "", 3, PlacePolicy(1));
net.place[778].number[1] = 2;
net.place[778].number[2] = 199;

InitPlace( 779, "", 3, PlacePolicy(1));
net.place[779].number[1] = 2;
net.place[779].number[2] = 200;

InitPlace( 780, "", 3, PlacePolicy(1));
net.place[780].number[1] = 2;
net.place[780].number[2] = 209;

InitPlace( 781, "", 3, PlacePolicy(1));
net.place[781].number[1] = 2;
net.place[781].number[2] = 210;

InitPlace( 782, "", 3, PlacePolicy(1));
net.place[782].number[1] = 2;
net.place[782].number[2] = 211;

InitPlace( 783, "", 3, PlacePolicy(1));
net.place[783].number[1] = 2;
net.place[783].number[2] = 212;

InitPlace( 784, "", 3, PlacePolicy(1));
net.place[784].number[1] = 2;
net.place[784].number[2] = 213;

InitPlace( 785, "", 3, PlacePolicy(1));
net.place[785].number[1] = 2;
net.place[785].number[2] = 214;

InitPlace( 786, "", 3, PlacePolicy(1));
net.place[786].number[1] = 2;
net.place[786].number[2] = 217;

InitPlace( 787, "", 3, PlacePolicy(1));
net.place[787].number[1] = 2;
net.place[787].number[2] = 218;

InitPlace( 788, "", 3, PlacePolicy(1));
net.place[788].number[1] = 2;
net.place[788].number[2] = 221;

InitPlace( 789, "", 3, PlacePolicy(1));
net.place[789].number[1] = 2;
net.place[789].number[2] = 229;

InitPlace( 790, "", 3, PlacePolicy(1));
net.place[790].number[1] = 2;
net.place[790].number[2] = 232;

InitPlace( 791, "", 3, PlacePolicy(1));
net.place[791].number[1] = 2;
net.place[791].number[2] = 233;

InitPlace( 792, "", 3, PlacePolicy(1) );
net.place[792].number[1] = 2;
net.place[792].number[2] = 234;

InitPlace( 793, "", 3, PlacePolicy(1));
net.place[793].number[1] = 2;
net.place[793].number[2] = 237;

InitPlace( 794, "", 3, PlacePolicy(1));
net.place[794].number[1] = 2;
net.place[794].number[2] = 238;

InitPlace( 795, "", 3, PlacePolicy(1));
net.place[795].number[1] = 2;
net.place[795].number[2] = 239;

InitPlace( 796, "", 3, PlacePolicy(1));
net.place[796].number[1] = 2;
net.place[796].number[2] = 242;

InitPlace( 797, "", 3, PlacePolicy(1));
net.place[797].number[1] = 2;
net.place[797].number[2] = 252;

InitPlace( 798, "", 3, PlacePolicy(1));
net.place[798].number[1] = 2;
net.place[798].number[2] = 253;

InitPlace( 799, "", 3, PlacePolicy(1));
net.place[799].number[1] = 2;
net.place[799].number[2] = 254;

InitPlace( 800, "", 3,PlacePolicy(1) );
net.place[800].number[1] = 2;
net.place[800].number[2] = 255;

InitPlace( 801, "", 3, PlacePolicy(1));
net.place[801].number[1] = 3;
net.place[801].number[2] = 0;

InitPlace( 802, "", 3, PlacePolicy(1));
net.place[802].number[1] = 3;
net.place[802].number[2] = 1;

InitPlace( 803, "", 3, PlacePolicy(1));
net.place[803].number[1] = 3;
net.place[803].number[2] = 2;

InitPlace( 804, "", 4, PlacePolicy(1));
net.place[804].number[1] = 3;
net.place[804].number[2] = 3;
net.place[804].number[3] = 0;

InitPlace( 805, "", 4, PlacePolicy(1));
net.place[805].number[1] = 3;
net.place[805].number[2] = 3;
net.place[805].number[3] = 1;

InitPlace( 806, "", 4, PlacePolicy(1) );
net.place[806].number[1] = 3;
net.place[806].number[2] = 3;
net.place[806].number[3] = 2;

InitPlace( 807, "", 4, PlacePolicy(1));
net.place[807].number[1] = 3;
net.place[807].number[2] = 3;
net.place[807].number[3] = 3;

InitPlace( 808, "", 4, PlacePolicy(1));
net.place[808].number[1] = 3;
net.place[808].number[2] = 3;
net.place[808].number[3] = 5;

InitPlace( 809, "", 4, PlacePolicy(1));
net.place[809].number[1] = 3;
net.place[809].number[2] = 3;
net.place[809].number[3] = 6;

InitPlace( 810, "", 4, PlacePolicy(1));
net.place[810].number[1] = 3;
net.place[810].number[2] = 3;
net.place[810].number[3] = 7;

InitPlace( 811, "", 3, PlacePolicy(1));
net.place[811].number[1] = 3;
net.place[811].number[2] = 4;

InitPlace( 812, "", 4, PlacePolicy(1) );
net.place[812].number[1] = 3;
net.place[812].number[2] = 8;
net.place[812].number[3] = 0;

InitPlace( 813, "", 4, PlacePolicy(1));
net.place[813].number[1] = 3;
net.place[813].number[2] = 8;
net.place[813].number[3] = 1;

InitPlace( 814, "", 4, PlacePolicy(1));
net.place[814].number[1] = 3;
net.place[814].number[2] = 8;
net.place[814].number[3] = 2;

InitPlace( 815, "", 4, PlacePolicy(1));
net.place[815].number[1] = 3;
net.place[815].number[2] = 8;
net.place[815].number[3] = 3;

InitPlace( 816, "", 4, PlacePolicy(1));
net.place[816].number[1] = 3;
net.place[816].number[2] = 8;
net.place[816].number[3] = 5;

InitPlace( 817, "", 4, PlacePolicy(1) );
net.place[817].number[1] = 3;
net.place[817].number[2] = 8;
net.place[817].number[3] = 6;

InitPlace( 818, "", 4, PlacePolicy(1));
net.place[818].number[1] = 3;
net.place[818].number[2] = 8;
net.place[818].number[3] = 7;

InitPlace( 819, "", 4, PlacePolicy(1));
net.place[819].number[1] = 3;
net.place[819].number[2] = 10;
net.place[819].number[3] = 0;

InitPlace( 820, "", 4, PlacePolicy(1));
net.place[820].number[1] = 3;
net.place[820].number[2] = 10;
net.place[820].number[3] = 1;

InitPlace( 821, "", 4, PlacePolicy(1));
net.place[821].number[1] = 3;
net.place[821].number[2] = 10;
net.place[821].number[3] = 2;

InitPlace( 822, "", 4, PlacePolicy(1));
net.place[822].number[1] = 3;
net.place[822].number[2] = 10;
net.place[822].number[3] = 3;

InitPlace( 823, "", 4, PlacePolicy(1));
net.place[823].number[1] = 3;
net.place[823].number[2] = 10;
net.place[823].number[3] = 5;

InitPlace( 824, "", 4, PlacePolicy(1));
net.place[824].number[1] = 3;
net.place[824].number[2] = 10;
net.place[824].number[3] = 6;

InitPlace( 825, "", 4, PlacePolicy(1));
net.place[825].number[1] = 3;
net.place[825].number[2] = 10;
net.place[825].number[3] = 7;

InitPlace( 826, "", 4, PlacePolicy(1));
net.place[826].number[1] = 3;
net.place[826].number[2] = 11;
net.place[826].number[3] = 0;

InitPlace( 827, "", 4, PlacePolicy(1));
net.place[827].number[1] = 3;
net.place[827].number[2] = 11;
net.place[827].number[3] = 1;

InitPlace( 828, "", 4, PlacePolicy(1));
net.place[828].number[1] = 3;
net.place[828].number[2] = 11;
net.place[828].number[3] = 2;

InitPlace( 829, "", 4, PlacePolicy(1));
net.place[829].number[1] = 3;
net.place[829].number[2] = 11;
net.place[829].number[3] = 3;

InitPlace( 830, "", 4, PlacePolicy(1));
net.place[830].number[1] = 3;
net.place[830].number[2] = 11;
net.place[830].number[3] = 5;

InitPlace( 831, "", 4, PlacePolicy(1));
net.place[831].number[1] = 3;
net.place[831].number[2] = 11;
net.place[831].number[3] = 6;

InitPlace( 832, "", 4, PlacePolicy(1));
net.place[832].number[1] = 3;
net.place[832].number[2] = 11;
net.place[832].number[3] = 7;

InitPlace( 833, "", 4, PlacePolicy(1) );
net.place[833].number[1] = 3;
net.place[833].number[2] = 12;
net.place[833].number[3] = 0;

InitPlace( 834, "", 4, PlacePolicy(1));
net.place[834].number[1] = 3;
net.place[834].number[2] = 12;
net.place[834].number[3] = 1;


DefineNet2();
}
#endif /* SEGMENTED_MEMORY */
#endif /* CONST_NET */

