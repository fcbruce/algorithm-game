/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 13 Sep 2015 09:08:49 AM CST
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
#ifdef _WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0);
const double eps = 1e-10;

typedef long long LL;
typedef int itn;

const int maxn = 20007;
const int maxm = 100007;

using namespace std;

int pre[maxn];
int size[maxn];

struct edge
{
  int u,v,w;
  void read()
  {
    scanf("%d%d%d",&u,&v,&w);
  }
  bool operator < (const edge &rhs) const
  {
    return w<rhs.w;
  }
}e[maxm];

long long cnt;

long long res[maxn];

struct qq
{
  int q,id;
  bool operator < (const qq &rhs) const
  {
    return q<rhs.q;
  }
}query[maxn];

int root(int x)
{
  return x == pre[x] ? x : pre[x] = root(pre[x]);
}

inline bool same(int x,int y)
{
  return root(x) == root(y);
}

inline long long calc(int x)
{
  return (long long ) x * (x-1);
}

inline void merge(int x, int y)
{
  if (same(x,y)) return ;
  int rx = root(x), ry = root(y);
  cnt -= calc(size[rx]);
  cnt -= calc(size[ry]);
  pre[rx] = ry;
  size[ry] += size[rx];
  cnt += calc(size[ry]);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for (int i = 1;i<=n;i++)
    {
      pre[i]=i;
      size[i]=1;
    }
    cnt = 0;
    for (int i =0; i< m;i++) e[i].read();
    sort(e,e+m);
    for (int i=0;i<q;i++) 
    {
      scanf("%d",&query[i].q);
      query[i].id = i;
    }
    sort(query,query+q);
    for (int i = 0,j = 0; i < q; i++)
    {
      while (j<m && e[j].w <= query[i].q)
      {
        merge(e[j].u,e[j].v);
        j++;
      }
      res[query[i].id] = cnt;
    }
    for (int i = 0; i <q; i++)
      printf(lld "\n",res[i]);
  }




  return 0;
}
