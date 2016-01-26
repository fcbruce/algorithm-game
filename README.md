algorithm game
========


###TODO
考虑添加Leetcode && 51Nod




##BZOJ



####1036 树的统计Count

树链剖分,点权,基础题







##Codeforces

####[581C Developing Skills](code/CF/problem/DevelopingSkills.cc)

贪心乱搞

####[582B Once Again...](code/CF/problem/582B_OnceAgain.cc)

dp,循环节,乱搞

####[582A GCD Table](code/CF/problem/582A_GCDTable.py)

gcd乱搞，贪心

####[584E Anton and Ira](code/CF/problem/584E_AntonandIra.cc)

选择排序+冒泡排序思想乱搞

####[584D Dima and Lisa](code/CF/problem/584D_DimaandLisa.cc)

二分乱搞

####[584C Marina and Vasya](code/CF/problem/584C_MarinaandVasya/Main.java)

字符串乱搞

####[165D Beard Graph](code/CF/problem/165D_BeardGraph.cc)

树链剖分，边权

####525A VitaliyandPie

模拟，统计

####525B PashaandString

乱搞

####525C IIyaandSticks

greed,two-pointer



####134C Swaps

YY,优先队列贪心,大的先换



####14A Letter

模拟乱搞



####15C IndustrialNim

Nim博弈,[0,x]异或



####182E WoodenFence

dp,计数



####19D Points

线段树,分治



####204A LittleElephantandInterval

乱搞，分类讨论，计数



####230C Shifts

枚举,二分,乱搞



####239B EasyTapeProgramming

模拟,水



####245E MishapinClub

乱搞,max-min



####25D RoadsnotonlyinBerland

tree,构造,水



####327C MagicFive

计数,等比数列求和



####327D BlockTower

bfs逆序，贪心，联通块



####330C Purification

YY乱搞,按行/列铺



####332C StudentsRevenge

贪心,sort



####359D PairofNumbers

gcd,线段树,二分



####35D Animals

greed,sort



####384C Milkingcows

贪心,首先考察任意两头牛的情况



####4C Registrationsystem

map



####520A Pangram

水,乱搞



####520B TwoButtons

bfs,水



####526A KingofThieves

枚举



####526B OmNomandDarkPark

二叉树,分治乱搞



####526C OmNomandCandies

贪心枚举乱搞,两边扫



####85C PetyaandTree

树形dp,分治



####8C LookingforOrder

状压dp,记忆化,顺序无关







##HDU

####[5601 N\*M bulbs](code/HDU/5601_N*Mbulbs.cc)

1的格子要进去奇数次，0的格子要进去偶数次，左上到右下一共要n+m-1步，判断是否同奇偶即可。

####[5486 Difference of Clustering](code/HDU/5486_DifferenceofClustering.cc)

可以把图看作二分图。如果某个块左部1个点、右部1个点，就是1:1，如果左部一个点、右部若干个点，就是split，如果左部若干点，右部1个点，就是merge。用度数乱搞就行。

####[5493 Queue](code/HDU/5493_Queue.cc)

线段树。从矮到高排序，对于第i人，前面要么空k<sub>i</sub>个位置，要么后面空k<sub>i</sub>个人，选择靠前的位置插入，找不到位置即为impossible.

####[5052 Yaoge's maximum profit](code/HDU/5052_Yaogesmaximumprofit.cc)

树链剖分+区间合并。首先考虑是线段的情况:对与一个区间(从左到右)maximum profit要么在左子区间，要么在右子区间，要么右子区间最大-左子区间最小，方向可能有两种，那维护两个就可以。
树上就考虑是从top到bottom还是从bottom到top两种方向。对于有根树，一条简单路径一定能分为从bottom to top 和top to bottom两段(允许为空),一样维护即可。

####[4405 Aeroplane chess](code/HDU/4405_Aeroplanechess/Main.java)

期望dp。dp[i]表示从i到n的期望步数。显然有
<img src='http://latex.numberempire.com/render?%5Csmall%20dp%5Bi%5D%3D%5Cfrac16%5Csum_%7Bj%3D1%7D%5E6dp%5Bi%2Bj%5D&sig=9c34c6817f663edaa44ab2db13bfb26a' 
dp[i]=\frac16\sum_{j=1}^6dp[i+j]> , 
当能直接跳的时候`dp[i]=dp[to[i]]`.

####[3853 LOOPS](code/HDU/3853_LOOPS/Main.java)

