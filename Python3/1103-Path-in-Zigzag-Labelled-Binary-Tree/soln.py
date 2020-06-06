class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        # 1 2 4 ...
        tree = [0, 1]
        level = 0
        reverse = True
        while True:
            level += 1
            cnt = 2 ** level
            nodes = range(len(tree), len(tree) + cnt)
            if reverse:
                nodes = reversed(nodes)
            reverse = not reverse
            tree.extend(nodes)
            if len(tree) - 1 >= label:
                break
        i = tree.index(label)
        # print(tree)
        ans = []
        while i != 1:
            ans.append(tree[i])
            i //= 2
        ans.append(1)
        return ans[::-1]
        
