/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 09 Aug 2015 04:24:28 PM CST
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

#define maxm 20007
#define maxn 10007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

int n;

int d[maxn];
bool vis[maxn];
int res[maxn];
int q[maxn];

inline void add_edge(int s,int t,int c)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void bfs(int s)
{
  int f,r;
  memset(vis,0,sizeof vis);
  d[s]=0;
  vis[s]=true;
  q[f=r=0]=s;

  while (f<=r)
  {
    int x=q[f++];
    for (int e=fir[x];~e;e=nex[e]) if (!vis[v[e]])
    {
      d[v[e]]=d[x]+w[e];
      vis[v[e]]=true;
      q[++r]=v[e];
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d",&n)==1)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=2,v,w;i<=n;i++)
    {
      scanf("%d%d",&v,&w);
      add_edge(i,v,w);
      add_edge(v,i,w);
    }

    bfs(1);
    int p=max_element(d+1,d+n+1)-d;
    bfs(p);
    for (int i=1;i<=n;i++) res[i]=d[i];
    p=max_element(d+1,d+n+1)-d;
    bfs(p);
    for (int i=1;i<=n;i++) res[i]=max(res[i],d[i]);

    for (int i=1;i<=n;i++)
      printf("%d\n",res[i]);
  }



  return 0;
}
