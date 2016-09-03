/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Sep 2016 14:56:57
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

const int maxn = 50007;
const int maxm = 0;

int phi[maxn], prime[maxn];
bool isp[maxn];
int pn;

void calc()
{
  memset(isp, true, sizeof isp);
  isp[0] = isp[1] = false;
  phi[1] = 1;
  pn = 0;

  for (int i = 2; i < maxn; i++)
  {
    if (isp[i])
    {
      prime[pn++] = i;
      phi[i] = i - 1;
    }
    for (int j = 0; j < pn; j++)
    {
      if (i * prime[j] > maxn) break;
      isp[i * prime[j]] = false;
      if (i % prime[j] == 0)
      {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
      else
      {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      }
    }
  }
}

LL sum[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  calc();
  sum[0] = 0;
  for (int i = 1; i < maxn; i++) sum[i] = sum[i - 1] + phi[i];

  int n;

  while (scanf("%d", &n) == 1 && n > 0)
  {
    printf(lld "\n", (sum[n] << 1) - phi[1]);
  }




  return 0;
}
