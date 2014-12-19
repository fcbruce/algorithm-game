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
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

stack<string> st[53];
string str;
char s[10];

inline bool same(const string &x,const string &y)
{
    return x[0]==y[0] || x[1]==y[1];
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (true)
    {
        int n=52;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            str=s;
            if (str=="#")   return 0;
            while (!st[i].empty()) st[i].pop();
            st[i].push(str);
        }

        while (true)
        {
            int vis=-1;
            for (int i=1;i<=n;i++)
            {
                if (i>3 && same(st[i].top(),st[i-3].top()))
                {
                    st[i-3].push(st[i].top());
                    st[i].pop();
                    vis=i;
                    break;
                }
                if (i>1 && same(st[i].top(),st[i-1].top()))
                {
                    st[i-1].push(st[i].top());
                    st[i].pop();
                    vis=i;
                    break;
                }
            }
            if (vis==-1)    break;
            if (st[vis].empty())
            {
                for (int i=vis;i<n;i++)
                {
                    st[i]=st[i+1];
                }
                n--;
            }
        }

        printf("%d ",n);
        if (n==1)   printf("pile remaining:")  ;
        else        printf("piles remaining:");
        for (int i=1;i<=n;i++)
            printf(" %d",st[i].size());
        printf("\n");


    }

    return 0;
}
