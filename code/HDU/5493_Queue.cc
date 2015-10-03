/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 03 Oct 2015 02:06:52 PM CST
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

struct Person
{
  int h, k;
  void read()
  {
    scanf("%d%d", &h, &k);
  }
  bool operator < (const Person &rhs) const
  {
    return h < rhs.h;
  }
}person[maxn];

int sum[maxn << 2];
int queue[maxn];

void update(int p, int k, int l, int r)
{
  sum[k]++;
  if (l + 1 == r) return ;
  int m = l + r >> 1;
  if (p < m) update(p, k * 2 + 1, l, m);
  else update(p, k * 2 + 2, m, r);
}

int query(int space, int k, int l, int r)
{
  if (l + 1 == r) return space == 0 && sum[k] == 0 ? l : INF;
  int m = l + r >> 1;
  int lc = k * 2 + 1, rc = k * 2 + 2;
  if (m - l - sum[lc] > space) return query(space, lc, l, m);
  else return query(space - (m - l - sum[lc]), rc, m, r);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    itn n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) person[i].read();

    std::sort(person, person + n);

    memset(sum, 0, sizeof sum);

    bool possible = true;

    for (int i = 0; i < n; i++)
    {
      int k = person[i].k;
      int pos = query(std::min(k, n - i - k - 1), 0, 0, n);
      if (pos >= n)
      {
        possible = false;
        break;
      }


      queue[pos] = person[i].h;
      update(pos, 0, 0, n);
    }

    printf("Case #%d:", ++__);
    if (!possible)
    {
      puts(" impossible");
      continue;
    }
    for (int i = 0; i < n; i++) printf(" %d", queue[i]);
    puts("");
  }




  return 0;
}
