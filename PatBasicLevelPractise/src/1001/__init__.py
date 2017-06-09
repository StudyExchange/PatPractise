#害死人不偿命的(3n+1)猜想 (15)
#input
inputStr = input()
number = int(inputStr)

#body
isEnd = False
counter = 0
while(not isEnd):
    if(number == 1):
        isEnd = True
        break
    counter += 1
    
    if(number % 2 == 0):
        number /= 2
    else:
        number = (number*3+1)/2

#output
print(counter)
