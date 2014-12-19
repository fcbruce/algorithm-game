/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	
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

#ifdef WIN32
	#define lld "%I64d"
#else
	#define lld "%lld"
#endif

#define maxm 
#define maxn 

using namespace std;

int g[22][22];
itn n;
int vis[22];

vector <int> l;

map<int,int>MAP;

struct Egalitarianism3Easy
{
	int maxCities(int nn, vector <int> a, vector <int> b, vector <int> len)
	{
		n=nn;
		memset(g,0x3f,sizeof g);
		for (int i=1;i<=n;i++)
			g[i][i]=0;
		for (int i=0;i<n-1;i++)
		{
			g[a[i]][b[i]]=g[b[i]][a[i]]=len[i];
		}
		
		for  (int k=1;k<=n;k++)
			for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		
		l.clear();
		for (int i=1;i<=n;i++)
				for (int j=1;j<=n;j++)
				{
					if (g[i][j]!=INF)
					{
						l.push_back(g[i][j]);
					}
				}
				
		sort(l.begin(),l.end());
		int sz=unique(l.begin(),l.end())-l.begin();
		
		itn ans=0;
		for (int k=0;k<sz;k++)
		{
			printf( "%d\n",l[k]);
			MAP.clear();
			for (int i=1;i<=n;i++)
			{
				for (int j=1;j<=n;j++)
				{
					if (g[i][j]==l[k])
					{
						bool ff=true;
						for (map<int,int>::iterator it=MAP.begin();it!=MAP.end();it++)
						{
							if ( (i!=it->first) && (j!=it->first) && g[i][it->first]!=l[k] ||g[j][it->first]!=l[k])
							{
								ff=false;
								break;
							}
						}
						if (ff)
						{
							MAP[i]++;
							MAP[j]++;
						}
					}
				}
			}
			ans=max(ans,(int)MAP.size());
		}
		
		return ans;
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	
	
	return 0;
}



