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

int a[1001][1001];

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,k,d;
	scanf( "%d %d %d",&n,&k,&d);
	
	if (log( (double)n)>(double)d*log( (double)k)+eps)
	{
		printf( "-1");
		return 0;
	}
	
	for (int i=0;i<d;i++)
		a[i][0]=1;
	for (int i=1;i<n;i++)
	{
		a[0][i]=a[0][i-1]+1;
		int add=0;
		if (a[0][i]>k)
		{
			a[0][i]=1;
			add=1;
		}
		for (int j=1;j<d;j++)
		{
			a[j][i]=a[j][i-1]+add;
			add=0;
			if (a[j][i]>k)
			{
				a[j][i]=1;
				add=1;
			}
		}
	}
	
	for (int i=0;i<d;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf( "%d ",a[i][j]);
		}
		puts("");
	}
	
	
	
	return 0;
}



