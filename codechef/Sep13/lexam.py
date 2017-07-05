def lexam():
    for t in xrange(input()):
        n = input()
        a = []
        used = [16]*0
        res = 1
        for i in xrange(n):
            z = map(int,raw_input().split())
            a.append(z)
        if n > 16:
            print 0.0
        else:
            upto = 1<<n
            for i in xrange(upto):
                j = i
                for k in xrange(n):
                    if ((j>>k)&1 == 0):
                        used
            
