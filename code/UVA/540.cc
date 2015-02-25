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
#include<list>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10
#define mm 1000000

using namespace std;

int Hash[mm];
char cmd[20];
int last[1001];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("/home/fcbruce/文档/code/t","r",stdin);
  #endif // ONLINE_JUDGE

  int n,m,x,cnt,tt=0,k;

  while (scanf("%d",&n),n)
  {
    printf("Scenario #%d\n",++tt);
    memset(Hash,-1,sizeof(Hash));
    memset(last,-1,sizeof(last));
    cnt=1;

    for (int i=1;i<=n;i++)
    {
      scanf("%d",&m);
      for (int j=0;j<m;j++)
      {
        scanf("%d",&x);
        Hash[x]=i;
      }
    }

    list<int> l,t;
    list<int>::iterator its[1001],it;

    while (true)
    {
      scanf("%s",cmd);
       // puts(cmd);
      if (strcmp(cmd,"STOP")==0) break;

       // puts(cmd);

      if (cmd[0]=='E')
      {
        scanf("%d",&x);
        int k=Hash[x];
        if (last[k]==-1)
        {
          its[k]=l.end();
          its[k]--;
        }

        its[k]++;
        its[k]=l.insert(its[k],x);
        last[k]=x;
        continue;
      }
      else
      {
        x=l.front();
        l.pop_front();
        k=Hash[x];
        printf("%d\n",x);
        if (last[k]==x)
        {
          last[k]=-1;
        }
      }
    }

    puts("");

  }

  return 0;
}
