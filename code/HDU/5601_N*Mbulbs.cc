/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 26 Dec 2015 07:17:35 PM CST
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
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, m;
    scanf("%d%d", &n, &m);
    int total = n + m - 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
      int v;
      scanf("%d", &v);
      total -= v;
    }

    if (total % 2 == 0) puts("YES");
    else puts("NO");
  }




  return 0;
}
