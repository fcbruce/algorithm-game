/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 28 Nov 2014 02:49:12 PM CST
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

double mol[]={12.01,1.008,16.00,14.01};//CHON

inline int id(char c)
{
  switch(c)
  {
    case 'C':return 0;
    case 'H':return 1;
    case 'O':return 2;
    case 'N':return 3;
  }
  return -1;
}

char str[233];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%s",str);

    double total=0.0;
    int res=0;
    double m=0.0;

    for (int i=0;str[i]!='\0';i++)
    {
      if (isdigit(str[i])) res=res*10+str[i]-'0';
      else
      {
        total+=max(1,res)*m;
        res=0;
        m=mol[id(str[i])];
      }
    }

    total+=max(1,res)*m;

    printf("%.3f\n",total);
  }



  return 0;
}
