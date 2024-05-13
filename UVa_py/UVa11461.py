from sys import stdin

n = 1
table = [0]
while True:
    num = n * n
    if num > 100000:
        break
    
    n += 1
    table.append(num)
# print(table)

for line in stdin:
    a, b = map(int, line.split())
    if a == 0 and b == 0:
        break
    for i in range(len(table)):
        if table[i] <= a <= table[i+1]:
            # print(f'{table[i] = } <= {a = } <= {table[i+1] = }')
            min = i
            if a == table[i]:
                min -= 1
            
            
        if table[i] <= b <= table[i+1]:
            # print(f'{table[i] = } <= {b = } <= {table[i+1] = }')
            max = i
            if b == table[i+1]:
                max += 1
    print(max - min)