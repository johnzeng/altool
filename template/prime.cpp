#define MAX_NUMBER 15000005
#define MAX_PRIME_NUM 20000
int prime[MAX_PRIME_NUM];
int ptr = 0;

void init_primes()
{
    prime[ptr++] = 2;
    for (int i = 3; i *i <= MAX_NUMBER; i += 2) {
        int flag = 1;
        for(int j = 0; j < ptr; ++j)
        {
            if(i % prime[j] == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)prime[ptr++] = i;
    }
}

