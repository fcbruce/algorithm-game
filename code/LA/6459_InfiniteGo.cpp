/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-06 19:34:30 
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
#define maxn 

using namespace std;

int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

map<pair<int,int>,int>MAP,vis;

pair<int,int> q[11111];

void bfs(int x,int y,int type)
{
	vis.clear();

	int f=0,r=-1;
	vis[q[++r]=make_pair(x,y)]=1;
	
	
	while (f<=r)
	{
		auto status=q[f++];
		
		for (int i=0;i<4;i++)
		{
			auto to_status=make_pair(status.first+dx[i],status.second+dy[i]);
			if (to_status.first>0 && to_status.second>0 && vis[to_status]==0)
			{
				int colour=MAP[to_status];

				if (colour==0)	return ;
				
				if (colour==type)
					q[++r]=to_status;
				
				vis[to_status]=1;
			}
		}
	}
	
	for (int i=0;i<=r;i++)
		MAP[q[i]]=0;
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
		MAP.clear();
		
		int n;
		scanf( "%d",&n);
		
		for (int i=0,x,y;i<n;i++)
		{
			scanf( "%d%d",&x,&y);
			
			MAP[make_pair(x,y)]=i&1?1:-1;
			
			for (int i=0;i<4;i++)
			{
				int tx=x+dx[i],ty=y+dy[i];
				
				if (MAP[make_pair(tx,ty)])
					bfs(tx,ty,MAP[make_pair(tx,ty)]);
			}
			
			bfs(x,y,i&1?1:-1);
			
		}
		
		int black=0,red=0;
		
		for (auto it : MAP)
		{
			if (it.second==1)	red++;
			if (it.second==-1)	black++;
		}
		
		printf( "%d %d\n",black,red);
	}
	
	return 0;
}



