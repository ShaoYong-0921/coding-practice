while True:
    
    try:
        x = input()

        if x == x[::-1]:
            print("yes")
        else:
            print("no")
    except:
        break

        
