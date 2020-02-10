import sys

def passengers(num_stops):
    if num_stops == 1:
        return 1
    else:
        return passengers(num_stops-1) + 2**(num_stops-1)

cases = sys.stdin.readline()

for line in sys.stdin.readlines():
    print(passengers(int(line)), end=" ")
print()