/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 20 Feb 2015 10:02:14 AM CST
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

  LL n,p,q;

  while (scanf(lld lld lld,&n,&p,&q)==3)
  {
    LL k,a,b;
    memset(&k,0x3f,sizeof k);
    
    for (int i=0;i<32;i++) for (int j=0;j<32;j++)
    {
      LL total=((p*(n-1)+(p*(n-1)<<i))>>j)+q;
      if (total>=n*q && total<k)
      {
        k=total;
        a=i;
        b=j;
      }
    }

    printf(lld " " lld " " lld "\n",k,a,b);
  }



  return 0;
}
