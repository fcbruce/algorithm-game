/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 20 May 2015 07:35:16 PM CST
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
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 

using namespace std;

char s[233];

inline bool uni(char *s)
{
  return s[0]=='/';
}

inline bool win(char *s)
{
  char *p=strchr(s,':');
  return p[2]!='/';
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%s",s);
    for (int i=0;s[i];i++)
    {
      if (s[i]=='\\') s[i]='/';
    }
    if (uni(s))
    {
      puts("It's a path in Unix-like systems!");
      for (int i=0;s[i];i++)
      {
        putchar(s[i]);
      }
    }
    else if (win(s))
    {
      puts("It's a path in Windows system!");
      for (int i=0;s[i];i++)
      {
        if (s[i]=='/') s[i]='\\';
        putchar(s[i]);
      }
    }
    else
    {
      puts("It's a URL!");
      for (itn i=0;s[i];i++) putchar(s[i]);
    }
    puts("");
  }



  return 0;
}
