##A Very User Friendly Program ...:P
i=int(input("Test case Number , Aye ?"))
while(i!=0):
    n=int(input("Bitch , Input Decimal , Heh ?"))
    m=n
    while(n>0):
        print(n%2,end='')
        n=n//2
    print('   ',end='')
    while(m>0):
        print(m%3,end='')
        m=m//3
    i=i-1
    print('\n')
    if(i==0):
        print('#')
