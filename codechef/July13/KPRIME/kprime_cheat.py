import urllib2  # the lib that handles the url stuff
data = ['0']
file = urllib2.urlopen("http://oeis.org/A001221/b001221.txt") # it's a file like object and works just like a file
for line in file: # files are iterable
    if line == '\n':
        continue
    else:
        data.append(line[-2])
#print data[100000]
##txt = urllib2.urlopen("http://oeis.org/A001221/b001221.txt").read()
##txt.split()
##for i in xrange(30):
##    print txt[i]

t = input()
for p in xrange(t):
    res = 0
    a,b,k = map(int,raw_input().split())
    for i in xrange(a,b+1):
        if int(data[i]) == k:
            res += 1
    print res
