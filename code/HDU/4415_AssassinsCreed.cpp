/*
 *
 *  Author  :  fcbruce
 *
 *  Date  :  2014-09-24 16:12:45 
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 100007

using namespace std;

struct _sword
{
  int a,b;
  bool operator < (const _sword &s)const
  {
    return a<s.a;
  }
}sword[maxn];

int no_sword[maxn];
long long used_no_sword[maxn],used_sword[maxn];

int
main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
#endif // FCBRUCE
  
  int T_T,__=0;
  scanf("%d",&T_T);
  
  while (T_T--)
  {
    int n,m;
    
    scanf("%d%d",&n,&m);
    
    int cnt_no_sword=0,cnt_sword=0;
    int final_kill_cnt,final_used,kill_cnt,rest;
    int total_free_kill=0;
    
    for (int i=0,a,b;i<n;i++)
    {
      scanf("%d%d",&a,&b);
      total_free_kill+=b;
      if (!b)
        no_sword[cnt_no_sword++]=a;
      else
        sword[cnt_sword++]=(_sword){a,b};
    }
    
    sort(no_sword,no_sword+cnt_no_sword);
    sort(sword,sword+cnt_sword);
    
    used_no_sword[0]=no_sword[0];
    for (int i=1;i<cnt_no_sword;i++) used_no_sword[i]=used_no_sword[i-1]+no_sword[i];
    
    used_sword[0]=sword[0].a;
    for (int i=1;i<cnt_sword;i++) used_sword[i]=used_sword[i-1]+sword[i].a;
    
    kill_cnt=upper_bound(used_no_sword,used_no_sword+cnt_no_sword,(long long)m)-used_no_sword;
    rest=kill_cnt?m-used_no_sword[kill_cnt-1]:m;
    if (rest>=sword[0].a)
    {
      kill_cnt+=cnt_sword;
      rest-=sword[0].a;
    }
    final_kill_cnt=kill_cnt;
    final_used=m-rest;

    for (int i=0;i<cnt_sword;i++)
    {
      rest=m-used_sword[i];
      if (rest<0) break;
      int rest_free_kill=total_free_kill-cnt_sword+i+1;
      if (cnt_no_sword-rest_free_kill>0)
        kill_cnt=upper_bound(used_no_sword,used_no_sword+cnt_no_sword-rest_free_kill,(long long)rest)-used_no_sword;
      else
        kill_cnt=0;
        
      rest-=kill_cnt?used_no_sword[kill_cnt-1]:0;
      kill_cnt+=cnt_sword;
      kill_cnt+=rest_free_kill;
      kill_cnt=min(kill_cnt,n);
      
      if (kill_cnt>final_kill_cnt)
      {
        final_kill_cnt=kill_cnt;
        final_used=m-rest;
      }
      else if (kill_cnt==final_kill_cnt && m-rest<final_used)
      {
        final_used=m-rest;
      }
    }
    
    printf("Case %d: %d %d\n",++__,final_kill_cnt,final_used);
  }
  
  return 0;
}



