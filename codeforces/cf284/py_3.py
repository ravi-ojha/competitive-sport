from fractions import gcd
def py_3():
	n,m = map(int,raw_input().split())
	a = map(int,raw_input().split())
	res = 0
	for i in xrange(m):
		x,y = map(int,raw_input().split())
		x -= 1
		y -= 1
		gcd1 = gcd(a[x],a[y])
		lcm = (a[x]*a[y])/gcd1
		res += lcm/gcd1
	print res
py_3()
