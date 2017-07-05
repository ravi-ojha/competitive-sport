def kadane(a):
    n = len(a)
    max_so_far = a[0]
    curr_max = a[0]
    for i in xrange(1,n):
        curr_max = max(a[i],curr_max+a[i])
        max_so_far = max(max_so_far,curr_max)
    return max_so_far

def reign():
    for t in xrange(input()):
        n,k = map(int,raw_input().split())
        a = map(int,raw_input().split())
        if k != 0:
            fsum = [0]*n
            fsum[0] = a[0]
            for i in xrange(1,n):
                fsum[i] = fsum[i-1] + a[i]
    ##        i = n-2
    ##        rsum = [0]*n
    ##        rsum[n-1] = a[n-1]
    ##        while i>=0:
    ##            rsum[i] = rsum[i+1] + a[i]
    ##            i -= 1
            #print fsum
            #print rsum
            min_sum = fsum[k] - fsum[0]
            min_idx_start = 1
            min_idx_end = k
            j = 0
            for i in xrange(k,n-1):
                if min_sum > (fsum[i]-fsum[j]):
                    min_sum = fsum[i]-fsum[j]
                    min_idx_start = j+1
                    min_idx_end = i
                j += 1
            #print min_sum
            #print min_idx_start, min_idx_end

            left = kadane(a[0:min_idx_start])
            right = kadane(a[min_idx_end+1:])
            print left+right
        else:
            dp = []
            for i in xrange(n):
                dp.append([0,0,0])
            dp[0][0] = a[1]
            for i in xrange(1,n-1):
                if dp[i-1][0] < 0:
                    dp[i][1] = dp[i-1][1]
                    dp[i][2] = i
                    dp[i][0] = dp[i-1][0] + a[i]
                else:
                    dp[i][1] = i
                    dp[i][2] = i
                    dp[i][0] = a[i]
            min_idx = 0
            for i in xrange(1,n-1):
                if dp[min_idx][0] > dp[i][0]:
                    min_idx = i
            print dp[min_idx][0]
            print dp[min_idx][1], dp[min_idx][2]
            left = kadane(a[0:dp[min_idx][1]])
            right = kadane(a[dp[min_idx][2]+1:])
            print left+right
reign()
