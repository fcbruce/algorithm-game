/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Aug 2015 03:19:34 PM CST
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

#define maxm 2000007
#define maxn 1000007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

long long d[maxn];
int q[maxn];
bool vis[maxn];

int q1[maxn],q2[maxn];
long long farest[maxn];

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

  int n,m;

  scanf("%d%d",&n,&m);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int i=2,v,w;i<=n;i++)
  {
    scanf("%d%d",&v,&w);
    add_edge(i,v,w);
    add_edge(v,i,w);
  }

  memset(farest,0,sizeof farest);

  bfs(1);
  int s=max_element(d+1,d+n+1)-d;
  bfs(s);
  int t=max_element(d+1,d+n+1)-d;
  for (int i=1;i<=n;i++) farest[i]=max(farest[i],d[i]);
  bfs(t);
  for (int i=1;i<=n;i++) farest[i]=max(farest[i],d[i]);

  int f1,f2,r1,r2;
  f1=f2=0;r1=r2=-1;

  int res=0;

  int last1=0,last2=0;
  for (int i=1;i<=n;i++)
  {
    while (f1<=r1 && farest[q1[r1]]>farest[i]) r1--;
    q1[++r1]=i;

    while (f2<=r2 && farest[q2[r2]]<farest[i]) r2--;
    q2[++r2]=i;

    while (f1<=r1 && f2<=r2 && farest[q2[f2]]-farest[q1[f1]]>m)
    {
      if (q2[f2]<q1[f1]) last2=q2[f2++];
      else last1=q1[f1++];
    }

    if (f1<=r1 && f2<=r2 && farest[q2[f2]]-farest[q1[f1]]<=m)
      res=max(res,i-max(last1,last2));
  }

  printf("%d\n",res);

  return 0;
}
