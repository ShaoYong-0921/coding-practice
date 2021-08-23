from sys import stdin, stdout 

def count(guess):
    a = 0
    b = 0

    check_ans = ans.copy()

    for i in range(4):
        if guess[i] == check_ans[i]:
            guess[i] = -1; check_ans[i] = -1
            a += 1

    for i in guess:
        if i == -1:
            continue
        else:
            if check_ans.count(i):
                x = check_ans.index(i)
                check_ans[x] = -1
                b += 1

    return f'{a}A{b}B'

output = ''

for line in stdin:
    if line.strip() == '':
        continue
    ans = line.strip().split()
    w = int(stdin.readline())
    for _ in range(w):
        guess = stdin.readline().strip().split() 
        output += count(guess)+'\n'

stdout.write(output.strip())