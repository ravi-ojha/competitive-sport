def py_1():
	a = map(int,raw_input().split())
	b = [0]*10
	for i in a:
		b[i] += 1
	unique = 0
	for i in b:
		if i >= 1:
			unique += 1
	if unique == 1:
		print 'Elephant'
	elif unique == 2:
		if 2 in b and 4 in b:
			print 'Elephant'
		elif 1 in b and 5 in b:
			print 'Bear'
		else:
			print 'Bear'
	elif unique == 3:
		if 4 in b and 1 in b:
			print 'Bear'
		else:
			print 'Alien'
	else:
		print 'Alien'
py_1()
