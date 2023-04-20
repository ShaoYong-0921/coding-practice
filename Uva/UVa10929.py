while True:
    num = str(input())

    if num == '0':
        break
    even = 0; odd = 0;
    for i in range(len(num)-1, -1, -1):
        if i % 2 == 0:
            even += int(num[i])
            # print(f'{even=}')
        else:
            odd += int(num[i])
            # print(f'{odd=}')
    if (even - odd) % 11 == 0:
        print('{} is a multiple of 11.'.format(num))
        
    else:
        print('{} is not a multiple of 11.'.format(num))