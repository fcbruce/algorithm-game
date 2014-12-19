/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-23 13:05:02 
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

#define maxm 23333
#define maxn 233

using namespace std;

int fir[maxn],deg[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int n;

void
add_edge(int _u,int _v)
{
  int e=e_max++;
  u[e]=_u;v[e]=_v;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

int st[maxn];

void
topo_sort()
{
  int top=-1;
  for (int i=1;i<=n;i++)
    if (deg[i]==0) st[++top]=i;
  
  for (int i=0;i<n;i++)
  {
    int x=st[top--];
    
    if (i) putchar(' ');
    printf("%d",x);
    
    for (int e=fir[x];~e;e=nex[e])
      if (--deg[v[e]]==0) st[++top]=v[e];
  }
  
  putchar('\n');
}


int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  scanf("%d",&n);
  
  e_max=0;
  memset(fir,-1,sizeof fir);
  memset(deg,0,sizeof deg);
  
  for (int i=1,x;i<=n;i++)
  {
    while (scanf("%d",&x),x)
    {
      add_edge(i,x);
      deg[x]++;
    }
  }
  
  topo_sort();
  
  return 0;
}



