/* this file was generated from the NETMAN file:
	C:\Users\mehdimashayekhi\Desktop\c++alaki\DRLIST_NETWORK\NETMODEL\NETMODELDRLIST.npn
	06/18/14 13:17:40
*/
#include "petri.h"

extern TOKEN_VALUE a1;
extern TOKEN_VALUE a2;
extern TOKEN_VALUE a3;
extern TOKEN_VALUE bay;
extern TOKEN_VALUE intersection;
extern TOKEN_VALUE vehicle;
#ifndef CONST_NET
#ifdef SEGMENTED_MEMORY
void DefineNet1();
void DefineNet2();
void DefineNet3();
void DefineNet4();
void DefineNet5();
void DefineNet6();
void DefineNet7();
void DefineNet8();
void DefineNet9();
void DefineNet10();
void DefineNet11();
void DefineNet12();
void DefineNet13();
void DefineNet14();
void DefineNet15();
void DefineNet16();
void DefineNet17();
void DefineNet18();
void DefineNet19();
void DefineNet20();
void DefineNet21();
void DefineNet22();
void DefineNet23();
void DefineNet24();
void DefineNet25();
void DefineNet26();
void DefineNet27();
void DefineNet28();
void DefineNet29();
void DefineNet30();
#endif /* SEGMENTED_MEMORY */
#endif /* CONST_NET */

#include <stdio.h>
#include <stdlib.h>

void Compute_MinToMax(int);
double SNExpoDist(double);
void NextCarTime(int,int);
void NextBusTime(int,int);
void Startup(void);
void Finishup(void);
void out (int,int,int,int);
int vehnum(int,int);
double VehInpTime(int,int);
int LeftCheck(int,int);
int RightCheck(int,int);
void change (int, int);
void UpdateSig(int,int);
void Force(int,int);
void PerOnTime(int,int,int);
void UpdateMasterCycle(void);
void GetSetForNextRelease(int);

extern FILE *output1;
extern FILE *output2;
extern FILE *output3; 
extern FILE *output4;
extern FILE *output5;
extern FILE *output6;
extern FILE *output7;
double TT_1_163 (TRANS_NUMBER); 

BOOLEAN TE_1_163 (TRANS_NUMBER); 

void TF_1_163 (TRANS_NUMBER); 

double TT_1_154 (TRANS_NUMBER); 

BOOLEAN TE_1_154 (TRANS_NUMBER); 

void TF_1_154 (TRANS_NUMBER); 

double TT_1_148 (TRANS_NUMBER); 

BOOLEAN TE_1_148 (TRANS_NUMBER); 

void TF_1_148 (TRANS_NUMBER); 

double TT_1_136 (TRANS_NUMBER); 

BOOLEAN TE_1_136 (TRANS_NUMBER); 

void TF_1_136 (TRANS_NUMBER); 

double TT_1_171 (TRANS_NUMBER); 

BOOLEAN TE_1_171 (TRANS_NUMBER); 

void TF_1_171 (TRANS_NUMBER); 

double TT_1_179 (TRANS_NUMBER); 

BOOLEAN TE_1_179 (TRANS_NUMBER); 

void TF_1_179 (TRANS_NUMBER); 

double TT_1_188 (TRANS_NUMBER); 

BOOLEAN TE_1_188 (TRANS_NUMBER); 

void TF_1_188 (TRANS_NUMBER); 

double TT_1_195 (TRANS_NUMBER); 

BOOLEAN TE_1_195 (TRANS_NUMBER); 

void TF_1_195 (TRANS_NUMBER); 

double TT_1_137 (TRANS_NUMBER); 

void TF_1_137 (TRANS_NUMBER); 

BOOLEAN TE_1_167 (TRANS_NUMBER); 

void TF_1_167 (TRANS_NUMBER); 

double TT_1_159 (TRANS_NUMBER); 

void TF_1_159 (TRANS_NUMBER); 

double TT_1_144 (TRANS_NUMBER); 

void TF_1_144 (TRANS_NUMBER); 

double TT_1_132 (TRANS_NUMBER); 

void TF_1_132 (TRANS_NUMBER); 

double TT_1_151 (TRANS_NUMBER); 

void TF_1_151 (TRANS_NUMBER); 

double TT_1_138 (TRANS_NUMBER); 

void TF_1_138 (TRANS_NUMBER); 

double TT_1_131 (TRANS_NUMBER); 

void TF_1_131 (TRANS_NUMBER); 

double TT_1_200 (TRANS_NUMBER); 

double TT_1_201 (TRANS_NUMBER); 

double TT_0_45 (TRANS_NUMBER); 

