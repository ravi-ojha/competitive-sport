import sys
def triquery():
    W = []
    N = map(int, sys.stdin.readline().split())
    for i in range(N[0]):
        w = map(int, sys.stdin.readline().split())
        W.append(w)
        #print W
    for j in range(N[1]):
        count = 0
        Z =  map(int, sys.stdin.readline().split())
        maxX = Z[0]+Z[2]
        maxY = Z[1]+Z[2]
        for k in range(N[0]):
            if W[k][0] >= Z[0] and W[k][0] <= maxX:
                if W[k][1] >= Z[1] and W[k][1] <= (Z[1]+maxX-W[k][0]):
                    count +=1
        print count
triquery()
