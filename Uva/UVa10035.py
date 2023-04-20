while True:
    num1, num2 = map(str, input().split(' '))
    if num1 == '0' and num2 == '0':
        break
    carry = 0
    check = False
    if len(num1) <= len(num2):
        for i in range(len(num1), -1):
            if int(num[i]) + int(num2[i]) >= 10:
                carry += 1
                check = True
            elif int(num[i]) + int(num[i]) == 9 and plus == True:
                carry += 1
            else:
                check = False
        print(f'{carry}')
        if carry:
            print(f'{carry} carry opertions ')
        else:
            print('No carry opertion') 