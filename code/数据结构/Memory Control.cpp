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
#define maxn 200007

using namespace std;

int setv[maxn<<2];
int lsum0[maxn<<2],rsum0[maxn<<2],msum0[maxn<<2];

struct Memory
{
    int l,r;
};

vector<Memory> v;

inline void pushup(int k,int l,int r)
{
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;

    if (lsum0[lc]==m-l)   lsum0[k]=lsum0[lc]+lsum0[rc]; else    lsum0[k]=lsum0[lc];
    if (rsum0[rc]==r-m)   rsum0[k]=rsum0[rc]+rsum0[lc]; else    rsum0[k]=rsum0[rc];
    msum0[k]=max(rsum0[lc]+lsum0[rc],max(msum0[lc],msum0[rc]));

}

inline void pushdown(int k,int l,int r)
{
    if (setv[k]!=-1)
    {
        int lc=k*2+1,rc=k*2+2,m=l+r>>1;
        setv[lc]=setv[rc]=setv[k];

        lsum0[lc]=rsum0[lc]=msum0[lc]=setv[k]?0:m-l;

        lsum0[rc]=rsum0[rc]=msum0[rc]=setv[k]?0:r-m;

        setv[k]=-1;
    }
}

void update(int a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return ;
    if (a<=l && r<=b)
    {
        setv[k]=v;
        lsum0[k]=rsum0[k]=msum0[k]=v?0:r-l;
    }
    else
    {
        pushdown(k,l,r);
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
        pushup(k,l,r);
    }
}

int query(int w,int k,int l,int r)
{
    int lc=k*2+1,rc=k*2+2,m=l+r>>1;

    if (r-l==1) return l;

    if (r-l!=1) pushdown(k,l,r);

    if (msum0[lc]>=w) return query(w,lc,l,m);
    if (rsum0[lc]+lsum0[rc]>=w)     return m-rsum0[lc];
    return query(w,rc,m,r);
}

int bin_search(int k)
{
    int l=0,r=v.size()-1,ans=-1;

    while (l<=r)
    {
        itn mid=l+r>>1;
        if (v[mid].l<=k)
        {
            l=mid+1;
            ans=mid;
        }
        else
        {
            r=mid-1;
        }
    }

    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,m,w,a,b,p;
    char op[10];

    while (~scanf("%d %d",&n,&m))
    {
        v.clear();
        update(0,n,0,0,0,n);

        while (m--)
        {
            scanf("%s",op);
            if (op[0]=='R')
            {
                v.clear();
                puts("Reset Now");
                update(0,n,0,0,0,n);
                continue;
            }

            if (op[0]=='N')
            {
                scanf("%d",&w);
                if (w<=msum0[0])
                {
                    a=query(w,0,0,n);
                    b=a+w;
                    update(a,b,1,0,0,n);
                    printf("New at %d\n",a+1);
                    Memory temp;
                    temp.l=a+1;
                    temp.r=b;
                    int id=bin_search(a+1)+1;
                    v.insert(v.begin()+id,temp);

                }
                else
                    puts("Reject New");
                continue;
            }

            if (op[0]=='F')
            {
                scanf("%d",&p);

                int id=bin_search(p);

                if (id==-1 || v[id].r<p)
                    puts("Reject Free");
                else
                {
                    printf("Free from %d to %d\n",v[id].l,v[id].r);
                    update(v[id].l-1,v[id].r,0,0,0,n);
                    v.erase(v.begin()+id,v.begin()+id+1);
                }
                continue;
            }

            if (op[0]=='G')
            {
                scanf("%d",&w);
                if (w<=v.size())
                    printf("Get at %d\n",v[w-1].l);
                else
                    puts("Reject Get");
            }
        }

        puts("");
    }


    return 0;
}
