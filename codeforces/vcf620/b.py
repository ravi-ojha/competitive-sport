def solve():
    d = {
        '0': 6,
        '1': 2,
        '2': 5,
        '3': 5,
        '4': 4,
        '5': 5,
        '6': 6,
        '7': 3,
        '8': 7,
        '9': 6,
    }
    res = 0
    a, b = map(int, raw_input().split())
    for i in xrange(a, b+1):
        x = str(i)
        for j in x:
            res += d[j]
    print res
solve()
