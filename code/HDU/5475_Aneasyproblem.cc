/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 26 Sep 2015 12:12:20 PM CST
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

long long p[maxn << 2];

long long mod;

void build(int k, int l, int r)
{
  p[k] = 1;
  if (l + 1 == r) return ;
  build(k * 2 + 1, l, l + r >> 1);
  build(k * 2 + 2, l + r >> 1, r);
}

void update(int pos, int v, int k, int l, int r)
{
  if (l + 1 == r)
  {
    p[k] = v % mod;
    return ;
  }

  int  m = l + r >> 1;
  if (pos < m) update(pos, v, k * 2 + 1, l, m);
  else update(pos, v, k * 2 + 2, m, r);

  p[k] = p[k * 2 + 1] * p[k * 2 + 2] % mod;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE
  
  int T_T, __=0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    printf("Case #%d:\n", ++__);
    int n;
    scanf("%d" lld, &n, &mod);
    build(0, 0, n);
    for (int i = 0; i < n; i++)
    {
      int a,b;
      scanf("%d%d", &a ,&b);
      if (a == 1)
        update(i, b, 0, 0, n);
      else
        update(b - 1, 1, 0, 0, n);
      printf(lld "\n", p[0]);
    }
  }





  return 0;
}
