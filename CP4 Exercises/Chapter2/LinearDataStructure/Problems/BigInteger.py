import sys
inputs = sys.stdin.read().splitlines()

i = 0
while (inputs[i] != "0"):
    print(int((int(inputs[i]) % 17) == 0))
    i += 1
























"""
Problem 3

for line in inputs:
    n, a = map(int, line.split())
    
    rst = 0
    for i in range(1, n + 1):
        rst += i * (a ** i)
    print(rst)
"""


"""
Problem 2

def reverse(n):
    rst = 0
    while n != 0:
        rst = rst * 10 + (n % 10)
        n //= 10
    return rst

ln = 1
N = int(inputs[0])

for i in range(N):
    n1, n2 = map(int, inputs[ln].split())
    print(reverse(reverse(n1) + reverse(n2)))
    ln += 1
"""


"""
Problem 1
ln = 0 # Corresponding to the line
casenum = 1 # Correspond to the case

while True:
    N, F = map(int, inputs[ln].split())
    ln += 1

    if N == 0 and F == 0: break
    sum = 0

    for _ in range(N):
        sum += int(inputs[ln])
        ln += 1
    
    print("Bill #%d costs %d: each friend should pay %d\n" %(casenum, sum, sum // F))
    casenum += 1
"""
