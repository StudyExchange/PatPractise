#import
import math

#define function
def getNumberListFromIngeter(intNumber):
    isEnd = False
    numberList = []
    while(not isEnd):
        if(intNumber < 10):
            numberList.append(intNumber)
            isEnd = True
            break
        lowest = intNumber % 10
        numberList.append(lowest)
        intNumber = math.floor(intNumber/10)
    return numberList

#body
pinyin = {
    0:'ling',
    1:'yi',
    2:'er',
    3:'san',
    4:'si',
    5:'wu',
    6:'liu',
    7:'qi',
    8:'ba',
    9:'jiu'
}

inputStr = input()

sum = 0
for n in inputStr:
    sum+=int(n)
sumNumberList = getNumberListFromIngeter(sum)
sumNumberList.reverse()
#print(sumNumberList)

#output
counter = 0
length = len(sumNumberList)
for n in sumNumberList:
    str = pinyin[n]
    print(str, end = '')
    if(counter < length-1):
        print(' ', end = '')
    counter += 1
