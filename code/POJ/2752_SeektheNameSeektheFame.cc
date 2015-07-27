/*
 *
 * Author : fcbruce
 *
 * Time : Wed 01 Oct 2014 04:24:21 PM CST
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
#define maxn 400004

using namespace std;

char str[maxn];
int nex[maxn],q[maxn];

void get_prefix(char *P,int nex[])
{
  nex[0]=-1;
  for (itn i=1,j=-1;P[i]!='\0';i++)
  {
    while (j>-1 && P[j+1]!=P[i]) j=nex[j];
    if (P[j+1]==P[i]) j++;
    nex[i]=j;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (~scanf("%s",str))
  {
    get_prefix(str,nex);

    int j,f=0,r=-1;
    j=strlen(str)-1;

    for (int p=j;~p;p=nex[p])
      q[++r]=p+1;

    while (f<r)
      printf("%d ",q[r--]);

    printf("%d",j+1);

    putchar('\n');
  }


  return 0;
}
