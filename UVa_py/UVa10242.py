def most_common(lst):
    counter = 0
    num = 0

    for i in lst:
        curr_frequency = lst.count(i)
        if(curr_frequency > counter):
            counter = curr_frequency
            num = i
 
    return num

while True:
    try:
        x = []
        y = []
        inputs = list( map( float, input().split() ) )
        
        if len(inputs) != 8:
            break

        for i in range(len(inputs)):
            if i % 2 == 0:
                x.append(inputs[i])
            if i % 2 == 1:
                y.append(inputs[i])

        x_point = most_common(x)
        y_point = most_common(y)
        # print(f'{x_point =} {y_point = }')

        ans_x = 0
        for i in x:
            ans_x += i
        ans_x -= x_point * 3

        ans_y = 0
        for i in y:
            ans_y += i
        ans_y -= y_point * 3
        
        # print('{:.3f} {:.3f}'.format(ans_x, ans_y))
        print(f'{ans_x:.3f} {ans_y:.3f}')

    except EOFError:
        break
