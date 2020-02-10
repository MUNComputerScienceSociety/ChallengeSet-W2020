import sys

sys.stdin.readline() #useless

tb = 0
lr = 0
for sword in sys.stdin.readlines():
    for i in range(4):
        temp = int(sword[i])
        if temp==0:
            if i < 2:
                tb += 1
            else:
                lr += 1

swords = 0
while (tb > 1) and (lr > 1):
    swords += 1
    tb -= 2
    lr -= 2

print("{} {} {}".format(swords, tb, lr))