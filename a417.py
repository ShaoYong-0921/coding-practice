from sys import stdin, stdout

def matrix(n):
    ans = [[0 for _ in range (n)] for _ in range (n)]
    x = 0
    y = 0
    step = 1

    while step <= n*n:

        while y < n and ans[x][y] == 0:#右
            ans[x][y] = step
            y += 1
            step += 1
            # print(f'{ans = }1')

        y -= 1; x += 1

        while x < n and ans[x][y] == 0:#下
            ans[x][y] = step
            x += 1
            step += 1
            # print(f'{ans = }2')

        x -= 1; y -= 1

        while y >= 0 and ans[x][y] == 0:#左
            ans[x][y] = step
            y -= 1
            step += 1
            # print(f'{ans = }3')
        
        y += 1; x -= 1

        while x >= 0 and ans[x][y] == 0:#上
            ans[x][y] = step
            x -= 1
            step += 1
            # print(f'{ans = }4')
        
        x += 1; y += 1

    return ans


t = int(stdin.readline())

for _ in range(t):
    output = ''
    n, m = map(int, stdin.readline().split())
    ans = matrix(n)

    if m == 1:
        for x in range(n):
            for y in range(n):
                if y == 0:
                    output += '{}'.format(ans[x][y])
                else:
                    output += '{0:>5d}'.format(ans[x][y])
            output += '\n'
        stdout.write(output)

    elif m == 2:
        for x in range(n):
            for y in range(n):
                if y == 0:
                    output += '{}'.format(ans[y][x])
                else:
                    output += '{0:>5d}'.format(ans[y][x])
            output += '\n'
        stdout.write(output)