期望dp。dp[i][j]表示从(i,j)到(n,m)的期望魔法值。显然有
<img src='http://latex.numberempire.com/render?%5Csmall%20dp%5Bi%5D%5Bj%5D%3Ddp%5Bi%5D%5Bj%5DP_1%5Bi%5D%5Bj%5D%2Bdp%5Bi%5D%5Bj%2B1%5DP_2%5Bi%5D%5Bj%5D%2Bdp%5Bi%2B1%5D%5Bj%5DP_3%5Bi%5D%5Bj%5D%2B2&sig=cc7f2d4ce7e09964b69064f9c0846d10' 
 dp[i][j]=dp[i][j]P_1[i][j]+dp[i][j+1]P_2[i][j]+dp[i+1][j]P_3[i][j]+2> ,
化简整理得 <img src='http://latex.numberempire.com/render?%5Csmall%20dp%5Bi%5D%5Bj%5D%3D%5Cfrac%7Bdp%5Bi%5D%5Bj%2B1%5DP_2%5Bi%5D%5Bj%5D%2Bdp%5Bi%2B1%5D%5Bj%5DP_3%5Bi%5D%5Bj%5D%2B2%7D%7B1-P_1%5Bi%5D%5Bj%5D%7D&sig=320dcb174ba1a8bee68c04d748b6f1d2' 
 dp[i][j]=\frac{dp[i][j+1]P_2[i][j]+dp[i+1][j]P_3[i][j]+2}{1-P_1[i][j]}>，注意当P<sub>1</sub>[i][j] = 1时，该点不可达。

####[5029 Relief grain](code/HDU/5029_Reliefgrain.cc)

树链剖分。问树上每个点被覆盖最多次的颜色。首先不考虑树，考虑线段：[x, y) 上染颜色c, 我们不妨在x点做标记+1，y点做标记-1，
然后对标记（事件点）排序，线性扫一边，当前哪种颜色最多，用堆维护即可。树上的话只要对树进行轻重路径剖分转化为线段即可。

####[5478 Can you find it](code/HDU/5478_Canyoufindit.cc)

2015上海赛区网络赛，费马小定理，枚举a，计算b，检查 a^k1 = b^k2 (mod C).

####[5475 An easy problem](code/HDU/5475_Aneasyproblem.cc)

2015上海赛区网络赛，线段树维护区间乘积。

####5441 Travel

离线并查集乱搞

####5437 Alish's Party

优先队列乱搞

####5442 Favorite Donut

最小表示法+hash

####2421 Deciphering Password

根据唯一分解定理，任意一个整数 N = p1^c1 * p2^c2 * ... * pk*ck ，N的因子的数量为 (c1+1) * (c2+1) * ... *(ck+1)。
假设 A^B 的因子 f = a1^b1 * a2*b2 * ... * an*bn, f 的因子数量 count = (b1+1) * (b2+1) * ... *(bn+1), 现在要求 sum(count^3).
count^3 = product(bi+1)^3 = product((bi+1)^3), 把式子展开再提公因子可以得 sum(count^3) = profuct(sum(j^3, j in 1 .. ci+1)).
立方和公式 (n*(n+1)/2)^2, 注意除以2要变成乘2对模10007下的逆元。

####3756 Dome of Circus

三分半径。

####4336 Card Collector

容斥原理

####2841 Visible Tree

容斥原理。"容斥原理简单来说就是奇数个加，偶数个减。"————我操

####3966 Aragorn's Story

树链剖分+线段树。

####4670 Cube number on a tree

树上点分治。首先对于一个cube number,他的每种质因子个数一定被3整除，那么只要维护路径上各质因子的个数。
对于一个分治子树，要统计的路径有两种：过根节点的和不过根节点的。不过根节点的只要在它的分治子树上去统计就行了；
过根节点的不方便统计，那么反过来考虑，全部的 - 不过根节点的 = 过根节点的，注意去重。



####1181 变形课

floyd,水



####1233 还是畅通工程

MST



####1254 推箱子

bfs+dfs



####1272 小希的迷宫

judge a tree 并查集



####3123 GCC

大数,找规律,小心模



####3336 Countthestring

KMP,计数,dp



####4509 湫湫系列故事减肥记II

乱搞,水



####4911 Inversion

逆序数



####5166 Missingnumber

sort,枚举



####5167 Fibonacci

红黑树,枚举,筛



####5178 pairs

sort,单调



####5179 beautifulnumber

dfs枚举



####1024 MaxSumPlusPlus

dp



####1025 ConstructingRoadsInJGShiningsKingdom

LIS



####1030 Delta-wave

14-15年周赛5(2014-12-28),乱搞



####1058 HumbleNumbers

init



####1069 MonkeyandBanana

init



####1078 FatMouseandCheese

dp,记忆化搜索



####1081 ToTheMax

dp,降维,最大连续子段和,水



####1128 SelfNumbers

打表



####1158 EmploymentPlanning

dp[i][j]表示第i天剩j人的最小花费



####1196 LowestBit

14-15年周赛5(2014-12-28)



