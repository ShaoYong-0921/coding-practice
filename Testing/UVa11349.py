label = 1
t = int(input())
for _ in range(t):
    line = str(input().strip())
    n = int(line[-1])

    # print(f'{n = }')

    matrix = []

    for _ in range(n):
        element = list(map(int, input().split() ) )
        matrix.append(element)
    # print(f'{matrix = }')

    flag = True
    for i in range(n):
        for j in range(n):
            # print(f'{i = };  {j = };  {n = }')
            # print(f'{matrix[i][j] = }')
            # print(f'{matrix[n-1-i][n-1-j] = }')
            if matrix[i][j] < 0 or matrix[n-1-i][n-1-j] < 0::
                flag = False
                break

            if matrix[i][j] != matrix[n-1-i][n-1-j]:
                flag = False
                break
        if flag == False:
            break

    if flag:
        print('Test #{}: Symmetric.'.format(label))
    else:
        print('Test #{}: Non-symmetric.'.format(label))

    label += 1