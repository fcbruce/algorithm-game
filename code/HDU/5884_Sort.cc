/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 18 Sep 2016 08:10:19
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

std::queue<long long> q1, q2;

int a[maxn];
int n, t;

bool ok(int limit)
{
  while (!q1.empty()) q1.pop();
  while (!q2.empty()) q2.pop();

  for (int i = 0; i < n; i++) q1.push(a[i]);

  long long sum = 0;

  int remain = (n - 1) % (limit - 1);
  if (remain)
  {
    remain++;
    for (int i = 0; i < remain; i++)
    {
      sum += q1.front();
      q1.pop();
    }
    q2.push(sum);
  }

  while (!q1.empty() || !q2.empty())
  {
    long long tmp = 0;
    for (int i = 0; i < limit; i++) 
    {
      if (q1.empty() && q2.empty()) break;
      if (q1.empty())
      {
        tmp += q2.front();
        q2.pop();
      }
      else if (q2.empty())
      {
        tmp += q1.front();
        q1.pop();
      }
      else
      {
        if (q1.front() < q2.front())
        {
          tmp += q1.front();
          q1.pop();
        }
        else
        {
          tmp += q2.front();
          q2.pop();
        }
      }
    }

    sum += tmp;
    if (sum > t) break;
    if (q1.empty() && q2.empty()) break;
    q2.push(tmp);
  }

  return sum <= t;
}

inline int read()
{
  int data = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  do
  {
    data = 10 * data + ch - '0';
    ch = getchar();
  } while ('0' <= ch && ch <= '9');
  return data;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int T_T;// = read();
  scanf("%d", &T_T);

  while (T_T--)
  {
    scanf("%d %d", &n, &t);

    for (int i = 0; i < n; i++) scanf("%d", a + i);

    std::sort(a, a + n);

    int l = 2, r = n, res = n;
    while (l <= r)
    {
      int mid = l + r >> 1;
      if (ok(mid))
      {
        res = mid;
        r = mid - 1;
      }
      else 
      {
        l = mid + 1;
      }
    }
    printf("%d\n", res);
  }




  return 0;
}
