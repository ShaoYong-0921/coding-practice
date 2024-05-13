n = int(input())

for i in range(n):
    relatives = list(map(int, input().split()))

    member = relatives.pop(0)
    relatives.sort()
    
    mid = (len(relatives)) // 2
    # print([abs(x - relatives[mid]) for x in relatives])
    
    distance = sum([abs(x - relatives[mid]) for x in relatives])
    
    print(distance)
    