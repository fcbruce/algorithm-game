/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Aug 2015 07:42:52 PM CST
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

int cnt;

char cmd[16];

struct Edge
{
  int u,v,w;
}edge[maxn];

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int maxv[maxn<<2];

int size[maxn],fa[maxn],son[maxn],dep[maxn],pos[maxn],top[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int f,int d)
{
  size[s]=1;
  son[s]=-1;
  dep[s]=d;
  fa[s]=f;
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
  for (int e=fir[s];~e;e=nex[e]) if (fa[s]!=v[e] && son[s]!=v[e])
    build(v[e],v[e]);
}

void update(int p,int v,int k,int l,int r)
{
  if (l+1==r)
  {
    maxv[k]=v;
    return ;
  }

  int m=l+r>>1;
  if (p<m) update(p,v,k*2+1,l,m);
  else update(p,v,k*2+2,m,r);

  maxv[k]=max(maxv[k*2+1],maxv[k*2+2]);
}

int query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (a<=l && r<=b) return maxv[k];

  return max(query(a,b,k*2+1,l,l+r>>1),query(a,b,k*2+2,l+r>>1,r));
}

int find(int x,int y)
{
  int fx=top[x],fy=top[y];
  int res=0;

  while (fx!=fy)
  {
    if (dep[fx]>dep[fy])
    {
      swap(x,y);
      swap(fx,fy);
    }

    res=max(res,query(pos[fy],pos[y]+1,0,0,cnt));
    y=fa[fy];
    fy=top[y];
  }

  if (x!=y)
  {
    if (dep[x]>dep[y]) swap(x,y);
    res=max(res,query(pos[son[x]],pos[y]+1,0,0,cnt));
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
    e_max=0;
    memset(fir,-1,sizeof fir);
    memset(maxv,0,sizeof maxv);

    int n;
    scanf("%d",&n);

    for (int i=1,u,v,w;i<n;i++) 
    {
      scanf("%d%d%d",&u,&v,&w);
      edge[i]={u,v,w};
      add_edge(u,v);
      add_edge(v,u);
    }

    cnt=0;
    dfs(1,-1,1);
    build(1,1);
    for (int i=1;i<n;i++)
    {
      if (dep[edge[i].u]>dep[edge[i].v]) swap(edge[i].u,edge[i].v);
      update(pos[edge[i].v],edge[i].w,0,0,cnt);
    }

    while (scanf("%s",cmd)==1 && cmd[0]!='D')
    {
      int x,y;
      scanf("%d%d",&x,&y);
      switch (cmd[0])
      {
        case 'Q':printf("%d\n",find(x,y));
                 break;
        case 'C':update(pos[edge[x].v],y,0,0,cnt);
                 break;
      }
    }
  }



  return 0;
}
