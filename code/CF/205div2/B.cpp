/*
 *
 * Author : fcbruce
 *
 * Time : Tue 30 Sep 2014 11:02:09 PM CST
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
#define maxn 233 

using namespace std;

struct _cube
{
  int x,id;
  bool operator < (const _cube &c)const
  {
    return x<c.x;
  }
}cube[maxn];

int ans[maxn];

set<int> _first,_second;

int _hash[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int n;
  scanf("%d",&n);

  for (int i=0;i<n*2;i++)
  {
    scanf("%d",&cube[i].x);
    cube[i].id=i;
    _hash[cube[i].x]++;
  }

  sort(cube,cube+n*2);
  int cnt1=0;
  for (int i=0;i<n*2;i++)
  {
    if (_hash[cube[i].x]==0) continue;
    if (_hash[cube[i].x]==1)
    {
      if (_first.size()<_second.size())
      {
        _first.insert(cube[i].x);
        cnt1++;
        ans[cube[i].id]=1;
        cube[i].id=-1;
      }
      else
      {
        _second.insert(cube[i].x);
        ans[cube[i].id]=2;
        cube[i].id=-1;
      }
    }
    else
    {
      if (_first.count(cube[i].x)==0)
      {
        _first.insert(cube[i].x);
        cnt1++;
        ans[cube[i].id]=1;
        cube[i].id=-1;
      }
      else if (_second.count(cube[i].x)==0)
      {
        _second.insert(cube[i].x);
        ans[cube[i].id]=2;
        cube[i].id=-1;
      }
      //else if (last==1)
      //{
      //  _second.insert(cube[i].x);
      //  ans[cube[i].id]=2;
      //  last=2;
      //}
      //else
      //{
      //  _first.insert(cube[i].x);
      //  ans[cube[i].id]=1;
      //  last=1;
      //}
    }
  }

  for (int i=0;i<n*2;i++)
  {
    if (cube[i].id==-1) continue;
    if (cnt1<n)
    {
      ans[cube[i].id]=1;
      cnt1++;
    }
    else
    {
      ans[cube[i].id]=2;
    }
  }

  printf("%d\n",_first.size()*_second.size());

  for (int i=0;i<n*2;i++)
    printf("%d ",ans[i]);


  return 0;
}
