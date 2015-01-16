/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 16 Jan 2015 09:53:44 AM CST
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
#define maxn 65536

using namespace std;

char str[maxn];
char Map[8][65536];


void init()
{
  int l=strlen(str);
  int len=0;
  int last=0;
  for (int i=0;i<l;i++)
  {
    int k=i-last;
    if (k==(1<<len)-1)
    {
      len++;
      last=i;
    }
    Map[len][i-last]=str[i];
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (fgets(str,maxn,stdin)!=NULL)
  {
    init();
    int len;
    while (len=[]()
        {
          int len=0;
          char c;
          for (int i=0;i<3;i++)
          {
            while (isspace(c=getchar()));
            if (c=='1') len|=1<<2-i;
          }
          return len;        
        }())
    {

      while ([&]()
          {
            int val=0;
            char c;
            for (int i=0;i<len;i++)
            {
              while (isspace(c=getchar()));
              if (c=='1') val|=1<<len-1-i;
            } 
            if (val==((1<<len)-1)) return false;
            putchar(Map[len][val]);
            return true;
          }()) ;
    }

    getchar();
    puts("");
  }


  return 0;
}
