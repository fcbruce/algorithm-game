/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 29 Jan 2015 12:19:51 PM CST
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
#define maxn 23333

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int iter[maxn],lv[maxn],q[maxn];

pair<int,int> poi[maxn],obs[maxn];
int X[107][107],Y[107][107],G[107][107];

inline void add_edge(int s,int t,int c)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
}

bool dinic_bfs(int s,int t)
{
  itn f,r;
  memset(lv,-1,sizeof lv);
  lv[s]=0;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e]) if (cap[e]>flow[e] && lv[v[e]]<0)
    {
      lv[v[e]]=lv[x]+1;
      q[++r]=v[e];
    }
  }

  return lv[t]>=0;
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

  while (dinic_bfs(s,t))
  {
    int f;
    memcpy(iter,fir,sizeof fir);
    while ((f=dinic_dfs(s,t,INF))>0) total_flow+=f;
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
    int n,m;
    scanf("%d%d",&n,&m);

    memset(G,0,sizeof G);

    int P;
    scanf("%d",&P);
    for (int i=0,x,y;i<P;i++)
    {
      scanf("%d%d",&x,&y);
      poi[i]={--x,--y};
      G[x][y]=1;
    }

    int W;
    scanf("%d",&W);
    for (int i=0,x,y;i<W;i++)
    {
      scanf("%d%d",&x,&y);
      obs[i]={--x,--y};
      G[x][y]=-1;
    }

    int r=0,c=0;
    for (int i=0;i<n;i++,r++) for (itn j=0;j<m;j++)
    {
      if (G[i][j]==-1)
        r++;
      else
        X[i][j]=r;
    }
    for (int j=0;j<n;j++,c++) for (int i=0;i<n;i++)
    {
      if (G[i][j]==-1)
        c++;
      else
        Y[i][j]=c;
    }

    auto _x=[&r,&c](int i){return i+1;};
    auto _y=[&r,&c](int i){return i+1+r;};

    int s=0,t=r+c+1;
    e_max=0;
    memset(fir,-1,sizeof  fir);
    for (int i=0;i<r;i++) add_edge(s,_x(i),1);
    for (int i=0;i<c;i++) add_edge(_y(i),t,1);

    for (int i=0;i<P;i++)
    {
      int x=poi[i].first,y=poi[i].second;
      add_edge(_x(X[x][y]),_y(Y[x][y]),1);
    }

    printf("%d\n",max_flow(s,t));
  }



  return 0;
}
