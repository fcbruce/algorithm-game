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
#define mm 1000000

using namespace std;

int n,s;
struct city
{
    int x,y,k;
    double r;
}a[1111];

bool cmp(const city &x,const city &y)
{
    return x.r<y.r;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif
	double r=0;

	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].k);
        a[i].r=sqrt(sqr(a[i].x)+sqr(a[i].y));
    }

    sort(a,a+n,cmp);

    int x=0;

    while (s<mm && x<n)
    {
        r=a[x].r;
        s+=a[x].k;
        x++;
    }

    if (s<mm)   puts("-1");
    else

        printf("%.7f\n",r);

	return 0;
}
