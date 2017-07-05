def py_chefgr():
	for t in xrange(input()):
		n,m = map(int,raw_input().split())
		a = map(int,raw_input().split())
		s = sum(a)
		s += m
		if s%n == 0:
			print 'Yes'
		else:
			print 'No'
py_chefgr()
