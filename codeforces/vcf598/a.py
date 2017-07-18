def get_two_to_the_power_less_than_n(n):
    i = 0
    res = 0
    to_power = 2**i
    while to_power <= n:
        i += 1
        res = res + to_power
        to_power = 2**i
    #print res
    return res

def solve():
    t = int(raw_input())
    for _ in xrange(t):
        n = int(raw_input())
        ans = (n*(n+1))/2
        to_sub = get_two_to_the_power_less_than_n(n)
        ans = ans - 2*to_sub
        print ans
solve()
