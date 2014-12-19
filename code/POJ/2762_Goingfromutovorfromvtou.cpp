/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 14 Oct 2014 11:37:19 AM CST
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

#define maxm 8964
#define maxn 1007

using namespace std;

int n,m;
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int pre[maxn],low[maxn],sccno[maxn];
int st[maxn],top;
int scc_cnt,dfs_clock;

int deg[maxn];

inline void add_edge(int _u,int _v)
{
  int e=e_max++;
  u[e]=_u;v[e]=_v;
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

  if (low[s]==pre[s])
  {
    scc_cnt++;
    for (;;)
    {
      int x=st[top--];
      sccno[x]=scc_cnt;
      if (x==s) break;
    }
  }
}

void find_scc()
{
  scc_cnt=dfs_clock=0;
  top=-1;
  memset(sccno,0,sizeof sccno);
  memset(pre,0,sizeof pre);
  for (int i=1;i<=n;i++)
    if (pre[i]==0)  tarjan_dfs(i);
}

bool unique_toposort()
{
  top=-1;
  for (int i=1;i<=scc_cnt;i++)
  {
    if (deg[i]==0) st[++top]=i;
  }

  for (int i=0;i<scc_cnt;i++)
  {
    if (top==1 || top==-1) return false;
    int x=st[top--];
    for (int e=fir[x];~e;e=nex[e])
    {
      deg[v[e]]--;
      if (deg[v[e]]==0) st[++top]=v[e];
    }
  }

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

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0,u,v;i<m;i++)
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v);
    }

    find_scc();

    int temp=e_max;
    e_max=0;
    memset(fir,-1,sizeof fir);
    memset(deg,0,sizeof deg);
    for (int e=0;e<temp;e++)
    {
      if (sccno[u[e]]==sccno[v[e]]) continue;
      deg[sccno[v[e]]]++;
      add_edge(sccno[u[e]],sccno[v[e]]);
    }

    if (unique_toposort())
      puts("Yes");
    else
      puts("No");
    
  }
  


  return 0;
}
