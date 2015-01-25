/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 25 Jan 2015 03:12:09 PM CST
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

#define maxm 198964
#define maxn 233

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int pre[maxn],d[maxn];
bool inq[maxn];
int q[maxm<<3];

inline void add_edge(int s,int t,itn c,int d)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;w[e]=d;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;w[e]=-d;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
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
    itn x=q[f++];
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

pair<int,int> min_cost_flow(int s,int t)
{
  int total_flow=0,total_cost=0;
  memset(flow,0,sizeof flow);

  for (;;)
  {
    SPFA(s);
    if (d[t]==INF) break;

    int f=INF;
    for (int e=pre[t];~e;e=pre[u[e]])
      f=min(f,cap[e]-flow[e]);

    for (int e=pre[t];~e;e=pre[u[e]])
    {
      flow[e]+=f;
      flow[e^1]-=f;
    }

    total_flow+=f;
    total_cost+=f*d[t];
  }

  return {total_flow,total_cost};
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  itn n;

  while (scanf("%d",&n),n!=0)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);
    int s=0,t=n+n+1;

    for (int i=1,m;i<=n;i++)
    {
      add_edge(s,i,1,0);
      add_edge(i+n,t,1,0);
      for (int k,d;;)
      {
        scanf("%d",&k);
        if (k==0) break;
        scanf("%d",&d);
        add_edge(i,k+n,1,d);
      }
    }

    auto res=min_cost_flow(s,t);

    if (res.first==n)
      printf("%d\n",res.second);
    else
      puts("N");
  }

  return 0;
}
