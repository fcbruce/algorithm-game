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
#define mm 50000

using namespace std;

int _sumv[mm<<2];

void add(itn p,int v,int k,int l,int r)
{
    if (r-l==1)
    {
        _sumv[k]+=v;
        return ;
    }

    int m=l+r>>1;
    if (p<m)    add(p,v,k*2+1,l,m); else    add(p,v,k*2+2,m,r);
    _sumv[k]=_sumv[k*2+1]+_sumv[k*2+2];
}

int query(int a,itn b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;

    if (a<=l && r<=b)   return _sumv[k];

    return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,a,b,p,v;
    scanf("%d\n",&T_T);
    for (int T__T=1;T__T<=T_T;T__T++)
    {
        printf("Case %d:\n",T__T);
        scanf("%d",&n);
        memset(_sumv,0,sizeof(_sumv));
        for (int i=0;i<n;i++)
        {
            scanf("%d",&v);
            add(i,v,0,0,n);
        }
        char op[10];
        while (~scanf("%s",op),strcmp("End",op))
        {
            //printf("%s\n",op);
            if (op[0]=='A')
            {
                scanf("%d %d",&p,&v);
                p--;
                add(p,v,0,0,n);
                continue;
            }

            if (op[0]=='S')
            {
                scanf("%d %d",&p,&v);
                p--;
                add(p,-v,0,0,n);
                continue;
            }

            if (op[0]=='Q')
            {
                scanf("%d %d",&a,&b);
                a--;
                printf("%d\n",query(a,b,0,0,n));
                continue;
            }
        }
    }


    return 0;
}
