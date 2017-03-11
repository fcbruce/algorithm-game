/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 11 Mar 2017 17:41:45
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

const int maxn = 2333;
const int maxm = 0;

struct sphere
{
  int p[3], r;
  void read()
  {
    scanf("%d%d%d%d", p + 0, p + 1, p + 2, &r);
  }
}sph[maxn];

int n;

int p[2][3];

inline void check(sphere s)
{
  for (int i = 0; i < 3; i++)
  {
    p[0][i] = std::min(p[0][i], s.p[i] - s.r);
    p[1][i] = std::max(p[1][i], s.p[i] + s.r);
  }
}

struct cube
{
  int p[3];
  int r;
  bool eat(sphere s)
  {
    for (int i = 0; i < 3; i++)
    {
      bool f = p[i] <= s.p[i] - s.r && s.p[i] + s.r <= p[i] + r;
      if (!f) return false;
    }
    return true;
  }
};

cube build_cube(int p[], int r, int st)
{
  cube c;
  c.r = r;
  for (int i = 0; i < 3; i++)
  {
    if ((st & (1 << i)) != 0)
    {
      c.p[i] = p[i] - r;
    }
    else 
    {
      c.p[i] = p[i];
    }
  }
  return c;
}

int cp[2][3];

bool ok(cube c1, cube c2)
{
  for (int i = 0; i < n; i++)
  {
    if (!c1.eat(sph[i]) && !c2.eat(sph[i])) return false;
  }
  return true;
}

int binary(int st)
{
  int l = 0, r = INF;
  int res = r;
  while (l <= r)
  {
    int mid = l + r >> 1;
    cube c1 = build_cube(cp[0], mid, st);
    cube c2 = build_cube(cp[1], mid, ~st);
    if (ok(c1, c2))
    {
      res = mid;
      r = mid - 1;
    }
    else 
    {
      l = mid + 1;
    }
  }
  return res;
}

// st-bit, 0 min, 1 max
int solve(int st)
{
  for (int i = 0; i < 3; i++)
  {
    int id = !!(st & (1 << i));
    cp[0][i] = p[id][i];
    cp[1][i] = p[id ^ 1][i];
  }

  return binary(st);
}

inline void init()
{
  p[0][0] = p[0][1] = p[0][2] = INF;
  p[1][0] = p[1][1] = p[1][2] = -INF;
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    init();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
      sph[i].read();
      check(sph[i]);
    }

    int res = INF;

    for (int i = 0; i < 8; i++)
    {
      res = std::min(res, solve(i));
    }

    printf("Case #%d: %d\n", ++__, res);


  }




  return 0;
}
