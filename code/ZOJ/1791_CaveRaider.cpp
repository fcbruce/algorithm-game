/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-18 16:54:17 
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
#define maxm 2333
#define maxn 55

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],w[maxm],nex[maxm];
int e_max;
int d[maxn];
int q[maxm<<3];
bool inq[maxn];
vector<int> rec[maxm];

stringstream str;

void add_edge(int _u,int _v,int _w)
{
	int e;
	e=e_max++;
	u[e]=_u;v[e]=_v;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
	rec[e].clear();
	int temp;
	while (str>>temp)	rec[e].push_back(temp);
	if (!(rec[e].size()&1)) rec[e].push_back(INF);
	e=e_max++;
	u[e]=_v;v[e]=_u;w[e]=_w;
	nex[e]=fir[u[e]];fir[u[e]]=e;
	rec[e]=rec[e-1];
}

void SPFA(int s,int t)
{
	int f,r;
	memset(inq,0,sizeof inq);
	memset(d,0x3f,sizeof d);
	d[s]=t;
	q[f=r=0]=s;
	while (f<=r)
	{
		int x=q[f++];
		inq[x]=false;
		for (int e=fir[x];~e;e=nex[e])
		{
			int p=upper_bound(rec[e].begin(),rec[e].end(),d[u[e]])-rec[e].begin();
			int arrive;
			if (p&1)
			{
				arrive=rec[e][p];
				p++;
			}
			else
			{
				arrive=d[u[e]];
			}
			for (int i=p;i<rec[e].size() && d[v[e]]>arrive+w[e];i+=2)
			{
				if (rec[e][i]-arrive>=w[e])
				{
					d[v[e]]=arrive+w[e];
					if (!inq[v[e]])
					{
						inq[v[e]]=false;
						q[++r]=v[e];
					}
					break;
				}
				else
				{
					arrive=rec[e][i+1];
				}
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	int n,m,s,t;
	char c_str[2333];
	
	
	while (~scanf( "%d%d%d%d",&n,&m,&s,&t),n)
	{
		e_max=0;
		memset(fir,-1,sizeof fir);
		for (int i=0,u,v,w;i<m;i++)
		{
			scanf( "%d %d %d",&u,&v,&w);
			fgets(c_str,2333,stdin);
			str.clear();
			str<<c_str;
			add_edge(u,v,w);
		}
		
		SPFA(s,0);
		if (d[t]==INF)
			puts( "*");
		else
			printf( "%d\n",d[t]);
	}
	
	return 0;
}



