s_base = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'
# print(base[36])
def change_base(n, base):
    convert = []; change = []
    i = 0; num = 1
    if n == 0:
        return ['0']

    while n >= num:
        num = pow(base, i)
        # print(f'{num = }')
        i += 1
        convert.append(num)
    convert.reverse()
    # print(f'{convert = }')

    for i in convert:
        # print(f'{n // i = }')
        change.append(s_base[n // i])
        n %= i
    # print(f'{change = }')

    return change

# change_base(15, 2)
first = False
t = int(input())

for k in range(t):
    if first:
        print()
    first = True
    print(f'Case {k+1}:')
    
    cost = []

    for _ in range(4):
        num = list(map(int, input().split()))
        for i in num:
            cost.append(i)
    # print(f'{cost = }')

    table = {}

    for i in range(len(cost)):
        table[s_base[i]] = cost[i]
    # print(f'{table = }')

    # data
    case = int(input())
    for _ in range(case):
        base = 2
        sum_list = []
        n = int(input())

        for i in range(2, 37):
            sum_cost = 0
            cost_list = change_base(n, i)
            for j in cost_list:
                sum_cost += table[j] 
            # print(f'num = {n} ;base = {i}. ;{sum_cost = }')
            sum_list.append(sum_cost)
        cheapest = min(sum_list)
        ans = ''
        for i in range(len(sum_list)):
            if sum_list[i] == cheapest:
                ans += f' {i + 2}'
        print(f'Cheapest base(s) for number {n}:{ans}')