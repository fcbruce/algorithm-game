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
#define mm

using namespace std;

int lead[123456];
int last[123456];
int on[123456];
int pl[123456];
int t[123456];
int befored[123456];
int n,m,p,np;
char op;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	scanf("%d%d",&n,&m);getchar();
	memset(last,-1,sizeof(last));
	memset(befored,0,sizeof(befored));
	memset(lead,0,sizeof(lead));
	memset(t,0,sizeof(t));
	memset(pl,0,sizeof(pl));
	int notlead=0;
	int before=0;

	np=0;

	for (int i=0;i<m;i++)
    {
        scanf("%c %d",&op,&p);getchar();
        if (op=='+')
        {
            if (last[p]!=i-1)
                lead[p]=0;
            last[p]=i;
            on[p]=1;
            np++;
            pl[p]=1;
        }
        if (op=='-')
        {
            if (last[p]==-1)
            {
                t[p]=i+1;
                last[p]=i;
                before=1;
                befored[p]=1;
            }
            else
            {
                t[p]+=(i-last[p]+1);
                np--;
            }
            on[p]=0;


        }
    }
    for (int i=1;i<=n;i++)
    {
        if (on[i])
        {
            t[i]+=(m-last[p]+1);
        }
    }
    int num=0;
 //   printf("%d\n",np);
 //printf("%d %d \n",t[3],on[3]);
    for (int i=1;i<=n;i++){
        if ((t[i]==m && (np==0 || on[i]!=0))|| last[i]==-1)
            {
                lead[i]=1;num++;
                if (before && pl[i] && befored[i]!=1)
                {
                    lead[i]=0;
                    num--;
                }
     //           printf("%d is \n",i);
        }
    }
    printf("%d\n",num);

    for (int i=1;i<=n;i++)
        if (lead[i]==1) printf("%d ",i);


	return 0;
}
