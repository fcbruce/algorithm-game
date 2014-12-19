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
#define maxm
#define maxn 1000007

using namespace std;

int minv[maxn<<2],addv[maxn<<2];

void build(int k,int l,int r)
{
    if (r-l==1)
    {
        scanf("%d",&minv[k]);
        addv[k]=0;
        return ;
    }
    build(k*2+1,l,l+r>>1);
    build(k*2+2,l+r>>1,r);
    addv[k]=0;
    minv[k]=min(minv[k*2+1],minv[k*2+2]);
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        addv[k]+=v;
        minv[k]+=v;
        return ;
    }
    update(a,b,v,k*2+1,l,l+r>>1);
    update(a,b,v,k*2+2,l+r>>1,r);
    minv[k]=min(minv[k*2+1],minv[k*2+2])+addv[k];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,a,b,v;

    scanf("%d %d",&n,&m);
    build(0,0,n);

    for (int i=0;i<m;i++)
    {

        scanf("%d %d %d",&v,&a,&b);
//        printf("%d %d %d\n",a,b,-v);
        a--;
        if (minv[0]<0)
        {
            puts("-1");
            printf("%d\n",i);
            return 0;
        }

        update(a,b,-v,0,0,n);
//        cout<<minv[0]<<endl;
//        if (query(a,b,0,0,n)<v)
//        {
//            puts("-1");
//            printf("%d\n",i+1);
//            break;
//        }
//        else
//        {
//            update(a,b,-v,0,0,k)
//        }

    }

    if (minv[0]<0)
    {
        puts("-1");
        printf("%d\n",m);
        return 0;
    }

    printf("%d\n",0);

    return 0;
}
