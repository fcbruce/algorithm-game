/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 15 Jan 2015 04:06:50 PM CST
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

char dna[55][1111];
char res[1111];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n,m;
    scanf("%d%d",&n,&m);
    
    for (int i=0;i<n;i++) scanf("%s",dna[i]);

    int diff=0;

    for (int i=0;i<m;i++)
    {
      int a,t,c,g;
      a=t=c=g=0;
      for (int j=0;j<n;j++)
      {
        switch (dna[j][i])
        {
          case 'A':
            a++;
            break;
          case 'T':
            t++;
            break;
          case 'C':
            c++;
            break;
          case 'G':
            g++;
            break;
          }
      }

      if (a>=t && a>=c && a>=g)
      {
        res[i]='A';
        diff+=c+t+g;
      }
      else if (c>=a && c>=t && c>=g)
      {
        res[i]='C';
        diff+=a+g+t;
      }
      else if (g>=a && g>=c && g>=t)
      {
        res[i]='G';
        diff+=a+c+t;
      }
      else
      {
        res[i]='T';
        diff+=a+c+g;
      }
    }

    res[m]='\0';
    puts(res);
    printf("%d\n",diff);
  }


  return 0;
}