####1222 WolfandRabbit

14-15年周赛5(2014-12-28)



####1237

表达式求值，栈



####1257 最少拦截系统

14-15年周赛5(2014-12-28)



####1269 迷宫城堡

14-15年周赛5(2014-12-28)



####1284 钱币兑换问题

14-15年周赛5(2014-12-28)



####1573 X问题

中国剩余定理,不互质



####1702 ACboyneedsyourhelpagain

模拟乱搞,queue,stack



####1711 NumberSequence

KMP



####1789 DoingHomeworkagain

init



####1829 ABugsLife

种类并查集



####1978 Howmantways

init



####2066 一个人的旅行

dijkstra,水



####2087 剪花布条

KMP



####2089 不要62

数位dp



####2196 Computer

树的直径



####2222 KeywordsSearch

AC自动机



####2448 MiningStationontheSea

14-15年周赛5(2014-12-28),费用流



####2452 Navymaneuvers

DAG动态规划



####2577 HowtoType

init



####2594 SimpsonsHiddenTalents

KMP



####2609 Howmany

字符串,最小表示法,状压



####2830 MatrixSwappingII

init



####2845 Beans

init



####2870 LargestSubmatrix

init



####2896 病毒侵袭

AC自动机



####3065 病毒侵袭持续中

AC自动机



####3125 Slash

模拟,水



####3181

init



####3333 TuringTree

init



####3374 StringProblem

KMP,最小表示法



####3411 SnailAlice

数列递推公式,矩阵快速幂



####3555 Bomb

数位dp



####3579 HelloKiKi

中国剩余定理,模数不互质,合并方程组两两求解



####3652 Bnumber

数位dp



####3696 FarmGame

DAG,dp/topo



####3709 BalancedNumber

数位dp



####3714 ErrorCurves

三分



####3746 CyclicNacklace

KMP



####3854 GloriousArray

脑洞,小于k的为单元集,每个元素都不能和同一集合的元素成pair,维护即可


####3872 Dargon Ball

DP+单调栈+线段树。dp[i]表示前i个球分好组的最小花费，显然此时i是右端点，若前一个和i同类型的位置为le[i],le[i] <= j < i,
dp[i]=min{dp[j] + max{ek | j < k <= i}},但这样的复杂度是O(n^2)，不妨考虑ek，若ek..ei中ek是最大的，那么显然ek就是后面这段的花费，
若ek前面第一个比他大的位置为j,则有dp[i]=min{min{dp|\[ j , k \) } + ek },所以用单调栈维护降序的e，在栈中去枚举，虽然负责度还是O(n^2),但基本达不到上界。


####3874 Necklace

init



####3972-2

init



####3972

init



####3976 Electricresistance

基尔霍夫第一定律,高斯消元



####3994 MissionImpossible

floyd概率dp



####4006 Thekthgreatnumber

红黑树,stl



####4009 Transferwater

init



####4027 Canyouanswerthesequeries

init



####4057 RescuetheRabbit

init



####4081 QinShiHuangsNationalRoadSystem

次小生成树



####4193 Non-negativePartialSums

单调队列



####4268 AliceandBob

init



####4324 TriangleLOVE

init



####4404 Worms

init



####4411 Arrest

init



####4415 AssassinsCreed

init



####4419 ColourfulRectangle

init



####4445 CrazyTank

init



####4734 Fx

数位dp



####4749 ParadeShow

KMP,前缀和维护前面有多少等级相同和等级小的,HDU数据SB,明显WA的code也能AC



####4786 FibonacciTree

生成树,乱搞



####4841

init



####4915 Parenthese

sequence init



####4918 Queryonthesubtree

点分治,树状数组维护点到分治中心的距离,注意去重



####4948 Kingdom

init



####4960 AnotherOCDPatient

init



####4966 GGSDDU

init



####4969 JustaJoke

init



####4970 KillingMonsters

init



####4971 Asimplebruteforceproblem

init



####4973 Asimplesimulationproblem

init



####4975 AsimpleGaussianeliminationproblem

init



####5023 ACorruptMayorsPerformanceArt

init



####5031 Lines

init



####5033 Building

init



####5071 Chat

init



####5086 RevengeofSegmentTree

init



####5091 BeamCannon

init



####5098 SmartSoftwareInstaller

DAG动态规划,最长路,SPFA/topo



####5124 line

init



####5130 SignalInterference

init



####5137 HowManyMaosDoestheGuanxiWorth

最短路,水



####5150 SumSumSum

HDU 5150



####5183 NegativeandPositiveNP

set,前缀和



####5191 BuildingBlocks

前后补0，区间乱搞，前缀和



####5192 BuildingBlocksII

Segment-Tree，前后加0，aver,aver+1,加挂加优化



