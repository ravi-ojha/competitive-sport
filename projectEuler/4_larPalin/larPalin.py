def isPalin(s):
    l = len(s)
    for i in range(l/2):
        if(s[i] != s[l-i-1]):
            return False
    return True
def largePalin():
    i = 999
    a = []
    while i>99:
        j = 999
        while j>99:
            s = i*j
            if isPalin(str(s)):
                a.append(s)         #storing all palindrome answers in a list
            j -= 1
        i -= 1
    #a.sort()  #sorting just to find max of the list
    #l = len(a)
    #print l
    #print a
    print max(a)
largePalin()
