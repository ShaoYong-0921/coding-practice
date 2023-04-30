import sys

member = {}

for line in sys.stdin.readlines():
    s, d = map(int, line.split())
        
    count = 0
    while True:
        print(f'{count = } {d = } {s = }')
        if d <= count:
            print('ans =',s - 1)
            break

        if s in member:
            print(f'{s = } ;{d = }; {member = }')
            count = member[s]
            # print(f'new_c = {count}')
            s += 1
        #     count += s 

        count += s
        member[s] = count
        s += 1
        