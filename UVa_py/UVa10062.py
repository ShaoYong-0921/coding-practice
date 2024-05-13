from collections import Counter
from sys import stdin

flag = False
for line in stdin.readlines():
        string = line.strip()
        charcters = {}

        if flag:
            print()

        for c in string:
            if c in charcters:
                charcters[c] += 1
            else:
                charcters[c] = 1

        c = Counter(charcters)
        arr = []

        for k, v in c.most_common():
            # print(f'{ord(k) = } {v = }')
            arr.append([ord(k), v])

        arr = sorted(arr, key=lambda x: (x[1], -x[0]))
        # print(f'{arr = }')
        for k, v in arr:
            print(f'{k} {v}')
        flag = True
