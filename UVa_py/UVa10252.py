try:
    while True:
            
        letters = []   
            
        a = input()
        b = input()
        
        list_b = [x for x in b]
        
        for i in b:
            list_b.append(i)
        
        for i in a:
            if i in list_b:
                letters.append(i)
                list_b.pop(list_b.index(i))

                # print(f'{x =}{i =}')

        # print(letters)
        letters = sorted(letters)
        # print(letters)
        for i in letters:
            print(i, end='')
        print()
except EOFError:
    pass