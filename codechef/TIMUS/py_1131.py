def py1131():
    n,k = map(int,raw_input().split())
    res = 1
    c = 0
    while res < k and res < n:
        res *= 2
        c += 1
    if res > n:
        res /= 2
        c -= 1
    t = n-res
    c = c + t/k
    if t%k != 0:
        c += 1
    print c
py1131()
