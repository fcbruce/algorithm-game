/*
 *
 * Author : fcbruce
 *
 * Time : Fri 26 Sep 2014 09:45:33 PM CST
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

char str[233];

int
_less(int a,int b,int l){
  for (int i=0;i<l;i++)
    if (str[(a+i)%l]!=str[(b+i)%l]) return str[(a+i)%l]-str[(b+i)%l];

  return 0;
}

int
main(){
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--){
    scanf("%s",str);
    int l=strlen(str);
    int min_begin=0;
    for (int i=1;i<l;i++){
      if (_less(i,min_begin,l)<0) min_begin=i;
    }
    for (int i=0;i<l;i++) putchar(str[(i+min_begin)%l]);
    putchar('\n');
  }


  return 0;
}
