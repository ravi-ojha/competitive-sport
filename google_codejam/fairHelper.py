def isPalin(s):
    l = len(s)
    for i in range(l/2):
        if(s[i] != s[l-i-1]):
            return False
    return True
def fairHelper():
    a = []
    i = 1
    j = 10**7 + 1
    print j
    while i < j:
        if isPalin(str(i)) and isPalin(str(i**2)):
            a.append([i,i**2])
        i += 1
        le = len(str(i))
        if i > (3*(10**(le-1))):
            #print 'check'
            i = 10**(le)
    print a
    for i in range(len(a)):
        print a[i]
    print len(a)
fairHelper()
