class Solution:
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        # each basket has one kind
        # longest sub-array that has two kinds of fruits
        # need to remember the last seen index of each fruit
        ans = 0
        i = 0
        s, idxes = set(), {}
        for j, val in enumerate(tree):
            s.add(val)
            idxes[val] = j
            if len(s) > 2:
                kind = min(s, key=lambda x : idxes[x])
                i = idxes[kind] + 1
                s.remove(kind)
            ans = max(j - i + 1, ans)
        return ans