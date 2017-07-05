from fractions import gcd

def lcm(a,b):
	return (a*b)/gcd(a,b)

res = 1
for i in xrange(2,26):
	res = lcm(i,res)
print res
