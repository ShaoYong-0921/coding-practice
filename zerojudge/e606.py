while True:
    try:    
        n = int(input())
        # x = list( map(int, input().split()))
        x = []
        for i in range(n):
            num = int(input())
            x.append(num)
        
        minimum = 0
        for i in x:
            minimum += i

        listA = []
        for a in range(max(x), -1, -1):
            count = 0
            for i in range(len(x)):
                count += abs(x[i] - a)
            listA.append(count)

            if count <= minimum:
                minimum = count

        listA.reverse()

        # print(f'{listA = } {min_a = }')
        ans2 = 0 
        ans3 = 0

        for i in x:
            if listA[i] == minimum:
                ans2 += 1

        for i in range(len(listA)):
            if listA[i] == minimum:
                ans3 += 1
        # print(f'{possible_a = }')

        print(min_a, ans2, ans3)
        # print(listA)

    except EOFError:
        break
    