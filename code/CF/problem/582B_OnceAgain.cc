/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 11 Oct 2015 03:45:39 PM CST
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

const int maxn = 107;
const int maxm = 100007;

int a[maxn];

int times[303];

int dp[maxm];

int prefix[maxm], suffix[maxm];

void lis(int n, int T)
{
  
  for (int i = 0; i < n * T; i++)
  {
    dp[i] = 1;
    for (int j = 0; j < i; j++) if (a[j % n] <= a[i % n]) dp[i] = std::max(dp[i], dp[j] + 1);
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, T;
  scanf("%d%d", &n, &T);

  for (int i = 0; i < n; i++) scanf("%d", a + i);

  if (2 * n >= T)
  {
    lis(n, T);
    printf("%d\n", *std::max_element(dp, dp + n * T));
  }
  else
  {
    lis(n, n);
    memcpy(prefix, dp, sizeof dp);
    for (int i = 0; i < n; i++) a[i] = -a[i];
    std::reverse(a, a + n);
    puts("");
    lis(n, n);
    memcpy(suffix, dp, sizeof dp);
    std::reverse(suffix, suffix + n * n);

    for (int i = 0; i < n; i++) a[i] = -a[i];
    std::reverse(a, a + n);

    long long res = 0;
    for (int i = 0; i < n; i++)
    {
      int cnt = 0;
      for (int j = 0; j < n; j++) if (a[i] == a[j]) cnt++;
      
      int front = 0;
      for (int j = 0; j < n; j++) if (a[j] <= a[i]) front = std::max(front, prefix[n * (n - 1) + j]);
      int back = 0;
      for (int j = 0; j < n; j++) if (a[j] >= a[i]) back = std::max(back, suffix[j]);

      res = std::max(res, cnt * (LL)(T - 2 * n) + front + back);
    }
    printf(lld "\n", res);
  }




  return 0;
}
