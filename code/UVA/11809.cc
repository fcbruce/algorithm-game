/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 09:42:53 PM CST
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
#define maxn 33

using namespace std;

vector<int> v[maxn];
char s[maxn];
double M[11][maxn];
int E[11][maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  for (int i=0;i<10;i++) for (int j=1;j<=30;j++)
  {
    double x = 1 - pow(2,-(i+1));
    double y = (double)((1<<(j))-1);
    x=log10(x)+y*log10(2);
    E[i][j]=floor(x);
    M[i][j]=pow(10,x-E[i][j]);
  }

  while (scanf("%s",s),strcmp(s,"0e0")!=0)
  {
    double a;
    int b;
    s[17]=' ';
    sscanf(s,"%lf%d",&a,&b);
    
    long long TEMP;
    memset(&TEMP,0x7f,sizeof TEMP);
    double __eps=*(double *)(&TEMP);
    int __M,__E;

    for (int i=0;i<10;i++) for (int j=1;j<=30;j++)
    {
      if (E[i][j]!=b) continue;
      if (__eps>fabs(M[i][j]-a))
      {
        __M=i;
        __E=j;
        __eps=fabs(M[i][j]-a);
      }
    }

    printf("%d %d\n",__M,__E);
  }


  return 0;
}
