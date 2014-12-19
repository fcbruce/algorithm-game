/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 15 Oct 2014 04:01:39 PM CST
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

#define maxm 4000007
#define maxn 2333

using namespace std;

int n,m;
int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int low[maxn],pre[maxn],sccno[maxn];
int st[maxn],top;
int scc_cnt,dfs_clock;

//u<<1 ~u  u<<1|1 u
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
      if (x==s) break;
    }
  }
}

void find_scc()
{
  top=-1;
  scc_cnt=dfs_clock=0;
  memset(sccno,0,sizeof sccno);
  memset(pre,0,sizeof pre);
  for (int i=0;i<n<<1;i++)
    if (pre[i]==0) tarjan_dfs(i);
}

bool check()
{
  for (int i=0;i<n;i++)
    if (sccno[i<<1]==sccno[i<<1|1]) return false;
  
  return true;
}

char op[5];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d%d",&n,&m);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int i=0,u,v,res;i<m;i++)
  {
    scanf("%d%d%d %s",&u,&v,&res,op);

    if (op[0]=='A')
    {
      if (res==1) // u and v = 1 : ~u->u and ~v->v
      { 
        add_edge(u<<1,u<<1|1);
        add_edge(v<<1,v<<1|1);
      }
      else  // u and v = 0 : u->~v and v->~u
      {
        add_edge(u<<1|1,v<<1);
        add_edge(v<<1|1,u<<1);
      }
    }
    else if (op[0]=='O')
    {
      if (res==1) // u or v = 1 : ~u->v and ~v->u
      {
        add_edge(u<<1,v<<1|1);
        add_edge(v<<1,u<<1|1);
      }
      else  // u or v =0 : u->~u and v->~v
      {
        add_edge(u<<1|1,u<<1);
        add_edge(v<<1|1,v<<1);
      }
    }
    else
    {
      if (res==1) // u xor v = 1 : u<->~v and v<->~u
      {
        add_edge(u<<1,v<<1|1);
        add_edge(u<<1|1,v<<1);
        add_edge(v<<1,u<<1|1);
        add_edge(v<<1|1,u<<1);
      }
      else  // u xor v = 0 : u<->v and ~u<->~v
      {
        add_edge(u<<1,v<<1);
        add_edge(v<<1,u<<1);
        add_edge(u<<1|1,v<<1|1);
        add_edge(v<<1|1,u<<1|1);
      }
    }
  }

  find_scc();

  if (check())
    puts("YES");
  else
    puts("NO");

  return 0;
}
