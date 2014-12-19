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
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

int n,m;
char c;
string matchname;
string temp;
map<string,int>MAP;
struct team
{
    string name;
    int pts,t,win,tie,lose,goal,lost;
    void clear ()
    {
        pts=t=win=tie=lose=goal=lost=0;
    }
}te[33];

bool cmp(const team &x,const team &y)
{
    if (x.pts==y.pts)
    {
        if (x.win==y.win)
        {
            if (x.goal-x.lost==y.goal-y.lost)
            {
                if (x.goal==y.goal)
                {
                    if (x.t==y.t)
                    {
                        string t1,t2;
                        for (int i=0;i<x.name.size();i++)
                                t1+=tolower(x.name[i]);
                        for (int i=0;i<y.name.size();i++)
                                t2+=tolower(y.name[i]);

                        return t1<t2;
                    }
                    return x.t<y.t;
                }
                return x.goal>y.goal;
            }
            return (x.goal-x.lost)>(y.goal-y.lost);
        }
        return x.win>y.win;
    }
    return x.pts>y.pts;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("t","r",stdin);
    #endif

	int tt,cc=0;
	scanf("%d",&tt);getchar();

	while (tt--)
    {
        MAP.clear();

        if (cc) puts("");
        cc++;

        matchname="";
        while (c=getchar(),c!='\n')
            matchname+=c;
        printf("%s\n",matchname.c_str());

        scanf("%d",&n);getchar();
        for (int i=0;i<n;i++)
        {
            temp="";
            while (c=getchar(),c!='\n')
                temp+=c;
            MAP[temp]=i;
            te[i].clear();
            te[i].name=temp;

        }


        scanf("%d",&m);getchar();

        for (int i=0;i<m;i++)
        {

            string t1,t2;
            int p1,p2;
            while (c=getchar(),c!='#')
                t1+=c;
            scanf("%d@%d#",&p1,&p2);
            while (c=getchar(),c!='\n')
                t2+=c;

            te[MAP[t1]].t++;
            te[MAP[t1]].goal+=p1;
            te[MAP[t1]].lost+=p2;
            te[MAP[t2]].t++;
            te[MAP[t2]].goal+=p2;
            te[MAP[t2]].lost+=p1;
            if (p1==p2)
            {
                te[MAP[t1]].pts++;  te[MAP[t1]].tie++;
                te[MAP[t2]].pts++;  te[MAP[t2]].tie++;

            }
            else
            {
                if (p1>p2)
                {
                    te[MAP[t1]].pts+=3;     te[MAP[t1]].win++;
                    te[MAP[t2]].lose++;
                }
                else
                {
                    te[MAP[t2]].pts+=3;     te[MAP[t2]].win++;
                    te[MAP[t1]].lose++;
                }
            }

        }

        sort(te,te+n,cmp);

        for (int i=0;i<n;i++)
        {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i+1,te[i].name.c_str(),te[i].pts,
                   te[i].t,te[i].win,te[i].tie,te[i].lose,te[i].goal-te[i].lost,te[i].goal,te[i].lost);
        }
    }


    return 0;
}
