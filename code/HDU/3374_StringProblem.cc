/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 03 Aug 2015 02:14:59 PM CST
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
#define maxn 1000007

using namespace std;

char s[maxn];
int nex[maxn];

inline void get_prefix(char *s)
{
  nex[0]=-1;
  for (int i=1,j=-1;s[i]!='\0';i++)
  {
    while (j>-1 && s[j+1]!=s[i]) j=nex[j];
    if (s[j+1]==s[i]) j++;
    nex[i]=j;
  }
}

int find(char *s,int l,int f)
{
  int i=0,j=1,k=0;
  while (i<l && j<l && k<l)
  {
    int d=s[(i+k)%l]-s[(j+k)%l];
    if (d==0) k++;
    else if (d*f>0)
    {
      j+=k+1;
      k=0;
      if (i==j) j++;
    }
    else
    {
      i+=k+1;
      k=0;
      if (i==j) i++;
    }
  }

  return min(i,j);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s",s)==1)
  {
    get_prefix(s);
    int l=strlen(s);
    int cnt= l%(l-1-nex[l-1])==0? l/(l-1-nex[l-1]) : 1;
    printf("%d %d %d %d\n",find(s,l,-1)+1,cnt,find(s,l,1)+1,cnt);
  }



  return 0;
}
