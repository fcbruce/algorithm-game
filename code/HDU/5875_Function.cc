/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 10 Sep 2016 16:16:48
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

int a[maxn], min[maxn << 2];

void update(int p, int v, int k, int l, int r)
{
  if (l + 1 == r)
  {
    min[k] = v;
    return ;
  }

  int m = l + r >> 1;
  if (p < m) update(p, v, k * 2 + 1, l, m);
  else update(p, v, k * 2 + 2, m, r);

  min[k] = std::min(min[k * 2 + 1], min[k * 2 + 2]);
}

std::pair<int, int> query(int p,int v, int k,int l, int r)
{
  if (min[k] > v) return {INF, INF};
  if (l + 1 == r) return {min[k], l};
  int lc = k * 2 + 1, rc = k * 2 + 2, m = l + r >> 1;
  if (p < m && min[lc] <= v) 
  {
    auto res = query(p, v, lc, l, m);
    if (res.second != INF) return res;
  }
  return query(p, v, rc, m, r);
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

    memset(min, 0x3f, sizeof min);

    for (int i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
      update(i, a[i], 0, 0, n);
    }

    int m;
    scanf("%d", &m);

    while (m--)
    {
      int l, r;
      scanf("%d%d", &l, &r);
      l--; r--;

      int x = a[l];
      int p = l + 1;
      while (p <= r)
      {
        auto q = query(p, x, 0, 0, n);
        if (q.second > r) break;
        x %= q.first;
        p = q.second + 1;
      }

      printf("%d\n", x);
    }
  }




  return 0;
}
