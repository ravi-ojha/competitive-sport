def third():
    w = map(int,raw_input().split())
    a = map(int,raw_input().split())
    n = 0
    b = [[0,0,0,0]]
    while n<w[1]:
        tem = map(int,raw_input().split())
        tem.append(0)
        b.append(tem)
        n += 1
    #print b
    n = 0
    while n<w[2]:
        t = map(int,raw_input().split())
        for i in range(t[0],t[1]+1):
            b[i][3] += 1
        n += 1
    #print b
    for i in range(1,w[1]+1):
        for j in range(b[i][0]-1,b[i][1]):
            a[j] += b[i][2]*b[i][3]
    print " ".join(map(str,a))
third()
        
