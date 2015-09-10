/* this file was generated from the NETMAN file:
	C:\NETMAN\Test\Test.npn
	07/09/98 15:09:11
*/

#include "petri.h"
#include "userfunc.h"

TOKEN_VALUE a1;
TOKEN_VALUE a2;
TOKEN_VALUE a3;
TOKEN_VALUE bay;
TOKEN_VALUE intersection;
TOKEN_VALUE vehicle;

#include "Mycode.h"
void TF_1_130 (TRANS_NUMBER tran)
{
GetSetForNextRelease(intersection);
}

void TF_1_133 (TRANS_NUMBER tran)
{
movements[intersection][0] = 1;
state[intersection][0] = 1;
PerOnTime(intersection, 0, 2);
}

void TF_1_140 (TRANS_NUMBER tran)
{
movements[intersection][0]=0;
state[intersection][0] = 0;
PerOnTime(intersection, 0, 3);
}

void TF_1_135 (TRANS_NUMBER tran)
{
state[intersection][0] = 3;
}

void TF_1_141 (TRANS_NUMBER tran)
{
movements[intersection][1]=1;
state[intersection][1] = 1;
PerOnTime(intersection, 1, 2);
}

void TF_1_143 (TRANS_NUMBER tran)
{
movements[intersection][1]=0;
state[intersection][1] = 0;
PerOnTime(intersection, 1, 3);
}

void TF_1_142 (TRANS_NUMBER tran)
{
state[intersection][1] = 3;
}

void TF_1_145 (TRANS_NUMBER tran)
{
movements[intersection][2]=1;
state[intersection][2] = 1;
PerOnTime(intersection, 2, 2);
}

void TF_1_152 (TRANS_NUMBER tran)
{
movements[intersection][2]=0;
state[intersection][2] = 0;
PerOnTime(intersection, 2, 3);
}

void TF_1_147 (TRANS_NUMBER tran)
{
state[intersection][2] = 3;
}

void TF_1_157 (TRANS_NUMBER tran)
{
movements[intersection][3]=1;
state[intersection][3] = 1;
PerOnTime(intersection, 3, 2);
}

void TF_1_160 (TRANS_NUMBER tran)
{
movements[intersection][3]=0;
state[intersection][3] = 0;
PerOnTime(intersection, 3, 3);
}

void TF_1_158 (TRANS_NUMBER tran)
{
state[intersection][3] = 3;
}

void TF_1_168 (TRANS_NUMBER tran)
{
movements[intersection][4]=0;
state[intersection][4] = 0;
PerOnTime(intersection, 4, 3);
}

void TF_1_166 (TRANS_NUMBER tran)
{
state[intersection][4] = 3;
}

void TF_1_165 (TRANS_NUMBER tran)
{
movements[intersection][4]=1;
state[intersection][4] = 1;
PerOnTime(intersection, 4, 2);
}

void TF_1_176 (TRANS_NUMBER tran)
{
movements[intersection][5]=0;
state[intersection][5] = 0;
PerOnTime(intersection, 5, 3);
}

void TF_1_174 (TRANS_NUMBER tran)
{
state[intersection][5] = 3;
}

void TF_1_173 (TRANS_NUMBER tran)
{
movements[intersection][5]=1;
state[intersection][5] = 1;
PerOnTime(intersection, 5, 2);
}

void TF_1_184 (TRANS_NUMBER tran)
{
movements[intersection][6]=0;
state[intersection][6] = 0;
PerOnTime(intersection, 6, 3);
}

void TF_1_182 (TRANS_NUMBER tran)
{
state[intersection][6] = 3;
}

void TF_1_181 (TRANS_NUMBER tran)
{
movements[intersection][6]=1;
state[intersection][6] = 1;
PerOnTime(intersection, 6, 2);
}

void TF_1_192 (TRANS_NUMBER tran)
{
movements[intersection][7]=0;
state[intersection][7] = 0;
PerOnTime(intersection, 7, 3);
}

void TF_1_0 (TRANS_NUMBER tran)
{
state[intersection][7] = 3;
}

