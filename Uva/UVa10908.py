direct_x = [1,0,-1,0] # down(1,0), right(0,1), up(-1,0), left(0-1)
direct_y = [0,1,0,-1]

def solution(x, y):
    side = 1
    char = matrix[x][y]
    # print(f'{char = }')

    flag = True
    while flag:
        side += 2
        x -= 1
        y -= 1

        for d in range(4):
            for _ in range(side-1):
                x += direct_x[d] 
                y += direct_y[d]
                # print(f'{x = }  {y = }')
                if ( x < 0 or y < 0 ):
                    return side - 2
                elif ( x >= m or y >= n):
                    return side -2 
                if matrix[x][y] != char:
                    side -= 2
                    flag = False
                    # print('false')
                    return side

        # print('end loop')
    return side
    # print(f'{side = }')

t = int(input())
for _ in range(t):
    m, n, q = map(int, input().split())
    print(f'{m} {n} {q}')

    matrix = [[] for _ in range(m)]

    for i in range(m):
        string = str(input())
        for s in string:
            matrix[i].append(s)

    # print(matrix)

    location = []
    for i in range(q):
        location.append(tuple(map(int, input().split())))
    # print(location)

    for l in location:
        x, y = l
        # print(f'{x = } {y = }')
        sol = solution(x,y)
        print(sol)