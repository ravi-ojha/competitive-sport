##def gcd1(a,b):
##    if b == 0:
##        return a
##    else:
##        return gcd(b,a%b)
##def gcd(a,b):
##    while b:      
##        a, b = b, a % b
##    return a
def gcd_test():
    t = 120
    count = 0
    for i in xrange(1,(t+1)):
        if(t%i == 0):
            count += 1
    print count
gcd_test()
