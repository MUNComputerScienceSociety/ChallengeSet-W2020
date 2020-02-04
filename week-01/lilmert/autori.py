import sys

for char in sys.stdin.readline():
    if char.isupper():
        print(char, end="")
print()