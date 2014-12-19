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
#define maxn

using namespace std;

struct qq
{
    int t,id;
    bool operator < (const qq &q)const
    {
        return t<q.t;
    }
}q[123456];

struct tas
{
    int t,id;
    bool operator < (const tas &ta)const
    {
        return t<ta.t;
    }
}t[123456];

int ans[123456];



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T,n,m;
    scanf("%d",&T_T);
    while (T_T--)
    {
        scanf("%d %d",&n,&m);
        for (int i=0;i<n;i++)
        {
            scanf("%d",&t[i].t);
            t[i].id=i;
        }
        for (int i=0;i<m;i++)
        {
            scanf("%d",&q[i].t);
            q[i].id=i;
        }
        t[n].t=0;
        n++;

        sort(t,t+n);
        sort(q,q+m);

        for (itn i=0,j=0;j<m;j++)
        {
            for (;i<n-1;)
            {
//                cout<<( (q[j].t<t[i].t && t[i+1].t>t[i].t+1 || q[j].t>=t[i].t && q[j].t<t[j+1].t && t[i+1].t>t[i].t+1) )<<endl;
//                printf("%d < %d && %d > %d || %d >= %d && %d<%d && %d>%d\n",q[j].t,t[i].t ,t[i+1].t,t[i].t+1 , q[j].t,t[i].t , q[j].t,t[j+1].t , t[i+1].t,t[i].t+1);
                if (q[j].t<t[i].t && t[i+1].t>t[i].t+1 || q[j].t>=t[i].t && q[j].t<t[i+1].t && t[i+1].t>t[i].t+1) break;
                i++;
            }
//            printf("qt = %d t[i].t = %d t[i+1].t = %d \n",q[j].t,t[i].t,t[i+1].t);
            ans[q[j].id]=max(t[i].t+1,q[j].t);
        }
        for (int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }


    return 0;
}
