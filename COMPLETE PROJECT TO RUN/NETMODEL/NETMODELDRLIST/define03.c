/* this file was generated from the NETMAN file:
	define03.c
	06/18/14 13:17:42
*/
#define SUPER_USER
#include "petri.h"
#include "userfunc.h"
#include <stdlib.h>

#ifndef CONST_NET
#ifdef SEGMENTED_MEMORY
void DefineNet3()
{
NCTArc *parcInputs, *parcOutputs;

InitPlace( 1249, "", 4, 0 );
net.place[1249].number[1] = 9;
net.place[1249].number[2] = 18;
net.place[1249].number[3] = 428;

InitPlace( 1250, "", 4, 0 );
net.place[1250].number[1] = 9;
net.place[1250].number[2] = 18;
net.place[1250].number[3] = 449;

InitPlace( 1251, "", 4, 0 );
net.place[1251].number[1] = 9;
net.place[1251].number[2] = 18;
net.place[1251].number[3] = 457;

InitPlace( 1252, "", 4, 0 );
net.place[1252].number[1] = 9;
net.place[1252].number[2] = 18;
net.place[1252].number[3] = 481;

InitPlace( 1253, "", 4, 0 );
net.place[1253].number[1] = 9;
net.place[1253].number[2] = 18;
net.place[1253].number[3] = 500;

InitPlace( 1254, "", 4, 0 );
net.place[1254].number[1] = 9;
net.place[1254].number[2] = 18;
net.place[1254].number[3] = 533;

InitPlace( 1255, "", 4, 0 );
net.place[1255].number[1] = 9;
net.place[1255].number[2] = 18;
net.place[1255].number[3] = 534;

InitPlace( 1256, "", 4, 0 );
net.place[1256].number[1] = 9;
net.place[1256].number[2] = 18;
net.place[1256].number[3] = 551;

InitPlace( 1257, "", 4, 0 );
net.place[1257].number[1] = 9;
net.place[1257].number[2] = 18;
net.place[1257].number[3] = 584;

InitPlace( 1258, "", 4, 0 );
net.place[1258].number[1] = 9;
net.place[1258].number[2] = 18;
net.place[1258].number[3] = 585;

InitPlace( 1259, "", 4, 0 );
net.place[1259].number[1] = 9;
net.place[1259].number[2] = 18;
net.place[1259].number[3] = 634;

InitPlace( 1260, "", 4, 0 );
net.place[1260].number[1] = 9;
net.place[1260].number[2] = 18;
net.place[1260].number[3] = 635;

InitPlace( 1261, "", 4, 0 );
net.place[1261].number[1] = 9;
net.place[1261].number[2] = 18;
net.place[1261].number[3] = 636;

InitPlace( 1262, "", 4, 0 );
net.place[1262].number[1] = 9;
net.place[1262].number[2] = 18;
net.place[1262].number[3] = 669;

InitPlace( 1263, "", 4, 0 );
net.place[1263].number[1] = 9;
net.place[1263].number[2] = 18;
net.place[1263].number[3] = 670;

InitPlace( 1264, "", 4, 0 );
net.place[1264].number[1] = 9;
net.place[1264].number[2] = 18;
net.place[1264].number[3] = 707;

InitPlace( 1265, "", 4, 0 );
net.place[1265].number[1] = 9;
net.place[1265].number[2] = 18;
net.place[1265].number[3] = 732;

InitPlace( 1266, "", 4, 0 );
net.place[1266].number[1] = 9;
net.place[1266].number[2] = 18;
net.place[1266].number[3] = 749;

InitPlace( 1267, "", 4, 0 );
net.place[1267].number[1] = 9;
net.place[1267].number[2] = 18;
net.place[1267].number[3] = 758;

InitPlace( 1268, "", 4, 0 );
net.place[1268].number[1] = 9;
net.place[1268].number[2] = 18;
net.place[1268].number[3] = 799;

InitPlace( 1269, "", 4, 0 );
net.place[1269].number[1] = 9;
net.place[1269].number[2] = 18;
net.place[1269].number[3] = 808;

InitPlace( 1270, "", 4, 0 );
net.place[1270].number[1] = 9;
net.place[1270].number[2] = 18;
net.place[1270].number[3] = 809;

InitPlace( 1271, "", 4, 0 );
net.place[1271].number[1] = 9;
net.place[1271].number[2] = 18;
net.place[1271].number[3] = 834;

InitPlace( 1272, "", 4, 0 );
net.place[1272].number[1] = 9;
net.place[1272].number[2] = 18;
net.place[1272].number[3] = 843;

InitPlace( 1273, "", 4, 0 );
net.place[1273].number[1] = 9;
net.place[1273].number[2] = 18;
net.place[1273].number[3] = 860;

InitPlace( 1274, "", 4, 0 );
net.place[1274].number[1] = 9;
net.place[1274].number[2] = 18;
net.place[1274].number[3] = 885;

InitPlace( 1275, "", 4, 0 );
net.place[1275].number[1] = 9;
net.place[1275].number[2] = 18;
net.place[1275].number[3] = 918;

InitPlace( 1276, "", 4, 0 );
net.place[1276].number[1] = 9;
net.place[1276].number[2] = 18;
net.place[1276].number[3] = 927;

InitPlace( 1277, "", 4, 0 );
net.place[1277].number[1] = 9;
net.place[1277].number[2] = 18;
net.place[1277].number[3] = 936;

InitPlace( 1278, "", 4, 0 );
net.place[1278].number[1] = 9;
net.place[1278].number[2] = 18;
net.place[1278].number[3] = 945;

InitPlace( 1279, "", 4, 0 );
net.place[1279].number[1] = 9;
net.place[1279].number[2] = 18;
net.place[1279].number[3] = 986;

InitPlace( 1280, "", 4, 0 );
net.place[1280].number[1] = 9;
net.place[1280].number[2] = 18;
net.place[1280].number[3] = 987;

InitPlace( 1281, "", 4, 0 );
net.place[1281].number[1] = 9;
net.place[1281].number[2] = 18;
net.place[1281].number[3] = 996;

InitPlace( 1282, "", 4, 0 );
net.place[1282].number[1] = 9;
net.place[1282].number[2] = 18;
net.place[1282].number[3] = 1021;

InitPlace( 1283, "", 4, 0 );
net.place[1283].number[1] = 9;
net.place[1283].number[2] = 18;
net.place[1283].number[3] = 1030;

InitPlace( 1284, "", 4, 0 );
net.place[1284].number[1] = 9;
net.place[1284].number[2] = 18;
net.place[1284].number[3] = 1047;

InitPlace( 1285, "", 4, 0 );
net.place[1285].number[1] = 9;
net.place[1285].number[2] = 18;
net.place[1285].number[3] = 1064;

InitPlace( 1286, "", 4, 0 );
net.place[1286].number[1] = 9;
net.place[1286].number[2] = 18;
net.place[1286].number[3] = 1081;

InitPlace( 1287, "", 4, 0 );
net.place[1287].number[1] = 9;
net.place[1287].number[2] = 18;
net.place[1287].number[3] = 1098;

InitPlace( 1288, "", 4, 0 );
net.place[1288].number[1] = 9;
net.place[1288].number[2] = 18;
net.place[1288].number[3] = 1107;

InitPlace( 1289, "", 4, 0 );
net.place[1289].number[1] = 9;
net.place[1289].number[2] = 18;
net.place[1289].number[3] = 1132;

InitPlace( 1290, "", 4, 0 );
net.place[1290].number[1] = 9;
net.place[1290].number[2] = 18;
net.place[1290].number[3] = 1149;

InitPlace( 1291, "", 4, 0 );
net.place[1291].number[1] = 9;
net.place[1291].number[2] = 18;
net.place[1291].number[3] = 1166;

InitPlace( 1292, "", 3, 0 );
net.place[1292].number[1] = 9;
net.place[1292].number[2] = 19;

InitPlace( 1293, "", 3, 0 );
net.place[1293].number[1] = 9;
net.place[1293].number[2] = 20;

InitPlace( 1294, "", 3, 0 );
net.place[1294].number[1] = 9;
net.place[1294].number[2] = 21;

InitPlace( 1295, "", 3, 0 );
net.place[1295].number[1] = 9;
net.place[1295].number[2] = 22;

InitPlace( 1296, "", 3, 1 );
net.place[1296].number[1] = 9;
net.place[1296].number[2] = 23;

InitPlace( 1297, "", 3, 1 );
net.place[1297].number[1] = 9;
net.place[1297].number[2] = 24;

InitPlace( 1298, "", 3, 1 );
net.place[1298].number[1] = 9;
net.place[1298].number[2] = 169;

InitPlace( 1299, "", 3, 1 );
net.place[1299].number[1] = 9;
net.place[1299].number[2] = 172;

InitPlace( 1300, "", 3, 1 );
net.place[1300].number[1] = 9;
net.place[1300].number[2] = 175;

InitPlace( 1301, "", 3, 1 );
net.place[1301].number[1] = 9;
net.place[1301].number[2] = 177;

InitPlace( 1302, "", 3, 1 );
net.place[1302].number[1] = 9;
net.place[1302].number[2] = 179;

InitPlace( 1303, "", 3, 1 );
net.place[1303].number[1] = 9;
net.place[1303].number[2] = 180;

InitPlace( 1304, "", 3, 1 );
net.place[1304].number[1] = 9;
net.place[1304].number[2] = 181;

InitPlace( 1305, "", 3, 1 );
net.place[1305].number[1] = 9;
net.place[1305].number[2] = 182;

InitPlace( 1306, "", 3, 1 );
net.place[1306].number[1] = 9;
net.place[1306].number[2] = 183;

InitPlace( 1307, "", 3, 1 );
net.place[1307].number[1] = 9;
net.place[1307].number[2] = 184;

InitPlace( 1308, "", 3, 1 );
net.place[1308].number[1] = 9;
net.place[1308].number[2] = 185;

InitPlace( 1309, "", 3, 1 );
net.place[1309].number[1] = 9;
net.place[1309].number[2] = 186;

InitPlace( 1310, "", 3, 1 );
net.place[1310].number[1] = 9;
net.place[1310].number[2] = 187;

InitPlace( 1311, "", 3, 1 );
net.place[1311].number[1] = 9;
net.place[1311].number[2] = 188;

InitPlace( 1312, "", 3, 1 );
net.place[1312].number[1] = 9;
net.place[1312].number[2] = 189;

InitPlace( 1313, "", 3, 1 );
net.place[1313].number[1] = 9;
net.place[1313].number[2] = 190;

InitPlace( 1314, "", 3, 1 );
net.place[1314].number[1] = 9;
net.place[1314].number[2] = 193;

InitPlace( 1315, "", 3, 0 );
net.place[1315].number[1] = 9;
net.place[1315].number[2] = 197;

InitPlace( 1316, "", 3, 1 );
net.place[1316].number[1] = 9;
net.place[1316].number[2] = 198;

InitPlace( 1317, "", 3, 1 );
net.place[1317].number[1] = 9;
net.place[1317].number[2] = 199;

InitPlace( 1318, "", 3, 1 );
net.place[1318].number[1] = 9;
net.place[1318].number[2] = 200;

InitPlace( 1319, "", 3, 1 );
net.place[1319].number[1] = 9;
net.place[1319].number[2] = 209;

InitPlace( 1320, "", 3, 1 );
net.place[1320].number[1] = 9;
net.place[1320].number[2] = 210;

InitPlace( 1321, "", 3, 1 );
net.place[1321].number[1] = 9;
net.place[1321].number[2] = 211;

InitPlace( 1322, "", 3, 1 );
net.place[1322].number[1] = 9;
net.place[1322].number[2] = 212;

InitPlace( 1323, "", 3, 1 );
net.place[1323].number[1] = 9;
net.place[1323].number[2] = 213;

InitPlace( 1324, "", 3, 1 );
net.place[1324].number[1] = 9;
net.place[1324].number[2] = 214;

InitPlace( 1325, "", 3, 1 );
net.place[1325].number[1] = 9;
net.place[1325].number[2] = 217;

InitPlace( 1326, "", 3, 1 );
net.place[1326].number[1] = 9;
net.place[1326].number[2] = 218;

InitPlace( 1327, "", 3, 1 );
net.place[1327].number[1] = 9;
net.place[1327].number[2] = 221;

InitPlace( 1328, "", 3, 1 );
net.place[1328].number[1] = 9;
net.place[1328].number[2] = 229;

InitPlace( 1329, "", 3, 1 );
net.place[1329].number[1] = 9;
net.place[1329].number[2] = 232;

InitPlace( 1330, "", 3, 1 );
net.place[1330].number[1] = 9;
net.place[1330].number[2] = 233;

InitPlace( 1331, "", 3, 1 );
net.place[1331].number[1] = 9;
net.place[1331].number[2] = 234;

InitPlace( 1332, "", 3, 1 );
net.place[1332].number[1] = 9;
net.place[1332].number[2] = 237;

InitPlace( 1333, "", 3, 1 );
net.place[1333].number[1] = 9;
net.place[1333].number[2] = 238;

InitPlace( 1334, "", 3, 1 );
net.place[1334].number[1] = 9;
net.place[1334].number[2] = 239;

InitPlace( 1335, "", 3, 1 );
net.place[1335].number[1] = 9;
net.place[1335].number[2] = 242;

InitPlace( 1336, "", 3, 1 );
net.place[1336].number[1] = 9;
net.place[1336].number[2] = 252;

InitPlace( 1337, "", 3, 1 );
net.place[1337].number[1] = 9;
net.place[1337].number[2] = 253;

InitPlace( 1338, "", 3, 1 );
net.place[1338].number[1] = 9;
net.place[1338].number[2] = 254;

InitPlace( 1339, "", 3, 1 );
net.place[1339].number[1] = 9;
net.place[1339].number[2] = 255;

InitPlace( 1340, "", 3, 1 );
net.place[1340].number[1] = 10;
net.place[1340].number[2] = 0;

InitPlace( 1341, "", 3, 1 );
net.place[1341].number[1] = 10;
net.place[1341].number[2] = 1;

InitPlace( 1342, "", 3, 1 );
net.place[1342].number[1] = 10;
net.place[1342].number[2] = 2;

InitPlace( 1343, "", 4, 1 );
net.place[1343].number[1] = 10;
net.place[1343].number[2] = 3;
net.place[1343].number[3] = 0;

InitPlace( 1344, "", 4, 1 );
net.place[1344].number[1] = 10;
net.place[1344].number[2] = 3;
net.place[1344].number[3] = 1;

InitPlace( 1345, "", 4, 1 );
net.place[1345].number[1] = 10;
net.place[1345].number[2] = 3;
net.place[1345].number[3] = 2;

InitPlace( 1346, "", 4, 1 );
net.place[1346].number[1] = 10;
net.place[1346].number[2] = 3;
net.place[1346].number[3] = 3;

InitPlace( 1347, "", 4, 1 );
net.place[1347].number[1] = 10;
net.place[1347].number[2] = 3;
net.place[1347].number[3] = 5;

InitPlace( 1348, "", 4, 1 );
net.place[1348].number[1] = 10;
net.place[1348].number[2] = 3;
net.place[1348].number[3] = 6;

InitPlace( 1349, "", 4, 1 );
net.place[1349].number[1] = 10;
net.place[1349].number[2] = 3;
net.place[1349].number[3] = 7;

InitPlace( 1350, "", 3, 1 );
net.place[1350].number[1] = 10;
net.place[1350].number[2] = 4;

InitPlace( 1351, "", 4, 1 );
net.place[1351].number[1] = 10;
net.place[1351].number[2] = 8;
net.place[1351].number[3] = 0;

InitPlace( 1352, "", 4, 1 );
net.place[1352].number[1] = 10;
net.place[1352].number[2] = 8;
net.place[1352].number[3] = 1;

InitPlace( 1353, "", 4, 1 );
net.place[1353].number[1] = 10;
net.place[1353].number[2] = 8;
net.place[1353].number[3] = 2;

InitPlace( 1354, "", 4, 1 );
net.place[1354].number[1] = 10;
net.place[1354].number[2] = 8;
net.place[1354].number[3] = 3;

InitPlace( 1355, "", 4, 1 );
net.place[1355].number[1] = 10;
net.place[1355].number[2] = 8;
net.place[1355].number[3] = 5;

InitPlace( 1356, "", 4, 1 );
net.place[1356].number[1] = 10;
net.place[1356].number[2] = 8;
net.place[1356].number[3] = 6;

InitPlace( 1357, "", 4, 1 );
net.place[1357].number[1] = 10;
net.place[1357].number[2] = 8;
net.place[1357].number[3] = 7;

InitPlace( 1358, "", 4, 1 );
net.place[1358].number[1] = 10;
net.place[1358].number[2] = 10;
net.place[1358].number[3] = 0;

InitPlace( 1359, "", 4, 1 );
net.place[1359].number[1] = 10;
net.place[1359].number[2] = 10;
net.place[1359].number[3] = 1;

InitPlace( 1360, "", 4, 1 );
net.place[1360].number[1] = 10;
net.place[1360].number[2] = 10;
net.place[1360].number[3] = 2;

InitPlace( 1361, "", 4, 1 );
net.place[1361].number[1] = 10;
net.place[1361].number[2] = 10;
net.place[1361].number[3] = 3;

InitPlace( 1362, "", 4, 1 );
net.place[1362].number[1] = 10;
net.place[1362].number[2] = 10;
net.place[1362].number[3] = 5;

InitPlace( 1363, "", 4, 1 );
net.place[1363].number[1] = 10;
net.place[1363].number[2] = 10;
net.place[1363].number[3] = 6;

InitPlace( 1364, "", 4, 1 );
net.place[1364].number[1] = 10;
net.place[1364].number[2] = 10;
net.place[1364].number[3] = 7;

InitPlace( 1365, "", 4, 1 );
net.place[1365].number[1] = 10;
net.place[1365].number[2] = 11;
net.place[1365].number[3] = 0;

InitPlace( 1366, "", 4, 1 );
net.place[1366].number[1] = 10;
net.place[1366].number[2] = 11;
net.place[1366].number[3] = 1;

InitPlace( 1367, "", 4, 1 );
net.place[1367].number[1] = 10;
net.place[1367].number[2] = 11;
net.place[1367].number[3] = 2;

InitPlace( 1368, "", 4, 1 );
net.place[1368].number[1] = 10;
net.place[1368].number[2] = 11;
net.place[1368].number[3] = 3;

InitPlace( 1369, "", 4, 1 );
net.place[1369].number[1] = 10;
net.place[1369].number[2] = 11;
net.place[1369].number[3] = 5;

InitPlace( 1370, "", 4, 1 );
net.place[1370].number[1] = 10;
net.place[1370].number[2] = 11;
net.place[1370].number[3] = 6;

InitPlace( 1371, "", 4, 1 );
net.place[1371].number[1] = 10;
net.place[1371].number[2] = 11;
net.place[1371].number[3] = 7;

InitPlace( 1372, "", 4, 1 );
net.place[1372].number[1] = 10;
net.place[1372].number[2] = 12;
net.place[1372].number[3] = 0;

InitPlace( 1373, "", 4, 1 );
net.place[1373].number[1] = 10;
net.place[1373].number[2] = 12;
net.place[1373].number[3] = 1;

InitPlace( 1374, "", 4, 1 );
net.place[1374].number[1] = 10;
net.place[1374].number[2] = 12;
net.place[1374].number[3] = 2;

InitPlace( 1375, "", 4, 1 );
net.place[1375].number[1] = 10;
net.place[1375].number[2] = 12;
net.place[1375].number[3] = 3;

InitPlace( 1376, "", 4, 1 );
net.place[1376].number[1] = 10;
net.place[1376].number[2] = 12;
net.place[1376].number[3] = 5;

InitPlace( 1377, "", 4, 1 );
net.place[1377].number[1] = 10;
net.place[1377].number[2] = 12;
net.place[1377].number[3] = 6;

InitPlace( 1378, "", 4, 1 );
net.place[1378].number[1] = 10;
net.place[1378].number[2] = 12;
net.place[1378].number[3] = 7;

InitPlace( 1379, "", 4, 1 );
net.place[1379].number[1] = 10;
net.place[1379].number[2] = 13;
net.place[1379].number[3] = 0;

InitPlace( 1380, "", 4, 1 );
net.place[1380].number[1] = 10;
net.place[1380].number[2] = 13;
net.place[1380].number[3] = 1;

InitPlace( 1381, "", 4, 1 );
net.place[1381].number[1] = 10;
net.place[1381].number[2] = 13;
net.place[1381].number[3] = 2;

InitPlace( 1382, "", 4, 1 );
net.place[1382].number[1] = 10;
net.place[1382].number[2] = 13;
net.place[1382].number[3] = 3;

InitPlace( 1383, "", 4, 1 );
net.place[1383].number[1] = 10;
net.place[1383].number[2] = 13;
net.place[1383].number[3] = 5;

InitPlace( 1384, "", 4, 1 );
net.place[1384].number[1] = 10;
net.place[1384].number[2] = 13;
net.place[1384].number[3] = 6;

InitPlace( 1385, "", 4, 1 );
net.place[1385].number[1] = 10;
net.place[1385].number[2] = 13;
net.place[1385].number[3] = 7;

InitPlace( 1386, "", 4, 1 );
net.place[1386].number[1] = 10;
net.place[1386].number[2] = 14;
net.place[1386].number[3] = 0;

InitPlace( 1387, "", 4, 1 );
net.place[1387].number[1] = 10;
net.place[1387].number[2] = 14;
net.place[1387].number[3] = 1;

InitPlace( 1388, "", 4, 1 );
net.place[1388].number[1] = 10;
net.place[1388].number[2] = 14;
net.place[1388].number[3] = 2;

InitPlace( 1389, "", 4, 1 );
net.place[1389].number[1] = 10;
net.place[1389].number[2] = 14;
net.place[1389].number[3] = 3;

InitPlace( 1390, "", 4, 1 );
net.place[1390].number[1] = 10;
net.place[1390].number[2] = 14;
net.place[1390].number[3] = 5;

InitPlace( 1391, "", 4, 1 );
net.place[1391].number[1] = 10;
net.place[1391].number[2] = 14;
net.place[1391].number[3] = 6;

InitPlace( 1392, "", 4, 1 );
net.place[1392].number[1] = 10;
net.place[1392].number[2] = 14;
net.place[1392].number[3] = 7;

InitPlace( 1393, "", 3, 1 );
net.place[1393].number[1] = 10;
net.place[1393].number[2] = 15;

InitPlace( 1394, "", 4, 1 );
net.place[1394].number[1] = 10;
net.place[1394].number[2] = 16;
net.place[1394].number[3] = 0;

InitPlace( 1395, "", 4, 1 );
net.place[1395].number[1] = 10;
net.place[1395].number[2] = 16;
net.place[1395].number[3] = 1;

InitPlace( 1396, "", 4, 1 );
net.place[1396].number[1] = 10;
net.place[1396].number[2] = 16;
net.place[1396].number[3] = 2;

InitPlace( 1397, "", 4, 1 );
net.place[1397].number[1] = 10;
net.place[1397].number[2] = 16;
net.place[1397].number[3] = 3;

InitPlace( 1398, "", 4, 1 );
net.place[1398].number[1] = 10;
net.place[1398].number[2] = 16;
net.place[1398].number[3] = 5;

InitPlace( 1399, "", 4, 1 );
net.place[1399].number[1] = 10;
net.place[1399].number[2] = 16;
net.place[1399].number[3] = 6;

InitPlace( 1400, "", 4, 1 );
net.place[1400].number[1] = 10;
net.place[1400].number[2] = 16;
net.place[1400].number[3] = 7;

InitPlace( 1401, "", 3, 1 );
net.place[1401].number[1] = 10;
net.place[1401].number[2] = 17;

InitPlace( 1402, "Y7", 4, 0 );
net.place[1402].number[1] = 10;
net.place[1402].number[2] = 18;
net.place[1402].number[3] = 0;

InitPlace( 1403, "", 4, 0 );
net.place[1403].number[1] = 10;
net.place[1403].number[2] = 18;
net.place[1403].number[3] = 1;

InitPlace( 1404, "", 4, 0 );
net.place[1404].number[1] = 10;
net.place[1404].number[2] = 18;
net.place[1404].number[3] = 2;

InitPlace( 1405, "", 4, 0 );
net.place[1405].number[1] = 10;
net.place[1405].number[2] = 18;
net.place[1405].number[3] = 3;

InitPlace( 1406, "", 4, 0 );
net.place[1406].number[1] = 10;
net.place[1406].number[2] = 18;
net.place[1406].number[3] = 4;

InitPlace( 1407, "", 4, 0 );
net.place[1407].number[1] = 10;
net.place[1407].number[2] = 18;
net.place[1407].number[3] = 5;

InitPlace( 1408, "", 4, 0 );
net.place[1408].number[1] = 10;
net.place[1408].number[2] = 18;
net.place[1408].number[3] = 6;

InitPlace( 1409, "", 4, 0 );
net.place[1409].number[1] = 10;
net.place[1409].number[2] = 18;
net.place[1409].number[3] = 7;

InitPlace( 1410, "", 4, 0 );
net.place[1410].number[1] = 10;
net.place[1410].number[2] = 18;
net.place[1410].number[3] = 8;

InitPlace( 1411, "", 4, 1 );
net.place[1411].number[1] = 10;
net.place[1411].number[2] = 18;
net.place[1411].number[3] = 9;

InitPlace( 1412, "", 4, 0 );
net.place[1412].number[1] = 10;
net.place[1412].number[2] = 18;
net.place[1412].number[3] = 10;

InitPlace( 1413, "", 4, 1 );
net.place[1413].number[1] = 10;
net.place[1413].number[2] = 18;
net.place[1413].number[3] = 11;

InitPlace( 1414, "", 4, 1 );
net.place[1414].number[1] = 10;
net.place[1414].number[2] = 18;
net.place[1414].number[3] = 12;

InitPlace( 1415, "", 4, 1 );
net.place[1415].number[1] = 10;
net.place[1415].number[2] = 18;
net.place[1415].number[3] = 13;

InitPlace( 1416, "", 4, 1 );
net.place[1416].number[1] = 10;
net.place[1416].number[2] = 18;
net.place[1416].number[3] = 14;

InitPlace( 1417, "", 4, 1 );
net.place[1417].number[1] = 10;
net.place[1417].number[2] = 18;
net.place[1417].number[3] = 15;

InitPlace( 1418, "", 4, 1 );
net.place[1418].number[1] = 10;
net.place[1418].number[2] = 18;
net.place[1418].number[3] = 16;

InitPlace( 1419, "", 4, 1 );
net.place[1419].number[1] = 10;
net.place[1419].number[2] = 18;
net.place[1419].number[3] = 17;

InitPlace( 1420, "", 4, 1 );
net.place[1420].number[1] = 10;
net.place[1420].number[2] = 18;
net.place[1420].number[3] = 18;

InitPlace( 1421, "", 4, 1 );
net.place[1421].number[1] = 10;
net.place[1421].number[2] = 18;
net.place[1421].number[3] = 19;

InitPlace( 1422, "", 4, 1 );
net.place[1422].number[1] = 10;
net.place[1422].number[2] = 18;
net.place[1422].number[3] = 20;

InitPlace( 1423, "", 4, 1 );
net.place[1423].number[1] = 10;
net.place[1423].number[2] = 18;
net.place[1423].number[3] = 21;

InitPlace( 1424, "", 4, 0 );
net.place[1424].number[1] = 10;
net.place[1424].number[2] = 18;
net.place[1424].number[3] = 42;

InitPlace( 1425, "", 4, 0 );
net.place[1425].number[1] = 10;
net.place[1425].number[2] = 18;
net.place[1425].number[3] = 43;

InitPlace( 1426, "", 4, 0 );
net.place[1426].number[1] = 10;
net.place[1426].number[2] = 18;
net.place[1426].number[3] = 76;

InitPlace( 1427, "R6", 4, 0 );
net.place[1427].number[1] = 10;
net.place[1427].number[2] = 18;
net.place[1427].number[3] = 77;

InitPlace( 1428, "GG7", 4, 0 );
net.place[1428].number[1] = 10;
net.place[1428].number[2] = 18;
net.place[1428].number[3] = 78;

InitPlace( 1429, "GR6", 4, 0 );
net.place[1429].number[1] = 10;
net.place[1429].number[2] = 18;
net.place[1429].number[3] = 79;

InitPlace( 1430, "", 4, 0 );
net.place[1430].number[1] = 10;
net.place[1430].number[2] = 18;
net.place[1430].number[3] = 80;

InitPlace( 1431, "GG6", 4, 0 );
net.place[1431].number[1] = 10;
net.place[1431].number[2] = 18;
net.place[1431].number[3] = 83;

InitPlace( 1432, "GG5", 4, 0 );
net.place[1432].number[1] = 10;
net.place[1432].number[2] = 18;
net.place[1432].number[3] = 84;

InitPlace( 1433, "GR5", 4, 0 );
net.place[1433].number[1] = 10;
net.place[1433].number[2] = 18;
net.place[1433].number[3] = 90;

InitPlace( 1434, "GG4", 4, 0 );
net.place[1434].number[1] = 10;
net.place[1434].number[2] = 18;
net.place[1434].number[3] = 91;

InitPlace( 1435, "GR4", 4, 0 );
net.place[1435].number[1] = 10;
net.place[1435].number[2] = 18;
net.place[1435].number[3] = 92;

InitPlace( 1436, "GR3", 4, 0 );
net.place[1436].number[1] = 10;
net.place[1436].number[2] = 18;
net.place[1436].number[3] = 93;

InitPlace( 1437, "GG3", 4, 0 );
net.place[1437].number[1] = 10;
net.place[1437].number[2] = 18;
net.place[1437].number[3] = 94;

InitPlace( 1438, "GR2", 4, 0 );
net.place[1438].number[1] = 10;
net.place[1438].number[2] = 18;
net.place[1438].number[3] = 95;

InitPlace( 1439, "GG2", 4, 0 );
net.place[1439].number[1] = 10;
net.place[1439].number[2] = 18;
net.place[1439].number[3] = 96;

InitPlace( 1440, "GR1", 4, 0 );
net.place[1440].number[1] = 10;
net.place[1440].number[2] = 18;
net.place[1440].number[3] = 97;

InitPlace( 1441, "GG1", 4, 0 );
net.place[1441].number[1] = 10;
net.place[1441].number[2] = 18;
net.place[1441].number[3] = 98;

InitPlace( 1442, "GR0", 4, 1 );
net.place[1442].number[1] = 10;
net.place[1442].number[2] = 18;
net.place[1442].number[3] = 99;

InitPlace( 1443, "GG0", 4, 0 );
net.place[1443].number[1] = 10;
net.place[1443].number[2] = 18;
net.place[1443].number[3] = 100;

InitPlace( 1444, "", 4, 1 );
net.place[1444].number[1] = 10;
net.place[1444].number[2] = 18;
net.place[1444].number[3] = 101;

InitPlace( 1445, "", 4, 1 );
net.place[1445].number[1] = 10;
net.place[1445].number[2] = 18;
net.place[1445].number[3] = 102;

InitPlace( 1446, "RG0", 4, 0 );
net.place[1446].number[1] = 10;
net.place[1446].number[2] = 18;
net.place[1446].number[3] = 103;

InitPlace( 1447, "M0", 4, 0 );
net.place[1447].number[1] = 10;
net.place[1447].number[2] = 18;
net.place[1447].number[3] = 104;

InitPlace( 1448, "Y0", 4, 0 );
net.place[1448].number[1] = 10;
net.place[1448].number[2] = 18;
net.place[1448].number[3] = 105;

InitPlace( 1449, "", 4, 0 );
net.place[1449].number[1] = 10;
net.place[1449].number[2] = 18;
net.place[1449].number[3] = 106;

InitPlace( 1450, "G0", 4, 0 );
net.place[1450].number[1] = 10;
net.place[1450].number[2] = 18;
net.place[1450].number[3] = 107;

InitPlace( 1451, "", 4, 1 );
net.place[1451].number[1] = 10;
net.place[1451].number[2] = 18;
net.place[1451].number[3] = 108;

InitPlace( 1452, "RG1", 4, 0 );
net.place[1452].number[1] = 10;
net.place[1452].number[2] = 18;
net.place[1452].number[3] = 109;

InitPlace( 1453, "", 4, 1 );
net.place[1453].number[1] = 10;
net.place[1453].number[2] = 18;
net.place[1453].number[3] = 110;

InitPlace( 1454, "Y1", 4, 0 );
net.place[1454].number[1] = 10;
net.place[1454].number[2] = 18;
net.place[1454].number[3] = 111;

InitPlace( 1455, "", 4, 0 );
net.place[1455].number[1] = 10;
net.place[1455].number[2] = 18;
net.place[1455].number[3] = 112;

InitPlace( 1456, "M1", 4, 0 );
net.place[1456].number[1] = 10;
net.place[1456].number[2] = 18;
net.place[1456].number[3] = 113;

InitPlace( 1457, "G1", 4, 0 );
net.place[1457].number[1] = 10;
net.place[1457].number[2] = 18;
net.place[1457].number[3] = 114;

InitPlace( 1458, "Y2", 4, 0 );
net.place[1458].number[1] = 10;
net.place[1458].number[2] = 18;
net.place[1458].number[3] = 115;

InitPlace( 1459, "", 4, 0 );
net.place[1459].number[1] = 10;
net.place[1459].number[2] = 18;
net.place[1459].number[3] = 116;

InitPlace( 1460, "M2", 4, 0 );
net.place[1460].number[1] = 10;
net.place[1460].number[2] = 18;
net.place[1460].number[3] = 117;

InitPlace( 1461, "G2", 4, 0 );
net.place[1461].number[1] = 10;
net.place[1461].number[2] = 18;
net.place[1461].number[3] = 118;

InitPlace( 1462, "", 4, 1 );
net.place[1462].number[1] = 10;
net.place[1462].number[2] = 18;
net.place[1462].number[3] = 119;

InitPlace( 1463, "RG2", 4, 0 );
net.place[1463].number[1] = 10;
net.place[1463].number[2] = 18;
net.place[1463].number[3] = 120;

InitPlace( 1464, "", 4, 1 );
net.place[1464].number[1] = 10;
net.place[1464].number[2] = 18;
net.place[1464].number[3] = 121;

InitPlace( 1465, "RG3", 4, 0 );
net.place[1465].number[1] = 10;
net.place[1465].number[2] = 18;
net.place[1465].number[3] = 122;

InitPlace( 1466, "", 4, 1 );
net.place[1466].number[1] = 10;
net.place[1466].number[2] = 18;
net.place[1466].number[3] = 123;

InitPlace( 1467, "", 4, 1 );
net.place[1467].number[1] = 10;
net.place[1467].number[2] = 18;
net.place[1467].number[3] = 124;

InitPlace( 1468, "", 4, 0 );
net.place[1468].number[1] = 10;
net.place[1468].number[2] = 18;
net.place[1468].number[3] = 125;

InitPlace( 1469, "Y3", 4, 0 );
net.place[1469].number[1] = 10;
net.place[1469].number[2] = 18;
net.place[1469].number[3] = 126;

InitPlace( 1470, "G3", 4, 0 );
net.place[1470].number[1] = 10;
net.place[1470].number[2] = 18;
net.place[1470].number[3] = 127;

InitPlace( 1471, "M3", 4, 0 );
net.place[1471].number[1] = 10;
net.place[1471].number[2] = 18;
net.place[1471].number[3] = 128;

InitPlace( 1472, "RG4", 4, 0 );
net.place[1472].number[1] = 10;
net.place[1472].number[2] = 18;
net.place[1472].number[3] = 129;

InitPlace( 1473, "", 4, 0 );
net.place[1473].number[1] = 10;
net.place[1473].number[2] = 18;
net.place[1473].number[3] = 130;

InitPlace( 1474, "Y4", 4, 0 );
net.place[1474].number[1] = 10;
net.place[1474].number[2] = 18;
net.place[1474].number[3] = 131;

InitPlace( 1475, "G4", 4, 0 );
net.place[1475].number[1] = 10;
net.place[1475].number[2] = 18;
net.place[1475].number[3] = 132;

InitPlace( 1476, "M4", 4, 0 );
net.place[1476].number[1] = 10;
net.place[1476].number[2] = 18;
net.place[1476].number[3] = 133;

InitPlace( 1477, "", 4, 1 );
net.place[1477].number[1] = 10;
net.place[1477].number[2] = 18;
net.place[1477].number[3] = 134;

InitPlace( 1478, "", 4, 1 );
net.place[1478].number[1] = 10;
net.place[1478].number[2] = 18;
net.place[1478].number[3] = 135;

InitPlace( 1479, "", 4, 1 );
net.place[1479].number[1] = 10;
net.place[1479].number[2] = 18;
net.place[1479].number[3] = 136;

InitPlace( 1480, "Y5", 4, 0 );
net.place[1480].number[1] = 10;
net.place[1480].number[2] = 18;
net.place[1480].number[3] = 137;

InitPlace( 1481, "", 4, 0 );
net.place[1481].number[1] = 10;
net.place[1481].number[2] = 18;
net.place[1481].number[3] = 138;

InitPlace( 1482, "RG5", 4, 0 );
net.place[1482].number[1] = 10;
net.place[1482].number[2] = 18;
net.place[1482].number[3] = 139;

InitPlace( 1483, "", 4, 1 );
net.place[1483].number[1] = 10;
net.place[1483].number[2] = 18;
net.place[1483].number[3] = 140;

InitPlace( 1484, "G5", 4, 0 );
net.place[1484].number[1] = 10;
net.place[1484].number[2] = 18;
net.place[1484].number[3] = 141;

InitPlace( 1485, "M5", 4, 0 );
net.place[1485].number[1] = 10;
net.place[1485].number[2] = 18;
net.place[1485].number[3] = 142;

InitPlace( 1486, "", 4, 1 );
net.place[1486].number[1] = 10;
net.place[1486].number[2] = 18;
net.place[1486].number[3] = 143;

InitPlace( 1487, "Y6", 4, 0 );
net.place[1487].number[1] = 10;
net.place[1487].number[2] = 18;
net.place[1487].number[3] = 144;

InitPlace( 1488, "", 4, 0 );
net.place[1488].number[1] = 10;
net.place[1488].number[2] = 18;
net.place[1488].number[3] = 145;

InitPlace( 1489, "G6", 4, 0 );
net.place[1489].number[1] = 10;
net.place[1489].number[2] = 18;
net.place[1489].number[3] = 146;

InitPlace( 1490, "M6", 4, 0 );
net.place[1490].number[1] = 10;
net.place[1490].number[2] = 18;
net.place[1490].number[3] = 147;

InitPlace( 1491, "RG6", 4, 0 );
net.place[1491].number[1] = 10;
net.place[1491].number[2] = 18;
net.place[1491].number[3] = 148;

InitPlace( 1492, "", 4, 1 );
net.place[1492].number[1] = 10;
net.place[1492].number[2] = 18;
net.place[1492].number[3] = 149;

InitPlace( 1493, "", 4, 0 );
net.place[1493].number[1] = 10;
net.place[1493].number[2] = 18;
net.place[1493].number[3] = 151;

InitPlace( 1494, "GR7", 4, 0 );
net.place[1494].number[1] = 10;
net.place[1494].number[2] = 18;
net.place[1494].number[3] = 152;

InitPlace( 1495, "G7", 4, 0 );
net.place[1495].number[1] = 10;
net.place[1495].number[2] = 18;
net.place[1495].number[3] = 153;

InitPlace( 1496, "", 4, 1 );
net.place[1496].number[1] = 10;
net.place[1496].number[2] = 18;
net.place[1496].number[3] = 154;

InitPlace( 1497, "", 4, 1 );
net.place[1497].number[1] = 10;
net.place[1497].number[2] = 18;
net.place[1497].number[3] = 155;

InitPlace( 1498, "M7", 4, 0 );
net.place[1498].number[1] = 10;
net.place[1498].number[2] = 18;
net.place[1498].number[3] = 156;

InitPlace( 1499, "RG7", 4, 0 );
net.place[1499].number[1] = 10;
net.place[1499].number[2] = 18;
net.place[1499].number[3] = 157;

InitPlace( 1500, "R7", 4, 0 );
net.place[1500].number[1] = 10;
net.place[1500].number[2] = 18;
net.place[1500].number[3] = 162;

InitPlace( 1501, "R5", 4, 0 );
net.place[1501].number[1] = 10;
net.place[1501].number[2] = 18;
net.place[1501].number[3] = 163;

InitPlace( 1502, "R4", 4, 0 );
net.place[1502].number[1] = 10;
net.place[1502].number[2] = 18;
net.place[1502].number[3] = 164;

InitPlace( 1503, "R3", 4, 0 );
net.place[1503].number[1] = 10;
net.place[1503].number[2] = 18;
net.place[1503].number[3] = 165;

InitPlace( 1504, "R2", 4, 0 );
net.place[1504].number[1] = 10;
net.place[1504].number[2] = 18;
net.place[1504].number[3] = 166;

InitPlace( 1505, "R1", 4, 0 );
net.place[1505].number[1] = 10;
net.place[1505].number[2] = 18;
net.place[1505].number[3] = 167;

InitPlace( 1506, "R0", 4, 0 );
net.place[1506].number[1] = 10;
net.place[1506].number[2] = 18;
net.place[1506].number[3] = 168;

InitPlace( 1507, "", 4, 0 );
net.place[1507].number[1] = 10;
net.place[1507].number[2] = 18;
net.place[1507].number[3] = 170;

InitPlace( 1508, "", 4, 0 );
net.place[1508].number[1] = 10;
net.place[1508].number[2] = 18;
net.place[1508].number[3] = 288;

InitPlace( 1509, "", 4, 0 );
net.place[1509].number[1] = 10;
net.place[1509].number[2] = 18;
net.place[1509].number[3] = 309;

InitPlace( 1510, "", 4, 0 );
net.place[1510].number[1] = 10;
net.place[1510].number[2] = 18;
net.place[1510].number[3] = 318;

InitPlace( 1511, "", 4, 0 );
net.place[1511].number[1] = 10;
net.place[1511].number[2] = 18;
net.place[1511].number[3] = 335;

InitPlace( 1512, "", 4, 0 );
net.place[1512].number[1] = 10;
net.place[1512].number[2] = 18;
net.place[1512].number[3] = 360;

InitPlace( 1513, "", 4, 0 );
net.place[1513].number[1] = 10;
net.place[1513].number[2] = 18;
net.place[1513].number[3] = 377;

InitPlace( 1514, "", 4, 0 );
net.place[1514].number[1] = 10;
net.place[1514].number[2] = 18;
net.place[1514].number[3] = 394;

InitPlace( 1515, "", 4, 0 );
net.place[1515].number[1] = 10;
net.place[1515].number[2] = 18;
net.place[1515].number[3] = 427;

InitPlace( 1516, "", 4, 0 );
net.place[1516].number[1] = 10;
net.place[1516].number[2] = 18;
net.place[1516].number[3] = 428;

InitPlace( 1517, "", 4, 0 );
net.place[1517].number[1] = 10;
net.place[1517].number[2] = 18;
net.place[1517].number[3] = 449;

InitPlace( 1518, "", 4, 0 );
net.place[1518].number[1] = 10;
net.place[1518].number[2] = 18;
net.place[1518].number[3] = 457;

InitPlace( 1519, "", 4, 0 );
net.place[1519].number[1] = 10;
net.place[1519].number[2] = 18;
net.place[1519].number[3] = 481;

InitPlace( 1520, "", 4, 0 );
net.place[1520].number[1] = 10;
net.place[1520].number[2] = 18;
net.place[1520].number[3] = 500;

InitPlace( 1521, "", 4, 0 );
net.place[1521].number[1] = 10;
net.place[1521].number[2] = 18;
net.place[1521].number[3] = 533;

InitPlace( 1522, "", 4, 0 );
net.place[1522].number[1] = 10;
net.place[1522].number[2] = 18;
net.place[1522].number[3] = 534;

InitPlace( 1523, "", 4, 0 );
net.place[1523].number[1] = 10;
net.place[1523].number[2] = 18;
net.place[1523].number[3] = 551;

InitPlace( 1524, "", 4, 0 );
net.place[1524].number[1] = 10;
net.place[1524].number[2] = 18;
net.place[1524].number[3] = 584;

InitPlace( 1525, "", 4, 0 );
net.place[1525].number[1] = 10;
net.place[1525].number[2] = 18;
net.place[1525].number[3] = 585;

InitPlace( 1526, "", 4, 0 );
net.place[1526].number[1] = 10;
net.place[1526].number[2] = 18;
net.place[1526].number[3] = 634;

InitPlace( 1527, "", 4, 0 );
net.place[1527].number[1] = 10;
net.place[1527].number[2] = 18;
net.place[1527].number[3] = 635;

InitPlace( 1528, "", 4, 0 );
net.place[1528].number[1] = 10;
net.place[1528].number[2] = 18;
net.place[1528].number[3] = 636;

InitPlace( 1529, "", 4, 0 );
net.place[1529].number[1] = 10;
net.place[1529].number[2] = 18;
net.place[1529].number[3] = 669;

InitPlace( 1530, "", 4, 0 );
net.place[1530].number[1] = 10;
net.place[1530].number[2] = 18;
net.place[1530].number[3] = 670;

InitPlace( 1531, "", 4, 0 );
net.place[1531].number[1] = 10;
net.place[1531].number[2] = 18;
net.place[1531].number[3] = 707;

InitPlace( 1532, "", 4, 0 );
net.place[1532].number[1] = 10;
net.place[1532].number[2] = 18;
net.place[1532].number[3] = 732;

InitPlace( 1533, "", 4, 0 );
net.place[1533].number[1] = 10;
net.place[1533].number[2] = 18;
net.place[1533].number[3] = 749;

InitPlace( 1534, "", 4, 0 );
net.place[1534].number[1] = 10;
net.place[1534].number[2] = 18;
net.place[1534].number[3] = 758;

InitPlace( 1535, "", 4, 0 );
net.place[1535].number[1] = 10;
net.place[1535].number[2] = 18;
net.place[1535].number[3] = 799;

InitPlace( 1536, "", 4, 0 );
net.place[1536].number[1] = 10;
net.place[1536].number[2] = 18;
net.place[1536].number[3] = 808;

InitPlace( 1537, "", 4, 0 );
net.place[1537].number[1] = 10;
net.place[1537].number[2] = 18;
net.place[1537].number[3] = 809;

InitPlace( 1538, "", 4, 0 );
net.place[1538].number[1] = 10;
net.place[1538].number[2] = 18;
net.place[1538].number[3] = 834;

InitPlace( 1539, "", 4, 0 );
net.place[1539].number[1] = 10;
net.place[1539].number[2] = 18;
net.place[1539].number[3] = 843;

InitPlace( 1540, "", 4, 0 );
net.place[1540].number[1] = 10;
net.place[1540].number[2] = 18;
net.place[1540].number[3] = 860;

InitPlace( 1541, "", 4, 0 );
net.place[1541].number[1] = 10;
net.place[1541].number[2] = 18;
net.place[1541].number[3] = 885;

InitPlace( 1542, "", 4, 0 );
net.place[1542].number[1] = 10;
net.place[1542].number[2] = 18;
net.place[1542].number[3] = 918;

InitPlace( 1543, "", 4, 0 );
net.place[1543].number[1] = 10;
net.place[1543].number[2] = 18;
net.place[1543].number[3] = 927;

InitPlace( 1544, "", 4, 0 );
net.place[1544].number[1] = 10;
net.place[1544].number[2] = 18;
net.place[1544].number[3] = 936;

InitPlace( 1545, "", 4, 0 );
net.place[1545].number[1] = 10;
net.place[1545].number[2] = 18;
net.place[1545].number[3] = 945;

InitPlace( 1546, "", 4, 0 );
net.place[1546].number[1] = 10;
net.place[1546].number[2] = 18;
net.place[1546].number[3] = 986;

InitPlace( 1547, "", 4, 0 );
net.place[1547].number[1] = 10;
net.place[1547].number[2] = 18;
net.place[1547].number[3] = 987;

InitPlace( 1548, "", 4, 0 );
net.place[1548].number[1] = 10;
net.place[1548].number[2] = 18;
net.place[1548].number[3] = 996;

InitPlace( 1549, "", 4, 0 );
net.place[1549].number[1] = 10;
net.place[1549].number[2] = 18;
net.place[1549].number[3] = 1021;

InitPlace( 1550, "", 4, 0 );
net.place[1550].number[1] = 10;
net.place[1550].number[2] = 18;
net.place[1550].number[3] = 1030;

InitPlace( 1551, "", 4, 0 );
net.place[1551].number[1] = 10;
net.place[1551].number[2] = 18;
net.place[1551].number[3] = 1047;

InitPlace( 1552, "", 4, 0 );
net.place[1552].number[1] = 10;
net.place[1552].number[2] = 18;
net.place[1552].number[3] = 1064;

InitPlace( 1553, "", 4, 0 );
net.place[1553].number[1] = 10;
net.place[1553].number[2] = 18;
net.place[1553].number[3] = 1081;

InitPlace( 1554, "", 4, 0 );
net.place[1554].number[1] = 10;
net.place[1554].number[2] = 18;
net.place[1554].number[3] = 1098;

InitPlace( 1555, "", 4, 0 );
net.place[1555].number[1] = 10;
net.place[1555].number[2] = 18;
net.place[1555].number[3] = 1107;

InitPlace( 1556, "", 4, 0 );
net.place[1556].number[1] = 10;
net.place[1556].number[2] = 18;
net.place[1556].number[3] = 1132;

InitPlace( 1557, "", 4, 0 );
net.place[1557].number[1] = 10;
net.place[1557].number[2] = 18;
net.place[1557].number[3] = 1149;

InitPlace( 1558, "", 4, 0 );
net.place[1558].number[1] = 10;
net.place[1558].number[2] = 18;
net.place[1558].number[3] = 1166;

InitPlace( 1559, "", 3, 0 );
net.place[1559].number[1] = 10;
net.place[1559].number[2] = 19;

InitPlace( 1560, "", 3, 0 );
net.place[1560].number[1] = 10;
net.place[1560].number[2] = 20;

InitPlace( 1561, "", 3, 0 );
net.place[1561].number[1] = 10;
net.place[1561].number[2] = 21;

InitPlace( 1562, "", 3, 0 );
net.place[1562].number[1] = 10;
net.place[1562].number[2] = 22;

InitPlace( 1563, "", 3, 1 );
net.place[1563].number[1] = 10;
net.place[1563].number[2] = 23;

InitPlace( 1564, "", 3, 1 );
net.place[1564].number[1] = 10;
net.place[1564].number[2] = 24;

InitPlace( 1565, "", 3, 1 );
net.place[1565].number[1] = 10;
net.place[1565].number[2] = 169;

InitPlace( 1566, "", 3, 1 );
net.place[1566].number[1] = 10;
net.place[1566].number[2] = 172;

InitPlace( 1567, "", 3, 1 );
net.place[1567].number[1] = 10;
net.place[1567].number[2] = 175;

InitPlace( 1568, "", 3, 1 );
net.place[1568].number[1] = 10;
net.place[1568].number[2] = 177;

InitPlace( 1569, "", 3, 1 );
net.place[1569].number[1] = 10;
net.place[1569].number[2] = 179;

InitPlace( 1570, "", 3, 1 );
net.place[1570].number[1] = 10;
net.place[1570].number[2] = 180;

InitPlace( 1571, "", 3, 1 );
net.place[1571].number[1] = 10;
net.place[1571].number[2] = 181;

InitPlace( 1572, "", 3, 1 );
net.place[1572].number[1] = 10;
net.place[1572].number[2] = 182;

InitPlace( 1573, "", 3, 1 );
net.place[1573].number[1] = 10;
net.place[1573].number[2] = 183;

InitPlace( 1574, "", 3, 1 );
net.place[1574].number[1] = 10;
net.place[1574].number[2] = 184;

InitPlace( 1575, "", 3, 1 );
net.place[1575].number[1] = 10;
net.place[1575].number[2] = 185;

InitPlace( 1576, "", 3, 1 );
net.place[1576].number[1] = 10;
net.place[1576].number[2] = 186;

InitPlace( 1577, "", 3, 1 );
net.place[1577].number[1] = 10;
net.place[1577].number[2] = 187;

InitPlace( 1578, "", 3, 1 );
net.place[1578].number[1] = 10;
net.place[1578].number[2] = 188;

InitPlace( 1579, "", 3, 1 );
net.place[1579].number[1] = 10;
net.place[1579].number[2] = 189;

InitPlace( 1580, "", 3, 1 );
net.place[1580].number[1] = 10;
net.place[1580].number[2] = 190;

InitPlace( 1581, "", 3, 1 );
net.place[1581].number[1] = 10;
net.place[1581].number[2] = 193;

InitPlace( 1582, "", 3, 0 );
net.place[1582].number[1] = 10;
net.place[1582].number[2] = 197;

InitPlace( 1583, "", 3, 1 );
net.place[1583].number[1] = 10;
net.place[1583].number[2] = 198;

InitPlace( 1584, "", 3, 1 );
net.place[1584].number[1] = 10;
net.place[1584].number[2] = 199;

InitPlace( 1585, "", 3, 1 );
net.place[1585].number[1] = 10;
net.place[1585].number[2] = 200;

InitPlace( 1586, "", 3, 1 );
net.place[1586].number[1] = 10;
net.place[1586].number[2] = 209;

InitPlace( 1587, "", 3, 1 );
net.place[1587].number[1] = 10;
net.place[1587].number[2] = 210;

InitPlace( 1588, "", 3, 1 );
net.place[1588].number[1] = 10;
net.place[1588].number[2] = 211;

InitPlace( 1589, "", 3, 1 );
net.place[1589].number[1] = 10;
net.place[1589].number[2] = 212;

InitPlace( 1590, "", 3, 1 );
net.place[1590].number[1] = 10;
net.place[1590].number[2] = 213;

InitPlace( 1591, "", 3, 1 );
net.place[1591].number[1] = 10;
net.place[1591].number[2] = 214;

InitPlace( 1592, "", 3, 1 );
net.place[1592].number[1] = 10;
net.place[1592].number[2] = 217;

InitPlace( 1593, "", 3, 1 );
net.place[1593].number[1] = 10;
net.place[1593].number[2] = 218;

InitPlace( 1594, "", 3, 1 );
net.place[1594].number[1] = 10;
net.place[1594].number[2] = 221;

InitPlace( 1595, "", 3, 1 );
net.place[1595].number[1] = 10;
net.place[1595].number[2] = 229;

InitPlace( 1596, "", 3, 1 );
net.place[1596].number[1] = 10;
net.place[1596].number[2] = 232;

InitPlace( 1597, "", 3, 1 );
net.place[1597].number[1] = 10;
net.place[1597].number[2] = 233;

InitPlace( 1598, "", 3, 1 );
net.place[1598].number[1] = 10;
net.place[1598].number[2] = 234;

InitPlace( 1599, "", 3, 1 );
net.place[1599].number[1] = 10;
net.place[1599].number[2] = 237;

InitPlace( 1600, "", 3, 1 );
net.place[1600].number[1] = 10;
net.place[1600].number[2] = 238;

InitPlace( 1601, "", 3, 1 );
net.place[1601].number[1] = 10;
net.place[1601].number[2] = 239;

InitPlace( 1602, "", 3, 1 );
net.place[1602].number[1] = 10;
net.place[1602].number[2] = 242;

InitPlace( 1603, "", 3, 1 );
net.place[1603].number[1] = 10;
net.place[1603].number[2] = 252;

InitPlace( 1604, "", 3, 1 );
net.place[1604].number[1] = 10;
net.place[1604].number[2] = 253;

InitPlace( 1605, "", 3, 1 );
net.place[1605].number[1] = 10;
net.place[1605].number[2] = 254;

InitPlace( 1606, "", 3, 1 );
net.place[1606].number[1] = 10;
net.place[1606].number[2] = 255;

InitPlace( 1607, "", 2, 1 );
net.place[1607].number[1] = 11;

InitPlace( 1608, "", 2, 1 );
net.place[1608].number[1] = 12;

InitPlace( 1609, "", 2, 1 );
net.place[1609].number[1] = 13;

InitPlace( 1610, "", 2, 1 );
net.place[1610].number[1] = 14;

InitPlace( 1611, "", 2, 1 );
net.place[1611].number[1] = 15;

InitPlace( 1612, "", 2, 1 );
net.place[1612].number[1] = 16;

InitPlace( 1613, "", 2, 1 );
net.place[1613].number[1] = 17;

InitPlace( 1614, "", 2, 1 );
net.place[1614].number[1] = 18;

InitPlace( 1615, "", 2, 1 );
net.place[1615].number[1] = 19;

InitPlace( 1616, "", 2, 1 );
net.place[1616].number[1] = 20;

InitPlace( 1617, "", 2, 1 );
net.place[1617].number[1] = 21;

InitPlace( 1618, "", 2, 1 );
net.place[1618].number[1] = 22;

InitPlace( 1619, "", 2, 0 );
net.place[1619].number[1] = 23;

InitPlace( 1620, "", 2, 0 );
net.place[1620].number[1] = 24;

InitPlace( 1621, "", 2, 0 );
net.place[1621].number[1] = 25;

InitPlace( 1622, "", 2, 0 );
net.place[1622].number[1] = 26;

InitPlace( 1623, "", 2, 0 );
net.place[1623].number[1] = 27;

InitPlace( 1624, "", 3, 1 );
net.place[1624].number[1] = -1;
net.place[1624].number[2] = 0;

InitPlace( 1625, "", 3, 1 );
net.place[1625].number[1] = -1;
net.place[1625].number[2] = 1;

InitPlace( 1626, "", 3, 1 );
net.place[1626].number[1] = -1;
net.place[1626].number[2] = 2;

InitPlace( 1627, "", 3, 1 );
net.place[1627].number[1] = -1;
net.place[1627].number[2] = 3;

InitPlace( 1628, "", 3, 1 );
net.place[1628].number[1] = -1;
net.place[1628].number[2] = 4;

InitPlace( 1629, "", 4, 1 );
net.place[1629].number[1] = -1;
net.place[1629].number[2] = 6;
net.place[1629].number[3] = 0;

InitPlace( 1630, "", 4, 1 );
net.place[1630].number[1] = -1;
net.place[1630].number[2] = 6;
net.place[1630].number[3] = 1;

InitPlace( 1631, "", 4, 1 );
net.place[1631].number[1] = -1;
net.place[1631].number[2] = 6;
net.place[1631].number[3] = 2;

InitPlace( 1632, "", 4, 1 );
net.place[1632].number[1] = -1;
net.place[1632].number[2] = 6;
net.place[1632].number[3] = 3;

InitPlace( 1633, "", 4, 1 );
net.place[1633].number[1] = -1;
net.place[1633].number[2] = 6;
net.place[1633].number[3] = 4;

InitPlace( 1634, "", 4, 1 );
net.place[1634].number[1] = -1;
net.place[1634].number[2] = 6;
net.place[1634].number[3] = 5;

InitPlace( 1635, "", 4, 1 );
net.place[1635].number[1] = -1;
net.place[1635].number[2] = 6;
net.place[1635].number[3] = 6;

InitPlace( 1636, "", 4, 1 );
net.place[1636].number[1] = -1;
net.place[1636].number[2] = 6;
net.place[1636].number[3] = 7;

InitPlace( 1637, "", 4, 1 );
net.place[1637].number[1] = -1;
net.place[1637].number[2] = 6;
net.place[1637].number[3] = 8;

InitPlace( 1638, "", 4, 1 );
net.place[1638].number[1] = -1;
net.place[1638].number[2] = 6;
net.place[1638].number[3] = 10;

InitPlace( 1639, "", 3, 1 );
net.place[1639].number[1] = -2;
net.place[1639].number[2] = 0;

InitPlace( 1640, "", 3, 1 );
net.place[1640].number[1] = -2;
net.place[1640].number[2] = 1;

InitPlace( 1641, "", 3, 1 );
net.place[1641].number[1] = -2;
net.place[1641].number[2] = 2;

InitPlace( 1642, "", 3, 1 );
net.place[1642].number[1] = -2;
net.place[1642].number[2] = 3;

InitPlace( 1643, "", 3, 1 );
net.place[1643].number[1] = -2;
net.place[1643].number[2] = 4;

InitPlace( 1644, "", 4, 1 );
net.place[1644].number[1] = -2;
net.place[1644].number[2] = 6;
net.place[1644].number[3] = 0;

InitPlace( 1645, "", 4, 1 );
net.place[1645].number[1] = -2;
net.place[1645].number[2] = 6;
net.place[1645].number[3] = 1;

InitPlace( 1646, "", 4, 1 );
net.place[1646].number[1] = -2;
net.place[1646].number[2] = 6;
net.place[1646].number[3] = 2;

InitPlace( 1647, "", 4, 1 );
net.place[1647].number[1] = -2;
net.place[1647].number[2] = 6;
net.place[1647].number[3] = 3;

InitPlace( 1648, "", 4, 1 );
net.place[1648].number[1] = -2;
net.place[1648].number[2] = 6;
net.place[1648].number[3] = 4;

InitPlace( 1649, "", 4, 1 );
net.place[1649].number[1] = -2;
net.place[1649].number[2] = 6;
net.place[1649].number[3] = 5;

InitPlace( 1650, "", 4, 1 );
net.place[1650].number[1] = -2;
net.place[1650].number[2] = 6;
net.place[1650].number[3] = 6;

InitPlace( 1651, "", 4, 1 );
net.place[1651].number[1] = -2;
net.place[1651].number[2] = 6;
net.place[1651].number[3] = 7;

InitPlace( 1652, "", 4, 1 );
net.place[1652].number[1] = -2;
net.place[1652].number[2] = 6;
net.place[1652].number[3] = 8;

InitPlace( 1653, "", 4, 1 );
net.place[1653].number[1] = -2;
net.place[1653].number[2] = 6;
net.place[1653].number[3] = 10;

InitPlace( 1654, "", 3, 1 );
net.place[1654].number[1] = -7;
net.place[1654].number[2] = 0;

InitPlace( 1655, "", 3, 1 );
net.place[1655].number[1] = -7;
net.place[1655].number[2] = 1;

InitPlace( 1656, "", 3, 1 );
net.place[1656].number[1] = -7;
net.place[1656].number[2] = 2;

InitPlace( 1657, "", 3, 1 );
net.place[1657].number[1] = -7;
net.place[1657].number[2] = 3;

InitPlace( 1658, "", 3, 1 );
net.place[1658].number[1] = -7;
net.place[1658].number[2] = 4;

InitPlace( 1659, "", 4, 1 );
net.place[1659].number[1] = -7;
net.place[1659].number[2] = 6;
net.place[1659].number[3] = 0;

InitPlace( 1660, "", 4, 1 );
net.place[1660].number[1] = -7;
net.place[1660].number[2] = 6;
net.place[1660].number[3] = 1;

InitPlace( 1661, "", 4, 1 );
net.place[1661].number[1] = -7;
net.place[1661].number[2] = 6;
net.place[1661].number[3] = 2;

InitPlace( 1662, "", 4, 1 );
net.place[1662].number[1] = -7;
net.place[1662].number[2] = 6;
net.place[1662].number[3] = 3;

InitPlace( 1663, "", 4, 1 );
net.place[1663].number[1] = -7;
net.place[1663].number[2] = 6;
net.place[1663].number[3] = 4;

InitPlace( 1664, "", 4, 1 );
net.place[1664].number[1] = -7;
net.place[1664].number[2] = 6;
net.place[1664].number[3] = 5;

InitPlace( 1665, "", 4, 1 );
net.place[1665].number[1] = -7;
net.place[1665].number[2] = 6;
net.place[1665].number[3] = 6;

InitPlace( 1666, "", 4, 1 );
net.place[1666].number[1] = -7;
net.place[1666].number[2] = 6;
net.place[1666].number[3] = 7;

InitPlace( 1667, "", 4, 1 );
net.place[1667].number[1] = -7;
net.place[1667].number[2] = 6;
net.place[1667].number[3] = 8;

InitPlace( 1668, "", 4, 1 );
net.place[1668].number[1] = -7;
net.place[1668].number[2] = 6;
net.place[1668].number[3] = 10;

InitPlace( 1669, "", 4, 1 );
net.place[1669].number[1] = -7;
net.place[1669].number[2] = 6;
net.place[1669].number[3] = 11;

InitPlace( 1670, "", 4, 1 );
net.place[1670].number[1] = -7;
net.place[1670].number[2] = 6;
net.place[1670].number[3] = 12;

InitPlace( 1671, "", 4, 1 );
net.place[1671].number[1] = -7;
net.place[1671].number[2] = 6;
net.place[1671].number[3] = 13;

InitPlace( 1672, "", 4, 1 );
net.place[1672].number[1] = -7;
net.place[1672].number[2] = 6;
net.place[1672].number[3] = 14;

InitPlace( 1673, "", 3, 1 );
net.place[1673].number[1] = -8;
net.place[1673].number[2] = 0;

InitPlace( 1674, "", 3, 1 );
net.place[1674].number[1] = -8;
net.place[1674].number[2] = 1;

InitPlace( 1675, "", 3, 1 );
net.place[1675].number[1] = -8;
net.place[1675].number[2] = 2;

InitPlace( 1676, "", 3, 1 );
net.place[1676].number[1] = -8;
net.place[1676].number[2] = 3;

InitPlace( 1677, "", 3, 1 );
net.place[1677].number[1] = -8;
net.place[1677].number[2] = 4;

InitPlace( 1678, "", 4, 1 );
net.place[1678].number[1] = -8;
net.place[1678].number[2] = 6;
net.place[1678].number[3] = 0;

InitPlace( 1679, "", 4, 1 );
net.place[1679].number[1] = -8;
net.place[1679].number[2] = 6;
net.place[1679].number[3] = 1;

InitPlace( 1680, "", 4, 1 );
net.place[1680].number[1] = -8;
net.place[1680].number[2] = 6;
net.place[1680].number[3] = 2;


DefineNet4();
}
#endif /* SEGMENTED_MEMORY */
#endif /* CONST_NET */
