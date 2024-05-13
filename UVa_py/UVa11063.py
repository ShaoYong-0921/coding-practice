label = 1
first = False

while True:
    try:
        if first:
            spece = input()
        first = True
        
        n = int(input())
        listB = list(map(int, input().split()))
        
        # print(f'{listB  = }')
        diffence = [] 
        status = True
        for i in range(n-1):
            if listB[i] < 1:
                status = False
            if listB[i] >= listB[i+1]:
                status = False
                
        for i in range(n):
            for j in range(i, n):
                # print(f'{i = }; {j = }')
                
                sums = listB[i] + listB[j]
                if sums in diffence:
                    status = False
                else:
                    diffence.append(listB[i] + listB[j])
            
            if status == False:
                break
            
        # print(f'{diffence = }')
        
        if status:
            print('Case #{}: It is a B2-Sequence.'.format(label))

        else:
            print('Case #{}: It is not a B2-Sequence.'.format(label))
            
        print()
        label += 1

    except EOFError:
        break

