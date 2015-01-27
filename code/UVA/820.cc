/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 27 Jan 2015 12:12:27 PM CST
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
#define maxn 107

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int lv[maxn],iter[maxn],q[maxn];

void add_edge(int s,int t,int c)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

void dinic_bfs(int s)
{
  int f,r;
  memset(lv,-1,sizeof lv);
  lv[s]=0;
  q[f=r=0]=s;

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

int dinic_dfs(int s,int t,int f)
{
  if (s==t) return f;

  for (int &e=iter[s];~e;e=nex[e])
  {
    if (cap[e]>flow[e] && lv[v[e]]>lv[s])
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

int max_flow(int s,int t)
{
  int total_flow=0;
  memset(flow,0,sizeof flow);

  for (;;)
  {
    dinic_bfs(s);
    if (lv[t]<0) break;

    int f;
    memcpy(iter,fir,sizeof fir);
    while ((f=dinic_dfs(s,t,INF))>0) total_flow+=f;
  }

  return total_flow;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  
  int n;

  while (scanf("%d",&n),n!=0)
  {
    int s,t,m;
    scanf("%d%d%d",&s,&t,&m);
    
    e_max=0;
    memset(fir,-1,sizeof fir);

    while (m--)
    {
      int u,v,c;
      scanf("%d%d%d",&u,&v,&c);
      add_edge(u,v,c);
      add_edge(v,u,c);
    }

    printf("Network %d\n",++__);
    printf("The bandwidth is %d.\n\n",max_flow(s,t));
  }

  return 0;
}
