/*
 *
 * Author : fcbruce
 *
 * Time : Mon 29 Sep 2014 03:31:05 PM CST
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
#define maxn 64

using namespace std;

struct node{
  int op;
  long long data;
}mul_first[maxn],plu_first[maxn];

char str[233];

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

    int mf=0,mr=-1,pf=0,pr=-1;

    long long data=0ll;
    for (int i=0;i<=l;i++){
      if (str[i]>='0' && str[i]<='9'){
        data=data*10+str[i]-'0';
      }
      else{
        if (mf<=mr && mul_first[mr].op==2){
          mr--;
          mul_first[mr].data*=data;
        }
        else{
          mul_first[++mr]=(node){0,data};
        }

        if (pf<=pr && plu_first[pr].op==1){
          pr--;
          plu_first[pr].data+=data;
        }
        else{
          plu_first[++pr]=(node){0,data};
        }

        data=0;

        int op=1;
        if (str[i]=='*') op++;

        mul_first[++mr]=plu_first[++pr]=(node){op,0};
      }
    }

    long long mul=0;
    for (int i=mf;i<=mr;i+=2) mul+=mul_first[i].data;
    
    long long plu=1;
    for (int i=pf;i<=pr;i+=2) plu*=plu_first[i].data;

    printf("The maximum and minimum are %lld and %lld.\n",max(mul,plu),min(mul,plu));
  }


  return 0;
}
