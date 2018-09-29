def f(N):
    N = [int(ch) for ch in reversed(str(N))]
    cnt, nonzero = 0, 0
    for k in range(len(N)-1, -1, -1):
#do somethin
    return cnt

for run in range(int(input())):
    l, r = map(int, input().split())
    print(f(r+1) - f(l))

