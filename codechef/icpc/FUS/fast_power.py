def fast_power(a,n):
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = result * value
        value = value * value
        power = power/2
    return result

def traditional_power(a,n):
    result = 1
    while n>0:
        result = result*a
        n -= 1
    return result
