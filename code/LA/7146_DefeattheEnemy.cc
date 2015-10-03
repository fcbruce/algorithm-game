/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Oct 2015 10:08:14 PM CST
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

const int maxn = 1000007;
const int maxm = 0;

std::multiset<int> defence;

std::pair<int, int> me[maxn], enemy[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE


  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) scanf("%d%d", &me[i].first, &me[i].second);
    for (int i = 0; i < m; i++) scanf("%d%d", &enemy[i].second, &enemy[i].first);

    std::sort(me, me + n);
    std::sort(enemy, enemy + m);

    int dead = 0;

    defence.clear();

    for (int i = m - 1, j = n - 1; i >= 0; i--)
    {
      while (j >= 0 && me[j].first >= enemy[i].first)
      {
        defence.insert(me[j].second);
        j--;
      }

      if (defence.size() == 0)
      {
        dead = n + 1;
        break;
      }

      auto def = defence.upper_bound(enemy[i].second);

      if (def == defence.end()) 
      {
        dead++;
        defence.erase(defence.begin());
      }
      else defence.erase(def);
    }

    printf("Case #%d: %d\n", ++__, n - dead);

  }



  return 0;
}
