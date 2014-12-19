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
#define mm 223456

using namespace std;

int a[mm];
int n,t,c;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int ans=0;

	scanf("%d%d%d",&n,&t,&c);

	for (int i=0;i<n;i++)
        scanf("%d",a+i);

    for (int i=0;i<n;i++)
    {
        int k=i;
        while (k<n && a[k]<=t) k++;
        //printf("%d %d\n",i,k);
        if (k-i<c)
        {
            i=k;
        }
        else
        {
            ans++;
            ans+=(k-i-c);
            //printf("%d\n",ans);
            i=k;
        }
    }

    printf("%d\n",ans);


	return 0;
}
