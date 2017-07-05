def building():
    T = input()
    for p in range(1,T+1):
        n = input()
        s = []
        su = []
        ser = []
        for i in range(n):
            s.append(raw_input())
            su.append(s[i].upper())
        #print s
        #print su
        bcode = list(raw_input())
        #print bcode
        print 'Data Set',p':'
        #for i in range(1, 5):
        #print 'Data Set {0} :'.format(p)
        for sup in su:
            lst = list(sup)
            #print lst
            ser = []
            for i in bcode:
                if i in lst:
                    m = lst.index(i)
                    lst[m] = '0'
                    #print lst
                    ser.append(m)
            if (ser == sorted(ser)) and (len(ser) == len(bcode)):
                b = su.index(sup)
                print s[b]
building()
