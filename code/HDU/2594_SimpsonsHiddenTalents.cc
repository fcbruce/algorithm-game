/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 27 Jul 2015 04:34:00 PM CST
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
#define maxn 50007

using namespace std;

char s1[maxn],s2[maxn];
int nex[maxn];

void get_prefix()
{
  nex[0]=-1;
  for (int i=1,j=-1;s1[i]!='\0';i++)
  {
    while (j>-1 && s1[j+1]!=s1[i]) j=nex[j];
    if (s1[j+1]==s1[i]) j++;
    nex[i]=j;
  }
}

int KMP()
{
  get_prefix();
  for (int i=0,j=-1;s2[i]!='\0';i++)
  {
    while (j>-1 && s1[j+1]!=s2[i]) j=nex[j];
    if (s1[j+1]==s2[i]) j++;
    if (s2[i+1]=='\0') return j+1;
  }
}

inline bool check(int l,int l2)
{
  if (l>l2) return false;
  printf("%d\n",l);

  for (int i=0;i<l;i++) if (s1[i]!=s2[l2-l+i]) return false;
  puts("ok");

  return true;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%s%s",s1,s2) == 2)
  {
    int res=KMP();
    s1[res]='\0';
    if (res==0) puts("0");
    else printf("%s %d\n",s1,res);
  }



  return 0;
}
