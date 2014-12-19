/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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

#define maxm 100001
#define maxn 1<<15

using namespace std;

int prime[maxn];
bool isprime[maxn];
int cnt;
bool vis[maxm];

void
build()
{
  cnt=0;
  memset(isprime,1,sizeof isprime);
  isprime[0]=isprime[1]=false;
  for (int i=2;i<maxn;i++)
  {
    if (isprime[i])
    {
      prime[cnt++]=i;
      for (int j=i<<1;j<maxn;j+=i) isprime[j]=false;
    }
  }
}

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  build();
  
  int T_T;
  scanf("%d",&T_T);
  
  while (T_T--)
  {
    int l,r;
    scanf("%d%d",&l,&r);
    
    memset(vis,0,sizeof vis);
    for (int i=0;i<cnt;i++)
    {
      int begin=max(l/prime[i],2)*prime[i];
      for (int j=begin;j<=r;j+=prime[i])
      {
        if (j>=l) vis[j-l]=true;
      }
    }
    
    for (int i=l;i<=r;i++)
      if (i>1 && !vis[i-l]) printf("%d\n",i);
      
    if (T_T) putchar('\n');
  }
  
  return 0;
}



