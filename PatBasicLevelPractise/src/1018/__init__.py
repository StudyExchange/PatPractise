#1018. 锤子剪刀布 (20)

#import

#class

#function

#input
n = int(input())
li = []
for i in range(n):
    li.append(input().split())

#main
a = [0, 0, 0]
aw = [0, 0, 0] #B, C, J
awMax = ''
b = [0, 0, 0]
bw = [0, 0, 0] #B, C, J
bwMax = ''
wStr = ['B', 'C', 'J']

for i in range(n):
    if li[i][0] == 'B' and li[i][1] == 'B':
        a[1] = a[1] + 1
        b[1] = b[1] + 1
        continue
    if li[i][0] == 'C' and li[i][1] == 'C':
        a[1] = a[1] + 1
        b[1] = b[1] + 1
        continue
    if li[i][0] == 'J' and li[i][1] == 'J':
        a[1] = a[1] + 1
        b[1] = b[1] + 1
        continue
        
    if li[i][0] == 'B' and li[i][1] == 'C':
        a[0] = a[0] + 1
        b[2] = b[2] + 1
        aw[0] = aw[0] + 1
        continue
    if li[i][0] == 'C' and li[i][1] == 'J':
        a[0] = a[0] + 1
        b[2] = b[2] + 1
        aw[1] = aw[1] + 1
        continue
    if li[i][0] == 'J' and li[i][1] == 'B':
        a[0] = a[0] + 1
        b[2] = b[2] + 1
        aw[2] = aw[2] + 1
        continue
    
    if li[i][0] == 'B' and li[i][1] == 'J':
        a[2] = a[2] + 1
        b[0] = b[0] + 1
        bw[0] = bw[0] + 1
        continue
    if li[i][0] == 'C' and li[i][1] == 'B':
        a[2] = a[2] + 1
        b[0] = b[0] + 1
        bw[1] = bw[1] + 1
        continue
    if li[i][0] == 'J' and li[i][1] == 'C':
        a[2] = a[2] + 1
        b[0] = b[0] + 1
        bw[2] = bw[2] + 1
        continue

for i in range(3):
    if aw[i] == max(aw):
        awMax = wStr[i]
        break
for i in range(3):
    if bw[i] == max(bw):
        bwMax = wStr[i]
        break
#output
print('%d %d %d' %(tuple(a)))
print('%d %d %d' %(tuple(b)))
print('%s %s' %(awMax, bwMax), end='')
