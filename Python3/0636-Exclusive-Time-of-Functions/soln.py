class Solution:
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        ans, stack = [0] * n, []
        pre = 0
        for log in logs:
            fn, tp, time = log.split(':')
            fn, time = int(fn), int(time)
            if tp[0] == 's': # start
                if stack:
                    ans[stack[-1]] += time - pre_time
                # always need to push the start fn onto stack
                stack.append(fn)
                pre_time = time
            else: # end
                ans[stack.pop()] += time - pre_time + 1
                pre_time = time + 1
        return ans