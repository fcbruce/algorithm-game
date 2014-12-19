#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

long long a[123456];
int r,l,R;

void init()
{
    LL k=2;
    a[1]=1;
    a[2]=2;
    for (int i=3;i<123456;i+=2)
    {
        a[i]=(1+k)*k-k;
        a[i+1]=(1+k)*k;
        if (a[i+1]>INT_MAX)
        {
            R=i+1;
            break;
        }
        k++;
    }

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	init();
	LL x,y,w;
	int p;
	int tt;
	scanf("%d",&tt);

	while (tt--)
    {
        scanf("%lld%lld",&x,&y);
        w=abs(y-x);
        p=lower_bound(a,a+R,w)-a;
        printf("%d\n",p);
    }

	return 0;
}
