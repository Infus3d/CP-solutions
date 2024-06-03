n = int(input().split()[0])
a = [int(i) for i in input().split()]

b = [0] * 120
#  print(b)

for i in range(n):
    cnt = 0
    aa = a[i]
    
    while aa > 1:
        cnt = cnt + 1
        aa = aa // 2
        
    b[cnt] += 1

ans = 0
for i in range(119):
    b[i+1] += b[i] // 2
    if b[i] > 0:
        ans = i

#  print(b)

print(2 ** ans)
