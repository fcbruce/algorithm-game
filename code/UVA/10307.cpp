/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-11 15:26:39 
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
#define maxn 

using namespace std;

struct node
{
	int x,y,w;
	bool operator < (const node &n)const
	{
		return w>n.w;
	}
};

int n,m,total;
char G[101][101];
char buf[101];
int vis[101][101];
int sx,sy;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int bfs()
{
	int res=0;
	priority_queue<node >	q;
	q.push( (node){sx,sy,0});
	memset(vis,0x3f,sizeof vis);
	vis[sx][sy]=0;
	
	while (!q.empty() || total)
	{
		node s=q.top();q.pop();
		
		if (G[s.x][s.y]=='A')
		{
			res+=s.w;
			s.w=0;
			G[s.x][s.y]=' ';
			total--;
		}
		
		for (int i=0;i<4;i++)
		{
			int tx=s.x+dx[i];
			int ty=s.y+dy[i];
			int tw=s.w+1;
			if (G[tx][ty]!='#' && vis[tx][ty]>tw)
			{
				q.push( (node){tx,ty,tw});
				vis[tx][ty]=tw;
			}
		}
	}
	
	return res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int T_T;
	scanf( "%d",&T_T);
	
	while (T_T--)
	{
		scanf( "%d %d",&m,&n);getchar();
		for (int i=0;i<n;i++)
			gets(G[i]);
			
		total=0;
		
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				if (G[i][j]=='S')
				{
					sx=i;sy=j;
				}
				if (G[i][j]=='A')
					total++;
			}
		}
		
		printf( "%d\n",bfs());
	}
	
	return 0;
}



