import sys

line = sys.stdin.readline()

count = 0
heights = []
boxes = []
for num in line.split(" "):
    if count < 6:
        boxes.append(int(num))
    else:
        heights.append(int(num))
    count += 1

boxes.sort(reverse=True)

def find_tower(box_list, total_height):
    for i in range(4):
        temp = len(box_list[i+1:])
        for j in range(temp-1):
            box1 = box_list[i]
            box2 = box_list[i+j+1]
            others = box_list[i+j+2:]
            for box3 in others:
                if box1+box2+box3==total_height:
                    print(box1, end=" ")
                    print(box2, end=" ")
                    print(box3, end=" ")

find_tower(boxes, heights[0])
find_tower(boxes, heights[1])
print()

