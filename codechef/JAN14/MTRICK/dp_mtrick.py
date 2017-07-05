def dp_mtrick():
    for t in xrange(input()):
        n = input()
        a = map(int,raw_input().split())
        add,mult,mod = map(int,raw_input().split())
        s = raw_input()
        temp1 = 1
        temp2 = 0
        mvalue = 1
        i = 0
        roy = 0
        final = []
        front = 0
        back = n-1
        while i<n:
            if s[i] == 'A':
                temp2 = (temp2 + add)%mod
            if s[i] == 'M':
                temp1 = (temp1*mult)%mod
                temp2 = (temp2*mult)%mod
            if s[i] == 'R':
                roy += 1
            if roy%2 == 1:
                res = (temp1*a[back])%mod
                res = (res + temp2)%mod
                final.append(str(res))
                back -= 1
            else:
                res = (temp1*a[front])%mod
                res = (res + temp2)%mod
                final.append(str(res))
                front += 1
            i += 1
        print ' '.join(final)
dp_mtrick()