void TF_1_189 (TRANS_NUMBER tran)
{
movements[intersection][7]=1;
state[intersection][7] = 1;
PerOnTime(intersection, 7, 2);
}

double TT_1_164 (TRANS_NUMBER tran)
{
return  MinToMax[intersection][3];
}

void TF_1_164 (TRANS_NUMBER tran)
{
state[intersection][3] = 2;
change(intersection,3);
}

BOOLEAN TE_1_190 (TRANS_NUMBER tran)
{
return ForceOff[intersection][3];
}

void TF_1_190 (TRANS_NUMBER tran)
{
ForceOff[intersection][3] = 0;
state[intersection][3] = 2;
change(intersection,2);
}

double TT_1_156 (TRANS_NUMBER tran)
{
return MinToMax[intersection][2];
}

void TF_1_156 (TRANS_NUMBER tran)
{
state[intersection][2] = 2;
change(intersection,3);
}

BOOLEAN TE_1_183 (TRANS_NUMBER tran)
{
return ForceOff[intersection][2];
}

void TF_1_183 (TRANS_NUMBER tran)
{
ForceOff[intersection][2] = 0;
state[intersection][2] = 2;
change(intersection,2);
}

double TT_1_149 (TRANS_NUMBER tran)
{
return MinToMax[intersection][1];
}

void TF_1_149 (TRANS_NUMBER tran)
{
state[intersection][1] = 2;
change(intersection,3);
}

BOOLEAN TE_1_175 (TRANS_NUMBER tran)
{
return ForceOff[intersection][1];
}

void TF_1_175 (TRANS_NUMBER tran)
{
ForceOff[intersection][1] = 0;
state[intersection][1] = 2;
change(intersection,2);
}

double TT_1_196 (TRANS_NUMBER tran)
{
return  MinToMax[intersection][7];
}

void TF_1_196 (TRANS_NUMBER tran)
{
state[intersection][7] = 2;
change(intersection,3);
}

BOOLEAN TE_1_199 (TRANS_NUMBER tran)
{
return ForceOff[intersection][7];
}

void TF_1_199 (TRANS_NUMBER tran)
{
ForceOff[intersection][7] = 0;
state[intersection][7] = 2;
change(intersection,2);
}

double TT_1_187 (TRANS_NUMBER tran)
{
return MinToMax[intersection][6];
}

void TF_1_187 (TRANS_NUMBER tran)
{
state[intersection][6] = 2;
change(intersection,3);
}

BOOLEAN TE_1_198 (TRANS_NUMBER tran)
{
return ForceOff[intersection][6];
}

void TF_1_198 (TRANS_NUMBER tran)
{
ForceOff[intersection][6] = 0;
state[intersection][6] = 2;
change(intersection,2);
}

double TT_1_180 (TRANS_NUMBER tran)
{
return MinToMax[intersection][5];
}

void TF_1_180 (TRANS_NUMBER tran)
{
state[intersection][5] = 2;
change(intersection,3);
}

BOOLEAN TE_1_197 (TRANS_NUMBER tran)
{
return ForceOff[intersection][5];
}

void TF_1_197 (TRANS_NUMBER tran)
{
ForceOff[intersection][5] = 0;
state[intersection][5] = 2;
change(intersection,2);
}

double TT_1_172 (TRANS_NUMBER tran)
{
return MinToMax[intersection][4];
}

void TF_1_172 (TRANS_NUMBER tran)
{
state[intersection][4] = 2;
change(intersection,3);
}

BOOLEAN TE_1_191 (TRANS_NUMBER tran)
{
return ForceOff[intersection][4];
}

void TF_1_191 (TRANS_NUMBER tran)
{
ForceOff[intersection][4] = 0;
state[intersection][4] = 2;
change(intersection,2);
}

BOOLEAN TE_3_254 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_254 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

BOOLEAN TE_3_255 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_255 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

void TF_3_261 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 1);
if (vehicle < 0) bay = 5;
else bay = LeftCheck(intersection,bay);
}

void TF_3_245 (TRANS_NUMBER tran)
{
bay=1;
out(vehicle, intersection, bay, 3);
}

double TT_3_249 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

double TT_3_247 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

