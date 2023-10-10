from collections import Counter

def most_common(list):
    data = Counter(list)
    return max(list, key=data.get)

while True:
    try:
        x = []
        y = []
        inputs = list( map( float, input().split() ) )

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
        
        print('{:.3f} {:.3f}'.format(ans_x, ans_y))

    except EOFError:
        break