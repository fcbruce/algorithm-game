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
#define mm 200000

using namespace std;

int h,w;
int _max[mm<<2];
int _min[mm<<2];
int rec[mm];

void update(int p,int v,int k,int l,int r)
{
    if (r-l==1)
    {
        _max[k]=_min[k]=v;
        return ;
    }

    int m=l+r>>1;
    if (p<m)    update(p,v,k*2+1,l,m);  else    update(p,v,k*2+2,m,r);
    _max[k]=max(_max[k*2+1],_max[k*2+2]);
    _min[k]=min(_min[k*2+1],_min[k*2+2]);
}

void query(int v,int k,int l,int r,itn &ans)
{
    if (v>w-_min[k])    return ;

    if (v<=w-_max[k])
    {
        ans=min(l,ans);
        return ;
    }

    if (r-l==1) return ;

    int m=l+r>>1;
    query(v,k*2+1,l,m,ans);
    if (ans<m)  return ;    //重要剪枝
    query(v,k*2+2,m,r,ans);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,v,ans,p;

    while (~scanf("%d %d %d",&h,&w,&n))
    {
        int _n=min(n,h);    //最多这么多行啦,如果h>n就都浪费啦
        for (int i=0;i<_n;i++)
            update(i,0,0,0,_n),rec[i]=0;

        while (n--)
        {
            scanf("%d",&v);
            ans=INF;
            query(v,0,0,_n,ans);
            if (ans!=INF && w-rec[ans]>=v)
            {

                printf("%d\n",ans+1);
                rec[ans]+=v;
                update(ans,rec[ans],0,0,_n);

            }
            else
            {
                puts("-1");
            }
        }
    }


    return 0;
}
