/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 05 Dec 2014 06:41:35 PM CST
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

int solve()
{
  double s=-1,x,a=1,sum=1,p=1,i;
  x=-100;
  while (fabs(p)>1e-6)
  {
    i=sqr(x)/(a*(a+1));
    a++;
    p*=i;
    s=-s;
    sum+=p*s;
  }

  printf("%f\n",sum);

}






int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
/*
  int T_T;
  scanf("%d",&T_T);getchar();getchar();

  while (T_T--)
  {
    MAP.clear();
    while (gets(s),s[0]!='\0')
    {
      stringstream ss(s);
      ss>>str1;
      int l1=strlen(str1);
      str1[--l1]='\0';
      W=0;
      if (str1[l1-1]=='*')
      {
        W=1;

      }


    }

  }
*/
  solve();


  return 0;
}
