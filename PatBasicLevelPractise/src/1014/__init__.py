
#import

#class

#function
def getDate(str):
    dateDict = {
        'A':'MON',
        'B':'TUE',
        'C':'WED',
        'D':'THU',
        'E':'FRI',
        'F':'STA',
        'G':'SUN',
    }
    return dateDict[str]

def getMinute(str):
    n = ord(str)
    if n>=48 and n<=57:
        n = n-48
    elif n>=65 and n<=78:
        n = n-65+10
    return n

#input
li = ['3485djDkxh4hhGE','2984akDfkkkkggEdsb','s&hgsfdk','d&Hyscvnm']
# li = []
# for i in range(4):
#     li.append(input())
#main
dateStr = ''
minuteStr = ''
secondPos = 0
counter = 0
for i in range(len(li[0])):
    if li[0][i].isupper() and li[1][i].isupper() and li[0][i] == li[1][i]:
        if counter == 0:
            dateStr = li[0][i]
            counter += 1
            continue
        if counter == 1:
            minuteStr = li[0][i]
            break
for i in range(len(li[2])):
    a = li[2][i]
    b = li[3][i]
    if a.isalpha() and b.isalpha() and a == b:
        secondPos = i
        break
#output
print(getDate(dateStr), end=' ')
minute = getMinute(minuteStr)
print('%02d' %minute, end=':')
print('%02d' %secondPos, end='')
