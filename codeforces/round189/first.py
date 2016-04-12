def first():
    s = raw_input()
    l = len(s)
    flag = 0
    fourCount = 0
    otherCount = 0
    if l == 1 or l== 2:
        if s[0] != '1':
            print 'NO'
        else:
            print 'YES'
    else:
        for i in range(l):
            if s[i] != '4':
                fourCount = 0
            if s[i] != '4' and s[i] != '1':
                flag = 1
                break
            if s[i] == '4':
                fourCount += 1
            if fourCount > 2:
                flag = 1
                break
        if flag == 1:
            print 'NO'
        else:
            if s[0] != '1':
                print 'NO'
            else:
                print 'YES'
first()
