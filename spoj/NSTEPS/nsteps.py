def nsteps():
    t = input()
    for p in xrange(t):
        x,y = map(int,raw_input().split())
        if x == y:
            if x&1:
                print x*2 - 1
            else:
                print x*2
        elif x == (y+2):
            if x&1:
                print x*2 - 3
            else:
                print x*2 - 2
        else:
            print 'No Number'
nsteps()
