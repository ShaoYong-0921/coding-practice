import sys

for line in sys.stdin.readlines():
    s, d = map(int, line.split())
        
    while True:
        # print(f'{s = }  {d = }')
        d -= s

        if d <= 0:
            print(s)
            break
        s += 1

