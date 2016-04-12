def gcd(a,b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a,b):
    return (a*b)/gcd(a, b)
def wall():
    x,y,a,b = map(int,raw_input().split())
    z = lcm(x,y)
    goku = (a-1)/z
    naruto = b/z
    print naruto - goku
wall()
