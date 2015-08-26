ACM-ICPC
========



之前把题目的类型和思路放commit里，发现提交不方便，索性放README里。
一半题目的解题思路都已经总结出来了，剩下(init)的以后补上



##BZOJ



#####1036_树的统计Count

树链剖分,点权,基础题







##Codeforces



#####525A_VitaliyandPie

模拟，统计



#####525B_PashaandString

乱搞



#####525C_IIyaandSticks

greed,two-pointer



#####134C_Swaps

YY,优先队列贪心,大的先换



#####14A_Letter

模拟乱搞



#####15C_IndustrialNim

Nim博弈,[0,x]异或



#####182E_WoodenFence

dp,计数



#####19D_Points

线段树,分治



#####204A_LittleElephantandInterval

乱搞，分类讨论，计数



#####230C_Shifts

枚举,二分,乱搞



#####239B_EasyTapeProgramming

模拟,水



#####245E_MishapinClub

乱搞,max-min



#####25D_RoadsnotonlyinBerland

tree,构造,水



#####327C_MagicFive

计数,等比数列求和



#####327D_BlockTower

bfs逆序，贪心，联通块



#####330C_Purification

YY乱搞,按行/列铺



#####332C_StudentsRevenge

贪心,sort



#####359D_PairofNumbers

gcd,线段树,二分



#####35D_Animals

greed,sort



#####384C_Milkingcows

贪心,首先考察任意两头牛的情况



#####4C_Registrationsystem

map



#####520A_Pangram

水,乱搞



#####520B_TwoButtons

bfs,水



#####526A_KingofThieves

枚举



#####526B_OmNomandDarkPark

二叉树,分治乱搞



#####526C_OmNomandCandies

贪心枚举乱搞,两边扫



#####85C_PetyaandTree

树形dp,分治



#####8C_LookingforOrder

状压dp,记忆化,顺序无关







##HDU



#####1181_变形课

floyd,水



#####1233_还是畅通工程

MST



#####1254_推箱子

bfs+dfs



#####1272_小希的迷宫

judge a tree 并查集



#####3123_GCC

大数,找规律,小心模



#####3336_Countthestring

KMP,计数,dp



#####4509_湫湫系列故事减肥记II

乱搞,水



#####4911_Inversion

逆序数



#####5166_Missingnumber

sort,枚举



#####5167_Fibonacci

红黑树,枚举,筛



#####5178_pairs

sort,单调



#####5179_beautifulnumber

dfs枚举



#####1024_MaxSumPlusPlus

dp



#####1025_ConstructingRoadsInJGShiningsKingdom

LIS



#####1030_Delta-wave

14-15年周赛5(2014-12-28),乱搞



#####1058_HumbleNumbers

init



#####1069_MonkeyandBanana

init



#####1078_FatMouseandCheese

dp,记忆化搜索



#####1081_ToTheMax

dp,降维,最大连续子段和,水



#####1128_SelfNumbers

打表



#####1158_EmploymentPlanning

dp[i][j]表示第i天剩j人的最小花费



#####1196_LowestBit

14-15年周赛5(2014-12-28)



#####1222_WolfandRabbit

14-15年周赛5(2014-12-28)



#####1237

表达式求值，栈



#####1257_最少拦截系统

14-15年周赛5(2014-12-28)



#####1269_迷宫城堡

14-15年周赛5(2014-12-28)



#####1284_钱币兑换问题

14-15年周赛5(2014-12-28)



#####1573_X问题

中国剩余定理,不互质



#####1702_ACboyneedsyourhelpagain

模拟乱搞,queue,stack



#####1711_NumberSequence

KMP



#####1789_DoingHomeworkagain

init



#####1829_ABugsLife

种类并查集



#####1978_Howmantways

init



#####2066_一个人的旅行

dijkstra,水



#####2087_剪花布条

KMP



#####2089_不要62

数位dp



#####2196_Computer

树的直径



