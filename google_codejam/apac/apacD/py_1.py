def py_1():
	t = input()
	tt = 1
	while tt <= t:
		n = input()
		rdict = {}
		cdict = {}
		for i in xrange(n):
			s = raw_input()
			d = raw_input()
			if s in cdict:
				cdict[s] += 1
			else:
				cdict[s] = 1
			if d in cdict:
				cdict[d] += 1
			else:
				cdict[d] = 1
			rdict[s] = d
		res = []
		for src, cnt in cdict.iteritems():
		    if cnt == 1 and src in rdict:
		        res.append(src)
		curr = res[-1]
		#print curr
		while curr in rdict:
			res.append(rdict[curr])
			curr = res[-1]
		#print res
		rlen = len(res)
		final = []
		i = 0
		while i < (rlen-1):
			final.append(str(res[i]) + '-' + str(res[i+1]))
			i += 1
		#print final
		print 'Case #{0}:'.format(tt), ' '.join(final)
		#print ' '.join(final)
		tt += 1
py_1()
