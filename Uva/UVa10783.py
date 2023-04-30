label = 1

try:
    n = int(input())
    for i in range(n):
        a = int(input())
        b = int(input())

        if a % 2:
            pass
        else:
            a += 1
        total = 0
        
        while a <= b:
            # print(f'{a = }')
            total += a
            a += 2
            
        print('Case {}: {}'.format(label, total))
        label += 1
except EOFError:
    pass