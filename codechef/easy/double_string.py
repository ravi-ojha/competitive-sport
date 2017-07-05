def double_string():
    for t in xrange(input()):
        n = input()
        if n&1:
            print n-1
        else:
            print n
double_string()
