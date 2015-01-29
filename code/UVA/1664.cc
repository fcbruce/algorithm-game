/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 29 Jan 2015 10:28:58 PM CST
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

#define maxm 
#define maxn 200007

using namespace std;

int pre[maxn],size[maxn];
long long cap[maxn];

struct edge
{
  int u,v;
  long long w;
  void read()
  {
    scanf("%d%d" lld,&u,&v,&w);
  }
}e[maxn];

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

void merge(const edge &e)
{
  int rx=root(e.u),ry=root(e.v);
  long long sx=size[rx]*e.w,sy=size[ry]*e.w;

  if (cap[rx]+sy>cap[ry]+sx)
  {
    cap[rx]+=sy;
    size[rx]+=size[ry];
    pre[ry]=rx;
  }
  else
  {
    cap[ry]+=sx;
    size[ry]+=size[rx];
    pre[rx]=ry;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    for (int i=0;i<n-1;i++) e[i].read();
    sort(e,e+n-1,[](const edge &a,const edge &b){return a.w>b.w;});
    for (itn i=1;i<=n;i++)
    {
      pre[i]=i;
      size[i]=1;
      cap[i]=0;
    }
    for (int i=0;i<n-1;i++) merge(e[i]);
    printf(lld "\n",cap[root(1)]);
  }



  return 0;
}
