/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 31 Aug 2016 19:20:09
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

const int maxn = 65536;
const int maxm = 0;

char s[maxn];

const unsigned int g = 34943;

unsigned int CRC(char *s)
{
  int l = strlen(s);
  s[l] = s[l + 1] = 0;
  l += 2;
  unsigned int current = 0;
  for (int i = 0; i < l; i++)
  {
    for (int j = 7; j >= 0; j--)
    {
      current <<= 1;
      if (s[i] & (1 << j)) current |= 1;
      if (current >= g) current -= g;
    }
  }
  if (current == 0) return current;
  return g - current;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  while (gets(s) != nullptr && s[0] != '#')
  {
    unsigned crc = CRC(s);
    printf("%02X %02X\n", (unsigned)(crc >> 8u), crc & 0xff);
  }




  return 0;
}
