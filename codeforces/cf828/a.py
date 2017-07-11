def solve():
    n, a, b = map(int, raw_input().split())
    one = a
    two = b
    thalf = 0
    data = map(int, raw_input().split())

    res = 0
    for i in data:
        if i == 1:
            if one > 0:
                one -= 1
            elif two > 0:
                two -= 1
                thalf += 1
            elif thalf > 0:
                thalf -= 1
            else:
                res += 1
        else:
            if two > 0:
                two -= 1
            else:
                res += 2
    print res
solve()
