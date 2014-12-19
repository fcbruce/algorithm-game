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

int a[123456];
int n;

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	
	if (x1!=x2 && y1!=y2 && abs(x1-x2)!=abs(y1-y2))
	{
		printf( "-1");
		return 0;
	}
	else
	{
		printf("%d %d %d %d",x1,y2,x2,y1);
	}
	
	
	
	
	return 0;
}



