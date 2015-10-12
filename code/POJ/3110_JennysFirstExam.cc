/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 11 Oct 2015 06:40:04 PM CST
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

const int maxn = 300007;
const int maxm = 0;

int days[] = {0, 31, 28, 31,30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Course
{
  int a, b;
  bool operator < (const Course &rhs) const
  {
    return a > rhs.a;
  }
};

std::vector<Course> course;

int sum[maxn << 2];

inline void pushup(int k)
{
  sum[k] = sum[k * 2 + 1] + sum[k * 2 + 2];
}

bool update(int p, int k, int l, int r)
{
  if (l + 1 == r) 
  {
    if (sum[k]) return false;
    sum[k] = 1;
    return true;
  }

  bool res;
  int m = l + r >> 1;
  if (p < m) res = update(p, k * 2 + 1, l, l + r >> 1);
  else res = update(p, k * 2 + 2, l + r >> 1, r);
  pushup(k);
  return res;
}

int query(int a, int b, int k, int l, int r)
{
  if (sum[k] == r - l) return -1;
  if (l + 1 == r)
  {
    if (sum[k] == 0) return l;
    else return -1;
  }
  
  int m = l + r >> 1;
  if (b <= m) return query(a, b, k * 2 + 1, l, m);
  if (m <= a) return query(a, b, k * 2 + 2, m, r);

  int res = query(a, b, k * 2 + 2, m, r);
  if (res != -1) return res;
  return query(a, b, k * 2 + 1, l, m);
}

inline bool isleap(int y)
{
  return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0);
}

int dis(int y, int m, int d)
{
  int res = 0;
  for (int i = 1500; i < y; i++)
  {
    if (isleap(i)) res += 366;
    else res += 365;
  }
  if (isleap(y)) days[2] = 29;
  else days[2] = 28;
  for (int i = 1; i < m; i++)
  {
    res += days[i];

  }
  res += d;
  return res;
}

inline int dy(int y)
{
  return isleap(y) ? 366 : 365;
}

void date(int d)
{
  int y = 1500;
  while (d > dy(y)) 
  {
    d -= dy(y);
    y++;
  }

  if (isleap(y)) days[2] = 29;
  else days[2] = 28;
  int m = 1;

  while (d > days[m])
  {
    d -= days[m];
    m++;
  }

  printf("%02d.%02d.%04d\n", d, m, y);
}

char buff[256];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE


  int n;
  scanf("%d", &n);

  memset(sum, 0, sizeof sum);
  for (int i  = 0; i < n; i++)
  {
    int d, m, y;
    scanf("%s", buff);
    scanf("%s", buff);
    for (int i = 0 ; buff[i]; i++) if (buff[i] == '.')   buff[i] = ' ';
    sscanf(buff, "%d%d%d", &d, &m, &y);
    int k = dis(y, m, d);
    int t;
    scanf("%d", &t);
    if (!update(k, 0, 0, maxn))
    {
      puts("Impossible");
      return 0;
    }
    course.push_back({k - t, k});
  }

  std::sort(course.begin(), course.end());

  int res = INF;

  for (size_t i = 0; i < course.size(); i++)
  {
    int a = course[i].a;
    int b = course[i].b;
    int p = query(a, b, 0, 0, maxn);
    if (p != -1) update(p, 0, 0, maxn);
    else
    {
      puts("Impossible");
      return 0;
    }

    res = std::min(res, p);
  }

  date(res);





  return 0;
}
