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
#define mm 100007

using namespace std;

int q[mm],cost[mm],dp[mm];
int _f,_r;
int t[2501],r[2501];
int T,S,N,M;
int year,date,hour;
char _month[12][5]={ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
int dates[12]={31,29,31,30,31,30,31,31,30,31,30,31};
char month[5];

inline bool leap(int _y)
{
    return  (_y%400==0 || _y%100!=0 && _y%4==0);
}

inline int cal_hours(int _y,itn _m,int _d,int _h)
{
    int res=0;
    for (int i=2000;i<_y;i++)
    {
        if (leap(i))    res+=366;   else    res+=365;
    }

    if (leap(_y))   dates[1]=29;    else    dates[1]=28;

    for (int i=0;i<_m;i++)  res+=dates[i];

    res+=_d;
    res--;

    res*=24;

    return res+_h;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("/home/fcbruce/文档/code/t","r",stdin);
    #endif // ONLINE_JUDGE

    while (scanf("%d %d",&N,&M),N||M)
    {
        for (int i=0;i<N;i++)
        {
            scanf("%s %d %d %d %d",month,&date,&year,&hour,&r[i]);
            int _m;
            for (int i=0;i<12;i++)
                if (strcmp(month,_month[i])==0) {_m=i;break;}
            t[i]=cal_hours(year,_m,date,hour);

           // printf("%d\n",t[i]);
        }

        scanf("%d %d",&T,&S);
        for (int i=0;i<M;i++)
        {
            scanf("%d",cost+i);
            cost[i]+=S*(M-i);
        }

        _f=0;_r=-1;
        for (int i=0;i<M;i++)
        {
            while (_f<=_r && cost[q[_r]]>cost[i])   _r--;
            q[++_r]=i;

            while (q[_f]<i-T+1) _f++;

            dp[i]=cost[q[_f]]-S*(M-i);
        }

        long long ans=0;
        for (int i=0;i<N;i++)
        {
            ans+=dp[t[i]]*r[i];
        }

        //printf("%lld\n",ans);
        cout<<ans<<endl;

    }


    return 0;
}
