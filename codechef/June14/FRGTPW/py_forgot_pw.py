def forgot_pw():
    for t in xrange(input()):
        helper = {}
        n = input()
        for nn in xrange(n):
            tmp = map(str,raw_input().split())
            helper[tmp[0]] = tmp[1]
        #print helper
        s = list(raw_input())
        slen = len(s)
        for i in xrange(slen):
            tmp = helper.get(s[i],None)
            if tmp != None:
                s[i] = tmp
        s = ''.join(s)
        if '.' in s:
            s1,s2 = s.split('.')
            s1 = list(s1)
            s2 = list(s2)
            z = 0
            l1 = len(s1)
            while z < l1 and s1[z] == '0':
                z += 1
            s1 = ''.join(s1[z:])
            l2 = len(s2)
            x = l2-1
            while x >= 0 and s2[x] == '0':
                x -= 1
            s2 = ''.join(s2[:x+1])
            if s1 == '' and s2 == '':
                res = '0'
            elif s1 != '' and s2 == '':
                res = s1
            else:
                res = str(s1) + '.' + str(s2)
            print res
        else:
            slen = len(s)
            s = list(s)
            #print s
            z = 0
            while z < slen and s[z] == '0':
                z += 1
            s = ''.join(s[z:])
            if s == '':
                print '0'
            else:
                print s
forgot_pw()
