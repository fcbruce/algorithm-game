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
#define maxn 500001

using namespace std;

int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,554400};
int factornum[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,144,160,168,180,192,200};

char name[maxn][15];
int number[maxn];

int rest[maxn<<2];

void build(int k,int l,int r)
{
    rest[k]=r-l;
    if (r-l==1) return ;
    build(k*2+1,l,l+r>>1);
    build(k*2+2,l+r>>1,r);
}

int update(int res,int k,int l,int r)
{
    rest[k]--;
    if (r-l==1) return l;
    if (res<rest[k*2+1])
    {
        return update(res,k*2+1,l,l+r>>1);
    }
    else
    {
        return update(res-rest[k*2+1],k*2+2,l+r>>1,r);
    }
}

int query(int a,int b,int k,int l,int r)
{
    if (b<=l || r<=a)   return 0;
    if (a<=l && r<=b)   return rest[k];
    return query(a,b,k*2+1,l,l+r>>1)+query(a,b,k*2+2,l+r>>1,r);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,k,p;
    while (~scanf("%d %d",&n,&k))
    {
        for (int i=0;i<n;i++)
        {
            scanf("%s %d",name[i],number+i);
        }

        build(0,0,n);k--;
        int pos=-1;
        while (antiprime[pos+1]<=n)  pos++;

        for (int i=0;i<antiprime[pos];i++)
        {
            p=update(k,0,0,n);
            int rrest=query(0,p,0,0,n);
            int lrest=query(p,n,0,0,n);
            int total=lrest+rrest;
            if (total==0)   break;
            int mov=number[p]%total;
            if (mov==0) mov=number[p]<0?1:-1;
            if (mov<0)
            {
                if (abs(mov)<=rrest)
                    k=rrest+mov;
                else
                    k=rrest+rrest+mov+lrest;
            }
            else
            {
                if (mov<=lrest)
                    k=rrest+mov-1;
                else
                    k=mov-lrest-1;

            }
        }
        printf("%s",name[p]);

        printf(" %d\n",factornum[pos]);
    }

    return 0;
}
