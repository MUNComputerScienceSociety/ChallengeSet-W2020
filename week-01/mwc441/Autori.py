import sys

def autori(name):
    return "".join(word[0] for word in name.split("-"))

for i in sys.stdin:
    print(autori(i))
