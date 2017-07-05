import sys
def salary():
    T = input()
    for k in range(T):
        N = input()
        W = map(int, sys.stdin.readline().split())
        W.sort()
        print W
        stepCount = 0
        while True:
            if W[0] == W[-1]:
                sys.stdout.write(str(stepCount) + '\n')
                break
            j = N-1;
            while True:
                if W[j] == W[j-1]:
                    j -= 1
                else:
                    break
            for i in range(N):
                if i == j:
                    continue
                W[i]  += 1
            print 'Incre',W
            stepCount += 1
    return;

salary()
