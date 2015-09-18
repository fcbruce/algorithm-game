/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 15 Sep 2015 09:01:42 PM CST
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

const int maxn = 10007;
const int maxm = 1000007;

struct segment
{
  int a, b, y, v;
  bool operator < (const segment &rhs) const
  {
    if (y == rhs.y) return v > rhs.v;
    return y < rhs.y;
  }
}seg[maxn << 1];

int value[maxm];

long long add[maxm << 2];
long long s[maxm<<2], s2[maxm<<2];

inline void pushdown(int k, int l, int r)
{
  if (add[k] != 0)
  {
    int lc = k * 2 + 1, rc = k * 2 + 2, m = l + r >> 1;
    add[lc] += add[k]; add[rc] += add[k];
    s2[lc] += 2 * s[lc] * add[k] + sqr((LL)add[k]) * (m - l);
    s[lc] += add[k] * (m - l);
    s2[rc] += 2 * s[rc] * add[k] + sqr((LL)add[k]) * (r - m);
    s[rc] += add[k] * (r - m);
    add[k] = 0;
  }
}

void pushup(int k)
{
  s2[k] = s2[k*2+1] + s2[k*2+2];
  s[k] = s[k*2+1] + s[k*2+2];
}

void update(int a, int b, int v, int k, int l, int r)
{
  if (b <= l || r <= a) return ;
  if (a <= l && r <= b)
  {
    add[k] += v;
    s2[k] += 2 * s[k] * v +  (r - l);
    s[k] += v * (r - l);
    return ;
  }

  pushdown(k, l, r);
  update(a, b, v, k * 2 + 1, l, l + r >> 1);
  update(a, b, v, k * 2 + 2, l + r >> 1, r);
  pushup(k);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __=0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int x = 0, y = 0;
    int cnt = 0;
    while (k--)
    {
      char d;
      int t;
      scanf(" %c %d", &d, &t);
      switch (d)
      {
        case 'R':
          seg[cnt++] = {x, x + t, y, 1};
          x += t;
          break;
        case 'L':
          seg[cnt++] = {x - t, x, y, -1};
          x -= t;
          break;
        case 'U':
          y -= t;
          break;
        case 'D':
          y += t;
          break;
      }
    }
    std::sort(seg, seg + cnt);
    memset(add, 0, sizeof add);
    memset(s, 0, sizeof s);
    memset(s2, 0, sizeof s2);
    long long res = 0;
    for (int i = 0, j = 0; i < n; i++)
    {
      while (j < cnt && seg[j].y <= i)
      {
        update(seg[j].a, seg[j].b, seg[j].v, 0, 0, m);
        j++;
      }
      res += s2[0];
    }
    printf("Case #%d: %lld\n", ++__, res);
  }




  return 0;
}
