def sumof(s):
    ans = 0
    for i in range(len(s)):
        ans = ans + int(s[i])
    return ans
def sumofdig():
    for i in range(1,1001):
        ans = 2**i
        sumOfDigits = sumof(str(ans))
    print i,  ans,  sumOfDigits
sumofdig()


agarwalsunit2903@gmail.com
