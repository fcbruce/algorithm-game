/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 14 Aug 2015 02:12:37 PM CST
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

int w[maxn];
int size[maxn],dep[maxn],fa[maxn],balance[maxn];
bool vis[maxn];

int q[maxn];

struct record
{
  int root,dep,sudoer;
};

vector<record> records[maxn];

int pool[maxn*40];
int cnt;

struct BIT
{
  int *p;
  int n;
  BIT() {p=NULL;n=0;}
  void init(int size)
  {
    p=pool+cnt;
    n=size;
    cnt+=n;
    fill(p,p+n,0);
  }
  void add(int k,int v)
  {
    for (; k < n; k += ~k & k + 1) p[k] += v;
  }
  int query(int k)
  {
    k = min(k, n - 1);
    int res = 0;
    for (; k >= 0; k -= ~k & k + 1) res += p[k];
    return res;
  }
};

map<int,BIT> bits[maxn];

inline void add_edge(int s, int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void bfs_root(int s,int &root,int n)
{
  int f,r;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x = q[f++];
    size[x] = 1;
    balance[x] = 0;
    for (int e=fir[x];~e;e=nex[e]) if (v[e] != fa[x] && !vis[v[e]])
    {
      fa[v[e]] = x;
      q[++r] = v[e];
    }
  }
  for (int i = r; i >= 0; i--)
  {
    int x = q[i];
    for (int e=fir[x];~e;e=nex[e]) if (v[e] != fa[x] && !vis[v[e]])
    {
      size[x] += size[v[e]];
      balance[x] = max(balance[x], size[v[e]]);
    }
  }
  for (int f = 0; f <= r;)
  {
    int x = q[f++];
    balance[x] = max(balance[x], n - size[x]);
    if (root == -1 || balance[root] > balance[x]) root = x;
  }
}

void solve(int s,int n)
{
  int root=-1;
  bfs_root(s,root,n);

  bits[root][-1].init(n);
  bits[root][-1].add(0,w[root]);
  records[root].push_back((record){root,0,-1});
  vis[root]=true;
  for (int e=fir[root];~e;e=nex[e]) if (!vis[v[e]])
  {
    int f,r;
    q[f=r=0]=v[e];
    fa[v[e]]=root;
    dep[v[e]]=1;
    int deepest=1;
    while (f<=r)
    {
      int x=q[f++];
      for (int e=fir[x];~e;e=nex[e]) if (v[e]!=fa[x] && !vis[v[e]])
      {
        q[++r]=v[e];
        fa[v[e]]=x;
        dep[v[e]]=dep[x]+1;
        deepest = max(deepest, dep[v[e]]);
      }
    }

    bits[root][v[e]].init(deepest + 1);
    for (int f=0;f<=r;)
    {
      int x=q[f++];
      records[x].push_back((record){root,dep[x],v[e]});
      bits[root][-1].add(dep[x],w[x]);
      bits[root][v[e]].add(dep[x],w[x]);
    }

    solve(v[e],size[v[e]]);
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,q;

  while (scanf("%d%d",&n,&q)==2)
  {
    for (int i=1;i<=n;i++) scanf("%d",w+i);

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,u,v;i<n;i++)
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v);
      add_edge(v,u);
    }

    cnt=0;
    for (int i=0;i<=n;i++)
    {
      records[i].clear();
      bits[i].clear();
    }

    memset(vis, false, sizeof vis);
    solve(1,n);

    while (q--)
    {
      char cmd;
      int v,d;
      scanf(" %c%d%d", &cmd, &v, &d);
      if (cmd == '!')
      {
        d-=w[v];
        for (size_t i = 0; i < records[v].size(); i++)
        {
          int root = records[v][i].root;
          int dep = records[v][i].dep;
          int sudoer = records[v][i].sudoer;
          bits[root][-1].add(dep, d);
          if (~sudoer) bits[root][sudoer].add(dep, d);
        }
        w[v]+=d;
      }
      else
      {
        int res = 0;
        for (size_t i = 0; i < records[v].size(); i++) if (records[v][i].dep <= d)
        {
          int root = records[v][i].root;
          int dep = records[v][i].dep;
          int sudoer = records[v][i].sudoer;
          res += bits[root][-1].query(d - dep);
          if (~sudoer) res -= bits[root][sudoer].query(d - dep);
        }
        printf("%d\n",res);
      }
    }
  }



  return 0;
}
