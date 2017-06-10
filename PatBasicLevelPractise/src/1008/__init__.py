#1008. 数组元素循环右移问题 (20)

#import
import math
#class

#function
def reverse(li, start, stop):
    length = int(math.floor((stop-start)/2))
    for i in range(length):
        temp = li[start+i]
        li[start+i]=li[stop-i-1]
        li[stop-i-1]=temp
        
#input
str1 = input()
m = int(str1.split(' ')[1])
str2 = input()
li = str2.split(' ')

#main
m = m%len(li)
length = len(li)
reverse(li, 0, length-m)
reverse(li, length-m, length)
reverse(li, 0, length)

#output
for i in range(len(li)):
    if i < len(li) - 1:
        print(li[i], end=' ')
    else:
        print(li[i], end='')
        