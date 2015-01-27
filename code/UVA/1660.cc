/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 27 Jan 2015 08:47:26 PM CST
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

#define maxm 55555
#define maxn 55<<1

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int iter[maxn],lv[maxn],q[maxn];

pair<int,int> edge[maxm];

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
  int f,r;
  memset(lv,-1,sizeof lv);
  lv[s]=0;
  q[r=f=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e]) if (cap[e]>flow[e] && lv[v[e]]<0)
    {
      lv[v[e]]=lv[x]+1;
      q[++r]=v[e];
    }
  }

  return lv[t]!=-1;
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
    memcpy(iter,fir,sizeof fir);
    int f;
    while ((f=dinic_dfs(s,t,INF))>0) total_flow+=f;
  }

  return total_flow;
}

inline int test(int u,int v,int n,int m)
{
  e_max=0;
  memset(fir,-1,sizeof fir);

  auto in=[&n](int i){return i;};
  auto out=[&n](int i){return i+n;};

  for (int i=0;i<n;i++) add_edge(in(i),out(i),1);
  for (int i=0,a,b;i<m;i++)
  {
    a=edge[i].first;b=edge[i].second;
    add_edge(out(a),in(b),INF);
    add_edge(out(b),in(a),INF);
  }
  int s=n<<1,t=s+1;
  add_edge(s,out(u),INF);
  add_edge(in(v),t,INF);
  
  return max_flow(s,t);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;

  while (scanf("%d%d",&n,&m)==2)
  {
    for (int i=0,u,v;i<m;i++)
    {
      scanf(" (%d,%d)",&u,&v);
      edge[i]={u,v};
    }

    int res=n;
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++)
      res=min(res,test(i,j,n,m));
    printf("%d\n",res);
  }



  return 0;
}
