num = 2
f_n1 = 3
f_n2 = 1
tmp = 0
while num != 40:
    tmp = f_n1 * 5 + f_n2
    if tmp % 2 == 1:
        num += 1
    f_n1, f_n2 = tmp, f_n1
print(tmp)