freq = [0]*100001
b = []
myarray = [[0 for x in range(100002)] for x in range(100002)]
def freqCheck(V,J):
    k = 0
    while k<=J:
        if freq[V-b[k]] != 0:
            return False
        k += 1
    return True
def chornot():
    n = input()
    a = map(int,raw_input().split())
    a.sort()
    b.append(a[0])
    j = 0
    for i in xrange(1,n):
        if freqCheck(a[i], j):
            for p in xrange(j+1):
                freq[a[i] - b[p]] += 1
            b.append(a[i])
            j += 1
    print j+1
    print " ".join(str(x) for x in b)
chornot()
