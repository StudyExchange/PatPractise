#import
import re

#define function
def rule1(str):
    for i in range(len(str)):
        if(str[i] == 'P' or str[i] == 'A' or str[i] == 'T'):
            continue
        return False
    return True

#input
inputStr = input()
inputCounter = int(inputStr)

inputList = []
for index in range(inputCounter):
    inputStr = input()
    inputList.append(inputStr)

#body
print(inputList)
resultList = []

for i in range(len(inputList)):
    resultList.append(rule1(inputList[i]))

#output
for i in range(len(resultList)):
    print(resultList[i])