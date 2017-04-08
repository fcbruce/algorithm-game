/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 08 Apr 2017 12:46:32
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

const int maxn = 0;
const int maxm = 0;

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    long long n, k;
    scanf(lld lld, &n, &k);

    printf("Case #%d: ", ++__);

    int level = 0;
    long long x = n, y = k;
    while (y != 0)
    {
      level++;
      y >>= 1;
      if (y != 0)
      {
        x--;
        x = std::max(x / 2, x - x / 2);
      }
    }
    long long total = 1ll << (level - 1);
    long long l = 1, r = total, res = -1;
    while (l <= r)
    {
      long long mid = l + r >> 1;
      long long sum = mid * x + (total - mid) * (x - 1) + (total - 1);
      if (sum >= n)
      {
        res = mid;
        r = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    k -= total;
    long long length = k < res ? x : x - 1;
    length--;
    long long a = length >> 1, b = length - a;
    printf(lld " " lld "\n", std::max(a, b), std::min(a, b));
  }




  return 0;
}
