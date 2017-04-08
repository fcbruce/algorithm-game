/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 08 Apr 2017 10:28:08
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

const int maxn = 1024;
const int maxm = 0;

char chips[maxn];
int k;

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    scanf("%s %d", chips, &k);
    int l = strlen(chips);
    int res = 0;
    for (int i = 0; i <= l - k; i++)
    {
      if (chips[i] == '-') 
      {
        for (int j = 0; j < k; j++)
        {
          char &c = chips[j + i];
          c = (c == '-' ? '+' : '-');
        }
        res++;
      }
    }
    for (int i = l - k; i < l; i++)
      if (chips[i] == '-') res = -1;

    printf("Case #%d: ", ++__);
    if (res >= 0) printf("%d\n", res);
    else puts("IMPOSSIBLE");
  }

  return 0;
}
