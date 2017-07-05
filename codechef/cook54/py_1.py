def py_1():
	t = input()
	for tt in xrange(t):
		n = input()
		a = map(int,raw_input().split())
		a.sort(reverse=True)
		i = 0
		res = 0
		while i < n:
			res += a[i]
			i += 1
			if i < n:
				res += a[i]
			i += 3
		print res
py_1()
