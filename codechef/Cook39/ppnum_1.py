pre  = [0,45,9810,1483650,197982000,24749775000,2969997300000,346499968500000,39599999640000000,4454999995950000000]
def ppnum():
    lll = [0,9,99,999,9999,99999,999999,9999999,99999999,999999999]
    for i in xrange(10):
        pre[i] = pre[i] % 1000000007
    for t in xrange(input()):
        l, r = map(int,raw_input().split())
        res = 0
        ll = len(str(l))
        rr = len(str(r))
        if ll == 10 or ll == rr:
            t1 = (l-1)*l
            t1 = t1/2
            t2 = r*(r+1)
            t2 = t2/2
            tmp = t2 - t1
            tmp = tmp*ll
            tmp = tmp % 1000000007
            res = tmp
            
        else:
            for i in xrange(ll+1,rr):
                res = res + pre[i]
                res = res % 1000000007
            t1 = lll[ll]*(lll[ll] + 1)
            t1 = t1/2
            t2 = (l-1)*l
            t2 = t2/2
            tmp = t1 - t2
            tmp = tmp*ll
            tmp = tmp % 1000000007
            res = res + tmp
            t1 = r*(r+1)
            t1 = t1/2
            t2 = lll[rr-1]*(lll[rr-1] + 1)
            t2 = t2/2
            tmp = t1 - t2
            tmp = tmp*rr
            tmp = tmp % 1000000007
            res = res + tmp
            res = res % 1000000007
        print res
ppnum()
        
