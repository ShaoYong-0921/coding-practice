from itertools import permutations as p
from sys import stdin, stdout

for line in stdin:
    if line.strip() == '':
        break
    output = ''
    n = int(line.strip())
    ans = [str(i) for i in range(n, 0,-1)]
    ans = p(ans)

    for i in ans:
        output += ''.join(i) + '\n'
    stdout.write(output)