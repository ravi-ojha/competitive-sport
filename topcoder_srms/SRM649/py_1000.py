class XorSequenceEasy:
	def count(self, aa):
		alen = len(aa)
		res = 0
		for i in xrange(alen):
			for j in xrange(i+1,alen):
				if aa[i] < aa[j]:
					res += 1
		return res
	def getmax(self, A, N):
		z = []
		for i in xrange(31):
			z.append(2**i)
			z.append(2**i - 1)
		a = list(A)
		zlen = len(z)
		aa = a[:]
		alen = len(a)
		res = 0
		for i in xrange(zlen):
			b = z[i]
			for j in xrange(alen):
				aa[j] = b^a[j]
			res = max(res,self.count(aa))

			aa = a[:]
		return res

a = XorSequenceEasy()
a.getmax((408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667), 1073741824)
