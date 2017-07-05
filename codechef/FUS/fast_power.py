def fast_power(self,a,n,mod):
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = (result * value) % mod
        value = (value * value) % mod
        power = power/2
        #print result
    return (result) % mod

def traditional_power(a,n):
    result = 1
    while n>0:
        result = result*a
        n -= 1
    return result

fast_power(17,22,1000000007)
