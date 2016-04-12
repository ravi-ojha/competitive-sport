def py_2():
	n,m = map(int,raw_input().split())
	a = {}
	for i in xrange(m):
		tmp = map(str,raw_input().split())
		a[tmp[0]] = tmp[1]
	s = map(str,raw_input().split())
	slen = len(s)
	for i in xrange(slen):
		tmp = a[s[i]]
		if len(s[i]) > len(tmp):
			s[i] = tmp
	print ' '.join(s)
py_2()
