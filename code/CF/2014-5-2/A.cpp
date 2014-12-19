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
#define mm 123456

using namespace std;

int a[mm];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n;

	int t=0,ans=0;

	scanf("%d",&n);

	for (int i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        if (k==-1)
        {
            if (t)
                t--;
            else
                ans++;
        }
        else
        {
            t+=k;
        }
    }
    printf("%d\n",ans);



	return 0;
}
