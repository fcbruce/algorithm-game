/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 07 Aug 2015 04:19:11 PM CST
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

#define maxm 40007
#define maxn 20007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int n;

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int size[maxn];

int res,that;

void dfs(int s,int f)
{
  int subsize=0;
  size[s]=1;

  for (int e=fir[s];~e;e=nex[e]) if (f!=v[e])
  {
    dfs(v[e],s);
    size[s]+=size[v[e]];
    subsize=max(subsize,size[v[e]]);
  }

  subsize=max(subsize,n-size[s]);

  if (subsize<res)
  {
    res=subsize;
    that=s;
  }
  else if (subsize == res && s < that)
  {
    that=s;
  }
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
    scanf("%d",&n);

    e_max=0;
    memset(fir,-1,sizeof fir);

    for (int i=1,u,v;i<n;i++)
    {
      scanf("%d%d",&u,&v);
      add_edge(u,v);
      add_edge(v,u);
    }

    res=INF;

    dfs(1,-1);

    printf("%d %d\n",that,res);
  }



  return 0;
}
