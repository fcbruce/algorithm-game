/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 29 Jan 2015 08:56:27 PM CST
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
#define maxn 207

using namespace std;

int fir[maxn];
itn u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int iter[maxn],lv[maxn],q[maxn];

int a[maxn];
bool b[maxn];
char G[maxn][maxn];

void add_edge(itn s,int t,int c)
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
    itn f;
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
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++) scanf("%d",a+i);

    for (int i=0;i<n;i++) scanf("%s",G[i]);

    memset(b,0,sizeof b);
    for (int i=0;i<n;i++) if (a[i]<=0) for (int j=0;j<n;j++) if (G[i][j]=='Y') b[j]=true;

    int l=1,r=100*n;
    int res=1;
    int s=0,t=n+n+1;

    auto X=[&](int i){return i+1;};
    auto Y=[&](int i){return i+1+n;};

    while (l<=r)
    {
      int mid=l+r>>1;

      e_max=0;
      memset(fir,-1,sizeof fir);

      int full_flow=0;

      for (int i=0;i<n;i++) if (a[i]>0)
      {
        add_edge(s,X(i),a[i]);
        for (int j=0;j<n;j++) if (a[j]>0 && G[i][j]=='Y') add_edge(X(i),Y(j),INF);
        add_edge(X(i),Y(i),INF);

        int f=1;
        if (b[i]) f=mid;

        add_edge(Y(i),t,f);

        full_flow+=f;
      }

      if (max_flow(s,t)==full_flow)
      {
        res=mid;
        l=mid+1;
      }
      else
        r=mid-1;
    }

    printf("%d\n",res);
  }

  return 0;
}
