/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 12 Aug 2015 03:40:52 PM CST
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

#define maxm 60007
#define maxn 30007

using namespace std;

int fir[maxn],w[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int size[maxn],pos[maxn],son[maxn],top[maxn],fa[maxn],dep[maxn];

int cnt;

int maxv[maxn<<2],sum[maxn<<2];

void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int f,int d)
{
  size[s]=1;
  fa[s]=f;
  dep[s]=d;
  son[s]=-1;

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=f)
  {
    dfs(v[e],s,d+1);
    size[s]+=size[v[e]];
    if (son[s]==-1 || size[v[e]]>size[son[s]]) son[s]=v[e];
  }
}

void build(int s,int tp)
{
  pos[s]=cnt++;top[s]=tp;
  if (son[s]!=-1) build(son[s],tp);
  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa[s] && v[e]!=son[s])
    build(v[e],v[e]);
}

void pushup(int k)
{
  int lc=k*2+1,rc=k*2+2;
  maxv[k]=max(maxv[lc],maxv[rc]);
  sum[k]=sum[lc]+sum[rc];
}

void update(int p,int v,int k,int l,int r)
{
  if (l+1==r)
  {
    sum[k]=maxv[k]=v;
    return ;
  }

  int m=l+r>>1;
  if (p<m) update(p,v,k*2+1,l,m);
  else update(p,v,k*2+2,m,r);

  pushup(k);
}

int query_max(int a,itn b,int k,int l,int r)
{
  if (b<=l || r<=a) return -INF;
  if (a<=l && r<=b) return maxv[k];

  return max(query_max(a,b,k*2+1,l,l+r>>1),query_max(a,b,k*2+2,l+r>>1,r));
}

int query_sum(int a,itn b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (a<=l && r<=b) return sum[k];

  return query_sum(a,b,k*2+1,l,l+r>>1)+query_sum(a,b,k*2+2,l+r>>1,r);
}

int query_max(int x,int y)
{
  int tx=top[x],ty=top[y];

  int res=-INF;

  while (tx!=ty)
  {
    if (dep[tx]>dep[ty])
    {
      swap(x,y);
      swap(tx,ty);
    }

    res=max(res,query_max(pos[ty],pos[y]+1,0,0,cnt));

    y=fa[ty];
    ty=top[y];
  }

  if (dep[x]>dep[y]) swap(x,y);
  res=max(res,query_max(pos[x],pos[y]+1,0,0,cnt));

  return res;
}

int query_sum(int x,int y)
{
  int tx=top[x],ty=top[y];

  int res=0;

  while (tx!=ty)
  {
    if (dep[tx]>dep[ty])
    {
      swap(x,y);
      swap(tx,ty);
    }

    res+=query_sum(pos[ty],pos[y]+1,0,0,cnt);

    y=fa[ty];
    ty=top[y];
  }

  if (dep[x]>dep[y]) swap(x,y);
  res+=query_sum(pos[x],pos[y]+1,0,0,cnt);

  return res;
}

char cmd[32];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int i=1,u,v;i<n;i++)
  {
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }

  for (int i=1;i<=n;i++) scanf("%d",w+i);

  cnt=0;
  dfs(1,-1,0);
  build(1,1);

  for (int i=1;i<=n;i++) update(pos[i],w[i],0,0,cnt);

  int q;
  scanf("%d",&q);

  while (q--)
  {
    int x,y;
    scanf("%s%d%d",cmd,&x,&y);

    switch (cmd[1])
    {
      case 'H':update(pos[x],y,0,0,cnt);
               break;
      case 'M':printf("%d\n",query_max(x,y));
               break;
      case 'S':printf("%d\n",query_sum(x,y));
               break;
    }
  }



  return 0;
}
