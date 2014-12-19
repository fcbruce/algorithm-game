/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-21 13:07:59 
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

#define maxm 100010
#define maxn 100010

using namespace std;

struct node
{
  double x,h;
  bool operator < (const node &n)const
  {
    return x<n.x;
  }
}sky[maxn];

struct __q
{
  double x;
  int h;
  bool operator < (const __q &q)const
  {
    return x<q.x;
  }
}q[maxm];

inline double
dot(const pair<double,double> &v1,const pair<double,double> &v2)
{
  return v1.first*v2.first+v1.second*v2.second;
}

inline double
len(const pair<double,double> &v)
{
  return sqrt(sqr(v.first)+sqr(v.second));
}

pair<double,double> v_l[maxn],v_r[maxn];

int st[maxn];

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T,__=0;
  scanf("%d",&T_T);
  
  while (T_T--)
  {
    int n,m;
    
    scanf("%d",&n);
    for (int i=0;i<n;i++)
      scanf("%lf%lf",&sky[i].x,&sky[i].h);
      
    sort(sky,sky+n);
    
    scanf("%d",&m);
    
    for (int i=0;i<m;i++)
    {
      scanf("%lf",&q[i].x);
      q[i].h=i;
    }
    
    sort(q,q+m);
    
    for (int i=0,j=0,top=-1;i<m;i++)
    {
      while (j<n && sky[j].x<q[i].x)
      {
        while (top>-1 && sky[j].h>sky[st[top]].h-eps) top--;

        while (top>0 && (sky[st[top]].h-sky[j].h)*(sky[st[top]].x-sky[st[top-1]].x)<
                        (sky[st[top-1]].h-sky[st[top]].h)*(sky[j].x-sky[st[top]].x)+eps) top--;
        
        st[++top]=j++;
        
        while (top>0 && sky[st[top]].h*(q[i].x-sky[st[top-1]].x)<
                        sky[st[top-1]].h*(q[i].x-sky[st[top]].x)+eps) top--;
      }
      
      while (top>0 && sky[st[top]].h*(q[i].x-sky[st[top-1]].x)<
                      sky[st[top-1]].h*(q[i].x-sky[st[top]].x)+eps) top--;

      v_l[q[i].h]=make_pair(sky[st[top]].x-q[i].x,sky[st[top]].h);
    }
    
    for (int i=m-1,j=n-1,top=-1;i>=0;i--)
    {
      while (j>=0 && sky[j].x>q[i].x)
      {
        while (top>-1 && sky[j].h>sky[st[top]].h-eps) top--;
        
        while (top>0 && (sky[st[top]].h-sky[j].h)*(sky[st[top-1]].x-sky[st[top]].x)<
                        (sky[st[top-1]].h-sky[st[top]].h)*(sky[st[top]].x-sky[j].x)+eps) top--;
                        
        st[++top]=j--;
        
        while (top>0 && sky[st[top]].h*(sky[st[top-1]].x-q[i].x)<
                        sky[st[top-1]].h*(sky[st[top]].x-q[i].x)+eps) top--;
      }
      
      while (top>0 && sky[st[top]].h*(sky[st[top-1]].x-q[i].x)<
                      sky[st[top-1]].h*(sky[st[top]].x-q[i].x)+eps) top--;
      
      v_r[q[i].h]=make_pair(sky[st[top]].x-q[i].x,sky[st[top]].h);
    }
    
    printf("Case #%d:\n",++__);
    
    for (int i=0;i<m;i++)
      printf("%.10f\n",acos(dot(v_l[i],v_r[i])/(len(v_r[i])*len(v_l[i])))*180/PI);
  }
  
  return 0;
}



