/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 08:05:57 PM CST
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
#define maxn 200007

using namespace std;

struct info
{
  int id,d;
  bool operator < (const info &rhs) const
  {
    return d<rhs.d;
  }
}a[maxn];

vector<pair<int,int> > res;

priority_queue<info> q;
stack<info> st;

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n,m;
  int k=0;
  int M=0;
  scanf("%d%d",&n,&m);

  for (int i=1,v;i<=n;i++) 
  {
    scanf("%d",&v);
    if (v==0) continue;
    M=max(M,v);
    a[i]={i,v};
    q.push(a[i]);
    k++;
  }

  if (M>=k) 
  {
    puts("No");
    return 0;
  }
  

  while (!q.empty())
  {
    info x=q.top();q.pop();
    if (x.d!=a[x.id].d) continue;

    while (x.d--)
    {
      info g;
      if (q.empty()) 
      {
        puts("No");
        return 0;
      }
      while (!q.empty())
      {
        g=q.top();q.pop();
        if (g.d==a[g.id].d) break;
      }
      g.d--;
      a[g.id].d--;
      res.push_back({g.id,x.id});
      if (g.d!=0) st.push(g);
    }
    a[x.id].d=0;
    while (!st.empty()) 
    {
      q.push(st.top());
      st.pop();
    }
  }

  puts("Yes");

  if (res.size()!=0) printf("%d\n",(int)res.size());
  for (auto e:res) printf("%d %d\n",e.first,e.second);

  return 0;
}
