/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 24 Jul 2015 10:47:08 AM CST
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

#define maxm 120007
#define maxn 2007

using namespace std;

int fir[maxn],iter[maxn],lv[maxn],d[maxn];
int u[maxm],v[maxm],w[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int q[maxm<<3];

bool inq[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

inline void add_edge(int s,int t,int c,int f)
{
  int &e=e_max;
  u[e]=s;v[e]=t;w[e]=c;cap[e]=f;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;w[e]=c;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

void SPFA(int s)
{
  int f,r;
  memset(d,0x3f,sizeof d);
  memset(inq,false,sizeof inq);
  memset(lv,0x3f,sizeof lv);
  d[s]=lv[s]=0;
  q[f=r=0]=s;
  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      bool update=false;
      if (d[v[e]]==d[u[e]]+w[e] && lv[v[e]]>lv[u[e]]+1)
      {
        update=true;
        lv[v[e]]=lv[u[e]]+1;
      }
      else if (d[v[e]]>d[u[e]]+w[e])
      {
        update=true;
        lv[v[e]]=lv[u[e]]+1;
        d[v[e]]=d[u[e]]+w[e];
      }
      if (update && !inq[v[e]])
      {
        inq[v[e]]=true;
        q[++r]=v[e];
      }
    }
  }
}

bool dinic_bfs(int s,int t)
{
  int f,r;
  memset(lv,-1,sizeof fir);
  lv[s]=0;
  q[f=r=0]=s;
  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e]) if (cap[e]>flow[e] && lv[v[e]]<0)
    {
      lv[v[e]]=lv[u[e]]+1;
      q[++r]=v[e];
    }
  }
  return lv[t]>-1;
}

int dinic_dfs(int s,int t,int f)
{
  if (s==t) return f;
  for (int &e=iter[s];~e;e=nex[e]) if (cap[e]>flow[e] && lv[v[e]]>lv[s])
  {
    int d=dinic_dfs(v[e],t,min(f,cap[e]-flow[e]));
    if (d>0) 
    {
      flow[e]+=d;
      flow[e^1]-=d;
      return d;
    }
  }
  return 0;
}

int max_flow(int s,int t)
{
  int total_flow=0;
  memset(flow,0,sizeof flow);
  while (dinic_bfs(s,t))
  {
    memcpy(iter,fir,sizeof fir);
    int f;
    while ((f=dinic_dfs(s,t,INF))>0) total_flow+=f;
  }
  return total_flow;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  
  while (scanf("%d%d",&n,&m)==2)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0,u,v,w;i<m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      add_edge(u,v,w);
      add_edge(v,u,w);
    }

    SPFA(1);
    int res = m-lv[n];

    int E=e_max;
    e_max=0;
    memset(fir,-1,sizeof fir);
    for (int e=0;e<E;e++)
      if (d[v[e]]==d[u[e]]+w[e]) add_edge(u[e],v[e],INF,1);
    
    printf("%d %d\n",max_flow(1,n),max(res,0));
  }



  return 0;
}
