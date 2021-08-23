from sys import stdin, stdout

while True:
    try:
        n, m = map(int, stdin.readline().split())
        foods = []
        arr = [[0 for _ in range(n+1)] for _ in range(n+1)]
        output = ''
        for i in range(n):
            foods.append(list(map(int, stdin.readline().split())))
        

        for i in range(n):
            for j in range(1, n+1):
                arr[i+1][j] = foods[i][j-1] + arr[i+1][j-1]
                
        # print(f'{arr=}')

        for i in range(n):
            for j in range(1,n+1):
                arr[i+1][j] += arr[i][j]

        # print(f'{arr=}')

        for i in range(m):
            x1, y1, x2, y2 = map(int, stdin.readline().split())
            ans = 0
            ans = arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1 - 1][y1 - 1]
            
            # print(f'{ans=}')
            output += f'{ans}\n'

        stdout.write(output)
    except:
        break