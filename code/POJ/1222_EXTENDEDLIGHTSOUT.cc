/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Aug 2015 08:41:00 AM CST
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
#define maxn 32

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int a[maxn][maxn];

inline bool in(int i, int j)
{
  return 0 <= i && i < 5 && 0 <= j && j < 6;
}

inline int encode(int i, int j)
{
  return i * 6 + j;
}

void gauss(int a[maxn][maxn], int n)
{
  for (int i = 0; i < n; i++)
  {
    int r = i;
    for (; a[r][i] == 0; r++);
    if (r != i) for (int j = 0; j <= n; j++) swap(a[i][j], a[r][j]);

    for (int k = i + 1; k < n; k++)
    {
      if (a[k][i] == 0) continue;
      for (int j = i; j <= n; j++) a[k][j] ^= a[i][j];
    }
  }

  for (int i = n - 1; i >= 0; i--)
  {
    for (int j = i + 1; j < n; j++)
      a[i][n] ^= a[j][n] & a[i][j];
  }
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
    memset(a, 0, sizeof a);

    for (int i = 0; i < 30; i++) scanf("%d", a[i] + 30);

    for (int i = 0; i < 5; i++) for (int j = 0; j < 6; j++)
    {
      a[encode(i, j)][encode(i, j)] = 1;
      for (int k = 0; k < 4; k++)
      {
        int x = i + dx[k], y = j + dy[k];
        if (!in(x, y)) continue;
        a[encode(x, y)][encode(i, j)] = 1;
      }
    }

    gauss(a, 30);

    printf("PUZZLE #%d\n", ++__);
    for (int i = 0; i < 5; i++)
    {
      for (int j = 0; j < 6; j++)
      {
        if (j > 0) putchar(' ');
        printf("%d", a[encode(i, j)][30]);
      }
      puts("");
    }
  }



  return 0;
}
