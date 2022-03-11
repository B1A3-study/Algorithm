def solution(numbers, target):
    answer = 0
    tree = [0]
    for num in numbers:
        sub_tree = []
        for tree_num in tree:
            sub_tree.append(tree_num + num)
            sub_tree.append(tree_num - num)
        tree = sub_tree
    for i in tree:
        if i == target:
            answer += 1
    return answer