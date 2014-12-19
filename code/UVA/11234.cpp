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
#define mm 10001

using namespace std;

struct Node
{
    int i,l,r;
}node[mm];

stack<int> st;
queue<int> que;

char s[mm];
string str;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;

    scanf("%d",&tt);

    while (tt--)
    {
        while (!st.empty()) st.pop();
        while (!que.empty())    que.pop();

        scanf("%s",s);
        int l=strlen(s);

        for (int i=0;i<l;i++)
        {
            node[i].i=i;
            node[i].l=node[i].r=-1;
            if (islower(s[i]))
            {
                st.push(i);
                continue;
            }
            if (isupper(s[i]))
            {
                node[i].r=st.top();st.pop();
                node[i].l=st.top();st.pop();
                st.push(i);
            }
        }

        int k=st.top();st.pop();
        que.push(k);
        str="";
        while (!que.empty())
        {
            int k=que.front();
            que.pop();

            str+=s[k];
            if (node[k].l!=-1)  que.push(node[k].l);
            if (node[k].r!=-1)  que.push(node[k].r);
        }
        reverse(str.begin(),str.end());

        puts(str.c_str());
    }




    return 0;
}
