/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 10 Mar 2017 18:52:04
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

const int maxn = 2007;
const int maxm = 0;

bool dp[maxn][maxn];
char s[maxn], t[maxn];

void match(int i, int j)
{
  if (s[i] != '*' && t[j] != '*')
  {
    if (s[i] != t[j])
    {
      dp[i][j] = false;
      return ;
    }
    else
    {
      dp[i][j] |= dp[i - 1][j - 1];
    }
  }

  if (s[i] == '*')
  {
    int limit = 4;
    for (int k = 0; k <= limit && !dp[i][j]; k++)
    {
      if (j - k < 0) break;
      if (t[j - k] == '*') limit += 1;
      dp[i][j] |= dp[i - 1][j - k];
    }
  }
  if (t[j] == '*')
  {
    int limit = 4;
    for (int k = 0; k <= limit && !dp[i][j]; k++)
    {
      if (i - k < 0) break;
      if (s[i - k] == '*') limit += 1;
      dp[i][j] |= dp[i - k][j - 1];
    }
  }
}

int main()
{
#ifdef FCBRUCE
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    scanf("%s %s", s + 2, t + 2);
    s[1] = t[1] = '#';
    int l1 = strlen(s + 1);
    int l2 = strlen(t + 1);
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    for (int i = 1; s[i]; i++)
    {
      for (int j = 1; t[j]; j++)
      {
        match(i, j);
      }
    }
    printf("Case #%d: ", ++__);
    puts(dp[l1][l2] ? "TRUE" : "FALSE");
  }





  return 0;
}
