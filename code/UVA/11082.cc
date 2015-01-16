/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 16 Jan 2015 03:46:50 PM CST
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

#define maxm 8964
#define maxn 64

using namespace std;

itn fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int lv[maxn],iter[maxn];
int q[maxm];

int r[maxn],c[maxn];

int G[maxn][maxn];

inline void add_edge(int s,itn t,int c)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;flow[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;flow[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

int dinic_dfs(int s,int t,int f)
{
  if (s==t) return f;
  for (int e=fir[s];~e;e=nex[e])
  {
    if (cap[e]>flow[e] && lv[u[e]]<lv[v[e]])
    {
      int d=dinic_dfs(v[e],t,min(f,cap[e]-flow[e]));
      if (d>0)
      {
        flow[e]+=d;
        flow[e^1]-=d;
        return d;
      }
    }
  }
  return 0;
}

void dinic_bfs(int s)
{
  memset(lv,-1,sizeof lv);
  lv[s]=-1;
  int f,r;
  q[f=r=0]=s;
  lv[s]=0;

  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e])
    {
      if (cap[e]>flow[e] && lv[v[e]]<0)
      {
        lv[v[e]]=lv[x]+1;
        q[++r]=v[e];
      }
    }
  }
}

void max_flow(int s,int t)
{
  int total=0;
  for (;;)
  {
    dinic_bfs(s);
    if (lv[t]<0) break;

    memcpy(iter,fir,sizeof fir);
    itn f;
    while ((f=dinic_dfs(s,t,INF))>0) total+=f;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    memset(fir,-1,sizeof fir);
    e_max=0;

    int n,m;
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    r[0]=c[0]=0;
    for (int i=1;i<=n;i++)
    {
      scanf("%d",r+i);
      add_edge(s,i,r[i]-r[i-1]-m);
    }
    for (int i=1;i<=m;i++)
    {
      scanf("%d",c+i);
      add_edge(i+n,t,c[i]-c[i-1]-n);
    }
    for (int i=1;i<=n;i++)
      for (int j=1;j<=m;j++)
        add_edge(i,j+n,19);

    max_flow(s,t);

    for (int i=0;i<e_max;i++)
    {
      if (0<u[i] && u[i]<=n && n<v[i] && v[i]<=n+m)
        G[u[i]][v[i]-n]=flow[i]+1;
    }

    if (__>0) puts("");
    printf("Matrix %d\n",++__);
    for (int i=1;i<=n;i++)
    {
      printf("%d",G[i][1]);
      for (int j=2;j<=m;j++) printf(" %d",G[i][j]);
      puts("");
    }
  }


  return 0;
}
