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
		freopen("t","r",stdin);
	#endif

	int tt;
	scanf("%d",&tt);
	int n,m;
	int x,y;

	while (tt--)
    {
        scanf("%d%d",&n,&m);
        n-=2;m-=2;
        x=ceil(n/3.0);
        y=ceil(m/3.0);
        printf("%d\n",x*y);
    }

	return 0;
}
