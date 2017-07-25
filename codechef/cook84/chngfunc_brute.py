
sq = []

def solve():
    for i in xrange(1, 100):
        sq.append(i*i)
    a, b = map(int, raw_input().split())

    res = 0
    for i in xrange(1, a+1):
        for j in xrange(1, b+1):
            if (i*i + j) in sq:
                res += 1
    print res



solve()


def asdf():
    a = []
    for i in xrange(1, 1000001):
        a.append(i*i)

    b = []
    alen = len(a)
    for i in xrange(1, alen):
        if (a[i] - a[i-1]) > 1000000:
            print a[i]
            break
        b.append(a[i]-a[i-1])

    # print b
    # print max(b)

# asdf()
