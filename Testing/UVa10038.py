import sys 
for line in sys.stdin.readlines():
    num = list(map(int, line.split()))
    # print(f'{num = }')

    absolute = [abs(num[x+1] - num[x])  for x in range(len(num)-1)]
    print(f'{absolute = }')
    absolute.sort()
    
    if len(absolute) == 1:
        status = True


    for i in range(len(absolute)-1):
        # print(f'{absolute[i] = }')
        # print(f'{absolute[i+1] = }')
        if absolute[i] == absolute[i+1] or absolute[i]+1 == absolute[i+1]:
            status = True
            # print('y')
        else:
            # print('n')
            status = False
            break
    if status:
        print('jolly')
    else:
        print('not jolly')
