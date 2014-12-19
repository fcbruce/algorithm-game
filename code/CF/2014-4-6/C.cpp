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
#define mm 1000000001

using namespace std;

int cnt,a,b,n,k,p,t;
int ans[100001];

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("t","r",stdin);
	#endif


	scanf("%d%d",&n,&k);

	if (n==1 && k==0)
    {
        puts("1\n");
        return 0;
    }

    if (n==1)
    {
        puts("-1");
        return 0;
    }

	if (n/2 > k)
    {
        puts("-1");
        return 0;
    }

    cnt=0;
    a=k/(n/2);
    t=k%(n/2);
    p=1;
    for (int i=0;i<n/2-t;i++)
    {
        if ((p+1)*(a)<mm)
        {

            ans[cnt++]=p*(a);
            ans[cnt++]=(p+1)*(a);

            p+=2;
        }
        else
        {
            puts("-1");
            return 0;
        }
    }
    for (int i=0;i<t;i++)
    {
        if ((p+1)*(a+1)<mm)
        {
            ans[cnt++]=p*(a+1);
            ans[cnt++]=(p+1)*(a+1);

            p+=2;
        }
        else
        {
            puts("-1");
            return 0;
        }
    }

    for (int i=0;i<cnt;i++)
    {
        printf("%d ",ans[i]);
    }

    if (n%2==1)
    {
        printf("%d\n",p*(a+1));
    }

    printf("\n");


	return 0;
}
