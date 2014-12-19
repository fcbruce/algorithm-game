/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 28 Oct 2014 12:07:09 PM CST
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

#define maxm 80808
#define maxn 404

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int lv[maxn],iter[maxn],q[maxn];

char matrix[maxn][maxn];

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

  for (int &e=iter[s];~e;e=nex[e])
  {
    if (cap[e]>flow[e] && lv[v[e]]>lv[s])
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
  memset(flow,0,sizeof flow);
  int total_flow=0;

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

  int n;
  
  while (scanf("%d",&n)==1)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);
    for (int i=0;i<n;i++)
    {
      scanf("%s",matrix[i]);
      for (int j=0;j<n;j++)
        if (matrix[i][j]=='U') add_edge(i,j+n,1);
    }

    int s=n<<1,t=s+1;

    for (int i=0;i<n;i++)
    {
      add_edge(s,i,1);
      add_edge(i+n,t,1);
    }

    if (max_flow(s,t)==n) puts("YES");
    else puts("NO");
  }


  return 0;
}
