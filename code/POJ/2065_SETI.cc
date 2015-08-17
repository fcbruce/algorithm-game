/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Aug 2015 06:54:44 PM CST
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
#define maxn 96

using namespace std;

int a[maxn][maxn];
char s[maxn];

void init(int n, int mod)
{
  for (int i = 0; i < n; i++)
  {
    a[i][0] = 1;
    for (int j = 1; j < n; j++) a[i][j] = a[i][j - 1] * (i + 1) % mod;
    a[i][n] = s[i] == '*' ? 0 : s[i] - 'a' + 1;
  }
}

int gcd(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }
  int d = gcd(b, a % b, y, x);
  y -= x * (a / b);
  return d;
}

int mod_equation(int a, int b, int mod)
{
  int x, y;
  int d = gcd(a, mod, x, y);
  x %= mod; x += mod; x %= mod;
  return x * (b / d) % (mod / d);
}

void gauss(int a[][maxn], int n, int mod)
{
  for (int i = 0; i < n; i++)
  {
    int r = i;
    for (int j = i + 1; j < n; j++) if (abs(a[r][i]) < abs(a[j][i])) r = j;
    if (r != i) for (int j = i; j <= n; j++) swap(a[r][j], a[i][j]);

    for (int k = i + 1; k < n; k++)
    {
      int d = __gcd(a[i][i], a[k][i]);
      int x = a[i][i] / d;
      int y = a[k][i] / d;
      for (int j = i; j <=n; j++)
        a[k][j] = ((a[k][j] * x - a[i][j] * y) % mod + mod ) % mod;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < n; j++)
    {
      a[i][n] -= a[j][n] * a[i][j] % mod;
      a[i][n] %= mod;
    }
    a[i][n] %= mod; a[i][n] += mod; a[i][n] %= mod;
    a[i][n] = mod_equation(a[i][i], a[i][n], mod);
  }
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
    int p;
    scanf("%d%s", &p, s);
    int n = strlen(s);
    init(n, p);
    gauss(a, n, p);

    for (int i = 0; i < n; i++)
    {
      if (i > 0) putchar(' ');
      printf("%d", a[i][n]);
    }
    puts("");
  }




  return 0;
}
