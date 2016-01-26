/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 26 Jan 2016 06:22:51 AM PST
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

const int maxn = 1007;
const int maxm = 0;

int dp[maxn][maxn];
char buffer[maxn];

int dfs(int l, int r)
{
  if (r - l < 1) return 0;
  if (dp[l][r] < INF) return dp[l][r];
  if (buffer[l] == buffer[r]) return dp[l][r] = dfs(l + 1, r - 1);
  return dp[l][r] = std::min(dfs(l + 1, r), dfs(l, r - 1)) + 1;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  scanf("%s", buffer);

  int l = strlen(buffer);

  memset(dp, 0x3f, sizeof dp);

  printf("%d\n", dfs(0, l-1));


  return 0;
}
