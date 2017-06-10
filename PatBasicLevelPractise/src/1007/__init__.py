#1007. 素数对猜想 (20)

#import
import math
#class

#function
def isPrime(n):
    if n <= 1:
        return False
    r = range(int(math.floor(math.sqrt(n)))+1)
    #print(list(r))
    r = r[2::]
    #print(r)
    #print(list(r))
    for i in r:
        if n % i == 0:
            return False
        else: 
            continue
    return True    
    
#input
n = int(input())
#main
li = [True for i in range(0, n+1)]
length = len(li)
#print(li)
li[0] = False
li[1] = False
for i in range(2, int(math.floor(n/2))+1):
    for j in range(2, int(math.floor(n/i))+1):
        #if i*j < length:
        #print(i*j, end = ' ')
        li[i*j] = False

#print(li)
result = 0
for i in range(2,len(li)):
    if li[i] == True and li[i-2] == True:
        result = result+1
        #print(li[i], end=' ')
#output
#print(result)
print(result)