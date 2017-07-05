def ipow(a,n):
    ans = 1
    power = a
    while n:
        if (n&1):
            ans = ans*power
            #ans = ans%1000000007
        power = power*power
        #power = power%1000000007
        n >>= 1
    return ans

def pal():
    t = input()
    for p in range(t):
        n = input()
        l = (n+1)/2
        ans = 0
        ans = ipow(26,l) - 1
        ans = ans/25
        ans = ans*52
        ans = ans%1000000007
        if(n&1):
            ans = ans - ipow(26,l)
            
##        for i in range(1,l+1):
##            ans = ans + 2*a[i]
##            if n%2==1 and i==l:
##                ans = ans - a[i]
##            ans = ans%1000000007
        print ans
pal()
