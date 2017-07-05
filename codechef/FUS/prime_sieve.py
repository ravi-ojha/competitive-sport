N = 2000001
prime = [0]*N
prime[0] = 1
prime[1] = 1
def sieve():
    i = 2
    while i*i <= N:
        j = 2*i
        if prime[i] != 1: 
            while j < N:
                prime[j] = 1
                j += i
        i += 1
