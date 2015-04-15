/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 12 Apr 2015 06:11:17 PM CST
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
#define maxn 1000007

using namespace std;

char s[233];
int n;

long long q[maxn];

void useq()
{
  int f=0,r=-1;
  while (n--)
  {
    scanf("%s",s);
    if (strcmp(s,"IN")==0)
    {
      long long v;
      scanf(lld,&v);
      q[++r]=v;
    }
    else
    {
      if (f<=r) printf(lld"\n",q[f++]);
      else puts("None");
    }
  }
}

void usest()
{
  int f=0,r=-1;
  while (n--)
  {
    scanf("%s",s);
    if (strcmp(s,"IN")==0)
    {
      long long v;
      scanf(lld,&v);
      q[++r]=v;
    }
    else
    {
      if (f<=r) printf(lld"\n",q[r--]);
      else puts("None");
    }
  }
}
int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%d%s",&n,s);

    if (strcmp(s,"FIFO")==0) useq();
    else usest();
  }


  return 0;
}
