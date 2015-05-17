/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 07:44:28 PM CST
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

char str[233];
char s[233];

int x[10];

bool rm[233];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  scanf("%d%d",&n,&m);

  scanf("%s",str);

  while (m--)
  {
    int l,r;
    scanf("%d%d",&l,&r);
    l--;r--;

    int p=l;
    int d=1;

    memset(x,0,sizeof x);
    memset(rm,0,sizeof rm);
    strcpy(s,str);
    int last=-1;
    while (l<=p && p<=r)
    {
      if (isdigit(s[p]))
      {
        x[s[p]-'0']++;
        if (s[p]=='0') rm[p]=true;
        else s[p]--;
      }
      else
      {
        if (last!=-1 && !isdigit(s[last])) rm[last]=true;
        if (s[p]=='<') d=-1;
        else d=1;
      }
      last=p;
      p+=d;
      while (rm[p]) p+=d;
    }
    for (int i=0;i<10;i++) printf("%d ",x[i]);
    puts("");
  }



  return 0;
}
