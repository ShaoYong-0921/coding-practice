
while True:
    try:
        x = []
        y = []
        line = list( map( float, input().split() ) )
        if len(line) != 8:
            break

        for i in range(len(line)):
            if i % 2 == 0:
                x.append(line[i])
            if i % 2 == 1:
                y.append(line[i])
        # print(f'{x_point =} {y_point = }')

        if x[1] == x[2] and y[1] == y[2]:
            ans_x = x[0] + x[3] - x[1]
            ans_y = y[0] + y[3] - y[1]

        elif x[0] == x[2] and y[0] == y[2]:
            ans_x = x[1] + x[3] - x[0]
            ans_y = y[1] + y[3] - y[0] 

        elif x[0] == x[3] and y[0] == y[3]:
            ans_x = x[1] + x[2] - x[0]
            ans_y = y[1] + y[2] - y[0] 

        elif x[1] == x[3] and y[1] == y[3]:
            ans_x = x[0] + x[2] - x[1]
            ans_y = y[0] + y[2] - y[1] 
        
        print('{:.3f} {:.3f}'.format(ans_x, ans_y))


    except EOFError:
        break
