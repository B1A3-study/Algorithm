def solution(record):
    answer = []
    user = {}

    for i in record:
        '''
        파이썬 문법) split이란?
        >> > a = "Life is too short"
        >> > a.split()
        ['Life', 'is', 'too', 'short']
        >> > b = "a:b:c:d"
        >> > b.split(':')
        ['a', 'b', 'c', 'd']
        '''
        if i.split()[0] == 'Enter' or i.split()[0] == 'Change':
            user[i.split()[1]] = i.split()[2]

    for i in record:
        if i.split()[0] == 'Enter':
            answer.append(user[i.split()[1]] + "님이 들어왔습니다.")
        elif i.split()[0] == 'Leave':
            answer.append(user[i.split()[1]] + "님이 나갔습니다.")

    return answer

record = ["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]
print(solution(record))