class Solution:
    def numSteps(self, s: str) -> int:
        dq = collections.deque(s)
        cnt = 0
        while len(dq) != 1 or dq[-1] == '0':
            if dq[-1] == '0':
                dq.pop()
            else:
                dq[-1] = '0'
                i = len(dq) - 2
                while i >= 0 and dq[i] == '1':
                    dq[i] = '0'
                    i -= 1
                if i < 0:
                    dq.appendleft('1')
                else:
                    dq[i] = '1'
            cnt += 1
        return cnt
