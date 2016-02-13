/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 12 Feb 2016 09:00:06 PM PST
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

char str[maxn];
char p[maxn << 1];
int r[maxn << 1];

void manacher(char *p, int *r)
{
  int pos = 0;
  int far = 0;
  for (int i = 1; p[i]; i++)
  {
    if (far > i)
      r[i] = std::min(far - i, r[2 * pos - i]);
    else
      r[i] = 1;
    while (p[i - r[i]] == p[i + r[i]]) r[i]++;
    if (i + r[i] > far)
    {
      far = i + r[i];
      pos = i;
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  int __ = 0;

  while (gets(str) != NULL && strcmp(str, "END") != 0)
  {
    p[0] = '$';
    p[1] = '#';
    for (int i = 0, j = 2; str[i]; i++)
    {
      p[j++] = str[i];
      p[j++] = '#';
      p[j] = '\0';
    }

    manacher(p, r);

    int max = 0;
    for (int i = 1; p[i]; i++)
      max = std::max(max, r[i] - 1);

    printf("Case %d: %d\n", ++__, max);
  }




  return 0;
}
