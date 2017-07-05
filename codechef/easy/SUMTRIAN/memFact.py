def memoizedFactorial(n):
    remember = [0]*101
    remember[0] = 1
    if remember[n] != 0:
        return remember[n]
    else:
        temp = n*memoizedFactorial(n-1)
        remember[n] = temp
        return temp
