import time
def main():
    from sys import stdin, stdout

    output = ''
    for line in stdin:
        if (line.strip()) == '':
            continue
        ans = line.strip().split()
        count = {str(i): 0 for i in range(10)}
        for n in ans: count[n] += 1
        w = int(stdin.readline())
        for _ in range(w):
            A, B, C = 0, 0, count.copy()
            t = stdin.readline().strip().split() 
            bchk = []
            for i in range(4):
                d = t[i]
                if C[d]:
                    if (d == ans[i]):
                        A += 1
                        C[d] -= 1
                    else:
                        bchk.append(d)
            
            for d in bchk:
                if (C[d]):
                    B += 1
                    C[d] -= 1
            output += f'{A}A{B}B\n'
    stdout.write(output.strip())

start = time.time()
main()
end = time.time()
print(f'耗時{end-start:.10f}秒')