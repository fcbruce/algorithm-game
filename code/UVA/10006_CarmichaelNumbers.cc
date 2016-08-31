/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 31 Aug 2016 08:40:23
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

const int maxn = 65536;
const int maxm = 0;

bool isprime[maxn];

int power(int x, int n, int m)
{
  long long  res = 1;
  long long tmp = x;
  while (n)
  {
    if (n & 1)
    {
      res *= tmp;
      res %= m;
    }
    tmp *= tmp;
    tmp %= m;
    
    n >>= 1;
  }
  return res;
}

inline bool isp(int n)
{
  return isprime[n];
}

inline bool carmichael(int n)
{
  if (isp(n)) return false;
  for (int i = 0; i < std::min(8964, n); i++)
  {
    int a = rand() % n - 2;
    a += 2;
    if (power(a, n, n) != a) return false;
  }
  return true;
}

void init()
{
  memset(isprime, true, sizeof isprime);
  isprime[0] = isprime[1] = false;
  for (int i = 2; i < maxn; i++)
  {
    if (!isprime[i]) continue;
    for (int j = i << 1; j < maxn; j += i) isprime[j] = false;
  }
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  init();
  srand(time(nullptr));

  int n;

  while (scanf("%d", &n) && n)
  {
    if (carmichael(n))
      printf("The number %d is a Carmichael number.\n", n);
    else
      printf("%d is normal.\n", n);
  }




  return 0;
}
