s_base = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
# print(base[36])
def change_base(n, base):
    convert = []; change = []
    i = 0; num = 1
    
    while n > num:
        num = pow(base, i)
        print(f'{num = }')
        i += 1
        convert.append(num)
    convert.reverse()
    print(f'{convert = }')

    for i in convert:
        print(f'{n // i = }')
        change.append(s_base[n // i])
        n %= i
    print(f'{change = }')

    return change

change_base(15, 2)

'''
t = int(input())

for _ in range(t):
    
    cost = []

    for _ in range(4):
        num = list(map(int, input().split()))
        for i in num:
            cost.append(i)

    table = {}

    for i in range(len(cost)+1):
        table[s_base[i]] = cost[i]

    print(f'{table = }')

    case = int(input())

    base = 2
    for _ in range(case):
        n = int(input())
'''