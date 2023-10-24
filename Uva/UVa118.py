def f(x, y, d):
    if d == 'N':
        y += 1
    if d == 'S':
        y -= 1
    if d == 'E':
        x += 1
    if d == 'W':
        x -= 1
    return x, y

orientition = ['N', 'E', 'S', 'W']
lost_d = []
dx, dy = map(int, input().split())

while True:
    try:
        x, y, d = map(str, input().split())
        x, y = int(x), int(y)
        string = str(input())
        while orientition[0] != d:
            orientition.insert(0, orientition.pop())
        # print(f'{orientition = }')
        lost = False

        for s in string:
            if s == 'R':
                orientition.insert(3, orientition.pop(0))
            elif s == 'L':
                orientition.insert(0, orientition.pop())
            elif s == 'F':
                before = (x, y)
                x, y = f(x, y, orientition[0])

            if x < 0 or x > dx or y < 0 or y > dy:
                # print(f'{x, y =}')
                x, y = before
                if [x, y] in lost_d:
                    lost = False
                    continue
                lost = True
                lost_d.append([x, y])
                break

        output = f'{x} {y} {orientition[0]}'
        if lost:
            output += ' LOST'
        print(output)

        # print(f'{x, y, orientition[0] = }')
        # print(f'{lost_d = }')
        # print(f'{lost = }')

    except EOFError:
        break