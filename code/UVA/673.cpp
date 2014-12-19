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

stack<int> st;

char s[200];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);getchar();

    for (int t=0;t<tt;t++)
    {
        fgets(s,200,stdin);
        int l=strlen(s)-1;
        while (!st.empty()) st.pop();

        bool flag=true;

        for (int i=0;i<l;i++)
        {
            if (s[i]=='(')
            {
                st.push(1);
                continue;
            }
            if (s[i]=='[')
            {
                st.push(2);
                continue;
            }
            if (s[i]==')')
            {
                if (!st.empty() && st.top()==1) st.pop();
                else
                {
                    flag=false;
                    break;
                }
                continue;
            }
            if (s[i]==']')
            {
                if (!st.empty() && st.top()==2) st.pop();
                else
                {
                    flag=false;
                    break;
                }
                continue;
            }
        }

        if (flag && st.empty())
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }

    return 0;
}
