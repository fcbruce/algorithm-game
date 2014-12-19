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

char str[1234567],s[1234567];
int st[1234567];

bool none;

int did(int ll)
{
    int top=0;
//    puts(s);
    for (int i=1;i<ll;i++)
    {
        if (s[i]==')' && s[top]=='(')
            top--;
        else
            s[++top]=s[i];
//            printf("%d\n",top);
    }
    s[++top]='\0';
//    puts(s);
//    puts("");
    return top;
}

int check(int len)
{
    int top=-1;
    int l,r;
    l=r=0;
    for (int i=0;i<len;i++)
    {
        if (s[i]=='(')
        {
            l++;
//            continue;
        }
        if (s[i]=='?')
        {
            st[++top]=i;
//            continue;
        }
        if (s[i]==')')
        {
            r++;
            if (r>l+top+1)
            {
                none=false;
                return -1;
            }

        }

        if (l+top+1==r || l+top==r)
        {
            while (top>=0)
            {
                s[st[top]]='(';
                l++;
                top--;
            }
        }

    }

    return top+1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%s",s))
    {
        int ll=strlen(s);

        if (ll&1)
        {
            puts("None");
            continue;
        }

        none=true;
        int last=-1;
        int rest;
        for (;;)
        {
            ll=did(ll);

            rest=check(ll);
            reverse(s,s+ll);
            for (int i=0;i<ll;i++)
            {
                if (s[i]=='(') s[i]=')';
                else
                    if (s[i]==')') s[i]='(';
            }
            ll=did(ll);
            rest=check(ll);
            if (!none || rest==0 || rest==last)  break;
            last=rest;

        }

        if (!none)
        {
            puts("None");
            continue;
        }

        if (rest)
            puts("Many");
        else
            puts("Unique");

    }

    return 0;
}
