/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-25 11:11:28 
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
#define maxn 2333

using namespace std;

char buff[maxn];

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  bool first=true;
  while (fgets(buff,maxn,stdin)!=NULL)
  {
    for (int i=0;buff[i]!='\n';i++)
    {
      if (buff[i]=='\"')
      {
        if (first==true)
        {
          putchar('`');
          putchar('`');
          first=false;
        }
        else
        {
          putchar('\'');
          putchar('\'');
          first=true;
        }
      }
      else putchar(buff[i]);
    }
    putchar('\n');
  }
  
  return 0;
}



