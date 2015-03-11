/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 08 Mar 2015 07:58:27 PM CST
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

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  while (scanf("%d",&n)==1)
  {
    if (n==1)
    {
      puts("14");
      continue;
    }
    if (n==2)
    {
      puts("155");
      continue;
    }
    printf("1575");
    for (int i=3;i<n;i++) printf("0");
    puts("");
  }



  return 0;
}
