def solve():
    s = raw_input()
    s = list(s)
    slen = len(s)
    # remove all ;
    for i in xrange(slen):
        if s[i] == ';':
            s[i] = ','

    # Adding $ for empty strings
    if s[0] == ',':
        s.insert(0, '$')

    if s[-1] == ',':
        s.append('$')

    s2 = []
    s2.append(s[0])

    # Length might have changed
    slen = len(s)
    for i in xrange(1, slen):
        # Again, adding $ for empty string
        if s[i-1] == ',' and s[i] == ',':
            s2.append('$')
        s2.append(s[i])

    s3 = ''.join(s2)
    s3 = s3.split(',')

    sa = []
    sb = []
    for i in s3:
        if len(i) != 1 and i[0] == '0':
            sb.append(i)
            continue
        try:
            x = int(i)
            sa.append(i)
        except ValueError:
            sb.append(i)

    sblen = len(sb)
    for i in xrange(sblen):
        if sb[i] == '$':
            sb[i] = ''

    if sa:
        # sa.insert(0, "\"")
        # sa.append("\"")
        p = "\""
        q = ','.join(sa)
        print p+q+p
    else:
        print '-'
    if sb:
        # sb.insert(0, "\"")
        # sb.append("\"")
        p = "\""
        q = ','.join(sb)
        print p+q+p
    else:
        print '-'
solve()
