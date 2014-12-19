/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-28 10:11:31 
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
#define maxn 200007

using namespace std;

int sum[maxn<<2];

inline void pushup(int k)
{
	sum[k]=sum[k*2+1]+sum[k*2+2];
}

void build(int k,int l,int r)
{
	if (r-l==1)
	{
		scanf( "%d\n",&sum[k]);
		return ;
	}
	
	build(k*2+1,l,l+r>>1);
	build(k*2+2,l+r>>1,r);
	
	pushup(k);
}

void update(int p,int v,int k,int l,int r)
{
	if (r-l==1)
	{
		sum[k]=v;
		return ;
	}
	
	itn m=l+r>>1;
	if (p<m)
		update(p,v,k*2+1,l,m);
	else
		update(p,v,k*2+2,m,r);
		
	pushup(k);
}

int query(int a,int b,int k,int l,int r)
{
	if (b<=l || r<=a)	return 0;
	if (a<=l && r<=b)	return sum[k];
	
	return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,T_T=0;
	
	while (scanf( "%d",&n),n)
	{
		if (T_T)	putchar( '\n');
		printf( "Case %d:\n",++T_T);
		build(0,0,n);
		
		char op[5];
		int a,b;
		while (scanf( "%s",op),strcmp(op,"END"))
		{
			scanf( "%d%d",&a,&b);
			a--;
			if (op[0]=='S')
				update(a,b,0,0,n);
			else
				printf( "%d\n",query(a,b,0,0,n));
		}
	}
	
	return 0;
}



