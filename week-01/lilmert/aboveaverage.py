import sys

cases = int(sys.stdin.readline())

def reader():
    cond = sys.stdin.read(1)
    temp = []
    while cond.isalnum():
        temp.append(cond)
        cond = sys.stdin.read(1)
    
    return int(''.join(temp))

class Classroom:
    def __init__(self, num_ppl, avg=None):
        self.num_ppl = int(num_ppl)
        self.avg = avg
        self.grades = []

for i in range(cases):
    temp_class = Classroom(reader())
    for j in range(temp_class.num_ppl):
        temp_class.grades.append(reader())
    
    temp_avg = sum(temp_class.grades)/len(temp_class.grades)
    count = 0
    for grade in temp_class.grades:
        if grade > temp_avg:
            count += 1
    
    output = count/len(temp_class.grades) * 100
    print("{:.3f}%".format(output))