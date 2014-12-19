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
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int a[33],b[33];
int x,n,k,v;
char c;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	n=0;
	while (~scanf("%d%c",&x,&c))
    {
        if (c!='\n')
        {
            b[n]=x;
            a[n++]=x;
            printf("%d%c",x,c);
            continue;
        }

        printf("%d%c",x,c);
        b[n]=x;
        a[n++]=x;
        sort(b,b+n);

        k=n-1;
        while (k)
        {
            while (k>=0 && a[k]==b[k])  k--;
          //  printf("k=%d\n",k);
            if (k==-1)   break;
       //     freopen("con","r",stdin);
     //       getchar();

            v=-1;
            for (int i=k;i>=0;i--)
            {
                if (a[i]==b[k])
                {
                    v=i;
                    break;
                }
            }
         //   printf("v=%d\n",v);
            if (v!=0)
            {

                reverse(a,a+v+1);
                printf("%d ",n-v);
            }
         //   getchar();

            printf("%d ",n-k);
            reverse(a,a+k+1);
        }

        printf("0\n");

        n=0;


    }


	return 0;
}
