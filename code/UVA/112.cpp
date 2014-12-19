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
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm

using namespace std;

struct Node
{
    int v,l,r,k;
    //v 节点的权值,l 左孩子的指针,r 右孩子的指针,k 该点右括号的数量
}node[1000000];
stack<int>st;
int n,sum,root;
bool f;

void solve()
{
    char c;
    int l=0,r=0;
    int sign=1;

    while (true)
    {
        while (c=getchar(),isspace(c))  ;

        if (c=='(')
        {
            l++;
            continue;
        }
        if (c==')')
        {
            r++;
            if (!st.empty())
            {
                int k=st.top();
                node[k].k++;
                if (node[k].k==2)//找父亲
                {
                    st.pop();
                    if (!st.empty())
                    {
                         if (node[st.top()].l==-1)
                        {
                            node[st.top()].l=k;
                        }
                        else
                        {
                            node[st.top()].r=k;
                        }
                    }
                    else
                    {
                        root=k;
                    }
                }
            }
            if (l==r)   break;
            continue;
        }
        if (c=='-')
        {
            sign=-1;
            continue;
        }
        if (isdigit(c))
        {
            int v=c-'0';
            while (c=getchar(),isdigit(c))
            {
                v=v*10+c-'0';
            }
            v*=sign;
            node[n].v=v;
            node[n].l=node[n].r=-1;
            node[n].k=0;
            st.push(n);
            n++;
            sign=1;

            if (c=='(') l++;
            continue;
        }
    }

}

void dfs(int x,int s)
{
    if (x==-1)  return ;
    if (node[x].l==-1 && node[x].r==-1)
    {
        if (s+node[x].v==sum) f=true;
        return ;
    }
    if (f)  return ;
    if (node[x].l!=-1) dfs(node[x].l,s+node[x].v);
    if (node[x].r!=-1) dfs(node[x].r,s+node[x].v);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (~scanf("%d",&sum))
    {
        n=0;
        while (!st.empty()) st.pop();
        solve();

        if (n==0)
        {
            puts("no");
            continue;
        }
        f=false;
        dfs(root,0);
        if (f)
        {
            puts("yes");
        }
        else
        {
            puts("no");
        }

    }

    return 0;
}

