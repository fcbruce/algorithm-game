/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 12 Aug 2015 07:05:10 PM CST
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

#define maxm 20007
#define maxn 10007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int size[maxn],dep[maxn],son[maxn],fa[maxn],pos[maxn],top[maxn];

int minv[maxn<<2],maxv[maxn<<2],neg[maxn<<2];

int cnt;

char cmd[32];

struct Edge
{
  int u,v,w;
  void swap(){std::swap(u,v);};
}edge[maxn];

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
  dep[s]=d;
  son[s]=-1;
  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=f)
  {
    dfs(v[e],s,d+1);
    size[s]+=size[v[e]];
    if (son[s]==-1 || son[v[e]]>son[s]) son[s]=v[e];
  } 
}

void build(int s,int tp)
{
  pos[s]=cnt++;top[s]=tp;
  if (son[s]!=-1) build(son[s],tp);
  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa[s] && v[e]!=son[s])
    build(v[e],v[e]);
}

inline void pushdown(int k)
{
  if (neg[k]!=0)
  {
    int lc=k*2+1,rc=k*2+2;
    neg[lc]^=1;neg[rc]^=1;
    swap(minv[lc],maxv[lc]);
    minv[lc]=-minv[lc];maxv[lc]=-maxv[lc];
    swap(minv[rc],maxv[rc]);
    minv[rc]=-minv[rc];maxv[rc]=-maxv[rc];
    neg[k]=0;
  }
}

inline void pushup(int k)
{
  int lc=k*2+1,rc=k*2+2;
  minv[k]=min(minv[lc],minv[rc]);
  maxv[k]=max(maxv[lc],maxv[rc]);
}

void update(int p,int v,int k,int l,int r)
{
  if (l+1==r)
  {
    minv[k]=maxv[k]=v;
    return ;
  }

  pushdown(k);

  int m=l+r>>1;
  if (p<m) update(p,v,k*2+1,l,m);
  else update(p,v,k*2+2,m,r);

  pushup(k);
}

void negated(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return ;
  if (a<=l && r<=b)
  {
    neg[k]^=1;
    swap(minv[k],maxv[k]);
    minv[k]=-minv[k];
    maxv[k]=-maxv[k];
    return ;
  }

  pushdown(k);

  negated(a,b,k*2+1,l,l+r>>1);
  negated(a,b,k*2+2,l+r>>1,r);

  pushup(k);
}

int query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return -INF;
  if (a<=l && r<=b) return maxv[k];
  pushdown(k);

  return max(query(a,b,k*2+1,l,l+r>>1),query(a,b,k*2+2,l+r>>1,r));
}

void update(int x,int y)
{
  while (top[x]!=top[y])
  {
    if (dep[top[x]]>dep[top[y]]) swap(x,y);
    negated(pos[top[y]],pos[y]+1,0,1,cnt);
    y=fa[top[y]];
  }
  if (x!=y)
  {
    if (dep[x]>dep[y]) swap(x,y);
    negated(pos[son[x]],pos[y]+1,0,1,cnt);
  }
}

int query(int x,int y)
{
  int res=-INF;
  while (top[x]!=top[y])
  {
    if (dep[top[x]]>dep[top[y]]) swap(x,y);
    res=max(res,query(pos[top[y]],pos[y]+1,0,1,cnt));
    y=fa[top[y]];
  }
  if (x!=y)
  {
    if (dep[x]>dep[y]) swap(x,y);
    res=max(res,query(pos[son[x]],pos[y]+1,0,1,cnt));
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

  while (T_T--)
  {
    int n;
    scanf("%d",&n);

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,u,v,w;i<n;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      edge[i]={u,v,w};
      add_edge(u,v);
      add_edge(v,u);
    }

    memset(neg,0,sizeof neg);
    cnt=0;
    dfs(1,-1,0);
    build(1,1);
    for (int i=1;i<n;i++)
    {
      if (dep[edge[i].u]>dep[edge[i].v]) edge[i].swap();
      update(pos[edge[i].v],edge[i].w,0,1,cnt);
    }

    while (scanf("%s",cmd)==1 && cmd[0]!='D')
    {
      int x,y;
      scanf("%d%d",&x,&y);
      switch (cmd[0])
      {
        case 'C':update(pos[edge[x].v],y,0,1,cnt);
                 break;
        case 'N':update(x,y);
                 break;
        case 'Q':printf("%d\n",query(x,y));
                 break;
      }
    }
  }



  return 0;
}
