def win():
    n = input()
    s1 = raw_input()
    s2 = raw_input()
    m = 2*n
    a = []
    f = 0
    s = 0
    for i in range(m):
        a.append([s1[i],s2[i]])
    a.sort(reverse=True)
    for k in range(m):
        if k&1:
            if a[k][0] != '0' and a[k][1] != '0':
                s += 1
        else:
            if a[k][0] != '0' and a[k][1] != '0':
                f += 1
        if a[k][0] != '0' and a[k][1] != '0':
            break;
    if f == s:
        print 'Draw'
    elif f>s:
        print 'First'
    else:
        print 'Second'
    print a
win()
