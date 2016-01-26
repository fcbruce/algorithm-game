/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 26 Jan 2016 12:32:34 AM PST
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

char word[10000][16];
char buffer[16];
int n;

inline bool iscorrect(char *s)
{
  for (int i = 0; i < n; i++) if (strcmp(buffer, word[i]) == 0) return true;
  return false;
}

bool sim(char *s1, char *s2)
{
  int l = strlen(s2), diff = 0;
  for (int i = 0, j = 0; j < l; j++)
  {
    if (s1[i] != s2[j]) diff++;
    else i++;
  }
  return diff == 1;
}

bool diff(char *s1, char *s2)
{
  int l = strlen(s1), differ = 0;

  for (int i = 0; i < l; i++)
    if (s1[i] != s2[i]) differ++;

  return differ == 1;
}

void find_sim(char *s)
{
  printf("%s:", s);
  for (int i = 0; i < n; i++)
  {
    int d = strlen(s) - strlen(word[i]);
    switch (d)
    {
      case 0:
        if (diff(word[i], s)) printf(" %s", word[i]);
        break;
      case 1:
        if (sim(word[i], s)) printf(" %s", word[i]);
        break;
      case -1:
        if (sim(s, word[i])) printf(" %s", word[i]);
        break;
    }
  }
  puts("");
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  n = 0;

  while (scanf("%s", buffer), buffer[0] != '#')
    strcpy(word[n++], buffer);

  while (scanf("%s", buffer), buffer[0] != '#')
  {
    if (iscorrect(buffer))
    {
      printf("%s is correct\n", buffer);
      continue;
    }

    find_sim(buffer);
  }



  return 0;
}
