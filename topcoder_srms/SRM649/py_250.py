class DecipherabilityEasy:
    def check(self, s, t):
    	slen = len(s)
    	tlen = len(t)
    	sl = list(s)
    	tl = list(t)
    	for i in xrange(slen):
    		del sl[i]
    		if sl == tl:
    			return "Possible"
    		sl = list(s)
    	return "Impossible"
