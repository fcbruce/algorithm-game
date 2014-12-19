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
#define mm

using namespace std;

int n;
int a[3003];
int v[3003];
int ans;

int _find(int x)
{
    int l=0,r=n;
    int k=0;
    while (l<=r)
    {
        int mid=(l+r)>>1;

        if (v[mid]<x)
        {
            l=mid+1;
        }
        else
        {
            k=mid;
            r=mid-1;
        }
    }

    return k;
}

void write()
{
    for (itn i=0;i<n && v[i]!=INF;i++)
        printf("%4d",v[i]);
    puts("");
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

//    printf("%d %d\n",1<<30,INF);

    while (~scanf("%d",&n))
    {
        for (itn i=0;i<n;i++)
        {
            scanf("%d",a+i);
            v[i]=INF;
        }
//        for (int i=0;i<n;i++)
//            printf("%d ",v[i]);
//        puts("");

        sort(a,a+n);
        reverse(a,a+n);
        ans=0;

        for (int i=0;i<n;i++)
        {
//            int kk=_find(a[i]);//upper_bound(v,v+n,a[i])-v;
//            v[kk]=a[i];
//            ans=max(ans,++kk);
            int j;
            for (j=ans-1;j>=0 && v[j]==a[i];j--);
            if (j>=0)   v[j]=a[i];
            else        v[j=ans]=a[i];
            ans=max(ans,++j);
//            write();
        }
//
//        for (int i=0;v[i]!=INF;i++)
//        {
//            printf(" %d",v[i]);
//        }
//        puts("");

        printf("%d\n",ans);
    }


    return 0;
}
