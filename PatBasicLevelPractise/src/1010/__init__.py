#1010. 一元多项式求导 (25)

#import

#class

#function

#input
str = input()
li = str.split()

numLi = []
for i in range(len(li)):
    numLi.append(int(li[i]))
#main
n = len(numLi)
result = [0 for i in range(0,n)]
for i in range(int(len(numLi)/2)):
    result[i*2] = numLi[i*2]*numLi[i*2+1]
    if numLi[i*2+1] == 0:
        result[i*2+1] = 0
    else:
        result[i*2+1] = numLi[i*2+1] - 1

#output
for i in range(int(n/2)):
    if result[i*2] == 0 and n != 2:
        break
    if i == 0:
        print('%d %d' % (result[i*2], result[i*2+1]), end='')
    else:
        print(' %d %d' % (result[i*2], result[i*2+1]), end='')
