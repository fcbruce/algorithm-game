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

	int n,cnt=0,ans;
	int a[1111];

	while (scanf("%d",&n),n)
    {
        ++cnt;
        int sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
        }
        int average=sum/n;
        ans=0;
        for (int i=0;i<n;i++)
        {
            ans+=max(0,a[i]-average);
        }
        //if (cnt>1)puts("");
        printf("Set #%d\n",cnt);
        printf("The minimum number of moves is %d.\n\n",ans);
    }

	return 0;
}
