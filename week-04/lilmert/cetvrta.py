import sys

xs = []
ys = []
for line in sys.stdin.readlines():
    count = 0
    for num in line.split(" "):
        if count==0:
            xs.append(int(num))
        else:
            ys.append(int(num))
        count += 1

def find_missing(a_list):
    for num in a_list:
        if a_list.count(num) < 2:
            return num

print(find_missing(xs), end=" ")
print(find_missing(ys))