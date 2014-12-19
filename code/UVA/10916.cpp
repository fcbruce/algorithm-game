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

int a[200];

void init()
{
    double k=0;
    int p=1;
    for (int i=1960;i<=2160;i++)
    {
        int t=4*pow(2,(i-1960)/10);
        while (k<=t)
        {
            p++;
            k+=(log(p)/log(2));
        }
        a[i-1960]=p-1;

    }
}

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("t","r",stdin);
	#endif

    init();
    int n;

    while (scanf("%d",&n),n)
    {
        printf("%d\n",a[n-1960]);
    }



	return 0;
}