void TF_3_247 (TRANS_NUMBER tran)
{
if (vehicle < 0) bay = 5;
else bay = RightCheck(intersection, bay);
}

void TF_0_8 (TRANS_NUMBER tran)
{
SigCheck();
}

void TF_1_112 (TRANS_NUMBER tran)
{
UpdateSig(intersection,6);
}

void TF_1_108 (TRANS_NUMBER tran)
{
UpdateSig(intersection,4);
}

void TF_1_106 (TRANS_NUMBER tran)
{
UpdateSig(intersection,3);
}

void TF_1_104 (TRANS_NUMBER tran)
{
UpdateSig(intersection,2);
}

void TF_1_100 (TRANS_NUMBER tran)
{
UpdateSig(intersection,0);
}

void TF_1_84 (TRANS_NUMBER tran)
{
UpdateSig(intersection,7);
}

void TF_1_81 (TRANS_NUMBER tran)
{
UpdateSig(intersection,6);
}

void TF_1_80 (TRANS_NUMBER tran)
{
UpdateSig(intersection,5);
}

void TF_1_78 (TRANS_NUMBER tran)
{
UpdateSig(intersection,4);
}

void TF_1_76 (TRANS_NUMBER tran)
{
UpdateSig(intersection,2);
}

void TF_1_74 (TRANS_NUMBER tran)
{
UpdateSig(intersection,1);
}

void TF_1_72 (TRANS_NUMBER tran)
{
UpdateSig(intersection,0);
}

void TF_1_96 (TRANS_NUMBER tran)
{
UpdateSig(intersection,5);
}

void TF_1_95 (TRANS_NUMBER tran)
{
UpdateSig(intersection,4);
}

void TF_1_92 (TRANS_NUMBER tran)
{
UpdateSig(intersection,3);
}

void TF_1_87 (TRANS_NUMBER tran)
{
UpdateSig(intersection,1);
}

void TF_1_86 (TRANS_NUMBER tran)
{
UpdateSig(intersection,0);
}

void TF_1_69 (TRANS_NUMBER tran)
{
UpdateSig(intersection,7);
}

void TF_1_68 (TRANS_NUMBER tran)
{
UpdateSig(intersection,6);
}

void TF_1_67 (TRANS_NUMBER tran)
{
UpdateSig(intersection,5);
}

void TF_1_64 (TRANS_NUMBER tran)
{
UpdateSig(intersection,4);
}

void TF_1_62 (TRANS_NUMBER tran)
{
UpdateSig(intersection,3);
}

void TF_1_60 (TRANS_NUMBER tran)
{
UpdateSig(intersection,1);
}

void TF_1_58 (TRANS_NUMBER tran)
{
UpdateSig(intersection,0);
}

void TF_1_55 (TRANS_NUMBER tran)
{
UpdateSig(intersection,7);
}

void TF_1_53 (TRANS_NUMBER tran)
{
UpdateSig(intersection,6);
}

void TF_1_51 (TRANS_NUMBER tran)
{
UpdateSig(intersection,4);
}

void TF_1_49 (TRANS_NUMBER tran)
{
UpdateSig(intersection,3);
}

void TF_1_47 (TRANS_NUMBER tran)
{
UpdateSig(intersection,2);
}

void TF_1_45 (TRANS_NUMBER tran)
{
UpdateSig(intersection,1);
}

void TF_1_44 (TRANS_NUMBER tran)
{
UpdateSig(intersection,0);
}

void TF_1_41 (TRANS_NUMBER tran)
{
UpdateSig(intersection,7);
}

void TF_1_39 (TRANS_NUMBER tran)
{
UpdateSig(intersection,6);
}

void TF_1_37 (TRANS_NUMBER tran)
{
UpdateSig(intersection,5);
}

void TF_1_36 (TRANS_NUMBER tran)
{
UpdateSig(intersection,4);
}

BOOLEAN TE_1_35 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][4];
}

void TF_1_33 (TRANS_NUMBER tran)
{
UpdateSig(intersection,3);
}

void TF_1_32 (TRANS_NUMBER tran)
{
UpdateSig(intersection,2);
}

void TF_1_29 (TRANS_NUMBER tran)
{
UpdateSig(intersection,0);
}

