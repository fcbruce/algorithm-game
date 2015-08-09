/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 09 Aug 2015 09:20:42 AM CST
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
#define maxn 3007

using namespace std;

int n,m;

int fir[maxn];
int u[maxn],v[maxn],w[maxn],nex[maxn];
int e_max;

int dp[maxn][maxn];
int leaves[maxn];
int pay[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s)
{
  memset(dp[s],0xcf,sizeof dp[s]);
  dp[s][0]=0;

  if (pay[s]!=-1)
  {
    leaves[s]=1;
    dp[s][1]=pay[s];
    return ;
  }

  leaves[s]=0;

  for (int e=fir[s];~e;e=nex[e])
  {
    dfs(v[e]);
    leaves[s]+=leaves[v[e]];
    for (int i=leaves[s];i>=0;i--) for (int j=0;j<=leaves[v[e]];j++)
    {
      if (j>i) break;
      dp[s][i]=max(dp[s][i],dp[s][i-j]+dp[v[e]][j]-w[e]);
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  e_max=0;
  memset(fir,-1,sizeof fir);

  memset(pay,-1,sizeof pay);

  scanf("%d%d",&n,&m);

  for (int i=1;i<=n-m;i++)
  {
    int k;
    scanf("%d",&k);
    int v,w;
    while (k-- && scanf("%d%d",&v,&w)) add_edge(i,v,w);
  }

  for (int i=n-m+1;i<=n;i++) scanf("%d",pay+i);

  dfs(1);

  int res=0;
  for (int i=0;i<=m;i++) if (dp[1][i]>=0) res=i;

  printf("%d\n",res);

  return 0;
}
