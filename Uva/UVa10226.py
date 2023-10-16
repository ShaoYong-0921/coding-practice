from collections import OrderedDict
from sys import stdin

flag = False
n = int(stdin.readline())
space = stdin.readline()
for i in range(n):
    if flag:
        print()

    species = {}
    count = 0

    while True:
        try:
            tree = str(stdin.readline().strip())
            if tree == '':
                break
        
            if tree in species:
                species[tree] += 1
            else:
                species[tree] = 1
            count += 1
        except EOFError:
            break

    c = OrderedDict(species)
    c = sorted(c, key= lambda x : x)
    # print(c)

    for t in c:
        percentage = (species[t] / count) * 100
        print(f'{t} {percentage:.4f}')
    flag = True