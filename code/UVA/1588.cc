/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 07:40:02 PM CST
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

char s1[233],s2[233];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s %s",s1,s2)==2)
  {
    auto judge = [](const char *s1,const char *s2,int l1,int l2)
    {
      for (int i=0;i<l2;i++)
      {
        if ([&]()
            {
              for (int j=0;j<l1 && i+j<l2;j++)
                if (s1[j]=='2' && s2[i+j]=='2') return false;
              return true;
            }()) 
          return max(l2,i+l1);
        
      }
      return l1+l2;
    };

    int l1=strlen(s1),l2=strlen(s2);

    int MIN=l1+l2;
    MIN=min(MIN,judge(s1,s2,l1,l2));
    MIN=min(MIN,judge(s2,s1,l2,l1));

    printf("%d\n",MIN);
  }


  return 0;
}
