def mymax(a):
    mx = -1
    idx = 0
    for i in xrange(len(a)):
        if a[i] > mx:
            mx = a[i]
            idx = i
    return idx

def lebamhelp():
    a = map(int,raw_input().split())
    while all(a[0] == a[i] for i in xrange(len(a))) != True:
        j = mymax(a)
        for k in xrange(len(a)):
            if k == j:
                a[k] -= 1
            else:
                a[k] += 1
        print a
lebamhelp()
