def solve():
    n = int(raw_input())
    a = map(int, raw_input().split())
    b = [0]*(n+1)

    for i in xrange(n):
        b[a[i]] = i+1

    res = 0
    for i in xrange(2, n+1):
        res += abs(b[i] - b[i-1])
    print res
solve()
