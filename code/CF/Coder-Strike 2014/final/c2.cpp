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
#define mm 123456

using namespace std;

int lead[mm],befp[mm],last[mm],on[mm],t[mm];
int p,op,bef;
char c;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	memset(last,-1,sizeof(last));

	int n,m;
	scanf("%d%d",&n,&m);getchar();

    for (int i=0;i<m;i++)
    {
        scanf("%c %d",&c,&p);getchar();
        if (c=='+')
        {
            if (i-last[p]!=1)
            {
                lead[p]=-1;
            }
            else
            {
                last[p]=i;
            }
            on[p]=1;
            op++;
        }
        else
        {
            if (last[p]==-1)
            {
                bef=1;
                befp[p]=1;
                t[p]=i+1;
            }
            else
            {
                t[p]=i+1-last[p];
                op--;
                on[p]=0;
            }
        }
    }

    int num=0;
    for (int i=1;i<=n;i++)
    {
        if (on[i])
            t[i]=m+1-last[i];

        if (bef==1 && befp[i]!=1)
            t[i]=0;

        if (lead[i]!=-1){
            if (t[i]==m || last[i]==-1 )
        {
            lead[i]=1;
            num++;
        }
        }
    }

    printf("%d\n",num);
    for (int i=1;i<=n;i++)
        if (lead[i]) printf("%d ",i);




	return 0;
}
