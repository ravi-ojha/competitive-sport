from sys import stdin
def gcd(a,b):
    while a:
        a,b = b%a,a
    return b
def guess():
    for t in xrange(input()):
        n,m = map(int,raw_input().split())
        x = ((n+1)/2)*(m/2) + (n/2)*((m+1)/2)
        y = n*m
        din = gcd(x,y)
        print '%d/%d'%(x/din,y/din)
guess()
