/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 17 May 2015 06:38:54 PM CST
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
#define maxn 300007

using namespace std;

int gcd[maxn<<4];
int minv[maxn<<4];
int a[maxn];

vector<pair<int,int> > info[maxn],ans;

inline int readint()
{
  int data=0;
  int c=getchar();
  bool flag=false;
  while (!isdigit(c))
  {
    if (c=='-') flag=true;
    c=getchar();
  }
  do
  {
    data=data*10+c-'0';
    c=getchar();
  } while (isdigit(c));
  if (flag) return -data;
  return data;
}

void build(int k,int l,int r)
{
  if (l+1==r)
  {
    minv[k]=gcd[k]=a[l];
    return ;
  }

  build(k*2+1,l,l+r>>1);
  build(k*2+2,l+r>>1,r);
  gcd[k]=__gcd(gcd[k*2+1],gcd[k*2+2]);
  minv[k]=min(minv[k*2+1],minv[k*2+2]);
}

pair<int,int> query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return {0,INF};
  if (a<=l && r<=b) return {gcd[k],minv[k]};

  auto v1=query(a,b,k*2+1,l,l+r>>1);
  auto v2=query(a,b,k*2+2,l+r>>1,r);
  return {__gcd(v1.first,v2.first),min(v1.second,v2.second)};
}

int Min(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return INF;
  if (a<=l && r<=b) return minv[k];

  return min(Min(a,b,k*2+1,l,l+r>>1),Min(a,b,k*2+2,l+r>>1,r));
}

bool check(int l,int n)
{
  info[l].clear();
  for (int i=0;i<n-l+1;i++) 
  {
    auto e=query(i,i+l,0,0,n);
    if (e.first==e.second)
      info[l].push_back({l,i});
  }

  return info[l].size()>0;
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n=readint();
  for (int i=0;i<n;i++) a[i]=readint();

  build(0,0,n);

  int MAX=0;

  int l=1,r=n;
  int res=1;
  while (l<=r) 
  {
    int mid=l+r>>1;

    if (check(mid,n))
    {
      res=mid;
      l=mid+1;
    }
    else r=mid-1;
  }

  printf("%d %d\n",(int)info[res].size(),res-1);
  for (auto e: info[res]) printf("%d ",e.second+1);

  return 0;
}
