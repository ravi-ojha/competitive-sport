def GCD(a,b):
    while a:
        a, b = b%a, a
    return b
        
        
def GCD_Reduce(list):
    return reduce(GCD, list)

def q1():
    t = input()
    for p in range(t):
        n = input()
        w = map(int,raw_input().split())
        print GCD_Reduce(w)
q1()
