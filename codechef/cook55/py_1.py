MOD = 1000000007
fact = [1]
def pre_fact():
    for i in xrange(1,301):
        fact.append((i*fact[i-1])%MOD)

def fast_power(a,n):
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = (result * value) % MOD
        value = (value * value) % MOD
        power = power/2
        #print result
    return result

coins = [4,6]

def method2(target):
    tmp = []
    da = target/coins[0]
    for i in xrange(da+1):
        rem = target - (i*coins[0])
        if rem < 0:
            break
        else:
            if rem%coins[1] == 0:
                #print i, rem/coins[1]
                tmp.append([i,rem/coins[1]])
    return tmp

#print breakit(24,coins)

def solve():
    pre_fact()
    t = input()
    for i in xrange(t):
        r,b,l = map(int,raw_input().split())
        if r > 6*b:
            print '0'
        else:
            #denom = breakit(r, coins)
            res = 0
            six = 0
            denom = []
            while six*6 <= r and six <= b:
                other = r - six*6
                if other%4 == 0:
                    four = other/4
                    denom.append([six,four])
                six += 1
            for den in denom:
                #print den
                if (den[0]+den[1]) > b:
                    continue
                else:
                    tmpr = fact[b]
                    left = b - (den[0]+den[1])
                    niche4 = fact[den[0]]
                    niche6 = fact[den[1]]
                    niche4 = fast_power(niche4,MOD-2)
                    niche6 = fast_power(niche6, MOD-2)

                    for wickets in xrange(l+1):
                        tmpr = fact[b]
                        niche0 = left - wickets
                        if niche0 >= 0:
                            nicheW = fast_power(fact[wickets],MOD-2)
                            niche0 = fast_power(fact[niche0], MOD-2)
                            tmpr = tmpr*niche4
                            tmpr %= MOD
                            tmpr = tmpr*niche6
                            tmpr %= MOD
                            tmpr = tmpr*niche0
                            tmpr %= MOD
                            tmpr = tmpr*nicheW
                            tmpr %= MOD
                            res += tmpr
                            res %= MOD
            print res

solve()
