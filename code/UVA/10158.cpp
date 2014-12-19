/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-15 23:10:51  
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
#define maxn 10007

using namespace std;

int pre[maxn<<1];

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
	pre[root(x)]=root(y);
}


int main()
{
#ifdef FCBRUCE
	freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
	
	int n;
	scanf( "%d",&n);
	
	for (int i=0;i<n<<1;i++)
	{
		pre[i]=i;
	}
	
	int op,x,y;
	
	while (scanf( "%d%d%d",&op,&x,&y),op||x||y)
	{
		switch (op)
		{
			case 1:
				if (!same(x,y+n))
				{
					_merge(x,y);
					_merge(x+n,y+n);
				}
				else
				{
					puts( "-1");
				}
				break;
			case 2:
				if (!same(x,y))
				{
					_merge(x,y+n);
					_merge(x+n,y);
				}
				else
				{
					puts( "-1");
				}
				break;
			case 3:
				puts(same(x,y)?"1":"0");
				break;
			case 4:
				puts(same(x,y+n)?"1":"0");
				break;
		}
	}
	
	return 0;
}



