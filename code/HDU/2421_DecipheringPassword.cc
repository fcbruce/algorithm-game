/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 28 Aug 2015 01:44:50 PM CST
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

const int maxn = 1000007;
const int maxm = 0;
const long long mod = 10007;

int p[maxn];
bool isp[maxn];
int pc;

inline void init()
{
  memset(isp, true, sizeof isp);
  isp[0] = isp[1] = false;
  pc = 0;
  for (int i = 2; i < maxn; i++)
  {
    if (!isp[i]) continue ;
    for (int j = i + i; j < maxn; j += i) isp[j] = false;
    p[pc++] = i;
  }
}

long long cubesum(long long n)
{
  n %= mod;
  return sqr(n * (n + 1) * 5004 % mod) % mod;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int __ = 0;

  init();

  int a, b;

  while (scanf("%d%d", &a, &b) == 2)
  {
    int r = sqrt(a);
    b %= mod;
    long long res = 1;
    for (int i = 0; p[i] <= r; i++) if (a % p[i] == 0)
    {
      int n = 0;
      while (a % p[i] == 0)
      {
        a /= p[i];
        n++;
      }
      res *= cubesum(b * n + 1);
      res %= mod;
    }
    if (a != 1) res *= cubesum(b + 1);
    res %= mod;
    printf("Case %d: ", ++__);
    printf(lld "\n", res);
  }




  return 0;
}
