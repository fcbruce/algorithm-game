/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 04:42:27 PM CST
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

int vis[10][3333];
int res[33333];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int a,b;
  
  while (scanf("%d%d",&a,&b)==2)
  {
    printf("%d/%d = %d.",a,b,a/b);
    a%=b;
    a*=10;

    int left,right;

    memset(vis,-1,sizeof vis);
    for (int i=0;;i++)
    {
      res[i]=a/b;
      a%=b;
      if (vis[res[i]][a]>=0)
      {
        left=vis[res[i]][a];
        right=i;
        break;
      }
      vis[res[i]][a]=i;
      a*=10;
    }

    for (int i=0;i<right;i++)
    {
      if (i==left) putchar('(');
      if (i==50)
      {
        if (left>50) putchar('(');
        printf("...");
        break;
      }
      putchar('0'+res[i]);
    }
    printf(")\n   %d = number of digits in repeating cycle\n\n",right-left);
  }


  return 0;
}
