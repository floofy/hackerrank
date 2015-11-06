'''
https://www.hackerrank.com/challenges/encryption
'''
import math

msg = raw_input()
length = len(msg)
sqrt = math.sqrt(length)
floor = sqrt if (length - pow(int(sqrt),2)) < (pow(int(sqrt+1),2) - length) else int(sqrt+1)

# If length is not perfect square, find the cieling
if floor != int(floor) and length-pow(sqrt,2) < pow(sqrt+1,2)-length:
    floor = int(floor)
    count = 0
    tmp = pow(floor,2)
    while tmp < length:
        tmp += floor
        count += 1
    ciel = floor + count
else:
    floor = int(floor)
    ciel = floor     # perfect square

rows = floor
cols = ciel

mat = [[] for row in range(rows)]
for i in range(length):
    mat[i/cols].append(msg[i])

encryption = ""
for col in range(cols):
    for row in range(rows):
        try:
            encryption += mat[row][col]
        except:
            pass
    encryption += ' '
    
print encryption
#for row in mat:
    #print ''.join(row)
