def sumof(s):
    ans = 0
    for i in range(len(s)):
        ans = ans + int(s[i])
    return ans
def fctrl():
    t = input()
    for i in range(t):
        n = input()
        ans = 1
        while n != 1:
            ans = ans*n
            n -= 1
        print ans
        #summ = sumof(str(ans))
        #print summ
fctrl()
