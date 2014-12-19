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

int gcd(int x,int y)
{
    if (y==0)
        return x;

    return gcd(y,x%y);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n,k;

	while (~scanf("%d%d",&n,&k))
    {
        printf("%10d%10d    ",n,k);
        /*printf("%10d%10d%5s",n,k," ");
        if (gcd(n,k)==1)
            puts("Good Choice\n");
        else
            puts("Bad Choice\n");
            */
        if (gcd(n,k)==1)
            printf("Good Choice\n");
        else
            printf("Bad Choice\n");
        printf("\n");
    }


	return 0;
}
