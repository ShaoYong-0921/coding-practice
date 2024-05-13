def solution(x, y):
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    for i in range(4):
        for j in range(2):
            x += dx[i]
            y += dy[i]
            square[x][y] += 1

count = 1
flag = False
while True:
    n, m = map(int, input().split())
    if m == 0 and n == 0:
        break
    if flag:
        print()

    square = [[0 for i in range(m + 2)] for i in range(n + 2)]

    field = []
    for i in range(n):
        field.append([s for s in str(input())])

    location = []
    for i in range(n):
        for j in range(m):
            if field[i][j] == '*':
                # print(f'{i = } {j = }')
                location.append([i, j])

    for i, j in location:
        solution(i, j)
    for i, j in location:
        square[i+1][j+1] = '*'

    print(f'Field #{count}:')
    for i in range(1, n+1):
        for j in range(1, m+1):
            print(square[i][j], end='')
        print()
    count += 1
    flag = True