void TF_1_28 (TRANS_NUMBER tran)
{
UpdateSig(intersection,7);
}

void TF_1_23 (TRANS_NUMBER tran)
{
UpdateSig(intersection,5);
}

void TF_1_21 (TRANS_NUMBER tran)
{
UpdateSig(intersection,3);
}

void TF_1_19 (TRANS_NUMBER tran)
{
UpdateSig(intersection,2);
}

void TF_1_17 (TRANS_NUMBER tran)
{
UpdateSig(intersection,1);
}

void TF_1_15 (TRANS_NUMBER tran)
{
UpdateSig(intersection,0);
}

BOOLEAN TE_1_4 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][1];
}

void TF_1_14 (TRANS_NUMBER tran)
{
UpdateSig(intersection,7);
}

void TF_1_12 (TRANS_NUMBER tran)
{
UpdateSig(intersection,6);
}

void TF_1_8 (TRANS_NUMBER tran)
{
UpdateSig(intersection,5);
}

void TF_1_7 (TRANS_NUMBER tran)
{
UpdateSig(intersection,4);
}

void TF_1_3 (TRANS_NUMBER tran)
{
UpdateSig(intersection,3);
}

void TF_1_2 (TRANS_NUMBER tran)
{
UpdateSig(intersection,2);
}

void TF_1_1 (TRANS_NUMBER tran)
{
UpdateSig(intersection,1);
}

void TF_3_206 (TRANS_NUMBER tran)
{
bay = 7;
}

void TF_3_266 (TRANS_NUMBER tran)
{
bay = 1;

out(vehicle, intersection, bay, 3);
}

void TF_3_265 (TRANS_NUMBER tran)
{
bay = 1;
out(vehicle, intersection, bay, 3);
}

BOOLEAN TE_3_273 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_273 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

void TF_3_213 (TRANS_NUMBER tran)
{
bay =2;
}

void TF_8_4 (TRANS_NUMBER tran)
{
if (intersection == 2) intersection=3;
else intersection=2;
}

void TF_12_4 (TRANS_NUMBER tran)
{
if (intersection == 2) intersection=5;
else intersection=2;
}

void TF_6_4 (TRANS_NUMBER tran)
{
if (intersection == 1) intersection=2;
else intersection=1;
}

double TT_0_36 (TRANS_NUMBER tran)
{
return VehInpTime(4,5);
}

void TF_0_36 (TRANS_NUMBER tran)
{
intersection = 4;
bay = 5;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

double TT_0_34 (TRANS_NUMBER tran)
{
return VehInpTime(4,3);
}

void TF_0_34 (TRANS_NUMBER tran)
{
intersection = 4;
bay = 3;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

double TT_0_35 (TRANS_NUMBER tran)
{
return VehInpTime(4,1);
}

void TF_0_35 (TRANS_NUMBER tran)
{
intersection = 4;
bay =1;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

void TF_3_236 (TRANS_NUMBER tran)
{
bay = 4;
}

double TT_3_225 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

double TT_1_194 (TRANS_NUMBER tran)
{
return MinTime[intersection][7];
}

double TT_1_186 (TRANS_NUMBER tran)
{
return MinTime[intersection][6];
}

double TT_1_178 (TRANS_NUMBER tran)
{
return MinTime[intersection][5];
}

double TT_1_170 (TRANS_NUMBER tran)
{
return MinTime[intersection][4];
}

double TT_1_162 (TRANS_NUMBER tran)
{
return MinTime[intersection][3];
}

double TT_1_153 (TRANS_NUMBER tran)
{
return MinTime[intersection][2];
}

double TT_1_146 (TRANS_NUMBER tran)
{
return MinTime[intersection][1];
}

double TT_1_134 (TRANS_NUMBER tran)
{
return MinTime[intersection][0];
}

BOOLEAN TE_1_115 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 2) || (Initphase[intersection] == 3))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_116 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 2) || (Initphase[intersection] == 3))
  return 0;
else
  return 1;
}

BOOLEAN TE_1_117 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 4) || (Initphase[intersection] == 5))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_118 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 4) || (Initphase[intersection] == 5))
  return 0;
