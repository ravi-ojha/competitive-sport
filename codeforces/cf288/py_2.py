s = raw_input()
k = '08624'
b = s
for i in range(len(s)-1):
	if(s[i] in  k):
		b = s[:i] + s[-1] + s[i+1:-1] + s[i]
		if s[i] < s[-1]:
			break;
if b == s:
	print "-1"
else:
	print b
