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
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

bool U_,I_,P_;
double U,I,P;
char *pu,*pi,*pp;
char pre;

char s[1111];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int tt,t=0;

	scanf("%d",&tt);getchar();

	while (tt--)
    {
    //    if (t)  puts("");
        t++;
        printf("Problem #%d\n",t);

        U_=I_=P_=false;
        fgets(s,1111,stdin);
        pu=strstr(s,"U=");
        pi=strstr(s,"I=");
        pp=strstr(s,"P=");

        if (pu!=NULL)
        {

            sscanf(pu,"U=%lf%c",&U,&pre);
            U_=true;
            if (pre=='m')   U*=1e-3;
            if (pre=='k')   U*=1000;
            if (pre=='M')   U*=1000000;
        }

        if (pi!=NULL)
        {

            sscanf(pi,"I=%lf%c",&I,&pre);
            I_=true;
            if (pre=='m')   I*=1e-3;
            if (pre=='k')   I*=1000;
            if (pre=='M')   I*=1000000;

        }

        if (pp!=NULL)
        {

            sscanf(pp,"P=%lf%c",&P,&pre);
            P_=true;
            if (pre=='m')   P*=1e-3;
            if (pre=='k')   P*=1000;
            if (pre=='M')   P*=1000000;
        }

        if (U_&&I_)
        {
            P=U*I;
            printf("P=%.2fW\n\n",P);
            continue;
        }

        if (I_&&P_)
        {
            U=P/I;
            printf("U=%.2fV\n\n",U);
            continue;
        }

        if (U_&&P_)
        {
            I=P/U;
            printf("I=%.2fA\n\n",I);
            continue;
        }

    }

	return 0;
}
