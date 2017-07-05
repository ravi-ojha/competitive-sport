import sys
def salary():
    T = input()
    for k in range(T):
        N = input()
        W = map(int, sys.stdin.readline().split())
        W.sort()
        count = N-1
        stepCount = 0
        for i in range(count):
            temp = W[i+1] - W[i]
            #print temp
            stepCount = stepCount + temp*count
            #print count
            count -= 1
        print stepCount
salary()
