/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 08 Apr 2017 11:15:04
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

char s[20];
int l;

long long dfs(int pos, int pre, bool top, long long cur)
{
  if (pos == l)
    return cur;

  int r = top ? s[pos] - '0' : 9;
  long long max = 0;
  for (int i = pre; i <= r; i++)
    max = std::max(max, dfs(pos + 1, i, top & i == r, cur * 10 + i));
  return max;
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    printf("Case #%d: ", ++__);
    scanf("%s", s);
    l = strlen(s);
    printf(lld "\n", dfs(0, 0, true, 0ll));
  }





  return 0;
}
