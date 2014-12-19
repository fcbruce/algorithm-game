/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-04 20:07:41 
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
#define maxn 131

using namespace std;

double G[maxn][maxn];

struct __city
{
	double x,y;
	double dis(const __city &c)const
	{
		return sqrt(sqr(x-c.x)+sqr(y-c.y));
	}
}city[maxn];

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	int n,T_T,__=0;
	
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d",&n);
		
		for (int i=0;i<n;i++)
		{
			scanf( "%lf%lf",&city[i].x,&city[i].y);
			for (int j=0;j<=i;j++)
			{
				double __dis=city[i].dis(city[j]);
				if (__dis>10+eps) __dis=INF;
				G[i][j]=G[j][i]=__dis;
			}
		}
		
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
					
		double MAX=-1e10;
		
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				MAX=max(MAX,G[i][j]);
	
				
		printf( "Case #%d:\n",++__);
		if (MAX<INF-eps)
			printf( "%.4f\n",MAX);
		else
			puts( "Send Kurdy");
			
		putchar( '\n');
	}
	
	
	return 0;
}



