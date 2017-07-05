def crossprod (list1, list2):
    output = 0
    for i in range(0,len(list1)):
        output += list1[i]*list2[i]

    return output

def breakit(target, coins):
    coinslimit = [(target / coins[i]) for i in range(0,len(coins))]
    count = 0
    temp = []
    for i in range(0,len(coins)):
        temp.append([j for j in range(0,coinslimit[i]+1)])

    r=[[]]
    for x in temp:
        t = []
        for y in x:
            for i in r:
                t.append(i+[y])
        r = t

    ans = []
    for targets in r:
        if crossprod(targets, coins) == target:
            ans.append(targets)

    return len(ans)

coins = [4,6]
for i in xrange(1,1801):
    print breakit(i,coins)
