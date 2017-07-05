MOD = 1000000007
def fast_pow(a,n):
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = (result * value) % MOD
        value = (value * value) % MOD
        power = power/2
    return result

def arrgame2():
    for t in xrange(input()):
        n,m,q,k = map(int,raw_input().split())
        if q > m:
            print '0'
        else:
            tmp = ((fast_pow(q+1,n) + fast_pow(q-1,n) + 2*MOD - 2*fast_pow(q,n))) % MOD
            print ((m-q)*tmp) % MOD
arrgame2()
