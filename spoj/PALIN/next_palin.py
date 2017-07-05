def isPalin(s):
    l = len(s)
    for i in range(l/2):
        if s[i] != s[l-i-1]:
            return False
    return True
def next_palin():
    t = input()
    for p in xrange(t):
        n = input()
        n += 1
        while True:
            if isPalin(str(n)):
                break
            else:
                n += 1
        print n
def opti_next_palin():
    t = input()
    for p in xrange(t):
        res = []
        n = raw_input()
        l = len(n)
        if l == 1:
            if n[0] == '9':
                print '11'
            else:
                n = int(n)
                print n+1
        elif l == 2:
            if n[0] == '9' and n[1] == '9':
                print '101'
            else:
                mid1 = int(n[0])
                mid2 = int(n[1])
                if mid1 > mid2:
                    res.append(str(mid1))
                    res.append(str(mid1))
                    print ''.join(res)
                else:
                    mid1 += 1
                    res.append(str(mid1))
                    res.append(str(mid1))
                    print ''.join(res)
        else:
            if l&1:
                res.append(n[0:l/2])
                mid = int(n[l/2])
                mid += 1
                res.append(str(mid))
                temp = res[0]
                temp = temp[::-1]
                res.append(temp)
                print ''.join(res)
            else:
                #res.append(n[0:l/2-1])
                mid1 = int(n[l/2 - 1])
                mid2 = int(n[l/2])
                i = 1
                while (mid1 == mid2) and i< l/2:
                    mid1 = int(n[l/2 - 1 - i])
                    mid2 = int(n[l/2 + i])
                    i += 1
                #print mid1,mid2
                if mid1 > mid2:
                    #print 'mid1 > mid2'
                    res.append(n[0:l/2])
                    temp = n[0:l/2]
                    temp = temp[::-1]
                    res.append(temp)
                    print ''.join(res)
                else:
                    res.append(n[0:l/2 - 1])
                    mid1 = int(n[l/2-1])
                    mid1 += 1
                    res.append(str(mid1))
                    res.append(str(mid1))
                    temp = n[0:l/2 - 1]
                    temp = temp[::-1]
                    res.append(temp)
                    print ''.join(res)
opti_next_palin()
