from math import * 

try:
    while True:
        r, x, string = input().split()
        r, x = int(r), int(x)
        if string == 'min':
            deg = x / 60
        else:
            deg = x
        while deg > 360: deg -= 360
        if deg >= 180: deg = 360 - deg

        # print(f'{deg = }')
        deg = radians(deg)

        r += 6440
        arc = r * deg 
        chord = (r * r + r * r  - 2 * r * r * cos(deg)) ** 0.5
        # print(f'{r = } {x = } {deg = } {arc = } {chord = }')
        print(f'{arc:.6f} {chord:.6f}')

except EOFError:
    pass

# data = list(map (int, input().split()))