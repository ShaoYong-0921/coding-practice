import time

def is_prime(integer):
    count = 0
    if integer <= 1:
        return False
    elif integer == 2:
        return True
    elif integer == 3:
        return True


    if integer % 2 == 0:
        return False
    elif integer % 3 == 0:
        return False

    for i in range(5, integer, 2): 
        #print(f'{i=},{integer=}')
        count += 1

        if integer % i == 0:
            return False

        if i*i > integer:
            break

        if count == 2:
            count = 0
            continue    
    return True



def main(a, b):
    prime = []

    for i in range(a, b+1):
        if is_prime(i):
            prime.append(i)


    return len(prime)

#while True:
    # try:
    #     a, b = input().split()
    #     a = int(a); b = int(b)
    #     print(main(a, b))
    # except:
    #     break
#main
a, b = input().split()
a = int(a); b = int(b)
time_start = time.time()
print(main(a, b))
time_end = time.time()

total_time = time_end - time_start
print(f'finish in {total_time}')