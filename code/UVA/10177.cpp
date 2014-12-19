#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

LL a[6][111];

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("t","r",stdin);
	#endif

	memset(a,0,sizeof(a));

	for (LL i=1;i<101;i++)
    {
        a[0][i]=a[0][i-1]+sqr(i);
        a[1][i]=sqr(i*(i+1)/2)-a[0][i];
        a[2][i]=a[2][i-1]+sqr(i)*i;
        a[3][i]=sqr(i*(i+1)/2)*(i*(i+1)/2)-a[2][i];
        a[4][i]=a[4][i-1]+sqr(sqr(i));
        a[5][i]=sqr(sqr(i*(i+1)/2))-a[4][i];

    }

    int x;

    while (scanf("%d",&x)==1)
    {
        printf("%lld %lld %lld %lld %lld %lld\n",a[0][x],a[1][x],a[2][x],a[3][x],a[4][x],a[5][x]);
    }


	return 0;
}
