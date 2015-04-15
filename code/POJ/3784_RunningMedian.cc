/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 12 Apr 2015 08:45:10 PM CST
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
#define maxn 10007

using namespace std;

long long a[maxn];
long long x[maxn];

int cnt[maxn<<2];

vector<long long> res;

void update(int p,int k,int l,int r)
{
  if (l+1==r)
  {
    cnt[k]++;
    return ;
  }

  int m=l+r>>1;

  if (p<m) update(p,k*2+1,l,m);
  else update(p,k*2+2,m,r);

  cnt[k]=cnt[k*2+1]+cnt[k*2+2];
}

int query(int a,int b,int k,int l,int r)
{
  if (b<=l || r<=a) return 0;
  if (a<=l && r<=b) return cnt[k];
  
  return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  int T_T;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int id;
    scanf("%d",&id);
    int n;
    scanf("%d",&n);

    res.clear();
    memset(cnt,0,sizeof cnt);
    for (int i=0;i<n;i++) 
    {
      scanf(lld,a+i);
      x[i+1]=a[i];
    }

    sort(x+1,x+n+1);
    int xn=unique(x+1,x+n+1)-x;

    for (int i=0;i<n;i++)
    {
      int p=lower_bound(x+1,x+n+1,a[i])-x;
      update(p,0,0,xn);
      if (i%2==0)
      {
        int l=1,r=xn-1;
        int ret;
        while (l<=r)
        {
          int mid=l+r>>1;

          int lc=query(0,mid,0,0,xn);
          int rc=query(mid+1,xn,0,0,xn);
          int pos=query(mid,mid+1,0,0,xn);

          if (lc<=i/2 && rc<=i/2 && pos!=0)
          {
            ret=x[mid];
            break;
          }

          if (lc<rc)
          {
            l=mid+1;
          }
          else
          {
            r=mid-1;
          }
        }
        res.push_back(ret);
      }
    }

    printf("%d %d",id,(int)res.size());
    for (int i=0;i<res.size();i++)
    {
      if (i%10==0) putchar('\n');
      else putchar(' ');
      printf(lld,res[i]);
    }
    puts("");
  }




  return 0;
}
