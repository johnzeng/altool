def step(x):
    ret = 1;
    while x:
        ret = ret * x
        x = x - 1
    return ret

def c(n,m):
    ret = 1
    x = n
    while x > m:
        ret = ret * x
        x = x - 1
    return ret // step(n - m)

def p(n,m):
    ret = 1
    x = n
    while x > (n - m):
        ret = x * ret
        x = x - 1
    return ret

def my_pow(a,b,mod):
    if b == 1:
        return a
    if b == 0:
        return 1
    halfRet = my_pow(a, b>>1, mod)
    if b % 2 == 1:
        return (((halfRet * a) % mod ) * halfRet) % mod
    else:
        return (halfRet * halfRet) % mod

def checkPrim(a):
    check_list = [2,3,5,7,11]
    for i in check_list:
        if i != a:
            if 1 != my_pow(i, a - 1,a):
                return False
    return True

#if the input is small then (10^11), use this...this is not slow as well it can run out answer for worse case in 124ms
def checkPrim2(a):
    i = 2
    while i * i <= a:
        if a % i == 0:
            return False
        i+=1
    return True