#####2222_KeywordsSearch

AC自动机



#####2448_MiningStationontheSea

14-15年周赛5(2014-12-28),费用流



#####2452_Navymaneuvers

DAG动态规划



#####2577_HowtoType

init



#####2594_SimpsonsHiddenTalents

KMP



#####2609_Howmany

字符串,最小表示法,状压



#####2830_MatrixSwappingII

init



#####2845_Beans

init



#####2870_LargestSubmatrix

init



#####2896_病毒侵袭

AC自动机



#####3065_病毒侵袭持续中

AC自动机



#####3125_Slash

模拟,水



#####3181

init



#####3333_TuringTree

init



#####3374_StringProblem

KMP,最小表示法



#####3411_SnailAlice

数列递推公式,矩阵快速幂



#####3555_Bomb

数位dp



#####3579_HelloKiKi

中国剩余定理,模数不互质,合并方程组两两求解



#####3652_Bnumber

数位dp



#####3696_FarmGame

DAG,dp/topo



#####3709_BalancedNumber

数位dp



#####3714_ErrorCurves

三分



#####3746_CyclicNacklace

KMP



#####3854_GloriousArray

脑洞,小于k的为单元集,每个元素都不能和同一集合的元素成pair,维护即可


#####3872_Dargon Ball

DP+单调栈+线段树。dp[i]表示前i个球分好组的最小花费，显然此时i是右端点，若前一个和i同类型的位置为le[i],le[i] <= j < i,
dp[i]=min{dp[j]+max{ek|j < k <=i}},但这样的复杂度是O(n^2)，不妨考虑ek，若ek..ei中ek是最大的，那么显然ek就是后面这段的花费，
若ek前面第一个比他大的位置为j,则有dp[i]=min{min{dp|\[ j , k \) } + ek },所以用单调栈维护降序的e，在栈中去枚举，虽然负责度还是O(n^2),但基本达不到上界。


#####3874_Necklace

init



#####3972-2

init



#####3972

init



#####3976_Electricresistance

基尔霍夫第一定律,高斯消元



#####3994_MissionImpossible

floyd概率dp



#####4006_Thekthgreatnumber

红黑树,stl



#####4009_Transferwater

init



#####4027_Canyouanswerthesequeries

init



#####4057_RescuetheRabbit

init



#####4081_QinShiHuangsNationalRoadSystem

次小生成树



#####4193_Non-negativePartialSums

单调队列



#####4268_AliceandBob

init



#####4324_TriangleLOVE

init



#####4404_Worms

init



#####4411_Arrest

init



#####4415_AssassinsCreed

init



#####4419_ColourfulRectangle

init



#####4445_CrazyTank

init



#####4734_Fx

数位dp



#####4749_ParadeShow

KMP,前缀和维护前面有多少等级相同和等级小的,HDU数据SB,明显WA的code也能AC



#####4786_FibonacciTree

生成树,乱搞



#####4841

init



#####4915_Parenthese

sequence init



#####4918_Queryonthesubtree

点分治,树状数组维护点到分治中心的距离,注意去重



#####4948_Kingdom

init



#####4960_AnotherOCDPatient

init



#####4966_GGSDDU

init



#####4969_JustaJoke

init



#####4970_KillingMonsters

init



#####4971_Asimplebruteforceproblem

init



#####4973_Asimplesimulationproblem

init



#####4975_AsimpleGaussianeliminationproblem

init



#####5023_ACorruptMayorsPerformanceArt

init



#####5031_Lines

init



#####5033_Building

init



#####5071_Chat

init



#####5086_RevengeofSegmentTree

init



#####5091_BeamCannon

init



#####5098_SmartSoftwareInstaller

DAG动态规划,最长路,SPFA/topo



#####5124_line

init



#####5130_SignalInterference

init



#####5137_HowManyMaosDoestheGuanxiWorth

最短路,水



#####5150_SumSumSum

HDU 5150



