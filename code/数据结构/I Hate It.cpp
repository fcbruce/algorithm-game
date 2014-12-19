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
#include<list>
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm 8000000

using namespace std;

int n,a[mm];

void init(int n_)
{
    n=1;
    while (n<n_)    n<<=1;

    memset(a,-1,sizeof a);
}

void update(int k,int x)
{
    k+=n-1;
    a[k]=x;

    while (k>0)
    {
        k=(k-1)>>1;
        a[k]=max(a[(k<<1)+1],a[(k<<1)+2]);
    }
}

int query(int x,int y,int k,itn l,int r)
{
    if (r<=x || y<=l)   return -1;

    if (x<=l && r<=y)   return a[k];
    else
    {
        int v1=query(x,y,k*2+1,l,(l+r)>>1);
        itn v2=query(x,y,k*2+2,(l+r)>>1,r);

        return max(v1,v2);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int N,M,x,y;
    char ch;
    while (scanf("%d%d",&N,&M)==2)
    {
        init(N);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&x);
            update(i,x);
        }
        while (M--)
        {
//            getchar();
//            ch=getchar();
            scanf("%1s %d %d",&ch,&x,&y);
            x--;
            if (ch=='Q')
                printf("%d\n",query(x,y,0,0,n));
            else
                update(x,y);
        }
    }


    return 0;
}
