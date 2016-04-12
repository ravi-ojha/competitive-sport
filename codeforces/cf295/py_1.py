def solve():
	n = input()
	s = raw_input()
	s = s.lower()
	freq = [0]*256
	for i in s:
		freq[ord(i)] = 1
	c = 0
	for i in xrange(97,123):
		if freq[i]:
			c += 1
	if c == 26:
		print "YES"
	else:
		print "NO"
solve()