#####5183_NegativeandPositiveNP

set,前缀和



#####5191_BuildingBlocks

前后补0，区间乱搞，前缀和



#####5192_BuildingBlocksII

Segment-Tree，前后加0，aver,aver+1,加挂加优化



#####5198_StrangeClass

模拟乱搞，注意细节



#####5199_Gunner

离线乱搞



#####5200_Trees

离线并查集，逆向思维



#####5222_Exploration

混合图找环,并查集无向边缩点,有向边用topo找环



#####5288_OOsSequence

筛法,找规律,计数



#####5289_Assignment

二分,ST表O(1)查询区间最值



#####5294_TricksDevice

最短路+最小割



#####1520_Anniversaryparty

init



#####3255_Farming

init



#####WirelessPassword

init







##LA(UVa

Live)



#####2191_Potentiometers

init



#####3661_AnimalRun

init



#####6281_ExactMeasurement

init



#####6459_InfiniteGo

init



#####6485_2

init



#####6485_ElectricCarRally

init



#####6487_StarSimulations

init



#####6622_AbsurdistanRoads

init



#####6623_BattleforSilver

init



#####6663_CounttheRegions

init







##POJ



#####2299_Ultra-QuickSort

merge,逆序数,bug fixed



#####2352_Stars

离线BIT



#####2456_Aggressivecows

二分



#####3450_CorporateIdentity

二分长度,字符串乱搞



#####1001_Exponentiation

init



#####1006_Biorhythms

中国剩余定理



#####1028_WebNavigation

模拟,水



#####1094_SortingItAllOut

toposort



#####1095_TreesMadetoOrder

卡特兰数,分治



#####1099_SquareIce

模拟,图形打印,较复杂



#####1105_S-Trees

二叉树



#####1128_FrameStacking

init



#####1135_DominoEffect

init



#####1155_TELE

树形dp,分组背包



#####1166_TheClocks

高斯消元,模线性方程,扩展欧几里得



#####1182

init



#####1192_最优连通子集

init



#####1222_EXTENDEDLIGHTSOUT

开关问题,高斯消元



#####1236_NetworkofSchools

init



#####1258_Agri-Net

init



#####1465_Multiple

init



#####1487_SinglePlayerGames

正规文法,树,递归,高斯消元,简单期望



#####1625_Censored

init



#####1655_BalancingAct

树分治



#####1741_Tree

男人八题之经典树(点)分治



#####1741_Tree_again

点分治



#####1847_Tram

最短路



#####1947_RebuildingRoads

树形dp,dp[i][j]表示以i为根的子树剩j个点(一定含i)要切多少条边



#####2031_BuildingaSpaceStation

init



#####2065_SETI

高斯消元,模线性方程,扩展欧几里得



#####2152_Fire

树形dp,2006年陈启峰国家集训队论文



#####2185_MilkingGrid

init



#####2186_PopularCows

init



#####2236_WirelessNetwork

并查集



#####2259_TeamQueue

队列嵌套,模拟乱搞



#####2342_Anniversaryparty

树形dp



#####2367_Genealogicaltree

toposort



#####2406_PowerStrings

KMP



#####2421_ConstructingRoads

init



#####2482_StarsinYourWindow

init



#####2486_AppleTree

树形dp,分组背包,dp[i][j][0]i子树走j步不回到i,dp[i][j][1]要回到i



#####2559_LargestRectangleinaHistogram

dp,左右跳,乱搞



#####2585_WindowPains

init



#####2676

init



#####2694_ASimplePokerGame

模拟,中档水题



#####2696_AMysteriousFunction

记忆化,水



#####2750_IdiomaticPhrasesGame

init



#####2752_SeektheNameSeektheFame

KMP



#####2762_Goingfromutovorfromvtou

init



#####2763_HousewifeWind

树链剖分,模板题



#####2793_Cactus

仙人掌度,点双联通,高精度



#####2796_FeelGood

