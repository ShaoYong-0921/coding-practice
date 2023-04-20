'''
def f(a, b, c):

    if b**2 - 4*a*c > 0:

        x1 = int( (-1*b + (b**2 - 4*a*c)**0.5) / (2*a) )
        x2 = int( (-1*b - (b**2 - 4*a*c)**0.5) / (2*a) )
        print (f'Two different roots {x1=}, {x2=}')

    elif b**2 - 4*a*c == 0:
        x = int((-1*b) / 2*a)
        print(f'Two same roots {x=}')

    elif b**2 - 4*a*c < 0:
        print('No real root')

a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c) 
f(a ,b, c)
'''
def f(a, b, c):
	
    if b**2 - 4*a*c > 0:

        x1 = int( (-1*b + (b**2 - 4*a*c)**0.5) / (2*a) )
        x2 = int( (-1*b - (b**2 - 4*a*c)**0.5) / (2*a) )
        print ('Two different roots x1={}, x2={}'.format(x1, x2))

    elif b**2 - 4*a*c == 0:
        x = int((-1*b) / 2*a)
        print('Two same roots x={}'.format(x))

    elif b**2 - 4*a*c < 0:
        print('No real root')

a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c) 
f(a ,b, c)