/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 07 May 2015 04:55:42 AM CST
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
#define maxn 1000007

using namespace std;

int n,m1,m2;
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int pre[maxn];

int q[maxn],d[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int root(int x)
{
  return x==pre[x]?x:pre[x]=root(pre[x]);
}

inline bool same(int u,int v)
{
  return root(u)==root(v);
}

inline void merge(int u,int v)
{
  pre[root(v)]=root(u);
}

bool cycle()
{
  int f=0,r=-1;
  memset(d,0,sizeof d);
  for (int e=0;e<e_max;e++) d[v[e]]++;

  for (int i=1;i<=n;i++) if (d[i]==0) q[++r]=i;

  for (int i=0;i<n;i++)
  {
    if (f>r) return true;

    int x=q[f++];

    for (int e=fir[x];~e;e=nex[e])
    {
      d[v[e]]--;
      if (d[v[e]]==0) q[++r]=v[e];
    }
  }

  return false;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%d%d%d",&n,&m1,&m2);

    for (int i=1;i<=n;i++) pre[i]=i;

    bool ok=false;
    while (m1--)
    {
      int u,v;
      scanf("%d%d",&u,&v);

      if (same(u,v)) ok=true;

      merge(u,v);
    }

    memset(fir,-1,sizeof fir);
    e_max=0;

    while (m2--)
    {
      int u,v;
      scanf("%d%d",&u,&v);

      if (same(u,v)) ok=true;

      add_edge(root(u),root(v));
    }


    if (!ok) ok=cycle();

    puts(ok?"YES":"NO");
  }


  return 0;
}
