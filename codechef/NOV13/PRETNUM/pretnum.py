N = 1000001
prime = [0]*N
prime[0] = 1
prime[1] = 1
def sieve():
    i = 2
    while i*i <= N:
        j = 2*i
        if prime[i] != 1: 
            while j < N:
                prime[j] = 1
                j += i
        i += 1
def pretnum():
    sieve()
    for t in xrange(input()):
        res = 0
        l,r = map(int,raw_input().split())
        for z in xrange(l,r+1):
            div = 0
            i = 1
            while i*i <= z:
                if z%i == 0:
                    j = z/i
                    div += 2
                    if j == i:
                        div -= 1
                i += 1
            #print div
            if prime[div] == 0:
                res += 1
                #print 'Yes'
            #else:
                #print 'No'
        print res
pretnum()
