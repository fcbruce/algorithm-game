/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 11 Oct 2015 06:01:55 PM CST
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

const int maxn = 100007;
const int maxm = 0;

long long add[maxn << 2], sum[maxn << 2];

inline void pushdown(int k, int l, int r)
{
  if (add[k])
  {
    int lc = k * 2  + 1, rc = k * 2 + 2;
    int m = l + r >> 1;
    add[lc] += add[k];
    add[rc] += add[k];
    sum[lc] += (LL)(m - l) * add[k];
    sum[rc] += (LL)(r - m) * add[k];
    add[k]  = 0;
  }
}

inline void pushup(int k)
{
  sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
}

void build(int k, int l, int r)
{
  add[k] = 0;
  if (l + 1 == r)
  {
    scanf(lld,  &sum[k]);
    return ;
  }

  build(k * 2 + 1, l, l + r >> 1);
  build(k * 2 + 2, l + r >> 1, r);
  pushup(k);
}

void update(int a, int b, int v, int k, int l,int r)
{
  if (b <= l || r <= a)  return ;
  if (a <= l && r <= b)
  {
    add[k] += v;
    sum[k] += (LL)v * (r - l);
    return ;
  }

  pushdown(k, l, r);
  update(a, b, v, k * 2 + 1, l, l + r >> 1);
  update(a, b, v, k * 2 + 2, l + r >> 1, r);
  pushup(k);
}

LL query(int a, int b, int k,int l, int r)
{
  if (b <= l || r <= a) return 0ll;
  if (a <= l && r <= b) return sum[k];

  pushdown(k, l,  r);
  return query(a, b, k * 2 + 1, l, l + r >> 1) + query(a, b, k * 2 + 2, l + r >> 1, r);
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, m;
  scanf("%d%d", &n, &m);

  build(0, 0, n);

  for (int i = 0; i < m; i++)
  {
    char cmd;
    scanf(" %c", &cmd);
    if (cmd == 'C')
    {
      int x, y, v;
      scanf("%d%d%d", &x, &y, &v);
      x--;
      update(x, y, v, 0, 0, n);
    }
    else
    {
      int x, y;
      scanf("%d%d", &x, &y);
      printf(lld "\n", query(x - 1, y, 0, 0, n));
    }
  }




  return 0;
}