####5198 StrangeClass

模拟乱搞，注意细节



####5199 Gunner

离线乱搞



####5200 Trees

离线并查集，逆向思维



####5222 Exploration

混合图找环,并查集无向边缩点,有向边用topo找环



####5288 OOsSequence

筛法,找规律,计数



####5289 Assignment

二分,ST表O(1)查询区间最值



####5294 TricksDevice

最短路+最小割



####1520 Anniversaryparty

init



####3255 Farming

init



####WirelessPassword

init







##LA(UVa Live)

####[7143 Room Assignment](code/LA/7143_RoomAssignment.cc)

dp+组合数学。dp[i][j]表示装完i房间后还剩j对双胞胎，接下来要装i+1房间，j中选x对双胞胎都装进i+1，然后j-x中选y对拆开其中1个装进去，最后装那些独生子女，即
<img src='http://latex.numberempire.com/render?dp%5Bi%5D%5Bj%5D%5Cmathrm%7BC%7D_j%5Ex%5Cmathrm%7BC%7D_%7Bj-x%7D%5E%7By%7D%5Cmathrm%7BC%7D_%7Brest-2j%7D%5E%7Bc%5Bi%5D-2x-y%7D&sig=b3ceb1a2ab302e027886df75451df966'
dp[i][j]\mathrm{C}_j^x\mathrm{C}_{j-x}^{y}\mathrm{C}_{rest-2j}^{c[i]-2x-y}> 

####[7141 BombX](code/LA/7141_BombX.cc)

离散化+线段树扫描线。首先想一想POJ的那道Stars in the Window，就是那篇情书，这两题的建模其实非常相似。炸弹需要W\*H的空间，那么不妨反过来考虑卒，一个卒占W\*H的空间，可以重叠。
那么空出来的格点就可以放炸弹，这个位置对应的范围的x方向+y方向的卒就是炸的数量，用前缀和搞下即可。

####[7148 LRIP](code/LA/7148_LRIP.cc)

树的分治+线段树。单调不降的path,对与树s,要么穿过s，要么完全在它的某个子树内。后者直接分治，前者则可以从s开始分为单调不降和单调不升的两个链，把这些链全部找到后要取匹配，
维护两棵线段树，对于长度l的链，取其中d最小的，然后就是找最长的且d满足的即可。

####[7147 World Cup](code/LA/7147_WorldCup/Main.java)

脑洞。求最大：对于后面的队伍，拿最高的分，然后就是前m+1个队伍中垫底分数最高，可以并列，总的win场次=lose场次，那么要最高，大家分都一样，如果是奇数就取`max(draw, lose)`。求最小反过来考虑即可。

####[7146 Defeat the Enemy](code/LA/7146_DefeattheEnemy.cc)

multiset!对于敌人(A,D),我们首先要找一个Attack大于等于D的，其次要这个可以two pointers搞，然后要找Defence仅大于A的，如果找不到用最小的。


####7129 Rotation

计算每个格点被包围了多少次，然后计算平方和，用扫描线的思想即可。


####2191 Potentiometers

init



####3661 AnimalRun

init



####6281 ExactMeasurement

init



####6459 InfiniteGo

init



####6485 2

init



####6485 ElectricCarRally

init



####6487 StarSimulations

init



####6622 AbsurdistanRoads

init



####6623 BattleforSilver

init



####6663 CounttheRegions

init


##POJ

####[1426 Find The Multiple](code/POJ/1426_FindTheMultiple.cc)

bfs,同余

####[1035 Spell checker](code/POJ/1035_Spellchecker.cc)

字符串乱搞

####[1459 Power Network](code/POJ/1459_PowerNetwork.cc)

多源多汇最大流

####[1019 NumberSequence](code/POJ/1019_NumberSequence.cc)

二分乱搞

####[1011 Sticks](code/POJ/1011_Sticks.cc)

搜索+减枝，从大到小搜。

####[3110 Jenny's First Exam](code/POJ/3110_JennysFirstExam.cc)

线段树，日期映射。

####[3134 Power Calculus](code/POJ/3134_PowerCalculus.cc)

暴搜+打表。

####[3468 A Simple Problem with Integers](code/POJ/3468_ASimpleProblemwithIntegers.cc)

线段树。

####[2096 Collecting Bugs](code/POJ/2096_CollectingBugs/Main.java)

