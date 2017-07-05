def fib(n):
    if n==1 or n==2:
        return 1
    else:
        return (fib(n-1) + fib(n-2))

def iter_fib():
    a = []
    a.append(1)
    a.append(1)
    t = a[0] + a[1]
    i = 2
    while len(str(t)) != 1000:
        a.append(t)
        t = a[i] + a[i-1]
        i += 1
        #print a
    print i
    return i
iter_fib()
