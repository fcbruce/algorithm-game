/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-15 13:14:59 
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

int maxv[222<<2][1111<<2];

void pushup(int k_2d,int k)
{
	maxv[k_2d][k]=max(maxv[k_2d][k*2+1],maxv[k_2d][k*2+2]);
}

void update_1d(int p,int v,int k,int l,int r,int k_2d,int type)
{
	if (r-l==1)
	{
		if (type)
			maxv[k_2d][k]=max(maxv[k_2d][k],v);
		else
			maxv[k_2d][k]=max(maxv[k_2d*2+1][k],maxv[k_2d*2+2][k]);
	}
	else
	{
		int m=l+r>>1;
		if (p<m)
			update_1d(p,v,k*2+1,l,m,k_2d,type);
		else
			update_1d(p,v,k*2+2,m,r,k_2d,type);
		
		pushup(k_2d,k);
	}
}

void update_2d(int p,int y,int v,int k,int l,int r)
{
	if (r-l==1)
	{
		update_1d(y,v,0,0,1111,k,1);
		return ;
	}
	
	int m=l+r>>1;
	if (p<m)
		update_2d(p,y,v,k*2+1,l,m);
	else
		update_2d(p,y,v,k*2+2,m,r);
		
	update_1d(y,v,0,0,1111,k,0);
}

int query_1d(int a,int b,int k,int l,int r,int k_2d)
{
	if (b<=l || r<=a)	return -1;
	if (a<=l && r<=b)	return maxv[k_2d][k];
	
	return max(query_1d(a,b,k*2+1,l,l+r>>1,k_2d),query_1d(a,b,k*2+2,l+r>>1,r,k_2d));
	
}

int query_2d(int a,int b,int ya,int yb,int k,int l,int r)
{
	if (b<=l || r<=a)	return -1;
	if (a<=l && r<=b)
	{
		return query_1d(ya,yb,0,0,1111,k);
	}
	
	return max(query_2d(a,b,ya,yb,k*2+1,l,l+r>>1),query_2d(a,b,ya,yb,k*2+2,l+r>>1,r));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int m,h,h1,h2;
	double a,l,a1,a2;
	while (scanf( "%d",&m),m)
	{
		memset(maxv,-1,sizeof maxv);
		while (m--)
		{
			char op[5];
			scanf( "%s",op);
			
			if (op[0]=='I')
			{
				scanf( "%d%lf%lf",&h,&a,&l);
				update_2d(h,(int)(a*10),(int)(l*10),0,0,222);
			}
			else
			{
				scanf( "%d%d%lf%lf",&h1,&h2,&a1,&a2);
				if (h1>h2)	swap(h1,h2);
				if (a1>a2)	swap(a1,a2);
				int res=query_2d(h1,h2+1,(int)(a1*10),(int)(a2*10)+1,0,0,222);
				if (res==-1)
					printf( "-1\n");
				else
					printf( "%d.%d\n",res/10,res%10);
			}
		}
	}
	
	return 0;
}



