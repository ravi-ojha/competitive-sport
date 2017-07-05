def names():
    a = []
    b = []
    res = 0
    for i in range(5163):
        a.append(raw_input())
    a.sort()
    for i in range(5163):
        worth = 0
        for j in range(len(a[i])):
            worth += (ord(a[i][j])-64)
        b.append(worth)
    for i in range(5163):
        res = res + b[i]*(i+1)
    print res
names()
