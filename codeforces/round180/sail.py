def sail():
    p = map(int,raw_input().split())
    b = raw_input()
    w = 0
    e = 0
    n = 0
    s = 0
    if p[1] > p[3]:
        w = p[1] - p[3]
    else:
        e = p[3] - p[1]
    if p[2] > p[4]:
        s = p[2] - p[4]
    else:
        n = p[4] - p[2]
    i = 0
    while i<p[0]:
        if s == 0 and w == 0 and e == 0 and n == 0:
            break
        if b[i] == 'S' and s>0:
            s -= 1
        elif b[i] == 'W' and w>0:
            w -= 1
        elif b[i] == 'N' and n>0:
            n -= 1
        elif b[i] == 'E' and e>0:
            e -= 1
        i += 1
    if i==p[0]:
        if s == 0 and w == 0 and e == 0 and n == 0:
            print i
        else:
            print -1
    else:
        print i
sail()
