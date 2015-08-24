/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 24 Aug 2015 07:45:30 PM CST
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
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 

using namespace std;

long long a[6], m[6];

long long gcd(long long a, long long b, long long &x, long long &y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }
  long long d = gcd(b, a % b, y, x);
  y -= x * (a / b);
  return d;
}

long long solve(long long a[], long long m[], int n)
{
  for (int i = 1; i < n; i++)
  {
    long long x, y;
    long long d = gcd(m[i-1], m[i], x, y);
    if ((a[i] - a[i - 1]) % d != 0) return -1;
    a[i] = m[i - 1] * x * (a[i] - a[i - 1]) / d + a[i - 1];
    m[i] = m[i - 1] * m[i] / d;
    a[i] %= m[i]; a[i] += m[i]; a[i] %= m[i];
  }
  return a[n - 1] != 0ll ? a[n - 1] : m[n - 1];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf(lld, m + i);
    for (int i = 0; i < n; i++) scanf(lld, a + i);

    printf("Case %d: " lld "\n", ++__, solve(a, m, n));
  }



  return 0;
}
