/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-13 16:17:59 
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
#define maxn 1<<23

using namespace std;

struct __patch
{
	int time;
	unsigned int and_in,in,and_out,or_out;
}p[101];

struct Heap_node
{
	int d;
	unsigned int s;
	bool operator < (const Heap_node &n)const
	{
		return d>n.d;
	}
};

int n,m;
int d[maxn];


void bfs()
{
	memset(d,0x3f,sizeof d);
	unsigned int s=0;
	for (int i=0;i<n;i++)	s |= 1<<i;
	priority_queue<Heap_node> q;
	q.push( (Heap_node){0,s});
	
	while (!q.empty())
	{
		Heap_node x=q.top();q.pop();
		
		if (x.s==0)	return;
		if (x.d>d[x.s]) continue;
		
		for (int i=0;i<m;i++)
		{
			unsigned int in,out;
			int _d;
			in=x.s & p[i].and_in;
			out=x.s & p[i].and_out | p[i].or_out;
			_d=x.d+p[i].time;
			
			if (in==p[i].in && _d<d[out])
			{
				d[out]=_d;
				q.push( (Heap_node){_d,out});
			}
		}
	}
	
	
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	
	char s_in[30],s_out[30];
	int T_T=0;
	
	while (scanf( "%d%d",&n,&m),n||m)
	{
		for (int i=0;i<m;i++)
		{
			scanf( "%d %s %s",&p[i].time,s_in,s_out);
			unsigned int in,out,and_in,and_out,or_out;
			in=out=or_out=0;
			and_in=and_out=0;
			for (int j=0;j<n;j++)
			{
				if (s_in[j]=='0')
				{
					and_in |= 1<<j;
				}
				if (s_in[j]=='+')
				{
					in |= 1<<j;
				}
				if (s_out[j]=='-')
				{
					and_out |= 1<<j;
				}
				if (s_out[j]=='+')
				{
					or_out |= 1<<j;
				}
			}
			
			p[i].and_in=~and_in;
			p[i].in=in;
			p[i].and_out=~and_out;
			p[i].or_out=or_out;
		}
		
		bfs();
		
		printf ( "Product %d\n",++T_T);
		
		if (d[0]==INF)
			puts( "Bugs cannot be fixed.");
		else
			printf( "Fastest sequence takes %d seconds.\n",d[0]);
			
		putchar( '\n');
	}
	
	
	return 0;
}



