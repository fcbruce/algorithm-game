/*
 *
 * Author : fcbruce
 *
 * Time : Thu 09 Oct 2014 12:11:27 PM CST
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

#define maxm 180000
#define maxn 333

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int iter[maxn],lv[maxn];
int q[maxn];

inline void add_edge(int _u,int _v,int _w)
{
  int &e=e_max;
  u[e]=_u;v[e]=_v;cap[e]=_w;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=_v;v[e]=_u;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

void dinic_bfs(int s)
{
  memset(lv,-1,sizeof lv);
  int f,r;
  q[f=r=0]=s;
  lv[s]=0;
  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e])
    {
      if (lv[v[e]]<0 && cap[e]>flow[e])
      {
        lv[v[e]]=lv[x]+1;
        q[++r]=v[e];
      }
    }
  }
}

int dinic_dfs(int s,int t,int _f)
{
  if (s==t) return _f;
  for (itn &e=iter[s];~e;e=nex[e])
  {
    if (lv[v[e]]>lv[s] && cap[e]>flow[e])
    {
      int d=dinic_dfs(v[e],t,min(_f,cap[e]-flow[e]));
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

int max_flow(int s,int t)
{
  int total_flow=0;
  memset(flow,0,sizeof flow);

  for (;;)
  {
    dinic_bfs(s);
    if (lv[t]<0) break;

    memcpy(iter,fir,sizeof fir);

    int f;
    while ((f=dinic_dfs(s,t,INF))>0)
      total_flow+=f;
  }

  return total_flow;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  while (scanf("%d%d",&n,&m),n||m)
  {
    int s=0,t=n+1;

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,c;i<=n;i++)
    {
      scanf("%d",&c);
      if (c==1) add_edge(s,i,1);
      else add_edge(i,t,1);
    }

    for (int i=0,u,v;i<m;i++)
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v,1);
      add_edge(v,u,1);
    }

    printf("%d\n",max_flow(s,t));
  }


  return 0;
}