期望dp。dp[i][j]表示从已经发现i种bug分布在j个系统到(n,s)的期望步数，由全期望公式
<img src='http://latex.numberempire.com/render?%5Csmall%20dp%5Bi%5D%5Bj%5D%3Ddp%5Bi%5D%5Bj%5D%5Cfrac%20in%5Cfrac%20js%2Bdp%5Bi%2B1%5D%5Bj%5D%5Cfrac%7Bn-i%7Dn%5Cfrac%20js%2Bdp%5Bi%5D%5Bj%2B1%5D%5Cfrac%20in%5Cfrac%7Bs-j%7Ds%2Bdp%5Bi%2B1%5D%5Bj%2B1%5D%5Cfrac%7Bn-i%7Dn%5Cfrac%7Bs-j%7Ds%2B1&sig=aca9b7b7fe25b3748e10c7c7b11c72ac' 
dp[i][j]=dp[i][j]\frac in\frac js+dp[i+1][j]\frac{n-i}n\frac js+dp[i][j+1]\frac in\frac{s-j}s+dp[i+1][j+1]\frac{n-i}n\frac{s-j}s+1>, 
化简即得状态转移方程。

####3101 Astronomy

Java 大数。考虑两个星球，假设其周期为t1,t2,到一直线的周期为 T = abs( 1 / ( 1 / t1 - 1 / t2) ) / 2;
那么n个星球有 n - 1 个这样的周期T，求其最小公倍数即可。两个分数的最小公倍数怎么求呢？假设其最简形式分别为 a/b, c/d,
首先考虑 lcm(a, c) 除以这两个分数一定能得到整数：lcm(a, c) * b / a = c * b / gcd(a, c), lcm(a, c) * d / c = a * d / gcd(a, c);
那我们要这两个数最小，显然 b 和 d 还能除以gcd(b, d),从而 lcm(a/b, c/d) = lcm(a, c) / gcd(b, d).




####2299 Ultra-QuickSort

merge,逆序数,bug fixed



####2352 Stars

离线BIT



####2456 Aggressivecows

二分



####3450 CorporateIdentity

二分长度,字符串乱搞



####1001 Exponentiation

init



####1006 Biorhythms

中国剩余定理



####1028 WebNavigation

模拟,水



####1094 SortingItAllOut

toposort



####1095 TreesMadetoOrder

卡特兰数,分治



####1099 SquareIce

模拟,图形打印,较复杂



####1105 S-Trees

二叉树



####1128 FrameStacking

init



####1135 DominoEffect

init



####1155 TELE

树形dp,分组背包



####1166 TheClocks

高斯消元,模线性方程,扩展欧几里得



####1182

init



####1192 最优连通子集

init



####1222 EXTENDEDLIGHTSOUT

开关问题,高斯消元



####1236 NetworkofSchools

init



####1258 Agri-Net

init



####1465 Multiple

init



####1487 SinglePlayerGames

正规文法,树,递归,高斯消元,简单期望



####1625 Censored

init



####1655 BalancingAct

树分治



####1741 Tree

男人八题之经典树(点)分治



####1741 Tree again

点分治



####1847 Tram

最短路



####1947 RebuildingRoads

树形dp,dp[i][j]表示以i为根的子树剩j个点(一定含i)要切多少条边



####2031 BuildingaSpaceStation

init



####2065 SETI

高斯消元,模线性方程,扩展欧几里得



####2152 Fire

树形dp,2006年陈启峰国家集训队论文



####2185 MilkingGrid

init



####2186 PopularCows

init



####2236 WirelessNetwork

并查集



####2259 TeamQueue

队列嵌套,模拟乱搞



####2342 Anniversaryparty

树形dp



####2367 Genealogicaltree

toposort



####2406 PowerStrings

KMP



####2421 ConstructingRoads

init



####2482 StarsinYourWindow

init



####2486 AppleTree

树形dp,分组背包,dp[i][j][0]i子树走j步不回到i,dp[i][j][1]要回到i



####2559 LargestRectangleinaHistogram

dp,左右跳,乱搞



####2585 WindowPains

init



####2676

init



####2694 ASimplePokerGame

模拟,中档水题



####2696 AMysteriousFunction

记忆化,水



####2750 IdiomaticPhrasesGame

init



####2752 SeektheNameSeektheFame

KMP



####2762 Goingfromutovorfromvtou

init



####2763 HousewifeWind

树链剖分,模板题



####2793 Cactus

仙人掌度,点双联通,高精度



####2796 FeelGood

离线并查集



####2947 WidgetFactory

高斯消元,模线性方程,无解,多解,唯一解



####2987 Firing

init



####3026 BorgMaze

init



####3080 BlueJeans

字符串,枚举



####3107 Godfather

树的重心,分治



####3159 Candies

init



####3162 WalkingRace

树的直径,单调队列求最长连续区间最值差不超过k,经典题



####3167 CowPatterns

KMP,前缀和维护前面有多少等级相同和等级小的,HDU数据SB,明显WA的code也能AC



####3169 Layout

init



####3180 TheCowProm

init



####3237 Tree

树链剖分+线段树lazy



####3252 RoundNumbers

数位dp



