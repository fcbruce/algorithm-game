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

vector<int> ev,od,ans[123456];
int cc,me,mo;
int n,k,p,x,q;

void solve()
{
    puts("YES");
    for (itn i=0;i<k;i++)
    {
        printf("%d",ans[i].size());
        for (int j=0;j<ans[i].size();j++)
        {
            printf(" %d",ans[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d",&n,&k,&p);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if (x&1)
        {
            od.push_back(x);
        }
        else
        {
            ev.push_back(x);
        }
    }

    q=k-p;
    me=ev.size();
    mo=od.size();
    //printf("%d %d\n",me,mo);
    int pe=0,po=0;

    if (q==0)
    {
        if (mo&1)
        {
            puts("NO");
            return 0;
        }
        else
        {
            for (;po<mo && cc<k;)
            {
                ans[cc].push_back(od[po]);po++;
                ans[cc].push_back(od[po]);po++;
                cc++;
            }
            for (;pe<me && cc<k;)
            {
                ans[cc].push_back(ev[pe]);pe++;
                cc++;
            }
            if (cc==k)
            {
                while (po<mo)
                {
                    ans[0].push_back(od[po++]);
                }
                while (pe<me)
                {
                    ans[0].push_back(ev[pe++]);
                }
            }

            if (cc==k)
            {
                solve();return 0;
            }
            else
            {
                puts("NO");
                return 0;
            }
        }
    }

    for (;po<mo && cc<q;po++)
    {
        //printf("%d\n",cc);
        ans[cc].push_back(od[po]);
        cc++;
    }

    if (cc<q)
    {
        puts("NO");
        return 0;
    }

    if ((mo-po)%2)
    {
        puts("NO");
        return 0;
    }

    for (;po<mo && cc<k;po+=2)
    {
        ans[cc].push_back(od[po]);
        ans[cc].push_back(od[po+1]);
        cc++;
    }

    for (;pe<me && cc<k;pe++)
    {
        //printf("%d\n",cc);
        ans[cc].push_back(ev[pe]);
        cc++;
    }
    //printf("%d %d\n",pe,po);
    if (cc==k)
    {
        while (po<mo)
        {
            ans[0].push_back(od[po++]);
        }
        while (pe<me)
        {
            ans[0].push_back(ev[pe++]);
        }
        solve();
        return 0;
    }
    else
    {
        //printf("%d\n",cc);
        puts("NO");
        return 0;
    }






    return 0;
}
