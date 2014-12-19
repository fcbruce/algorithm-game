/*
 *
 * Author : fcbruce
 *
 * Time : Wed 01 Oct 2014 04:54:28 PM CST
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

#define maxm 1000007
#define maxn 10007

using namespace std;

char T[maxm],P[maxn];
int nex[maxn];

void get_prefix(char *P,int nex[])
{
  nex[0]=-1;
  for (int i=1,j=-1;P[i]!='\0';i++)
  {
    while (j>-1 && P[j+1]!=P[i]) j=nex[j];
    if (P[j+1]==P[i]) j++;
    nex[i]=j;
  }
}

int KMP(char *T,char *P,int nex[])
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
      j=nex[j];
    }
  }

  return res;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%s %s",P,T);

    printf("%d\n",KMP(T,P,nex));
  }


  return 0;
}
