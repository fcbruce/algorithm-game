/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 07 Aug 2015 08:30:47 AM CST
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

  scanf("%d",&n);

  long long res=0;
  int one=0;

  for (int i=0,v;i<n;i++)
  {
    scanf("%d",&v);
    one+=v;
    if (v==0) res+=one;
  }

  printf(lld "\n",res);



  return 0;
}
