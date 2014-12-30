/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 29 Dec 2014 08:18:52 PM CST
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

#define maxm 1333333
#define maxn 555 

using namespace std;

int n,m,p,k;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],w[maxm],nex[maxm];
int e_max;

inline void add_edge(int s,int t,int c,int d)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;flow[e]=0;w[e]=d;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;flow[e]=0;w[e]=-d;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

inline void add_edge(int s,int t,int d)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=d;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int d[maxn],pre[maxn];
int q[maxm<<3];
bool inq[maxn];

void spfa(int s)
{
  int f,r;
  memset(d,0x3f,sizeof d);
  memset(inq,0,sizeof inq);
  d[s]=0;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (d[v[e]]>d[u[e]]+w[e])
      {
        d[v[e]]=d[u[e]]+w[e];
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

void SPFA(int s)
{
  int f,r;
  memset(d,0x3f,sizeof d);
  memset(inq,0,sizeof inq);
  pre[s]=-1;

  d[s]=0;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (cap[e]>flow[e] && d[v[e]]>d[u[e]]+w[e])
      {
        d[v[e]]=d[u[e]]+w[e];
        pre[v[e]]=e;
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

int MCMF(int s,int t)
{
  int total_cost=0;

  for (;;)
  {
    SPFA(s);
    if (d[t]==INF) break;

    int f=INF;
    for (int e=pre[t];~e;e=pre[u[e]]){
      f=min(f,cap[e]-flow[e]);
    }

    for (int e=pre[t];~e;e=pre[u[e]])
    {
      flow[e]+=f;
      flow[e^1]-=f;
    }

    total_cost+=f*d[t];
  }

  return total_cost;
}

int sta[maxn];
int G[maxn][maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  while (scanf("%d%d%d%d",&n,&m,&k,&p)==4)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    int s=0,t=n+n+1;
    for (int i=1;i<=n;i++)
      scanf("%d",sta+i);

    for (int i=0,a,b,c;i<k;i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      add_edge(a,b,c);
      add_edge(b,a,c);
    }

    for (int i=0,d,e,f;i<p;i++)
    {
      scanf("%d%d%d",&d,&e,&f);
      add_edge(e,d+m,f);
    }

    for (int i=1;i<=n;i++)
    {
      spfa(sta[i]);
      for (int j=1;j<=n;j++)
        G[i][j]=d[j+m];
    }

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1;i<=n;i++)
    {
      add_edge(s,i,1,0);
      add_edge(i+n,t,1,0);
      for (int j=1;j<=n;j++)
        if (G[i][j]<INF)
          add_edge(i,j+n,1,G[i][j]);
    }

    printf("%d\n",MCMF(s,t));
  }


  return 0;
}
