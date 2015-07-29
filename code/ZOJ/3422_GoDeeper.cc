/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 29 Jul 2015 04:33:00 PM CST
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

#define maxm 40404
#define maxn 404

using namespace std;

int n,m;
int a[maxm],b[maxm],c[maxm];

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int col[maxn],pre[maxn],low[maxn];
int dfs_clock,scc_cnt;

int st[maxn];
int top;

inline int pos(int i)
{
  return i;
}

inline int neg(int i)
{
  return i+n;
}

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void tarjan_dfs(int s)
{
  pre[s]=low[s]=++dfs_clock;
  st[++top]=s;
  for (int e=fir[s];~e;e=nex[e])
  {
    int t=v[e];
    if (pre[t]==0)
    {
      tarjan_dfs(t);
      low[s]=min(low[s],low[t]);
    }
    else
    {
      if (col[t]==0)
        low[s]=min(low[s],pre[t]);
    }
  }
  if (low[s]==pre[s])
  {
    scc_cnt++;
    for (;;)
    {
      int x=st[top--];
      col[x]=scc_cnt;
      if (x==s) break;
    }
  }
}

void find_scc()
{
  scc_cnt=dfs_clock=0;
  top=-1;
  memset(col,0,sizeof col);
  memset(pre,0,sizeof pre);
  for (int i=0;i<n+n;i++)
    if (pre[i]==0) tarjan_dfs(i);
}

bool ok(int dep)
{
  e_max=0;
  memset(fir,-1,sizeof fir);
  for (int i=0;i<dep;i++)
  {
    switch (c[i])
    {
      case 0:
        add_edge(neg(a[i]),pos(b[i]));
        add_edge(neg(b[i]),pos(a[i]));
        break;
      case 1:
        add_edge(pos(a[i]),pos(b[i]));
        add_edge(pos(b[i]),pos(a[i]));
        add_edge(neg(a[i]),neg(b[i]));
        add_edge(neg(b[i]),neg(a[i]));
        break;
      case 2:
        add_edge(pos(a[i]),neg(b[i]));
        add_edge(pos(b[i]),neg(a[i]));
        break;
    }
  }

  find_scc();

  for (int i=0;i<n;i++) if (col[pos(i)]==col[neg(i)]) return false;
  return true;
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
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) scanf("%d%d%d",a+i,b+i,c+i);
    int l=0,r=m,res=0;
    while (l<=r)
    {
      int mid=l+r>>1;
      if (ok(mid))
      {
        res=mid;
        l=mid+1;
      }
      else r=mid-1;
    }

    printf("%d\n",res);
  }



  return 0;
}
