def py_1():
	n,m,a,b = map(int,raw_input().split())
	if(m*a > b):
		mrides = n/m
		mcost = mrides*b
		leftRides = n%m
		if leftRides*a > leftRides*b:
			total = leftRides*b + mcost
		else:
			total = leftRides*a + mcost
	else:
		total = n*a
	print total
py_1()
