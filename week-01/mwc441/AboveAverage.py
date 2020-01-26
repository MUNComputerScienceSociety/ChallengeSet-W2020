def aboveAvg(arr):
    total = arr[0]
    avgarr = []
    for x in range(1, total+1):
        avg = float((sum(arr[x])-arr[x][0])/arr[x][0])
        count = 0
        for num in arr[x]:
            if(num>avg):
                count += 1
        avgarr.append(str(float(count)/float(arr[x][0])*100)+"%")
    return avgarr
