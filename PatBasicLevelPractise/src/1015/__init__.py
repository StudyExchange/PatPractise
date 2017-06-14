#1015. 德才论 (25)
#import

#class

#function
def cmp_stu(x, y):
    if (x[1] + x[2]) > (y[1] + y[2]):
        return True
    elif (x[1] + x[2]) < (y[1] + y[2]):
        return False
    else:
        if x[1] > y[1]:
            return True
        elif x[1] < y[1]:
            return False
        else:
            if x[0] > y[0]:
                return False
            else:
                return True
#input
str = input()
(n, l, h) = map(int, str.split())
li = []
for i in range(n):
    (num, de, cai) = map(int, input().split())
    li.append((num, de, cai))
#main
a=[]
b=[]
c=[]
d=[]
result = []
for i in range(n):
    if li[i][1] >= h and li[i][2] >= h:
        a.append(li[i])
    elif li[i][1] >= h and li[i][2] < h and li[i][2] >= l:
        b.append(li[i])
    elif li[i][1] < h and li[i][2] < h and li[i][1] >= li[i][2]:
        c.append(li[i])
    elif li[i][1] >= l and li[i][2] >= l:
        d.append(li[i])
result.extend(sorted(sorted(sorted(a, key=lambda x:(x[0]), reverse=False), key=lambda x:(x[1]), reverse=True), key=lambda x:(x[1]+x[2]), reverse=True))
result.extend(sorted(sorted(sorted(b, key=lambda x:(x[0]), reverse=False), key=lambda x:(x[1]), reverse=True), key=lambda x:(x[1]+x[2]), reverse=True))
result.extend(sorted(sorted(sorted(c, key=lambda x:(x[0]), reverse=False), key=lambda x:(x[1]), reverse=True), key=lambda x:(x[1]+x[2]), reverse=True))
result.extend(sorted(sorted(sorted(d, key=lambda x:(x[0]), reverse=False), key=lambda x:(x[1]), reverse=True), key=lambda x:(x[1]+x[2]), reverse=True))

#output
print(len(result))
for i in range(len(result)):
    print('%d %d %d' %(result[i][0], result[i][1], result[i][2]))
    