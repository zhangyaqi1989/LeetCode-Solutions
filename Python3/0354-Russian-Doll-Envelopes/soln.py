class Solution:
    def maxEnvelopes(self, envs):
        """
        :type envs: List[List[int]]
        :rtype: int
        """
        envs.sort(key=lambda x : (x[0], -x[1]))
        tails = []
        def helper(envs, tails, env):
            l, r = 0, len(tails) - 1
            while l <= r:
                mid = (l + r) >> 1
                if envs[tails[mid]][1] >= env[1]:
                    r = mid - 1
                else:
                    l = mid + 1
            return l
        for i, env in enumerate(envs):
            idx = helper(envs, tails, env)
            if idx >= len(tails):
                tails.append(i)
            else:
                tails[idx] = i
        return len(tails)