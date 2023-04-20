while True:
    try:
        n = input()
        list_num = list(map(int, input().split()))
        list_num.sort(reverse=True)
        list_ans = []

        for i in range(10):
            for j in list_num:
                if j % 10 == i:
                    list_ans.append(j)
                    #print(list_ans)

        for ans in list_ans:
            print(ans, end=' ')
        print()
    except:
        break