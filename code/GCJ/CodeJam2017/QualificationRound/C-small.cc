/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 08 Apr 2017 12:16:28
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
    printf("Case #%d: ", ++__);
    long long n, k;
    scanf(lld lld, &n, &k);
    std::priority_queue<int> q;
    q.push(n);
    for (int i = 1; i < k; i++)
    {
      long long x = q.top(); q.pop();
      x--;
      long long l = x / 2, r = x - l;
      if (l > 0) q.push(l);
      if (r > 0) q.push(r);
    }
    long long x = q.top(); q.pop();
    x--;
    long long l = x / 2, r = x - l;
    printf(lld " " lld "\n", std::max(l, r), std::min(l, r));
  }




  return 0;
}
