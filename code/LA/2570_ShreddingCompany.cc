/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sun 22 May 2016 15:25:20
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
#ifdef _WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

const int INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
const double PI = acos(-1.0);
const double eps = 1e-10;

typedef long long LL;
typedef int itn;

const int maxn = 0;
const int maxm = 0;

int limit, number;
int sum, count, max;
std::stack<int> st, res_st;

void print()
{
  printf("%d", max);
  while (!res_st.empty()) 
  {
    printf(" %d", res_st.top());
    res_st.pop();
  }
  puts("");
}

inline int reverse(std::stack<int> temp)
{
  int result = 0;
  while (!temp.empty())
  {
    result = result * 10 + temp.top() % 10;
    temp.pop();
  }
  return result;
}

void dfs(int number)
{
  if (sum > limit) return;
  if (number == 0)
  {
    if (sum == max)
    {
      count++;
      res_st = st;
    }
    else if (sum > max)
    {
      count = 1;
      max = sum;
      res_st = st;
    }

    return ;
  }

  std::stack<int> temp;

  while (number)
  {
    temp.push(number % 10);
    number /= 10;

    int rev = reverse(temp);

    sum += rev;
    st.push(rev);
    dfs(number);
    st.pop();
    sum -= rev;
  }
}

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t", "r", stdin);
#endif // FCBRUCE

  while (scanf("%d%d", &limit, &number) == 2 && (limit || number))
  {
    count = 0;
    max = -1;
    sum = 0;
    while (!st.empty()) st.pop();
    dfs(number);

    if (count == 0) puts("error");
    if (count > 1) puts("rejected");
    if (count == 1) print();
  }




  return 0;
}
