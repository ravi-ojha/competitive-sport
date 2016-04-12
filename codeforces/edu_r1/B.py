def rotate_str(s1, l, r, k):
    #import ipdb; ipdb.set_trace()
    s2 = s1[l:r+1]
    # copy of s2, because s3 me hum gandagi machane jaa rahe hai
    s3 = s2[:]
    len_s2 = r - l + 1
    for i in xrange(len_s2):
        # s2 ki aisi ki taisi
        s2[(i+k) % len_s2] = s3[i]

    # s1 me s2 jaha se uthaya tha waha pe daal do
    for i in xrange(l, r+1):
        s1[i] = s2[i-l]
    return s1


def magic():
    s = raw_input()
    s1 = list(s)
    q = int(raw_input())
    for _ in xrange(q):
        l, r, k = map(int, raw_input().split())
        l -= 1
        r -= 1
        k = k % (r - l + 1)
        s1 = rotate_str(s1, l, r, k)
        #print s1
    print ''.join(s1)
magic()