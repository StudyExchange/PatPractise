#1006. 换个格式输出整数 (15)

#import
import math

#class

#function
def printNum(n, index):
    if index == 0:
        for i in range(n):
            print(i+1, end='')
    elif index == 1:
        for i in range(n):
            print('S', end='')
    elif index == 2:
        for i in range(n):
            print('B', end='')
    else:
        print('Error: Out of bounds')
#input
n = int(input())

#main
li = []
while True:
    if n <= 0:
        break
    li.append(n%10)
    n = int(math.floor(n/10))
    
#output
r = range(len(li))
for i in r[::-1]:
    printNum(li[i], i)
