/*
 *
 * Author : fcbruce
 *
 * Time : Fri 26 Sep 2014 05:14:54 PM CST
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
#define maxn 1000001

using namespace std;

int a[maxn];

int
cal(int n){
  for (int i=0;i<=n;i++){
    int k=i;
    int res=i;
    while (k!=0){
      res+=k%10;
      k/=10;
    }
    if (a[res]==0) a[res]=i;
  }

  return 0;
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);
  memset(a,0,sizeof a);
  cal(1000000);
  while (T_T--){
    int n;
    scanf("%d",&n);
    printf("%d\n",a[n]);
  }

  return 0;
}
