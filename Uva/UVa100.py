import sys
table = {}
def algorithm(x):
    # output = [x]
    step = 1
    num = x
    if x in table:
        return table[x]

    while True:
        if x == 1: break 
        if x % 2:
            x = 3*x + 1
            # output.append(x)
            step += 1
        else:
            x //= 2
            # output.append(x)
            step += 1
    # print(f'{step =}')
    # print(f'{output =}')
    table[num] = step
    # print(table)
    return step

for line in sys.stdin.readlines():

    # print(line)
    i, j = map(int, line.split())

    max_cycle = 0
    for x in range(min(i, j),max(i, j)+1):
        # print(f'{x = }')
        cycle = algorithm(x)
        if max_cycle < cycle:
           max_cycle = cycle
    # print(num_list)
    print(i , j, max_cycle)
# print(table)