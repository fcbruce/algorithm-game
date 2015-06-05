/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 05 Jun 2015 09:39:08 PM CST
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

#define maxm 10007
#define maxn 1007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

int d[maxn];
bool vis[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dijkstra(int s,int n)
{
  memset(d,0x3f,sizeof d);
  memset(vis,0,sizeof vis);
  d[0]=0;

  for (;;)
  {
    int x=-1;
    for (int i=0;i<=n;i++) if (!vis[i] && (x==-1 || d[i]<d[x])) x=i;

    if (x==-1) break;
    vis[x]=true;

    for (int e=fir[x];~e;e=nex[e]) d[v[e]]=min(d[v[e]],d[x]+w[e]);
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int m,n1,n2;

  while (scanf("%d%d%d",&m,&n1,&n2)==3)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);
    int n=0;
    while (m-->0)
    {
      int u,v,w;
      n=max(n,max(u,v));
      scanf("%d%d%d",&u,&v,&w);
      add_edge(u,v,w);
      add_edge(v,u,w);
    }

    for (int i=0,v;i<n1;i++)
    {
      scanf("%d",&v);
      add_edge(0,v,0);
    }

    dijkstra(0,n);
    int res=INF;
    for (int i=0,v;i<n2;i++)
    {
      scanf("%d",&v);
      res=min(res,d[v]);
    }

    printf("%d\n",res);
  }




  return 0;
}
