def get_max_power(n):
    ans = 0
    i = 0
    while ans < n:
        ans += 2**i
        i += 1
    return ans

def magic():
    t = int(raw_input())
    for _ in xrange(t):
        n = int(raw_input())
        res = (n*(n+1))/2
        res = res - 2*(get_max_power(n))
        print res
magic()