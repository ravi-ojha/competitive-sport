def speed():
    n = map(int,raw_input().split(' '))
    a = n[0]
    y = n[1]
    m = map(int,raw_input().split(' '))
    L = m[0]
    d = m[1]
    w = m[2]
    t = 0.0
    v = min(y,w)
    temp = float(v)/a
    t = t+temp
    dis = (a*(temp**2))/float(2)
    if dis>d:
        v = 2*a*d
        v = math.sqrt(v)
        left = L-d
        temp2 = float(left)/v
        t = t+temp2
    left = d - dis
    temp2 = float(left)/v
    t = t+temp2
    left = L-d
    if v<y:
        temp = (y-v)/float(a)
        t = t+temp
        dtemp = v*temp + (a*(temp**2))/float(2)
        left = L-d-dtemp
    temp2 = left/float(y)
    t = t+temp2
    print '{0:.9f}'.format(t)
speed()
