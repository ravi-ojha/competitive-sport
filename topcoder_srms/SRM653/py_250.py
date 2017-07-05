class CountryGroup:
	def solve(self, a):
		b = list(a)
		n = len(b)
		#print b
		res = 0
		i = 0
		while i < n:
			res += 1
			c = b[i]
			for j in xrange(c-1):
				if (i+1) < n and b[i+1] == c:
					i += 1
				else:
					return -1
			i += 1
			#print res
		return res





a = CountryGroup()
print a.solve((1,2,2,1,3,3,3,3,3,3,3,3,3))
print a.solve((1,))
print a.solve((3,))
print a.solve((3,3,))
print a.solve((3,3,3))
print a.solve((3,3,3,2,2,2,2,2,2,3,3,3,2,2,2,2,2,2,2,2))
