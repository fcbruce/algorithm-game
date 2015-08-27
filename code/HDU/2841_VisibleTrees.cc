/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 27 Aug 2015 07:28:33 PM CST
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

const int maxn = 100007;
const int maxm = 0;

std::vector<int> pf[maxn];
bool isp[maxn];
int p[maxn];
int pc;

void init()
{
  memset(isp, true, sizeof isp);
  isp[0] = isp[1] = false;
  pc = 0;
  for (int i = 2; i < maxn; i++)
  {
    if (!isp[i]) continue ;
    p[pc++] = i;
    for (int j = i; j < maxn; j += i) isp[j] = false;
  }

  for (int i = 2; i < maxn; i++)
  {
    int n = sqrt(i);
    int x = i;
    for (int j = 0; p[j] <= n; j++)
    {
      if (x % p[j] == 0) pf[i].push_back(p[j]);
      while (x % p[j] == 0) x /= p[j];
    }
    if (x != 1) pf[i].push_back(x);
  }
}

long long calc(int x, int range)
{
  int n = pf[x].size();
  long long res = 0ll;
  for (int s = 1; s < (1 << n); s++)
  {
    int p = 1, c = 0;
    for (int i = 0; i < n; i++) if ((s & (1 << i)) > 0)
    {
      p *= pf[x][i];
      c++;
    }
    if ((c & 1) == 0) res -= range - range / p;
    else res += range - range / p;
  }
  return res ;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  init();

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, m;
    scanf("%d%d", &n, &m);
    
    long long res = m;
    for (int i = 2; i <= n; i++)
      res += calc(i, m);

    printf(lld "\n", res);
  }




  return 0;
}
