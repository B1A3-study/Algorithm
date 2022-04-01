check_list = ['U', 'C', 'P', 'C']
flag = True
s = input()

for check in check_list:
    if check in s:
        s = s[s.find(check)+1:]
    else:
        flag = False
        break

if flag:
    print("I love UCPC")
else:
    print("I hate UCPC")