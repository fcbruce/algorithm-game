/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 18 Aug 2015 10:43:47 AM CST
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
#define maxn 333

using namespace std;

char start[8], leave[8];
int a[maxn][maxn];

char days[][8] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

inline int day(char *s)
{
  for (int i = 0; i < 7; i++) if (strcmp(s, days[i]) == 0) return i;
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

int gauss(int a[][maxn], int m,int n)
{
  int row = 0, col = 0;
  for (int i = 0; i < n; i++)
  while (row < m && col <= n)
  {
    int r = row;
    for (int j = row + 1; j < m; j++) if (abs(a[r][col]) < abs(a[j][col])) r = j;
    if (r != row) for (int j = row; j <= n; j++) swap(a[r][j], a[row][j]);
    
    if (a[row][col] == 0)
    {
      col++;
      continue ;
    }

    for (int k = 0; k < m; k++) if (k != row && a[k][col] != 0)
    {
      int d = __gcd(a[row][col], a[k][col]);
      int x = a[row][col] / d;
      int y = a[k][col] / d;
      for (int j = 0; j <= n; j++) a[k][j] = ((a[k][j] * x - a[row][j] * y) % 7 + 7) % 7;
    }

    row++; col++;
  }

  int r = 0;
  for (int i = 0; i < m; i++)
  {
    bool zero = true;
    for (int j = 0; j < n; j++) if (a[i][j] != 0)
    {
      zero = false;
      break;
    }
    if (!zero) r++;
    else if (a[i][n] != 0) return -1;
  }

  if (r < n) return 1;

  for (int i = 0; i < n; i++) a[i][n] = mod_equation(a[i][i], a[i][n], 7);
  return 0;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n, m;
  
  while (scanf("%d%d", &n, &m) == 2 && n != 0 && m != 0)
  {
    memset(a, 0, sizeof a);
    for (int i = 0; i < m; i++)
    {
      int k;
      scanf("%d %s %s", &k, start, leave);
      a[i][n] = day(leave) + 7 - day(start) + 1;
      a[i][n] %= 7;
      while (k--)
      {
        int c;
        scanf("%d", &c);
        a[i][c - 1]++;
        a[i][c - 1] %= 7;
      }
    }

    switch (gauss(a, m ,n))
    {
      case 1: puts("Multiple solutions.");
              break;
      case -1: puts("Inconsistent data.");
               break;
      default:
                 for (int i = 0; i < n; i++) printf("%d%s", a[i][n] < 3 ? a[i][n] + 7 : a[i][n], i != n-1 ? " " : "\n");
                 break;
    }
  }



  return 0;
}
