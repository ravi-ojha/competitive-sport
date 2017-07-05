def fact():
    f = [1]
    for i in range(1,40):
        f.append((f[i-1]*i))
    print f[36]
    print f[8]
    print f[10]
    print f[14]
##    print f[100]
##    print f[1000]
##    print f[1000000]
fact()
