/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 22 Jul 2015 04:29:07 PM CST
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

#define maxm 100007
#define maxn 10007

using namespace std;

const long long mod = 10000000000ll;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;

vector<pair<int,int> > save;

long long from[maxn],to[maxn];

int deg[maxn];

int d[maxn];
int q[maxm<<3];
bool inq[maxn];

int topo[maxn];

inline long long add(long long lhs,long long rhs)
{
  return (lhs+rhs) % mod;
}

inline long long multi(long long lhs,long long rhs)
{
  long long lhs1=lhs%100000;
  lhs/=100000;
  long long rhs1=rhs%100000;
  rhs/=100000;
  return (((lhs*rhs1)+(rhs*lhs1))*100000+lhs1*rhs1)%mod;
}

inline void add_edge(int s,int t,int c=0)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=c;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
  int f,r;
  memset(inq,0,sizeof inq);
  memset(d,0x3f,sizeof d);
  d[s]=0;
  q[f=r=0]=s;
  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (d[v[e]]>d[u[e]]+w[e])
      {
        d[v[e]]=d[u[e]]+w[e];
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

int toposort(int n)
{
  int f=0,r=-1;
  memset(deg,0,sizeof deg);
  for (int e=0;e<e_max;e++) deg[v[e]]++;
  q[++r]=0;
  
  for (int i=0;i<n;i++)
  {
    if (f>r) return i;
    int x=topo[i]=q[f++];
    for (int e=fir[x];~e;e=nex[e])
    {
      from[v[e]]=add(from[v[e]],from[u[e]]);
      if (--deg[v[e]]==0) q[++r]=v[e];
    }
  }
  return n;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m,q;

  while (scanf("%d%d%d",&n,&m,&q)==3)
  {
    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=0,u,v,w;i<m;i++)
    {
      scanf("%d%d%d",&u,&v,&w);
      add_edge(u,v,w);
    }

    SPFA(0);

    memset(from,0,sizeof from);
    from[0]=1;
    fill(to,to+n,1);

    save.clear();
    for (int e=0;e<e_max;e++)
      if (d[v[e]]==d[u[e]]+w[e]) save.push_back({u[e],v[e]});

    e_max=0;
    memset(fir,-1,sizeof fir);
    for (auto e : save) add_edge(e.first,e.second);

    n=toposort(n);

    for (int i=n-1;i>=0;i--)
    {
      int x=topo[i];
      for (int e=fir[x];~e;e=nex[e])
        to[u[e]]=add(to[u[e]],to[v[e]]);
    }

    while (q--)
    {
      int x;
      scanf("%d",&x);
      printf("%010lld\n",multi(from[x],to[x]));
    }
  }



  return 0;
}
