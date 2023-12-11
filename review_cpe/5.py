while True:
    string = input()
    if string == "0":
        break
    odd = 0; even = 0
    for i in range(len(string)):
        # print(f'{string[i] = }')
        if (i % 2 == 0):
            even += int(string[i])
        else:
            odd += int(string[i])
    # print (f'{odd = } {even = }')
    
    if abs(even - odd ) % 11 == 0:
        print(f'{string} is a multiple of 11.')
    else:
        print(f'{string} is not a multiple of 11.')
        