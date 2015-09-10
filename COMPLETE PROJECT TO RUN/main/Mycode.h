/* My Code, All times in seconds */
#include<iostream>
#include <math.h>
using namespace std;

// Traffic data
int CarVolume[9][6][4];
int BusVolume[6][4];
double CarArriveTime[6][4];
double BusArriveTime[6][4];
int Turn[6][8];

// Cycle length data
int MasterCycle = 50;
int EndCycle = 0;
int MinCycle = 50;
int MaxCycle = 130;
float beta = 0.0;
double MaxCycAdjPct = 5.0;
double MaxOffAdjPct = 5.0;
double MaxOffAdj = 3.0;

// Intersection specific data
int Mode[6];
int Initphase[6];
int last[6];
int current[6];
int next[6];
int TermCond[6];
int SigStat[6];
int Mainstreet[6];
int Offset[6];
int OldOffset[6];
int TimeToRelease[6];
int DesiredCycle[6];

//Forceoffs and permissives
int ForceTime[6][3];
int Permissive[6][3];
int PermissiveTime[6][3];
double ForceTimePct[6][3];
double PermissiveTimePct[6][3];

// Movement specific data
int TransToPhase[6][8];
int ForceOff[6][8];
int state[6][8];
int GrnStart[6][8];
int RedStart[6][8];
int movements[6][8];
int presence[6][8];
double PresenceExtend[6][8];
int on[6][8];
int onstart[6][8];
int FixGreen[6][8];
int MaxTime[6][8];
int MinTime[6][8];
int MinToMax[6][8];
int OffAdjWt[6][8];

double DetermDischargePart[6][8];
double ExpoDischargePart[6][8];

// Movements serviced by phase
int MovesByPhase[8][2]={{0,4},{0,5},{1,4},{1,5},{2,6},{2,7},{3,6},{3,7}};

// Moving average data
double AvgMasterCycle;
double AvgGrn[6][8];
double AvgRed[6][8];
double AvgGrnOn[6][8];
double AvgRedOn[6][8];
double CurGrn[6][8];
double CurRed[6][8];
double CurOn[6][8];

//Miscellaneous parameters
int FxdHdwys;
int TwoPhase;
int CarNumber;
int BusNumber;
int NumberofCycles;
int checker1;
int checker2;
long event;
double pi = 3.1416;
double TMax = 9000.0;
double BusServiceTime;

//File specifications
  FILE *infile;
  FILE *output1;
//FILE *output2;
  FILE *output3;
//FILE *output4;
  FILE *output5;
//FILE *output6;
  FILE *output7;

// * * * * * * * * * * * * * MinToMax * * * * * * * * * * * * *

//Compute incremental time from MinGreen to MaxGreen
void Compute_MinToMax (int inter)
{
  int j;
  for (j = 0; j <= 7; ++j)
    {
    if (Mode[inter] == 0) // Signal is operating Pretimed
      MinToMax[inter][j] = FixGreen[inter][j] - MinTime[inter][j];
    else
      MinToMax[inter][j] = MaxTime[inter][j] - MinTime[inter][j];
    }
}

// * * * * * * * * * Shifted Negative Exponential Headways * * * * * * * * * * * *

// Routine to compute exponential headways
double SNExpoDist (double Head)
{
  double b;
  double ExpPart;
  double DetPart = 1.0;
  ExpPart = Head - DetPart;
  b = 1.0 * (double) rand() / (double) RAND_MAX;
  ExpPart = -ExpPart * log(b);
  Head = DetPart + ExpPart;
  return (Head);
}

// * * * * * * * * * Car Input Times * * * * * * * * * * * *

// Routine to compute car input times
// bae should have values 1, 3, 5, or 7

void NextCarTime (int inter, int bae)
{
  int i;
  int j;
  int b;
  int StartTPer;
  int EndTPer;
  double StartVol;
  double EndVol;
  double CurVol;
  double StartTime;
  double EvalTime;
  double Headway;
  double Percentage;

  b = (bae - 1)/2;
  Headway = 0;
  j = ((int)(ncGetTime()/900));
  for (i = j; i < 7; ++i)
    {
    if (CarVolume[i][inter][b] > 0) break;
    Headway = Headway + 900;
    }
  StartTPer = i;
  EndTPer = StartTPer + 1;
  StartVol = CarVolume[StartTPer][inter][b];
  EndVol = CarVolume[EndTPer][inter][b];
  StartTime = 900*StartTPer;
  if (StartTime <= ncGetTime()) EvalTime = ncGetTime(); else EvalTime = StartTime;
  Percentage = (EvalTime - StartTime) / 900;
  CurVol = Percentage * (EndVol - StartVol) + StartVol;
  if (CurVol <= 0)
    Headway = Headway + 900;
  else
    {
    if (FxdHdwys == 1) Headway = Headway + 3600/CurVol;
    else Headway = Headway + SNExpoDist(3600/CurVol);
    }
  CarArriveTime[inter][b] = ncGetTime() + Headway;
  if (CarArriveTime[inter][b] > BusArriveTime[inter][b])
    if (CarArriveTime[inter][b] - BusArriveTime[inter][b] < 1.0)
      CarArriveTime[inter][b] = BusArriveTime[inter][b] + 1.0;
}

// * * * * * * * * * Bus Input Times * * * * * * * * * * * *

// Routine to compute bus input times
// bae should have values 1, 3, 5, or 7
// When random, headways are uniformly distributed between 90% and 110% of the average

