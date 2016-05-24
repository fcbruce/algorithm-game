/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 24 May 2016 09:25:45
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

std::priority_queue<double> q;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    double x;
    scanf("%lf", &x);
    q.push(x);
  }

  for (int i = 1; i < n; i++)
  {
    double v1 = q.top(); q.pop();
    double v2 = q.top(); q.pop();
    q.push(2 * sqrt(v1 * v2));
  }

  printf("%.3f\n", q.top());




  return 0;
}
