#我要通过！(20)

#import
import re

#define function
def rule1(str):
    re.compile('A*[PAT]+', flags)
    return True

#input
# inputStr = input()
# inputCounter = int(inputStr)
# 
# inputList = []
# for index in range(inputCounter):
#     inputStr = input()
#     inputList.append(inputStr)

#body
inputList = [
    'PAT',
    'PAAT',
    'AAPATAA',
    'AAPAATAAAA',
    'xPATx',
    'PT',
    'Whatever',
    'APAAATAA']
print(inputList)
resultList = []

for i in range(len(inputList)):
    resultList.append(rule1(inputList[i]))


#output
for i in range(len(resultList)):
    print(resultList[i])
