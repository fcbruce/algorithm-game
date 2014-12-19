/*
 *
 * Author : fcbruce
 *
 * Time : Mon 29 Sep 2014 02:59:05 PM CST
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

#define maxm 1000010
#define maxn 1001

using namespace std;

int a[maxn],s[maxm];

int
main(){
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0,n;

  while (scanf("%d",&n),n!=0){
    int cnt=0;

    for (int i=0;i<n;i++){
      scanf("%d",a+i);
      for (int j=0;j<i;j++) s[cnt++]=a[i]+a[j];
    }

    sort(s,s+cnt);
    cnt=unique(s,s+cnt)-s;

    printf("Case %d:\n",++__);

    int m,q;
    scanf("%d",&m);
    
    while (m--){
      scanf("%d",&q);
      int id=lower_bound(s,s+cnt,q)-s;

      if (id==0)
        printf("Closest sum to %d is %d.\n",q,s[id]);
      else
        printf("Closest sum to %d is %d.\n",q,abs(s[id]-q)<abs(s[id-1]-q)?s[id]:s[id-1]);
    }
  }



  return 0;
}
