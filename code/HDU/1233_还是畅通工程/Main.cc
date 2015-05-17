/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 12:36:44 PM CST
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
#define maxn 107

using namespace std;

int G[maxn][maxn];
int d[maxn];
bool vis[maxn];

int prim(int n)
{
  memset(vis,0,sizeof vis);
  memset(d,0x3f,sizeof d);
  d[1]=0;
  int res=0;

  for (;;)
  {
    int v=-1;
    for (int i=1;i<=n;i++) if (!vis[i] && (v==-1 || d[v]>d[i])) v=i;

    if (v==-1) break;

    vis[v]=true;
    res+=d[v];

    for (int i=1;i<=n;i++) d[i]=min(d[i],G[v][i]);
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1,n!=0)
  {
    for (int i=0,u,v,w;i<n*(n-1)/2;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      G[u][v]=w;
      G[v][u]=w;
    }

    printf("%d\n",prim(n));
  }



  return 0;
}
