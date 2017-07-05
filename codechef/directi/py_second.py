def first():
    a = [1,3]
    t = 2*a[1] + a[0]
    i = 2
    while t <= 10**15:
        t = 2*a[i-1] + a[i-2]
        a.append(t)
        i += 1
    print a
    print len(a)
first()
