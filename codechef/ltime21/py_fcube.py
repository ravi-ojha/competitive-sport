MOD = 1000000007
def isSquare(n):
	root = round(n**(1/2.0))
	if n == root*root:
		return True
	return False

def isCube(n):
	croot = round(n**(1/3.0))
	if n == croot*croot*croot:
		return True
	return False

def solve():
	t = input()
	for i in xrange(t):
		m = input()
		n = input()
		if isSquare(n):
			print (n*int(n**(1/2.0)))%MOD
		elif isCube(n):
			print (n)%MOD
		else:
			print (n**3)%MOD

# for i in xrange(1,1200):
# 	if isSquare(i):
# 		print i
#solve()

def bf():
	t = input()
	for i in xrange(t):
		m = input()
		n = input()
		ncopy = n
		i = 1
		while True:
			if isCube(ncopy):
				print (ncopy)%MOD
				break
			i += 1
			ncopy = i*n
bf()
