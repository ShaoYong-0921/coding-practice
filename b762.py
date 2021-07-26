n = int(input())
x = [input() for _ in range(n)] 


kill = 0
die = 0
assist = 0
combo = 0

for i in x:

    if i == "Get_Kill":

        kill += 1
        combo += 1

        if combo < 3:
            print("You have slain an enemie.")

        if combo == 3:
            print("KILLING SPREE!")  

        if combo == 4:
            print("RAMPAGE~")
            
        if combo == 5:
            print("UNSTOPPABLE!")
            
        if combo == 6:
            print("DOMINATING!")
            
        if combo == 7:
            print("GUALIKE!")
            
        if combo > 7:
            print("LEGENDARY!")

    if i == "Die":
        
        die += 1
        if  combo < 3:
            
            print("You have been slained.")

        else:
            print("SHUTDOWN.")
        combo = 0

    if i == "Get_Assist":
        assist = assist+1
        
print(f"{kill}/{die}/{assist}")
