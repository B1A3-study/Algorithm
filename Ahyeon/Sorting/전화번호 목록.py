t = int(input())
for _ in range(t):
    n = int(input())
    # 입력 숫자들 정렬
    phonebook = sorted([input() for _ in range(n)])
    # 일관성이 계속 유지되는지 확인
    unique = True 
    for i in range(1, len(phonebook)):
        if phonebook[i-1] in phonebook[i][:len(phonebook[i-1])]:
            unique = False
            break
    if unique:
        print('YES')
    else:
        print('NO')