else
  return 1;
}

BOOLEAN TE_1_119 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 6) || (Initphase[intersection] == 7))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_120 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 6) || (Initphase[intersection] == 7))
  return 0;
else
  return 1;
}

double TT_3_216 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

double TT_3_248 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

double TT_3_214 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

double TT_3_215 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

double TT_3_224 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

double TT_3_271 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

void TF_0_14 (TRANS_NUMBER tran)
{
intersection=0;
}

void TF_0_40 (TRANS_NUMBER tran)
{
intersection=1;
}

void TF_0_44 (TRANS_NUMBER tran)
{
intersection=2;
}

void TF_0_42 (TRANS_NUMBER tran)
{
intersection=3;
}

void TF_0_41 (TRANS_NUMBER tran)
{
intersection=4;
}

void TF_0_43 (TRANS_NUMBER tran)
{
intersection=5;
}

BOOLEAN TE_1_113 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 0) || (Initphase[intersection] == 1))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_114 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 0) || (Initphase[intersection] == 1))
  return 0;
else
  return 1;
}

BOOLEAN TE_1_121 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 0) || (Initphase[intersection] == 2))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_122 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 0) || (Initphase[intersection] == 2))
  return 0;
else
  return 1;
}

BOOLEAN TE_1_123 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 1) || (Initphase[intersection] == 3))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_124 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 1) || (Initphase[intersection] == 3))
  return 0;
else
  return 1;
}

BOOLEAN TE_1_125 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 4) || (Initphase[intersection] == 6))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_126 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 4) || (Initphase[intersection] == 6))
  return 0;
else
  return 1;
}

BOOLEAN TE_1_127 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 5) || (Initphase[intersection] == 7))
  return 1;
else
  return 0;
}

BOOLEAN TE_1_128 (TRANS_NUMBER tran)
{
if ((Initphase[intersection] == 5) || (Initphase[intersection] == 7))
  return 0;
else
  return 1;
}

BOOLEAN TE_1_5 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][2];
}

BOOLEAN TE_1_6 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][3];
}

BOOLEAN TE_1_9 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][4];
}

BOOLEAN TE_1_10 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][5];
}

BOOLEAN TE_1_13 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][7];
}

BOOLEAN TE_1_30 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][0];
}

BOOLEAN TE_1_31 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][2];
}

BOOLEAN TE_1_34 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][3];
}

BOOLEAN TE_1_38 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][5];
}

BOOLEAN TE_1_40 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][6];
}

BOOLEAN TE_1_42 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][7];
}

BOOLEAN TE_1_57 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][0];
}

BOOLEAN TE_1_59 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][1];
}

BOOLEAN TE_1_61 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][3];
}

BOOLEAN TE_1_65 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][5];
}

BOOLEAN TE_1_66 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][6];
}

BOOLEAN TE_1_70 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][7];
}

BOOLEAN TE_1_73 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][1];
}

BOOLEAN TE_1_75 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][2];
}

BOOLEAN TE_1_77 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][4];
}

BOOLEAN TE_1_79 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][5];
}

BOOLEAN TE_1_82 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][6];
}

BOOLEAN TE_1_83 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][7];
}

BOOLEAN TE_1_16 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][0];
}

BOOLEAN TE_1_18 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][1];
}

BOOLEAN TE_1_22 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][3];
}

BOOLEAN TE_1_25 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][5];
}

BOOLEAN TE_1_43 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][0];
}

BOOLEAN TE_1_46 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][1];
}

BOOLEAN TE_1_48 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][2];
}

BOOLEAN TE_1_50 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][3];
}

BOOLEAN TE_1_52 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][4];
}

BOOLEAN TE_1_54 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][6];
}

BOOLEAN TE_1_56 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][7];
}

BOOLEAN TE_1_85 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][0];
}

BOOLEAN TE_1_88 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][1];
}

BOOLEAN TE_1_89 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][2];
}

BOOLEAN TE_1_94 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][4];
}

BOOLEAN TE_1_93 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][5];
}

BOOLEAN TE_1_97 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][7];
}

BOOLEAN TE_1_99 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][0];
}

