/*
 *
 * Author : fcbruce
 *
 * Time : Thu 02 Oct 2014 12:30:48 PM CST
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

#define maxm 100
#define maxn 10007

using namespace std;

int r,c;
int _width[maxm];
char str[maxn][maxm];
int nex[maxn];
unsigned long long P[maxn];

template<typename T>
void get_prefix(T *P,int nex[])
{
  nex[0]=-1;
  for (int i=1,j=-1;P[i];i++)
  {
    while (j>-1 && P[j+1]!=P[i]) j=nex[j];
    if (P[j+1]==P[i]) j++;
    nex[i]=j;
  }
}

unsigned long long BKDRHash(char *s,int l)
{
  unsigned long long seed=131ull,hash=0ull;

  for (int i=0;i<l;i++)
    hash=hash*seed+s[i];

  return hash;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d%d",&r,&c);

  int height,width;

  memset(_width,0,sizeof _width);

  for (int i=0;i<r;i++)
  {
    scanf("%s",str[i]);
    get_prefix(str[i],nex);
    for (int j=c-1;~j;j=nex[j])
      _width[c-1-nex[j]]++;
  }

  for (int i=1;i<=c;i++)
    if (_width[i]==r)
    {
      width=i;
      break;
    }

  for (int i=0;i<r;i++)
    P[i]=BKDRHash(str[i],width);
  P[r]=0ull;

  get_prefix(P,nex);

  for (int j=r-1;~j;j=nex[j])
  {
    height=r-1-nex[j];
    break;
  }

  printf("%d\n",width*height);

  return 0;
}
