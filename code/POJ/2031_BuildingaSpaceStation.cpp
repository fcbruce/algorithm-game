/*
 *
 *	Author	: 	fcbruce
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
#define maxm 10010
#define maxn 101

using namespace std;

struct __ball
{
	double x,y,z,r;
	double dis(const __ball &b)const
	{
		return sqrt(sqr(x-b.x)+sqr(y-b.y)+sqr(z-b.z))-r-b.r;
	}
}ball[maxn];

struct __edge
{
	int u,v;
	double w;
	bool operator < (const __edge &e)const
	{
		return w<e.w;
	}
}edge[maxm];
int e_max;
int pre[maxn];

int root(int x)
{
	if (pre[x]==x)	return x;
	return pre[x]=root(pre[x]);
}

bool __same(int x,int y)
{
	return root(x)==root(y);
}

void __merge(int x,int y)
{
	pre[root(x)]=root(y);
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n;
	while (~scanf( "%d",&n),n)
	{
		for (int i=0;i<n;i++)	pre[i]=i;
		e_max=0;
		int total=n;
		double x,y,z,r;
		
		for (int i=0;i<n;i++)
		{
			scanf( "%lf %lf %lf %lf",&x,&y,&z,&r);
			ball[i]=(__ball){x,y,z,r};
			for (int j=0;j<i;j++)
			{
				double d=ball[i].dis(ball[j]);
				if (d<eps)
				{
					if (!__same(i,j))
					{
						__merge(i,j);
						total--;
					}
				}
				else
				{
					edge[e_max++]=(__edge){i,j,d};
				}
			}
		}
		
		sort(edge,edge+e_max);
		double res=0;
		
		for (int e=0;e<e_max && total>1;e++)
		{
			if (!__same(edge[e].u,edge[e].v))
			{
				res+=edge[e].w;
				__merge(edge[e].u,edge[e].v);
				total--;
			}
		}
		
		printf( "%.3f\n",res);
	}
	
	return 0;
}

