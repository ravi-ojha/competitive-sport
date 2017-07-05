def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)
def amsgame2():
    for t in xrange(input()):
        dp = [0]*10001
        n = input()
        a = map(int,raw_input().split())
        for i in a:
            for j in xrange(1,10001):
                if dp[j] > 0:
                    dp[gcd(i,j)] += dp[j]
            dp[i]+=1
        print dp[1]
amsgame2()
