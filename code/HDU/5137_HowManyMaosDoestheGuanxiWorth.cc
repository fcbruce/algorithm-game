/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 26 May 2015 11:43:22 PM CST
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

#define maxm 
#define maxn 37

using namespace std;

int G[maxn][maxn];
int d[maxn];
bool vis[maxn];

int dijkstra(int s,int ban,int n)
{
  memset(vis,0,sizeof vis);
  memset(d,0x3f,sizeof d);
  d[s]=0;
  vis[ban]=true;

  for (;;)
  {
    int v=-1;
    for (int i=1;i<=n;i++) if (!vis[i] && (v==-1 || d[v]>d[i])) v=i;

    if (v==-1) break;
    vis[v]=true;

    for (int i=1;i<=n;i++) d[i]=min(d[i],d[v]+G[v][i]);
  }

  return d[n];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  
  while (scanf("%d%d",&n,&m),n!=0 && m!=0)
  {
    memset(G,0x3f,sizeof G);
    while (m--)
    {
      int u,v,w;
      scanf("%d%d%d",&u,&v,&w);
      G[u][v]=G[v][u]=min(G[u][v],w);
    }

    int res=0;
    for (int i=2;i<n;i++) res=max(res,dijkstra(1,i,n));

    if (res==INF) puts("Inf");
    else printf("%d\n",res);
  }



  return 0;
}
