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
#define mm

using namespace std;

int a[111];
int n,k;

bool cmp(const int &x,const int &y)
{
    return x>y;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif


	scanf("%d%d",&n,&k);

	for (int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }

    sort(a,a+n,cmp);

    printf("%d\n",a[k-1]);

	return 0;
}
