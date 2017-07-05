def py_3():
	t = input()
	for tt in xrange(t):
		n,k = map(int,raw_input().split())
		a = map(int,raw_input().split())
		while True:
			alen = len(a)
			if alen < 3:
				break
			i = 0
			flag = 0
			while alen >= 3 and i <= (alen-3):
				if (a[i+1] - a[i] == k) and (a[i+2] - a[i+1] == k):
					del a[i]
					del a[i]
					del a[i]
					flag = 1
					i += 1
					break
				else:
					i += 1
			#print a
			if i >= (alen-3) and flag == 0:
				break
		print 'Case #{0}:'.format(tt+1),str(len(a))
py_3()
