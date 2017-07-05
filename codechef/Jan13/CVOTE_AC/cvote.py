import sys
def threedif():
    T = map(int, sys.stdin.readline().split())
    W = []
    V = []
    p = []
    m = []
    c = []
    n = []
    i = 0
    maxChef = 0
    Chef = 0
    for k in range(T[0]):
        W.append(sys.stdin.readline().split())
    for j in range(T[1]):
        V.append(raw_input())
    V.sort()
    
    while i < len(V):
        Chef = 0
        a = V[i]
        p.append(V[i])
        while i < len(V) and a == V[i]:
            Chef += 1
            i += 1
            #print i
        m.append(Chef)
    #print p
    #print m
    p.sort()
    #maxChef = 
    for j in range(len(p)):
        i =0
        while p[j] != W[i][0]:
            i += 1
        if W[i][1] not in c:
            c.append(W[i][1])
            n.append(m[j])
        else:
            ind = c.index(W[i][1])
            n[ind] = n[ind]+m[j]
        #print c
        #print n
    c.sort()
    n.sort()
    print c[n.index(max(n))]
    print p[m.index(max(m))]
##    if V[0][0] == W[0][0]:
##        print True
threedif()



##T = sys.stdin.readline().split()
##>>> 
##1 3
##['1', '3']
