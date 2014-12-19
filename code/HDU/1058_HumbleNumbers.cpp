/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Tue 28 Oct 2014 01:46:32 PM CST
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

priority_queue<LL,vector<LL>,greater<LL> > q;
set<LL> Set;
long long hn[6666];
int mul[]={2,3,5,7};

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;

  q.push(1ll);
  Set.insert(1ll);
  for (int i=1;i<=5842;i++)
  {
    hn[i]=q.top();q.pop();
    for (int j=0;j<4;j++)
    {
      LL x=hn[i]*mul[j];
      if (Set.count(x)==0)
      {
        q.push(x);
        Set.insert(x);
      }
    }
  }

  while (scanf("%d",&n),n)
  {
    printf("The %d",n);

    if (n%10==1 && n%100!=11) printf("st");
    else if (n%10==2 && n%100!=12) printf("nd");
    else if (n%10==3 && n%100!=13) printf("rd");
    else printf("th");

    printf(" humble number is "lld".\n",hn[n]);
  }


  return 0;
}
