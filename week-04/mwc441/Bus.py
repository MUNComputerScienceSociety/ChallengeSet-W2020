import sys


def bus(n):
    num = 1
    for i in range(1, n, 1):
        num = (num+0.5)*2
    return num

count = 0
for i in sys.stdin:
    if(count > 0):
        print(int(bus(int(i))))
    count = count + 1

