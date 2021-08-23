from sys import stdin

def change(x):
    count = 0
    x = bin(x)
    for i in x[::-1]:
        if i == '1':
            count += 1
        else:
            break
    return count

for s in stdin:
    if s == '0':
        break
    x = int(s)
    ans = change(x)
    print(ans)