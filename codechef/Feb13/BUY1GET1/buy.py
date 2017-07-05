def buy():
    T = input()
    for k in range(T):
        mylist = []
        count = 0
        w = raw_input()
        #print w
        for i in range(len(w)):
            #print w[i]
            if w[i] not in mylist:
                #print w
                count += 1
                mylist.append(w[i])
                #print mylist
            else:
                mylist.remove(w[i])
                #print mylist
        print count
buy()
