/*
 *
 * Author : fcbruce
 *
 * Time : Fri 03 Oct 2014 12:55:32 PM CST
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
#define maxn 233

using namespace std;

int n;
int busyness[maxn];

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

inline void add_edge(int _u,int _v,int _w)
{
  int e=e_max++;
  u[e]=_u;v[e]=_v;w[e]=_w;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int d[maxn],inc[maxn],p[maxn];
bool inq[maxn];
int q[maxm],qb[maxn];
bool vis[maxn];

void bfs(int s)
{
  vis[s]=true;
  int f,r;
  qb[f=r=0]=s;
  d[s]=0;

  while (f<=r)
  {
    int x=qb[f++];
    for (int e=fir[x];~e;e=nex[e])
    {
      if (!vis[v[e]])
      {
        vis[v[e]]=true;
        d[v[e]]=0;
        qb[++r]=v[e];
      }
    }
  }
}

void SPFA(int s)
{
  memset(vis,0,sizeof vis);
  memset(d,0x3f,sizeof d);
  memset(inq,0,sizeof inq);
  memset(inc,0,sizeof inc);
  int f,r;
  q[f=r=0]=s;
  d[s]=0;

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (!vis[v[e]] && d[v[e]]>d[u[e]]+w[e])
      {
        d[v[e]]=d[u[e]]+w[e];
        p[v[e]]=u[e];
        if (!inq[v[e]])
        {
          inc[v[e]]++;
          if (inc[v[e]]>n) bfs(v[e]);
          if (vis[v[e]]) continue;
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  itn __=0;
  
#define cube(x) (sqr(x)*(x))

  while (scanf("%d",&n)==1)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1;i<=n;i++)
      scanf("%d",busyness+i);

    int m;
    scanf("%d",&m);
    for (int i=0,u,v;i<m;i++)
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v,cube(busyness[v]-busyness[u]));
    }

    SPFA(1);

    printf("Set #%d\n",++__);

    int q,dest;
    scanf("%d",&q);
    while (q--)
    {
      scanf("%d",&dest);
      if (d[dest]<3 || d[dest]==INF)
        puts("?");
      else
        printf("%d\n",d[dest]);
    }
  }



  return 0;
}
