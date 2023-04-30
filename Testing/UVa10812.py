try:
    n = int(input())
    for i in range(n):
        s, d = map(int, input().split())
        a = (s+d)/2
        b = s - a
        if a % 2:
            print(' !impossible')
            
        # print(f'{a = }{b = }')
        elif b < 0:
            print(' < impossible')
        
        else:
            print(int(a), int(b))
except EOFError:
    pass