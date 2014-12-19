/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 06 Nov 2014 03:50:45 PM CST
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

char G[1007][1007];
int x[1007],y[1007];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  x[0]=0;
  y[0]=0;
  int MAX=0,MIN=0;
  for (int i=1,sign=1,a;i<=n;i++,sign*=-1)
  {
    scanf("%d",&a);
    x[i]=x[i-1]+a;
    y[i]=y[i-1]+a*sign;
    MAX=max(MAX,y[i]);
    MIN=min(MIN,y[i]);
  }

  memset(G,' ',sizeof G);
  for (int i=0;i<n;i++)
  {
    char add='/';
    int step=-1,move=-1;
    if (i&1)
    {
      add='\\';
      step=1;
      move=0;
    }
    for (int j=x[i],k=MAX-y[i];j<x[i+1];j++,k+=step)
      G[k+move][j]=add;
  }

  for (int i=0;i<MAX-MIN;i++)
  {
    for (int j=0;j<x[n];j++)
      putchar(G[i][j]);
    putchar('\n');
  }


  return 0;
}
