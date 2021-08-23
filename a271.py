from sys import stdin, stdout

output = ''
def setting_effect_list():
            
    eft = list(map(int, stdin.readline().split())) 
    eft[2] *= -1;eft[3] *= -1;eft[4] *= -1
    hp = eft[5]

    # print(f'{eft=}{hp=}')
    return eft, hp

def effect(eat, hp):
    poisoning = 0

    for i in eat:
        
        i -= 1

        if poisoning:
            hp += poisoning

        if hp <= 0:
            return'bye~Rabbit'

        if i == 3:
            poisoning += eft[4]
            hp += eft[i]

        elif i == -1:
            pass
        
        else:
            hp += eft[i]

        # print(f'{hp=},{poisoning=}')

    if hp <= 0:
            return'bye~Rabbit'
            
    return f'{hp}g'

times = int(stdin.readline())
for i in range(times):
    eft, hp = setting_effect_list()
    eat = list(map(int, stdin.readline().split()))
    output += effect(eat, hp) + '\n'

stdout.write(output)