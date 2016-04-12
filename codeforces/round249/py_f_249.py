def f_249():
    n,m = map(int,raw_input().split())
    a = map(int,raw_input().split())
    cnt = 1
    i = 0
    curr = 0
    while i < n:
        if curr + a[i] <= m:
            curr += a[i]
            i += 1
        else:
            curr = 0
            cnt += 1
    print cnt
f_249()
