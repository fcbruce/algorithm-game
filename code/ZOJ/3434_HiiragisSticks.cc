/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 26 Jul 2015 01:47:13 PM CST
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 1000007

using namespace std;

bool S[maxn];

bool isp[maxn];
vector<int> factor[maxn];

long long dp[maxn];

inline void init()
{
  memset(isp,true,sizeof isp);
  isp[0]=isp[1]=true;
  for (int i=2;i<maxn;i++) if (isp[i])
  {
    factor[i].push_back(i);
    for (int j=i*2;j<maxn;j+=i) 
    {
      factor[j].push_back(i);
      isp[j]=false;
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  init();

  int T_T;
  scanf("%d",&T_T);

  while (T_T-->0)
  {
    int n,m,l;
    scanf("%d%d%d",&n,&m,&l);
    memset(S,false,sizeof S);
    S[0]=true;
    for (int i=0,v;i<n;i++)
    {
      scanf("%d",&v);
      for (int j=v;j<=l;j++) S[j]|=S[j-v];
    }
    memset(dp,0,sizeof dp);
    for (int i=0,v;i<m;i++)
    {
      scanf("%d",&v);
      dp[v]++;
    }
    
    for (int i=2;i<=l;i++)
      for (auto e : factor[i]) dp[i]+=dp[i/e];

    long long res=0;
    for (int i=1;i<=l;i++) if (S[i]) res+=dp[i];

    printf(lld "\n",res);
  }



  return 0;
}