####3258 RiverHopscotch

二分



####3259 Wormholes

init



####3342 PartyatHaliBula

树形dp



####3345 BribingFIPA

树形dp,分组背包



####3461 Oulipo

KMP



####3532 Resistance

基尔霍夫第一定律,高斯消元,注意判断是否联通



####3678 KatuPuzzle

init



####3687 LabelingBalls

init



####3691 DNArepair

init



####3784 RunningMedian

蒟蒻只会线段树+二分



####3835 Columbussbargin

最短路,坑



####3897 MazeStretching

二分,A*,卡精度貌似



####1122 FDNYtotheRescue

init







##SGU



####134 Centroid

dfs,树的重心,树分治基础







##SPOJ



####1022 AngelsandDevils

init



####1043 CanyouanswerthesequeriesI

init



####11772 NegativeScore

init



####11840 SumofSquareswithSegmentTree

init



####14932 LowestCommonAncestor

init



####1693 Coconuts

init



####1716 CanyouanswerthesequeriesIII

init



####1716 CanyouanswerthesequeriesIII again

init



####203 Potholers

init



####2 PrimeGenerator

init



####32 ANeddleintheHaystack

init



####3868 TotalFlow

init



####4033 PhoneList

init



####7212 FindStringRoots

init



####962 IntergalacticMap

init



####GONE

数位dp



####HIGH

生成树计数,基尔霍夫矩阵,高斯消元,行列式



####LUCIFER

数位dp



####NUMTSN

数位dp



####PERIOD

KMP



####QTREE

树链剖分,单点修改,RMQ,入门题



####RAONE

数位dp







##URAL



####1108 Heritage

数学,YY



####1385 InterestingNumber

数论，打表找规律



####1762 SearchforaHidingPlace

手动模拟找规律



##UVa

####[10900 So you want to be a 2n-aire](code/UVA/10900_Soyouwanttobea2naire/Main.java)

期望。假设现在在第n题，如果答对，能拿到钱2<sup>n</sup>，如果答对的概率为P，那么选择答能拿到的期望奖金为 P\*2<sup>n</sup>,如果不答，则拿2<sup>n-1</sup>。
那么如果P比较大，我们就会选择答，否则我们不答，那么我们可以计算出一个P的临界值P<sub>0</sub>，然后根据全期望公式，可推出转移方程。

####[10288 Coupons](code/UVA/10288_Coupons/Main.java)

期望。离散性随机变量的期望为 <img src='http://latex.numberempire.com/render?%5Csmall%20E%28X%29%3D%5Csum_%7Bk%3D1%7D%5E%7B%5Cinfty%7Dx_kp_k&sig=9bbc5969829707520b14b518790ca4d3' 
E(X)=\sum_{k=1}^{\infty}x_kp_k>.
假设我们已经有了t个,令`s=t/n`,则获得一个新的需要k次的概率为s<sup>k-1</sup>(1-s),则
<img src='http://latex.numberempire.com/render?%5Csmall%20E%28K%29%3D%281-s%29%5Csum_%7Bk%3D1%7D%5E%7B%5Cinfty%7Dk%20s%5E%7Bk-1%7D&sig=4be45faebe9a91e978fcf1a1b4f53dd7' 
E(K)=(1-s)\sum_{k=1}^{\infty}ks^{k-1}>.
令<img src='http://latex.numberempire.com/render?%5Csmall%20T%3D%5Csum_%7Bk%3D1%7D%5E%7B%5Cinfty%7Dk%20s%5E%7Bk-1%7D&sig=6837a9f135a938a78249ea2627bb95a4' T=\sum_{k=1}^{\infty}ks^{k-1}>,
用错位相减法可求得`E(K)=(1-s)T=n/(n-t)`,求和即为总的期望。

####[10491 Cows and Cars](code/UVA/10491_CowsandCars/Main.java)

概率，古典概型，全概率公式。

####[11181 Probability|Given](code/UVA/11181_ProbabilityGiven/Main.java)

概率，贝叶斯定理。已知n人各自买东西的概率P(H<sub>i</sub>)，最终有r个人买了东西，求每个人买了东西的概率。
求的是后验概率，贝叶斯公式:<img src='http://latex.numberempire.com/render?%5Csmall%20P%28H_k%7CA%29%3D%5Cfrac%7BP%28A%20H_k%29%7D%7BP%28A%29%7D&sig=a81c10e519886ff9ac9f18f6d86f3055' P(H_k|A)=\frac{P(AH_k)}{P(A)}> ,
P(A)为r人买东西这一事件的概率。本质是条件概率。

####[12230 Crossing Rivers](code/UVA/12230_CrossingRivers/Main.java)

简单期望

####[11021 Tribles](code/UVA/11021_Tribles.cc)

