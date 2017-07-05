def fact(n):
	res = 1
	for i in xrange(1,n+1):
		res = res*i
	return res

def sum_of_n_fact(n):
	res = 0
	for i in xrange(1,n+1):
		res = res + i*fact(i)
	print res, fact(n+1)-1

sum_of_n_fact(7)
