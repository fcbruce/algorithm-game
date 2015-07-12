/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 05 Jul 2015 03:07:35 PM CST
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
#define maxn 10007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
double rate[maxm];
int e_max;

int n;

int q[maxm<<3];
bool inq[maxn];

double p[maxn],w[maxn];

inline int dcmp(double k)
{
  return fabs(k)<eps?0:k>0?1:-1;
}

inline void add_edge(int s,int t,double w)
{
  int e=e_max++;
  u[e]=s;v[e]=t;rate[e]=w;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void SPFA()
{
  int f=0,r=-1;
  for (int i=1;i<=n;i++)
  {
    inq[i]=true;
    q[++r]=i;
  }

  while (f<=r)
  {
    int x=q[f++];
    inq[x]=false;
    for (int e=fir[x];~e;e=nex[e])
    {
      if (dcmp(p[v[e]]-p[u[e]]*rate[e])<0)
      {
        p[v[e]]=p[u[e]]*rate[e];
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

  while (scanf("%d",&n),n!=0)
  {
    for (int i=1;i<=n;i++) scanf("%lf %lf",p+i,w+i);

    int m;
    scanf("%d",&m);

    e_max=0;
    memset(fir,-1,sizeof fir);

    while (m-->0)
    {
      int k,u,v;
      double r;
      scanf("%d",&k);
      scanf("%d",&u);
      for (int i=1;i<k;i++)
      {
        scanf("%lf %d",&r,&v);
        add_edge(v,u,r);
        u=v;
      }
    }

    SPFA();

    double res=0;

    for (int i=1;i<=n;i++) res+=p[i]*w[i];

    printf("%.2f\n",res);
  }



  return 0;
}
