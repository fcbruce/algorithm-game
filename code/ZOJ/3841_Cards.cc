/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 08 Apr 2015 09:46:56 PM CST
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

char s[233];

const long long mod=1000000007ll;

long long intv(long long x)
{
  long long k=mod-2;
  long long res=1ll;
  long long temp=x;
  while (k)
  {
    if (k&1)
    {
      res*=temp;
      res%=mod;
    }
    temp*=temp;
    temp%=mod;
    k>>=1;
  }
  return res;
}

long long in[64];

long long res;

long long rest[233];

int tod(char c)
{
  if (isdigit(c)) return c-'0';
  if (c=='A') return 1;
  if (c=='J') return 11;
  if (c=='Q') return 12;
  if (c=='K') return 13;
  return 10;

}

int d[233];

void calc()
{
  long long sum=0;
  for (int i=1;i<=13;i++)
  {
    sum+=rest[i];
  }
  long long temp=1;

  for (int i=1;i<=sum;i++)
  {
    temp*=i;
    temp%=mod;
  }

  for (int i=1;i<=13;i++) if (rest[i]>0)
  {
    for (int j=1;j<=rest[i];j++) 
    {
      temp*=in[j];
      temp%=mod;
    }
  }

  res+=temp;
  res%=mod;
}

void dfs(int p)
{
  if (!d[p])
  {
    return ;
  }
  int sum=0;
  for (int i=1;i<=13;i++) sum+=rest[i];
  if (sum==0) 
  {
    res++;
    return ;
  }
  for (int i=1;i<d[p];i++) 
  {
    if (rest[i]>0)
    {
      rest[i]--;
      calc();
      rest[i]++;
    }
  }

  if (rest[d[p]]>0) 
  {
    rest[d[p]]--;
    dfs(p+1);
    rest[d[p]]++;
  }

}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  for (int i=1;i<64;i++) in[i]=intv(i);

  while (scanf("%s",s)==1)
  {
    res=0;
    for (int i=1;i<=13;i++) rest[i]=4;

    memset(d,0,sizeof d);

    for (int i=0,j=0;s[i];i++)
    {
      if (s[i]=='1') 
      {
        rest[10]--;
        d[j++]=10;
        i++;
      }
      else
      {
        rest[tod(s[i])]--;
        d[j++]=tod(s[i]);
      }
    }


    dfs(0);

    printf("%lld\n",res);
    
  }




  return 0;
}
