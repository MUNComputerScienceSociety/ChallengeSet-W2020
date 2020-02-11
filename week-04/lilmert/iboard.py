import sys

for line in sys.stdin.readlines():
    line = line.strip("\n")
    left = 0
    right = 0    
    for char in line:
        binary = "{:07b}".format(ord(char))
        for bit in binary:
            if bit=='1':
                left += 1
            else:
                right += 1
    if (left%2==0 and right%2==0):
        print("free")
    else:
        print("trapped")