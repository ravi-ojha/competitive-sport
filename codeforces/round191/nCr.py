import math

def nCr(n,r):
    f = math.factorial
    return f(n)/ f(r) / f(n-r)

def main():
    res = 0
    for i in xrange(100):
        res += nCr(99,i)
    print res
main()
