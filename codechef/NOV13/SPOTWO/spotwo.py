def fast_pow(a,n):
    result = 1
    power = n
    value = a
    while power > 0:
        if power&1:
            result = result*value
            result %= 1000000007
        value *= value
        value %= 1000000007
        power >>= 1
    return result
def spotwo():
    for t in xrange(input()):
        n = input()
        b = bin(n)
        z = str(b)
        z = b[2:]
        #print z
        z = int(z)
        #print b,z
        res = fast_pow(2,z)
        z *= 2
        res = res*res
        res %= 1000000007
        print res
        #z %= 1000000007
        #print fast_pow(2,z)
spotwo()
