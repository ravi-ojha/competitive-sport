import sys
def attack():
    T = input()
    for k in range(T):
        N = map(int, sys.stdin.readline().split())
        D = {}
        for i in range(N[1]):
            W = map(int, sys.stdin.readline().split())
            D[W[0]] = W[1]
        #print dic
        n = N;
        while(n>0):
            if n in W:
                
attack()

