#1013. 数素数 (20)
#import
import math
#class

#function
def isPrime(n):
    if n <= 1:
        return False
    max = int(math.sqrt(n))
    for i in range(2, max+1):
        if n%i == 0:
            return False
    return True
    

#input
str = input()
li = str.split()
m = int(li[0])
n = int(li[1])
#main
i = 1
counter = 0
while True:
    if isPrime(i):
        counter += 1
        if counter>=m and counter<n:
            if (counter-m+1)%10==0:
                print(i)
            else:
                print(i, end=' ')
        elif counter==n:
            print(i, end='')  
            break 
    i+=1
#output


                
