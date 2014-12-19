/*
 *
 * Author : fcbruce
 *
 * Time : Thu 02 Oct 2014 06:28:26 PM CST
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
#define maxn 100007

using namespace std;

char P[maxn];
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

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s",P),P[0]!='*')
  {
    get_prefix(P,nex);

    int l=strlen(P);

    printf("%d\n",l%(l-1-nex[l-1])==0?l/(l-1-nex[l-1]):1);
  }


  return 0;
}
