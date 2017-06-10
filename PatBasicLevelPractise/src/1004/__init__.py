#1004. 成绩排名 (20)

#import
from _ast import Num
from _operator import itemgetter

#define function

#define class

#input
numStr = input()
num = int(numStr)

studentList = []
for i in range(num):
    studentStr = input()
    student = studentStr.split()
    student[2] = int(student[2])
    studentTuple = tuple(student)
    studentList.append(studentTuple)

#main
s1 = sorted(studentList, key=itemgetter(2), reverse=True)

#Output
print(s1[0][0], end=' ')
print(s1[0][1])
print(s1[-1][0], end=' ')
print(s1[-1][1])
