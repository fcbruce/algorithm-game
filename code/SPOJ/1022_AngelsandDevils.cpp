/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 01 Nov 2014 05:49:46 PM CST
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

#define maxm 433333
#define maxn 90909

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int lv[maxn],iter[maxn],q[maxn];
int n,m;
int LAST[303];
char G[303][303];

inline void add_edge(int s,int t,int c)
{
  int &e=e_max;
  u[e]=s;v[e]=t;cap[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  u[e]=t;v[e]=s;cap[e]=0;
  nex[e]=fir[u[e]];fir[u[e]]=e++;
  if (e>maxm) for (;;);
}

inline int idx(int a,int b)
{
  return a*m+b;
}

void dinic_bfs(int s)
{
  memset(lv,-1,sizeof lv);
  int f,r;
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
    if (cap[e]>flow[e] && lv[s]<lv[v[e]])
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
    //printf("%d\n",total_flow);
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
    scanf("%d%d",&n,&m);

    for (int i=0;i<n;i++)
      for (int j=0;j<m;j++)
        scanf(" %c",&G[i][j]);

    int s=n*m,t=s+1;
    e_max=0;
    memset(fir,-1,sizeof fir);

    memset(LAST,-1,sizeof LAST);
    for (int i=0;i<n;i++)
    {
      int last=-1;
      for (int j=0;j<m;j++)
      {
        if (G[i][j]=='H')
        {
          if (LAST[j]!=-1)
            add_edge(idx(LAST[j],j),idx(i,j),1);
          if (last!=-1)
            add_edge(idx(i,last),idx(i,j),1);
          else
            add_edge(s,idx(i,j),1);
          LAST[j]=i;
          last=j;
        }
        else if (G[i][j]=='A')
        {
          if (LAST[j]!=-1)
            add_edge(idx(LAST[j],j),t,1);
          if (last!=-1);
          //  add_edge(idx(i,last),t,1);
          //add_edge(s,t,1);
          LAST[j]=last=-1;
        }
      }
    }

    for (int i=0;i<m;i++)
      if (LAST[i]!=-1)
        add_edge(idx(LAST[i],i),t,1);

    printf("%d\n",max_flow(s,t));
  }


  return 0;
}
