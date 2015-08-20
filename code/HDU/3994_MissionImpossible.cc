/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 20 Aug 2015 08:47:31 AM CST
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
#define maxn 256

using namespace std;

double g[maxn][maxn];
bool server[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
    {
      scanf("%lf", &g[i][j]);
      g[i][j] /= 100.0;
      g[i][j] = 1.0 / g[i][j];
    }

    memset(server, 0, sizeof server);
    server[0] = server[1] = true;
    int m;
    scanf("%d", &m);
    while (m--)
    {
      int v;
      scanf("%d", &v);
      server[--v] = true;
    }

    for (int k = 0; k < n; k++) 
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          g[i][j] = min(g[i][j], g[i][k] * g[k][j]);
    
    for (int k = 0; k < n; k++) if (server[k])
      for (int i = 0; i < n; i++) if (server[i])
        for (int j = 0; j < n; j++) if (server[j])
          g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    double c;
    scanf("%lf", &c);
    printf("%.8f\n", c * g[0][1]);
  }



  return 0;
}
