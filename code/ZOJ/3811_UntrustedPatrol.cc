/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 28 Apr 2015 08:39:57 PM CST
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
int u[maxm],v[maxm],nex[maxm];
int e_max;

int cnt;

bool install[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int pre[maxn];

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

inline bool same(int u,int v)
{
  return root(u)==root(v);
}

inline void merge(int u,int v)
{
  if (same(u,v)) return ;
  pre[root(u)]=root(v);
  cnt--;
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
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);

    cnt=n;
    for (int i=1;i<=n;i++) pre[i]=i;

    memset(install,0,sizeof install);
    for (int i=0,v;i<k;i++)
    {
      scanf("%d",&v);
      install[v]=true;
    }

    e_max=0;
    memset(fir,-1,sizeof fir);
    for (int i=0;i<m;i++)
    {
      int u,v;
      scanf("%d%d",&u,&v);
      if (!install[u] && !install[v]) merge(u,v);
      else
      {
        add_edge(u,v);
        add_edge(v,u);
      }
    }

    int l;
    scanf("%d",&l);

    int last=-1;
    bool ok=true;

    for (int i=0;i<l;i++)
    {
      int s;
      scanf("%d",&s);

      if (!ok) continue;

      for (int e=fir[s];~e;e=nex[e])
        if (!install[v[e]]) merge(s,v[e]);

      if (~last) ok=same(last,s);

      install[s]=false;
      last=s;
    }

    if (cnt!=1) ok=false;

    puts(ok?"Yes":"No");
  }

  return 0;
}
