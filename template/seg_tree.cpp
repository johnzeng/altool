//单点替换、单点增减、区间求和、区间最值
#include <cstdio>
#include <algorithm>
using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 222222;

int MAX[maxn<<2];
int MIN[maxn<<2];
int SUM[maxn<<2];
int max(int a,int b){if(a>b)return a;else return b;}
int min(int a,int b){if(a<b)return a;else return b;}

void PushUP(int rt)
{
  MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
  MIN[rt] = min(MIN[rt<<1] , MIN[rt<<1|1]);
  SUM[rt] = SUM[rt<<1] + SUM[rt<<1|1];
}

void build(int l,int r,int rt) {
  if (l == r)
    {
    scanf("%d",&MAX[rt]);
    MIN[rt] = MAX[rt];
    SUM[rt] = MAX[rt];
    //printf("mi = %d\n",MIN[rt]);
  //    printf("ma = %d\n",MAX[rt]);
    return ;
  }
  int m = (l + r) >> 1;
  build(lson);
  build(rson);
  PushUP(rt);
}

void replace(int p,int tihuan,int l,int r,int rt)
{
  if (l == r) {
    MAX[rt] = tihuan;
    MIN[rt] = tihuan;
    SUM[rt] = tihuan;
    return ;
  }
  int m = (l + r) >> 1;
  if (p <= m) replace(p , tihuan ,lson);
  else replace(p , tihuan , rson);
  PushUP(rt);
}

void add_one(int p,int add,int l,int r,int rt)
{
  if (l == r) {
    SUM[rt] = SUM[rt] + add;
    return ;
  }
  int m = (l + r) >> 1;
  if (p <= m) add_one(p , add ,lson);
  else add_one(p , add , rson);
  PushUP(rt);
}

int query_max(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return MAX[rt];
  }
  int m = (l + r) >> 1;
  int ret = -1;
  if (L <= m) ret = max(ret , query_max(L , R , lson));
  if (R > m)  ret =  max(ret , query_max(L , R , rson));
  return ret;
}

int query_min(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return MIN[rt];
  }
  int m = (l + r) >> 1;
  int ret = 99999;
  if (L <= m) ret = min(ret , query_min(L , R , lson));
  if (R > m)  ret =  min(ret , query_min(L , R , rson));
  return ret;
}

int query_sum(int L,int R,int l,int r,int rt)
{
  if (L <= l && r <= R)
  {
    return SUM[rt];
  }
  int m = (l + r) >> 1;
  int ret = 0;
  if (L <= m) ret += query_sum(L , R , lson);
  if (R > m)  ret +=  query_sum(L , R , rson);
  return ret;
}

int main()
{
  int n , m;
  while (~scanf("%d%d",&n,&m))
  {
    build(1 , n , 1);
    while (m --) {
      char op[2];
      int a , b;
      scanf("%s%d%d",op,&a,&b);
      if (op[0] == 'Q') //区间求最大
      {
         /* for(int i = 1;i<=10;i++)
          printf("%d ",MAX[i]);
        puts("");*/
        printf("%d\n",query_max(a , b , 1 , n , 1));
      }
      else if(op[0]=='U') //单点替换
        replace(a , b , 1 , n , 1);
      else if(op[0]=='M')//区间求最小
      {
        /*for(int i = 1;i<=10;i++)
          printf("%d ",MIN[i]);
        puts("");*/
        printf("%d\n",query_min(a , b , 1 , n , 1));
      }
      else if(op[0]=='H')//区间求和
      {
        printf("%d\n",query_sum(a , b , 1 , n , 1));
      }
      else if(op[0]=='S')//单点增加
      {
        scanf("%d%d",&a,&b);
        add_one(a , b , 1 , n , 1);
      }
       else if(op[0]=='E')//单点减少
      {
        scanf("%d%d",&a,&b);
        add_one(a , -b , 1 , n , 1);
      }
    }
  }
  return 0;
}
