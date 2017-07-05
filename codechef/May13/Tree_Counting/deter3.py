import numpy
def deter():
    for i in range(2,11):
        v = i*3
        M = []
        for k in range(v):
            if k == 0:
                continue
            m = [-1]*(v)
            m[k] = v-3
            if k%3 == 0:
                m[k+1] = 0
                m[k+2] = 0
            elif k%3 == 1:
                m[k-1] = 0
                m[k+1] = 0
            elif k%3 == 2:
                m[k-2] = 0
                m[k-1] = 0
            #print m
            print ' '.join(map(str, m[1:]))
            M.append(m[1:])
        #print M
        a = abs(numpy.linalg.det(M))
        #a = round(a)
        #a = int(a)
        #a = a%1000000007
        print '%18f' % a
deter()
