/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	
 *
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define maxm 
#define maxn 

using namespace std;

int a[7654321];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	
	scanf( "%d",&n);
	
	for (int i=0;i<n;i++)
		scanf( "%d",a+i);
		
	sort(a,a+n);
	
	printf( "%d ",a[n-1]-a[0]);
	
	if (a[0]==a[n-1])
	{
		printf( "%I64d\n",(long long)n*(n-1)/2);
		return 0;
	}
	
	int x=upper_bound(a,a+n,a[0])-a;
	int y=upper_bound(a,a+n,a[n-1])-lower_bound(a,a+n,a[n-1]);
	
	printf("%I64d",(long long)x*y);
	
	return 0;
}



