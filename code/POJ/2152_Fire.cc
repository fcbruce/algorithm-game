/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Aug 2015 02:21:02 PM CST
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

#define maxm 2007
#define maxn 1007

using namespace std;

int n;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

int c[maxn],d[maxn],best[maxn];

int dis[maxn][maxn];
int dp[maxn][maxn];

bool belong[maxn][maxn];

int q[maxn];
bool vis[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void sub(int s,int fa,int i)
{
  belong[s][i]=true;
  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
    sub(v[e],s,i);
}

void dfs(int s,int fa)
{
  memset(dp[s],0x3f,sizeof dp[s]);

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
    dfs(v[e],s);

  sub(s,fa,s);

  for (int j=1;j<=n;j++) if (dis[s][j]<=d[s])
  {
    dp[s][j]=0;
    if (!belong[j][s] || j==s)
    {
      for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
        dp[s][j]+=min(best[v[e]],dp[v[e]][j]);
      if (s==j) dp[s][j]+=c[s];
    }
    else if (belong[j][s])
    {
      for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
        if (belong[j][v[e]]) dp[s][j]+=dp[v[e]][j];
        else dp[s][j]+=min(best[v[e]],dp[v[e]][j]);
    }

    if (belong[j][s]) best[s]=min(best[s],dp[s][j]);
  }
}

void bfs(int s)
{
  int f,r;
  memset(vis,false,sizeof vis);
  dis[s][s]=0;
  vis[s]=true;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e]) if (!vis[v[e]])
    {
      dis[s][v[e]]=dis[s][x]+w[e];
      vis[v[e]]=true;
      q[++r]=v[e];
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%d",&n);

    for (int i=1;i<=n;i++) scanf("%d",c+i);
    for (int i=1;i<=n;i++) scanf("%d",d+i);

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,u,v,w;i<n;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      add_edge(u,v,w);
      add_edge(v,u,w);
    }

    for (int i=1;i<=n;i++) bfs(i);

    memset(best,0x3f,sizeof best);
    memset(belong,false,sizeof belong);

    dfs(1,-1);
    
    printf("%d\n",best[1]);
  }



  return 0;
}
