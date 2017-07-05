def pyth_rocks():
    for t in xrange(input()):
        n = input()
        a = map(int,raw_input().split())
        print (n*(n-1))/2
pyth_rocks()
