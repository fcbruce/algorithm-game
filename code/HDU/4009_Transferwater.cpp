/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Nov 2014 04:24:26 PM CST
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

#define maxm 1000007
#define maxn 1007

using namespace std;

const long long INFll = 0x3f3f3f3f3f3f3f3fll;

int n,X,Y,Z;
int x[maxn],y[maxn],z[maxn];

inline int __dis(int a,int b)
{
  return abs(x[a]-x[b])+abs(y[a]-y[b])+abs(z[a]-z[b]);
}

inline int calc_cost(int s,int t)
{
  int res=__dis(s,t)*Y;
  if (z[t]>z[s]) res+=Z;
  return res;
}

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
long long w[maxm];
int e_max,v_max;

int vis[maxn],cir_no[maxn],__prev[maxn];
long long in[maxn];

inline void add_edge(int s,int t,long long c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

long long dmst(int s)
{
  long long res=0ll;
  for (;;)
  {
    memset(in,0x3f,sizeof in);
    for (int e=0;e<e_max;e++)
    {
      if (w[e]<in[v[e]] && u[e]!=v[e])
      {
        in[v[e]]=w[e];
        __prev[v[e]]=u[e];
      }
    }

    for (int i=0;i<v_max;i++)
      if (i!=s && in[i]==INFll) return -1;

    int cir_cnt=0;
    memset(cir_no,-1,sizeof cir_no);
    memset(vis,-1,sizeof vis);
    in[s]=0;

    for (int i=0;i<v_max;i++)
    {
      res+=in[i];
      int v=i;
      while (vis[v]!=i && cir_no[v]==-1 && v!=s)
      {
        vis[v]=i;
        v=__prev[v];
      }

      if (v!=s && cir_no[v]==-1)
      {
        for (int u=__prev[v];u!=v;u=__prev[u])
          cir_no[u]=cir_cnt;
        cir_no[v]=cir_cnt++;
      }
    }

    if (cir_cnt==0) break;

    for (int i=0;i<v_max;i++)
      if (cir_no[i]==-1)
        cir_no[i]=cir_cnt++;

    for (itn e=0;e<e_max;e++)
    {
      int t=v[e];
      u[e]=cir_no[u[e]];
      v[e]=cir_no[v[e]];
      if (u[e]!=v[e]) w[e]-=in[t];
    }

    v_max=cir_cnt;
    s=cir_no[s];
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d%d%d",&n,&X,&Y,&Z),n||X||Y||Z)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1;i<=n;i++)
    {
      scanf("%d%d%d",x+i,y+i,z+i);
      add_edge(0,i,X*z[i]);
    }

    for (int i=1,k;i<=n;i++)
    {
      scanf("%d",&k);
      for (int j=0,v;j<k;j++)
      {
        scanf("%d",&v);
        add_edge(i,v,calc_cost(i,v));
      }
    }

    v_max=n+1;

    long long res=dmst(0);
    if (res>=0) printf(lld"\n",res);
    else puts("poor XiaoA");
  }


  return 0;
}
