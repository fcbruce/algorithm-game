/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 24 Oct 2014 11:39:51 PM CST
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

struct _node
{
  int c,p,id;
  bool operator < (const _node &_)const
  {
    return p>_.p;
  }
}node[1007];

stack<int> r[1007];

int ans[1007][2];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  for (int i=0;i<n;i++)
  {
    scanf("%d%d",&node[i].c,&node[i].p);
    node[i].id=i+1;
  }
  sort(node,node+n);

  int k;
  scanf("%d",&k);
  for (int i=1,x;i<=k;i++)
  {
    scanf("%d",&x);
    r[x].push(i);
  }

  int m=0,s=0;
  for (int i=0;i<n;i++)
  {
    for (int j=node[i].c;j<=1000;j++)
    {
      if (!r[j].empty())
      {
        ans[m][0]=node[i].id;
        ans[m][1]=r[j].top();
        r[j].pop();
        m++;
        s+=node[i].p;
        break;
      }
    }
  }

  printf("%d %d\n",m,s);
  for (int i=0;i<m;i++)
  {
    printf("%d %d\n",ans[i][0],ans[i][1]);
  }


  return 0;
}
