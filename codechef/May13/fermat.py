def fermat():
    ans = 1
    for i in range(220):
        ans = ans*26
        ans = ans%221
    print ans
fermat()
