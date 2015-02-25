#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm 10001

using namespace std;

int a[mm];
int n,q,x,*y,tt=1;


int main()
{
  #ifndef ONLINE_JUDGE
    freopen("t","r",stdin);
  #endif

  while (scanf("%d%d",&n,&q),n||q)
  {
    printf("CASE# %d:\n",tt++);
    for (int i=0;i<n;i++)
    {
      scanf("%d",a+i);
    }

    sort(a,a+n);

    for (int i=0;i<q;i++)
    {
      scanf("%d",&x);
      y=lower_bound(a,a+n,x);
      if ((*y)==x)
        printf("%d found at %ld\n",x,y-a+1);
      else
        printf("%d not found\n",x);
    }
  }
  
  return 0;
}
