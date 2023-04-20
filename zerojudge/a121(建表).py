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


def creat_prime_list():
    primes = []
    for i in range(1, 10000):
        if is_prime(i):
            primes.append(i)
    return primes


def judge(a, b):

    result = []
    # print('loading..')
    for i in range(a, b+1):
        for prime in primes:
            # print(f'{prime=},{i=}')
            if i % prime == 0:
                break
        else:
            result.append(i)
    return len(result)
            

def contrast(a, b):
    
    if a > 10000 and b > 10000:
        return judge(a, b)

    elif a < 10000 and b > 10000:
        ans = [prime for prime in primes if a <= prime <= 10000]
        result = judge(10000, b)
        return len(ans)+result

    elif b <= 10000:
        ans = [prime for prime in primes if a <= prime <= b]
        return len(ans)

    
primes = creat_prime_list()
while True:
    try:
        a, b = input().split()
        a = int(a); b = int(b)
        print(main(a, b))
    except:
        break

#main

# primes = creat_prime_list()
# a, b = input().split()
# a = int(a); b = int(b)
# time_start = time.time()
# print(main(a, b))

# time_end = time.time()
# total_time = time_end - time_start
# print(f'finish in {total_time}')