void NextBusTime (int inter, int bae)
{
  int b;
  double BusInterval;
  double Headway;
  double RandPart;
  double ConstPart;
  double temp;

  b = (bae - 1)/2;
  if (BusVolume[inter][b] <=0)
    Headway = TMax;
  else
    {
    Headway = 3600/BusVolume[inter][b];
    if (FxdHdwys != 1)
      {
      ConstPart = 0.9 * BusInterval;
      RandPart = 0.1 * BusInterval;
      temp = 1.0 * (double) rand() / (double) RAND_MAX;
      Headway  = ConstPart + 2.0 * temp * RandPart;
      }
    }
  BusArriveTime[inter][b] = ncGetTime() + Headway;
  if (BusArriveTime[inter][b] > CarArriveTime[inter][b])
    if (BusArriveTime[inter][b] - CarArriveTime[inter][b] < 1.0)
      BusArriveTime[inter][b] = CarArriveTime[inter][b] + 1.0;
}

// * * * * * * Initialization * * * * * * * * * * * *

//Initialization routine
void Startup (void)
{
  int i;
  int j;
  int k;
  int temp;

  CarNumber = 0;
  BusNumber = 0;
  event = 0;
  checker1 = 0;
  checker2 = 0;
  i = 0;
  j = 0;
  k = 0;

  infile = fopen("input.dat","r");
  output1 = fopen("veh.txt","w");
//output2 = fopen("det.txt","w");
  output3 = fopen("phsdur.txt","w");
//output4 = fopen("phssel.txt","w");
//output5 = fopen("phschg.txt","w");
//output6 = fopen("mascyc.txt","w");
  output7 = fopen("descyc.txt","w");

//fprintf (output1,"\t\tVehicle Events\n");
  fprintf (output1,"Event\tTime\tVeh\tInter\tBay\tTrans\tState\n");
//fprintf (output2,"\t\tDetector Actuations\n");
//fprintf (output2,"Time\tInter\tMvmt\tCurOn\tAvgOn\tRdGrn\n");
//fprintf (output3,"\t\tSignal Timings\n");
  fprintf (output3,"Time\tInter\tCurrent\tMvmt\tState\tP0\tP1\tP2\tP3\tP4\tP5\tP6\tP7\n");
//fprintf (output4,"\t\tPhase Change Evaluations\n");
//fprintf (output4,"Time\tCurrent\tmove0\tmove1\tState0\tState1\tPres0\tPres1\n");
//fprintf (output5,"\t\tPhase Changes\n");
//fprintf (output5,"Time\tInter\tMode\tCurrent\tTermCond\n");
//fprintf (output6,"\t\tOffset Changes\n");
//fprintf (output6,"Time\tMstrCyc\tInter\tOffAdj\tOffset\tTimeToRel\n");
//fprintf (output7,"\t\tDesired Cycle Lengths\n");
  fprintf (output7,"Time\tInter\tTotAvgOn\tDesCyc\tMasCyc\n");

//Initialize intersection parameters
  for (i = 0; i <=5; ++i)
    { Mode[i] = 0; current[i] = 3; last[i] = 0; Mainstreet[i] = 3;
      Offset[i] = 0; OldOffset[i] = 0; SigStat[i] = 0; next[i] = 0;
      DesiredCycle[i] = 0; }

//Initialize permissive parameters
  for (i = 0; i <=5; ++i)
  for (k = 0; k <=2; ++k)
    { Permissive[i][k] = 0; PermissiveTime[i][k] = 10; ForceTime[i][k] = 15; }

//Initialize movement parameters
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    { ForceOff[i][j] = 0; state[i][j] = 0; GrnStart[i][j] = 0; TransToPhase[i][j] = 0;
      movements[i][j] = 0; presence[i][j] = 0; on[i][j] = 0; onstart[i][j] = 0;
      FixGreen[i][j] = 5; MaxTime[i][j] = 20; MinTime[i][j] = 5; MinToMax[i][j] = 15;
      TermCond[i] = 0; OffAdjWt[i][j] = 0; Turn[i][j] = 0; PresenceExtend[i][j] = 1.0;
      DetermDischargePart[i][j] = 1.5; ExpoDischargePart[i][j] = 0.5;
      AvgGrn[i][j] = 0; AvgRed[i][j] = 0; AvgGrnOn[i][j] = 0; AvgRedOn[i][j] = 0;
      CurGrn[i][j] = 0; CurRed[i][j] = 0; CurOn[i][j] = 0; }

//Initialize the car and bus input times
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=3; ++j)
    { CarArriveTime[i][j] = 0; BusArriveTime[i][j] = 0; }

//Start Reading Input Data

//Cycle length parameters
  fscanf (infile, "%d%d%d%f", &MinCycle, &MaxCycle, &temp, &beta );
  MaxCycAdjPct = (double) temp;

//Initialize master cycle length values
  EndCycle = 0;
  MasterCycle = MinCycle;
  AvgMasterCycle = MasterCycle;

//Vehicle headway flag
//If set to 1, input headways will be derministic
  fscanf (infile, "%d", &FxdHdwys);

//Flow rates for all traffic inputs in phase order
//Values at time = 0, 15, 30, 45, 60, 75, 90, 105, 120
//Each intersection (0, 1, 2, 3, 4, 5)
//Each direction (EB, SB, WB, NB) [1, 3, 5, 7]
  for (i = 0; i <=8; ++i)
  for (j = 0; j <=5; ++j)
  for (k = 0; k <=3; ++k)
    fscanf (infile, "%d", &CarVolume[i][j][k]),cout <<endl<<CarVolume[i][j][k];


//Compute initial input times for cars
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=3; ++j)
    NextCarTime(i, 2*j+1);

//Turning percentages in phase order, with RT percentages in the through positions:
//WBLT  EBRT  NBLT  SBRT  EBLT  WBRT  SBLT  NBRT
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%d", &Turn[i][j]);

//Two Phase flag for pre-timed operation (1 => two phase, 0 => four phase)
  fscanf (infile, "%d", &TwoPhase);

//Shifted negative exponential discharge headway components
//Combined values yield service time (e.g., 1.5 + 0.5 = 2.0 )
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%lf", &DetermDischargePart[i][j]);
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%lf", &ExpoDischargePart[i][j]);

