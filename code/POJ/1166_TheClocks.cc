/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Aug 2015 01:49:41 PM CST
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
#define maxn 16

using namespace std;

char ways[][8] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};

int a[maxn][maxn];

void build()
{
  memset(a, 0, sizeof a);
  for (int i = 0; i < 9; i++) for (int j = 0; ways[i][j] != '\0'; j++) 
    a[ways[i][j] - 'A'][i] = 1;
}

int gcd(int a, int b, int &x, int &y)
{
  if (b == 0)
  {
    x = 1; y = 0;
    return a;
  }
  int r = gcd(b, a % b, y, x);
  y -= x * (a / b);
  return r;
}

int mod_equation(int a, int b, int mod)
{
  int x, y;
  int g = gcd(a, mod, x, y);
  x %= mod; x += mod; x %= mod;
  return x * (b / g) % (mod / g);
}

void gauss(int a[][maxn], int n)
{
  for (int i = 0; i < n; i++)
  {
    int r = i;
    for (; a[r][i] == 0; r++) ;
    if (r != i) for (int j = 0; j <= n; j++) swap(a[r][j], a[i][j]);
    
    for (int k = i + 1; k < n; k++)
    {
      int g = __gcd(a[i][i], a[k][i]);
      int x = a[i][i] / g;
      int y = a[k][i] / g;
      for (int j = i; j <= n; j++) a[k][j] = ((a[k][j] * x - a[i][j] * y) % 4 + 4) % 4;
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < n; j++)
      a[i][n] -= a[j][n] * a[i][j];
    a[i][n] %= 4;
    a[i][n] += 4;
    a[i][n] %= 4;
    a[i][n] = mod_equation(a[i][i], a[i][n], 4);
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  build();

  for (int i = 0; i < 9; i++) scanf("%d", a[i] + 9);
  for (int i = 0; i < 9; i++) if (a[i][9] > 0) a[i][9] = 4 - a[i][9];

  gauss(a, 9);

  bool fir = true;
  for (int i = 0; i < 9; i++) for (int j = 0; j < a[i][9]; j++)
  {
    if (!fir) putchar(' ');
    fir = false;
    printf("%d", i + 1);
  }
  puts("");


  return 0;
}
