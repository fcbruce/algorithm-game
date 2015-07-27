/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 27 Jul 2015 02:26:57 PM CST
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

char s[maxn];
int nex[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    scanf("%s",s);
    
    nex[0]=-1;
    for (int i=1,j=-1;s[i]!='\0';i++)
    {
      while (j>-1 && s[j+1]!=s[i]) j=nex[j];
      if (s[j+1]==s[i]) j++;
      nex[i]=j;
    }

    int len=strlen(s);
    int gap=len-1-nex[len-1];
    printf("%d\n",len%gap==0 && len!=gap?0:gap-len%gap);
  }



  return 0;
}
