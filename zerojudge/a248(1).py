from decimal import *
from sys import stdin, stdout

output = ''

for line in stdin:
    try:
        a, b ,n = line.split()
        n = int(n)
        x = 10 ** n
        a = int(a)*x; b = int(b)*x
        getcontext().rounding = ROUND_DOWN
        ans = Decimal(a) / Decimal(b)
        ans = Decimal(ans).quantize(Decimal('0.' + '0'*(n-1) + '1'))
        output += str(ans) + '\n'
    except Exception as e:
        print(e)
        break

stdout.write(output)