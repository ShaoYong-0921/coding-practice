num1, num2 = input().split()
num1 = int(num1)
num2 = int(num2)
answers = []

for i in range(num1, num2):
    ans = str(i)
    x = len(ans)
    sum = 0

    for num in ans :
        num = int(num)
        sum += num**x

    if sum == i:
        answers.append(i)

if answers == []:
    print('none')
else:
    for anser in answers:
        print(anser, end=' ')
