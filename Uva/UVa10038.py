import sys 
for line in sys.stdin.readlines():
    num = list(map(int, line.split()))
    # print(f'{num = }')
    n = num.pop(0)
    # print(f'{n = }')
    absolute = [abs(num[x+1] - num[x])  for x in range(len(num)-1)]
    # print(f'{absolute = }, {n = }')
    absolute.sort(reverse=True)
    status = True

    for i in range(len(absolute)):
        if absolute[i] == (n - 1 - i):
            pass
        else:
            status = False 
            break

    if status:
        print('Jolly')
    else:
        print('Not jolly')