void TF_0_45 (TRANS_NUMBER); 

void TF_1_109 (TRANS_NUMBER); 

void TF_1_102 (TRANS_NUMBER); 

void TF_1_90 (TRANS_NUMBER); 

BOOLEAN TE_1_20 (TRANS_NUMBER); 

BOOLEAN TE_1_27 (TRANS_NUMBER); 

BOOLEAN TE_1_26 (TRANS_NUMBER); 

void TF_1_24 (TRANS_NUMBER); 

BOOLEAN TE_1_11 (TRANS_NUMBER); 

BOOLEAN TE_1_71 (TRANS_NUMBER); 

BOOLEAN TE_1_63 (TRANS_NUMBER); 

BOOLEAN TE_1_91 (TRANS_NUMBER); 

BOOLEAN TE_1_101 (TRANS_NUMBER); 

void TF_1_98 (TRANS_NUMBER); 

void TF_3_289 (TRANS_NUMBER); 

void TF_3_288 (TRANS_NUMBER); 

void TF_3_287 (TRANS_NUMBER); 

BOOLEAN TE_3_272 (TRANS_NUMBER); 

void TF_3_272 (TRANS_NUMBER); 

double TT_3_268 (TRANS_NUMBER); 

void TF_3_268 (TRANS_NUMBER); 

void TF_3_275 (TRANS_NUMBER); 

void TF_3_276 (TRANS_NUMBER); 

void TF_3_277 (TRANS_NUMBER); 

void TF_3_230 (TRANS_NUMBER); 

void TF_3_229 (TRANS_NUMBER); 

void TF_3_228 (TRANS_NUMBER); 

BOOLEAN TE_3_226 (TRANS_NUMBER); 

void TF_3_226 (TRANS_NUMBER); 

BOOLEAN TE_3_0 (TRANS_NUMBER); 

void TF_3_0 (TRANS_NUMBER); 

void TF_3_238 (TRANS_NUMBER); 

double TT_3_217 (TRANS_NUMBER); 

void TF_3_217 (TRANS_NUMBER); 

BOOLEAN TE_3_207 (TRANS_NUMBER); 

void TF_3_207 (TRANS_NUMBER); 

void TF_3_205 (TRANS_NUMBER); 

BOOLEAN TE_3_212 (TRANS_NUMBER); 

void TF_3_212 (TRANS_NUMBER); 

void TF_3_218 (TRANS_NUMBER); 

void TF_3_219 (TRANS_NUMBER); 

void TF_3_220 (TRANS_NUMBER); 

void TF_0_20 (TRANS_NUMBER); 

void TF_0_21 (TRANS_NUMBER); 

void TF_0_22 (TRANS_NUMBER); 

double TT_0_32 (TRANS_NUMBER); 

void TF_0_32 (TRANS_NUMBER); 

double TT_0_37 (TRANS_NUMBER); 

void TF_0_37 (TRANS_NUMBER); 

double TT_0_33 (TRANS_NUMBER); 

void TF_0_33 (TRANS_NUMBER); 

double TT_0_31 (TRANS_NUMBER); 

void TF_0_31 (TRANS_NUMBER); 

double TT_0_38 (TRANS_NUMBER); 

void TF_0_38 (TRANS_NUMBER); 

double TT_0_39 (TRANS_NUMBER); 

void TF_0_39 (TRANS_NUMBER); 

void TF_0_28 (TRANS_NUMBER); 

void TF_0_26 (TRANS_NUMBER); 

void TF_0_27 (TRANS_NUMBER); 

void TF_0_24 (TRANS_NUMBER); 

void TF_0_23 (TRANS_NUMBER); 

void TF_0_25 (TRANS_NUMBER); 

void TF_0_19 (TRANS_NUMBER); 

void TF_0_18 (TRANS_NUMBER); 

double TT_0_30 (TRANS_NUMBER); 

void TF_0_30 (TRANS_NUMBER); 

double TT_0_29 (TRANS_NUMBER); 

void TF_0_29 (TRANS_NUMBER); 

void TF_4_4 (TRANS_NUMBER); 

void TF_0_4 (TRANS_NUMBER); 

void TF_0_5 (TRANS_NUMBER); 

void TF_0_10 (TRANS_NUMBER); 

double TT_0_3 (TRANS_NUMBER); 

void TF_0_3 (TRANS_NUMBER); 

double TT_0_2 (TRANS_NUMBER); 

void TF_0_2 (TRANS_NUMBER); 

double TT_0_9 (TRANS_NUMBER); 

void TF_0_9 (TRANS_NUMBER); 

