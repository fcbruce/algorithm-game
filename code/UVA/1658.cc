/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 16 Jan 2015 08:25:26 PM CST
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
#define maxn 2333

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int pre[maxn],d[maxn];
bool inq[maxn];
int q[maxm<<3];

inline void add_edge(int s,int t,int c,int d)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;w[e]=d;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;w[e]=-d;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

void spfa(int s)
{
  memset(d,0x3f,sizeof d);
  memset(inq,0,sizeof inq);
  int f,r;
  q[f=r=0]=s;
  d[s]=0;
  pre[s]=-1;
  
  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (itn e=fir[x];~e;e=nex[e])
    {
      if (cap[e]>flow[e] && d[v[e]]>d[x]+w[e])
      {
        d[v[e]]=d[x]+w[e];
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
  memset(flow,0,sizeof flow);

  for (;;)
  {
    spfa(s);
    if (d[t]==INF) break;

    int f=INF;

    for (int e=pre[t];~e;e=pre[u[e]])
      f=min(f,cap[e]-flow[e]);
    
    for (int e=pre[t];~e;e=pre[u[e]])
    {
      flow[e]+=f;
      flow[e^1]-=f;
    }

    total_cost+=d[t]*f;
  }

  return total_cost;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(fir,-1,sizeof fir);
    e_max=0;

    for (int i=1;i<=n;i++) add_edge(i+n,i,1,0);
    for (int i=0,u,v,d;i<m;i++)
    {
      scanf("%d%d%d",&u,&v,&d);
      add_edge(u,v+n,1,d);
    }

    int s=0,t=n+n+1;
    add_edge(s,1,2,0);
    add_edge(n+n,t,2,0);

    printf("%d\n",MCMF(s,t));
  }
  return 0;
}
