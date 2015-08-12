/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 12 Aug 2015 01:41:10 PM CST
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

#define maxm 404
#define maxn 202

using namespace std;

int n;
int fir[maxn];
int u[maxm],v[maxm],type[maxm],nex[maxm];
int e_max;

int d[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;type[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int maxl;

bool vis[maxn];
int q[maxn];

void bfs(int s)
{
  int f,r;
  memset(vis,0,sizeof vis);
  d[s]=1;
  vis[s]=true;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e]) if (!vis[v[e]] && type[e]==1)
    {
      d[v[e]]=d[x]+1;
      maxl=max(maxl,d[v[e]]);
      vis[v[e]]=true;
      q[++r]=v[e];
    }
  }
}

int f[maxn],g[maxn];

void dfs(int s,int fa)
{
  f[s]=g[s]=1;

  vector<pair<int,int> > tmp;

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
  {
    dfs(v[e],s);
    if (type[e]==0) tmp.push_back({f[v[e]],g[v[e]]});
    else if (type[e]>0) g[s]=max(g[s],g[v[e]]+1);
    else f[s]=max(f[s],f[v[e]]+1);
  }

  if (tmp.empty())
  {
    if (f[s]+g[s]-1 > maxl)
      f[s]=g[s]=INF;
    return ;
  }

  int f0=f[s],g0=g[s];
  f[s]=g[s]=INF;

  int n=tmp.size();
  sort(tmp.begin(),tmp.end());
  int maxg[maxn];
  maxg[n-1]=tmp[n-1].second;
  for (int k=n-2;k>=0;k--) maxg[k]=max(maxg[k+1],tmp[k].second);
  for (int k=0;k<=n;k++)
  {
    int f1=f0,g1=g0;
    if (k>0) f1=max(f1,tmp[k-1].first+1);
    if (k<n) g1=max(g1,maxg[k]+1);
    if (f1+g1-1 <= maxl) f[s]=min(f[s],f1);
  }

  sort(tmp.begin(),tmp.end(),[](const pair<int,int> &lhs, const pair<int,int> &rhs){ return lhs.second<rhs.second;});
  int maxf[maxn];
  maxf[n-1]=tmp[n-1].first;
  for (int k=n-2;k>=0;k--) maxf[k]=max(maxf[k+1],tmp[k].first);
  for (int k=0;k<=n;k++)
  {
    int f1=f0,g1=g0;
    if (k>0) g1=max(g1,tmp[k-1].second+1);
    if (k<n) f1=max(f1,maxf[k]+1);
    if (f1+g1-1 <= maxl) g[s]=min(g[s],g1);
  }

  if (f[s]+g[s]-1 > maxl)
    f[s]=g[s]=INF;
}

void read(int u)
{
  int v;
  char c;
  n=max(n,u);
  while (scanf("%d%c",&v,&c)==2 && v!=0)
  {
    n=max(n,v);
    switch (c)
    {
      case 'u':add_edge(u,v,-1);
               add_edge(v,u,1);
               break;
      case 'd':add_edge(u,v,1);
               add_edge(v,u,-1);
               break;
      default:add_edge(u,v,0);
              add_edge(v,u,0);
              break;
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int u;

  while (scanf("%d",&u)==1 && u!=0)
  {
    n=0;
    e_max=0;
    memset(fir,-1,sizeof fir);

    read(u);
    while (scanf("%d",&u)==1 && u!=0) read(u);

    maxl=0;
    for (int i=1;i<=n;i++) bfs(i);

    dfs(1,-1);

    printf("%d\n",maxl+(f[1]+g[1]-1 > maxl ? 1 : 0));
  }



  return 0;
}
