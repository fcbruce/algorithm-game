/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 13 Feb 2016 12:18:19 AM PST
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

const int maxn = 100007;
const int maxm = 0;

int h[maxn << 1];
int r[maxn << 1];

int manacher(int *p)
{
  int pos = 0;
  int far = 0;
  int max = 0;
  for (int i = 1; p[i]; i++)
  {
    if (far > i)
      r[i] = std::min(r[pos * 2 - i], far - i);
    else
      r[i] = 1;

    while (p[i + r[i]] == p[i - r[i]] && p[i + r[i]] <= p[i + r[i] - 2]) r[i]++;

    if (i + r[i] > far)
    {
      far = i + r[i];
      pos = i;
    }

    max = std::max(max, r[i] - 1);
  }

  return max;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);
  while (T_T--)
  {
    int n;
    scanf("%d", &n);

    h[0] = INF;
    h[1] = -1;
    for (int i = 0, j = 2; i < n; i++)
    {
      scanf("%d", h + j);
      h[++j] = -1;
      h[++j] = 0;
    }

    printf("%d\n", manacher(h));
  }




  return 0;
}
