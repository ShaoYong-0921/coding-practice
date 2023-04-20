def Bangla_Number(int):
    ans = ''
    
    kuti = int // 10000000
    int %= 10000000
    if kuti:
        ans += ' {} kuti'.format(kuti)    
    
    lakh = int // 100000
    int %= 100000
    if lakh:
        ans += ' {} lakh'.format(lakh)
    
    hajar = int // 1000
    int %= 1000
    if hajar:
        ans += ' {} hajar'.format(hajar)
            
    shata = int // 100
    int %= 100
    if shata:
        ans += ' {} shata'.format(shata)
        
    if int:
        ans += ' {}'.format(int)
        
    return ans 

try:
    label = 1 
    
    while True:
        ans = ''
        num = str(input())
        
        if len(num) >= 8:
            kuti = int(num[:-7])
            num = num[-7:]
            # print(f'{kuti=} {num=}')
            
            ans += Bangla_Number(kuti)
            ans += ' kuti'
            # print(f'{ans=}')

        num = int(num)
        ans += Bangla_Number(num)
        
        if ans:
            print('{}.{}'.format(label, ans))
        else:
            print('{}. 0'.format(label))

        label += 1
        
except EOFError:
    pass