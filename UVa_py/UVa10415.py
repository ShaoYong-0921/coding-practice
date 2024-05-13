finger = [ [2, 3, 4, 7, 8, 9, 10],
        [2, 3, 4, 7, 8, 9],
        [2, 3, 4, 7, 8],
        [2, 3, 4, 7],
        [2, 3, 4],
        [2, 3],
        [2],
        [3],
        [1, 2, 3, 4, 7, 8, 9],
        [1, 2, 3, 4, 7, 8],
        [1, 2, 3, 4, 7],
        [1, 2, 3, 4],
        [1, 2, 3],
        [1, 2] ]
characters = 'cdefgabCDEFGAB'

t = int(input())
for _ in range(t):
    times = [0 for _ in range(10)]
    string = str(input())
    last = []
    for s in string:
        index = characters.find(s)
        # print(f'{ index = } {finger[index] = }')
        for i in finger[index]:
            if i in last:
                continue
            times[i - 1] += 1

        last = finger[index]
    output = ''
    for i in times:
        output += f'{i} '
    print(output.strip())