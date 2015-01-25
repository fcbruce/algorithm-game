/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 28 Nov 2014 04:18:16 PM CST
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

bool judge(const char *s,int t)
{
  for (int i=0;s[i]!='\0';i++)
    if (s[i]!=s[i%t]) return false;
  
  return true;
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

    int l=strlen(s);

    for (int i=1;i<=l;i++)
    {
      if (l%i==0 && judge(s,i))
      {
        printf("%d\n",i);
        break;
      }
    }

    if (T_T) putchar('\n');
  }

  return 0;
}