概率dp，dp[i]表示一只麻球i天后死干净的概率，则k个在第i天后死干净的概率为dp[i]<sup>k</sup>(独立事件)，`dp[i] = p[0] + p[1] * dp[i-1]^1 + p[2] * dp[i-1]^2 + ... `.

####[11427 Expect the Expected](code/UVA/11427_ExpecttheExpected.cc)

概率dp，dp[i][j]表示玩了i盘胜了j盘且 j/i < p 的概率, 根据全概率公式有: `dp[i][j] = dp[i-1][j] * (1-p) + dp[i-1][j-1] * p, dp[0][0] = 1`.

####[11761 Race to 1](code/UVA/11761_Raceto1/Main.java)

期望dp，dp[i]表示i变为1的期望，由全期望公式有：`dp[i] = dp[i] * (1 - g[i]/p[i]) + sum(dp[i/j] / p[i])` 其中g[i]表示i素约数的个数，p[i]表示比i小的素数个数，j为i的素约数，
化简可得：`dp[i] = (sum(dp[i/j]) + p[i]) / g[i]`.


####1025

dp[i][j]-i分钟在j站一共的等车时间



####111

dp,lis/lcs



####1347

dp,记忆化搜索,dp[i][j]表示分别走到i,j时还要走的路程



####1591

枚举,考察deltaQ



####207

模拟，题目上的输入数据样例格式是有问题的，多一个空格，这题不卡精度，要注意发钱的情况



####437

dp,DAG最长路



####679

二叉树,找规律



####815

乱搞



####10004

init



####1001

易证圆外一点到圆的最短路线是沿着圆心连线,floyd乱搞



####10010

模拟乱搞



####10014

init



####10025

init



####10026

init



####10034

init



####10047

init



####10048

floyd



####10050

init



####10054

init



####10057

init



####10061

init



####10082

乱搞



####10098

UVa 10098



####10099

init



####101

模拟乱搞



####10106

init



####10110

init



####10112

init



####10115

init



####10129

init



####10132

init



####10152

init



####10158

init



####10161

init



####10167

init



####10177

init



####10194

init



####10250

init



####10269

init



####10273

init



####10298 PowerStrings

KMP



####10300

init



####10305

init



####10307

init



####10330

init



####10340

乱搞



####10341

init



####10361

init



####10369

init



####10387

init



####10392

init



####10397

init



####104

init



####10420

init



####10449

init



####10474

二分



####10487

init



####10494

init



####10499

init



####10557

init



####10562

init



####10594

init



####10596

init



####10608

init



####10679

init



####107

init



####10700

init



####10706

init



####10719

init



####10735

Network Flow 混合图的欧拉回路 无向边任意定向，出入度判断是否可行，去掉有向边，增加源汇，入>出，连汇，否则连源，满流可行



####10746

init



####10763

init



####10785

init



####10790

init



####10801

最短路



####10803

init



####10806

init



####10815

sort



####10878

init



####10879

init



####10905

init



####10916

init



####10970

init



####10985

init



####10986

init



####1103

dfs找联通块,加边界



####11038

数位dp



####11044

init



####11045

init



####11082

最小割



####11111

init



####112

init



####11205

init



####11234

init



####11297

init



####113

init



####11419

init



####11488

init



####1151

dfs枚举+kruskal



####11809

数学，乱搞，对数



####11988

list



####120

init



####12096

STL,set



####12108

模拟



####12186 AnotherCrisis

树形dp



####1218 PerfectService

树形dp



####122

二叉树,bfs



####1220 PartyatHaliBula

树形dp



####12219

表达式树化简，map判重，用sscanf+正则tle



####1225

乱搞



####12264

network flow,题意略坑，某个army移动过后不能再移动，二分答案，每个点拆成左右两部分，源连左，右连汇，边界点到汇容量为mid…



####123

init



####1232

init



####124

init



####12412

模拟乱搞，要仔细



####125

init



####12549

行列消除，如果没有障碍物，显然是二分图最小点覆盖；遇到障碍物移到新的行列即可,建图是一样的



####12657

双向链表，模拟



####12661

最短路



####127

init



####131

UVa 131



####1328 Period

KMP



####133

模拟乱搞



####1339

sort统计乱搞



####1349

MCMF,二分图,每一个点属于一个有向圈->每一个点有唯一后继



####136

红黑树,乱搞



####1368

字符串模拟



####1380 ASchedulingProblem

树形dp,好难,f[i]表示从孩子到i的最长链,g[i]表示从i出发的最长链,对无向边定向,s.t.最长链尽量短



####1395

kruskal



####146

UVa 146



####1515

network flow,S-草，洞-T



####152

init



####156

stl,sort,map,vector



####1572

topo找环,A+ & B+ 在同一个块中连(A-,B+)&(B-,A+)



