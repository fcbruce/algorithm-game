/*
 *
 *	Author	: 	fcbruce
 *
 *	Date	:	2014-08-10 15:22:35 
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

bool appear[30],pending[30],G[30][30];
int deg[30],st[30];
int n;

void write()
{
	for (int i=0;i<n;i++)
		putchar(st[i]+'a');
	putchar ( '\n');
}

void toposort(int x,int top)
{
	st[++top]=x;
	if (top+1==n)
	{
		write();
		return ;
	}
	
	for (int i=0;i<30;i++)
	{
		if (G[x][i])
		{
			deg[i]--;
			if (deg[i]==0)
			{
				pending[i]=true;
			}
		}
	}
	
	for (int i=0;i<30;i++)
	{
		if (pending[i])
		{
			pending[i]=false;
			toposort(i,top);
			pending[i]=true;
		}
	}
	
	for (int i=0;i<30;i++)
	{
		if (G[x][i])
		{
			deg[i]++;
			if (deg[i]!=0)
			{
				pending[i]=false;
			}
		}
	}
}

void slove()
{
	memset(pending,0,sizeof pending);
	for (int i=0;i<30;i++)
	{
		if (appear[i] && deg[i]==0)
			pending[i]=true;
	}
	
	for (int i=0;i<30;i++)
	{
		if (pending[i])
		{
			pending[i]=false;
			toposort(i,-1);
			pending[i]=true;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	//	freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	
	char last,ch;
	int cnt=0;
	bool first=true,cmp=false;
	memset(appear,0,sizeof appear);
	memset(G,0,sizeof G);
	memset(deg,0,sizeof deg);
	
	while ( (ch=getchar())!=EOF)
	{
		if (ch==' ')	continue;
	
		if (ch=='\n')
		{
			cnt++;
		}
		if (cnt==0)
		{
			appear[ch-'a']=true;
			n++;
		}
		
		if (cnt==1)
		{
			if (ch=='\n') continue;
			if (cmp)
			{
				cmp=false;
				if (G[last-'a'][ch-'a'])	continue;
				G[last-'a'][ch-'a']=true;
				deg[ch-'a']++;
			}
			else
			{
				cmp=true;
				last=ch;
			}
		}
		
		
		if (cnt==2)
		{
			if (!first)	putchar( '\n');
			first=false;
			slove();
			memset(appear,0,sizeof appear);
			memset(G,0,sizeof G);
			memset(deg,0,sizeof deg);
			cnt=n=0;
		}
	}
	
	return 0;
}



