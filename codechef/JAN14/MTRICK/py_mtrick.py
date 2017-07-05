def fast_power(a,n,mod):
    result = 1
    value = a
    power = n
    while power > 0:
        if power % 2 == 1:
            result = (result * value)%mod
        value = (value * value)%mod
        power = power/2
    return result

def mtrick():
    for t in xrange(input()):
        n = input()
        a = map(int,raw_input().split())
        add,mult,mod = map(int,raw_input().split())
        s = raw_input()
        front = 0
        back = n-1
        i = 0
        res = []
        roy = 0
        alfi = 0
        bob = 0
        flag = 0
        if s[0] == 'R':
            tmp = a[back]
        else:
            tmp = a[front]
        while i<n:
            if s[i] == 'R':
                roy += 1
            if s[i] == 'A':
                alfi += 1
            if s[i] == 'M':
                bob += 1
            if roy%2 == 1:
                tmp = (a[back] + add*alfi)%mod
                #print fast_power(mult,bob,mod)
                tmp = (tmp*fast_power(mult,bob,mod))%mod
                res.append(str(tmp))
                back -= 1
            else:
                tmp = (a[front] + add*alfi)%mod
                #print fast_power(mult,bob,mod)
                tmp = (tmp*fast_power(mult,bob,mod))%mod
                res.append(str(tmp))
                front += 1
            i += 1
            print res
        print ' '.join(res)
mtrick()
