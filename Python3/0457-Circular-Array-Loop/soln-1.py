class Solution(object):
    def circularArrayLoop(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        m = {}
        n = len(nums)
        visited = [0] * n
        for i in range(n):
            if not visited[i]:
                cur = i
                while True:
                    visited[cur] = True
                    nxt = (cur + nums[cur]) % n
                    if nxt < 0:
                        nxt += n
                    if nxt == cur or nums[nxt] * nums[cur] < 0:
                        break
                    if nxt in m:
                        return True
                    m[cur] = nxt
                    cur = nxt
        return False