####1583

乱搞



####1584

乱搞



####1585

乱搞



####1586

乱搞



####1587

乱搞



####1588

匹配，乱搞



####1589

模拟



####1590

位运算，模拟



####1592

枚举,红黑树,hash



####1599

spfa,bfs,字典序,画出结构层次



####1658

两条没有公共点的路径,费用流,拆点



####1660

拆点，枚举源汇，最小割，边容量inf



####1663

最大独立集，编码差1的建边，V-FLOW/2



####1664

并查集，按权从大到小排，merge时看收益，注意long long



####1665

并查集，离线，输出格式-每个数后加空格



####196

init



####201

枚举统计



####202

模拟除法



####210

双端队列,模拟



####213

位运算,乱搞



####220

模拟



####221

枚举扫描线,离散化



####227

乱搞



####232

字符串模拟



####247

floyd找强联通



####253

模拟乱搞



####270

init



####272

乱搞



####297

init



####299

init



####340

乱搞



####350

init



####375

init



####400

模拟乱搞



####401

乱搞



####408

init



####409

init



####414

init



####424

init



####439

init



####442

init



####445

init



####455

乱搞



####457

init



####458

init



####465

init



####488

init



####489

模拟乱搞



####490

init



####494

init



####506

模拟,树,标记,spj



####508

模拟,compare



####509

模拟，位运算



####512

离线乱搞



####514

stack,模拟



####515

init



####532

init



####537

init



####540

stl,list



####548

init



####550

init



####558

init



####563

init



####567

init



####568

init



####572

init



####573

init



####575

init



####579

init



####591

init



####621

init



####644

init



####657

init



####658

bfs



####673

init



####694

init



####699

init



####705

init



####712

init



####748

init



####753

network flow



####755

init



####784

init



####814

红黑树,模拟乱搞



####816

bfs,迷宫,状态判重



####820

network flow



####821

floyd



####839

init



####846

init







##ZOJ



####3411 SpecialSpecialJudge

大数,计数,dp



####3447 DoraemonsNumberGame

贪心,凑样例,大数



####3587 MarlonsString

KMP,计数,dp,倒着+



####1039 NumberGame

状压dp,记忆化搜索,考虑必胜态和必败态如何转化



####1082 StockbrokerGrapevine

init



####1134 StrategicGame

树形dp



####1203 Swordfish

init



####1221 Risk

init



####1232 AdventureofSuperMario

init



####1354 ExtendedLightsOut

开关问题,枚举第一层状态,剩下的都能确定



####1455 ScheduleProblem

init



####1508 Intervals

init



####1586 QSNetwork

init



####1655 TransportGoods

init



####1721 TheDoors

init



####1791 CaveRaider

init



####1857 FireStation

init



####1967 FiberNetwork

init



####2027 TravellingFee

init



####2158 TruckHistory

init



####2702 UnrhymableRhymes

双向链，贪心



####2859 MatrixSearching

init



####2913 Bus

Pass init



####2921 Stock

贪心，从后往前贪



####3088 EasterHolidays

init



####3175 NumberofContainers

找规律



####3201 TreeofTree

树形dp,分组背包



####3408 Gao

最短路,dp,计数



####3409 KKV

动量守恒,计算几何,参数方程



####3415 ZhouYu

期望,等比数列求和



####3420 DoubleMaze

BFS,字典序最小



####3422 GoDeeper

####2-SAT,二分



####3424 Rescue

维护(a+b)^2=a^2+2ab+b^2



####3430 DetecttheVirus

AC自动机



####3434 HiiragisSticks

dp,筛法,计数



####3449 DoraemonsNumberGameIII

打表找规律



####3450 DoraemonsRailgun

dp,分组背包



####3455 ShizukasLetter

等价判断,扫描O(1)维护出现次数



####3524 CrazyShopping

DAG,DP,背包



####3525 Disappearance

扫描线



####3526 WeekendParty

缩点,dfs



####3540 AddingNewMachine

线段树扫描线,离散化,计数



####3569 DrZombosssRevenge

注意每多一个就要加,所以多出来的每一个期望都是ai/n



####3575 UnderAttackIII

计算几何,椭圆转化为圆



####3580 AngryBirds

记忆化搜索,状压dp,枚举,物理,斜抛运动



####3646 MatrixTransformer

init



####3710 Friend

图，乱搞



####3747 AttackonTitans

dp,至少转化为至多



####3790 Consecutive

Blocks init



####3795 Grouping

init



####3809 TheHimalayas

水



####3811 UntrustedPatrol

离线并查集



####3826 HierarchicalNotation

init



####3841 Cards

dfs,计数,逆元



####1456 MinimumTransportCost

init



####2008 InvitationCards

init



