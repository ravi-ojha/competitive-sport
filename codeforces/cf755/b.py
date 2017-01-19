n, m = map(int, raw_input().split())
pb = {}
eb = {}
for i in xrange(n):
    tmp = raw_input()
    pb[tmp] = 1
for i in xrange(m):
    tmp = raw_input()
    eb[tmp] = 1

turn = 'pb'

common_count = 0
for i in pb:
    if eb.get(i) is not None:
        common_count += 1

n = n - common_count
m = m - common_count

if common_count % 2 == 0:
    turn = 'pb'
else:
    turn = 'eb'

if turn == 'pb':
    if n > m:
        print "YES"
    else:
        print "NO"
else:
    if m > n:
        print "NO"
    else:
        print "YES"