void TF_10_4 (TRANS_NUMBER); 

double TT_2_6 (TRANS_NUMBER); 

BOOLEAN TE_2_2 (TRANS_NUMBER); 

void TF_2_1 (TRANS_NUMBER); 

BOOLEAN TE_2_4 (TRANS_NUMBER); 

double TT_3_222 (TRANS_NUMBER); 

void TF_3_222 (TRANS_NUMBER); 

double TT_3_270 (TRANS_NUMBER); 

double TT_3_269 (TRANS_NUMBER); 

double TT_3_223 (TRANS_NUMBER); 

void TF_3_237 (TRANS_NUMBER); 

void TF_3_257 (TRANS_NUMBER); 

void TF_3_256 (TRANS_NUMBER); 

double TT_3_246 (TRANS_NUMBER); 

BOOLEAN TE_1_111 (TRANS_NUMBER); 

BOOLEAN TE_1_110 (TRANS_NUMBER); 

BOOLEAN TE_1_107 (TRANS_NUMBER); 

BOOLEAN TE_1_105 (TRANS_NUMBER); 

BOOLEAN TE_1_103 (TRANS_NUMBER); 

BOOLEAN TE_1_99 (TRANS_NUMBER); 

BOOLEAN TE_1_97 (TRANS_NUMBER); 

BOOLEAN TE_1_93 (TRANS_NUMBER); 

BOOLEAN TE_1_94 (TRANS_NUMBER); 

BOOLEAN TE_1_89 (TRANS_NUMBER); 

BOOLEAN TE_1_88 (TRANS_NUMBER); 

BOOLEAN TE_1_85 (TRANS_NUMBER); 

BOOLEAN TE_1_56 (TRANS_NUMBER); 

BOOLEAN TE_1_54 (TRANS_NUMBER); 

BOOLEAN TE_1_52 (TRANS_NUMBER); 

BOOLEAN TE_1_50 (TRANS_NUMBER); 

BOOLEAN TE_1_48 (TRANS_NUMBER); 

BOOLEAN TE_1_46 (TRANS_NUMBER); 

BOOLEAN TE_1_43 (TRANS_NUMBER); 

BOOLEAN TE_1_25 (TRANS_NUMBER); 

BOOLEAN TE_1_22 (TRANS_NUMBER); 

BOOLEAN TE_1_18 (TRANS_NUMBER); 

BOOLEAN TE_1_16 (TRANS_NUMBER); 

BOOLEAN TE_1_83 (TRANS_NUMBER); 

BOOLEAN TE_1_82 (TRANS_NUMBER); 

BOOLEAN TE_1_79 (TRANS_NUMBER); 

BOOLEAN TE_1_77 (TRANS_NUMBER); 

BOOLEAN TE_1_75 (TRANS_NUMBER); 

BOOLEAN TE_1_73 (TRANS_NUMBER); 

BOOLEAN TE_1_70 (TRANS_NUMBER); 

BOOLEAN TE_1_66 (TRANS_NUMBER); 

BOOLEAN TE_1_65 (TRANS_NUMBER); 

BOOLEAN TE_1_61 (TRANS_NUMBER); 

BOOLEAN TE_1_59 (TRANS_NUMBER); 

BOOLEAN TE_1_57 (TRANS_NUMBER); 

BOOLEAN TE_1_42 (TRANS_NUMBER); 

BOOLEAN TE_1_40 (TRANS_NUMBER); 

BOOLEAN TE_1_38 (TRANS_NUMBER); 

BOOLEAN TE_1_34 (TRANS_NUMBER); 

BOOLEAN TE_1_31 (TRANS_NUMBER); 

BOOLEAN TE_1_30 (TRANS_NUMBER); 

BOOLEAN TE_1_13 (TRANS_NUMBER); 

BOOLEAN TE_1_10 (TRANS_NUMBER); 

BOOLEAN TE_1_9 (TRANS_NUMBER); 

BOOLEAN TE_1_6 (TRANS_NUMBER); 

BOOLEAN TE_1_5 (TRANS_NUMBER); 

BOOLEAN TE_1_128 (TRANS_NUMBER); 

BOOLEAN TE_1_127 (TRANS_NUMBER); 

BOOLEAN TE_1_126 (TRANS_NUMBER); 

BOOLEAN TE_1_125 (TRANS_NUMBER); 

BOOLEAN TE_1_124 (TRANS_NUMBER); 

BOOLEAN TE_1_123 (TRANS_NUMBER); 

BOOLEAN TE_1_122 (TRANS_NUMBER); 

BOOLEAN TE_1_121 (TRANS_NUMBER); 

