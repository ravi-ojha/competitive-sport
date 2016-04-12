def py_2():
	n = input()
	a = map(int,raw_input().split())
	plan1 = []
	plan2 = []
	plan3 = []
	freq = [0]*2001
	for i in a:
		freq[i] += 1
	twoCount = 0
	greaterCount = 0
	for i in freq:
		if i == 2:
			twoCount += 1
		elif i >= 3:
			greaterCount += 1
	if twoCount >= 2:
		print 'YES'
		i = 0
		while i < 2001:
			if freq[i] == 2:
				x = i
				i += 1
				break
			i += 1
		while i < 2001:
			if freq[i] == 2:
				y = i
				i += 1
				break
			i += 1
		i = 0
		while i < n:
			if a[i] == x:
				p = i
				i += 1
				break
			i += 1
		while i < n:
			if a[i] == x:
				q = i
				i += 1
				break
			i += 1
		i = 0
		while i < n:
			if a[i] == y:
				r = i
				i += 1
				break
			i += 1
		while i < n:
			if a[i] == y:
				s = i
				i += 1
				break
			i += 1
		i = 0
		print p,q
		print r,s
		while i < n:
			if i == p:
				plan1.append(str(p+1))
			elif i == q:
				plan1.append(str(q+1))
			elif i == r:
				plan1.append(str(r+1))
			elif i == s:
				plan1.append(str(s+1))
			else:
				plan1.append(str(i+1))
			i += 1
		i = 0
		while i < n:
			if i == p:
				plan2.append(str(q+1))
			elif i == q:
				plan2.append(str(p+1))
			elif i == r:
				plan2.append(str(r+1))
			elif i == s:
				plan2.append(str(s+1))
			else:
				plan2.append(str(i+1))
			i += 1
		i = 0
		while i < n:
			if i == p:
				plan3.append(str(q+1))
			elif i == q:
				plan3.append(str(p+1))
			elif i == r:
				plan3.append(str(s+1))
			elif i == s:
				plan3.append(str(r+1))
			else:
				plan3.append(str(i+1))
			i += 1
		print ' '.join(plan1)
		print ' '.join(plan2)
		print ' '.join(plan3)
	if greaterCount >= 1:
		print 'YES'

	else:
		print 'NO'
py_2()
