/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-24 09:53:20 
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
#define maxn 50007

using namespace std;

long long sum[maxn<<2],mul[maxn<<2],maxv[maxn<<2];

inline void pushdown(int k)
{
	if (mul[k])
	{
		int lc=k*2+1,rc=k*2+2;
		mul[lc]+=mul[k];mul[rc]+=mul[k];
		sum[lc]<<=mul[k];sum[rc]<<=mul[k];
		maxv[lc]<<=mul[k];maxv[rc]<<=mul[k];
		mul[k]=0;
	}
}

inline void pushup(int k)
{
	int lc=k*2+1,rc=k*2+2;
	sum[k]=sum[lc]+sum[rc];
	maxv[k]=max(maxv[lc],maxv[rc]);
}

void build(int k,int l,int r)
{
	mul[k]=0;
	if (r-l==1)
	{
		sum[k]=1;
		maxv[k]=1;
		return ;
	}
	
	build(k*2+1,l,l+r>>1);
	build(k*2+2,l+r>>1,r);
	
	pushup(k);
}

void update_plus(int p,LL v,int k,int l,int r)
{
	if (r-l==1)
	{
		sum[k]+=v;
		maxv[k]+=v;
		return ;
	}
	
	pushdown(k);
	int m=l+r>>1;
	if (p<m)
		update_plus(p,v,k*2+1,l,m);
	else
		update_plus(p,v,k*2+2,m,r);
	pushup(k);
}

void update_mul(int a,int b,int k,int l,int r)
{
	if (b<=l || r<=a)	return ;
	if (a<=l && r<=b)
	{
		sum[k]<<=1;
		mul[k]++;
		maxv[k]<<=1;
		return ;
	}
	
	pushdown(k);
	update_mul(a,b,k*2+1,l,l+r>>1);
	update_mul(a,b,k*2+2,l+r>>1,r);
	pushup(k);
}

int query_pos(LL s,int k,int l,int r)
{
	if (r-l==1)	return l;
	
	int lc=k*2+1,rc=k*2+2;
	
	pushdown(k);
	if (s<=sum[lc])
		return query_pos(s,lc,l,l+r>>1);
	else
		return query_pos(s-sum[lc],rc,l+r>>1,r);
}

LL query_sum(int a,int b,int k,int l,int r)
{
	if (b<=l || r<=a)	return 0;
	if (a<=l && r<=b)
	{
		return sum[k];
	}
	
	pushdown(k);
	return query_sum(a,b,k*2+1,l,l+r>>1)+query_sum(a,b,k*2+2,l+r>>1,r);
}

LL query_max(int a,int b,int k,int l,int r)
{
	if (b<=l || r<=a)	return 0;
	if (a<=l && r<=b)
	{
		return maxv[k];
	}
	
	pushdown(k);
	return max(query_max(a,b,k*2+1,l,l+r>>1),query_max(a,b,k*2+2,l+r>>1,r));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T,__=0;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		printf( "Case #%d:\n",++__);
		
		int n,m;
		scanf( "%d%d",&n,&m);
		
		build(0,0,n);
		
		long long l,r;
		char op;
		for (int i=0;i<m;i++)
		{
			scanf( " %c" lld lld ,&op,&l,&r);
			int a=query_pos(l,0,0,n);
			int b=query_pos(r,0,0,n);
			if (op=='D')
			{
				if (a==b)
				{
					update_plus(a,r-l+1,0,0,n);
				}
				else
				{
					LL v1=query_sum(0,a+1,0,0,n)-l+1;
					LL v2=r-query_sum(0,b,0,0,n);
					update_plus(a,v1,0,0,n);
					update_plus(b,v2,0,0,n);
					if (a+1<b)	update_mul(a+1,b,0,0,n);
				}
			}
			else
			{
				LL MAX=0;
				if (a==b)
				{
					MAX=r-l+1;
				}
				else
				{
					MAX=query_sum(0,a+1,0,0,n)-l+1;
					MAX=max(MAX,r-query_sum(0,b,0,0,n));
					if (a+1<b)	MAX=max(MAX,query_max(a+1,b,0,0,n));
				}
				printf ( lld "\n",MAX);
			}
		}
	}
	
	return 0;
}



