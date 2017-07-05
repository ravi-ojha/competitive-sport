MOD = 1000000007
f = [1]
def fact():
    i = 1
    while i < 210:
        t = (f[i-1]*i)%MOD
        f.append(t)
        i += 1

def lemov():
    fact()
    #print f[:10]
    for t in xrange(input()):
        n,k = map(int,raw_input().split())
        arr = map(int,raw_input().split())
        freq = [0]*210
        a = []
        for i in xrange(n):
            tmp = arr[i]
            if freq[tmp] == 0:
                a.append(tmp)
            freq[tmp] += 1
        a.sort()
        i = len(a) - 1
        res = 0
        while k >= 0 and i >= 0:
            res = res + (freq[a[i]]*f[n-1])%MOD
            res = res % MOD
            i -= 1
            k -= 1
        print res
lemov()
