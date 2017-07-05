mymap = {'A':0, 'B':1, 'C':2, 'D':3, 'E':4, 'F':5, 'G':6, 'H':7}
def py_2():
	t = input()
	tt = 1
	while tt <= t:
		n = input()
		chess = []
		for i in xrange(70):
			tmp = [0]*70
			chess.append(tmp)
		for i in xrange(n):
			s = raw_input()
			chess[mymap[s[0]]+1][int(s[1])] = s[-1]
		res = 0
		for i in xrange(70):
			for j in xrange(70):
				if chess[i][j] == 'K':
					if chess[i+1][j] != 0:
						res += 1
					if chess[i-1][j] != 0:
						res += 1
					if chess[i][j-1] != 0:
						res += 1
					if chess[i][j+1] != 0:
						res += 1
					if chess[i-1][j-1] != 0:
						res += 1
					if chess[i-1][j+1] != 0:
						res += 1
					if chess[i+1][j-1] != 0:
						res += 1
					if chess[i+1][j+1] != 0:
						res += 1
				elif chess[i][j] == 'P':
					if chess[i+1][j-1] != 0:
						res += 1
					if chess[i+1][j+1] != 0:
						res += 1
				elif chess[i][j] == 'R':
					x = i+1
					while x < 70 and chess[x][j] == 0:
						x += 1
					if x < 70:
						res += 1
					x = j+1
					while x < 70 and chess[i][x] == 0:
						x += 1
					if x < 70:
						res += 1
					x = i-1
					while x > 0 and chess[x][j] == 0:
						x -= 1
					if x > 0:
						res += 1
					x = j-1
					while x > 0 and chess[i][x] == 0:
						x -= 1
					if x > 0:
						res += 1
				elif chess[i][j] == 'B':
					x = i+1
					y = j+1
					while x < 70 and y < 70 and chess[x][y] == 0:
						x += 1
						y += 1
					if x < 70 and y < 70 and chess[x][y] != 0:
						res += 1
					x = i+1
					y = j-1
					while x < 70 and y > 0 and chess[x][y] == 0:
						x += 1
						y -= 1
					if x < 70 and y > 0 and chess[x][y] != 0:
						res += 1
					x = i-1
					y = j+1
					while x > 0 and y < 70 and chess[x][y] == 0:
						x -= 1
						y += 1
					if x > 0 and y < 70 and chess[x][y] != 0:
						res += 1
					x = i-1
					y = j-1
					while x > 0 and y > 0 and chess[x][y] == 0:
						x -= 1
						y -= 1
					if x > 0 and y > 0 and chess[x][y] != 0:
						res += 1
				elif chess[i][j] == 'Q':
					x = i+1
					while x < 70 and chess[x][j] == 0:
						x += 1
					if x < 70:
						res += 1
					x = j+1
					while x < 70 and chess[i][x] == 0:
						x += 1
					if x < 70:
						res += 1
					x = i-1
					while x > 0 and chess[x][j] == 0:
						x -= 1
					if x > 0:
						res += 1
					x = j-1
					while x > 0 and chess[i][x] == 0:
						x -= 1
					if x > 0:
						res += 1
					x = i+1
					y = j+1
					while x < 70 and y < 70 and chess[x][y] == 0:
						x += 1
						y += 1
					if x < 70 and y < 70 and chess[x][y] != 0:
						res += 1
					x = i+1
					y = j-1
					while x < 70 and y > 0 and chess[x][y] == 0:
						x += 1
						y -= 1
					if x < 70 and y > 0 and chess[x][y] != 0:
						res += 1
					x = i-1
					y = j+1
					while x > 0 and y < 70 and chess[x][y] == 0:
						x -= 1
						y += 1
					if x > 0 and y < 70 and chess[x][y] != 0:
						res += 1
					x = i-1
					y = j-1
					while x > 0 and y > 0 and chess[x][y] == 0:
						x -= 1
						y -= 1
					if x > 0 and y > 0 and chess[x][y] != 0:
						res += 1
				elif chess[i][j] == 'N':
					if i+2 < 70 and j+1 < 70 and chess[i+2][j+1] != 0:
						res += 1
					if i+2 < 70 and j-1 > 0 and chess[i+2][j-1] != 0:
						res += 1
					if i-2 > 0 and j+1 < 70 and chess[i-2][j+1] != 0:
						res += 1
					if i-2 < 70 and j-1 > 0 and chess[i-2][j-1] != 0:
						res += 1
					if i+1 < 70 and j+2 < 70 and chess[i+1][j+2] != 0:
						res += 1
					if i-1 < 70 and j+2 > 0 and chess[i-1][j+2] != 0:
						res += 1
					if i+1 > 0 and j-2 < 70 and chess[i+1][j-2] != 0:
						res += 1
					if i-1 < 70 and j-2 > 0 and chess[i-1][j-2] != 0:
						res += 1
		print 'Case #{0}:'.format(tt), str(res)
		tt += 1
py_2()
