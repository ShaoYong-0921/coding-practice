def squares():
    min = int(input())
    max = int(input())
    squares_list = []

    for i in range(min, max+1):
        if i**0.5 % 1 == 0:
            squares_list.append(i)
    return squares_list


x = int(input())
for i in range(x):
    print(f'Case {i+1}:',sum(squares() ) )
