/*
 *
 * Author : fcbruce
 *
 * Time : Wed 01 Oct 2014 03:28:23 PM CST
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

char str[maxn];
int nex[maxn];
int n;

void get_prefix()
{
  nex[0]=-1;
  for (int i=1,j=-1;i<n;i++)
  {
    while (j>-1 && str[j+1]!=str[i]) j=nex[j];
    if (str[j+1]==str[i]) j++;
    nex[i]=j;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int __=0;

  while (scanf("%d",&n),n!=0)
  {
    printf("Test case #%d\n",++__);
    scanf("%s",str);

    get_prefix();

    for (int i=0;i<n;i++)
    {
      if (nex[i]>=0 && (i+1)%(i-nex[i])==0)
        printf("%d %d\n",i+1,(i+1)/(i-nex[i]));
    }

    putchar('\n');
  }


  return 0;
}
