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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt,n,k;
	scanf("%d",&tt);

	while (tt--)
    {
        scanf("%d",&k);
        k=abs(k);
        n=1;
        while ((n*(n+1)/2)<k)   n++;
        while ((((n*(n+1)/2)-k)&1)!=0)  n++;
        printf("%d\n",n);
        if (tt)  puts("");
    }

	return 0;
}
