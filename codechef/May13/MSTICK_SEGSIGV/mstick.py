def mstick():
    n = input()
    a = map(int,raw_input().split())
    q = input()
    if n&1:
        for p in range(q):
            w = map(int,raw_input().split())
            print "%.1f" % a[0]
    else:
        for p in range(q):
            w = map(int,raw_input().split())
            if w[0] == 0 and w[1] != (n-1):
                res = min(a[w[0]:w[1]+1])
                preRes = max(a[w[1]+1:n])
                preAns = max(a[w[0]:w[1]+1]) - res
                preAns = float(preAns)/2
                res = res + max([preRes,preAns])
                print "%.1f" % res
            elif w[0] != 0 and w[1] == (n-1):
                res = min(a[w[0]:w[1]+1])
                preRes = max(a[0:w[0]])
                preAns = max(a[w[0]:w[1]+1]) - res
                preAns = float(preAns)/2
                res = res + max([preRes,preAns])
                print "%.1f" % res
            elif w[0] == 0 and w[1] == (n-1):
                res = min(a[w[0]:w[1]+1])
                preAns = max(a[w[0]:w[1]+1]) - res
                #print preAns
                preAns = float(preAns)/2
                #print preAns
                res = res + preAns
                print "%.1f" % res
            else:
                #print min(a[w[0]:w[1]+1])
                res = min(a[w[0]:w[1]+1])
                print res
                #print a[0:w[0]]
                #print a[w[1]+1:n]
                preRes = max([max(a[0:w[0]]), max(a[w[1]+1:n])])
                print preRes
                preAns = max(a[w[0]:w[1]+1]) - res
                print preAns
                preAns = float(preAns)/2
                print preAns
                res = res + max([preRes,preAns])
                print "%.1f" % res
mstick()
