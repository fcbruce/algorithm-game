/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 08 May 2015 11:28:52 AM CST
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

#define maxm 10007
#define maxn 107

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int d[maxn],q[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void toposort(int n)
{
  int f=0,r=-1;

  memset(d,0,sizeof d);
  for (int e=0;e<e_max;e++) d[v[e]]++;

  for (int i=1;i<=n;i++) if (d[i]==0) q[++r]=i;

  for (int i=0;i<n;i++)
  {
    int x=q[f++];
    
    if (i!=0) putchar(' ');
    printf("%d",x);

    for (int e=fir[x];~e;e=nex[e])
    {
      d[v[e]]--;
      if (d[v[e]]==0) q[++r]=v[e];
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  e_max=0;
  memset(fir,-1,sizeof fir);

  for (int i=0,v;i<n;i++)
    while (scanf("%d",&v),v!=0) add_edge(i+1,v);

  toposort(n);

  return 0;
}
