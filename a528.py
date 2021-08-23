from sys import stdin, stdout

while True:
    try:
        n = int(stdin.readline().strip())
        output = ''
        ans = []
        for _ in range(n):
            ans.append(int(stdin.readline().strip()))

        ans.sort()
        
        for i in ans:
            output += str(i) + '\n'
        stdout.write(output)
    except:
        break
