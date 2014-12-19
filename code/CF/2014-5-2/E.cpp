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
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int a[1234567];
int le[1234567];
int ri[1234567];
int n,m,nl,nr,l,r;
LL ans,x;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	scanf("%d%d",&n,&m);

	for (int i=0;i<n;i++)
        scanf("%d",a+i);

    l=0,r=n-1;
    nl=nr=0;

    while (r-l>=m)
    {
      //  printf("%d ",a[l]);
        le[nl++]=a[l];
        l+=m;
        if (r-l>=m)
        {
       //     printf("%d ",a[r]);
            ri[nr++]=a[r];
            r-=m;
        }
    }
    ri[nr++]=a[r];
    //printf("%d\n",a[l]);

    ans=0;
   // printf("%d\n",a[r]);
	x=a[l];
	for (int i=0;i<nl;i++)
        ans+=2*(abs(x-le[i]));
    for (int i=0;i<nr;i++)
        ans+=2*(abs(x-ri[i]));

    printf("%I64d\n",ans);



	return 0;
}
