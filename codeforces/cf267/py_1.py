def first():
	a,m = map(int,raw_input().split())
	a = a%m
	if a == 0:
		print 'Yes'
	else:
		while a < m:
			a = a + (a%m)
		if a == m:
			print 'Yes'
		else:
			print 'No'
first()
