label = 1
t = int(input())
for _ in range(t):
    line = list(map(str, input().split()))
    n = int(line[-1])

    # print(f'{line = }')

    matrix = []
    re_matrix = []
    flag = True 
    for _ in range(n):
        num = list(map(int, input().split() ) )

        for n in num:
            if n < 0:
                flag = False
        matrix.append(num)
        re_num = num.copy()
        re_num.reverse()
        # print(f'{re_num = }')
        re_matrix.append(re_num)
    
    re_matrix.reverse()
    
    if re_matrix != matrix:
        flag = False    

    if flag:
        print('Test #{}: Symmetric.'.format(label))
    else:
        print('Test #{}: Non-symmetric.'.format(label))

    label += 1