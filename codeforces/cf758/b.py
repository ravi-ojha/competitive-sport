s = raw_input()
s = list(s)
slen = len(s)
a = s[:4]

if a[0] == '!':
    i = 0
    i += 4
    while i < slen:
        if s[i] != '!':
            a[0] = s[i]
        i += 4

if a[1] == '!':
    i = 1
    i += 4
    while i < slen:
        if s[i] != '!':
            a[1] = s[i]
        i += 4

if a[2] == '!':
    i = 2
    i += 4
    while i < slen:
        if s[i] != '!':
            a[2] = s[i]
        i += 4

if a[3] == '!':
    i = 3
    i += 4
    while i < slen:
        if s[i] != '!':
            a[3] = s[i]
        i += 4

if '!' in a:
    idx = a.index('!')
    if 'R' not in a:
        a[idx] = 'R'
    if 'G' not in a:
        a[idx] = 'G'
    if 'Y' not in a:
        a[idx] = 'Y'
    if 'B' not in a:
        a[idx] = 'B'


result = {
    'R': 0,
    'G': 0,
    'Y': 0,
    'B': 0,
}

for i in xrange(slen):
    if s[i] == '!':
        result[a[i%4]] += 1

print result['R'], result['B'], result['Y'], result['G']
