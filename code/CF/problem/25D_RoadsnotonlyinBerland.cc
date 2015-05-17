/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 06:23:24 PM CST
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

vector<pair<int,int> > res;

int pre[1007];

int root(int x)
{
  if (x==pre[x]) return x;
  return pre[x]=root(pre[x]);
}

inline bool same(int x,int y) 
{
  return root(x)==root(y);
}

inline void merge(int x,int y)
{
  pre[root(x)]=root(y);
}


int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  for (int i=1;i<=n;i++) pre[i]=i;

  for (int i=1;i<n;i++) {
    int u,v;
    scanf("%d%d",&u,&v);
    if (!same(u,v)) merge(u,v);
    else res.push_back({u,v});
  }

  printf("%d\n",(int)res.size());
  int k=0;

  for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (!same(i,j)) 
  {
    merge(i,j);
    printf("%d %d ",res[k].first,res[k].second);
    printf("%d %d\n",i,j);
    k++;
  }



  return 0;
}
