/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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

#define maxm 100007
#define maxn 10007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int n,m;

void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int pre[maxn],low[maxn],st[maxn],sccno[maxn];
int dfs_clock,scc_cnt,top;

void tarjan_dfs(int _u)
{
  pre[_u]=low[_u]=++dfs_clock;
  st[++top]=_u;
  for (int e=fir[_u];e!=-1;e=nex[e])
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
    while (true)
    {
      int x=st[top--];
      sccno[x]=scc_cnt;
      if (x==_u) break;
    }
  }
} 

void find_scc()
{
  dfs_clock=scc_cnt=0;
  top=-1;
  memset(sccno,0,sizeof sccno);
  memset(pre,0,sizeof pre);
  for (int i=1;i<=n;i++)
  {
    if (pre[i]==0)  tarjan_dfs(i);
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  while (scanf("%d%d",&n,&m),n||m)
  {
    memset(fir,-1,sizeof fir);
    e_max=0;
    
    for (int i=0,s,t;i<m;i++)
    {
      scanf("%d%d",&s,&t);
      add_edge(s,t);
    
    }
    
    find_scc();
    
    if (scc_cnt==1)puts("Yes");
    else puts("No");
  
  }
  
  
  return 0;
}



