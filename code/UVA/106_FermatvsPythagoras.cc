/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 02 Sep 2016 18:59:29
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

const int maxn = 2000007;
const int maxm = 0;

bool vis[maxn];

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  LL n;

  while (scanf(lld, &n) == 1)
  {
    LL k = sqrt(n) + 5;
    memset(vis, false, sizeof vis);
    int cnt = 0;
    for (LL i = 1; i <= k; i++)
    {
      for (LL j = i - 1; j > 0 ; j -= 2)
      {
        if (std::__gcd(i, j) == 1)
        {
          LL a = sqr(i) - sqr(j);
          LL b = 2 * i * j;
          LL c = sqr(i) + sqr(j);
          for  (int k = 1; c * k <= n; k++)
          {
            vis[a * k] = vis[b * k] = vis[c * k] = true;
          }
          if (c <= n && std::__gcd(a, b) == 1) cnt ++;
        }
      }
    }

    int not_app = 0;
    for (int i = 1; i <= n; i++) not_app += !vis[i];

    printf("%d %d\n", cnt, not_app);
    
  }





  return 0;
}