离线并查集



#####2947_WidgetFactory

高斯消元,模线性方程,无解,多解,唯一解



#####2987_Firing

init



#####3026_BorgMaze

init



#####3080_BlueJeans

字符串,枚举



#####3107_Godfather

树的重心,分治



#####3159_Candies

init



#####3162_WalkingRace

树的直径,单调队列求最长连续区间最值差不超过k,经典题



#####3167_CowPatterns

KMP,前缀和维护前面有多少等级相同和等级小的,HDU数据SB,明显WA的code也能AC



#####3169_Layout

init



#####3180_TheCowProm

init



#####3237_Tree

树链剖分+线段树lazy



#####3252_RoundNumbers

数位dp



#####3258_RiverHopscotch

二分



#####3259_Wormholes

init



#####3342_PartyatHaliBula

树形dp



#####3345_BribingFIPA

树形dp,分组背包



#####3461_Oulipo

KMP



#####3532_Resistance

基尔霍夫第一定律,高斯消元,注意判断是否联通



#####3678_KatuPuzzle

init



#####3687_LabelingBalls

init



#####3691_DNArepair

init



#####3784_RunningMedian

蒟蒻只会线段树+二分



#####3835_Columbussbargin

最短路,坑



#####3897_MazeStretching

二分,A*,卡精度貌似



#####1122_FDNYtotheRescue

init







##SGU



#####134_Centroid

dfs,树的重心,树分治基础







##SPOJ



#####1022_AngelsandDevils

init



#####1043_CanyouanswerthesequeriesI

init



#####11772_NegativeScore

init



#####11840_SumofSquareswithSegmentTree

init



#####14932_LowestCommonAncestor

init



#####1693_Coconuts

init



#####1716_CanyouanswerthesequeriesIII

init



#####1716_CanyouanswerthesequeriesIII_again

init



#####203_Potholers

init



#####2_PrimeGenerator

init



#####32_ANeddleintheHaystack

init



#####3868_TotalFlow

init



#####4033_PhoneList

init



#####7212_FindStringRoots

init



#####962_IntergalacticMap

init



#####GONE

数位dp



#####HIGH

生成树计数,基尔霍夫矩阵,高斯消元,行列式



#####LUCIFER

数位dp



#####NUMTSN

数位dp



#####PERIOD

KMP



#####QTREE

树链剖分,单点修改,RMQ,入门题



#####RAONE

数位dp







##URAL



#####1108_Heritage

数学,YY



#####1385_InterestingNumber

数论，打表找规律



#####1762_SearchforaHidingPlace

手动模拟找规律







##UVa



#####1025

dp[i][j]-i分钟在j站一共的等车时间



#####111

dp,lis/lcs



#####1347

dp,记忆化搜索,dp[i][j]表示分别走到i,j时还要走的路程



#####1591

枚举,考察deltaQ



#####207

模拟，题目上的输入数据样例格式是有问题的，多一个空格，这题不卡精度，要注意发钱的情况



#####437

dp,DAG最长路



#####679

二叉树,找规律



#####815

乱搞



#####10004

init



#####1001

易证圆外一点到圆的最短路线是沿着圆心连线,floyd乱搞



#####10010

模拟乱搞



#####10014

init



#####10025

init



#####10026

init



#####10034

init



#####10047

init



#####10048

floyd



#####10050

init



#####10054

init



#####10057

init



#####10061

init



#####10082

乱搞



#####10098

UVa 10098



#####10099

init



#####101

模拟乱搞



#####10106

init



#####10110

init



#####10112

init



#####10115

init



#####10129

init



#####10132

init



#####10152

init



#####10158

init



#####10161

init



#####10167

init



#####10177

init



#####10194

init



#####10250

init



#####10269

init



#####10273

init



#####10298_PowerStrings

KMP



#####10300

init



#####10305

init



#####10307

init



#####10330

init



#####10340

乱搞



#####10341

init



#####10361

