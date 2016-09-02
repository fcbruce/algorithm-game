/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 02 Sep 2016 23:54:06
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

int bit[64];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n;
    scanf("%d", &n);
    int l = 0;
    while (n)
    {
      if (n & 1)
      {
        bit[l++] = 1;
        n--;
        n /= -2;
      }
      else
      {
        bit[l++] = 0;
        n /= -2;
      }
    }

    printf("Case #%d: ", ++__);
    for (int i = std::max(l - 1, 0); i >= 0; i--) printf("%d", bit[i]);
    puts("");
  }




  return 0;
}
