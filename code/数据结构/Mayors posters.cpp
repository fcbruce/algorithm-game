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
#define maxm 80004
#define maxn 10001

using namespace std;

struct poster
{
    int a,b;
}p[maxn];

int setv[maxm<<2];
bool _hash[maxn];
int pos[maxn<<1];
map<int,int> MAP;
int ans;

void pushdown(int k)
{
    if (setv[k]>0)
    {
        setv[k*2+1]=setv[k*2+2]=setv[k];
        setv[k]=-1;
    }
}

void update(itn a,int b,int v,int k,int l,int r)
{
    if (b<=l || r<=a)   return;
    if (a<=l && r<=b)
    {
        setv[k]=v;
        return ;
    }
    else
    {
        pushdown(k);
        update(a,b,v,k*2+1,l,l+r>>1);
        update(a,b,v,k*2+2,l+r>>1,r);
    }
}

void query(int k,int l,int r)
{
    if (r-l==1)
    {
        if (setv[k]>0)
            if (!_hash[setv[k]])
            {
                _hash[setv[k]]=true;
                ans++;
            }
        return ;
    }
    pushdown(k);
    query(k*2+1,l,l+r>>1);
    query(k*2+2,l+r>>1,r);
}


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,a,b   ;
    scanf("%d",&T_T);
    while (T_T--)
    {
        MAP.clear();
        memset(setv,-1,sizeof setv);
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            p[i].a=a;p[i].b=b;
            MAP[a]=MAP[b]=0;
            //update(a,b,i,0,0,maxm);
        }

        int kk=0;
        int last=-1;
        for (map<int,int>::iterator it=MAP.begin();it!=MAP.end();it++)
        {
            if (it->first-last==1)  kk++;
            else    kk+=2;
            last=it->first;
//            printf("MAP %d %d\n",it->first,kk);
            it->second=kk;
        }
//            it->second=kk<<1;

        for (itn i=0;i<n;i++)
        {
            update(MAP[p[i].a]-1,MAP[p[i].b],i+1,0,0,kk<<1);
//            printf("%d %d\n",MAP[p[i].a]-1,MAP[p[i].b]);
        }
        memset(_hash,0,sizeof _hash);
        ans=0;
        query(0,0,kk<<1);
        printf("%d\n",ans);
    }


    return 0;
}

