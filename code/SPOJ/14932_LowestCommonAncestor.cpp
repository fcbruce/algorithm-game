/*
 *
 * Author : fcbruce
 *
 * Time : Fri 03 Oct 2014 11:33:30 AM CST
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

const int maxn_log = 11;

int fir[maxn];
int u[maxn],v[maxn],nex[maxn];
int e_max;

bool not_root[maxn];

int parent[maxn_log][maxn];
int depth[maxn];

inline void add_edge(int _u,int _v)
{
  int e=e_max++;
  u[e]=_u;v[e]=_v;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs_lca(int _v,int p,int d)
{
  parent[0][_v]=p;
  depth[_v]=d;

  for (int e=fir[_v];~e;e=nex[e])
    dfs_lca(v[e],_v,d+1);
}

void init_lca(int root,int n)
{
  dfs_lca(root,-1,0);

  for (int k=0;k+1<maxn_log;k++)
    for (int v=1;v<=n;v++)
      if (parent[k][v]<0)
        parent[k+1][v]=-1;
      else
        parent[k+1][v]=parent[k][parent[k][v]];
}

int lca(int u,int v)
{
  if (depth[u]>depth[v]) swap(u,v);
  for (int k=0;k<maxn_log;k++)
    if (depth[v]-depth[u]>>k&1)
      v=parent[k][v];

  if (u==v) return u;

  for (int k=maxn_log-1;k>=0;k--)
    if (parent[k][u]!=parent[k][v])
    {
      u=parent[k][u];
      v=parent[k][v];
    }

  return parent[0][u];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);
    memset(not_root,0,sizeof not_root);

    int n;
    scanf("%d",&n);

    for (int i=1,m;i<=n;i++)
    {
      scanf("%d",&m);
      for (int j=0,v;j<m;j++)
      {
        scanf("%d",&v);
        add_edge(i,v);
        not_root[v]=true;
      }
    }

    int root;
    for (int i=1;i<=n;i++)
      if (!not_root[i])
      {
        root=i;
        break;
      }

    init_lca(root,n);

    int q;
    scanf("%d",&q);
    
    printf("Case %d:\n",++__);
    while (q--)
    {
      int u,v;
      scanf("%d%d",&u,&v);

      printf("%d\n",lca(u,v));
    }
  }


  return 0;
}
