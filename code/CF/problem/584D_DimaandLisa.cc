/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 10 Oct 2015 10:15:15 PM CST
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

const int maxn = 10000007;
const int maxm = 0;

bool isp[maxn];
int prime[maxn];
int pn;

inline bool isprime(int x)
{
  int limit = sqrt(x);
  limit++;
  for (int i = 0; prime[i] < limit; i++) if (x % prime[i] == 0) return false;
  return true;
}

int main()
{
#ifdef FCBRUCE
  //freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  pn = 0;
  memset(isp, true, sizeof isp);
  isp[0] = isp[1] = false;

  for (int i = 2; i < maxn; i++)
  {
    if (!isp[i]) continue;
    prime[pn++] = i;
    for (int j = i + i; j < maxn; j += i) isp[j] = false;
  }

  int n;
  scanf("%d", &n);

  int cut = std::lower_bound(prime, prime + pn, n) - prime;
  if (prime[cut] == n) printf("1\n%d\n", n);
  else
  {
    cut--;
    n -= prime[cut];
    if (n == 2)
    {
      printf("2\n2 %d\n", prime[cut]);
      return 0;
    }

    for (int i = 0; i < pn && prime[i] < n; i++)
    {
      if (isprime(n - prime[i]))
      {
        printf("3\n%d %d %d\n", prime[cut], prime[i], n - prime[i]);
        return 0;
      }
    }
  }





  return 0;
}
