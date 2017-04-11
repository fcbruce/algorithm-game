/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 10 Apr 2017 22:03:57
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

const int maxn = 2507;
const int maxm = 0;

int cnt[maxn];

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n;
    scanf("%d", &n);
    memset(cnt, 0, sizeof cnt);
    n = n * n * 2 - n;
    for (int i = 0; i < n; i++)
    {
      int tmp;
      scanf("%d", &tmp);
      cnt[tmp]++;
    }

    printf("Case #%d: ", ++__);
    bool space = false;
    for (int i = 0; i < maxn; i++) if (cnt[i] & 1)
    {
      if (space) putchar(' ');
      printf("%d", i);
      space = true;
    }
    puts("");
  }




  return 0;
}
