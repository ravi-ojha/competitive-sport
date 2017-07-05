def cleanup():
    for t in xrange(input()):
        n,m = map(int,raw_input().split())
        a = [0]*(n+1)
        chef = []
        c = 0
        assis = []
        done = map(int,raw_input().split())
        for i in xrange(m):
            a[done[i]] = 1
        for i in xrange(1,n+1):
            if a[i] == 0:
                if c == 0:
                    chef.append(str(i))
                    c = 1
                else:
                    assis.append(str(i))
                    c = 0
        print ' '.join(chef)
        print ' '.join(assis)
cleanup()    
