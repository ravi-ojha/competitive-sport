def solve():
    n, k = map(int, raw_input().split())

    x = k + 1
    a = (n/2) / x
    b = k*a
    c = n - b - a
    print a, b, c
solve()
