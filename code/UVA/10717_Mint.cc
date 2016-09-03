/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Sep 2016 10:49:12
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

const int maxn = 0;
const int maxm = 0;

int coin[55];
int table[11];
int min[11], max[11];

int lcm(int a, int b)
{
  return a / std::__gcd(a, b) * b;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, t;
  
  while (scanf("%d%d", &n, &t) == 2)
  {
    for (int i = 0; i < n; i++) scanf("%d", coin + i);
    for (int i = 0; i < t; i++) scanf("%d", table + i);

    memset(max, 0, sizeof max);
    memset(min, 0x3f, sizeof min);
    

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        for (int k = 0; k < j; k++)
        {
          for (int l = 0; l < k; l++)
          {
            int LCM = lcm(lcm(coin[i], coin[j]), lcm(coin[k], coin[l]));
            for (int i = 0; i < t; i++)
            {
              int n = table[i] / LCM;
              int m = n;
              if (table[i] % LCM != 0) m += 1;
              max[i] = std::max(max[i], n * LCM);
              min[i] = std::min(min[i], m * LCM);
            }
          }
        }
      }
    }

    for (int i = 0; i < t; i++) printf("%d %d\n", max[i], min[i]);
  }




  return 0;
}
