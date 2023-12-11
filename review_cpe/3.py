while True:
    a, b = map(str, input().split())
    if a == "0" and b == "0":
        break

    if (len(a) < len(b)):
        for _ in range(len(b) - len(a)):
            a = "0" + a
    elif (len(b) < len(a)):
        for _ in range(len(a) - len(b)):
            b = "0" + b
    digit = len(a)
    count = 0; carry = 0
    # print(f'{a = } {b = }')
    for i in range(digit - 1, -1, -1):
        # print("addition = ", int(a[i]) +int(b[i]) + carry)
        if (int(a[i]) +int(b[i]) + carry >= 10):
            carry = 1
            count += 1
        else:
            carry = 0
    if count == 0:
        print("No carry operation.")
    elif count == 1:
        print("1 carry operation.")
    else:
        print(f'{count} carry operations.')