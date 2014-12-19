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

	LL n;

	while (scanf("%lld",&n),n>=0)
    {
        if (n<=1)   puts("0%");
        else    printf("%lld%%\n",n*25);
    }

	return 0;
}
