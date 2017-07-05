import sys
def pswrd():
    T,N,H = map(int,raw_input().split())
    z = 'pieguyravi'
    for i in range(T):
        for j in range(N):
            print z
            sys.stdout.flush()
        score = raw_input()
pswrd()
