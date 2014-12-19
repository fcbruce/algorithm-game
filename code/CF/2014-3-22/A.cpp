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
#define mm

using namespace std;

int a[1000];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int n;
	scanf("%d",&n);

	for (int i=0;i<n;i++)
         {

                  scanf("%d",&a[i]);
         }


	sort(a,a+n);

	for (int i=0;i<n;i++)
         {
                  printf("%d ",a[i]);
         }

	return 0;
}
