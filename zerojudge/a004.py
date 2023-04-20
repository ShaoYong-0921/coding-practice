while True:
    try:
        
        n=int(input())
        

        
        
        if n%4 == 0:
            if n%100 == 0:
                if n%400 == 0:
                     print("閏年")
                else:
                     print("平年")
            else:
                print("閏年")
        else:
            print("平年")
    except:
        break

