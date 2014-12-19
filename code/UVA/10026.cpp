/*
 *
 * Author : fcbruce
 *
 * Time : Mon 29 Sep 2014 04:38:59 PM CST
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

struct _job{
  int a,b,id;
  bool
  operator < (const _job &job)const{
    if (a*job.b==job.a*b) return id<job.id;
    return a*job.b<job.a*b;
  }
}job[maxn];

int
main(){
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--){
    int n;
    scanf("%d",&n);
    
    for (int i=0,a,b;i<n;i++){
      scanf("%d%d",&a,&b);
      job[i]=(_job){a,b,i+1};
    }

    sort(job,job+n);

    for (int i=0;i<n;i++){
      if (i>0) putchar(' ');
      printf("%d",job[i].id);
    }
    putchar('\n');

    if (T_T) putchar('\n'); 
  }


  return 0;
}
