/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 14 Oct 2014 03:00:16 PM CST
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

#define maxm 50007
#define maxn 10007

using namespace std;

int n,m;
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int pre[maxn],low[maxn],sccno[maxn],w[maxn];
int st[maxn],top;
int scc_cnt,dfs_clock;

int deg[maxn];

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
      if (sccno[t]==0)
        low[s]=min(low[s],pre[t]);
    }
  }

  if (pre[s]==low[s])
  {
    scc_cnt++;
    for (;;)
    {
      int x=st[top--];
      sccno[x]=scc_cnt;
      w[scc_cnt]++;
      if (x==s) break;
    }
  }
}

void find_scc()
{
  top=-1;
  scc_cnt=dfs_clock=0;
  memset(pre,0,sizeof pre);
  memset(low,0,sizeof low);
  memset(w,0,sizeof w);
  for (int i=1;i<=n;i++)
    if (pre[i]==0) tarjan_dfs(i);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d%d",&n,&m);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int e=0,u,v;e<m;e++)
  {
    scanf("%d%d",&u,&v);
    add_edge(u,v);
  }

  find_scc();

  memset(deg,0,sizeof deg);

  for (int e=0;e<e_max;e++)
  {
    if (sccno[u[e]]==sccno[v[e]]) continue;
    deg[sccno[u[e]]]++;
  }

  int cnt=0,the_one;

  for (int i=1;i<=scc_cnt;i++)
  {
    if (deg[i]==0)
    {
      cnt++;
      the_one=i;
    }
  }

  if (cnt==1) printf("%d\n",w[the_one]);
  else  puts("0");


  return 0;
}
