from sys import stdin

def createTree(node, b, e, SumTree, MaxIndexTree, A):
    if b == e:
        SumTree[node] = A[b]
        MaxIndexTree[node] = b
    else:
        createTree(2*node, b, (b+e)/2, SumTree, MaxIndexTree, A)
        createTree(2*node + 1, (b+e)/2 + 1, e, SumTree, MaxIndexTree, A)
        SumTree[node] = SumTree[2*node] + SumTree[2*node + 1]
        if A[MaxIndexTree[2*node]] >= A[MaxIndexTree[2*node + 1]]:
            MaxIndexTree[node] = MaxIndexTree[2*node]
        else:
            MaxIndexTree[node] = MaxIndexTree[2*node + 1]

def update(node, b, e, SumTree, MaxIndexTree, idx, val, A):
    if b>e or b>idx or e < idx:
        return
    if b == e:
        SumTree[node] = val
        return
    update(2*node, b, (b+e)/2, SumTree, MaxIndexTree, idx, val, A)
    update(2*node + 1, (b+e)/2 + 1, e, SumTree, MaxIndexTree, idx, val, A)
    SumTree[node] = SumTree[2*node] + SumTree[2*node + 1]
    if A[MaxIndexTree[2*node]] >= A[MaxIndexTree[2*node + 1]]:
        MaxIndexTree[node] = MaxIndexTree[2*node]
    else:
        MaxIndexTree[node] = MaxIndexTree[2*node + 1]

def findRangeSum(node, b, e, SumTree, goku, naruto):
    if goku <= b and naruto >= e:
        return SumTree[node]
    if b > naruto or e < goku:
        return 0
    return findRangeSum(2*node, b, (b+e)/2, SumTree, goku, naruto) + findRangeSum(2*node + 1, (b+e)/2 + 1, e, SumTree, goku, naruto)

def findRangeMaxIndex(node, b, e, MaxIndexTree, goku, naruto, A):
    if goku <= b and naruto >= e:
        return MaxIndexTree[node]
    if b > naruto or e < goku:
        return -1
    q = findRangeMaxIndex(2*node, b, (b+e)/2, MaxIndexTree, goku, naruto, A)
    w = findRangeMaxIndex(2*node + 1, (b+e)/2 + 1, e, MaxIndexTree, goku, naruto, A)
    if A[q] >= A[w]:
        return q
    else:
        return w
    #return findRangeMaxIndex(2*node, b, (b+e)/2, MaxTree, goku, naruto, A) + findRangeSum(2*node + 1, (b+e)/2 + 1, e, MaxTree, goku, naruto, A)

def seabal():
    d = 0
    data = stdin.readlines()
    n,m = map(int,data[d].split())
    d += 1
    a = map(int,data[d].split())
    a.append(-1)
    d += 1
    #print n,m,a
    sumTree = [0]*263143
    maxIndexTree = [0]*263143
    createTree(1,0,n-1,sumTree,maxIndexTree,a)
    clones = [[] for x in xrange(n)]
    l = []
    r = []
    pairs = []
    for i in xrange(m):
        t = map(int,data[d].split())
        d += 1
        l.append(t[0])
        r.append(t[1])
        clones[findRangeMaxIndex(1, 0, n-1, maxIndexTree, l[i]-1, r[i]-1, a)].append(i)
        pairs.append(findRangeSum(1,0,n-1,sumTree,l[i]-1,r[i]-1))
    print clones
    change = 0
    count = 0
    k = int(data[d])
    d += 1
    while k!=0:
        count = 0
        x = int(data[d])
        d += 1
        y = x + change
        for i in xrange(m):
            if y >= l[i] and y <= r[i]:
                pairs[i] -= 1
            if pairs[i] == 0:
                count += 1
        change = count
        print count
        k -= 1
seabal()
