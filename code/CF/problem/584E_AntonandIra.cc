/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 10 Oct 2015 10:30:12 PM CST
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

const int maxn = 2333;
const int maxm = 0;

int s[maxn], p[maxn], pos[maxn];

std::vector<std::pair<int, int> > res;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++) scanf("%d", s + i);

  for (int i = 1; i <= n; i++) pos[s[i]] = i;

  for (int i = 1; i <= n; i++) p[i] = pos[p[i]];

  int cost = 0;

  for (int i = n; i > 0; i--)
  {
    int pos = 0;
    for (int j = 1; j <= n; j++) if (p[j] == i) pos = j;
    for (int j = pos + 1; j <= i; j++)
    {
      if (p[j] <= pos)
      {
        cost += j - pos;
        res.push_back({j, pos});
        std::swap(p[pos], p[j]);
        pos = j;
      }
    }

  }

  printf("%d\n", cost);
  printf("%lu\n", res.size());

  for (auto p : res) printf("%d %d\n", p.first, p.second);




  return 0;
}
