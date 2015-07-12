/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 11 Jul 2015 07:42:59 PM CST
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

long long dp[20][20];
int digit[20];

long long number(int pos,bool top)
{
  long long res=top?0:1;
  int p=pos;
  while (pos-->0) res = res * 10;
  if (!top) return res;
  long long tmp=0;
  p--;
  while (p!=-1) tmp = tmp * 10 + digit[p--];
  res+=tmp;
  res++;
  return res;
}

long long dfs(int pos,int pre,bool top,bool begin)
{
  if (pos<=0) return 1;
  if (!top && begin && dp[pos][pre]!=-1) return dp[pos][pre];
  int r=top?digit[pos]:9;
  long long res=0;
  for (int i=0;i<=r;i++) res+=dfs(pos-1,i,top && i==r,begin || i!=0);
  if (begin) res+=number(pos,top && 0==r);
  if (!top && begin) return dp[pos][pre]=res;
  return res;
}

long long calc(long long x)
{
  if (x<0) return 0;
  int pos=0;
  while (x!=0)
  {
    digit[pos++]=x%10;
    x/=10;
  }
  return dfs(pos-1,0,true,false);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  LL l,r;
  memset(dp,-1,sizeof dp);
  
  while (scanf("%lld%lld",&l,&r),l>=0)
  {
    printf("%lld\n",calc(r)-calc(l-1));
  }



  return 0;
}
