/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 18 Jan 2015 07:22:13 PM CST
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

#define maxm 50007
#define maxn 307

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],a[maxm],b[maxm],nex[maxm];
int e_max;

long long d[maxn];
bool inq[maxn];
int q[maxm<<3];

inline void add_edge(int s,int t,int _a,int _b,int d)
{
  int e=e_max++;
  u[e]=s;v[e]=t;w[e]=d;a[e]=_a;b[e]=_b;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA(int s)
{
  memset(d,0x3f,sizeof d);
  memset(inq,0,sizeof inq);
  int f,r;
  q[f=r=0]=s;
  d[s]=0;

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      int td=[](int e)
      {
        int k=a[e]+b[e];
        int r=d[u[e]]%k;
        if (r+w[e]<=a[e]) return d[u[e]]+w[e];
        return d[u[e]]+k-r+w[e];
      }(e);
      if (d[v[e]]>td)
      {
        d[v[e]]=td;
        if (!inq[v[e]])
        {
          inq[v[e]]=true;
          q[++r]=v[e];
        }
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;
  int n,m,s,t;
  
  while (scanf("%d%d%d%d",&n,&m,&s,&t)==4)
  {
    memset(fir,-1,sizeof fir);
    e_max=0;

    for (int i=0,u,v,a,b,t;i<m;i++)
    {
      scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
      if (t<=a) add_edge(u,v,a,b,t);
    }

    SPFA(s);
    printf("Case %d: %lld\n",++__,d[t]);
  }

  return 0;
}
