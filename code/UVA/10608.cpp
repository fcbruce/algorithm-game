/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	 2014-09-14 23:43:52 
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
#define maxn 30007

using namespace std;

int pre[maxn],num[maxn];
int MAX;

int root(int x)
{
	if (x==pre[x])	return x;
	return pre[x]=root(pre[x]);
}

bool same(int x,int y)
{
	return root(x)==root(y);
}

void _merge(int x,int y)
{
	int rx=root(x),ry=root(y);
	
	pre[rx]=ry;
	num[ry]+=num[rx];
	
	MAX=max(MAX,num[ry]);
}

int main()
{
#ifdef FCBRUCE
	freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		int n,m;
		scanf( "%d%d",&n,&m);
		
		MAX=1;
		
		for (int i=1;i<=n;i++)
		{
			pre[i]=i;
			num[i]=1;
		}
		
		for (int i=0,x,y;i<m;i++)
		{
			scanf( "%d%d",&x,&y);
			if (same(x,y))	continue;
			_merge(x,y);
		}
		
		printf( "%d\n",MAX);
	}
	
	return 0;
}



