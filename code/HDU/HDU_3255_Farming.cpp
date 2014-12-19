/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-27 14:14:21 
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
#define maxn 30303

using namespace std;

struct __seed
{
	int x1,y1,x2,y2,price;
}seed[maxn];

struct __edge
{
	int x1,x2,y,type;
	bool operator < (const __edge &e)const
	{
		return y<e.y;
	}
}edge[maxn<<1];

int price[4];

int X[maxn<<1];

int add[maxn<<3],sum[maxn<<3];

inline void pushup(int k,int l,int r)
{
	if (add[k]>0)
		sum[k]=X[r]-X[l];
	else if (r-l==1)
		sum[k]=0;
	else
		sum[k]=sum[k*2+1]+sum[k*2+2];
}

void update(int a,int b,int v,itn k,int l,int r)
{
	if (b<=l || r<=a)	return ;
	if (a<=l && r<=b)
	{
		add[k]+=v;
	}
	else
	{
		update(a,b,v,k*2+1,l,l+r>>1);
		update(a,b,v,k*2+2,l+r>>1,r);
	}
	
	pushup(k,l,r);
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m,T_T;
	scanf( "%d",&T_T);
	
	for (int __=1;__<=T_T;__++)
	{
		scanf( "%d%d",&n,&m);
		price[0]=0;
		for (int i=1;i<=m;i++)
			scanf( "%d",price+i);
			
		for (int i=0,x1,y1,x2,y2,type;i<n;i++)
		{
			scanf( "%d%d%d%d%d",&x1,&y1,&x2,&y2,&type);
			seed[i]=(__seed){x1,y1,x2,y2,price[type]};
		}
		
		sort(price+1,price+m+1);

		LL income=0;
		
		for (int i=1;i<=m;i++)
		{
			int cnt=0;
			
			for (int j=0;j<n;j++)
			{
				if (seed[j].price>=price[i])
				{
					edge[cnt]=(__edge){seed[j].x1,seed[j].x2,seed[j].y1,1};
					X[cnt++]=seed[j].x1;
					edge[cnt]=(__edge){seed[j].x1,seed[j].x2,seed[j].y2,-1};
					X[cnt++]=seed[j].x2;
				}
			}
			
			sort(edge,edge+cnt);
			sort(X,X+cnt);
			int xn=unique(X,X+cnt)-X;
			
			memset(sum,0,sizeof sum);
			memset(add,0,sizeof add);
			LL area=0;
			
			for (int j=0;j<cnt;j++)
			{
				if (j) area+=(LL)(edge[j].y-edge[j-1].y)*sum[0];
				int a=lower_bound(X,X+xn,edge[j].x1)-X;
				int b=lower_bound(X,X+xn,edge[j].x2)-X;
				update(a,b,edge[j].type,0,0,xn+1);
			}
			
			income+=(LL)(price[i]-price[i-1])*area;
		}
		
		printf( "Case %d: ",__);
		printf( lld "\n",income);
		
	}
	
	return 0;
}



