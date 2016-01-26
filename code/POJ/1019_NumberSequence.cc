/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 25 Jan 2016 04:01:15 AM PST
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

const int maxn = 40000;
const int maxm = 0;

LL count[maxn], sum[maxn];
int tmp[1024];

int counts(int x)
{
  int c = 0;
  while (x)
  {
    x /= 10;
    c++;
  }
  return c;
}

int find(int n, int k)
{
  int c = 0;
  while (n)
  {
    tmp[c++] = n % 10;
    n /= 10;
  }
  return tmp[c - k];
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  count[0] = sum[0] = 0;
  for (int i = 1; i < maxn; i++)
  {
    count[i] = count[i - 1] + counts(i);
    sum[i] = sum[i - 1] + count[i];
  }

  int T_T;
  scanf("%d", &T_T);

  while (T_T--)
  {
    LL n;
    scanf(lld, &n);
    n -= *(std::lower_bound(sum, sum + maxn, n) - 1);
    int k = std::lower_bound(count, count + maxn, n) - count;
    n -= count[k - 1];
    printf("%d\n", find(k, n));
  }




  return 0;
}
