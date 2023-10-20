while True:
    direction = []
    dice_ew = [3, 1, 4]
    dice_ns = [2, 1, 5]
    
    n = int(input())

    if n == 0:
        break

    for _ in range(n):
        direction.append(str(input()))
    top = 1
    for d in direction:
        # print(f'{dice_ew = }')
        change = 7 - top

        if d == 'north':
            dice_ns.pop(0)
            dice_ns.append(change)
            top = dice_ns[1]

        elif d == 'south':
            dice_ns.pop(2)
            dice_ns.insert(0, change)
            top = dice_ns[1]

        elif d == 'east':
            dice_ew.pop(2)
            dice_ew.insert(0, change)
            top = dice_ew[1]

        elif d == 'west':
            dice_ew.pop(0)
            dice_ew.append(change)
            top = dice_ew[1]
        
        dice_ew[1] = dice_ns[1] = top


        # print(dice_ns)
        # print(dice_ew)
    print(dice_ns[1])