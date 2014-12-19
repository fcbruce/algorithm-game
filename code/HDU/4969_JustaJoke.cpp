/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-19 20:53:26 
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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		double v1,v2,r,d;
		scanf ( "%lf%lf%lf%lf",&v1,&v2,&r,&d);
		
		if (r*v2*asin(v1/v2)/v1>d+eps)
			puts( "Why give up treatment");
		else
			puts( "Wake up to code");
	}
	
	return 0;
}



