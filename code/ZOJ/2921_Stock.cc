/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Wed 11 Mar 2015 06:21:35 PM CST
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

struct heapnode
{
  int p,n;
  bool operator < (const heapnode &rhs) const
  {
    return p<rhs.p;
  }
};

priority_queue<heapnode> q;

struct share
{
  int x,p,m;
  void read()
  {
    scanf("%d%d%d",&x,&p,&m);
  }
}shares[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++) shares[i].read();

    long long res=0;
    while (!q.empty()) q.pop();
    for (int i=n-1;i>=0;i--)
    {
      auto &e=shares[i];

      q.push({e.p,e.m});

      while (!q.empty() && e.x>0)
      {
        auto x=q.top();q.pop();
        int out=min(x.n,e.x);
        res+=out*x.p;
        x.n-=out;
        e.x-=out;
        if (x.n>0) q.push(x);
      }
    }

    printf(lld "\n",res);
  }



  return 0;
}
