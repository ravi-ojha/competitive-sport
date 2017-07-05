def amicable():
    a = [0,0]
    for i in range(2,10001):
        s = 0
        for j in range(1,i/2+1):
            if i%j == 0:
                s = s + j
        a.append(s)
    print a[10000]
    res = 0
    for i in range(2,10001):
        if a[i] == i:
            print i,a[i]
            continue
        if a[i]<10001 and i == a[a[i]]:
            res += i
    print res
amicable()
