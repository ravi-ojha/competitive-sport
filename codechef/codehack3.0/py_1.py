def solve():
	t = input()
	for i in xrange(t):
		n = map(long, raw_input().split())
		l = n[0]
		a = n[1:]
		res = 0
		for i in xrange(l):
			for j in xrange(i):
				if a[j] > a[i]:
					res += 1
		print res
solve()
