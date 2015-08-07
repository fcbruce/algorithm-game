/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Fri 07 Aug 2015 09:44:57 AM CST
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

int n,p,k;

struct order
{
  int a,b;
  int id;
  bool operator < (const order &rhs) const
  {
    return a>rhs.a;
  }
}orders[maxn],orderb[maxn];

bool cmp(const order &lhs,const order &rhs)
{
  return lhs.b==rhs.b? lhs.a>rhs.a : lhs.b<rhs.b;
}

bool vis[maxn];


int solve()
{
  priority_queue<order> q;
  memset(vis,false,sizeof vis);
  int pos;
  for (int i=n-1;i>=p-k;i--)
  {
    if (q.size()<k)
    {
      vis[orders[i].id]=true;
      q.push(orders[i]);
      pos=i;
    }
    else if(orders[i].a>q.top().a)
    {
      vis[q.top().id]=false;
      q.pop();
      vis[orders[i].id]=true;
      q.push(orders[i]);
      pos=i;
    }
  }
  return pos;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  scanf("%d%d%d",&n,&p,&k);

  for (int i=0,a,b;i<n;i++)
  {
    scanf("%d%d",&a,&b);
    orders[i]={a,b,i+1};
  }

  sort(orders,orders+n,cmp);
  
  int pos=solve();

  for (int i=pos-(p-k);i<pos;i++) printf("%d ",orders[i].id);
  for (int i=pos;i<n;i++) if (vis[orders[i].id]) printf("%d ",orders[i].id);


  return 0;
}
