import numpy
def deter():
    for i in range(2,11):
        v = i*2
        M = []
        for k in range(i*2 - 1):
##            if k %2 == 0:
##                m = [-1]*(v-1)
##            else:
##                m = [0]*(v-1)
            m = [-1]*(v-1)
            if k == 0:
                m[k] = v-2
            elif k%2 == 1:
                m[k] = v-2
                m[k+1] = 0
            else:
                m[k] = v-2
                m[k-1] = 0
            #print m
            print ' '.join(map(str, m))
            M.append(m)
        #print M
        a = abs(numpy.linalg.det(M))
        #a = round(a)
        #a = int(a)
        #a = a%1000000007
        print '%18f' % a
deter()
