import sys

coordsx = []
coordsy = []
for i in sys.stdin:
    coord = i.rstrip().split(" ")
    coordsx.append(coord[0])
    coordsy.append(coord[1])

xval = 0
for i in coordsx:
    if coordsx.count(i) == 1:
        xval = i

yval = 0
for i in coordsy:
    if coordsy.count(i) == 1:
        yval = i

print(str(xval) + " " + str(yval))
