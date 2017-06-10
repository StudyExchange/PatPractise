#1003. 我要通过！(20)

#import

#define function
def rule(str):
    status = 0
    pn = 0
    an = 0
    tn = 0
    pre = 0
    mid = 0
    post = 0
    for i in range(len(str)):
        if not(str[i] == 'P' or str[i] == 'A' or str[i] == 'T'):
            break
        if str[i] == 'P':
            pn = pn + 1
        if str[i] == 'A':
            an = an + 1
        if str[i] == 'T':
            tn = tn + 1
            
        if status == 0:
            if str[i] == 'A':
                pre = pre + 1
            elif str[i] == 'P':
                status = 1
                continue
            else:
                return False
        if status == 1:
            if str[i] == 'A':
                mid = mid + 1
            elif str[i] == 'T':
                status = 2
                continue
            else:
                return False
        if status == 2:
            if str[i] == 'A':
                post = post + 1
            else:
                return False
#    print((pre, mid, post))
    if pn!=1 or an<1 or tn!=1:
        return False
    if pre*mid == post:
        return True
    else:
        return False            

#body
# inputList = [
#     'PAT',
#     'PAAT',
#     'AAPATAA',
#     'AAPAATAAAA',
#     'xPATx',
#     'PT',
#     'Whatever',
#     'APAAATAA']
n = input()
li = []
for i in range(int(n)):
    li.append(input())
#print(li)

#main
resultList = []
for i in range(len(li)):
    resultList.append(rule(li[i]))


#output
for i in range(len(resultList)):
    if resultList[i]:
        print('YES')
    else:
        print('NO')
