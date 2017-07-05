import math
def almprm():
    t = input()
    for i in range(t):
        n = input()
        p = math.sqrt(n)
        m = int(p)
        count = 0
        print p
        #print m
        if n == 1:
            print 'NO'
        elif m == p:
            count = 1
            i = 2
            while i<m:
                if n%i == 0:
                    count += 1
                    break
                i += 1
            if count == 1:
                print 'YES'
            else:
                print 'NO'
        else:
            print 'NO'
almprm()
