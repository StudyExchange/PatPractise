#1011. A+B和C (15)

#import

#class

#function

#input
n = int(input())
li = []
for i in range(n):
    li.append(input().split())
#main

#output
for i in range(len(li)):
    a = int(li[i][0])
    b = int(li[i][1])
    c = int(li[i][2])
    if a+b>c:
        print('Case #%d: true' % (i+1))
    else:
        print('Case #%d: false' % (i+1))
        