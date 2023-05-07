label = 1
first = False

while True:
    try:
        # if first:
        #     spece = input()
        first = True
        n = int(input())
        listB = list(map(int, input().split()))

        diffence = [] 
        bool = True
        for i in range(len(listB)):
            if n <= 1:
                bool = False
                break
            for j in range(i, len(listB)):
                # print(f'{listB[i] =}  ; {listB[j] =}')
                
                if (listB[i]+listB[j]) in diffence:
                    bool = False
                    # diffence.append(listB[i]+listB[j])
                    break
                diffence.append(listB[i]+listB[j])
            if bool == False:
                break
        # print(diffence)

        if bool:
            print('Case #{}: It is a B2-Sequence.'.format(label))
            print()
        else:
            print('Case #{}: It is not a B2-Sequence.'.format(label))
            print()
        label += 1

    except EOFError:
        break

