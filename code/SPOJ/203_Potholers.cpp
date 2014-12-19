/*
 *
 * Author : fcbruce
 *
 * Time : Wed 08 Oct 2014 12:20:04 PM CST
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

#define maxm 46464
#define maxn 233

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max=0;

int q[maxm];
int lv[maxn];
int iter[maxn];

inline void add_edge(int _u,int _v,int _w)
{
  int e=e_max++;
  u[e]=_u;v[e]=_v;cap[e]=_w;
  nex[e]=fir[u[e]];fir[u[e]]=e;
  e=e_max++;
  u[e]=_v;v[e]=_u;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dinic_bfs(int s)
{
  itn f,r;
  memset(lv,-1,sizeof lv);
  lv[s]=0;
  q[f=r=0]=s;

  while (f<=r)
  {
    itn x=q[f++];
    for (int e=fir[x];~e;e=nex[e])
    {
      if (lv[v[e]]<0 && cap[e]>flow[e])
      {
        q[++r]=v[e];
        lv[v[e]]=lv[x]+1;
      }
    }
  }
}

int dinic_dfs(itn s,itn t,int _f)
{
  if (s==t) return _f;
  for (int &e=iter[s];~e;e=nex[e])
  {
    if (cap[e]>flow[e] && lv[v[e]]>lv[s])
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

int max_flow(itn s,int t)
{
  int total_flow=0;
  memset(flow,0,sizeof flow);

  for (;;)
  {
    dinic_bfs(s);
    if (lv[t]<0) break;

    memcpy(iter,fir,sizeof fir);

    int _f;
    while ((_f=dinic_dfs(s,t,INF))>0)
      total_flow+=_f;
  }

  return total_flow;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  itn T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    itn n;
    scanf("%d",&n);

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,m;i<n;i++)
    {
      scanf("%d",&m);
      for (int j=0,v;j<m;j++)
      {
        scanf("%d",&v);
        if (i==1 || v==n)
          add_edge(i,v,1);
        else
          add_edge(i,v,INF);
      }
    }

    int s=1,t=n;

    printf("%d\n",max_flow(s,t));
  }


  return 0;
}
