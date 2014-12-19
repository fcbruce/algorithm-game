/*
 *
 * Author : fcbruce
 *
 * Time : Fri 26 Sep 2014 11:50:06 PM CST
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

long long a[33334],s[33334];

int
main(){
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);
  
  a[0]=0;s[0]=0;
  for (int i=1;i<33333;i++){
    a[i]=a[i-1]+(int)log10(i)+1;
    s[i]=s[i-1]+a[i];
  }
  
  
  while (T_T--){
    long long n;
    scanf("%lld",&n);
    int pos=lower_bound(s,s+33333,n)-s-1;
    long long op=1,rest;
    for (long long i=s[pos++];i<n;){
      int l=log10(op)+1;
      if (i+l<n){
        i+=l;
        op++;
      }
      else{
        rest=n-i;
        break;
      }
    }

    int l=log10(op)+1;
    int k=pow(10,l-rest);
    printf("%d\n",(op/k)%10);

  }


  return 0;
}
