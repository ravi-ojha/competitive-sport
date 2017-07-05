import sys
def threedif():
    T = input()
    for k in range(T):
        W = map(int, sys.stdin.readline().split())
        W.sort()
        res = W[0]*(W[1] - 1)*(W[2] - 2)
        res = res%(10**9 + 7)
        print res
threedif()
