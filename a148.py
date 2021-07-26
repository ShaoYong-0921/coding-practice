while True:
    try:
        line = list(map(int, input().split()))
        n = line[0]
        sum_scores = 0

        for score in line[1:]:
            sum_scores += score

        ans = sum_scores / n

        if ans > 59:
            print('no')
        else:
            print('yes')
    except:
        break
