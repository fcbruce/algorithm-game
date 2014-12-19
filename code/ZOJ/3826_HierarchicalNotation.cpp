#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

#define maxn 400007

char buff[maxn];

map<string,vector<int> > MAP;

char buf[maxn];

void print(int pos)
{
    int rest=0;
    while ((buff[pos]!=','&& buff[pos]!='}' || rest>0) && buff[pos]!='\0')
    {
        if (buff[pos]=='{')
            rest++;
        if (buff[pos]=='}')
            rest--;

        putchar(buff[pos++]);
    }
    putchar('\n');
}

int ans[1007];

void analyse(const char *s)
{
    int j=0;

    for (int i=0;s[i]!='\0';i++)
    {
        if (s[i]=='{')
        {
            while (j>0 && buf[j-1]!='|') buf[j--]='\0'; // 先往前删到键
            if (j>0 && buf[j-1]=='|') j--;
            buf[j]='\0';
            buf[j++]='.';
            buf[j]='\0';
            continue;
        }

        if (s[i]=='}')  //删掉两层
        {
            while (j>0 &&buf[j-1]!='.') buf[j--]='\0';
            buf[j--]='\0';
            while (j>0 &&buf[j-1]!='.') buf[j--]='\0';
            buf[j]='\0';

            continue;
        }
        if (s[i]==':')
        {
            buf[j]='\0';
            if (MAP.count(string(buf))==1)  //如果是要查询的，把输出位置记录
            {
                for (int k=0;k<MAP[(string)buf].size();k++)
                    ans[MAP[(string)buf][k]]=i+1;
            }
            buf[j++]='|'; //'|'用来分割
            buf[j]='\0';
            continue;
        }
        if (s[i]==',')
        {
            while (buf[j-1]!='.') buf[j--]='\0';  //删掉一层

            continue;
        }
        buf[j++]=s[i];
        buf[j]='\0';
    }
}

char query[maxn];

int main()
{
    query[0]='.';
    int T_T;
    scanf("%d",&T_T);

    while (T_T--)
    {
        MAP.clear();
        scanf("%s",buff);

        int q;
        scanf("%d",&q);

        memset(ans,-1,sizeof ans);

        for (int i=1;i<=q;i++)
        {
            scanf("%s",query+1);
            MAP[string(query)].push_back(i);
        }

        analyse(buff);

        for (int i=1;i<=q;i++)
            if (ans[i]==-1)
                puts("Error!");
            else
                print(ans[i]);
    }

    return 0;

}
