import itertools
import math

f = [0]*31
f[0] = 1
f[1] = 1
def fact():
    for i in xrange(2,31):
        f[i] = f[i-1]*i
    #print f

def isCollinear(a):
    if (a[0][1] - a[1][1])*(a[0][0] - a[2][0]) == (a[0][1] - a[2][1])*(a[0][0] - a[1][0]):
        return True
    else:
        return False

##def isColl(a):
##    if (a[0][0] * (a[1][1] - a[2][1]) + a[1][0] * (a[2][1] - a[0][1]) + a[2][0] * (a[0][1] - a[1][1])) == 0:
##        return True
##    else:
##        return False
    
def centre(a):
    l = 2*(a[1][0] - a[0][0])
    m = 2*(a[1][1] - a[0][1])
    n = a[0][0]**2 + a[0][1]**2 - a[1][0]**2 - a[1][1]**2
    p = 2*(a[2][0] - a[1][0])
    q = 2*(a[2][1] - a[1][1])
    r = a[1][0]**2 + a[1][1]**2 - a[2][0]**2 - a[2][1]**2
    x = (m*r - q*n)  
    y = (n*p - l*r)
    z = (l*q - m*p)  #this value is dinominator, normally we could have divided 'x' and 'y' by it, but that will destroy precision
    return [x,y,z] #but we are returning dinominator as well

def cirkill():
    fact()
    t = input()
    for p in xrange(t):
        n = input()
        a = []
        kill = 0
        for i in xrange(n):
            a.append(map(int,raw_input().split()))
        #print a
        TR = list(itertools.combinations(a, 3))
        for pos in TR:
            pos =  list(pos)
            if isCollinear(pos):
                continue
            else:
                c = centre(pos) #so c[2] here will be dinominator, c[0] = x and c[1] = y
                rsquare  = (c[2]*pos[0][0] - c[0])**2 + (c[2]*pos[0][1] - c[1])**2 #here c[0]/c[2] hota, but maine c[2] ko cross multiply kr diya
# here rsquare is radius square but because of cross multiplication rsquare is not actual square of radius but it is radiusSquare*(c[2]^2)
                for j in a:
                    if j in pos:
                        continue
                    else:
                        if ((j[0]*c[2] - c[0])**2 + (j[1]*c[2] - c[1])**2) <= (rsquare): # yaha bhi humne wohi kiya jo rsquare me kiya
                            kill += 1
        total = f[n]/f[n-3]
        total = total/f[3]
        total = total*(n-3)
        answer =  kill/float(total)
        print answer
cirkill()
