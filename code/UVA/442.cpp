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

struct matrix
{
    int r,c;
    matrix(){r=c=0;}
    matrix(int nr,int nc){r=nr;c=nc;}
    matrix(const matrix &m){r=m.r;c=m.c;}
}m[30];

stack<matrix>   st;

char s[222];

LL solve()
{
    LL res=0;
    int l=strlen(s);
    for (int i=0;i<l;i++)
    {
        if (s[i]=='(')  continue;
        if (s[i]==')')
        {
            matrix a,b;
            b=st.top();st.pop();
            a=st.top();st.pop();
           // printf("%d %d\n%d %d\n",a.c,a.r,b.r,b.c);
            if (a.c!=b.r)   return -1;
            res+=a.r*b.c*b.r;
            st.push(matrix(a.r,b.c));
            continue;
        }
        if (isupper(s[i]))
        {
            st.push(m[s[i]-'A']);
            continue;
        }

    }
    return res;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int n;
    char c;
    scanf("%d",&n);

    for (int i=0;i<n;i++)
    {
        int x,y;
        getchar();
        scanf("%c %d %d",&c,&x,&y);
        int k=c-'A';
        m[k].r=x;m[k].c=y;

    }


    while (scanf("%s",s)!=EOF)
    {
        while (!st.empty()) st.pop();
        int l=strlen(s);
        LL res=solve();
        if (res==-1)
            puts("error");
        else
            printf("%lld\n",res);
    }


    return 0;
}
