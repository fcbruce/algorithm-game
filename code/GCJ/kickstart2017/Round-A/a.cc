/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 10 Mar 2017 17:51:05
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

const LL mod = 1000000007ll;

LL calc_brute(LL r, LL c)
{
  LL res = 0;
  if (r > c) std::swap(r, c);
  for (int i = 0; i < r; i++)
  {
    LL tmp = (r - i) * (c - i) % mod;
    tmp *= (i + 1);
    res += tmp % mod;
    res %= mod;
  }
  return res;
}

LL add(LL a, LL b)
{
  return (a + b) % mod;
}

LL mul(LL a, LL b)
{
  return a * b % mod;
}

LL sub(LL a, LL b)
{
  return (((a - b) % mod) + mod) % mod;
}

LL calc(LL r, LL c)
{
  LL res = 0;
  if (r > c) std::swap(r, c);
  LL rc = mul(r, c);
  LL tmp = (1 + r) * r >> 1;
  tmp %= mod;
  res = add(res, mul(tmp, rc));
  LL tmp2 = r * (r + 1) >> 1;
  if (tmp2 % 3 == 0)
  {
    tmp2 /= 3;
    tmp2 %= mod;
    tmp2 = mul(tmp2, (2 * r + 1) % mod);
  }
  else
  {
    tmp2 %= mod;
    tmp2 = mul(tmp2, (2 * r + 1) / 3 % mod);
  }
  res = sub(res, mul(add(r, c), sub(tmp2, tmp)));
  LL tmp3 = (r * (r - 1) / 2) % mod;
  tmp3 = mul(tmp3, tmp3);
  res = add(res, tmp3);
  res = add(res, sub(tmp2, mul(r, r)));
  return res;
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int r, c;
    scanf("%d%d", &r, &c);
    r--;
    c--;
    printf("Case #%d: " lld "\n", ++__, calc(r, c));
  }




  return 0;
}
