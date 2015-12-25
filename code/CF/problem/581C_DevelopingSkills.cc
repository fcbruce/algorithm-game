/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 25 Oct 2015 04:17:39 PM CST
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

int cnt[11];

int main()
{
#ifdef FCBRUCE
  //freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n, k;
  scanf("%d%d", &n, &k);

  long long total = 0ll;

  memset(cnt, 0, sizeof cnt);

  for (int i = 0; i < n; i++)
  {
    int v;
    scanf("%d", &v);
    total += v / 10;
    cnt[10] += (100 - v) / 10;
    v %= 10;
    if (v == 0) continue;
    cnt[10 - v]++;
  }

  for (int i = 1; i <= 10; i++)
  {
    if (k < i) break;
    int add = std::min(k / i, cnt[i]);
    total += add;
    k -= add * i;
  }

  printf(lld "\n", total);



  return 0;
}
