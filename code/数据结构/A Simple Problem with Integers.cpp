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
#define mm (100000<<2)

using namespace std;

itn n,q;
LL a[mm],b[mm];

void add(int x,int y,int t,itn k,int l,int r)
{
    if (x<=l && y>=r)
    {
        a[k]+=t;
    }
    else
    {
        if (l<y && x<r)
        {
            b[k]+=(min(y,r)-max(x,l))*t;
            add(x,y,t,k*2+1,l,l+r>>1);
            add(x,y,t,k*2+2,l+r>>1,r);
        }
    }
}

LL sum(int x,int y,int k,int l,int r)
{
    if (y<=l || x>=r)   return 0;

    if (x<=l && r<=y)   return a[k]*(r-l)+b[k];

    LL res=(min(r,y)-max(l,x))*a[k];
    res+=sum(x,y,k*2+1,l,(l+r)>>1);
    res+=sum(x,y,k*2+2,(l+r)>>1,r);

    return res;
}

void write()
{
    puts("---------------------------------------------------------------");
    for (int i=0;i<n<<2;i++)   printf("%3d ",i);puts("");
    puts("---------------------------------------------------------------");
    for (int i=0;i<n<<2;i++)   printf("%3d ",a[i]);
    puts("");
    for (int i=0;i<n<<2;i++)   printf("%3d ",b[i]);
    puts("");

    puts("---------------------------------------------------------------");
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
        freopen("/home/fcbruce/文档/code/t1","w",stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d",&n,&q);
    int x,y,z;
    char ch;

    for (itn i=0;i<n;i++)
    {
        scanf("%d",&x);
        add(i,i+1,x,0,0,n);
//        write();
    }

    for (itn i=0;i<q;i++)
    {
        scanf("%1s",&ch);

        if (ch=='C')
        {
            scanf("%d%d%d",&x,&y,&z);
            add(x-1,y,z,0,0,n);
        }
        else
        {
            scanf("%d%d",&x,&y);
            printf("%lld\n",sum(x-1,y,0,0,n));
        }
//        write();
    }

    return 0;
}