//Read bus volumes and compute first input times
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=3; ++j)
    { fscanf (infile, "%d", &BusVolume[i][j]); NextBusTime(i,2*j+1); }

//Bus dwell time
  fscanf (infile, "%lf", &BusServiceTime);

//Initial modes for intersections
// 0-pretimed, 1-fully actuated, 2-semi-actuated & coordinated,
// 3-random,   4-queue length management
  for (i = 0; i <=5; ++i) fscanf (infile, "%d", &Mode[i]);

//Mainstreet phase for each intersection (3 = EW, 7 = NS)
  for (i = 0; i <=5; ++i) fscanf (infile, "%d", &Mainstreet[i]);

//Initial phases for each intersection
  for (i = 0; i <=5; ++i)
    {
    fscanf (infile, "%d", &next[i]);
    if (Mode[i] == 2) next[i] = Mainstreet[i];
    current[i] = next[i];
    Initphase[i] = current[i];
    }

//Offset adjustment weights for each intersection
// 0    1    2    3    4    5    6    7
//WBLT EBTR NBLT SBTR EBLT WBTR SBLT NBTR
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%d", &OffAdjWt[i][j]);

//Maximum percentage value for offset adjustments
  fscanf (infile, "%lf", &MaxOffAdjPct);
  MaxOffAdj = MasterCycle*MaxOffAdjPct/100.0;

//Number of cycles for short-way transition
  fscanf (infile, "%d", &NumberofCycles);

//Initial offset values and set initial value for TimeToRelease
  for (i = 0; i <=5; ++i)
    {
    fscanf (infile, "%d", &Offset[i]);
    TimeToRelease[i] = Offset[i];
    OldOffset[i] = Offset[i];
    }

//Minimum greens (seconds) in phase order:
// 0    1    2    3    4    5    6    7
//WBLT EBTR NBLT SBTR EBLT WBTR SBLT NBTR
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%d", &MinTime[i][j]);

//Maximum greens (seconds)in phase order:
// 0    1    2    3    4    5    6    7
//WBLT EBTR NBLT SBTR EBLT WBTR SBLT NBTR
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%d", &MaxTime[i][j]);

//Presence detector extensions (seconds)in phase order:
// 0    1    2    3    4    5    6    7
//WBLT EBTR NBLT SBTR EBLT WBTR SBLT NBTR
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%lf", &PresenceExtend[i][j]);

// Fixed greens (seconds)for pretimed operation
// 0    1    2    3    4    5    6    7
//WBLT EBTR NBLT SBTR EBLT WBTR SBLT NBTR
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=7; ++j)
    fscanf (infile, "%d", &FixGreen[i][j]);

//Compute MinGreen to MaxGreen increments
  for (i = 0; i <=5; ++i) Compute_MinToMax(i);

//Permissive times (seconds) for semi-actuated coordinated control
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=2; ++j)
    {
    Permissive[i][j] = 0;
    fscanf (infile, "%d", &temp);
    PermissiveTimePct[i][j] = (double) temp;
    PermissiveTime[i][j] = (int)(PermissiveTimePct[i][j] /100.0 * MasterCycle );
    }

//Force-offs (seconds) for semi-actuated coordinated control
  for (i = 0; i <=5; ++i)
  for (j = 0; j <=2; ++j)
    {
    fscanf (infile, "%d", &temp);
    ForceTimePct[i][j] = (double) temp;
    ForceTime[i][j] = (int)(ForceTimePct[i][j] /100.0 * MasterCycle );
    }
}

// * * * * * * * * Finish Up * * * * * * * * * * * *

//Finish all processing
void Finishup (void)
{
  if( output1 != 0 ) fclose( output1 );
//if( output2 != 0 ) fclose( output2 );
  if( output3 != 0 ) fclose( output3 );
//if( output4 != 0 ) fclose( output4 );
//if( output5 != 0 ) fclose( output5 );
//if( output6 != 0 ) fclose( output6 );
  if( output7 != 0 ) fclose( output7 );
}

// * * * * * * * * * Output * * * * * * * * * * * *

//Output file print statement
// v1 = vehicle, v2 = intersection, v3 = bay, v4 = transaction

