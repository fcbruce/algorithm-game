/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 04 Aug 2015 09:51:09 AM CST
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

#define maxm 307
#define maxn 157

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int dp[maxn][maxn];
int size[maxn];

int res;

int n,p;

void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int fa)
{
  memset(dp[s],0x3f,sizeof dp[s]);
  size[s]=1;
  dp[s][1]=0;

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
  {
    dfs(v[e],s);
    size[s]+=size[v[e]];
    dp[s][1]++;
  }

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
  {
    for (int i=size[s];i>0;i--) for (int j=1;j<=size[v[e]];j++)
    {
      if (i<j) break;
      dp[s][i]=min(dp[s][i],dp[s][i-j]+dp[v[e]][j]-1);
    }
  }

  res = min(res,dp[s][p] + (fa==-1? 0 : 1));
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  e_max=0;
  memset(fir,-1,sizeof fir);

  scanf("%d%d",&n,&p);

  for (int i=1,u,v;i<n;i++)
  {
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }

  res=INF;
  dfs(1,-1);

  printf("%d\n",res);


  return 0;
}
