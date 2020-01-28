import sys


def messyBanner(bldg):
    if(len(bldg.strip()) == 0):
        return True
    if(len(bldg) != 8):
        spaces = 8 - len(bldg)
        bldg = bldg + " "*spaces
    
    letters = True
    total = 0
    for count in range(len(bldg)):
        if(bldg[count].isupper() and letters):
            total = total + 1
        if(bldg[count].islower()):
            return False
        if(count < 3 and letters==False and bldg[count] != " "):
            return False
        if(count < 3 and letters == False and total < 1):
            return False
        if(count < 3 and bldg[count].isalpha() == False and letters):
            letters = False
        if(count <= 6 and count >= 3 and bldg[count].isdigit() == False):
            return False
        if(count == 7 and (bldg[count] != " " and bldg[count].isupper() == False)):
            return False
    return True

for i in sys.stdin:
    if(messyBanner(i.rstrip())):
        print("Y")
    else:
        print("N")
