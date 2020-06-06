class Solution:
    def totalFruit(self, tree):
        """
        :type tree: List[int]
        :rtype: int
        """
        # sliding window
        counter = collections.Counter()
        i, ans = 0, 0
        for j, num in enumerate(tree):
            counter[num] += 1
            while len(counter) > 2:
                counter[tree[i]] -= 1
                if counter[tree[i]] == 0:
                    counter.pop(tree[i])
                i += 1
            ans = max(ans, j - i + 1)
        return ans