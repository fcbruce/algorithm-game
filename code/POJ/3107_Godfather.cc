/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 09 Aug 2015 09:49:59 AM CST
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
#define maxn 50007

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int res;

int n;

int size[maxn],value[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int f)
{
  size[s]=1;
  value[s]=0;
  
  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=f)
  {
    dfs(v[e],s);
    size[s]+=size[v[e]];
    value[s]=max(value[s],size[v[e]]);
  }
  value[s]=max(value[s],n-size[s]);

  res=min(res,value[s]);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  e_max=0;
  memset(fir,-1,sizeof fir);

  scanf("%d",&n);

  for (int i=1,u,v;i<n;i++)
  {
    scanf("%d%d",&u,&v);
    add_edge(u,v);
    add_edge(v,u);
  }

  res=INF;
  dfs(1,-1);

  bool first=true;
  for (int i=1;i<=n;i++) if (value[i]==res)
  {
    if (!first) putchar(' ');
    first=false;
    printf("%d",i);
  }
  puts("");


  return 0;
}
