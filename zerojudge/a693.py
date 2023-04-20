from sys import stdin, stdout

while True:
    try:
        n, m = map(int, stdin.readline().split())
        foods = list(map(int, stdin.readline().split()))
        arr = [0] + foods

        for i in range(1, n+1):
            arr[i] = arr[i-1] + arr[i]
        # print(f'{arr = }')
        output = ''
        for _ in range(m):
            l, r = map(int, stdin.readline().split())
            ans = arr[r] - arr[l-1] 

            output += str(ans) + '\n'
        stdout.write(output)
    
    except:
        break
