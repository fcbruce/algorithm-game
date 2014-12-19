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
#define maxm 200020
#define maxn 200020

using namespace std;

LL _min[maxm<<2];
LL _add[maxm<<2];

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        _add[k]+=v;
    }
    else
    {
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
    }
    if (r-l==1) _min[k]=_add[k];
    else
    _min[k]=min(_min[k*2+1],_min[k*2+2])+_add[k];
}

LL _minv;
void query(int a,int b,int k,int l,int r,LL _addv)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        _minv=min(_minv,_min[k]+_addv);
    }
    else
    {
        query(a,b,k*2+1,l,l+r>>1,_addv+_add[k]);
        query(a,b,k*2+2,l+r>>1,r,_addv+_add[k]);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,a,b,v;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&v);
        update(i,i+1,v,0,0,n);
    }

    scanf("%d",&m);getchar();

    char str[100];
    while (m--)
    {
        gets(str);
        if (sscanf(str,"%d %d %d",&a,&b,&v)==2)
        {
            _minv=(long long )INF<<8|INF;
            if (a<=b)
                query(a,b+1,0,0,n,0);
            else
                query(0,b+1,0,0,n,0),query(a,n,0,0,n,0);
            printf("%I64d\n",_minv);
        }
        else
        {
            if (a<=b)
                update(a,b+1,v,0,0,n);
            else
                update(0,b+1,v,0,0,n),update(a,n,v,0,0,n);
        }    }



    return 0;
}
