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
#define mm 10001

using namespace std;

int a[mm];

void init()
{
    a[0]=1;
    for (int i=1;i<mm;i++)
    {
        a[i]=a[i-1]*i;
        while (a[i]%10==0)
            a[i]/=10;
        a[i]%=100000;
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	init();

	int n;

	while (~scanf("%d",&n))
        printf("%5d -> %d\n",n,a[n]%10);


	return 0;
}
