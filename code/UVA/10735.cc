/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 17 Jan 2015 03:50:22 PM CST
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

#define maxm 5555
#define maxn 1111

using namespace std;

vector<pair<int,int> > u_e,d_e;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int iter[maxn],lv[maxn];
int q[maxm];

int in[maxn],out[maxn];

inline void add_edge(int s,int t,int c)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dinic_bfs(int s)
{
  memset(lv,-1,sizeof lv);
  itn f,r;
  q[f=r=0]=s;
  lv[s]=0;

  while (f<=r)
  {
    int x=q[f++];
    for (itn e=fir[x];~e;e=nex[e])
    {
      if (cap[e]>flow[e] && lv[v[e]]<0)
      {
        lv[v[e]]=lv[x]+1;
        q[++r]=v[e];
      }
    }
  }
}

int dinic_dfs(int s,int t,int f)
{
  if (s==t) return f;
  for (int &e=iter[s];~e;e=nex[e])
  {
    if (cap[e]>flow[e] && lv[u[e]]<lv[v[e]])
    {
      int d=dinic_dfs(v[e],t,min(f,cap[e]-flow[e]));
      if (d>0)
      {
        flow[e]+=d;
        flow[e^1]-=d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s,int t)
{
  int total_flow=0;
  memset(flow,0,sizeof flow);

  for (;;)
  {
    dinic_bfs(s);
    if (lv[t]<0) break;

    memcpy(iter,fir,sizeof fir);
    int f;
    while ((f=dinic_dfs(s,t,INF))>0) total_flow+=f;
  }

  return total_flow;
}

bool vis[maxm];

int st[maxm<<1];
int top;

void dfs(int s)
{
  for (int e=fir[s];~e;e=nex[e])
  {
    if (vis[e]) continue;
    vis[e]=true;
    dfs(v[e]);
    st[++top]=v[e];
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // fcbruce

  bool first=true;
  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    memset(fir,-1,sizeof fir);
    e_max=0;
    u_e.clear();
    d_e.clear();
    memset(in,0,sizeof in);
    memset(out,0,sizeof out);
    
    char c;
    for (int i=0,u,v;i<m;i++)
    {
      scanf("%d%d %c",&u,&v,&c);
      if (c=='U')
      {
        if (rand()&1) swap(u,v);
        u_e.push_back({u,v});
        add_edge(u,v,1);
      }
      else d_e.push_back({u,v});
      out[u]++;in[v]++;
    }

    if (!first) puts("");
    first=false;

    if (![&]()
        {
          for (int i=1;i<=n;i++)
            if (((out[i]-in[i])&1)==1) return false;
          return true;
        }())
    {
      puts("No euler circuit exist");
      continue;
    }

    int s=0,t=n+1,full_flow=0;

    for (int i=1;i<=n;i++)
    {
      if (in[i]>out[i]) add_edge(i,t,in[i]-out[i]>>1);
      else add_edge(s,i,out[i]-in[i]>>1),full_flow+=(out[i]-in[i]>>1);
    }
    
    if (max_flow(s,t)!=full_flow)
    {
      puts("No euler circuit exist");
      continue;
    }

    int e_MAX=e_max;
    memset(fir,-1,sizeof fir);
    e_max=0;
    for (int e=0;e<e_MAX;e+=2)
    {
      if (u[e]==s || v[e]==t) continue;
      if (flow[e]==1) swap(u[e],v[e]);
      add_edge(u[e],v[e]);
    }

    for (auto &e : d_e) add_edge(e.first,e.second);

    top=-1;
    memset(vis,0,sizeof vis);
    dfs(1);
    printf("%d",1);
    while (top>=0) printf(" %d",st[top--]);
    puts("");
  }


  return 0;
}
