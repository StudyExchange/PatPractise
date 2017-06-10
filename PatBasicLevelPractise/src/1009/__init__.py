#1009. 说反话 (20)

#import

#class

#function

#input
str = input()
#main
li = str.split(' ')
li.reverse()
#output
n = len(li)
for i in range(n):
    if i < n-1:
        print(li[i], end=' ')
    else:
        print(li[i], end='')
