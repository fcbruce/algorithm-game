/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 12 Apr 2015 07:45:45 PM CST
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

int x[10];
int n;

char s[233];
int  lea[1024];
int b[233];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  while (scanf("%d",&n),n!=0)
  {
    printf("S-Tree #%d:\n",++__);
    for (int i=0;i<n;i++)
    {
      scanf("%s",s);
      
      x[i]=s[1]-'0';
    }

    for (int i=0;i<(1<<n);i++) scanf("%1d",lea+i);


    int k;
    scanf("%d",&k);
    memset(b,0,sizeof b);
    int cut=1<<n;
    cut-=1;
    for (int i=0;i<k;i++)
    {
      for (int j=1;j<=n;j++)
      {
        scanf("%1d",b+j);
      }
      int p=0;
      for (int j=0;j<n;j++)
      {
        if (b[x[j]]) p=p*2+2;
        else p=p*2+1;
      }
      printf("%d",lea[p-cut]);
    }
    puts("\n");
  }



  return 0;
}
