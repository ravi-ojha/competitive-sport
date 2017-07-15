print 1
s = ''.join(['v' for i in xrange(1000000)])
a = []
a.append(1000000)
for i in xrange(1, 1000001):
    a.append(i)
print s, ' '.join(str(i) for i in a)
