#1005. 继续(3n+1)猜想 (25)
#import

#define function

#define class

#input
putCounter = input()
inputStr = input()
inputList = inputStr.split(' ')
inputNum = []
for i in range(len(inputList)):
    inputNum.append(int(inputList[i]))

#main
#print(inputNum)
coverDict = dict()

for i in range(len(inputNum)):
    num = inputNum[i]
    if num in coverDict:
        if coverDict[num] == 0:
            print('Warning: same number!')
            continue
        else:
            coverDict[num] = coverDict[num] + 1
            continue
    else:
        coverDict[num] = 0
    while(True):
        if num == 1:
            break
        if num % 2 == 0:
            num = num/2
        else:
            num = (3*num + 1)/2
        num = int(num)
        if num in coverDict:
            coverDict[num] = coverDict[num] + 1
        else:
            coverDict[num] = 1
resultList = []
for (k,v) in coverDict.items():
    if v == 0:
        resultList.append(k)

result = sorted(resultList, reverse = True)
#Output
for i in range(len(result)):
    print(result[i], end = '')
    if(i < len(result) - 1):
        print(' ', end = '')
