class ValueOfString:
	def findValue(self, s):
		slen = len(s)
		t = list(s)
		map1 = {}
		for i in xrange(26):
			map1[chr(i+ord('a'))] = i+1
		res = 0
		for i in xrange(slen):
			mult = 0
			for j in t:
				if j <= s[i]:
					mult += 1
			res += mult*map1[s[i]]
		return res

a = ValueOfString()
print a.findValue('y')
