

"""
All palindromes in 24 hours:

00:00 -- 0
01:10 -- 70
02:20 -- 140
03:30 -- 210
04:40 -- 280
05:50 -- 350
06:60 -- 420 this is not a palindrome
07:70 -- neither is this
08:80 -- nope
09:90 -- nah
10:01 -- 601
11:11 -- 671
12:21 -- 741
13:31 -- 811
14:41 -- 881
15:51 -- 951
16:61 -- nope
17:71 -- nope
18:81 -- nope
19:91 -- nope
20:02 -- 1202
21:12 -- 1272
22:22 -- 1342
23:32 -- 1412
"""
def solve():
    # Yo
    a = [0, 70, 140, 210, 280, 350, 601, 671, 741, 811, 881, 951, 1202, 1272, 1342, 1412, 1440]
    h,m = map(int,raw_input().split(':'))
    mins = h*60 + m
    sleep_mins = 10000000000

    for i in a:
        if i >= mins:
            sleep_mins = min(sleep_mins, (i-mins))
    print sleep_mins

solve()
