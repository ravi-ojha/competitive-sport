def addrev():
    t = input()
    for p in xrange(t):
        one,two = map(str,raw_input().split())
        one = one[::-1]
        two = two[::-1]
        one = int(one)
        two = int(two)
        res = one+two
        res = str(res)
        res = res[::-1]
        res = int(res)
        print res
addrev()
