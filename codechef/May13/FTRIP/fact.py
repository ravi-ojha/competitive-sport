f = []
def fact(n):
        if n == 0 or n==1:
            return 1
        return n*f[n-1]
for i in range(0,101):
    f.append(fact(i))
    print f
