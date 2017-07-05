def numfact():
    t = input()
    for p in xrange(t):
        n = input()
        ans = 0
        a = map(int,raw_input().split())
        res = a[0]
        for i in xrange(1,n):
            res = res*a[i]
        for i in xrange(1,res/2 + 1):
            if res%i == 0:
                #print i
                ans += 1
        print ans+1
numfact()