BOOLEAN TE_1_114 (TRANS_NUMBER); 

BOOLEAN TE_1_113 (TRANS_NUMBER); 

void TF_0_43 (TRANS_NUMBER); 

void TF_0_41 (TRANS_NUMBER); 

void TF_0_42 (TRANS_NUMBER); 

void TF_0_44 (TRANS_NUMBER); 

void TF_0_40 (TRANS_NUMBER); 

void TF_0_14 (TRANS_NUMBER); 

double TT_3_271 (TRANS_NUMBER); 

double TT_3_224 (TRANS_NUMBER); 

double TT_3_215 (TRANS_NUMBER); 

double TT_3_214 (TRANS_NUMBER); 

double TT_3_248 (TRANS_NUMBER); 

double TT_3_216 (TRANS_NUMBER); 

BOOLEAN TE_1_120 (TRANS_NUMBER); 

BOOLEAN TE_1_119 (TRANS_NUMBER); 

BOOLEAN TE_1_118 (TRANS_NUMBER); 

BOOLEAN TE_1_117 (TRANS_NUMBER); 

BOOLEAN TE_1_116 (TRANS_NUMBER); 

BOOLEAN TE_1_115 (TRANS_NUMBER); 

double TT_1_134 (TRANS_NUMBER); 

double TT_1_146 (TRANS_NUMBER); 

double TT_1_153 (TRANS_NUMBER); 

double TT_1_162 (TRANS_NUMBER); 

double TT_1_170 (TRANS_NUMBER); 

double TT_1_178 (TRANS_NUMBER); 

double TT_1_186 (TRANS_NUMBER); 

double TT_1_194 (TRANS_NUMBER); 

double TT_3_225 (TRANS_NUMBER); 

void TF_3_236 (TRANS_NUMBER); 

void TF_0_35 (TRANS_NUMBER); 

double TT_0_35 (TRANS_NUMBER); 

void TF_0_34 (TRANS_NUMBER); 

double TT_0_34 (TRANS_NUMBER); 

void TF_0_36 (TRANS_NUMBER); 

double TT_0_36 (TRANS_NUMBER); 

void TF_6_4 (TRANS_NUMBER); 

void TF_12_4 (TRANS_NUMBER); 

void TF_8_4 (TRANS_NUMBER); 

void TF_3_213 (TRANS_NUMBER); 

void TF_3_273 (TRANS_NUMBER); 

BOOLEAN TE_3_273 (TRANS_NUMBER); 

void TF_3_265 (TRANS_NUMBER); 

void TF_3_266 (TRANS_NUMBER); 

void TF_3_206 (TRANS_NUMBER); 

void TF_1_1 (TRANS_NUMBER); 

void TF_1_2 (TRANS_NUMBER); 

void TF_1_3 (TRANS_NUMBER); 

void TF_1_7 (TRANS_NUMBER); 

void TF_1_8 (TRANS_NUMBER); 

void TF_1_12 (TRANS_NUMBER); 

void TF_1_14 (TRANS_NUMBER); 

BOOLEAN TE_1_4 (TRANS_NUMBER); 

void TF_1_15 (TRANS_NUMBER); 

void TF_1_17 (TRANS_NUMBER); 

void TF_1_19 (TRANS_NUMBER); 

void TF_1_21 (TRANS_NUMBER); 

void TF_1_23 (TRANS_NUMBER); 

void TF_1_28 (TRANS_NUMBER); 

void TF_1_29 (TRANS_NUMBER); 

void TF_1_32 (TRANS_NUMBER); 

void TF_1_33 (TRANS_NUMBER); 

BOOLEAN TE_1_35 (TRANS_NUMBER); 

void TF_1_36 (TRANS_NUMBER); 

void TF_1_37 (TRANS_NUMBER); 

void TF_1_39 (TRANS_NUMBER); 

void TF_1_41 (TRANS_NUMBER); 

void TF_1_44 (TRANS_NUMBER); 

void TF_1_45 (TRANS_NUMBER); 

void TF_1_47 (TRANS_NUMBER); 

void TF_1_49 (TRANS_NUMBER); 

void TF_1_51 (TRANS_NUMBER); 

void TF_1_53 (TRANS_NUMBER); 

void TF_1_55 (TRANS_NUMBER); 

void TF_1_58 (TRANS_NUMBER); 

void TF_1_60 (TRANS_NUMBER); 

void TF_1_62 (TRANS_NUMBER); 

void TF_1_64 (TRANS_NUMBER); 

void TF_1_67 (TRANS_NUMBER); 

void TF_1_68 (TRANS_NUMBER); 

