def solve():
    c, v0, v1, a, l = map(int, raw_input().split())
    res = 0
    v2 = v0
    cnt = 0
    while res < c:
        cnt += 1
        res = res + v0
        # If the last page of the book was read then break
        # If we don't break this now and if l is > 0 then res will again become < c and we will count more days
        # But we were supposed to end when the last page was read the first time
        if res >= c:
            break
        res = res - l
        v0 = min(v1, v0+a)
    print cnt
solve()
