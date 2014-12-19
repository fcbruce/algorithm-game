/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-09-03 16:31:53 
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
#define maxn 101

using namespace std;

int n,obj;

int v[5];
vector <int> stop[5];
int G[5][maxn],d[5][maxn];
pair<int,int> q[maxn<<8];
bool inq[5][maxn];


void SPFA()
{
	memset(d,0x3f,sizeof d);
	memset(inq,0,sizeof inq);
	int f=0,r=-1;
	for (int i=0;i<n;i++)
		if (G[i][0])
		{
			q[++r]=make_pair(i,0);
			d[i][0]=0;
		}
		
	while (f<=r)
	{
		pair<int,int> x=q[f++];
		inq[x.first][x.second]=false;
		for (int u:stop[x.first])
		{
			if (d[x.first][u]>d[x.first][x.second]+abs(x.second-u)*v[x.first])
			{
				d[x.first][u]=d[x.first][x.second]+abs(x.second-u)*v[x.first];
				if (!inq[x.first][u])
				{
					inq[x.first][u]=true;
					q[++r]=make_pair(x.first,u);
				}
			}
		}
		for (int i=0;i<n;i++)
		{
			if (x.first==i || G[i][x.second]==false)	continue;
			if (d[i][x.second]>d[x.first][x.second]+60)
			{
				d[i][x.second]=d[x.first][x.second]+60;
				if (!inq[i][x.second])
				{
					inq[i][x.second]=true;
					q[++r]=make_pair(i,x.second);
				}
			}
		}
	}
}

int main()
{
	#ifdef FCBRUCE
		freopen("/home/fcbruce/code/t","r",stdin);
	#endif // FCBRUCE
	
	char str[233];
	
	while (~scanf( "%d%d",&n,&obj))
	{
		memset(G,0,sizeof G);
	
		for (int i=0;i<n;i++)
			scanf( "%d",v+i);
			
		getchar();
		
		for (int i=0;i<n;i++)
		{
			gets(str);
			stringstream s(str);
			int x;
			stop[i].clear();
			while (s>>x)
			{
				stop[i].push_back(x);
				G[i][x]=true;
			}
		}
		
		SPFA();
		
		int MIN=INF;
		
		for (int i=0;i<n;i++)
			if (G[i][obj])	MIN=min(MIN,d[i][obj]);
			
		if (MIN==INF)
			puts( "IMPOSSIBLE");
		else
			printf( "%d\n",MIN);
	}
	
	return 0;
}



