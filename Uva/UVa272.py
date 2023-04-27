import sys
change = False

for line in sys.stdin.readlines():
    for char in line:

        if char == '"':
            if change:
                print('\'\'',end='')
                change = False
            else:
                print('``', end='')
                change = True
        else:
            print(char, end='')