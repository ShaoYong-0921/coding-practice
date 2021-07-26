class Randow_Radish:
    def __init__(self):
        self.poisoning = 0
        self.eft = []
        self.eats =[]

    def setting_effect_list(self):
        
        eft = list(map(int, input().split())) 
        eft.insert(0, 0)
        eft[3] *= -1;eft[4] *= -1;eft[5] *= -1

        print(f'{eft=}')
        return eft

    def effect(self, eat):
        if poisoning:
            hp += poisoning

        elif eat == 4:
            self.poisoning += eft[5]

        hp += eft[eat]
        print(f'{hp=},{poisoning=}')

        return hp

    def result(self):
        self.eft = self.setting_effect_list()
        self.eats = list(map(int, input().split()))
        for eat in self.eats:
            hp = self.effect(eat)

            if hp <= 0:
                return'bye~Rabbit'

            return f'{hp}g'


    def main(self):
        times = int(input())
        try:
            for _ in range(times):
                print(self.result())

        except Exception as e:
            print(e)

if __name__ == '__main__':
    r = Randow_Radish()
    r.main()
            







