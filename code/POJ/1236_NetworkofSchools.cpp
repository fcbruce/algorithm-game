/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 14 Oct 2014 10:35:57 AM CST
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

#define maxm 10007
#define maxn 107

using namespace std;

int n,m;
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int sccno[maxn],low[maxn],pre[maxn];
int st[maxn],top;
int scc_cnt,dfs_clock;

int ind[maxn],outd[maxn];

inline void add_edge(int _u,int _v)
{
  int e=e_max++;
  u[e]=_u;v[e]=_v;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void tarjan_dfs(int _u)
{
  pre[_u]=low[_u]=++dfs_clock;
  st[++top]=_u;
  for (int e=fir[_u];~e;e=nex[e])
  {
    int _v=v[e];
    if (pre[_v]==0)
    {
      tarjan_dfs(_v);
      low[_u]=min(low[_v],low[_u]);
    }
    else
    {
      if (sccno[_v]==0)
        low[_u]=min(low[_u],pre[_v]);
    }
  }

  if (low[_u]==pre[_u])
  {
    scc_cnt++;
    for (;;)
    {
      int x=st[top--];
      sccno[x]=scc_cnt;
      if (x==_u) break;
    }
  }

}

void find_scc()
{
  top=-1;
  scc_cnt=dfs_clock=0;
  memset(sccno,0,sizeof sccno);
  memset(pre,0,sizeof pre);
  for (int i=1;i<=n;i++)
    if (pre[i]==0) tarjan_dfs(i);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d",&n);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int i=1,v;i<=n;i++)
    while (scanf("%d",&v),v!=0) add_edge(i,v);
  
  find_scc();

  if (scc_cnt==1)
  {
    printf("1\n0\n");
    return 0;
  }

  memset(ind,0,sizeof ind);
  memset(outd,0,sizeof outd);

  for (int e=0;e<e_max;e++)
  {
    if (sccno[u[e]]==sccno[v[e]]) continue;
    outd[sccno[u[e]]]++;
    ind[sccno[v[e]]]++;
  }

  int in0=0,out0=0;

  for (int i=1;i<=scc_cnt;i++)
  {
    if (ind[i]==0) in0++;
    if (outd[i]==0) out0++;
  }

  printf("%d\n%d\n",in0,max(out0,in0));


  return 0;
}
