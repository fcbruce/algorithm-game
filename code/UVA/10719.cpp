#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm 10001

using namespace std;

int a[mm];
int k;
int b[mm];
int r,n;
char c;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt=0;

	while (~scanf("%d",&k))
	{
	    n=0;
	    while (scanf("%d%c",&a[n++],&c)==2)
        {
           // c=getchar();
          // printf("n=%d%c",a[n-1],c);
            if (c=='\n')    break;
        }
        //printf("n=%d\n",n);
        for (int i=0;i<n;i++)
        {
            b[i]=a[i];
            a[i+1]+=b[i]*k;
        }

        printf("q(x):");
        for (int i=0;i<n-1;i++)
        {
            printf(" %d",b[i]);
        }
        printf("\nr = %d\n\n",b[n-1]);
	}

	return 0;
}
