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

int app[111];
int x;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for (int i=0;i<a;i++)
    {
        scanf("%d",&x);
        app[x]=1;
    }
    for (int i=0;i<b;i++)
    {
        scanf("%d",&x);
        app[x]=2;
    }

    for (int i=1;i<=n;i++)
        printf("%d ",app[i]);



	return 0;
}
