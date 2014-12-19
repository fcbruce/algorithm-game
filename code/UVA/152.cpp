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
#define mm 5555

using namespace std;

double x[mm],y[mm],z[mm];
int n=0;
int now,MIN;
int ans[10];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	while (scanf("%lf%lf%lf",x+n,y+n,z+n),x[n]||y[n]||z[n]) n++;

	for (int i=0;i<n;i++)
    {
        MIN=INF;
        for (int j=0;j<n;j++)
        {
            if (i==j)continue;

            now=sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j])+sqr(z[i]-z[j]));
            MIN=min(MIN,now);
        }

        ans[MIN]++;
    }

    for(int i=0;i<10;i++)
        printf("%4d",ans[i]);

    printf("\n");


	return 0;
}
