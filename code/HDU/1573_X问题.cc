/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 25 Aug 2015 09:38:04 AM CST
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

int a[10], m[10];

int gcd(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }
  int d = gcd(b, a % b, y, x);
  y -= x * a / b;
  return d;
}

int CRT(int a[], int  m[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int x, y;
    int d = gcd(m[i - 1], m[i], x, y);
    if ((a[i] - a[i - 1]) % d != 0) return -1;
    a[i] = m[i - 1] / d * x * (a[i] - a[i - 1]) + a[i - 1];
    m[i] *= m[i - 1] / d;
    a[i] %= m[i]; a[i] += m[i]; a[i] %= m[i];
  }
  return 0;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    long long X;
    int n;
    scanf(lld "%d", &X, &n);
    for (int i = 0; i < n; i++) scanf("%d", m + i);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    int k = CRT(a, m, n);
    if (k == -1 || a[n - 1] > X) puts("0");
    else printf(lld "\n", (X - a[n - 1]) / m[n - 1] + (a[n - 1] > 0 ? 1 : 0));
  }



  return 0;
}
