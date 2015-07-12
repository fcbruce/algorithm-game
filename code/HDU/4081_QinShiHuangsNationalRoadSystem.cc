/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 11 Jul 2015 03:32:23 PM CST
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
#define maxn 1007

using namespace std;

struct City
{
  int x,y,p;
  void read()
  {
    scanf("%d%d%d",&x,&y,&p);
  }
  double dis(const City &rhs)
  {
    return sqrt(sqr(x-rhs.x)+sqr(y-rhs.y));
  }
}city[maxn];

double g[maxn][maxn];
double maxcost[maxn][maxn];
double mincost[maxn];
bool vis[maxn];

int p[maxn];

double prim(int n)
{
  memset(mincost,0x7f,sizeof mincost);
  memset(maxcost,0,sizeof maxcost);
  memset(vis,0,sizeof vis);
  mincost[0]=0;
  for (int i=0;i<n;i++) p[i]=i;

  double res=0;

  for (;;)
  {
    int v=-1;
    for (int i=0;i<n;i++)
      if (!vis[i] && (v==-1 || mincost[v]>mincost[i])) v=i;

    if (v==-1) break;

    res+=mincost[v];
    vis[v]=true;

    for (int i=0;i<n;i++)
    {
      if (!vis[i] && mincost[i]>g[v][i])
      {
        mincost[i]=g[v][i];
        p[i]=v;
      }
      if (vis[i] && v!=i)
      {
        maxcost[v][i]=maxcost[i][v]=max(maxcost[i][p[v]],g[p[v]][v]);
      }
    }
  }

  return res;

}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T-->0)
  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) city[i].read();

    for (int i=0;i<n;i++)
    {
      for (int j=0;j<i;j++)
        g[i][j]=g[j][i]=city[i].dis(city[j]);

      g[i][i]=0;
    }

    double W=prim(n);
    double res=0;

    for (int i=0;i<n;i++) for (int j=0;j<i;j++)
      res=max(res,(city[i].p+city[j].p)/(W-maxcost[i][j]));

    printf("%.2f\n",res);
  }



  return 0;
}