init



#####10369

init



#####10387

init



#####10392

init



#####10397

init



#####104

init



#####10420

init



#####10449

init



#####10474

二分



#####10487

init



#####10494

init



#####10499

init



#####10557

init



#####10562

init



#####10594

init



#####10596

init



#####10608

init



#####10679

init



#####107

init



#####10700

init



#####10706

init



#####10719

init



#####10735

Network Flow 混合图的欧拉回路 无向边任意定向，出入度判断是否可行，去掉有向边，增加源汇，入>出，连汇，否则连源，满流可行



#####10746

init



#####10763

init



#####10785

init



#####10790

init



#####10801

最短路



#####10803

init



#####10806

init



#####10815

sort



#####10878

init



#####10879

init



#####10905

init



#####10916

init



#####10970

init



#####10985

init



#####10986

init



#####1103

dfs找联通块,加边界



#####11038

数位dp



#####11044

init



#####11045

init



#####11082

最小割



#####11111

init



#####112

init



#####11205

init



#####11234

init



#####11297

init



#####113

init



#####11419

init



#####11488

init



#####1151

dfs枚举+kruskal



#####11809

数学，乱搞，对数



#####11988

list



#####120

init



#####12096

STL,set



#####12108

模拟



#####12186_AnotherCrisis

树形dp



#####1218_PerfectService

树形dp



#####122

二叉树,bfs



#####1220_PartyatHaliBula

树形dp



#####12219

表达式树化简，map判重，用sscanf+正则tle



#####1225

乱搞



#####12264

network flow,题意略坑，某个army移动过后不能再移动，二分答案，每个点拆成左右两部分，源连左，右连汇，边界点到汇容量为mid…



#####123

init



#####1232

init



#####124

init



#####12412

模拟乱搞，要仔细



#####125

init



#####12549

行列消除，如果没有障碍物，显然是二分图最小点覆盖；遇到障碍物移到新的行列即可,建图是一样的



#####12657

双向链表，模拟



#####12661

最短路



#####127

init



#####131

UVa 131



#####1328_Period

KMP



#####133

模拟乱搞



#####1339

sort统计乱搞



#####1349

MCMF,二分图,每一个点属于一个有向圈->每一个点有唯一后继



#####136

红黑树,乱搞



#####1368

字符串模拟



#####1380_ASchedulingProblem

树形dp,好难,f[i]表示从孩子到i的最长链,g[i]表示从i出发的最长链,对无向边定向,s.t.最长链尽量短



#####1395

kruskal



#####146

UVa 146



#####1515

network flow,S-草，洞-T



#####152

init



#####156

stl,sort,map,vector



#####1572

topo找环,A+ & B+ 在同一个块中连(A-,B+)&(B-,A+)



#####1583

乱搞



#####1584

乱搞



#####1585

乱搞



#####1586

乱搞



#####1587

乱搞



#####1588

匹配，乱搞



#####1589

模拟



#####1590

位运算，模拟



#####1592

枚举,红黑树,hash



#####1599

spfa,bfs,字典序,画出结构层次



#####1658

两条没有公共点的路径,费用流,拆点



#####1660

拆点，枚举源汇，最小割，边容量inf



#####1663

最大独立集，编码差1的建边，V-FLOW/2



#####1664

并查集，按权从大到小排，merge时看收益，注意long long



#####1665

并查集，离线，输出格式-每个数后加空格



#####196

init



#####201

枚举统计



#####202

模拟除法



#####210

双端队列,模拟



#####213

位运算,乱搞



#####220

模拟



#####221

枚举扫描线,离散化



#####227

乱搞



#####232

字符串模拟



#####247

floyd找强联通



#####253

模拟乱搞



#####270

init



#####272

乱搞



#####297

init



#####299

init



#####340

乱搞



#####350

init



#####375

init



#####400

模拟乱搞



#####401

乱搞



#####408

init



#####409

init



#####414

init



