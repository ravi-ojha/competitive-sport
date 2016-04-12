def py_1():
	a,b,s = map(int,raw_input().split())
	d = abs(a) + abs(b)
	if s == d:
		print "Yes"
	elif s < d:
		print "No"
	elif s > d:
		if d%2 == 0:
			if s%2 == 0:
				print "Yes"
			else:
				print "No"
		else:
			if s%2 == 1:
				print "Yes"
			else:
				print "No"
py_1()
