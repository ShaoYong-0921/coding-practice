from sys import stdin


def prime(integer):
    ans = []
    count = 0

    if integer == 1:
        return [1]
    elif integer == 2:
        return [2]
    elif integer == 3:
        return [3]

    if integer % 2 == 0:
        ans.append(2)
        
    if integer % 3 == 0:
        ans.append(3)

    for i in range(5, int(integer*0.5)+1, 2): 
        print(f'{i=},{integer=}')
        count += 1
        if count == 2:
            count = 0
            continue

        if (integer % i == 0):
            
            ans.append(i)
            print(f'{i=}{ans=}')
    
    return ans

while True:
    # try:
    x = int(stdin.readline().strip())
    ans = []
    a_prime = prime(x)
    print(f'{a_prime=}')

    if a_prime == []:
        print(x)


    

    # except:
    #     break