def is_palin(s):
	slen = len(s)
	i = 0
	half = slen/2;
	while i < half:
		if s[i] != s[slen-i-1]:
			return False
		i += 1
	return True

def solve():
	t = input()
	for i in xrange(t):
		s = raw_input()
		if is_palin(s):
			print ord(s[len(s)/2])
		else:
			print '-1'
solve()
