/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-24 13:03:05 
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
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

#ifdef _WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define maxm 
#define maxn 300

using namespace std;

int n;
int minv[maxn<<2][maxn<<2];

inline void pushup(int k_2d,int k)
{
	minv[k_2d][k]=min(minv[k_2d][k*2+1],minv[k_2d][k*2+2]);
}

void build_1d(int k,int l,int r,int k_2d,int type)
{
	if (r-l==1)
	{
		if (type)
			scanf( "%d",&minv[k_2d][k]);
		else
			minv[k_2d][k]=min(minv[k_2d*2+1][k],minv[k_2d*2+2][k]);
			
		return ;
	}
	
	build_1d(k*2+1,l,l+r>>1,k_2d,type);
	build_1d(k*2+2,l+r>>1,r,k_2d,type);
	
	pushup(k_2d,k);
}

void build_2d(int k,int l,int r)
{
	if (r-l==1)
		build_1d(0,0,n,k,1);
	else
	{
		build_2d(k*2+1,l,l+r>>1);
		build_2d(k*2+2,l+r>>1,r);
		
		build_1d(0,0,n,k,0);
	}
}

int query_1d(int a,int b,int k,int l,int r,int k_2d)
{
	if (b<=l || r<=a)	return INF;
	if (a<=l && r<=b)	return minv[k_2d][k];
	
	return min(query_1d(a,b,k*2+1,l,l+r>>1,k_2d),query_1d(a,b,k*2+2,l+r>>1,r,k_2d));
 
}

int query_2d(int a,int b,int ya,int yb,int k,int l,int r)
{
	if (b<=l || r<=a)	return INF;
	if (a<=l && r<=b)	return query_1d(ya,yb,0,0,n,k);
	
	return min(query_2d(a,b,ya,yb,k*2+1,l,l+r>>1),query_2d(a,b,ya,yb,k*2+2,l+r>>1,r));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d",&n);
		build_2d(0,0,n);
		
		int m;
		scanf( "%d",&m);
		int x1,x2,y1,y2;
		while (m--)
		{
			scanf( "%d%d%d%d",&x1,&y1,&x2,&y2);
			x1--;
			y1--;
			printf( "%d\n",query_2d(x1,x2,y1,y2,0,0,n));
		}
	}
	
	
	return 0;
}



