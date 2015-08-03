/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 03 Aug 2015 07:53:38 PM CST
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

#define maxm 32007
#define maxn 16007

using namespace std;

int res;

int n;
int cnt;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;

int value[maxn],size[maxn];

inline void add_edge(int s,int t)
{
  int e=e_max++;
  u[e]=s;v[e]=t;
  nex[e]=fir[u[e]];fir[u[e]]=e;
}

void dfs(int s,int fa)
{
  value[s]=0;
  size[s]=1;

  for (int e=fir[s];~e;e=nex[e]) if (v[e]!=fa)
  {
    dfs(v[e],s);
    value[s]=max(value[s],size[v[e]]);
    size[s]+=size[v[e]];
  }

  value[s]=max(value[s],n-size[s]);

  if (res>value[s])
  {
    res=value[s];
    cnt=1;
  }
  else if (res==value[s])
  {
    cnt++;
  }
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
  cnt=0;

  dfs(1,-1);
  
  printf("%d %lu\n",res,cnt);

  bool first=true;
  for (int i=1;i<=n;i++) if (res==value[i])
  {
    if (!first) putchar(' ');
    first=false;
    printf("%d",i);
  }
  puts("");


  return 0;
}
