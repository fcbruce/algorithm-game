/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-24 14:48:53 
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

#define maxm 233333
#define maxn 233

using namespace std;

const int split_w=100000;

int G[maxn][maxn];

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],cost[maxm],nex[maxm];
int e_max=0;
int d[maxn],p[maxm],q[maxm<<3];
bool inq[maxn];

inline void
add_edge(int _u,int _v,int _cap,int _cost)
{
  int e;
  e=e_max++;
  u[e]=_u;v[e]=_v;cap[e]=_cap;cost[e]=_cost;
  nex[e]=fir[u[e]];fir[u[e]]=e;
  e=e_max++;
  u[e]=_v;v[e]=_u;cap[e]=0;cost[e]=-_cost;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void
SPFA(int s)
{
  int f,r;
  memset(d,0x3f,sizeof d);
  memset(inq,0,sizeof inq);
  d[s]=0;
  p[s]=-1;
  q[f=r=0]=s;
  
  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (cap[e]>flow[e] && d[v[e]]>d[u[e]]+cost[e])
      {
        d[v[e]]=d[u[e]]+cost[e];
        p[v[e]]=e;
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

pair<int,int>
min_cost_flow(int s,int t)
{
  memset(flow,0,sizeof flow);
  int total_cost=0,total_flow=0;
  
  for (;;)
  {
    SPFA(s);
    if (d[t]==INF) break;
    
    int _f=INF;
    for (int e=p[t];~e;e=p[u[e]]) _f=min(_f,cap[e]-flow[e]);
    
    for (int e=p[t];~e;e=p[u[e]])
    {
      flow[e]+=_f;
      flow[e^1]-=_f;
    }
    
    total_cost+=_f*d[t];
    total_flow+=_f;
  }
  
  return make_pair(total_cost,total_flow);
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int n,m,k;
  
  while (scanf("%d%d%d",&n,&m,&k),n||m||k)
  {
    memset(G,0x3f,sizeof G);
    for (int i=0,u,v,w;i<m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      G[u][v]=G[v][u]=min(G[u][v],w);
    }
    
    for (int k=0;k<=n;k++)
      for (int i=0;i<=n;i++)
        if (G[i][k]!=INF)
          for (int j=0;j<=n;j++)
            G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            

    e_max=0;
    memset(fir,-1,sizeof fir);
    
    int s=2*n+1,t=2*n+2;
    
    add_edge(s,0,k,0);
    add_edge(0,t,k,0);
    
    for (int i=1;i<=n;i++)
    {
      add_edge(i,i+n,1,-split_w);
      add_edge(0,i,1,G[0][i]);
      add_edge(i+n,t,1,G[0][i]);
    }
    
    for (int i=1;i<=n;i++)
      for (int j=i+1;j<=n;j++)
        add_edge(i+n,j,1,G[i][j]);

    printf("%d\n",min_cost_flow(s,t).first+split_w*n);
  }
  
  return 0;
}



