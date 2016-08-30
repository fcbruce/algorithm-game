/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 30 Aug 2016 19:59:02
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
  freopen("/root/code/t", "r", stdin);
#endif // FCBRUCE

  int k = 0;

  long long l = 2;
  while (k < 10)
  {
    long long s = (sqr(l) << 3) + (l << 3) + 1;
    long long rt = sqrt(s);
    if (sqr(rt) == s)
    {
      k++;
      long long n = (l << 1) + 1 + rt;
      n >>= 1;
      printf("%10lld%10lld\n", n, n + l);
    }
    l += 2;
  }




  return 0;
}
