n = int(input())
for i in range(n):
    l = int(input())
    x = list(map(int, input().split()))
    step = 0

    for i in range(len(x)):
        for j in range(len(x)-1):      
            if x[j + 1] < x[j]:
                x[j + 1], x[j] = x[j], x[j + 1]
                step += 1

    print(f'Optimal train swapping takes {step} swaps.')