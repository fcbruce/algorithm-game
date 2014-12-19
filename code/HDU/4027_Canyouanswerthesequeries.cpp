/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-27 16:46:52 
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
#define maxn 100007

using namespace std;

LL sum[maxn<<2];

inline void pushup(itn k)
{
	sum[k]=sum[k*2+1]+sum[k*2+2];
}

void build(int k,int l,int r)
{
	if (r-l==1)
	{
		scanf( lld ,&sum[k]);
		return ;
	}
	
	build(k*2+1,l,l+r>>1);
	build(k*2+2,l+r>>1,r);
	
	pushup(k);
}

void update(int a,int b,int k,int l,int r)
{
	if (b<=l || r<=a)	return ;
	if (sum[k]==r-l)	return ;
	
	if (r-l==1)
	{
		sum[k]=(LL)sqrt(sum[k]);
		return ;
	}
	
	update(a,b,k*2+1,l,l+r>>1);
	update(a,b,k*2+2,l+r>>1,r);
	
	pushup(k);
	
}

LL query(itn a,int b,itn k,int l,int r)
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
	
	int n,m,__=0;
	while (~scanf( "%d",&n))
	{
		printf( "Case #%d:\n",++__);
		build(0,0,n);
		itn q,a,b;
		scanf( "%d",&m);
		while (m--)
		{
			scanf( "%d%d%d",&q,&a,&b);
			if (a>b)	swap(a,b);
			a--;
			if (q)
				printf( lld "\n",query(a,b,0,0,n));
			else
				update(a,b,0,0,n);
		}
		putchar( '\n');
	}
	
	return 0;
}



