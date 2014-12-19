/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-15 16:07:39 
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
#define maxn 507

using namespace std;

int maxv[maxn<<2][maxn<<2],minv[maxn<<2][maxn<<2];
int N,M;

inline int ReadInt()
{
    int flag=0;
    char ch = getchar();
    int data = 0;
    while (ch < '0' || ch > '9')
    {
        if(ch=='-') flag=1;
        ch = getchar();
    }
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    }while (ch >= '0' && ch <= '9');
        if(flag) data=-data;
        return data;
}

inline void pushup(int k_2d,int k)
{
	minv[k_2d][k]=min(minv[k_2d][k*2+1],minv[k_2d][k*2+2]);
	maxv[k_2d][k]=max(maxv[k_2d][k*2+1],maxv[k_2d][k*2+2]);
}

void build_1d(int k,int l,int r,int k_2d,int type)
{
	if (r-l==1)
	{
		if (type)
			minv[k_2d][k]=maxv[k_2d][k]=ReadInt();
		else
		{
			minv[k_2d][k]=min(minv[k_2d*2+1][k],minv[k_2d*2+2][k]);
			maxv[k_2d][k]=max(maxv[k_2d*2+1][k],maxv[k_2d*2+2][k]);
		}
		
		return ;
	}

	build_1d(k*2+1,l,l+r>>1,k_2d,type);
	build_1d(k*2+2,l+r>>1,r,k_2d,type);		
	
	pushup(k_2d,k);
	
}

void build_2d(int k,int l,int r)
{
	if (r-l==1)
	{
		build_1d(0,0,M,k,1);
		return ;
	}
	
	build_2d(k*2+1,l,l+r>>1);
	build_2d(k*2+2,l+r>>1,r);
	
	build_1d(0,0,M,k,0);
}

void update_1d(int p,int v,int k,int l,int r,int k_2d,int type)
{
	if (r-l==1)
	{
		if (type)
			maxv[k_2d][k]=minv[k_2d][k]=v;
		else
		{
			minv[k_2d][k]=min(minv[k_2d*2+1][k],minv[k_2d*2+2][k]);
			maxv[k_2d][k]=max(maxv[k_2d*2+1][k],maxv[k_2d*2+2][k]);
		}
		
		return ;
	}
	
	int m=l+r>>1;
	
	if (p<m)
		update_1d(p,v,k*2+1,l,m,k_2d,type);
	else
		update_1d(p,v,k*2+2,m,r,k_2d,type);
		
	pushup(k_2d,k);
}

void update_2d(int p,int y,int v,int k,int l,int r)
{
	if (r-l==1)
	{
		update_1d(y,v,0,0,M,k,1);
		return ;
	}
	
	int m=l+r>>1;
	
	if (p<m)
		update_2d(p,y,v,k*2+1,l,m);
	else
		update_2d(p,y,v,k*2+2,m,r);
		
	update_1d(y,v,0,0,M,k,0);
}

pair<int,int> query_1d(itn a,int b,int k,int l,itn r,int k_2d)
{
	if (b<=l || r<=a)	return make_pair(INF,0);
	if (a<=l && r<=b)	return make_pair(minv[k_2d][k],maxv[k_2d][k]);
	
	pair<int,int> v1=query_1d(a,b,k*2+1,l,l+r>>1,k_2d);
	pair<int,int> v2=query_1d(a,b,k*2+2,l+r>>1,r,k_2d);
	
	return make_pair(min(v1.first,v2.first),max(v1.second,v2.second));
}

pair<int,int> query_2d(int a,int b,int ya,int yb,int k,int l,int r)
{
	if (b<=l || r<=a)	return make_pair(INF,0);
	if (a<=l && r<=b)	return query_1d(ya,yb,0,0,M,k);
	
	pair<int,int> v1=query_2d(a,b,ya,yb,k*2+1,l,l+r>>1);
	pair<int,int> v2=query_2d(a,b,ya,yb,k*2+2,l+r>>1,r);
	
	return make_pair(min(v1.first,v2.first),max(v1.second,v2.second));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	scanf( "%d %d",&N,&M);
	
	build_2d(0,0,N);
	
	int q,x1,x2,y1,y2,v;
	char op[5];
	
	scanf( "%d",&q);
	
	while (q--)
	{
		scanf( "%s",op);
		if (op[0]=='q')
		{
			scanf( "%d%d%d%d",&x1,&y1,&x2,&y2);
			x1--;y1--;
			pair<int,int> res=query_2d(x1,x2,y1,y2,0,0,N);
			printf( "%d %d\n",res.second,res.first);
		}
		else
		{
			scanf( "%d%d%d",&x1,&y1,&v);
			x1--;y1--;
			update_2d(x1,y1,v,0,0,N);
		}
	}
	
	return 0;
}