void TF_1_69 (TRANS_NUMBER); 

void TF_1_86 (TRANS_NUMBER); 

void TF_1_87 (TRANS_NUMBER); 

void TF_1_92 (TRANS_NUMBER); 

void TF_1_95 (TRANS_NUMBER); 

void TF_1_96 (TRANS_NUMBER); 

void TF_1_72 (TRANS_NUMBER); 

void TF_1_74 (TRANS_NUMBER); 

void TF_1_76 (TRANS_NUMBER); 

void TF_1_78 (TRANS_NUMBER); 

void TF_1_80 (TRANS_NUMBER); 

void TF_1_81 (TRANS_NUMBER); 

void TF_1_84 (TRANS_NUMBER); 

void TF_1_100 (TRANS_NUMBER); 

void TF_1_104 (TRANS_NUMBER); 

void TF_1_106 (TRANS_NUMBER); 

void TF_1_108 (TRANS_NUMBER); 

void TF_1_112 (TRANS_NUMBER); 

void TF_0_8 (TRANS_NUMBER); 

void TF_3_247 (TRANS_NUMBER); 

double TT_3_247 (TRANS_NUMBER); 

double TT_3_249 (TRANS_NUMBER); 

void TF_3_245 (TRANS_NUMBER); 

void TF_3_261 (TRANS_NUMBER); 

void TF_3_255 (TRANS_NUMBER); 

BOOLEAN TE_3_255 (TRANS_NUMBER); 

void TF_3_254 (TRANS_NUMBER); 

BOOLEAN TE_3_254 (TRANS_NUMBER); 

void TF_1_191 (TRANS_NUMBER); 

BOOLEAN TE_1_191 (TRANS_NUMBER); 

void TF_1_172 (TRANS_NUMBER); 

double TT_1_172 (TRANS_NUMBER); 

void TF_1_197 (TRANS_NUMBER); 

BOOLEAN TE_1_197 (TRANS_NUMBER); 

void TF_1_180 (TRANS_NUMBER); 

double TT_1_180 (TRANS_NUMBER); 

void TF_1_198 (TRANS_NUMBER); 

BOOLEAN TE_1_198 (TRANS_NUMBER); 

void TF_1_187 (TRANS_NUMBER); 

double TT_1_187 (TRANS_NUMBER); 

void TF_1_199 (TRANS_NUMBER); 

BOOLEAN TE_1_199 (TRANS_NUMBER); 

void TF_1_196 (TRANS_NUMBER); 

double TT_1_196 (TRANS_NUMBER); 

void TF_1_175 (TRANS_NUMBER); 

BOOLEAN TE_1_175 (TRANS_NUMBER); 

void TF_1_149 (TRANS_NUMBER); 

double TT_1_149 (TRANS_NUMBER); 

void TF_1_183 (TRANS_NUMBER); 

BOOLEAN TE_1_183 (TRANS_NUMBER); 

void TF_1_156 (TRANS_NUMBER); 

double TT_1_156 (TRANS_NUMBER); 

void TF_1_190 (TRANS_NUMBER); 

BOOLEAN TE_1_190 (TRANS_NUMBER); 

void TF_1_164 (TRANS_NUMBER); 

double TT_1_164 (TRANS_NUMBER); 

void TF_1_189 (TRANS_NUMBER); 

void TF_1_0 (TRANS_NUMBER); 

void TF_1_192 (TRANS_NUMBER); 

void TF_1_181 (TRANS_NUMBER); 

void TF_1_182 (TRANS_NUMBER); 

void TF_1_184 (TRANS_NUMBER); 

void TF_1_173 (TRANS_NUMBER); 

void TF_1_174 (TRANS_NUMBER); 

void TF_1_176 (TRANS_NUMBER); 

void TF_1_165 (TRANS_NUMBER); 

void TF_1_166 (TRANS_NUMBER); 

void TF_1_168 (TRANS_NUMBER); 

void TF_1_158 (TRANS_NUMBER); 

void TF_1_160 (TRANS_NUMBER); 

void TF_1_157 (TRANS_NUMBER); 

void TF_1_147 (TRANS_NUMBER); 

void TF_1_152 (TRANS_NUMBER); 

void TF_1_145 (TRANS_NUMBER); 

void TF_1_142 (TRANS_NUMBER); 

void TF_1_143 (TRANS_NUMBER); 

void TF_1_141 (TRANS_NUMBER); 

void TF_1_135 (TRANS_NUMBER); 

void TF_1_140 (TRANS_NUMBER); 

void TF_1_133 (TRANS_NUMBER); 

void TF_1_130 (TRANS_NUMBER); 
