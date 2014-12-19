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
int cc;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n,k,p,x;
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

    if (k==p)
    {
        if (od.size()&1 || od.size()/2+ev.size()<k)
        {
            puts("NO");
            return 0;
        }
        else
        {
            puts("YES");
            if (p==1)
            {
                printf("%d",n);
                for (int i=0;i<od.size();i++)
                    printf(" %d",od[i]);
                for (int i=0;i<ev.size();i++)
                    printf(" %d",ev[i]);
                puts("");
                return 0;
            }
/*
            printf("%d",od.size());
            for (itn i=0;i<od.size();i++)
            {
                printf(" %d",od[i]);
            }
            puts("");
            p--;*/
            int i=0;
            while (p>1 && i<od.size())
            {
                printf("2 %d",od[i++]);printf(" %d\n",od[i++]);
                p--;
            }
            if (p==1)
            {
                printf("%d",od.size()-i+ev.size());
                for (;i<od.size();i++)
                    printf(" %d",od[i]);
                for (i=0;i<ev.size();i++)
                    printf(" %d",ev[i]);
                puts("");
                return 0;
            }
            //int i=0;
            if (od.size()-i){
            printf("%d",od.size()-i);
                for (;i<od.size();i++)
                    printf(" %d",od[i]);
                    p--;
            }
            while (p>1)
            {
                printf("1 %d\n",ev[i++]);
                p--;
            }
            if (ev.size()-i >0){
            printf("%d",ev.size()-i);
            for (;i<ev.size();i++)
                printf(" %d",ev[i]);
            puts("");
            }
            return 0;
        }
    }

    if (ev.size()>=p)
    {
        if (od.size()-(k-p)<0 || (od.size()-(k-p))&1)
        {
            puts("NO");
            return 0;
        }
        else
        {
            puts("YES");
            int i=0;
            int pp=p;
            while (p)
            {
                printf("1 %d\n",ev[i++]);
                p--;
            }


            int t=k-pp;
            int j=0;
            while (t>1)
            {
                printf("1 %d\n",od[j++]);
                t--;
            }
            printf("%d",od.size()-j+ev.size()-i);
            for (;j<od.size();j++)
                printf(" %d",od[j]);
            for (;i<ev.size();i++)
                printf(" %d",ev[i]);
            puts("");
        }
    }
    else
    {
        int re=p-ev.size();
        if (re*2 < od.size() && (od.size()-re*2)>=(k-p) && ((od.size()-re*2-(k-p))&1)==0)
        {
            puts("YES");
            for (int i=0;i<ev.size();i++)
            {
                printf("1 %d\n",ev[i]);
            }

            int i=0;
            for (int j=0;j<re;j++)
            {
                printf("2 %d ",od[i++]);printf("%d\n",od[i++]);
            }
            itn t=od.size()-re*2;
            while (t>1)
            {
                printf("1 %d\n",od[i++]);
                t--;
            }
            if (t){
            printf("%d",od.size()-i);
            for (;i<od.size();i++)
                printf(" %d",od[i]);
            puts("");
            }
        }
        else
        {
            puts("NO");
        }
    }

    return 0;
}
