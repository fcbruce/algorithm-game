/*
 *
 * Author : fcbruce
 *
 * Time : Mon 29 Sep 2014 03:15:32 PM CST
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
#define maxn 2333333

using namespace std;

char s[maxn],t[maxn];

bool
judge(char *s,char *t){
  int sl=strlen(s),tl=strlen(t);

  for (int i=0,j=0;i<sl;i++,j++){
    for (;j<tl && s[i]!=t[j];j++);
    if (j==tl) return false;
  }

  return true;
}

int
main(){
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (~scanf("%s %s",s,t)){
    if (judge(s,t))
      puts("Yes");
    else
      puts("No");
  }


  return 0;
}
