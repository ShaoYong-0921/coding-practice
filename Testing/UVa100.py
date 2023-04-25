def algorithm(x):
    output = []
    
    while True:
        print(f'{output =}')
        if x == 1: break 
        if x % 2:
            x = 3*x + 1
        else:
            x //= 2
            output.append(x)
        return output

i, j = map(int, input().split())
print(f'{i =}{j =}')
i_list = algorithm(i)
j_list = algorithm(j)
print(f'{i_list =}{j_list =}')