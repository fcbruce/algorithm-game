/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 28 Feb 2015 05:08:21 PM CST
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
#define maxn 1007

using namespace std;

int a[maxn],st[maxn];
int top;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n),n!=0)
  {
    while (scanf("%d",a),a[0]!=0)
    {
      for (int i=1;i<n;i++) scanf("%d",a+i);

      top=-1;
      
      int A=1,B=0;
      bool ok=true;
      while (B<n)
      {
        if (A==a[B])
        {
          A++;
          B++;
        }
        else if (top>=0 && st[top]==a[B])
        {
          top--;
          B++;
        }
        else if (A<=n) st[++top]=A++;
        else 
        {
          ok=false;
          break;
        }
      }

      puts(ok?"Yes":"No");
    }
    puts("");
  }



  return 0;
}
