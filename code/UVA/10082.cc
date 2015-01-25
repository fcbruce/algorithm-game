/*
 *
 * Author : fcbruce
 *
 * Time : Fri 26 Sep 2014 04:47:52 PM CST
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

char key[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif //FCBRUCE

  char ch;

  while (ch=getchar(),ch!=EOF)
  {
    bool flag=false;
    for (int i=0;key[i]!='\0';i++)
      if (key[i]==ch)
      {
        putchar(key[i-1]);
        flag=true;
        break;
      }

    if (!flag) putchar(ch);
  }

  return 0;
}
