from itertools import combinations
from collections import Counter

def solution(orders, course):
    answer = []

    for i in course:
        temp_order = []
        for order in orders:
            temp_order.append(list(combinations(sorted(order), i)))
        temp_order = sum(temp_order, [])
        temp_order_dict = Counter(temp_order)
        if len(temp_order_dict) == 0:
            break
        else:
            if max(temp_order_dict.values()) != 1:
                for order in temp_order_dict:
                    if temp_order_dict[order] == max(temp_order_dict.values()):
                        answer.append(order)

    answer.sort(key=lambda x: x) # 배열의 각 원소에 저장된 문자열 또한 알파벳 오름차순으로 정렬
    # lambda 함수 써서 sort 하면
    # input : [('A', 'C'), ('C', 'D', 'E'), ('B', 'C', 'F', 'G'), ('A', 'C', 'D', 'E')]
    # output : [('A', 'C'), ('A', 'C', 'D', 'E'), ('B', 'C', 'F', 'G'), ('C', 'D', 'E')]

    answer = [''.join(i) for i in answer]

    return answer

orders = ["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"]
course = [2, 3, 4]

print(solution(orders, course))