BOOLEAN TE_1_103 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][2];
}

BOOLEAN TE_1_105 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][3];
}

BOOLEAN TE_1_107 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][4];
}

BOOLEAN TE_1_110 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][5];
}

BOOLEAN TE_1_111 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][6];
}

double TT_3_246 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

void TF_3_256 (TRANS_NUMBER tran)
{
bay =5;
}

void TF_3_257 (TRANS_NUMBER tran)
{
bay = 0;
}

void TF_3_237 (TRANS_NUMBER tran)
{
bay = 1;
}

double TT_3_223 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

double TT_3_269 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

double TT_3_270 (TRANS_NUMBER tran)
{
return DetermDischargePart[intersection][bay];
}

void TF_3_222 (TRANS_NUMBER tran)
{
if (vehicle < 0) bay = 1;
else bay = RightCheck(intersection,bay);
}

double TT_3_222 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

BOOLEAN TE_2_4 (TRANS_NUMBER tran)
{
if (vehicle < 0)return 1;
else return 0;
}

void TF_2_1 (TRANS_NUMBER tran)
{
PerOnTime(intersection,bay,1);
presence[intersection][bay] = presence[intersection][bay] + 1;
}

BOOLEAN TE_2_2 (TRANS_NUMBER tran)
{
if (vehicle > 0)return 1;
else return 0;
}

double TT_2_6 (TRANS_NUMBER tran)
{
return BusServiceTime;
}

void TF_10_4 (TRANS_NUMBER tran)
{
if (intersection == 2) intersection=4;
else intersection=2;
}

void TF_0_9 (TRANS_NUMBER tran)
{
intersection = 0;
bay = 1;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

double TT_0_9 (TRANS_NUMBER tran)
{
return VehInpTime(0,1);
}

void TF_0_2 (TRANS_NUMBER tran)
{
intersection = 0;
bay = 3;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

double TT_0_2 (TRANS_NUMBER tran)
{
return VehInpTime(0,3);
}

void TF_0_3 (TRANS_NUMBER tran)
{
intersection = 0;
bay = 7;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay, 0);
}

double TT_0_3 (TRANS_NUMBER tran)
{
return VehInpTime(0,7);
}

void TF_0_10 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_5 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_4 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay,4);
}

void TF_4_4 (TRANS_NUMBER tran)
{
if (intersection == 0) intersection=1;
else intersection=0;
}

void TF_0_29 (TRANS_NUMBER tran)
{
intersection = 1;
bay = 3;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

double TT_0_29 (TRANS_NUMBER tran)
{
return VehInpTime(1,3);
}

void TF_0_30 (TRANS_NUMBER tran)
{
intersection = 1;
bay = 7;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

double TT_0_30 (TRANS_NUMBER tran)
{
return VehInpTime(1,7);
}

void TF_0_18 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_19 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_25 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_23 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_24 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_27 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_26 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay,4);
}

void TF_0_28 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_39 (TRANS_NUMBER tran)
{
intersection = 5;
bay = 1;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay,0);
}

double TT_0_39 (TRANS_NUMBER tran)
{
return VehInpTime(5,1);
}

void TF_0_38 (TRANS_NUMBER tran)
{
intersection = 5;
bay = 5;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay, 0);
}

double TT_0_38 (TRANS_NUMBER tran)
{
return VehInpTime(5,5);
}

void TF_0_31 (TRANS_NUMBER tran)
{
intersection = 5;
bay = 7;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay, 0);
}

double TT_0_31 (TRANS_NUMBER tran)
{
return VehInpTime(5,7);
}

void TF_0_33 (TRANS_NUMBER tran)
{
intersection = 3;
bay = 3;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay, 0);
}

double TT_0_33 (TRANS_NUMBER tran)
{
return VehInpTime(3,3);
}

void TF_0_37 (TRANS_NUMBER tran)
{
intersection = 3;
bay = 5;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay, 0);
}

double TT_0_37 (TRANS_NUMBER tran)
{
return VehInpTime(3,5);
}

void TF_0_32 (TRANS_NUMBER tran)
{
intersection = 3;
bay = 7;
vehicle = vehnum(intersection, bay);
out(vehicle, intersection, bay, 0);
}

