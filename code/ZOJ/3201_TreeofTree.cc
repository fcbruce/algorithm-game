/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 03 Aug 2015 09:00:30 PM CST
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

#define maxm 207
#define maxn 107

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int dp[maxn][maxn];
int w[maxn];

int n,k;

int res;

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int fa)
{
  memset(dp[s],0,sizeof dp[s]);
  dp[s][1]=w[s];
  res=max(res,dp[s][1]);

  for (int e=fir[s];~e;e=nex[e]) if (fa!=v[e])
  {
    dfs(v[e],s);
    for (int i=k;i>0;i--) for (int j=1;j<=k;j++) 
    {
      if (j>=i) break;
      dp[s][i]=max(dp[s][i],dp[s][i-j]+dp[v[e]][j]);
      res=max(res,dp[s][i]);
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d",&n,&k)==2)
  {
    for (int i=0;i<n;i++) scanf("%d",w+i);
    
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,u,v;i<n;i++) 
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v);
      add_edge(v,u);
    }

    res=0;

    dfs(0,-1);

    printf("%d\n",res);
  }



  return 0;
}
