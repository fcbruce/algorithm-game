/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 28 Jan 2015 06:10:22 PM CST
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
#define maxn 2333

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],cap[maxm],flow[maxm],nex[maxm];
int e_max;

int iter[maxn],lv[maxn],q[maxn];

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

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;

  char str[23];
  vector<int> v;


  while (scanf("%d%d",&n,&m),n!=0 && m!=0)
  {
    v.clear();
    for (int i=0;i<m;i++)
    {
      scanf("%s",str);
      int id=0;
      for (int j=0;j<n;j++)
        if (str[j]=='1') id|=1<<j;
      v.push_back(id);
      for (int j=0;j<n;j++) if (str[j]=='*')
      {
        id|=1<<j;
        v.push_back(id);
        break;
      }
    }
    sort(v.begin(),v.end());
    auto vs=unique(v.begin(),v.end())-v.begin();

    auto X=[&vs](int i){return i+1;};
    auto Y=[&vs](int i){return i+1+vs;};

    int s=0,t=vs+vs+1;

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0;i<vs;i++)
    {
      add_edge(s,X(i),1);
      add_edge(Y(i),t,1);
    }

    for (int i=0;i<vs;i++) for (int j=0;j<vs;j++) if (i!=j)
    {
      int diff=v[i]^v[j];
      if ((diff & -diff) == diff)
      {
        add_edge(X(i),Y(j),1);
        add_edge(X(j),Y(i),1);
      }
    }

    printf("%d\n",vs-max_flow(s,t)/2);
  }

  return 0;
}
