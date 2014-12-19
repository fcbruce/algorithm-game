#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("t","r",stdin);
	#endif

	LL a,b;
	int t=0;
	while (scanf("%lld%lld",&a,&b),a||b)
    {
        t++;
        printf("Case %d: %lld\n",t,a*b*(a-1)*(b-1)/4);
    }

	return 0;
}
