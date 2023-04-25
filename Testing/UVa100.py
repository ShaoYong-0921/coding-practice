def algorithm(x):
    output = [x]
    
    while True:
        
        if x == 1: break 
        if x % 2:
            x = 3*x + 1
        else:
            x //= 2
            output.append(x)
    # print(f'{output =}')
    return output

try:
        
    while True:    
        i, j = map(int, input().split())
        # print(f'{i =}\n{j =}')
        i_list = algorithm(i)
        j_list = algorithm(j)        
        print(f'{i_list =}\n{j_list =}')
        # print(len(i_list), len(j_list))
        x = 0
        for i in range(len(j_list), 1, -1):
            x += i
            print(f'{i = }\n{x = }')


except EOFError:
    pass