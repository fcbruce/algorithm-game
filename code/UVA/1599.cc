/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 02 Mar 2015 07:49:18 PM CST
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

#define maxm 400007
#define maxn 100007

using namespace std;

int fir[maxn];
itn u[maxm],v[maxm],w[maxm],nex[maxm];
itn e_max;

int q[maxm<<3];
bool inq[maxn];
int d[maxn];

int c[maxn];
int cp[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
  int f,r;
  memset(inq,0,sizeof inq);
  memset(d,0x3f,sizeof d);
  d[s]=0;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (d[v[e]]>d[u[e]]+1)
      {
        d[v[e]]=d[u[e]]+1;
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

void bfs(int s,int t)
{
  int f,r;
  q[f=r=0]=s;
  memset(inq,0,sizeof inq);
  memset(c,0x3f,sizeof c);
  memset(cp,0x3f,sizeof cp);

  while (f<=r)
  {
    int x=q[f++];

    if (x==t) return ;

    if (c[d[x]]!=cp[x]) continue;

    for (int e=fir[x];~e;e=nex[e]) if (d[v[e]]+1==d[x])
      c[d[v[e]]]=min(c[d[v[e]]],w[e]);
    
    for (int e=fir[x];~e;e=nex[e]) if (d[v[e]]+1==d[x] && c[d[v[e]]]==w[e])
    {
      cp[v[e]]=min(cp[v[e]],w[e]);
      if (!inq[v[e]])
      {
        inq[v[e]]=true;
        q[++r]=v[e];
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;

  while (scanf("%d %d",&n,&m)==2)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0,u,v,w;i<m;i++) 
    {
      scanf("%d %d %d",&u,&v,&w);
      add_edge(u,v,w);
      add_edge(v,u,w);
    }

    SPFA(n);

    bfs(1,n);

    printf("%d\n",d[1]);
    
    int first=true;
    for (int i=d[1]-1;i>=0;i--)
    {
      if (!first) putchar(' ');
      first=false;
      printf("%d",c[i]);
    }
    puts("");
  }



  return 0;
}
