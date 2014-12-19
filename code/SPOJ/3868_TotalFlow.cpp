/*
 *
 * Author : fcbruce
 *
 * Time : Wed 08 Oct 2014 07:31:18 PM CST
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

#define maxm 2333
#define maxn 100 

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

itn iter[maxn],lv[maxn];
itn q[maxn];

inline void add_edge(itn _u,int _v,itn _w)
{
  int &e=e_max;
  u[e]=_u;v[e]=_v;cap[e]=_w;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=_v;v[e]=_v;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

void dinic_bfs(int s)
{
  memset(lv,-1,sizeof fir);
  int f,r;
  q[f=r=0]=s;

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
  
  for (int &e=iter[s];~e;e=nex[e])
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
  memset(flow,0,sizeof fir);

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

  int n;
  while (scanf("%d",&n)==1)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    char u,v;
    itn w;
    for (int i=0;i<n;i++)
    {
      scanf(" %c %c %d",&u,&v,&w);
      add_edge(u-'A',v-'A',w);
    }

    int s=0,t=25;

    printf("%d\n",max_flow(s,t));
  }

  return 0;
}
