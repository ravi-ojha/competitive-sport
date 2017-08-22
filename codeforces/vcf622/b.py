def solve():
    a, b = map(int, raw_input().split(':'))
    c = a*60 + b
    d = int(raw_input())
    e = c+d
    e = e%1440
    f = e/60
    g = e%60
    print '%02d:%02d' % (f, g)
solve()
