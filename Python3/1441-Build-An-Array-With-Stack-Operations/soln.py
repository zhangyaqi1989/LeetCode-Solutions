class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        nums = collections.deque(list(range(1, n + 1)))
        ans = []
        for num in target:
            while nums[0] != num:
                ans.append("Push")
                ans.append("Pop")
                nums.popleft()
            ans.append("Push")
            nums.popleft()
        return ans
