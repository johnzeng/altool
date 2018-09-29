#include<iostream>
#include<math.h>
using namespace std;
#define MAXN 10000
#define mmin(a, b)  ((num[a]<num[b])?(a):(b))
int num[MAXN] = {1,5,3,2,7,9,3,6,7,0,6,8};
//f1[i][j] the minum num's index in range: start from i, len 2^j
int f1[MAXN][64];

#define DEBUG(S, args...) {printf(S, args);printf("\n");}


void dump(int n){ //测试输出所有的f(i, j)
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; i + (1<<j) - 1 < n; j++){
            DEBUG("f[%d, %d] = %d\t", i, j, f1[i][j]);
        }
    }
    for(i = 0; i < n; i++)DEBUG("%d ", num[i]);
}

void sparse_table(int n){ //sparse table算法
    int i, j, k, m;
    k = (int) (log((double)n + 0.2) / log(2.0)); 
    for(i = 0; i < n; i++) f1[i][0] = i; //递推的初值
    for(j = 1; j <= k; j++){ //自底向上递推
        for(i = 0; i + (1 << j) - 1 < n; i ++){
            m = i + (1 << (j - 1)); //求出中间的那个值
            //f[i][j-1] -> [i, i+2^(j-1))
            //f[m][j-1] -> [i+2^(j-1), i+2^j)
            f1[i][j] = mmin(f1[i][j-1], f1[m][j-1]);
        }
    }
}

void rmq(int i, int j){ //查询[i, j]之间的最值,注意i是从0开始的
    int k = (int)(log(double(j-i+1+0.2)) / log(2.0)), t; //用对2去对数的方法求出k
    t = mmin(f1[i][k], f1[j - (1<<k) + 1][k]);
    DEBUG("rmq(%d, %d) = %d @ pos(%d)", i, j, num[t], t);
}

int main(){
    int i, j;
    sparse_table(12); //初始化
    dump(12); //测试输出所有f(i, j)
    while(scanf("%d%d", &i, &j) != EOF){
        rmq(i, j);
    }
    return 0;
}
