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
#define sqr(x) (x)*(x)
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
	long long n,a,b,t,y,l,r,mid;

	scanf("%I64d%I64d%I64d",&n,&a,&b);
	long long x,ans;

	for (int i=0;i<n;i++)
    {
        scanf("%I64d",&x);
        t=a*x/b;
        if ((t*b)%a==0)
        {
            y=t*b/a;
        }
        else
        {
            y=t*b/a + 1;
        }
        printf("%I64d ",x-y);
    }
    puts("");


	return 0;
}
