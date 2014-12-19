/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 14 Oct 2014 10:02:09 AM CST
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

#define maxm 500007
#define maxn 100007

using namespace std;

int n,m;
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int low[maxn],pre[maxn],sccno[maxn];
int st[maxn],top;
int scc_cnt,dfs_clock;

int cnt;

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
      low[_u]=min(low[_u],low[_v]);
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
    int ele_cnt=0;
    for (;;)
    {
      int x=st[top--];
      sccno[x]=scc_cnt;
      ele_cnt++;
      if (x==_u) break;
    }
    if (ele_cnt>1) cnt++;
  }
}

void find_scc()
{
  dfs_clock=scc_cnt=0;
  top=-1;
  memset(sccno,0,sizeof sccno);
  memset(pre,0,sizeof pre);
  for (int i=0;i<n;i++)
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

  for (int i=0,u,v;i<m;i++)
  {
    scanf("%d%d",&u,&v);
    add_edge(u,v);
  }

  cnt=0;

  find_scc();

  printf("%d\n",cnt);

  return 0;
}
