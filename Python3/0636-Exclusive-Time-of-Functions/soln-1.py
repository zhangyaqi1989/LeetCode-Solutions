class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        lst = []
        ans = [0] * n
        for log in logs:
            idx, op, time = log.split(':')
            idx, time = int(idx), int(time)
            if op == 'start':
                if lst:
                    lst[-1][1] += time - lst[-1][-1]
                    lst[-1][-1] = time
                lst.append([idx, 0, time])
                # print(lst)
            else:
                _, acc, start = lst.pop()
                ans[idx] += acc + time - start + 1
                if lst:
                    lst[-1][-1] = time + 1
                # print(lst)
        return ans
