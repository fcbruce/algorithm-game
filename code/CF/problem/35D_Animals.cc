/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 22 Mar 2015 07:07:14 PM CST
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

int a[2333];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  int n,m;
  scanf("%d%d",&n,&m);

  for (int i=0;i<n;i++) 
  {
    scanf("%d",a+i);
    a[i]*=(n-i);
  }

  sort(a,a+n);

  int res=0;

  for (int i=0;i<n;i++)
  {
    if (m>=a[i])
    {
      m-=a[i];
      res++;
    }
    else break;
  }

  printf("%d\n",res);




  return 0;
}
