/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 26 Jan 2015 06:10:35 PM CST
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

#define maxm 199655
#define maxn 8964

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int lv[maxn],iter[maxn];
int q[maxm<<3];

char G[55][55];

inline void add_edge(int s,int t,int c)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

void dinic_bfs(int s)
{
  int f,r;
  memset(lv,-1,sizeof lv);
  lv[s]=0;
  q[f=r=0]=s;
  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e])
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
  for (int &e=iter[s];~e;e=nex[e]) if (cap[e]>flow[e] && lv[v[e]]>lv[s])
  {
    int d=dinic_dfs(v[e],t,min(f,cap[e]-flow[e]));
    if (d>0)
    {
      flow[e]+=d;
      flow[e^1]-=d;
      return d;
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
    while ((f=dinic_dfs(s,t,INF))>0)
      total_flow+=f;
  }

  return total_flow;
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
    e_max=0;
    memset(fir,-1,sizeof fir);

    int n,m,d,f,b;
    scanf("%d%d",&m,&n);
    scanf("%d%d%d",&d,&f,&b);

    int s=0,t=n*m+1,res=0;
    
    auto id=[&n,&m](int i,int j){return (i-1)*m+j;};

    for (int i=1;i<=n;i++)
      scanf("%s",G[i]+1);

    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
    {
      if (i!=1 && j!=1)
      {
        add_edge(id(i,j),id(i-1,j),b);
        add_edge(id(i,j),id(i,j-1),b);
        add_edge(id(i-1,j),id(i,j),b);
        add_edge(id(i,j-1),id(i,j),b);
      }

      if (i==1 || i==n || j==1 || j==m) 
      {
        if (G[i][j]=='.')
          res+=f; 
        add_edge(s,id(i,j),INF);
        continue;
      }

      if (G[i][j]=='.') add_edge(id(i,j),t,f);
      else add_edge(s,id(i,j),d);
    }

    printf("%d\n",res+max_flow(s,t));
  }



  return 0;
}
