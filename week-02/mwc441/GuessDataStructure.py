f = open("GuessDataStructure.txt", "r")
arr = []
while True:
    nstr = f.readline()
    nstr = nstr.rstrip()
    if(len(nstr) == 0):
        break
    if(len(nstr) == 1):
        arr.append(int(nstr))
    if(len(nstr) == 3):
        arr.append([int(nstr[0]), int(nstr[2])])


def guessDataStructure(arr):
    total = 0
    for x in range(len(arr)):
        try:
            arr[x] += 1
            arr[x] -= 1
            queue = True
            stack = True
            priority = True
            total = arr[x]
            insert = []
            count = x+1
            counter = 0
            countdown = 0
            inserted = []
            for y in range(x+1, total+x+1, 1):
                if(total == 1):
                    break
                if(arr[y][0] == 1):
                    inserted.append(arr[y][1])
                if(arr[y][0] == 2):
                    #CHECK IF QUEUE
                    for j in range(count, total+x+1, 1):
                        insert = arr[j]
                        if(arr[j][0] == 1):
                            count = j+1
                            break
                    if(insert[1] != arr[y][1]):
                        queue = False
                    #CHECK IF STACK
                    for j in range(y, x, -1):
                        insert = arr[j]
                        if(arr[j][0] == 1 and countdown == 0):
                            counter = counter + 1
                            countdown = counter
                            break
                        if(arr[j][0] == 1 and countdown > 0):
                           countdown = countdown - 1
                    if(insert[1] != arr[y][1]):
                        stack = False

                    #CHECK IF PRIORITY QUEUE
                    if(max(inserted) == arr[y][1] and priority != False):
                        inserted.remove(max(inserted))   
                    else:
                        priority = False
            if(priority and not stack and not queue):
                print("priority queue")
            elif(stack and not queue and not priority):
                print("stack")
            elif(queue and not stack and not priority):
                print("queue")
            elif(total == 1):
                print("impossible")
            elif(not queue and not stack and not priority):
                print("impossible")
            else:
                print("not sure")
        except:
            x = x + 1
        
        
        
            

guessDataStructure(arr)
