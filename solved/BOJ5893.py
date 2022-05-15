n = input()
n = n[::-1]
d = 0
for i in range(len(n)):
    if (n[i] == '1'):
        d += (1 << (i))
d *= 17
ans = ''
while (d > 0):
    ans += ('1' if d % 2 else '0')
    d >>= 1
print(ans[::-1])
