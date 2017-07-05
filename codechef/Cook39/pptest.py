def kp(w,wt,val,n):
    dp = [[0 for x in xrange(w+1)] for x in xrange(n+1)]
    for i in xrange(n+1):
        for j in xrange(w+1):
            if i==0 or j == 0:
                dp[i][j] = 0
            elif wt[i-1] <= j:
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]],  dp[i-1][j])
            else:
                dp[i][j] = dp[i-1][j]
    return dp[n][w]
def pptest():
    for t in xrange(input()):
        a = []
        b = []
        n,w = map(int,raw_input().split())
        for i in xrange(n):
            t = map(int,raw_input().split())
            a.append(t[0]*t[1])
            b.append(t[2])
        print kp(w,b,a,n)
pptest()
