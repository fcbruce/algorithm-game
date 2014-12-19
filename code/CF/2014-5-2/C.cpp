#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm 300003
#define nn 100001

using namespace std;

int fir[nn];
int u[mm],v[mm],nex[mm];
int n,m;
int a[nn],p[nn],num[nn],d[nn];
bool inq[nn];

void init()
{
    for (int i=1;i<n;i++)
    {
        p[i]=i;
        num[i]=0;
    }
}


void rg()
{
    memset(fir,01,sizeof(fir));

    for (int i=0;i<m;i++)
    {
        scanf("%d%d",u[i],v[i]);
        nex[i]=fir[u[i]];
        fir[u[i]]=i;
    }

}

void spfa(int s)
{
    queue<int> q;
    memset(inq,false,sizeof(inq));
    memset(d,INF,sizeof(INF));
    d[s]=0;
    q.push(s);

    while (!q.empty())
    {
        int x=q.front();q.pop();
        inq[x]=false;
        for (int e=fir[x];e!=-1;e=nex[e])
        {
            if (d[v[e]]>d[x]+1)
            {
                d[v[e]]=d[x]+1;
                if (!inq[v[e]])
                {
                    inq[v[e]]=true;
                    q.push(v[e]);
                }
            }
        }
    }
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	scanf("%d",&n);

	for (int i=0;i<n;i++)
        scanf("%d",a+i);

    scanf("%d",m);

    rg();
    init();

    for (int i=0;i<n;i++)
    {
        spfa(i);
        for (int j=0;j<n;j++)
        {
            if (d[j]<INF)
            {

            }
        }
    }






	return 0;
}
