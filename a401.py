from sys import stdin
output = ''


a1, b1, c1, a2, b2, c2 = map(int, stdin.readline().strip().split())

d = (a1 * b2) - (a2 *b1)
dx = (c1 * b2) - (c2 * b1)
dy = (a1 * c2) - (a2 * c1)

if d:
    x = dx / d
    y = dy / d
    print('x={:.2f}\ny={:.2f}'.format(x,y))

elif d == dx == dy == 0:
    print('Too many')

else:
    print('No answer')

