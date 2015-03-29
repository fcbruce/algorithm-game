/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 28 Mar 2015 10:55:43 PM CST
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
#define maxn 50007

using namespace std;

long long a[maxn<<2],pref[maxn<<2];
long long sumv[maxn<<2],cntv[maxn<<2];
pair<LL,LL> MIN;

int n;
long long W,H;
long long rr;

inline LL readLL()
{
  long long res=0;
  bool flag=false;
  int ch=getchar();
  while (ch<'0' || '9'<ch)
  {
    if (ch=='-') flag=true;
    ch=getchar();
  }
  do
  {
    res=res*10+ch-'0';
    ch=getchar();
  } while ('0'<=ch && ch<='9');
  if (flag) return -res;
  return res;
}

void update(long long p,int cnt,int k,int l,int r)
{
  if (l+1==r)
  {
    sumv[k]+=cnt*p;
    cntv[k]+=cnt;
    return ;
  }

  int m=l+r>>1;
  if (p<m) update(p,cnt,k*2+1,l,m);
  else update(p,cnt,k*2+2,m,r);

  sumv[k]=sumv[k*2+1]+sumv[k*2+2];
  cntv[k]=cntv[k*2+1]+cntv[k*2+2];
}

pair<LL,LL> query(int a,int b,int k,int l,int r)
{
  if (r<=a || b<=l) return {0,0};
  if (a<=l && r<=b) return {sumv[k],cntv[k]};

  auto v1=query(a,b,k*2+1,l,l+r>>1);
  auto v2=query(a,b,k*2+2,l+r>>1,r);

  return {v1.first+v2.first,v1.second+v2.second};
}

inline void check(long long sumv,long long h)
{
  if (MIN.first==sumv)
  {
    MIN.second=max(MIN.second,h);
    return ;
  }
  if (MIN.first>sumv)
    MIN={sumv,h};

}

//[l,r)
inline void maintain(long long total,long long h,int l,int r)
{
  if (h*W>pref[n]) return ;
  auto sub=query(h,rr,0,0,rr);
  auto add=query(0,h,0,0,rr);

  long long res=max(sub.first-sub.second*h,add.second*h-add.first);

  check(res,h);
}

inline void solve()
{
  memset(sumv,0,sizeof(sumv[0])*rr<<2);
  memset(cntv,0,sizeof(cntv[0])*rr<<2);
  update(0,W,0,0,rr);
  for (int i=W;i<=n;i++)
  {
    //(i-W,i]
    update(a[i],1,0,0,rr);
    update(a[i-W],-1,0,0,rr);
    long long total=(pref[i]-pref[i-W]);
    long long aver=total/W;
    if (aver>=H) maintain(total,aver,i-W+1,i+1);
    else maintain(total,H,i-W+1,i+1);
    if (aver+1>=H) maintain(total,aver+1,i-W+1,i+1);
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE

  while (scanf("%d"lld lld,&n,&W,&H)==3)
  {
    memset(a,0,sizeof(a[0])*(n+W+W));
    rr=0;
    for (int i=1;i<=n;i++) rr=max(rr,a[i+W]=readLL());
    pref[0]=0;
    n+=2*W;
    for (int i=1;i<=n;i++) pref[i]=pref[i-1]+a[i];

    memset(&MIN,0x3f,sizeof (MIN));
    long long err=MIN.first;

    if (H*W<=pref[n]) solve();

    if (err==MIN.first) puts("-1");
    else printf(lld" "lld"\n",MIN.second,MIN.first);

  }




  return 0;
}
