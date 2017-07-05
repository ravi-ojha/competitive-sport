def tomya():
    for t in xrange(input()):
        n = input()
        m = 1
        while m<= 2048 and m <= n:
            m = m + m
        m = m/2
        print m
        count = 0
        while n > 0:
            count = count + n/m
            n = n%m
            m = m/2
        print count
tomya()
