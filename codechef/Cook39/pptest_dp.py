def pptest():
    for t in xrange(input()):
        a = []
        n,w = map(int,raw_input().split())
        for i in xrange(n):
            t = map(int,raw_input().split())
            a.append(t)
        dp = [102][102]
        res = [102][102]
        for i in xrange(n+1):
            dp[0][i] = 1
            res[0][i] = 0
        for i in xrange(1,w+1):
            dp[i][0] = 0
            res[i][0] = 0
        for i in xrange(1,w+1):
            for j in xrange(1,n+1):
                dp[i][j] = dp[i][j-1]
                res[i][j] = res[
                if (i >= a[j-1][2]):
                    
