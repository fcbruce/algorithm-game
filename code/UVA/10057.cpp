/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  
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

#define maxm 1000007
#define maxn 65537

using namespace std;

int X[maxn],a[maxm];
long long _hash[maxn];

inline int
ReadInt()
{
  int flag=0;
  char ch = getchar();
  int data = 0;
  while (ch < '0' || ch > '9')
  {
    if(ch=='-') flag=1;
    ch = getchar();
  }
  do
  {
    data = data*10 + ch-'0';
    ch = getchar();
  }while (ch >= '0' && ch <= '9');
  if(flag) data=-data;
  return data;
}


int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int n;
  while (~scanf("%d",&n))
  {
    memset(X,0,sizeof X);
    int MAX=0,MIN=INF;
    for (int i=0,x;i<n;i++)
    {
      x=ReadInt();
      a[i]=x;
      X[x]++;
      MIN=min(MIN,x);
      MAX=max(MAX,x);
    }
    
    sort(a,a+n);
    int A=a[(n+1)/2-1];
    
    long long minsum=0;
    for (int i=MIN;i<=MAX;i++) minsum+=(long long)abs(A-i)*X[i];
    long long sum=0;
    for (int i=MIN;i<=MAX;i++) sum+=(long long)abs(a[(n+1)/2]-i)*X[i];
    if (sum<minsum)
    {
      minsum=sum;
      A=a[(n+1)/2];
    }
    
    
    int cnt=0,cnt_diff=0;
    for (int i=MIN;i<=MAX;i++)
    {
      sum=0;
      for (int j=MIN;j<=MAX;j++)
      {
        sum+=(long long)abs(j-i)*X[j];
      }
      if (sum==minsum)
      {
        cnt_diff++;
        cnt+=X[i];
      }
    }
    
    
      
    printf("%d %d %d\n",A,cnt,cnt_diff);
  }
  
  return 0;
}