double TT_0_32 (TRANS_NUMBER tran)
{
return VehInpTime(3,7);
}

void TF_0_22 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_21 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_0_20 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 4);
}

void TF_3_220 (TRANS_NUMBER tran)
{
bay=3;
out(vehicle, intersection, bay, 3);
}

void TF_3_219 (TRANS_NUMBER tran)
{
bay = 3;
out(vehicle, intersection, bay, 3);
}

void TF_3_218 (TRANS_NUMBER tran)
{
bay = 3;
out(vehicle, intersection, bay, 3);
}

void TF_3_212 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

BOOLEAN TE_3_212 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_205 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 1);
if (vehicle < 0) bay = 7;
else bay = LeftCheck(intersection, bay);
}

void TF_3_207 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

BOOLEAN TE_3_207 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_217 (TRANS_NUMBER tran)
{
if (vehicle < 0) bay = 7;
else bay = RightCheck(intersection, bay);
}

double TT_3_217 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

void TF_3_238 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 1);
if (vehicle < 0) bay = 1;
else bay = LeftCheck(intersection, bay);
}

void TF_3_0 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

BOOLEAN TE_3_0 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_226 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

BOOLEAN TE_3_226 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_228 (TRANS_NUMBER tran)
{
bay=5;
out(vehicle, intersection, bay, 3);
}

void TF_3_229 (TRANS_NUMBER tran)
{
bay=5;
out(vehicle, intersection, bay, 3);
}

void TF_3_230 (TRANS_NUMBER tran)
{
bay=5;
out(vehicle, intersection, bay, 3);
}

void TF_3_277 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 1);
if (vehicle < 0) bay = 3;
else bay = LeftCheck(intersection, bay);
}

void TF_3_276 (TRANS_NUMBER tran)
{
bay = 3;
}

void TF_3_275 (TRANS_NUMBER tran)
{
bay = 6;
}

void TF_3_268 (TRANS_NUMBER tran)
{
if (vehicle < 0) bay = 3;
else bay = RightCheck(intersection, bay);
}

double TT_3_268 (TRANS_NUMBER tran)
{
return ExpoDischargePart[intersection][bay];
}

void TF_3_272 (TRANS_NUMBER tran)
{
out(vehicle, intersection, bay, 2);
presence[intersection][bay] = presence[intersection][bay] - 1;
PerOnTime(intersection,bay,0);
}

BOOLEAN TE_3_272 (TRANS_NUMBER tran)
{
return movements[intersection][bay];
}

void TF_3_287 (TRANS_NUMBER tran)
{
bay = 7;
out(vehicle, intersection, bay, 3);
}

void TF_3_288 (TRANS_NUMBER tran)
{
bay = 7;
out(vehicle, intersection, bay, 3);
}

void TF_3_289 (TRANS_NUMBER tran)
{
bay = 7;
out(vehicle, intersection, bay, 3);
}

void TF_1_98 (TRANS_NUMBER tran)
{
UpdateSig(intersection,7);
}

BOOLEAN TE_1_101 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][1];
}

BOOLEAN TE_1_91 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][3];
}

BOOLEAN TE_1_63 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][4];
}

BOOLEAN TE_1_71 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][0];
}

BOOLEAN TE_1_11 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][6];
}

void TF_1_24 (TRANS_NUMBER tran)
{
UpdateSig(intersection,6);
}

BOOLEAN TE_1_26 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][6];
}

BOOLEAN TE_1_27 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][7];
}

BOOLEAN TE_1_20 (TRANS_NUMBER tran)
{
return TransToPhase[intersection][2];
}

void TF_1_90 (TRANS_NUMBER tran)
{
UpdateSig(intersection,2);
}

void TF_1_102 (TRANS_NUMBER tran)
{
UpdateSig(intersection,1);
}

void TF_1_109 (TRANS_NUMBER tran)
{
UpdateSig(intersection,5);
}

void TF_0_45 (TRANS_NUMBER tran)
{
UpdateMasterCycle();
}

double TT_0_45 (TRANS_NUMBER tran)
{
return MasterCycle;
}

