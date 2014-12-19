/*
 *
 * Author : fcbruce
 *
 * Time : Tue 30 Sep 2014 12:10:09 AM CST
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
#define maxn 89

using namespace std;

char str[maxn];

int
main(){
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);
  

  while (T_T--){
    scanf("%s",str);

    int total_score=0;
    for (int i=0,l=strlen(str),single_score=0;i<l;i++){
      if (str[i]=='O')
        total_score+=++single_score;
      else
        single_score=0;
    }

    printf("%d\n",total_score);
  }


  return 0;
}
