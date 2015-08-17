/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 17 Aug 2015 07:54:59 PM CST
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
#define maxn 128

using namespace std;

int g[maxn][maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n, s, t;
  scanf("%d%d%d", &n, &s, &t);
  s--; t--;

  memset(g, 0x3f, sizeof g);

  for (int i = 0; i < n; i++)
  {
    int k, v;
    scanf("%d", &k);
    for (int j = 0; j < k; j++)
    {
      scanf("%d", &v);
      v--;
      g[i][v] = j > 0 ? 1 : 0;
    }
  }

  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

  if (g[s][t] == INF) puts("-1");
  else printf("%d\n", g[s][t]);


  return 0;
}
