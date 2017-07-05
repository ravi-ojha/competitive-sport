from fractions import gcd
class ThePermutationGameDiv2:
	def lcm(self,a,b):
		return (a*b)/gcd(a,b)
	def findMin(self, N):
		res = long(1)
		for i in xrange(2,N+1):
			res = self.lcm(res,i)
		return res

a = ThePermutationGameDiv2()
for i in xrange(1,36):
	print i, a.findMin(i)
