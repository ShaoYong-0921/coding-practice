from sys import stdin, stdout

lines = stdin.readlines() 
output = ''
for line in lines:
    a, b, n = line.split()
    a = int(a); b = int(b); n = int(n)
    integer = a // b
    a = a*10**n #補零
    digits = 0
    ans = str(a // b).zfill(n)

    for _ in str(integer):
        digits += 1

    
    if integer == 0:
        output += f'0.{ans}\n'

    else:
        output += f"{ans[:digits]}.{ans[digits:]}\n"


stdout.write(output)