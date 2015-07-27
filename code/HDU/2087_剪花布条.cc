/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 27 Jul 2015 10:57:15 AM CST
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

char T[maxn],P[maxn];
int nex[maxn];

inline void get_prefix(char P[],int nex[])
{
  nex[0]=-1;
  for (int i=1,j=-1;P[i]!='\0';i++)
  {
    while (j>-1 && P[j+1]!=P[i]) j=nex[j];
    if (P[j+1]==P[i]) j++;
    nex[i]=j;
  }
}

inline int kmp(char T[],char P[])
{
  int res=0;
  get_prefix(P,nex);
  for (int i=0,j=-1;T[i]!='\0';i++)
  {
    while (j>-1 && P[j+1]!=T[i]) j=nex[j];
    if (P[j+1]==T[i]) j++;
    if (P[j+1]=='\0')
    {
      res++;
      j=-1;
    }
  }
  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s",T),T[0]!='#')
  {
    scanf("%s",P);
    printf("%d\n",kmp(T,P));
  }



  return 0;
}
