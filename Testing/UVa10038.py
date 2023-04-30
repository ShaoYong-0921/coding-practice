import sys 
for line in sys.stdin.readlines():
    num = list(map(int, line.split()))
    # print(f'{num =  }')

    absolute = [abs(num[x+1] - num[x])  for x in range(len(num)-1)]
    # absolute.sort()
    print(f'{absolute = }')
    
    status = True
    for i in range(max(absolute), min(absolute), -1):
        
        if i not in absolute:
            print('Not jolly')
            status = False
            break
        
        
    if status:
        print('Jolly')