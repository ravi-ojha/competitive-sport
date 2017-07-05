N = 999999
prime = [0]*N
prime[0] = 1
prime[1] = 1
pret = [1]*N

def sieve():
    i = 2
    while i*i <= N:
        j = 2*i
        if prime[i] != 1:
            while j < N:
                prime[j] = 1
                j += i
        i += 1
##    for i in xrange(N):
##        if prime[i] == 0:
##            prime[i] = i
    for t in xrange(input()):
        m,n = map(long,raw_input().split())
        ourRange = []
        for i in xrange(m,n+1):
            ourRange.append(i)
        i = 2
        while i*i <= n:
            fr = m/i
            fr *= i
            j = fr
            while j <= n:
                if j!=i and j >= m:
                    ourRange[j-m] = 0
                j += i
            i += 1
        
        i = 2
        final = 0
        while i < N:
            if prime[i] != 1:
                j = i
                k = 1
                while j < m:
                    j = j*i
                    k += 1
                while j <= n:
                    if prime[k+1] == 0:
                        ourRange[j-m] = j
                        #final += 1
                    else:
                        ourRange[j-m] = 0
                    j = j*i
                    k += 1
            i += 1
        if ourRange[0] == 1:
            ourRange[0] = 0
        for i in xrange(m,n+1):
            if ourRange[i-m]:
                final += 1
        #print prime
        #print pret
        print final
sieve()
