import sys
def decFFS():
    T = input()
    for i in range(T):
        n = input()
        #print n
        a = []
        p = n
        #count = 0
        while p != 0:
            modu = p%3
            if modu == 0:
                a.append(6)
                p = p/3 - 1
                #count += 1
            else:
                a.append(modu+3)
                p = p/3
                #count += 1
        a = a[::-1]
        print "".join(str(v) for v in a)
##        for bla in range(count):
##            #sys.stdout.flush()
##            #sys.stdout.write(a[-1-bla])
##            print (a[-1-bla], end='')
decFFS()
