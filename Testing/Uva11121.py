n = int(input())

for case in range(n):
    num = int(input())
    if num == 0:
        print(f'Case #{case}: 0')
        continue

    max_base = 0
    max_value = 1
    while (True):
        if (num >= max_value and num < 0):
            break
        elif (num <= max_value and num > 0):
            break
        max_value *= -2
        max_base += 1
    print(f'{max_value = } {max_base = } {num = }')

    now = max_value
    output = '1'
    print(f'{now = }')
    for i in range(max_base - 1, -1 , -1):
        base = (-2) ** i
        print(f'{i = } {base = }')
        if now == num:
            output += '0'
            continue

        if now + base >= num and base < 0:
            output += '1'
            now += base
        elif now + base <= num and base > 0:
            output += '1'
            now += base
        else:
            output += '0'

    
        print(f'{now = } ')
    print(f'{output = }')