#1017. A除以B (20)

#import

#class

#function

#input
st = input()
li = st.split()
#main
n = int(li[1])
reminder = 0
result = ''
if len(li[0]) == 0:
    reminder = 0
    result = 0
if len(li[0]) == 1:
    origin = int(li[0])
    reminder = origin%n
    result = result + str(int(origin/n))
else:
    for i in range(0, len(li[0])):
        origin = int(li[0][i]) + reminder*10
        reminder = origin%n
        result = result + str(int(origin/n))

index = 0
for i in range(len(result)):
    if result[i] != '0':
        index = i
        break
#output
print('%s %s' %(result[index:len(result)], reminder))
