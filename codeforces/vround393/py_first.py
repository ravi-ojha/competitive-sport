def first():
    a = {'n':0,'i':0,'e':0,'t':0}
    s = raw_input()
    alist = list(a.keys())
    for i in xrange(len(s)):
        if s[i] in alist:
            a[s[i]] += 1
    a['e'] = a['e']/3
    a['n'] = (a['n']-1)/2
    res = min(a.values())
    if res <= 0:
        print '0'
    else:
        print res
first()
