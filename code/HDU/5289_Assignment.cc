/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Thu 23 Jul 2015 10:24:25 AM CST
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

int lg2[maxn],minv[maxn][20],maxv[maxn][20];

inline int readint()
{
  bool flag=false;
  char ch=getchar();
  int data=0;
  while (ch<'0' || ch>'9')
  {
    if (ch=='-') flag=true;
    ch=getchar();
  }
  do
  {
    data=data*10+ch-'0';
    ch=getchar();
  } while ('0'<=ch && ch<='9');
  if (flag) return -data;
  return data;
}

inline void init_st(int n)
{
  lg2[1]=0;
  for (int i=2;i<=n;i++)
  {
    lg2[i]=lg2[i-1];
    if ((1<<lg2[i]+1)==i) lg2[i]++;
  }
  for (int i=n-1;i>=0;i--)
  {
    maxv[i][0]=minv[i][0]=readint();
    for (int j=1;(i+(1<<j)-1)<n;j++)
    {
      maxv[i][j]=max(maxv[i][j-1],maxv[i+(1<<j-1)][j-1]);
      minv[i][j]=min(minv[i][j-1],minv[i+(1<<j-1)][j-1]);
    }
  }
}

inline pair<int,int> query(int l,int r)
{
  int k=lg2[r-l];
  return make_pair(max(maxv[l][k],maxv[r-(1<<k)][k]),min(minv[l][k],minv[r-(1<<k)][k]));
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE


  int T_T=readint();

  while (T_T--)
  {
    int n=readint(),k=readint();
    init_st(n);
    long long res =0ll;
    for (int i=0;i<n;i++)
    {
      int l=i,r=n;
      int pos=l+1;
      while (l<=r)
      {
        int mid=l+r>>1;
        pair<int,int> M=query(i,mid);
        if (M.first-M.second<k)
        {
          pos=mid;
          l=mid+1;
        }
        else r=mid-1;
      }
      res += pos - i;
    }

    printf(lld "\n",res);
  }


  return 0;
}
