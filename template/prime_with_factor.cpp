#define MX 15000000

int prime[MX+5], factor[MX+5], input[MAXN],s[MX], ptr = 0;

//此方法构造一个链表。factor[i]表示i的最小质因子。
// 反复执行i/factor[i]可以得到所有质因子
//预处理时间为 MX + sum(log(i)) for i in range(MX)
void init_primes_with_factor()
{
    for (int i = 2; i <= MX; ++i) {
        if(factor[i]== 0)
        {
            prime[ptr]=i;
            factor[i]=prime[ptr];
            ptr++;
        }
        for(int j=0; i*prime[j] <= MX;++j)
        {
            factor[i*prime[j]] = prime[j];
            if(i % prime[j] == 0)break;
        }
    }
//    for (int i = 0; i < 100; ++i) {
//        printf("%d ", factor[i]);
//    }
}


