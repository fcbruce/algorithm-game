/*
 *
 *	Author	:	fcbruce
 *
 *	Date	:	2014-08-16 19:28:45 
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
#define maxm sqr(505)
#define maxn 505
#define FUCK_YOU 0

using namespace std;

int fir[maxn];
int u[maxm],v[maxm],nex[maxm];
int e_max;
char str[maxn];
int deg[maxn];
int topo[maxn];
bool del[maxn];

int n,m;

void add_edge(int _u,int _v)
{
    int e=e_max++;
    u[e]=_u;v[e]=_v;
    nex[e]=fir[u[e]];fir[u[e]]=e;

}

bool slove()
{	

	int _v;
	for (int i=0;i<n;i++)
	{
		_v=-1;
		for (int j=1;j<=n;j++)
		{
			if (!del[j] && (_v==-1 || deg[_v]<=deg[j])) _v=j;
		}
		
		del[_v]=true;

		for (int e=fir[_v];~e;e=nex[e])
		{
			deg[v[e]]--;
		}
		
		topo[i]=_v;

	}
	
	return true;
}

void write()
{
	for (int i=n-1;i>=0;i--)
	{
		printf( "%d",topo[i]);
		if (i)	putchar( ' ');
	}
	putchar( '\n');
}



int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/home/fcbruce/文档/code/t","r",stdin);
	#endif // ONLINE_JUDGE
	int __=0;
	
	while (scanf( "%d",&n),n)
    {
//    	printf( "%d ",++__);
        e_max=0;
        memset(fir,-1,sizeof fir);
        memset(deg,0,sizeof deg);
        memset(del,0,sizeof del);
        int fuckyou=0;

        for (int i=1;i<=n;i++)
        {
            scanf("%s",str+1);
            for (int j=1;j<=n;j++)
            {

                if (str[j]=='0')
                    ;
                else
                {
                    add_edge(j,i);
                    deg[j]++;
                    fuckyou++;
                }
            }

        }
        
        for (int k=1;k<=n;k++)
        
        
        if (fuckyou!=(n*(n-1)/2))
        	puts( "fuckyou!");	
        
//        for (int i=1;i<=n;i++)
//        	printf( "%d\n",deg[i]);
        
        if (slove())
        {
        	write();
        }
        else
        	puts( "-1");
        
        
	}
	
	return FUCK_YOU;
}



