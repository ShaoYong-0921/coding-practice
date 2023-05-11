while True:
    n = int(input())

    if n == 0:
        break

    string = str(bin(n))
    # print(string)
    list_s = [i for i in string]
    count = list_s.count('1')

    binary = ''
    for i in range(2,len(list_s)):
        binary += list_s[i]
    # print(f'{binary}')

    print(f'The parity of {binary} is {count} (mod 2).')

