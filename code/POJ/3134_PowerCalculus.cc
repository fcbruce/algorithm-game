/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 11 Oct 2015 06:17:23 PM CST
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

const int maxn = 2200;
const int maxm = 0;

int res[maxn];

bool vis[maxn];

std::vector<int> status;

void dfs(int x, int d)
{
  if (d > 15 ) return ;
  if (x >= maxn) return ;
  if (d > res[x]) return ;
  vis[x] = true;
  res[x] = d;

  for (int i = 1; i < maxn; i++) if (vis[i])
  {
    dfs(x + i, d + 1);
    if (x > i) dfs(x - i, d + 1);

  }
  
  vis[x] = false;

}
int ans[1001] = { 0, 0, 1, 2, 2, 3, 3, 4, 3, 4, 4, 5, 4, 5, 5, 5, 4, 5, 5, 6, 5, 6, 6, 6, 5, 6, 6, 6, 6, 7, 6, 6, 5, 6, 6, 7, 6, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 8, 7, 8, 7, 8, 8, 8, 7, 8, 7, 7, 6, 7, 7, 8, 7, 8, 8, 8, 7, 8, 8, 8, 8, 8, 8, 8, 7, 8, 8, 8, 8, 8, 8, 9, 8, 9, 8, 9, 8, 8, 8, 8, 7, 8, 8, 8, 8, 9, 8, 9, 8, 9, 9, 9, 8, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 8, 9, 8, 8, 7, 8, 8, 9, 8, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 10, 9, 9, 9, 9, 9, 9, 9, 9, 8, 9, 9, 9, 9, 9, 9, 10, 9, 10, 9, 10, 9, 10, 10, 10, 9, 10, 10, 10, 9, 10, 10, 10, 9, 10, 9, 10, 9, 9, 9, 9, 8, 9, 9, 9, 9, 10, 9, 10, 9, 10, 10, 10, 9, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 9, 10, 9, 9, 8, 9, 9, 10, 9, 10, 10, 10, 9, 10, 10, 11, 10, 11, 10, 10, 9, 10, 10, 11, 10, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 11, 10, 10, 10, 11, 10, 11, 11, 11, 10, 11, 10, 11, 10, 11, 10, 11, 10, 11, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 10, 11, 10, 11, 10, 11, 10, 11, 11, 11, 10, 11, 11, 11, 10, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 10, 11, 11, 11, 10, 11, 10, 11, 10, 10, 10, 10, 9, 10, 10, 10, 10, 11, 10, 11, 10, 11, 11, 11, 10, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 11, 12, 11, 11, 10, 11, 11, 12, 11, 12, 11, 11, 10, 11, 11, 11, 10, 11, 10, 10, 9, 10, 10, 11, 10, 11, 11, 11, 10, 11, 11, 12, 11, 12, 11, 11, 10, 11, 11, 12, 11, 12, 12, 11, 11, 12, 12, 12, 11, 12, 11, 11, 10, 11, 11, 12, 11, 12, 12, 12, 11, 11, 12, 12, 11, 12, 11, 12, 11, 11, 11, 12, 11, 12, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 12, 11, 11, 11, 12, 11, 12, 12, 12, 11, 12, 11, 12, 11, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 11, 12, 11, 12, 11, 11, 11, 11, 11, 11, 10, 11, 11, 11, 11, 11, 11, 12, 11, 12, 11, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 11, 12, 11, 11, 11, 11, 10, 11, 11, 11, 11, 12, 11, 12, 11, 12, 12, 12, 11, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 12, 12, 12, 12, 11, 12, 12, 12, 12, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 12, 12, 12, 13, 12, 13, 12, 12, 12, 13, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 13, 12, 12, 12, 13, 12, 13, 12, 12, 12, 13, 12, 13, 12, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 12, 13, 13, 13, 12, 13, 13, 13, 12, 13, 12, 13, 12, 13, 13, 13, 12, 13, 13, 13, 12, 13, 12, 13, 12, 12, 12, 13, 12, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 12, 13, 12, 12, 12, 12, 12, 13, 12, 13, 13, 13, 12, 13, 13, 13, 12, 13, 12, 12, 11, 12, 12, 13, 12, 13, 13, 13, 12}

;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  memset(res, 0x3f, sizeof res);
  memset(vis, false, sizeof vis);
  res[0] = 0;
  //dfs(1, 0);

  //printf("int res[1001] = {");

  //for (int i = 0; i <= 1000; i++)
  //{
  //  if (i > 0) putchar(',');
  //  printf(" %d", res[i]);
  //}
  //printf("}\n");

  //return 0;





  int n;

  while (scanf("%d", &n) == 1 && n != 0)
  {
    printf("%d\n", ans[n]);
  }




  return 0;
}
