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

deque<int> dq;
stack<int>  lst,rst;
int res;

void write()
{
    if (res==0)
    {
        while (!lst.empty())
        {
            dq.push_front(lst.top());
            lst.pop();
        }
        while (!rst.empty())
        {
            dq.push_back(rst.top());
            rst.pop();
        }
        bool flag=false;
        while (!dq.empty())
        {
            if (flag)   printf(" ");
            flag=true;
            printf("%d",dq.front());
            dq.pop_front();
        }
    }
    else
    {
        while (!lst.empty())
        {
            dq.push_back(lst.top());
            lst.pop();
        }
        while (!rst.empty())
        {
            dq.push_front(rst.top());
            rst.pop();
        }
        bool flag=false;
        while (!dq.empty())
        {
            if (flag)   printf(" ");
            flag=true;
            printf("%d",dq.back());
            dq.pop_back();
        }
    }
    puts("");
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    int T_T;
    scanf("%d",&T_T);
    while (T_T--)
    {
        dq.clear();
        res=0;
        int n,x;
        scanf("%d",&n);
        for (itn i=0;i<n;i++)
        {
            scanf("%d",&x);
            dq.push_back(x);
        }
        int l;int r;
        scanf("%d%d",&l,&r);

        for (itn i=1;i<l;i++) lst.push(dq.front()),dq.pop_front();
        for (int i=n;i>r;i--)   rst.push(dq.back()),dq.pop_back();
        scanf("%d",&n);
        char op[20];
        char ch;
        int p=0;
        while (n--)
        {
            scanf("%s",op);

            if(strcmp(op,"Reverse")==0)
            {
                res^=1;

                continue;
            }

            if (strcmp(op,"MoveLeft")==0)
            {
//                printf("%s\n",op);
                scanf(" %c",&ch);
                if (ch=='L')
                {
                    if (res==0)
                    {
                        dq.push_front(lst.top());
                        lst.pop();
                    }
                    else
                    {
                        dq.push_back(lst.top());
                        lst.pop();
                    }
                }
                else
                {
                    if (res==0)
                    {
                        rst.push(dq.back());
                        dq.pop_back();
                    }
                    else
                    {
                        rst.push(dq.front());
                        dq.pop_front();
                    }
                }

                continue;
            }

            if (strcmp(op,"MoveRight")==0)
            {
//                printf("%s\n",op);
                scanf(" %c",&ch);
                if (ch=='L')
                {
                    if (res==0)
                    {
                        lst.push(dq.front());
                        dq.pop_front();
                    }
                    else
                    {
                        lst.push(dq.back());
                        dq.pop_back();
                    }
                }
                else
                {
                    if (res==0)
                    {
                        dq.push_back(rst.top());
                        rst.pop();
                    }
                    else
                    {
                        dq.push_front(rst.top());
                        rst.pop();
                    }
                }

                continue;
            }

            if (strcmp(op,"Insert")==0)
            {
//                printf("%s\n",op);
                scanf(" %c %d",&ch,&x);
                if (ch=='L')
                {
                    if (res==0)
                    {
                        dq.push_front(x);
                    }
                    else
                    {
                        dq.push_back(x);
                    }
                }
                else
                {
                    if (res==0)
                    {
                        dq.push_back(x);
                    }
                    else
                    {
                        dq.push_front(x);
                    }
                }

                continue;
            }

            if (strcmp(op,"Delete")==0)
            {
//                printf("%s\n",op);
                scanf(" %c %d",&ch,&x);
                if (ch=='L')
                {
                    if (res==0)
                    {
                        dq.pop_front();
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
                else
                {
                    if (res==0)
                    {
                        dq.pop_back();
                    }
                    else
                    {
                        dq.pop_front();
                    }
                }

                continue;
            }
        }

        write();

    }

    return 0;
}
