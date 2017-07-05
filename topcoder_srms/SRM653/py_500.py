from fractions import gcd
MOD = 1000000007
fact = [1]
class RockPaperScissorsMagicEasy:
	def fast_power(self,a,n,mod):
	    result = 1
	    value = a
	    power = n
	    while power > 0:
	        if power % 2 == 1:
	            result = (result * value) % mod
	        value = (value * value) % mod
	        power = power/2
	        #print result
	    return (result) % mod
	def fact(self):
		i = 1
		while i < 2100:
			fact.append((i*fact[i-1]) % MOD)
			i += 1
		#print fact
	def count(self, card, score):
		self.fact()
		cards = list(card)
		#print cards
		clen = len(cards)
		res = 0
		if score > clen:
			return res
		else:
			res = fact[clen]
			#print fact[clen]
			din1 = self.fast_power(fact[score], MOD-2, MOD)
			din2 = self.fast_power(fact[clen-score], MOD-2, MOD)
			res = (res * din1) % MOD
			res = (res * din2) % MOD


			again = self.fast_power(2, clen-score, MOD)
			res = (res * again) % MOD
			return res


a = RockPaperScissorsMagicEasy()
#print a.count((0,1,2), 2)
print a.count((0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2),7)
print a.count((0,1,2,0,1,2,2,1,0), 8)
print a.count((0,1,2), 0)
print a.count((0,1,2), 1)
print a.count((0,1,2,1), 0)
print a.count((1,),2)
