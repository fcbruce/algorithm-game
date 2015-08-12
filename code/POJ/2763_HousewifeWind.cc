/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 12 Aug 2015 04:31:51 PM CST
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

#define maxm 200007
#define maxn 100007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

struct edge
{
  int u,v,w;
  void swap()
  {
    std::swap(u,v);
  }
}edge[maxn];

int size[maxn],son[maxn],dep[maxn],fa[maxn],pos[maxn],top[maxn];

int cnt;

int sum[maxn<<2];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int f,int d)
{
  size[s]=1;
  fa[s]=f;
  son[s]=-1;
  dep[s]=d;
  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=f)
  {
    dfs(v[e],s,d+1);
    size[s]+=size[v[e]];
    if (son[s]==-1 || size[son[s]]<size[v[e]]) son[s]=v[e];
  }
}

void build(int s,int tp)
{
  pos[s]=cnt++;top[s]=tp;
  if (son[s]!=-1) build(son[s],tp);
  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa[s] && v[e]!=son[s])
    build(v[e],v[e]);
}

void update(int p,int v,int k,int l,int r)
{
  if (l+1==r)
  {
    sum[k]=v;
    return ;
  }
  int m=l+r>>1;
  if (p<m) update(p,v,k*2+1,l,m);
  else update(p,v,k*2+2,m,r);

  sum[k]=sum[k*2+1]+sum[k*2+2];
}

int query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (a<=l && r<=b) return sum[k];
  return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int query(int x,int y)
{
  int res=0;

  while (top[x]!=top[y])
  {
    if (dep[top[x]]>dep[top[y]]) swap(x,y);
    res+=query(pos[top[y]],pos[y]+1,0,1,cnt);
    y=fa[top[y]];
  }

  if (x!=y)
  {
    if (dep[x]>dep[y]) swap(x,y);
    res+=query(pos[son[x]],pos[y]+1,0,1,cnt);
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,q,s;
  scanf("%d%d%d",&n,&q,&s);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int i=1,u,v,w;i<n;i++)
  {
    scanf("%d%d%d",&u,&v,&w);
    edge[i]={u,v,w};
    add_edge(u,v);
    add_edge(v,u);
  }

  cnt=0;
  dfs(1,-1,0);
  build(1,1);
  for (int i=1;i<n;i++)
  {
    if (dep[edge[i].u]>dep[edge[i].v]) edge[i].swap();
    update(pos[edge[i].v],edge[i].w,0,1,cnt);
  }

  while (q--)
  {
    int q,x,y;
    scanf("%d",&q);
    if (q==0)
    {
      scanf("%d",&x);
      printf("%d\n",query(s,x));
      s=x;
    }
    else
    {
      scanf("%d%d",&x,&y);
      update(pos[edge[x].v],y,0,1,cnt);
    }
  }



  return 0;
}
