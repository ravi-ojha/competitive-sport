def solve():
    x1, y1 = map(int, raw_input().split())
    x2, y2 = map(int, raw_input().split())

    res = max(abs(x2-x1), abs(y2-y1))
    print res
solve()