void out (int v1, int v2, int v3, int v4)
{
  ++event;
  fprintf (output1, "%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    event,ncGetTime(),v1,v2,v3,v4,state[v2][v3]);
}

// * * * * * * * * * Assign Vehicle Type and Number * * * * * * * * * * * *

// Routine to assign vehicle type and vehicle number
// bae should have values 1, 3, 5, or 7
int vehnum (int inter, int bae)
{
  int b;

  b = (bae - 1)/2;
  if (BusArriveTime[inter][b] < CarArriveTime[inter][b])
   { BusNumber -= 1; return (BusNumber); }
  else
   { CarNumber += 1; return (CarNumber); }
}

// * * * * * * * * * Compute Next Vehicle Entry Time * * * * * * * * * * * *

// Routine to compute service time for vehicle generation
// bae should have values 1, 3, 5, or 7

double VehInpTime (int inter, int bae)
{
  int b;

  b = (bae - 1)/2;
  if (BusArriveTime[inter][b] < CarArriveTime[inter][b])
    { NextBusTime(inter,bae);
      return (BusArriveTime[inter][b] - ncGetTime()); }
  else
    { NextCarTime(inter,bae);
      return (CarArriveTime[inter][b] - ncGetTime()); }
}

// * * * * * * * * * Check for Left Turn Selection * * * * * * * * * * * *

//Function called to see if the vehicle should turn left
//bae has a value of either 1, 3, 5, or 7
int LeftCheck (int inter, int bae)
{
  double test1;
  double test2;
  int b;

  //Get random number between 0 and 100
  test1 = 100.0 * (double) rand()/ (double) RAND_MAX;

  //Get corresponding left turn percentage
  b = bae + 3;
  if (b > 7) b = b - 8;
  test2 = Turn[inter][b];

  //Decide if the vehicle should turn left or not (will be thru or right)
  if (test1 <= test2) return (b); else return (bae);
}

// * * * * * * * * * Check for Right Turn Selection * * * * * * * * * * * *

//Function called to see if the vehicle should turn right
//bae has a value of either 1, 3, 5, or 7
int RightCheck (int inter, int bae)
{
  double test1;
  double test2;
  int b;

  //Get random number between 0 and 100
  test1 = 100.0 * (double) rand()/ (double) RAND_MAX;

  //Compute conditional probability that the vehicle should turn right
  //RT percentage stored in the <bae> index location
  //RT%/(RT% + TH%) = RT%/(100% - LT%)
  b = bae + 3;
  if (b > 7) b = b - 8;
  test2 = 100.0 - Turn[inter][b];
  test2 = 100.0 * Turn[inter][bae]/ test2;

  //Decide if the vehicle should turn right or continue straight ahead
  if (test1 <= test2)
	{
	b = bae + 2;
	if (b == 9) b = 1;
	return (b);
	}
  else return (bae);
}

// * * * * * * * * * Next Movements to Service * * * * * * * * * * * *

// Routine that selects the next movements to service
// This routine is called by every signal indication that reaches rest green
// SigStat values are: 0-normal, 1-rest green, 2-next phase chosen but not implemented
// states are: 0-red, 1-initial green, 2-rest green, 3-yellow
// modes are:  0-pretimed, 1-fully actuated, 2-semi-actuated-coordinated,
//            3-random, 4-queue length management
// reasons for seeking a change are: 1-no presence, 2-forceoff, 3-max green, 4-rest green

void change (int inter, int reason)
{
  int j = 0;
  int regular = 0;
  int nextp;
  int move0;
  int move1;
  int State0;
  int State1;
  int MState[8];
  int Pres[8];
  int GoTo[8];
  int MaxQueue = 0;
  int y;
  int test0;
  int test1;
  double b;

//If a next phase has been chosen but not implemented, then return
  if (SigStat[inter] == 2) return;

//Get State0, State1 and test to see if anything should be done
//Each indication entering rest green makes a call to this routine
//Return if: 1) next phase not yet implemented, 2) both in MinGreen,
//           3) either in yellow, 4) either in red
  move0 = MovesByPhase[current[inter]][0];
  move1 = MovesByPhase[current[inter]][1];
  State0 = state[inter][move0];
  State1 = state[inter][move1];
//  fprintf (output4, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
//  	ncGetTime(), inter, current[inter], move0, move1, State0,
//    State1, presence[inter][move0], presence[inter][move1]);
  if ((State0 == 1) && (State1 == 1)) return;
  if ((State0 == 3) || (State1 == 3)) return;
  if ((State0 == 0) || (State1 == 0)) return;

//set next phase as undefined
  nextp = 99;

//Create local variables for all the presence and state data
//These data are not always used, but the overhead is small
  for (j = 0; j <=7; ++j)
    {
    Pres[j] = presence[inter][j];
    MState[j] = state[inter][j];
    }

//Pretimed (Mode=0)
//This is effectively semi-actuated, coordinated where all the minor movement times are fixed
  if (Mode[inter] == 0)
    {
    if ((State0 !=2) || (State1 != 2)) return;
    if ((current[inter] == Mainstreet[inter]) && (Permissive[inter][0]<1))
      {
      SigStat[inter] = 1;  //signal is in rest and needs to be re-examined
      return;
      }
    if (TwoPhase == 1)
      {
      switch (current[inter])
        {
        case 3: {nextp = 7; break;}
        case 7: {nextp = 3; break;}
        }
      }
    else
      {
      switch (current[inter])
        {
        case 0: {nextp = 3; break;}
        case 3: {nextp = 4; break;}
        case 4: {nextp = 7; break;}
        case 7: {nextp = 0; break;}
        }
      }

  //if no next phase is selected, then Mainstreet[inter] is selected
    if (nextp == 99) nextp = Mainstreet[inter];

    }
    //End of Pretimed logic

//Fully actuated (Mode=1)
  if (Mode[inter] == 1)
    {
    switch (current[inter])
      {
      case 0: //Moves 0 & 4
        if ((MState[0] == 1) && (MState[4] == 2) && (Pres[5] > 0)) nextp = 1;
        else if ((MState[0] == 2) && (MState[4] == 1) && (Pres[1] > 0)) nextp = 2;
        else if ((MState[0] == 2) && (MState[4] == 2))
          {
          if ((Pres[1] > 0) || (Pres[5] > 0)) nextp = 3;
          else if ((Pres[2] > 0) && (Pres[6] > 0)) nextp = 4;
          else if (Pres[2] > 0) nextp = 5;
          else if (Pres[6] > 0) nextp = 6;
          else if ((Pres[3] > 0) || (Pres[7] > 0)) nextp = 7;
          }
        //If no choice is made, nextp remains 99
        break;
      case 1: //Moves 0 & 5
        if ((MState[0] == 2) && (Pres[1] > 0)) nextp = 3;
        else if ((MState[0] == 2) && (MState[5] == 2))
          {
          if ((Pres[2] > 0) && (Pres[6] > 0)) nextp = 4;
          else if (Pres[2] > 0) nextp = 5;
          else if (Pres[6] > 0) nextp = 6;
          else if ((Pres[3] > 0) || (Pres[7] > 0)) nextp = 7;
          else if ((Pres[0] > 0) && (Pres[4] > 0)) nextp = 0;
          else if (Pres[4] > 0) nextp = 2;
          }
        //If no choice is made, nextp remains 99
        break;
      case 2: //Moves 1 & 4
        if ((MState[4] == 2) && (Pres[5] > 0)) nextp = 3;
        else if ((MState[1] == 2) && (MState[4] == 2))
          {
          if ((Pres[2] > 0) && (Pres[6] > 0)) nextp = 4;
          else if (Pres[2] > 0) nextp = 5;
          else if (Pres[6] > 0) nextp = 6;
          else if ((Pres[3] > 0) || (Pres[7] > 0)) nextp = 7;
          else if ((Pres[0] > 0) && (Pres[4] > 0)) nextp = 0;
          else if (Pres[0] > 0) nextp = 1;
          }
        //If no choice is made, nextp remains 99
        break;
      case 3: //Moves 1 & 5
        if ((MState[1] == 2) && (MState[5] == 2))
          {
          if ((Pres[2] > 0) && (Pres[6] > 0)) nextp = 4;
          else if (Pres[2] > 0) nextp = 5;
          else if (Pres[6] > 0) nextp = 6;
          else if ((Pres[3] > 0) || (Pres[7] > 0)) nextp = 7;
          else if ((Pres[0] > 0) && (Pres[4] > 0)) nextp = 0;
          else if (Pres[0] > 0) nextp = 1;
          else if (Pres[4] > 0) nextp = 2;
          }
        //If no choice is made, nextp remains 99
        break;
      case 4: //Moves 2 & 6
        if ((MState[2] == 1) && (MState[6] == 2) && (Pres[7] > 0)) nextp = 5;
        else if ((MState[2] == 2) && (MState[6] == 1) && (Pres[3] > 0)) nextp = 6;
        else if ((MState[2] == 2) && (MState[6] == 2))
          {
          if ((Pres[3] > 0) || (Pres[7] > 0)) nextp = 7;
          else if ((Pres[0] > 0) && (Pres[4] > 0)) nextp = 0;
          else if (Pres[0] > 0) nextp = 1;
          else if (Pres[4] > 0) nextp = 2;
          else if ((Pres[1] > 0) || (Pres[5] > 0)) nextp = 3;
          }
        //If no choice is made, nextp remains 99
        break;
      case 5: //Moves 2 & 7
        if ((MState[2] == 2) && (Pres[3] > 0)) nextp = 7;
        else if ((MState[2] == 2) && (MState[7] == 2))
          {
          if ((Pres[0] > 0) && (Pres[4] > 0)) nextp = 0;
          else if (Pres[0] > 0) nextp = 1;
          else if (Pres[4] > 0) nextp = 2;
          else if ((Pres[1] > 0) || (Pres[5] > 0)) nextp = 3;
          else if ((Pres[2] > 0) && (Pres[6] > 0)) nextp = 4;
          else if (Pres[6] > 0) nextp = 6;
          }
        //If no choice is made, nextp remains 99
        break;
      case 6: //Moves 3 & 6
        if ((MState[6] == 2) && (Pres[7] > 0)) nextp = 7;
        else if ((MState[3] == 2) && (MState[6] == 2))
          {
          if ((Pres[0] > 0) && (Pres[4] > 0)) nextp = 0;
          else if (Pres[0] > 0) nextp = 1;
          else if (Pres[4] > 0) nextp = 2;
          else if ((Pres[1] > 0) || (Pres[5] > 0)) nextp = 3;
          else if ((Pres[2] > 0) && (Pres[6] > 0)) nextp = 4;
          else if (Pres[2] > 0) nextp = 5;
          }
        //If no choice is made, nextp remains 99
        break;
      case 7:
        if ((MState[3] == 2) && (MState[7] == 2))
          {
          if ((Pres[0] > 0) && (Pres[4] > 0)) nextp = 0;
          else if (Pres[0] > 0) nextp = 1;
          else if (Pres[4] > 0) nextp = 2;
          else if ((Pres[1] > 0) || (Pres[5] > 0)) nextp = 3;
          else if ((Pres[2] > 0) && (Pres[6] > 0)) nextp = 4;
          else if (Pres[2] > 0) nextp = 5;
          else if (Pres[6] > 0) nextp = 6;
          }
        //If no choice is made, nextp remains 99
        break;
      }

    //If no next phase is selected, then Mainstreet[inter] is selected
    if (nextp == 99) nextp = Mainstreet[inter];

    }
    //End of fully actuated logic

//Semi-actuated, coordinated (Mode=2)
  if (Mode[inter] == 2)
    {
    //Determine the phases that can be served
    //Mainstreet[inter] = 3 implies EW, Mainstreet[inter] = 7 implies NS
      for (j = 0; j <= 7; j ++) GoTo[j] = 0;
      if (Mainstreet[inter] == 3) //then EW is the mainstreet
        {
        GoTo[1] = 1; GoTo[5] = 1;
        if (Permissive[inter][0]>0 && presence[inter][2] && ForceOff[inter][2]<1) GoTo[2] = 1;
        if (Permissive[inter][0]>0 && presence[inter][6] && ForceOff[inter][6]<1) GoTo[6] = 1;
        if (Permissive[inter][1]>0 && presence[inter][3] && ForceOff[inter][3]<1) GoTo[3] = 1;
        if (Permissive[inter][1]>0 && presence[inter][7] && ForceOff[inter][7]<1) GoTo[7] = 1;
        if (Permissive[inter][2]>0 && presence[inter][0] && ForceOff[inter][0]<1) GoTo[0] = 1;
        if (Permissive[inter][2]>0 && presence[inter][4] && ForceOff[inter][4]<1) GoTo[4] = 1;
        }
      else //(Mainstreet[inter] == 7) and NS is the mainstreet
        {
        GoTo[3] = 1; GoTo[7] = 1;
        if (Permissive[inter][0]>0 && presence[inter][0] && ForceOff[inter][0]<1) GoTo[0] = 1;
        if (Permissive[inter][0]>0 && presence[inter][4] && ForceOff[inter][4]<1) GoTo[4] = 1;
        if (Permissive[inter][1]>0 && presence[inter][1] && ForceOff[inter][1]<1) GoTo[1] = 1;
        if (Permissive[inter][1]>0 && presence[inter][5] && ForceOff[inter][5]<1) GoTo[5] = 1;
        if (Permissive[inter][2]>0 && presence[inter][2] && ForceOff[inter][2]<1) GoTo[2] = 1;
        if (Permissive[inter][2]>0 && presence[inter][6] && ForceOff[inter][6]<1) GoTo[6] = 1;
        };

    switch (current[inter])
      {
      case 0: //Moves 0 & 4
        if ((MState[0] == 1) && (MState[4] == 2) && (GoTo[5] > 0)) nextp = 1;
        else if ((MState[0] == 2) && (MState[4] == 1) && (GoTo[1] > 0)) nextp = 2;
        else if ((MState[0] == 2) && (MState[4] == 2))
          {
          if ((GoTo[1] > 0) || (GoTo[5] > 0)) nextp = 3;
          else if ((GoTo[2] > 0) && (GoTo[6] > 0)) nextp = 4;
          else if (GoTo[2] > 0) nextp = 5;
          else if (GoTo[6] > 0) nextp = 6;
          else if ((GoTo[3] > 0) || (GoTo[7] > 0)) nextp = 7;
          }
        //If no choice is made, nextp remains 99
        break;
      case 1: //Moves 0 & 5
        if ((MState[0] == 2) && (GoTo[1] > 0)) nextp = 3;
        else if ((MState[0] == 2) && (MState[5] == 2))
          {
          if ((GoTo[2] > 0) && (GoTo[6] > 0)) nextp = 4;
          else if (GoTo[2] > 0) nextp = 5;
          else if (GoTo[6] > 0) nextp = 6;
          else if ((GoTo[3] > 0) || (GoTo[7] > 0)) nextp = 7;
          else if ((GoTo[0] > 0) && (GoTo[4] > 0)) nextp = 0;
          else if (GoTo[4] > 0) nextp = 2;
          }
        //If no choice is made, nextp remains 99
        break;
      case 2: //Moves 1 & 4
        if ((MState[4] == 2) && (GoTo[5] > 0)) nextp = 3;
        else if ((MState[1] == 2) && (MState[4] == 2))
          {
          if ((GoTo[2] > 0) && (GoTo[6] > 0)) nextp = 4;
          else if (GoTo[2] > 0) nextp = 5;
          else if (GoTo[6] > 0) nextp = 6;
          else if ((GoTo[3] > 0) || (GoTo[7] > 0)) nextp = 7;
          else if ((GoTo[0] > 0) && (GoTo[4] > 0)) nextp = 0;
          else if (GoTo[0] > 0) nextp = 1;
          }
        //If no choice is made, nextp remains 99
        break;
      case 3: //Moves 1 & 5
        if ((MState[1] == 2) && (MState[5] == 2))
          {
          if ((GoTo[2] > 0) && (GoTo[6] > 0)) nextp = 4;
          else if (GoTo[2] > 0) nextp = 5;
          else if (GoTo[6] > 0) nextp = 6;
          else if ((GoTo[3] > 0) || (GoTo[7] > 0)) nextp = 7;
          else if ((GoTo[0] > 0) && (GoTo[4] > 0)) nextp = 0;
          else if (GoTo[0] > 0) nextp = 1;
          else if (GoTo[4] > 0) nextp = 2;
          }
        //If no choice is made, nextp remains 99
        break;
      case 4: //Moves 2 & 6
        if ((MState[2] == 1) && (MState[6] == 2) && (GoTo[7] > 0)) nextp = 5;
        else if ((MState[2] == 2) && (MState[6] == 1) && (GoTo[3] > 0)) nextp = 6;
        else if ((MState[2] == 2) && (MState[6] == 2))
          {
          if ((GoTo[3] > 0) || (GoTo[7] > 0)) nextp = 7;
          else if ((GoTo[0] > 0) && (GoTo[4] > 0)) nextp = 0;
          else if (GoTo[0] > 0) nextp = 1;
          else if (GoTo[4] > 0) nextp = 2;
          else if ((GoTo[1] > 0) || (GoTo[5] > 0)) nextp = 3;
          }
        //If no choice is made, nextp remains 99
        break;
      case 5: //Moves 2 & 7
        if ((MState[2] == 2) && (GoTo[3] > 0)) nextp = 7;
        else if ((MState[2] == 2) && (MState[7] == 2))
          {
          if ((GoTo[0] > 0) && (GoTo[4] > 0)) nextp = 0;
          else if (GoTo[0] > 0) nextp = 1;
          else if (GoTo[4] > 0) nextp = 2;
          else if ((GoTo[1] > 0) || (GoTo[5] > 0)) nextp = 3;
          else if ((GoTo[2] > 0) && (GoTo[6] > 0)) nextp = 4;
          else if (GoTo[6] > 0) nextp = 6;
          }
        //If no choice is made, nextp remains 99
        break;
      case 6: //Moves 3 & 6
        if ((MState[6] == 2) && (GoTo[7] > 0)) nextp = 7;
        else if ((MState[3] == 2) && (MState[6] == 2))
          {
          if ((GoTo[0] > 0) && (GoTo[4] > 0)) nextp = 0;
          else if (GoTo[0] > 0) nextp = 1;
          else if (GoTo[4] > 0) nextp = 2;
          else if ((GoTo[1] > 0) || (GoTo[5] > 0)) nextp = 3;
          else if ((GoTo[2] > 0) && (GoTo[6] > 0)) nextp = 4;
          else if (GoTo[2] > 0) nextp = 5;
          }
        //If no choice is made, nextp remains 99
        break;
      case 7:
        if ((MState[3] == 2) && (MState[7] == 2))
          {
          if ((GoTo[0] > 0) && (GoTo[4] > 0)) nextp = 0;
          else if (GoTo[0] > 0) nextp = 1;
          else if (GoTo[4] > 0) nextp = 2;
          else if ((GoTo[1] > 0) || (GoTo[5] > 0)) nextp = 3;
          else if ((GoTo[2] > 0) && (GoTo[6] > 0)) nextp = 4;
          else if (GoTo[2] > 0) nextp = 5;
          else if (GoTo[6] > 0) nextp = 6;
          }
        //If no choice is made, nextp remains 99
        break;
      }

    //If no next phase is selected, then the current phase is retained
    //This happens when one phase is still in min green because of the processing order
    if (nextp == 99) nextp = current[inter];

    }
    //End of semi-actuated, coordinated logic

//Random phase selection (Mode=3)
  if (Mode[inter] == 3)
    {
    if ((State0 != 2) || (State1 != 2)) return;
    b = 7.999 * (double) rand() / (double) RAND_MAX;
    nextp = (int) b;

    //If no next phase is selected, then Mainstreet[inter] is selected
    if (nextp == 99) nextp = Mainstreet[inter];

    }
    //End of random phase selection logic

//Queue length management
  if (Mode[inter] == 4)
    {
    if ((State0 != 2) || (State1 != 2)) return;
    for (j = 0; j <= 7; j++)
      {
      test0 = MovesByPhase[j][0];
	    test1 = MovesByPhase[j][1];
      y = presence[inter][test0] + presence[inter][test1];
      if (y > MaxQueue) {MaxQueue = y; nextp = j;}
      }

    //If no next phase is selected, then Mainstreet[inter] is selected
    if (nextp == 99) nextp = Mainstreet[inter];

    }
    //End of queue length management logic

//Closing logic in preparation for transition
//TransToPhase is the array read by the signal control logic
//TransToPhase[inter][phase] = 1 means transition, else do not transition
//If nextp is 99, no new phase choice was made, and nextp remains current[inter]

  if (nextp != current[inter])
    {
    TransToPhase[inter][nextp] = 1; //else it stays 0
    next[inter] = nextp;
    SigStat[inter] = 2;
    TermCond[inter] = reason;
    if (next[inter] == Mainstreet[inter] && Mode[inter] == 2)
      for (j = 0; j <=2; j++) Permissive[inter][j] = 0;
    }
  else
    SigStat[inter] = 1;  //signal is in rest and needs to be re-examined
}

// * * * * * * Re-examine Signals in Green Rest * * * * * * * * *
// Seek next phase choices for signals that are in green rest

void SigCheck()
{
  int i;

  for (i = 0; i <= 5; i++)
    if (SigStat[i] == 1) change(i,4);
}

// * * * * * * * * * Update Signal Status * * * * * * * * * * * *
// Update signal status, including current phase and cycle length

void UpdateSig(int inter, int phase)
{
  int j;
  double MaxOn;
  double on1;
  double on2;

  SigStat[inter] = 0;
  TransToPhase[inter][phase] = 0;
  last[inter] = current[inter];
  current[inter] = next[inter];
//fprintf (output5,"%d\t%d\t%d\t%d\t%d\n",
//  ncGetTime(), inter, Mode[inter], current[inter], TermCond[inter]);

//If Mainstreet, compute desired cycle length based on worst of top and bottom ring
  if (Mainstreet[inter] == phase)
    {
    on1 = 0.0;
    on2 = 0.0;
    for (j = 0; j <=3; j++) on1 = on1 + 0.1 * AvgGrnOn[inter][j];
    for (j = 4; j <=7; j++) on2 = on2 + 0.1 * AvgGrnOn[inter][j];

    if (on1 > on2) MaxOn = on1; else MaxOn = on2;

    DesiredCycle [inter] = (int)((double) beta * MaxOn / (double) MasterCycle);
    fprintf (output7, "%d\t%d\t%f\t%d\t%d\n", ncGetTime(),
      inter, MaxOn, DesiredCycle[inter], MasterCycle );
    }
}

// * * * * * * * * * Force Off Management * * * * * * * * * * * *

//Only really relevant if signal is operating semi-actuated
//Note that forceoffs and permissives are reset in GetSetForNextRelease

void Force(int inter, int window)
{
  int j;

  if (Mode[inter] != 2)
    {
    for (j = 0; j <=7; j++) ForceOff[inter][j] = 0;
    return;
    }
  if (Mainstreet[inter] == 3)
    {
    switch (window)
      {
      case 0: { ForceOff[inter][2] = 1; ForceOff[inter][6] = 1; break; }
      case 1: { ForceOff[inter][3] = 1; ForceOff[inter][7] = 1; break; }
      case 2: { ForceOff[inter][0] = 1; ForceOff[inter][4] = 1; break; }
      }
    }
  else //(Mainstreet[inter] == 7)
    {
    switch (window)
      {
      case 0: { ForceOff[inter][0] = 1; ForceOff[inter][4] = 1; break; }
      case 1: { ForceOff[inter][1] = 1; ForceOff[inter][5] = 1; break; }
      case 2: { ForceOff[inter][2] = 1; ForceOff[inter][6] = 1; break; }
      }
    }
}

// * * * * * * * * * Detector and Signal Data * * * * * * * * * * * *

// Updates detector and signal data:
// current and average on-time for both green and red indications
// 0-car leaves detector, 1-car enters detector, 2-signal goes green, 3-signal goes red

void PerOnTime(int inter, int bae, int onoff)
{

  int j;

  switch (onoff)
    {
    case 0: //car leaves detector
      if (presence[inter][bae] == 0)
        {
        CurOn[inter][bae] += (ncGetTime() - onstart[inter][bae]);
        on[inter][bae] = 0;
        }
      break;
    case 1: //car enters detector
      if (on[inter][bae] == 0) onstart[inter][bae] = ncGetTime();
      on[inter][bae] = 1;
      break;
    case 2: //signal goes green
      // signal indication data
      CurRed[inter][bae] = ncGetTime() - RedStart[inter][bae];
      AvgRed[inter][bae] = 0.3 * AvgRed[inter][bae]
        + 0.7 * CurRed[inter][bae];
      GrnStart[inter][bae] = ncGetTime();
      fprintf (output3, "%d\t%d\t%d\t%d\t%d", ncGetTime(), inter,
        current[inter], bae, state[inter][bae] );
      for (j = 0; j <=6; j++) fprintf(output3, "\t%d", presence[inter][j] );
      fprintf(output3, "\t%d\n", presence[inter][7] );
      // detector data
      if (on[inter][bae] == 1) CurOn[inter][bae] += (ncGetTime() - onstart[inter][bae]);
      if (CurRed[inter][bae] > 0)
        AvgRedOn[inter][bae] = 0.3 * AvgRedOn[inter][bae]
          + 0.7 * (CurOn[inter][bae]/CurRed[inter][bae]);
      else
        AvgRedOn[inter][bae] = 0;
      if (on[inter][bae] == 1) onstart[inter][bae] = ncGetTime();
    //fprintf (output2, "%d\t%d\t%d\t%f\t%f\t%d\n", ncGetTime(), inter,
    //  bae, CurOn[inter][bae], AvgRedOn[inter][bae], 1);
      CurOn[inter][bae] = 0;
      break;
    case 3: //signal goes red
      // signal indication data
      CurGrn[inter][bae] = ncGetTime() - GrnStart[inter][bae];
      AvgGrn[inter][bae] = 0.3 * AvgGrn[inter][bae]
        + 0.7 * CurGrn[inter][bae];
      RedStart[inter][bae] = ncGetTime();
      fprintf (output3, "%d\t%d\t%d\t%d\t%d", ncGetTime(), inter,
        current[inter], bae, state[inter][bae] );
      for (j = 0; j <=6; j++) fprintf(output3, "\t%d", presence[inter][j] );
      fprintf(output3, "\t%d\n", presence[inter][7] );
      // detector data
      if (on[inter][bae] == 1) CurOn[inter][bae] += (ncGetTime() - onstart[inter][bae]);
      if (CurGrn[inter][bae] > 0)
        AvgGrnOn[inter][bae] = 0.3 * AvgGrnOn[inter][bae] + 0.7 * CurOn[inter][bae];
      else
        AvgGrnOn[inter][bae] = 0;
      if (on[inter][bae] == 1) onstart[inter][bae] = ncGetTime();
    //fprintf (output2, "%d\t%d\t%d\t%f\t%f\t%d\n",ncGetTime(),
    //  inter, bae, CurOn[inter][bae], AvgGrnOn[inter][bae], 0);
      CurOn[inter][bae] = 0;
      break;
    }
}

// * * * * * * Update Master Cycle Length * * * * * * * * *
// Record end of current cycle and make adjustment to master cycle length

void UpdateMasterCycle()
{
  int i;
  int j;
  int temp;
  int adj;

  adj = (int) (MaxCycAdjPct / 100.0 * (double) MasterCycle);
  EndCycle = (int) ncGetTime();
  temp = MinCycle;
  for (i = 0; i <= 5; i++)
    {
    if (Mode[i] != 2) return;
    if (DesiredCycle[i] > temp) temp = DesiredCycle[i];
    }
  if (temp - MasterCycle > adj) MasterCycle = MasterCycle + adj;
  else if (temp - MasterCycle < - adj) MasterCycle = MasterCycle - adj;
  else MasterCycle = temp;
  if (MasterCycle > MaxCycle) MasterCycle = MaxCycle;
  AvgMasterCycle = 0.3 * AvgMasterCycle + 0.7 * MasterCycle;
  MaxOffAdj = MaxOffAdjPct / 100.0 * (double)MasterCycle;
  for (i = 0; i <= 5; i++)
  for (j = 0; j <= 2; j++)
    {
    PermissiveTime[i][j] = (int)(PermissiveTimePct[i][j] /100.0 * MasterCycle );
    ForceTime[i][j] = (int)(ForceTimePct[i][j] /100.0 * MasterCycle );
    }
  fprintf (output7, "%d\t%d\t%d\t%f\t%d\n", ncGetTime(),
    -1, temp, AvgMasterCycle, MasterCycle);

}

// * * * * * * Calculate new time to next signal release * * * * * * * * *
// Work with current cycle length and offsets to determine time to next release

void GetSetForNextRelease(int inter)
{
  int j;
  double OffAdj;

  for (j = 0; j <= 2; j++) Permissive[inter][j] = 1;
  for (j = 0; j <= 7; j++) ForceOff[inter][j] = 0;

//If mode = 2, then adjust the offset, otherwise leave it at its initial value
  if (Mode[inter] == 2)
    {
    OldOffset[inter] = Offset[inter];
    OffAdj = 0;
    for (j = 0; j <= 7; j++)
      OffAdj = OffAdj -
        MaxOffAdj*((double)OffAdjWt[inter][j]/100.0)*tan(pi*AvgRedOn[inter][j]);
    if (OffAdj > MaxOffAdj) OffAdj = MaxOffAdj;
    if (OffAdj < -MaxOffAdj) OffAdj = - MaxOffAdj;
    Offset[inter] = Offset[inter] + (int) OffAdj;
    }

  TimeToRelease[inter] = (EndCycle + MasterCycle + Offset[inter]) - (int)ncGetTime();
  if (TimeToRelease[inter]<MasterCycle/2)
    TimeToRelease[inter] = TimeToRelease[inter] + MasterCycle;

//fprintf (output6, "%d\t%d\t%d\t%f\t%d\t%d\n", ncGetTime(),
//  MasterCycle, inter, OffAdj,Offset[inter], TimeToRelease[inter]);

}

//end of code


