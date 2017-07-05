def firesc():
    T = input()
    for i in range(T):
        n = map(int,raw_input().split(' '))
        parent = []
        count = []
        a = []
        ans = 0
        ways = 1
        for i in range(n[0]+1):
            parent.append(i)
            count.append(1)
        #print parent
        #print count
        for i in range(n[1]):
            m = map(int,raw_input().split(' '))
            if (parent[m[0]] == m[0] and parent[m[1]] == m[1]):
                if count[m[0]] == 1 and count [m[1]] == 1:
                    a.append([m[0],m[1]])
                    parent[m[1]] = m[0]
                    count[m[0]] += 1
                elif count[m[0]] != 1 and count[m[1]] == 1:
                    j = 0
                    while a[j][0] != m[0]:
                        j += 1
                    a[j].append(m[1])
                    parent[m[1]] = m[0]
                    count[m[0]] += 1
                elif count[m[0]] == 1 and count[m[1]] != 1:
                    j = 0
                    while a[j][0] != m[1]:
                        j += 1
                    a[j].append(m[0])
                    parent[m[0]] = m[1]
                    count[m[1]] += 1
                else:
                    j = 0
                    while a[j][0] != parent[m[1]]:
                        j +=1
                    k = 0
                    while a[k][0] != parent[m[0]]:
                        k += 1
                    count[parent[m[1]]] = 1
                    for l in range(len(a[j])):
                        a[k].append(a[j][l])
                        parent[a[j][l]] = parent[m[0]]
                        count[m[0]] += 1
                    del a[j]
            elif (parent[m[0]] == m[0] and parent[m[1]] != m[1]):
                if count[m[0]] == 1:
                    j = 0
                    while a[j][0] != parent[m[1]]:
                        j +=1
                    a[j].append(m[0])
                    parent[m[0]] = parent[m[1]]
                    count[parent[m[1]]] += 1
                elif parent[m[1]] != m[0]:
                    j = 0
                    while a[j][0] != parent[m[1]]:
                        j +=1
                    k = 0
                    while a[k][0] != parent[m[0]]:
                        k += 1
                    count[parent[m[1]]] = 1
                    for l in range(len(a[j])):
                        a[k].append(a[j][l])
                        parent[a[j][l]] = parent[m[0]]
                        count[m[0]] += 1
                    del a[j]
            elif (parent[m[0]] != m[0] and parent[m[1]] == m[1]):
                if count[m[1]] == 1:
                    j = 0
                    while a[j][0] != parent[m[0]]:
                        j +=1
                    a[j].append(m[1])
                    parent[m[1]] = parent[m[0]]
                    count[parent[m[0]]] += 1
                elif parent[m[0]] != m[1]:
                    j = 0
                    while a[j][0] != parent[m[0]]:
                        j +=1
                    k = 0
                    while a[k][0] != parent[m[1]]:
                        k += 1
                    count[parent[m[0]]] = 1
                    for l in range(len(a[j])):
                        a[k].append(a[j][l])
                        parent[a[j][l]] = parent[m[1]]
                        count[m[1]] += 1
                    del a[j]
            elif (parent[m[0]] != m[0] and parent[m[1]] != m[1]):
                if parent[m[0]] != parent[m[1]]:
                    j = 0
                    while a[j][0] != parent[m[0]]:
                        j +=1
                    k = 0
                    while a[k][0] != parent[m[1]]:
                        k += 1
                    count[parent[m[0]]] = 1
                    for l in range(len(a[j])):
                        a[k].append(a[j][l])
                        parent[a[j][l]] = parent[m[1]]
                        count[m[1]] += 1
                    del a[j]
        for i in range(1,n[0]+1):
            if parent[i] == i:
                ans += 1
            ways = ways*count[i]
            #ways = ways%1000000007
        #print parent
        #print count
        print ans,ways%1000000007
firesc()

