/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 05 Apr 2015 12:50:19 AM CST
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

int d;

int n;

long long a[32768];

long long solve(int x)
{
  if (x>n) return 0;
  
  long long res=solve(x*2+1)+solve(x*2+2);
  long long add=abs(a[x*2+1]-a[x*2+2]);
  a[x*2+1]=a[x*2+2]=max(a[x*2+1],a[x*2+2]);

  a[x]+=a[x*2+1];

  return res+add;
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d",&d);

  n=2;
  for (int i=0;i<d;i++) n<<=1;
  n-=2;

  for (int i=1;i<=n;i++) scanf(lld,a+i);


  printf(lld"\n",solve(0));





  return 0;
}
