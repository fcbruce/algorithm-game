/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 19 Aug 2015 01:49:28 PM CST
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
#define maxn 100007

using namespace std;

int n, m, k;
int x[maxn], a[maxn];
int equal_x[maxn][32], equal_a[maxn][32];
int less_x[maxn][32], less_a[maxn][32];
int nex[maxn];

inline bool equal_xa(int i, int j)
{
  return equal_a[i][a[i]] == (equal_x[j][x[j]] - ((j - i - 1 >= 0) ? equal_x[j - i - 1][x[j]] : 0)) && 
    less_a[i][a[i]] == (less_x[j][x[j]] - ((j - i - 1 >= 0) ? less_x[j - i - 1][x[j]] : 0));
}

inline bool equal_aa(int i, int j)
{
  return equal_a[i][a[i]] == (equal_a[j][a[j]] - ((j - i - 1 >= 0) ? equal_a[j - i - 1][a[j]] : 0)) && 
    less_a[i][a[i]] == (less_a[j][a[j]] - ((j - i - 1 >= 0) ? less_a[j - i - 1][a[j]] : 0));
}

inline void get_fail()
{
  nex[0] = -1;
  for (int i = 1, j = -1; i < m; i++)
  {
    while (j > -1 && !equal_aa(j + 1, i)) j = nex[j];
    if (equal_aa(j + 1, i)) j++;
    nex[i] = j;
  }
}

int kmp()
{
  int res = 0;
  get_fail();
  for (int i = 0, j = -1; i < n; i++)
  {
    while (j > -1 && !equal_xa(j + 1, i)) j = nex[j];
    if (equal_xa(j + 1, i)) j++;
    if (j + 1 == m)
    {
      res++;
      j = -1;
    }
  }
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d%d%d", &n, &m, &k) == 3)
  {
    memset(equal_x, 0,sizeof equal_x);
    memset(less_x, 0,sizeof less_x);
    memset(equal_a, 0,sizeof equal_a);
    memset(less_a, 0,sizeof less_a);
    for (int i = 0; i < n; i++)
    {
      scanf("%d", x + i);
      if (i > 0)
      {
        memcpy(equal_x[i], equal_x[i - 1], sizeof equal_x[i]);
        memcpy(less_x[i], less_x[i - 1], sizeof less_x[i]);
      }
      equal_x[i][x[i]]++;
      for (int j = x[i] + 1; j <= k; j++) less_x[i][j]++;
    }

    for (int i = 0; i < m; i++)
    {
      scanf("%d", a + i);
      if (i > 0)
      {
        memcpy(equal_a[i], equal_a[i - 1], sizeof equal_a[i]);
        memcpy(less_a[i], less_a[i - 1], sizeof less_a[i]);
      }
      equal_a[i][a[i]]++;
      for (int j = a[i] + 1; j <= k; j++) less_a[i][j]++;
    }

    printf("%d\n", kmp());
  }



  return 0;
}
