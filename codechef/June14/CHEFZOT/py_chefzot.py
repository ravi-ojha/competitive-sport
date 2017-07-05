def chefzot():
    n = input()
    a = map(int,raw_input().split())
    res = 0
    cnt = 0
    for i in a:
        if i == 0:
            cnt = 0
        else:
            cnt += 1
            res = max(res,cnt)
    print res
chefzot()
