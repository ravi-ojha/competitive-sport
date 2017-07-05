##def powerset(s):
##  return [[s[j] for j in range(len(s)) if (i&(1<<j))] for i in range(1<<len(s))]

def powerSet(elts):
    if len(elts) == 0:
        return [[]]
    else:
        smaller = powerSet(elts[1:])
        elt = [elts[0]]
        withElt = []
        for s in smaller:
            withElt.append(s+elt)
        allofthem = smaller + withElt
        return allofthem

def GCD(a,b):
    a = abs(a)
    b = abs(b)
    while a:
        a, b = b%a, a
    return b
    
def GCD_List(list):
    return reduce(GCD, list)

def q1():
    t = input()
    for k in range(t):
        n = input()
        w = map(int,raw_input().split())
        p = powerSet(w)
        #print p
        upto = 2**n
        c = 0
        for i in range(upto):
            if len(p[i]) < 2:
                continue
            #print p[i]
            if GCD_List(p[i]) == 1:
                c += 1
        print c
        #print GCD_List(w)
#q1()
