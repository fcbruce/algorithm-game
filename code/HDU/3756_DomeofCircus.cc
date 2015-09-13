/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 28 Aug 2015 08:28:35 AM CST
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
const int maxm = 0;

struct point
{
  double x,y;
  void read(double &l)
  {
    double x, y, z;
    scanf("%lf%lf%lf", &x, &y, &z);
    this->x = sqrt(sqr(x) + sqr(y));
    l = std::max(l, this->x);
    this->y = z;
  }
  bool operator < (const point &rhs) const
  {
    return x < rhs.x;
  }
}p[maxn];
int n;

inline int dcmp(double k)
{
  return fabs(k) < eps ? 0 : k > 0 ? 1 : -1;
}

inline double height(double r)
{
  double h = 0;
  for (int i = 0; i < n; i++) h = std::max(h, p[i].y * r / (r - p[i].x));
  return h;
}

inline double Volume(double r)
{
  return height(r) * sqr(r) * PI / 3.0;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    scanf("%d", &n);
    double l = 0.0, r = 1e10;
    for (int i = 0; i < n; i++) p[i].read(l);

    while (dcmp(r - l) > 0)
    {
      double m0 = (l + r) / 2.0;
      double m1 = (m0 + r) / 2.0;

      if (Volume(m0) > Volume(m1)) l = m0;
      else r = m1;
    }

    printf("%.3f %.3f\n", height((l + r) / 2.0), (l + r) / 2.0);
  }




  return 0;
}
