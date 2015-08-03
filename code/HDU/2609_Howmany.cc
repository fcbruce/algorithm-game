/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Mon 03 Aug 2015 03:24:07 PM CST
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

char tmp[101];

set<pair<LL,LL> > SET;

pair<LL,LL> find(char *s)
{
  int l=strlen(s);
  int i=0,j=1,k=0;
  while (i<l && j<l && k<l)
  {
    int d=s[(i+k)%l]-s[(j+k)%l];
    if (d>0)
    {
      i+=k+1;
      k=0;
      if (i==j) i++;
    }
    else if (d<0)
    {
      j+=k+1;
      k=0;
      if (i==j) j++;
    }
    else k++;
  }

  int begin=min(i,j);

  LL a[2]={0ll,0ll};

  for (int i=0;i<l;i++)
    a[i/50]|=(LL)(s[(begin+i)%l]-'0')<<(i%50);

  return make_pair(a[0],a[1]);
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  while (scanf("%d",&n)==1)
  {
    SET.clear();
    for (int i=0;i<n;i++)
    {
      scanf("%s",tmp);
      SET.insert(find(tmp));
    }
    printf("%ld\n",SET.size());
  }



  return 0;
}
