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
