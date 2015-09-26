/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 26 Sep 2015 02:30:24 PM CST
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

long long pow_mod(long long x, int n, int m)
{
  n %= (m - 1);
  long long res = 1;
  while (n)
  {
    if (n&1)
    {
      res *= x;
      res %= m;
    }

    x *= x;
    x %= m;

    n >>= 1;

  }
  return  res;
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int c, k1, b1, k2;
  int __=0;

  while (scanf("%d%d%d%d" ,&c, &k1, &b1, &k2) == 4)
  {
    std::vector<std::pair<int, int> > res;
    for (int i = 1; i < c; i++)
    {
      int a = pow_mod(i, k1 + b1, c);
      int j = c - a;
      if (pow_mod(i, k1, c) == pow_mod(j, k2, c)) 
        res.push_back(std::make_pair(i, j));
    }

    std::sort(res.begin(), res.end());
    int cnt = std::unique(res.begin(), res.end()) - res.begin();

    printf("Case #%d:\n", ++__);
    for (int i = 0; i < cnt; i++)
      printf("%d %d\n", res[i].first, res[i].second);

   if (cnt == 0) puts("-1");
  }




  return 0;
}
