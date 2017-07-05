f = [0]*1001
f[0]=1
def calculate():
    for i in range(1,1001):
        f[i] = f[i-1]*i
def ncr(n, r):
    return ((f[n]/f[n-r])/f[r])
def trip():
    calculate()
    t = input()
    for p in range(0,t):
        w = map(int,raw_input().split())
        s = w[0]
        n = w[1]
        m = w[2]
        k =  w[3]
        if k >= n:
            print 0.000000
        elif s == n:
            print 1.000000
        elif s==m:
            print 1.000000
        else:
            final = 0.0
            total = ncr(s-1,n-1)
            tt=m-k
            for i in range(0,tt):
                if(n-1-k-i<0):
                        break
                final+=(ncr(s-m,n-1-k-i)*(ncr(m-1,k+i)))
                #print res
            ans=float(final)/float(total)
            print ans
trip()
