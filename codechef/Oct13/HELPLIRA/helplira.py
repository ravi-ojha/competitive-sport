def helplira():
    n = input()
    a = []
    minIndex = 0
    minValue = 1000000000
    maxIndex = 0
    maxValue = -1
    for i in xrange(n):
        x = map(int,raw_input().split())
        t = x[0]*(x[3] - x[5]) + x[2]*(x[5] - x[1]) + x[4]*(x[1] - x[3])
        if t < 0:
            t = -t
        t = t/2.0
        a.append(t)
    for i in xrange(n):
        if a[i] <= minValue:
            minValue = a[i]
            minIndex = i
    for i in xrange(n):
        if a[i] >= maxValue:
            maxValue = a[i]
            maxIndex = i
    print minIndex+1, maxIndex+1
helplira()
