def pointPos(a,b,c):
    return ((b[0] - a[0])*(c[1] - a[1]) - (b[1] - a[1])*(c[0] - a[0])) > 0
def findArea(a,b,c):
    area = a[0]*(b[1] - c[1]) + b[0]*(c[1] - a[1]) + c[0]*(a[1] - b[1])
    area = area/2.0
    if area < 0:
        area = (-1)*area
    return area
def second():
    n = input()
    a = []
    for t in xrange(n):
        u = map(float,raw_input().split())
        a.append(u)
    a.sort()
    A = a[0]
    B = a[-1]
    del a[0]
    del a[-1]
    area1 = []
    area2 = []
    area3 = []
    print A,B
    for t in xrange(n-2):
        if pointPos(A,B,a[t]):
            area1.append(findArea(A,B,a[t]))
            area3.append(findArea(A,B,a[t]))
        else:
            area2.append(findArea(A,B,a[t]))
            area3.append(findArea(A,B,a[t]))
    if area1 == [] or area2 == []:
        print 'bla'
        area3.sort()
        result = area3[-1] - area3[0]
    else:
        result = max(area1) + max(area2)
    print result
second()
