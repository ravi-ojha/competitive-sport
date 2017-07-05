def spiral():
    oddSquare = 0
    OS = []
    evenSquare = 0
    ES = []
    LM = []
    SM = []
    largeMedian = 0
    smallMedian = 0
    j = 0
    k = 0
    for i in range(1,1002):
        if i%2 == 1:
            OS.append(i*i)
            j += 1
        else:
            ES.append(i*i + 1)
            k += 1
    print sum(OS), sum(ES)
    for i in range(j-1):
        LM.append((OS[i+1]+ES[i])/2)
    for i in range(j-1):
        SM.append((OS[i]+ES[i])/2)
    print sum(LM), sum (SM)
    print sum(OS) + sum(ES) + sum(LM) + sum (SM)
spiral()
