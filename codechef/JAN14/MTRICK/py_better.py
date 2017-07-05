def fast_power(a,n,mod):
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = (result * value)%mod
        value = (value * value)%mod
        power = power/2
    return result%mod

def helper(s,a):
    z = s[0]
    i = 0
    c = 0
    n = len(s)
    while i < n:
        c = 0
        while i < n and s[i] == z:
            c += 1
            i += 1
        a.append([z,c])
        if i >= n:
            break
        z = s[i]

def mtrick():
    for t in xrange(input()):
        n = input()
        a = map(int,raw_input().split())
        add,mult,mod = map(int,raw_input().split())
        s = raw_input()
        freq = []
        helper(s,freq)
        #print freq
        res = []
        front = 0
        back = n-1
        i = 0
        R = 0
        while i<n:
            if s[i] == 'R':
                R += 1
            if R%2 == 1:
                tmp = a[back]%mod
                z = 0
                for j in freq:
                    z += j[1]
                    if z > i:
                        z -= j[1]
                        y = i-z+1
                        if j[0] == 'A':
                            tmp = (tmp + ((y%mod)*(add%mod))%mod)%mod
                        if j[0] == 'M':
                            tmp = (tmp*fast_power(mult,y,mod))%mod
                        break
                    if j[0] == 'A':
                        tmp = (tmp + ((j[1]%mod)*(add%mod))%mod)%mod
                    if j[0] == 'M':
                        tmp = (tmp*fast_power(mult,j[1],mod))%mod
                res.append(str(tmp))
                back -= 1
            else:
                tmp = a[front]%mod
                z = 0
                for j in freq:
                    z += j[1]
                    if z > i:
                        z -= j[1]
                        y = i-z+1
                        if j[0] == 'A':
                            tmp = (tmp + ((y%mod)*(add%mod))%mod)%mod
                        if j[0] == 'M':
                            tmp = (tmp*fast_power(mult,y,mod))%mod
                        break
                    if j[0] == 'A':
                        tmp = (tmp + ((j[1]%mod)*(add%mod))%mod)%mod
                    if j[0] == 'M':
                        tmp = (tmp*fast_power(mult,j[1],mod))%mod
                res.append(str(tmp))
                front += 1
            i += 1
            #print res
        print ' '.join(res)
mtrick()


                    
