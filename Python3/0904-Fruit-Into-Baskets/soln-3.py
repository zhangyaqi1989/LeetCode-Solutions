class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        # longest subarray with only two types
        counter = collections.defaultdict(int)
        lo, ans = 0, 0
        for i, num in enumerate(tree):
            counter[num] += 1
            while len(counter) > 2:
                counter[tree[lo]] -= 1
                if counter[tree[lo]] == 0:
                    counter.pop(tree[lo])
                lo += 1
            ans = max(ans, i - lo + 1)
        return ans