double TT_1_201 (TRANS_NUMBER tran)
{
return TimeToRelease[intersection];
}

double TT_1_200 (TRANS_NUMBER tran)
{
return TimeToRelease[intersection];
}

void TF_1_131 (TRANS_NUMBER tran)
{
Permissive[intersection][0] = 0;
}

double TT_1_131 (TRANS_NUMBER tran)
{
return PermissiveTime[intersection][0];
}

void TF_1_138 (TRANS_NUMBER tran)
{
Permissive[intersection][1] = 0;
}

double TT_1_138 (TRANS_NUMBER tran)
{
return PermissiveTime[intersection][1];
}

void TF_1_151 (TRANS_NUMBER tran)
{
Permissive[intersection][2] = 0;
}

double TT_1_151 (TRANS_NUMBER tran)
{
return PermissiveTime[intersection][2];
}

void TF_1_132 (TRANS_NUMBER tran)
{
Force(intersection,0);
}

double TT_1_132 (TRANS_NUMBER tran)
{
return ForceTime[intersection][0];
}

void TF_1_144 (TRANS_NUMBER tran)
{
Force(intersection,1);
}

double TT_1_144 (TRANS_NUMBER tran)
{
return ForceTime[intersection][1];
}

void TF_1_159 (TRANS_NUMBER tran)
{
Force(intersection,2);
}

double TT_1_159 (TRANS_NUMBER tran)
{
return ForceTime[intersection][2];
}

void TF_1_167 (TRANS_NUMBER tran)
{
ForceOff[intersection][0] = 0;
state[intersection][0] = 2;
change(intersection,2);
}

BOOLEAN TE_1_167 (TRANS_NUMBER tran)
{
return ForceOff[intersection][0];
}

void TF_1_137 (TRANS_NUMBER tran)
{
state[intersection][0] = 2;
change(intersection,3);
}

double TT_1_137 (TRANS_NUMBER tran)
{
return MinToMax[intersection][0];
}

void TF_1_195 (TRANS_NUMBER tran)
{
state[intersection][7] = 2;
change(intersection,1);
}

BOOLEAN TE_1_195 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][7] > 0) return 0;
else return 1;
}

double TT_1_195 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][7];
}

void TF_1_188 (TRANS_NUMBER tran)
{
state[intersection][6] = 2;
change(intersection,1);
}

BOOLEAN TE_1_188 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][6] > 0) return 0;
else return 1;
}

double TT_1_188 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][6];
}

void TF_1_179 (TRANS_NUMBER tran)
{
state[intersection][5] = 2;
change(intersection,1);
}

BOOLEAN TE_1_179 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][5] > 0) return 0;
else return 1;
}

double TT_1_179 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][5];
}

void TF_1_171 (TRANS_NUMBER tran)
{
state[intersection][4] = 2;
change(intersection,1);
}

BOOLEAN TE_1_171 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][4] > 0) return 0;
else return 1;
}

double TT_1_171 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][4];
}

void TF_1_136 (TRANS_NUMBER tran)
{
state[intersection][0] = 2;
change(intersection,1);
}

BOOLEAN TE_1_136 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][0] > 0) return 0;
else return 1;
}

double TT_1_136 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][0];
}

void TF_1_148 (TRANS_NUMBER tran)
{
state[intersection][1] = 2;
change(intersection,1);
}

BOOLEAN TE_1_148 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][1] > 0) return 0;
else return 1;
}

double TT_1_148 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][1];
}

void TF_1_154 (TRANS_NUMBER tran)
{
state[intersection][2] = 2;
change(intersection,1);
}

BOOLEAN TE_1_154 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][2] > 0) return 0;
else return 1;
}

double TT_1_154 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][2];
}

void TF_1_163 (TRANS_NUMBER tran)
{
state[intersection][3] = 2;
change(intersection,1);
}

BOOLEAN TE_1_163 (TRANS_NUMBER tran)
{
if (Mode[intersection] == 0) return 0;
else if (presence[intersection][3] > 0) return 0;
else return 1;
}

double TT_1_163 (TRANS_NUMBER tran)
{
return PresenceExtend[intersection][3];
}
