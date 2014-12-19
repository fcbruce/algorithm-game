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

int k,e;
char dict[30][30];
char ex[30][100];
char temp[100];
int v[30];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
	#endif

	int t=0;

	while (~scanf("%d%d",&k,&e))
    {
        //if (t)  puts("");
        memset(dict,0,sizeof(dict));
        memset(ex,0,sizeof(ex));
        memset(v,0,sizeof(v));

        for (int i=0;i<k;i++)
        {
            scanf("%s",dict[i]+1);
            dict[i][0]=' ';
            dict[i][strlen(dict[i])]=' ';
            for (int j=0;dict[i][j]!='\0';j++)
                dict[i][j]=tolower(dict[i][j]);
        }

        getchar();

        int MAX=0;

        for (int i=0;i<e;i++)
        {
            fgets(ex[i],100,stdin);
            memset(temp,0,sizeof(temp));
            for (int j=0;ex[i][j]!='\n' && ex[i][j]!='\0';j++)
                if (isalpha(ex[i][j]))
                    temp[j]=tolower(ex[i][j]) ;
                else
                    temp[j]=' ';


        //    printf("%s\n",temp);
            for (int j=0;j<k;j++)
            {

                if (strstr(temp,dict[j])!=NULL)
                {
                    v[i]++;
                //    printf("%s\n",dict[j]);
                }
            }

            MAX=max(MAX,v[i]);
        }

        printf("Excuse Set #%d\n",++t);

        for (int i=0;i<e;i++)
        {
            if (MAX==v[i])
                printf("%s",ex[i]);
        }

        puts("");




    }



	return 0;
}
