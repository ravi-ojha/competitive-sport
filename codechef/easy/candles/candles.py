import sys
def candle():
    t=int(raw_input())
    for i in xrange(t):
        n=map(int,raw_input().split(' '))
        #n = map(int, sys.stdin.readline().split())
        mini1=min(n[1:])
        mini=min(n)
        j=n[1:].index(mini1)
        if mini<mini1:
            k= '1'+'0'*(mini+1)
        else:
            k= str(j+1)*(mini1+1)
        print k
candle()
