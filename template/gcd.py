def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

def egcd(a,b):
    if b==0:
        return 1,0
    else:
        x,y=egcd(b,a%b)
        return y,x-a/b*y
