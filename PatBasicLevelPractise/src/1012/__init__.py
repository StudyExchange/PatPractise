#1012. 数字分类 (20)

#import

#class

#function

#input
str = input()
li = str.split()
for i in range(len(li)):
    li[i] = int(li[i])
#main
a1=[]
a2=[]
a3=[]
a4=[]
a5=[]
for i in range(len(li)):
    if li[i] % 5 == 0 and li[i] % 2 == 0:
        a1.append(li[i])
    if li[i] % 5 == 1:
        a2.append(li[i])
    if li[i] % 5 == 2:
        a3.append(li[i])
    if li[i] % 5 == 3:
        a4.append(li[i])
    if li[i] % 5 == 4:
        a5.append(li[i])
result = []
if len(a1) <= 0:
    result.append('N')
else:
    result.append(sum(a1))
    
if len(a2) <= 0:
    result.append('N')
else:
    for i in range(len(a2)):
        if i % 2 != 0:
            a2[i] = -a2[i]
    result.append(sum(a2))

if len(a3) <= 0:
    result.append('N')
else:
    result.append(len(a3))
    
if len(a4) <= 0:
    result.append('N')
else:
    avg = round(sum(a4)/len(a4),1)
    result.append(avg)

if len(a5) <= 0:
    result.append('N')
else:
    result.append(max(a5))
#output
print(a1)
print(a2)
print(a3)
print(a4)
print(a5)
for i in range(len(result)):
    if i < len(result)-1:
        print(result[i], end=' ')
    else:
        print(result[i], end='')
