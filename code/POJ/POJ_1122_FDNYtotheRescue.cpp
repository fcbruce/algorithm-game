/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-17 10:09:06 
 *
 */
#include <cstdio>
#include <sstream>
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
#define maxm 404
#define maxn 22

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn],__prev[maxn];

void add_edge(int _u,int _v,int _w)
{
	int e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
}

struct Heap_node
{
	int d,v;
	bool operator < (const Heap_node &n)const
	{
		return d>n.d;
	}
};

void dijkstra(int s)
{
	memset(d,0x3f,sizeof d);
	d[s]=0;
	priority_queue<Heap_node> q;
	q.push( (Heap_node){0,s});
	__prev[s]=-1;
	
	while (!q.empty())
	{
		Heap_node x=q.top();q.pop();
		if (x.d>d[x.v])	continue;
		
		for (int e=fir[x.v];~e;e=nex[e])
		{
			if (d[v[e]]>d[u[e]]+w[e])
			{
				d[v[e]]=d[u[e]]+w[e];
				__prev[v[e]]=u[e];
				q.push( (Heap_node){d[v[e]],v[e]});
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,T_T;
//	scanf( "%d",&T_T);
	
	while (~scanf( "%d",&n))
	{
//		scanf( "%d",&n);
		e_max=0;
		memset(fir,-1,sizeof fir);
		int _w,s;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				scanf( "%d",&_w);
				if (_w>=0)
				{
					add_edge(j,i,_w);
				}
			}
		}
		
		scanf( "%d",&s);
		char str[200];
		memset(str,0,sizeof str);
		fgets(str,200,stdin);
		istringstream ss(str);
		char *p=str;
		p+=1;
		vector<int> obj;
		int __obj;
		while(ss>>__obj)
		{
			//sscanf(p,"%d",&__obj);
			obj.push_back(__obj);
			//p=p+(int)log10(__obj)+2;
			
		}
		
		dijkstra(s);
		
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		for (int i=0;i<obj.size();i++)
		{
			q.push(make_pair(d[obj[i]],obj[i]));
		}
		
		puts( "Org\tDest\tTime\tPath");
		while (!q.empty())
		{
			pair<int,int> x=q.top();q.pop();
			printf( "%d\t%d\t%d",x.second,s,x.first);
			int _v=x.second;
			do
			{
				printf( "\t%d",_v);
				_v=__prev[_v];
			}while (_v!=-1);
			putchar( '\n');
		}
		
//		if (T_T)	putchar( '\n');
	}
	
	return 0;
}



