def maxim():
    for t in xrange(input()):
        n = input()
        i = 2
        res = 0
        if '4' in str(n) or '7' in str(n):
            res += 1
        while i*i <= n:
            if n%i == 0:
                j = n/i
                if '4' in str(i) or '7' in str(i):
                    res += 1
                if j != i:
                    if '4' in str(j) or '7' in str(j):
                        res += 1
            i += 1
        print res
maxim()

