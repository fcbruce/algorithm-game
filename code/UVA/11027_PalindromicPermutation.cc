/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 11 Sep 2016 15:16:25
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

char buffer[32];
int k;
int count[128];
char mid;
char left[32];
int length; 

LL p[32];

bool ok()
{
  length = strlen(buffer);
  memset(count, 0, sizeof count);
  for (int i = 0; i < length; i++) count[buffer[i]]++;
  int cnt = 0;
  for (int i = 'a'; i <= 'z'; i++) cnt += count[i] & 1;
  LL res = p[length >> 1];
  for (int i = 'a'; i <= 'z'; i++) res /= p[count[i] >> 1];
  return cnt < 2 && k <= res;
}

long long calc_count(char c)
{
  int len = 0;
  count[c]--;
  for (int i = 'a'; i <= 'z'; i++) len += count[i];
  LL res = p[len];
  for (int i = 'a'; i <= 'z'; i++) res /= p[count[i]];
  count[c]++;
  return res;
}

void rander()
{
  mid = 'a';
  for (; mid <= 'z' && !(count[mid] & 1); mid++) ;
  if (mid > 'z') mid = 0;
  for (int i = 'a'; i <= 'z'; i++) count[i] >>= 1;

  for (int i = 0; i < (length >> 1); i++)
  {
    for (int j = 'a'; j <= 'z'; j++) if (count[j] > 0)
    {
      long long cnt = calc_count(j);
      if (cnt >= k)
      {
        left[i] = j;
        count[j]--;
        break;
      }
      else
      {
        k -= cnt;
      }
    }
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  p[0] = 1;
  for (int i = 1; i < 32; i++) p[i] = p[i - 1] * i;

  int T_T, __ = 0;
  scanf("%d", &T_T);

  while (T_T--)
  {
    scanf("%s%d", buffer, &k);
    printf("Case %d: ", ++__);
    if (ok())
    {
      rander();
      for (int i = 0; i < (length >> 1); i++) putchar(left[i]);
      if (length & 1) putchar(mid);
      for (int i = (length >> 1) - 1; i >= 0; i--) putchar(left[i]);
      puts("");
    }
    else puts("XXX");
  }




  return 0;
}
