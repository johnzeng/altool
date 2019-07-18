#include <iostream>

long long C(long long n,long long m){
    long long ret = 1l;
    for(long long i = 0l; i < m; i ++)
    {
        ret *= (n - i);
    }
    for(long long i = 0l; i < m; i ++)
    {
        ret /= (i + 1);
    }
    return ret;
}
long long my_pow_with_mod(long long a, long long b, long long mod)
{
    if(b == 1)
    {
        return a;
    }
    else if(b == 0)
    {
        return 1;
    }
    long long halRet = my_pow_with_mod(a, b >> 1, mod);
    if(b % 2 == 1)
    {
        return ((halRet * halRet) % mod * a) % mod;
    }
    else
    {
        return (halRet * halRet) % mod;
    }
}
bool checkPrime(long long a)
{
    return 1 == my_pow_with_mod(2, a-1, a);
}

long long my_pow(long long a, long long b)
{
    if(b == 1)
    {
        return a;
    }
    else if(b == 0)
    {
        return 1;
    }
    long long halRet = my_pow(a, b>>1);
    if(b % 2 == 1)
    {
        return halRet * halRet * a;
    }
    else
    {
        return halRet * halRet;
    }
}

int main(int argc, char *argv[])
{
    for(int i = 0 ;i < 10;i ++)
    {
        std::cout << C(10, i) << std::endl;
    }
    return 0;
}
