#define MAXN 15000000

int prime[MAXN+5], factor[MAXN+5], ptr = 0;

//此方法构造一个链表。factor[i]表示i的最小质因子。
// 反复执行i/factor[i]可以得到所有质因子
//预处理时间为 MAXN + sum(log(i)) for i in range(MAXN)
void init_primes_with_factor()
{
    for (int i = 2; i <= MAXN; ++i) {
        if(factor[i]== 0)
        {
            prime[ptr]=i;
            factor[i]=prime[ptr];
            ptr++;
        }
        for(int j=0; i*prime[j] <= MAXN;++j)
        {
            factor[i*prime[j]] = prime[j];
            if(i % prime[j] == 0)break;
        }
    }
//    for (int i = 0; i < 100; ++i) {
//        printf("%d ", factor[i]);
//    }
}


