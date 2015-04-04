/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 04 Apr 2015 07:01:13 PM CST
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

bool judge(char *s)
{
  int i=0;
  char ch=s[i];
  i++;
  int cnt=0;
  for (;;i++) if (s[i]!=ch) {
    cnt=i;
    ch=s[i];
    break;
  }

  for (int j=0;;i++,j++) if (s[i]!=ch) {
    if (s[i]==s[0]) return false;
    if (cnt!=j) return false;
    ch=s[i];
    break;
  }

  for (int j=0;;i++,j++) if (s[i]!=ch) {
    if (s[i]!='\0') return false;
    if (cnt!=j) return false;
    ch=s[i];
    break;
  }

  return true;

}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s",s)==1) 
  {
    bool k=judge(s);
    puts(k?"YES":"NO");
  }




  return 0;
}
