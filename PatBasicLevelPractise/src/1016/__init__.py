#1016. 部分A+B (15)

#import

#class

#function

#input
str = input()
li = str.split()
#main
pa = ''
pb = ''
for i in range(len(li[0])):
    if li[0][i] == li[1]:
        pa = pa + li[0][i]
for i in range(len(li[2])):
    if li[2][i] == li[3]:
        pb = pb + li[2][i]
a = 0
b = 0
if len(pa) > 0:
    a = int(pa)
if len(pb) > 0:
    b = int(pb)
#output
print(a + b, end='')