#####424

init



#####439

init



#####442

init



#####445

init



#####455

乱搞



#####457

init



#####458

init



#####465

init



#####488

init



#####489

模拟乱搞



#####490

init



#####494

init



#####506

模拟,树,标记,spj



#####508

模拟,compare



#####509

模拟，位运算



#####512

离线乱搞



#####514

stack,模拟



#####515

init



#####532

init



#####537

init



#####540

stl,list



#####548

init



#####550

init



#####558

init



#####563

init



#####567

init



#####568

init



#####572

init



#####573

init



#####575

init



#####579

init



#####591

init



#####621

init



#####644

init



#####657

init



#####658

bfs



#####673

init



#####694

init



#####699

init



#####705

init



#####712

init



#####748

init



#####753

network flow



#####755

init



#####784

init



#####814

红黑树,模拟乱搞



#####816

bfs,迷宫,状态判重



#####820

network flow



#####821

floyd



#####839

init



#####846

init







##ZOJ



#####3411_SpecialSpecialJudge

大数,计数,dp



#####3447_DoraemonsNumberGame

贪心,凑样例,大数



#####3587_MarlonsString

KMP,计数,dp,倒着+



#####1039_NumberGame

状压dp,记忆化搜索,考虑必胜态和必败态如何转化



#####1082_StockbrokerGrapevine

init



#####1134_StrategicGame

树形dp



#####1203_Swordfish

init



#####1221_Risk

init



#####1232_AdventureofSuperMario

init



#####1354_ExtendedLightsOut

开关问题,枚举第一层状态,剩下的都能确定



#####1455_ScheduleProblem

init



#####1508_Intervals

init



#####1586_QSNetwork

init



#####1655_TransportGoods

init



#####1721_TheDoors

init



#####1791_CaveRaider

init



#####1857_FireStation

init



#####1967_FiberNetwork

init



#####2027_TravellingFee

init



#####2158_TruckHistory

init



#####2702_UnrhymableRhymes

双向链，贪心



#####2859_MatrixSearching

init



#####2913_Bus

Pass init



#####2921_Stock

贪心，从后往前贪



#####3088_EasterHolidays

init



#####3175_NumberofContainers

找规律



#####3201_TreeofTree

树形dp,分组背包



#####3408_Gao

最短路,dp,计数



#####3409_KKV

动量守恒,计算几何,参数方程



#####3415_ZhouYu

期望,等比数列求和



#####3420_DoubleMaze

BFS,字典序最小



#####3422_GoDeeper

#####2-SAT,二分



#####3424_Rescue

维护(a+b)^2=a^2+2ab+b^2



#####3430_DetecttheVirus

AC自动机



#####3434_HiiragisSticks

dp,筛法,计数



#####3449_DoraemonsNumberGameIII

打表找规律



#####3450_DoraemonsRailgun

dp,分组背包



#####3455_ShizukasLetter

等价判断,扫描O(1)维护出现次数



#####3524_CrazyShopping

DAG,DP,背包



#####3525_Disappearance

扫描线



#####3526_WeekendParty

缩点,dfs



#####3540_AddingNewMachine

线段树扫描线,离散化,计数



#####3569_DrZombosssRevenge

注意每多一个就要加,所以多出来的每一个期望都是ai/n



#####3575_UnderAttackIII

计算几何,椭圆转化为圆



#####3580_AngryBirds

记忆化搜索,状压dp,枚举,物理,斜抛运动



#####3646_MatrixTransformer

init



#####3710_Friend

图，乱搞



#####3747_AttackonTitans

dp,至少转化为至多



#####3790_Consecutive

Blocks init



#####3795_Grouping

init



#####3809_TheHimalayas

水



#####3811_UntrustedPatrol

离线并查集



#####3826_HierarchicalNotation

init



#####3841_Cards

dfs,计数,逆元



#####1456_MinimumTransportCost

init



#####2008_InvitationCards

init



