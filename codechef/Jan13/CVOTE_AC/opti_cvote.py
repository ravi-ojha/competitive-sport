import sys
def threedif():
    T = map(int, sys.stdin.readline().split())
    W = []
    V = []
    cV = []
    i =0
    nV = []
    chefList = []
    nationList = []
    nationRank = []
    maxR = 0
    for k in range(T[0]):
        W.append(sys.stdin.readline().split())
        cV.append(0)
    while i < T[0]:
        nationList.append(W[i][1])
        nV.append(0)
        i += 1
    nationList.sort()
    for j in range(T[1]):
        V.append(raw_input())
    W.sort()
    for i in V:
        #iterations = 0
        low = 0
        high = T[0]-1
        ans = (high + low)/2
        #iterations += 1 
        while W[ans][0] != i:
            if  W[ans][0] < i:
                low = ans + 1
            else:
                high = ans
            ans = (high + low)/2
            #iterations += 1
        cV[ans] += 1
        nV[nationList.index(W[ans][1])] += 1
    
    print nationList[nV.index(max(nV))]
    print W[cV.index(max(cV))][0]

threedif()
    #V.sort()
##    W.sort()
##    for i in range(len(W)):
##        cnt = V.count(W[i][0])
##        chefList.append(cnt)
##        if W[i][1] in nationList:
##            nationRank[nationList.index(W[i][1])][1] += cnt
##        else:
##            nationList.append(W[i][1])
##            nationRank.append([W[i][1],cnt])
##            
##    nationRank.sort()
##    for i in range(len(nationRank)):
##        if nationRank[i][1] > maxR:
##            maxR = nationRank[i][1]
##            leadNation = nationRank[i][0]
##    print leadNation
##    print W[chefList.index(max(chefList))][0]

















#

















    
##    while i < len(V):
##        Chef = 0
##        a = V[i]
##        p.append(V[i])
##        while i < len(V) and a == V[i]:
##            Chef += 1
##            i += 1
##            #print i
##        m.append(Chef)
##    #print p
##    #print m
##    p.sort()
##    #maxChef = 
##    for j in range(len(p)):
##        i =0
##        while p[j] != W[i][0]:
##            i += 1
##        if W[i][1] not in c:
##            c.append(W[i][1])
##            n.append(m[j])
##        else:
##            ind = c.index(W[i][1])
##            n[ind] = n[ind]+m[j]
##        #print c
##        #print n
##    c.sort()
##    n.sort()
##    print c[n.index(max(n))]
##    print p[m.index(max(m))]
##    if V[0][0] == W[0][0]:
##        print True




##T = sys.stdin.readline().split()
##>>> 
##1 3
##['1', '3']
