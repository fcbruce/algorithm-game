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
#define mm 3003

using namespace std;

double c[mm];
int n;
double a0,anp1,a1;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt;

	scanf("%d",&tt);

	for (int t=0;t<tt;t++)
    {
        if (t)  puts("");

        scanf("%d",&n);

        scanf("%lf%lf",&a0,&anp1);

        for (int i=0;i<n;i++)
            scanf("%lf",c+i);

        a1=n*a0+anp1;
        for (int i=0;i<n;i++)
            a1-=2*(n-i)*c[i];

        a1/=(n+1);

        printf("%.2f\n",a1);
    }



	return 0;
}
